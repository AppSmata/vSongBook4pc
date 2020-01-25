#include "vSongEdit.h"
#include "ui_vSongEdit.h"
#include "vSongBook.h"

#include <QTextCodec>
#include <QLibraryInfo>
#include <QMessageBox>
#include <QLocale>

#include "sqlite.h"
#include "RunSql.h"
#include "sqlitetablemodel.h"

char* edit_db = "Data/vSongBook.db";
bool isNewSong;
std::vector<QString> editset, book_ids, book_titles;
QString song_id,song_title;

vSongEdit::vSongEdit(QWidget *parent, bool newSong) :
    QDialog(parent),
    ui(new Ui::vSongEdit)
{
	isNewSong = newSong;
    ui->setupUi(this);
	GetSettings();
	PopulateSongbooks();
	if (isNewSong)
	{
		ui->actionSave->setText("Save a New Song");
	}
	else
	{
		song_id = editset[23];
		LoadSong();
	}
}

bool vSongEdit::GetSettings()
{
	bool retval = false;
	sqlite3* songsDb;
	char* err_msg = NULL, ** qryResult = NULL;
	int row, col, rc = sqlite3_open_v2(edit_db, &songsDb, SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE, NULL);

	char* sqlQuery = "SELECT content FROM settings ORDER BY settingid";

	if (rc == SQLITE_OK)
	{
		rc = sqlite3_get_table(songsDb, sqlQuery, &qryResult, &row, &col, &err_msg);

		for (int i = 1; i < row + 1; i++)
		{
			editset.push_back(*(qryResult + i * col + 0));
		}
		sqlite3_free_table(qryResult);
		sqlite3_close(songsDb);
		retval = true;
	}

	return retval;
}

bool vSongEdit::PopulateSongbooks()
{
	bool retval = false;
	if (ui->CmbSongbooks->count() > 0) ui->CmbSongbooks->clear();

	sqlite3* songsDb;
	char* err_msg = NULL, ** qryResult = NULL;
	int row, col, rc = sqlite3_open_v2(edit_db, &songsDb, SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE, NULL);

	char* sqlQuery = "SELECT bookid, title, songs FROM books WHERE enabled=1 ORDER BY position;";

	if (rc == SQLITE_OK)
	{
		rc = sqlite3_get_table(songsDb, sqlQuery, &qryResult, &row, &col, &err_msg);

		for (int i = 1; i < row + 1; i++)
		{
			QString title = *(qryResult + i * col + 1);
			QString songs = *(qryResult + i * col + 2);

			ui->CmbSongbooks->addItem(title + " (" + songs + ")");

			book_ids.push_back(*(qryResult + i * col + 0));
			book_titles.push_back(title);
		}
		sqlite3_free_table(qryResult);
		sqlite3_close(songsDb);
		ui->CmbSongbooks->setCurrentIndex(0);
		retval = true;
	}

	return retval;
}

void vSongEdit::LoadSong()
{
	sqlite3* songsDb;
	char* err_msg = NULL, ** qryResult = NULL;
	int row, col, rc = sqlite3_open_v2(edit_db, &songsDb, SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE, NULL);

	QString SqlQuery = "SELECT number, songs.title, alias, songs.content, key, author, books.title FROM songs";
	SqlQuery.append(" INNER JOIN books ON books.bookid = songs.bookid WHERE songs.songid=" + song_id);
	QByteArray bar = SqlQuery.toLocal8Bit();
	char* sqlQuery = bar.data();

	if (rc == SQLITE_OK)
	{
		rc = sqlite3_get_table(songsDb, sqlQuery, &qryResult, &row, &col, &err_msg);

		song_title = *(qryResult + 1 * col + 1);
		QString alias = *(qryResult + 1 * col + 2);
		QString lyrics = *(qryResult + 1 * col + 3);

		ui->TxtNumber->setText(*(qryResult + 1 * col + 0));
		ui->TxtTitle->setText(vSongBook::ReplaceView(song_title));
		ui->TxtAlias->setText(vSongBook::ReplaceView(alias));
		ui->TxtContent->setPlainText(vSongBook::ReplaceView(lyrics));
		ui->TxtKey->setText(*(qryResult + 1 * col + 4));
		ui->TxtAuthor->setText(*(qryResult + 1 * col + 5));

		sqlite3_free_table(qryResult);
		sqlite3_close(songsDb);
	}
}

void vSongEdit::ReloadSettings()
{

}

void vSongEdit::SaveNewSong()
{
	sqlite3* db;
	sqlite3_stmt* sqlqueryStmt;
	char* zErrMsg = NULL;
	int row, col, rc = sqlite3_open(edit_db, &db);

	uint timenow = QDateTime::currentSecsSinceEpoch();
	QString timeStr = QString::number(timenow);

	QString Bookid = book_ids[ui->CmbSongbooks->currentIndex()];
	QString Number = ui->TxtNumber->text();
	QString Title = ui->TxtTitle->text();
	QString Alias = ui->TxtAlias->text();
	QString Content = ui->TxtContent->toPlainText();
	QString Key = ui->TxtKey->text();
	QString Author = ui->TxtAuthor->text();

	QString SqlQuery = "INSERT INTO songs ( number, title, alias, content, key, bookid, created ) VALUES ( " + 
		Number + "', " + Title + "', " + Alias + "', " + Content.replace("\r\n", "\n") + "', " + Key + "', " + 
		Author + "', " + Bookid + ", " + timeStr + ")";

	QByteArray bar = SqlQuery.toLocal8Bit();
	char* sqlQuery = bar.data();

	rc = sqlite3_exec(db, sqlQuery, 0, 0, &zErrMsg);

	if (rc != SQLITE_OK) sqlite3_free(zErrMsg);
	sqlite3_close(db);
}

void vSongEdit::SaveChanges()
{
	sqlite3* db;
	sqlite3_stmt* sqlqueryStmt;
	char* zErrMsg = NULL;
	int row, col, rc = sqlite3_open(edit_db, &db);

	uint timenow = QDateTime::currentSecsSinceEpoch();
	QString timeStr = QString::number(timenow);

	QString Number = ui->TxtNumber->text();
	QString Title = ui->TxtTitle->text();
	QString Alias = ui->TxtAlias->text();
	QString Content = ui->TxtContent->toPlainText();
	QString Key = ui->TxtKey->text();
	QString Author = ui->TxtAuthor->text();

	QString SqlQuery = "UPDATE songs SET number = '" + Number + "', title = '" + Title +
		"', alias = '" + Alias + "', content = '" + Content.replace("\r\n", "\n") + "', key = '" + Key +
		"', author = '" + Author + "', updated='" + timeStr + "' WHERE songid=" + song_id;

	QByteArray bar = SqlQuery.toLocal8Bit();
	char* sqlQuery = bar.data();

	rc = sqlite3_exec(db, sqlQuery, 0, 0, &zErrMsg);

	if (rc != SQLITE_OK) sqlite3_free(zErrMsg);
	sqlite3_close(db);
}

vSongEdit::~vSongEdit()
{
    delete ui;
}

void vSongEdit::on_actionSave_triggered()
{
	if (isNewSong) SaveNewSong();
	else SaveChanges();
}

void vSongEdit::on_actionDelete_triggered()
{
	QMessageBox msgBox;
	msgBox.setText("Oops! Just a minute ...");
	msgBox.setInformativeText("Do you want to proceed with deleting the songbook: " + 
		vSongBook::ReplaceView(song_title) + "? This action is irrevesible!");
	msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
	msgBox.setDefaultButton(QMessageBox::No);
	int ret = msgBox.exec();

	switch (ret) {
	case QMessageBox::Yes:
		DeleteSong();
		break;
	default:
		// should never be reached
		break;
	}
}

void vSongEdit::DeleteSong()
{
	sqlite3* db;
	sqlite3_stmt* sqlqueryStmt;
	char* zErrMsg = NULL;
	int row, col, rc = sqlite3_open(edit_db, &db);

	QString SqlQuery = "DELETE FROM songs WHERE songid=" + song_id;
	QByteArray bar = SqlQuery.toLocal8Bit();
	char* sqlQuery = bar.data();

	rc = sqlite3_exec(db, sqlQuery, 0, 0, &zErrMsg);

	if (rc != SQLITE_OK) sqlite3_free(zErrMsg);
	sqlite3_close(db);
}

void vSongEdit::on_actionClear_triggered()
{
	ui->TxtNumber->setText("");
	ui->TxtTitle->setText("");
	ui->TxtAlias->setText("");
	ui->TxtContent->setPlainText("");
	ui->TxtKey->setText("");
	ui->TxtAuthor->setText("");
}
