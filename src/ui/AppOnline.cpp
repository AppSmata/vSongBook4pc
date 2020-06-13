#include <src\ui\AppOnline.h>
#include <src\ui\AppHome.h>
#include <ui_AppOnline.h>

#include <sqlite.h>
#include <RunSql.h>
#include <sqlitetablemodel.h>

#include <AsItem.h>
#include <AsBase.h>
#include <AsUtils.h>
#include <AsDelegate.h>

#include <QMovie>
#include <QDebug>
#include <QtCore>
#include <QtNetwork>
#include <QJsonDocument>
#include <QTextCodec>
#include <QLibraryInfo>
#include <QMessageBox>
#include <QLocale>
#include <QStandardItemModel>
#include <QObject>

#include <task.h>

QString networkResult, baseUrl;
//const int iterations = 20;
QVector<int> vector;
QMovie *mMovie;
std::vector<QString> selecteds, catids, titles, tags, contents, songnos;

AppOnline::AppOnline(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AppOnline)
{
    ui->setupUi(this);
	mMovie = new QMovie(":/images/loading.gif");
	ui->LblProgress->setMovie(mMovie);
	mMovie->start();
	baseUrl = AsBase::BaseUrl();
    LoadBooks();
}

void AppOnline::LoadBooks()
{
	ui->LblDetails->setText("Be patient as we load books from online for you...");
    showProgress(true);
    qnam = new QNetworkAccessManager();
    QObject::connect(qnam, SIGNAL(finished(QNetworkReply*)), this, SLOT(onBooksResult(QNetworkReply*)));
    request.setUrl(QUrl(baseUrl + AsUtils::BooksSelect()));

	AsBase::WriteLogs("Online", "Fetching books from online", "Url: " + baseUrl + AsUtils::BooksSelect() + " ", "");
    qnam->get(request);
}

void AppOnline::onBooksResult(QNetworkReply* reply)
{
	showProgress(false);
	if (reply->error()) {
		networkResult = (QString)reply->errorString();
		ui->TxtSearch->hide();
		ui->LstBooks->hide();
		ui->BtnProceed->hide();
		ui->BtnCancel->hide();
		ui->LblProgress->hide();
		ui->LblDetails->show();

		AsBase::WriteLogs("Online", "Failed to fetch books from online", "Reason: " + networkResult, "");
		ui->LblDetails->setText("Failed to fetch books from online.\nReason: " + networkResult);
        return;
    }
    else
    {
        networkResult = (QString)reply->readAll();
        QJsonDocument jsonResponse = QJsonDocument::fromJson(networkResult.toUtf8());
        QJsonObject jsonObject = jsonResponse.object();
        QJsonArray jsonArray = jsonObject["data"].toArray();
        
        bookModel = new QStandardItemModel();

        int count = 1;
        foreach(const QJsonValue & value, jsonArray) 
        {
            QJsonObject obj = value.toObject();
            QString title = obj["title"].toString();
            QString code = obj["backpath"].toString();
            QString songs = obj["qcount"].toString();

            QStandardItem* bookItem = new QStandardItem;
            AsItem book;

            book.image = "res/check.png";
            book.title = QString::number(count) + ". " + title;
            book.content = songs + " " + code + " songs";
            catids.push_back(obj["categoryid"].toString());
            titles.push_back(title);
            tags.push_back(obj["backpath"].toString());
            contents.push_back(obj["contents"].toString());
            songnos.push_back(songs);

            bookItem->setData(QVariant::fromValue(book), Qt::UserRole + 1);
            bookModel->appendRow(bookItem);
            count++;
        }

        createListView();

		QMessageBox::warning(this, "Just a Minute ...",
			tr("Take time to select a songbook at a time so as to setup your vSongBook Collection.\n\nOnce done that, proceed to the next stage")
		);
    }
}

void AppOnline::showProgress(bool show)
{
	if (show)
    {
		ui->TxtSearch->hide();
        ui->LstBooks->hide();
        ui->BtnProceed->hide();
        ui->BtnCancel->hide();
        ui->LblProgress->show();
        ui->LblDetails->show();
    }
    else
    {
		ui->TxtSearch->show();
		ui->LstBooks->show();
		ui->BtnProceed->show();
		ui->BtnCancel->show();
		ui->LblProgress->hide();
		ui->LblDetails->hide();
    }
}

void AppOnline::createListView()
{
    AsDelegate* asDelegate = new AsDelegate(this);
    ui->LstBooks->setItemDelegate(asDelegate);
    ui->LstBooks->setModel(bookModel);
    ui->LstBooks->setViewMode(QListView::ListMode);
    ui->LstBooks->setDragEnabled(true);
    ui->LstBooks->setSelectionMode(QAbstractItemView::MultiSelection);
    ui->LstBooks->setSpacing(1);
    ui->LstBooks->setStyleSheet("* { background-color: #D3D3D3; }");
}

void AppOnline::on_BtnProceed_clicked()
{
	selecteds.clear();
	QModelIndexList list = ui->LstBooks->selectionModel()->selectedIndexes();

	foreach(const QModelIndex &index, list)
	{
		int book = index.row();
		selecteds.push_back(catids[book]);
	}

    if (selecteds.size() > 0)
    {
		QString selectedones;
        QMessageBox msgBox;

		msgBox.setWindowTitle("Just a minute ...");
		QIcon icon;
		icon.addFile(QStringLiteral(":/icons/app_icon"), QSize(), QIcon::Normal, QIcon::Off);
		msgBox.setWindowIcon(icon);
		
		msgBox.setIcon(QMessageBox::Warning);
        msgBox.setText("Done with selecting?");
        for (int i = 0; i < selecteds.size(); i++)
        {
			int bid = selecteds[i].toInt() - 1;
            selectedones = selectedones + QString::number(i + 1) + ". " + titles[bid] + " - " + tags[bid] + " (" +
				songnos[bid] + " songs).\n";
        }
        msgBox.setInformativeText(selectedones);
        msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
        msgBox.setDefaultButton(QMessageBox::No);
		
		int ret = msgBox.exec();
		switch (ret) {
			case QMessageBox::Yes:
				LoadSongs();
				break;
			default:
				// should never be reached
				break;
		}
    }
    else 
		QMessageBox::warning(this, "Just a Minute ...", 
			tr("Oops! This is so heart breaking. You haven't selected a book, you expect things to be okay. You got to select at least one book. \n\n By the way we can always bring you back here to select afresh. But for now select at least one")
		);
}

void AppOnline::LoadSongs()
{
	ui->LblDetails->setText("Loading songs from online ...\n Thanks for you patience");
	setStyleSheet("* { background-color: #000000; color: #FFFFFF; }");
	showProgress(true);

    QString books = selecteds[0];
	int bid = books.toInt() - 1;
    AsBase::NewBook(titles[bid], catids[bid], tags[bid], contents[bid], songnos[bid], "1");

	if (selecteds.size() > 1)
	{
		for (int i = 1; i < selecteds.size(); i++)
		{
			books = books + "," + selecteds[i];
			int bid = selecteds[i].toInt() - 1;
			AsBase::NewBook(titles[bid], catids[bid], tags[bid], contents[bid], songnos[bid], QString::number(i + 1));
		}
	}

    qnam = new QNetworkAccessManager();
    QObject::connect(qnam, SIGNAL(finished(QNetworkReply*)), this, SLOT(onSongsResult(QNetworkReply*)));
	request.setUrl(QUrl(baseUrl + AsUtils::PostsSelect() + "?books=" + books));
	AsBase::WriteLogs("Online", "Fetching songs from online for books: " + books, "Url: " + baseUrl + AsUtils::PostsSelect() + "?books=" + books + " ", "");
    qnam->get(request);
}

QString InsertSongs()
{
	QJsonDocument jsonResponse = QJsonDocument::fromJson(networkResult.toUtf8());
	QJsonObject jsonObject = jsonResponse.object();
	QJsonArray jsonArray = jsonObject["data"].toArray();

	foreach(const QJsonValue & value, jsonArray)
	{
		QJsonObject obj = value.toObject();

		QString Bookid = obj["categoryid"].toString();
		QString Categoryid = obj["categoryid"].toString();
		QString Number = obj["number"].toString();
		QString Postid = obj["postid"].toString();
		QString Title = obj["title"].toString();
		QString Alias = obj["alias"].toString();
		QString Content = obj["content"].toString();
		QString Author = obj["who"].toString();

		Title = Title.replace("\n", "\\n");
		Title = Title.replace("'", "''");

		Content = Content.replace("\n", "\\n");
		Content = Content.replace("'", "''");

		AsBase::NewSong(Bookid, Categoryid, Number, Postid, Title, Alias, Content, "", Author);

	}
	return "Task Finished";
}

void AppOnline::onSongsResult(QNetworkReply* reply)
{
    if (reply->error()) {
		showProgress(false);
		networkResult = (QString)reply->errorString();
		ui->TxtSearch->hide();
		ui->LstBooks->hide();
		ui->BtnProceed->hide();
		ui->BtnCancel->hide();
		ui->LblProgress->hide();
		ui->LblDetails->show();

		AsBase::WriteLogs("Online", "Failed to fetch songs from online", "Reason: " + networkResult, "");
		ui->LblDetails->setText("Failed to fetch songs from online.\nReason: " + networkResult);
        return;
    }
    else
    {
        networkResult = (QString)reply->readAll();
		
		Task::await([]() {
			return InsertSongs();
		});

		showProgress(false);

        this->close();
    }
}

void AppOnline::on_BtnCancel_clicked()
{
	this->close();
}

AppOnline::~AppOnline()
{
    delete qnam;
    delete ui;
}
