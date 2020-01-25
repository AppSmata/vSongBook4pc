#include "vSongBooks.h"
#include "ui_vSongBooks.h"
#include "sqlite.h"
#include "RunSql.h"
#include "sqlitetablemodel.h"
#include <QStandardItemModel>
#include <QObject>

#include <QTextCodec>
#include <QLibraryInfo>
#include <QMessageBox>
#include <QLocale>

#include "ItemData.h"
#include "ItemDelegate.h"

char* book_db = "Data/vSongBook.db";
bool isNewBook;
std::vector<QString> booksets, booklist;
QString Songbookid, Title, Code, Content;

vSongBooks::vSongBooks(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::vSongBooks)
{
    ui->setupUi(this);
	isNewBook = false;
	LoadBooklist("");
}

vSongBooks::~vSongBooks()
{
    delete ui;
}

void vSongBooks::LoadBooklist(QString searchstr)
{
	QStringList strList;

	QStandardItemModel* bookModel = new QStandardItemModel();

	if (booklist.size() > 0) booklist.clear();

	QString SqlQuery = "SELECT bookid, title, code, content, songs FROM books";

	if (!searchstr.isEmpty())
	{
		SqlQuery.append(" WHERE title LIKE '%" + searchstr + "%' OR code LIKE '%" + searchstr + "%' OR content LIKE '%" + searchstr + "%'");
	}

	sqlite3* db;
	char* err_msg = NULL, ** qryResult = NULL;
	int row, col, rc = sqlite3_open_v2(book_db, &db, SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE, NULL);

	SqlQuery.append(" ORDER BY position");
	QByteArray bar = SqlQuery.toLocal8Bit();
	char* sqlQuery = bar.data();

	rc = sqlite3_get_table(db, sqlQuery, &qryResult, &row, &col, &err_msg);

	for (int i = 1; i < row + 1; i++)
	{
		booklist.push_back(*(qryResult + i * col + 0));

		QStandardItem* bookItem = new QStandardItem;
		ItemData songbooklist;
		songbooklist.title = *(qryResult + i * col + 1);

		QString contents = *(qryResult + i * col + 4);
		contents.append(" ");
		contents.append(*(qryResult + i * col + 2));
		contents.append(" songs");

		songbooklist.content = contents;
		bookItem->setData(QVariant::fromValue(songbooklist), Qt::UserRole + 1);
		bookModel->appendRow(bookItem);
	}

	ItemDelegate* itemDelegate = new ItemDelegate(this);
	ui->LstBooks->setItemDelegate(itemDelegate);
	ui->LstBooks->setModel(bookModel);

	sqlite3_free_table(qryResult);
	sqlite3_close(db);

	QModelIndex index = bookModel->index(0, 0);
	ui->LstBooks->setCurrentIndex(index);
	int setbook = booklist[index.row()].toInt();
	Songbookid = QString::number(setbook);
	LoadBook();
}

void vSongBooks::GetUpdates()
{

}

void vSongBooks::LoadBook()
{
	sqlite3* songsDb;
	char* err_msg = NULL, ** qryResult = NULL;
	int row, col, rc = sqlite3_open_v2(book_db, &songsDb, SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE, NULL);

	QString SqlQuery = "SELECT bookid, title, code, content, songs FROM books WHERE bookid=" + Songbookid;
	QByteArray bar = SqlQuery.toLocal8Bit();
	char* sqlQuery = bar.data();

	if (rc == SQLITE_OK)
	{
		rc = sqlite3_get_table(songsDb, sqlQuery, &qryResult, &row, &col, &err_msg);

		QString title = *(qryResult + 1 * col + 1);
		QString code = *(qryResult + 1 * col + 2);
		QString content = *(qryResult + 1 * col + 3);
		QString songs = *(qryResult + 1 * col + 4);

		ui->LblDescription->setText(title + " (" + code + ") has " + songs + " songs. " + content );
		ui->TxtTitle->setText(title);
		ui->TxtCode->setText(*(qryResult + 1 * col + 2));
		ui->TxtContent->setPlainText(content);

		sqlite3_free_table(qryResult);
		sqlite3_close(songsDb);
	}
}

void vSongBooks::on_LstBooks_clicked(const QModelIndex &index)
{
	int setbook = booklist[index.row()].toInt();
	Songbookid = QString::number(setbook);
	LoadBook();
}

void vSongBooks::on_TxtSearch_textChanged(const QString & searchstr)
{
	LoadBooklist(searchstr);
}

void vSongBooks::SaveNewBook()
{
	sqlite3* db;
	sqlite3_stmt* sqlqueryStmt;
	char* zErrMsg = NULL;
	int row, col, rc = sqlite3_open(book_db, &db);

	uint timenow = QDateTime::currentSecsSinceEpoch();
	QString timeStr = QString::number(timenow);

	Title = ui->TxtTitle->text();
	Code = ui->TxtCode->text();
	Content = ui->TxtContent->toPlainText();

	QString SqlQuery = "INSERT INTO books ( title, code, content, songs, created ) VALUES ( " +
		Title + "', " + Code + "', " + Content + "', 0, " + timeStr + ")";

	QByteArray bar = SqlQuery.toLocal8Bit();
	char* sqlQuery = bar.data();

	rc = sqlite3_exec(db, sqlQuery, 0, 0, &zErrMsg);

	if (rc != SQLITE_OK) sqlite3_free(zErrMsg);
	sqlite3_close(db);
	isNewBook = false;
}

void vSongBooks::SaveChanges()
{
	sqlite3* db;
	sqlite3_stmt* sqlqueryStmt;
	char* zErrMsg = NULL;
	int row, col, rc = sqlite3_open(book_db, &db);

	uint timenow = QDateTime::currentSecsSinceEpoch();
	QString timeStr = QString::number(timenow);

	Title = ui->TxtTitle->text();
	Code = ui->TxtCode->text();
	Content = ui->TxtContent->toPlainText();

	QString SqlQuery = "UPDATE books SET title = '" + Title + "', code = '" + Code +
		"', content = '" + Content + "', updated='" + timeStr + "' WHERE bookid=" + Songbookid;

	QByteArray bar = SqlQuery.toLocal8Bit();
	char* sqlQuery = bar.data();

	rc = sqlite3_exec(db, sqlQuery, 0, 0, &zErrMsg);

	if (rc != SQLITE_OK) sqlite3_free(zErrMsg);
	sqlite3_close(db);
}

void vSongBooks::DeleteBook()
{
	sqlite3* db;
	sqlite3_stmt* sqlqueryStmt;
	char* zErrMsg = NULL;
	int row, col, rc = sqlite3_open(book_db, &db);

	QString SqlQuery = "DELETE FROM books WHERE bookid=" + Songbookid + ";";
	SqlQuery.append("DELETE FROM songs WHERE bookid=" + Songbookid);
	QByteArray bar = SqlQuery.toLocal8Bit();
	char* sqlQuery = bar.data();

	rc = sqlite3_exec(db, sqlQuery, 0, 0, &zErrMsg);

	if (rc != SQLITE_OK) sqlite3_free(zErrMsg);
	sqlite3_close(db);
	LoadBooklist("");
}

void vSongBooks::on_actionNew_triggered()
{
	isNewBook = true;
	ui->LblDescription->setText("Start a new SongBook!");
	ui->TxtTitle->clear();
	ui->TxtCode->clear();
	ui->TxtContent->clear();
}

void vSongBooks::on_actionSave_triggered()
{
	if (isNewBook) SaveNewBook();
    else SaveChanges();
	LoadBooklist("");
}

void vSongBooks::on_actionDelete_triggered()
{
    QMessageBox msgBox;
    msgBox.setText("Oops! Just a minute...");
    msgBox.setInformativeText("Do you want to proceed with deleting the songbook: " + Title + " (" + Code + ")? " +
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

void vSongBooks::on_actionRefresh_triggered()
{
	isNewBook = false;
	LoadBooklist("");
}

void vSongBooks::on_actionUpdate_triggered()
{
	LoadBooklist("");
}
