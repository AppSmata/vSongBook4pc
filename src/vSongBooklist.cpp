#include "AsBase.h"
#include "AsUtils.h"

#include "vSongBooklist.h"
#include "ui_vSongBooklist.h"

#include "sqlite.h"
#include "RunSql.h"
#include "sqlitetablemodel.h"
#include <QStandardItemModel>
#include <QObject>

#include <QTextCodec>
#include <QLibraryInfo>
#include <QMessageBox>
#include <QLocale>

#include "AsItem.h"
#include "AsDelegate.h"

bool isNewBook;
std::vector<QString> booksets, booklist;
QString Songbookid, Title, Tags, Content;

vSongBooklist::vSongBooklist(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::vSongBooklist)
{
    ui->setupUi(this);
	isNewBook = false;
	LoadBooklist("");
}

vSongBooklist::~vSongBooklist()
{
    delete ui;
}

void vSongBooklist::LoadBooklist(QString searchstr)
{
	QStringList strList;

	QStandardItemModel* bookModel = new QStandardItemModel();

	if (booklist.size() > 0) booklist.clear();

	sqlite3* db;
	char* err_msg = NULL, ** qryResult = NULL;
	int row, col, rc = sqlite3_open_v2(AsUtils::APP_DB(), &db, SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE, NULL);

	QByteArray bar = AsUtils::BOOK_SEARCH_SQL(searchstr).toLocal8Bit();
	char* sqlQuery = bar.data();

	rc = sqlite3_get_table(db, sqlQuery, &qryResult, &row, &col, &err_msg);

	for (int i = 1; i < row + 1; i++)
	{
		booklist.push_back(*(qryResult + i * col + 0));

		QStandardItem* bookItem = new QStandardItem;
		AsItem songbooklist;
		
		songbooklist.title = *(qryResult + i * col + 3);

		QString contents = *(qryResult + i * col + 5);
		contents.append(" ");
		contents.append(*(qryResult + i * col + 4));
		contents.append(" songs");

		songbooklist.content = contents;
		bookItem->setData(QVariant::fromValue(songbooklist), Qt::UserRole + 1);
		bookModel->appendRow(bookItem);
	}

	AsDelegate* asDelegate = new AsDelegate(this);
	ui->LstBooks->setItemDelegate(asDelegate);
	ui->LstBooks->setModel(bookModel);

	sqlite3_free_table(qryResult);
	sqlite3_close(db);

	QModelIndex index = bookModel->index(0, 0);
	ui->LstBooks->setCurrentIndex(index);
	int setbook = booklist[index.row()].toInt();
	Songbookid = QString::number(setbook);
	LoadBook();
}

void vSongBooklist::GetUpdates()
{

}

void vSongBooklist::LoadBook()
{
	sqlite3* songsDb;
	char* err_msg = NULL, ** qryResult = NULL;
	int row, col, rc = sqlite3_open_v2(AsUtils::APP_DB(), &songsDb, SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE, NULL);

	QByteArray bar = AsUtils::BOOK_SINGLE_SQL(Songbookid).toLocal8Bit();
	char* sqlQuery = bar.data();

	if (rc == SQLITE_OK)
	{
		rc = sqlite3_get_table(songsDb, sqlQuery, &qryResult, &row, &col, &err_msg);

		QString title = *(qryResult + 1 * col + 3);
		QString code = *(qryResult + 1 * col + 4);
		QString songs = *(qryResult + 1 * col + 5);
		QString content = *(qryResult + 1 * col + 7);

		ui->LblDescription->setText(title + " (" + code + ") has " + songs + " songs. " + content );
		ui->TxtTitle->setText(title);
		ui->TxtCode->setText(code);
		ui->TxtContent->setPlainText(content);

		sqlite3_free_table(qryResult);
		sqlite3_close(songsDb);
	}
}

void vSongBooklist::on_LstBooks_clicked(const QModelIndex &index)
{
	int setbook = booklist[index.row()].toInt();
	Songbookid = QString::number(setbook);
	LoadBook();
}

void vSongBooklist::on_TxtSearch_textChanged(const QString & searchstr)
{
	LoadBooklist(searchstr);
}

void vSongBooklist::SaveChanges()
{
	sqlite3* db;
	sqlite3_stmt* sqlqueryStmt;
	char* zErrMsg = NULL;
	int row, col, rc = sqlite3_open(AsUtils::APP_DB(), &db);

	uint timenow = QDateTime::currentSecsSinceEpoch();
	QString timeStr = QString::number(timenow);

	Title = ui->TxtTitle->text();
	Tags = ui->TxtCode->text();
	Content = ui->TxtContent->toPlainText();

	QByteArray bar = AsUtils::BOOK_UPDATE_SQL(Songbookid, Title, Tags, Content).toLocal8Bit();
	char* sqlQuery = bar.data();

	rc = sqlite3_exec(db, sqlQuery, 0, 0, &zErrMsg);

	if (rc != SQLITE_OK) sqlite3_free(zErrMsg);
	sqlite3_close(db);
}

void vSongBooklist::DeleteBook()
{
	sqlite3* db;
	sqlite3_stmt* sqlqueryStmt;
	char* zErrMsg = NULL;
	int row, col, rc = sqlite3_open(AsUtils::APP_DB(), &db);

	//rc = sqlite3_exec(db, AsUtils::BOOK_DELETE_SQL(Songbookid), 0, 0, &zErrMsg);

	if (rc != SQLITE_OK) sqlite3_free(zErrMsg);
	sqlite3_close(db);
	LoadBooklist("");
}

void vSongBooklist::on_actionNew_triggered()
{
	isNewBook = true;
	ui->LblDescription->setText("Start a new SongBook!");
	ui->TxtTitle->clear();
	ui->TxtCode->clear();
	ui->TxtContent->clear();
}

void vSongBooklist::on_actionSave_triggered()
{
	if (isNewBook)
	{
		Title = ui->TxtTitle->text();
		Tags = ui->TxtCode->text();
		Content = ui->TxtContent->toPlainText();
		AsBase::NewBook(Title, "", Tags, Content, "0");
		isNewBook = false;
	}
    else SaveChanges();
	LoadBooklist("");
}

void vSongBooklist::on_actionDelete_triggered()
{
    QMessageBox msgBox;
    msgBox.setText("Oops! Just a minute...");
    msgBox.setInformativeText("Do you want to proceed with deleting the songbook: " + Title + " (" + Tags + ")? " +
        "All the songs in this songbook will be lost!");
    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    msgBox.setDefaultButton(QMessageBox::No);
    int ret = msgBox.exec();

    switch (ret) {
        case QMessageBox::Yes:
            DeleteBook();
            break;
        default:
            // should never be reached
            break;
    }
}

void vSongBooklist::on_actionRefresh_triggered()
{
	isNewBook = false;
	LoadBooklist("");
}

void vSongBooklist::on_actionUpdate_triggered()
{
	LoadBooklist("");
}
