#include "vSongOnline.h"
#include "ui_vSongOnline.h"
#include "AsItem.h"
#include <QDebug>

#include <QtCore>
#include <QtNetwork>
#include <QJsonDocument>

#include <QTextCodec>
#include <QLibraryInfo>
#include <QMessageBox>
#include <QLocale>

#include "sqlite.h"
#include "RunSql.h"
#include "sqlitetablemodel.h"

char* onmy_db = "Data/vSongBook.db";
QString booksresult;
const int iterations = 20;
QVector<int> vector;
std::vector<QString> catids, titles;
QStringList selecteds, selectedBooks;

vSongOnline::vSongOnline(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::vSongOnline)
{
    ui->setupUi(this);
    ui->TxtSearch->hide();

    LoadBooks();
}

void vSongOnline::LoadBooks()
{
    showProgress(true);
    qnam = new QNetworkAccessManager();
    QObject::connect(qnam, SIGNAL(finished(QNetworkReply*)), this, SLOT(onBooksResult(QNetworkReply*)));
    request.setUrl(QUrl("http://sing.appsmata.com/as-api/book-select.php"));
    qnam->get(request);
}

void vSongOnline::onBooksResult(QNetworkReply* reply)
{
    showProgress(false);
    if (reply->error()) {
        qDebug() << reply->errorString();
        return;
    }
    else
    {
        booksresult = (QString)reply->readAll();
        QJsonDocument jsonResponse = QJsonDocument::fromJson(booksresult.toUtf8());
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
            titles.push_back(title + " (" + songs + " songs)");

            bookItem->setData(QVariant::fromValue(book), Qt::UserRole + 1);
            bookModel->appendRow(bookItem);
            count++;
        }
        createListView();
    }
}

void vSongOnline::onSongsResult(QNetworkReply* reply)
{
    showProgress(false);
    if (reply->error()) {
        qDebug() << reply->errorString();
        return;
    }
    else
    {
        booksresult = (QString)reply->readAll();
        QJsonDocument jsonResponse = QJsonDocument::fromJson(booksresult.toUtf8());
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
            titles.push_back(title + " (" + songs + " songs)");

            bookItem->setData(QVariant::fromValue(book), Qt::UserRole + 1);
            bookModel->appendRow(bookItem);
            count++;
        }
        createListView();
    }
}

void vSongOnline::progressManager(qint64 ist, qint64 max)
{
    //ui->progressBar->setRange(0, max);
    //ui->progressBar->setValue(ist);
    //if (max < 0) hideProgress();
}

void vSongOnline::showProgress(bool show)
{
    if (show)
    {
        ui->TxtSearch->hide();
        ui->LstBooks->hide();
        ui->LblNothing->hide();
        ui->BtnProceed->hide();
        ui->BtnCancel->hide();
        ui->progressBar->show();
    }
    else
    {
        ui->TxtSearch->show();
        ui->LstBooks->show();
        ui->LblNothing->show();
        ui->BtnProceed->show();
        ui->BtnCancel->show();
        ui->progressBar->hide();
    }
}

void vSongOnline::createListView()
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

void vSongOnline::on_LstBooks_clicked(const QModelIndex &index)
{
    QModelIndexList list = ui->LstBooks->selectionModel()->selectedIndexes();

    selecteds.clear();
    selectedBooks.clear();

    foreach(const QModelIndex & index, list)
    {
        int selectint = catids[index.row()].toInt();
        selecteds.push_back(catids[selectint]);
        selectedBooks.push_back(titles[selectint]);
    }
}

void vSongOnline::LoadSongs()
{
    QString books = selectedBooks[0] + "";
    for (int i = 1; i < selectedBooks.size(); i++) {
        books = books + "," + selectedBooks[i];
    }
}

void vSongOnline::on_BtnProceed_clicked()
{
    QString selectedones;
    if (selectedBooks.size() > 0)
    {
        QMessageBox msgBox;
        msgBox.setText("Done with selecting?");
        for (int i = 0; i < selectedBooks.size(); i++)
        {
            selectedones = selectedones + QString::number(i + 1) + ". " + selectedBooks[i] + ".\n";
        }
        msgBox.setInformativeText(selectedones);
        msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
        msgBox.setDefaultButton(QMessageBox::No);

        int ret = msgBox.exec();

        switch (ret) {
        case QMessageBox::Yes:
            showProgress(true);
            LoadSongs();
            break;
        default:
            // should never be reached
            break;
        }
    }
    else
    {
        QMessageBox::warning(this, "Just a Minute ...", tr("Oops! This is so heart breaking. You haven't selected a book, you expect things to be okay. You got to select at least one book. \n\n By the way we can always bring you back here to select afresh. But for now select at least one"));

    }
}

void vSongOnline::on_BtnCancel_clicked()
{
    this->close();
}

vSongOnline::~vSongOnline()
{
    delete qnam;
    delete ui;
}
