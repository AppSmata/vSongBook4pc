#include "AsBase.h"
#include "AsUtils.h"
#include "vSongEditor.h"
#include "ui_vSongEditor.h"
#include "vSongBook.h"
#include "AsBase.h"

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

vSongEditor::vSongEditor(QWidget *parent, bool newSong) :
    QDialog(parent),
    ui(new Ui::vSongEditor)
{
	isNewSong = newSong;
    ui->setupUi(this);
	editset = AsBase::AppSettings();
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

bool vSongEditor::PopulateSongbooks()
{
	bool retval = false;
	if (ui->CmbSongbooks->count() > 0) ui->CmbSongbooks->clear();

	sqlite3* songsDb;
	char* err_msg = NULL, ** qryResult = NULL;
	int row, col, rc = sqlite3_open_v2(edit_db, &songsDb, SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE, NULL);

	QByteArray bar = AsUtils::BOOK_LIST_SQL("1").toLocal8Bit();
	char* sqlQuery = bar.data();

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

void vSongEditor::LoadSong()
{
	sqlite3* songsDb;
	char* err_msg = NULL, ** qryResult = NULL;
	int row, col, rc = sqlite3_open_v2(edit_db, &songsDb, SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE, NULL);

	QByteArray bar = AsUtils::SONG_SINGLE_SQL(song_id).toLocal8Bit();
	char* sqlQuery = bar.data();

	if (rc == SQLITE_OK)
	{
		rc = sqlite3_get_table(songsDb, sqlQuery, &qryResult, &row, &col, &err_msg);

		song_title = *(qryResult + 1 * col + 1);
		QString alias = *(qryResult + 1 * col + 2);
		QString lyrics = *(qryResult + 1 * col + 3);

		ui->TxtNumber->setText(*(qryResult + 1 * col + 0));
		ui->TxtTitle->setText(AsBase::ReplaceView(song_title));
		ui->TxtAlias->setText(AsBase::ReplaceView(alias));
		ui->TxtContent->setPlainText(AsBase::ReplaceView(lyrics));
		ui->TxtKey->setText(*(qryResult + 1 * col + 4));
		ui->TxtAuthor->setText(*(qryResult + 1 * col + 5));

		sqlite3_free_table(qryResult);
		sqlite3_close(songsDb);
	}
}

void vSongEditor::ReloadSettings()
{

}

void vSongEditor::SaveNewSong()
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

	//QByteArray bar = "", //AsUtils::SONG_INSERT_SQL(Number, Title, Alias, Content.replace("\r\n", "\n"), 
	//	Key, Author, Bookid).toLocal8Bit();
	//char* sqlQuery = bar.data();

	//rc = sqlite3_exec(db, sqlQuery, 0, 0, &zErrMsg);

	if (rc != SQLITE_OK) sqlite3_free(zErrMsg);
	sqlite3_close(db);
}

void vSongEditor::SaveChanges()
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

	//QByteArray bar = "", //AsUtils::SONG_UPDATE_SQL(Number, Title, Alias, Content.replace("\r\n", "\n"),
	//	Key, Author, song_id).toLocal8Bit();
	//char* sqlQuery = bar.data();

	//rc = sqlite3_exec(db, sqlQuery, 0, 0, &zErrMsg);

	if (rc != SQLITE_OK) sqlite3_free(zErrMsg);
	sqlite3_close(db);
}

vSongEditor::~vSongEditor()
{
    delete ui;
}

void vSongEditor::on_actionSave_triggered()
{
	if (isNewSong) SaveNewSong();
	else SaveChanges();
}

void vSongEditor::on_actionDelete_triggered()
{
	QMessageBox msgBox;
	msgBox.setText("Oops! Just a minute ...");
	msgBox.setInformativeText("Do you want to proceed with deleting the songbook: " + 
		AsBase::ReplaceView(song_title) + "? This action is irrevesible!");
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

void vSongEditor::DeleteSong()
{
	sqlite3* db;
	sqlite3_stmt* sqlqueryStmt;
	char* zErrMsg = NULL;
	int row, col, rc = sqlite3_open(edit_db, &db);

	rc = sqlite3_exec(db, AsUtils::SONG_DELETE_SQL(song_id), 0, 0, &zErrMsg);

	if (rc != SQLITE_OK) sqlite3_free(zErrMsg);
	sqlite3_close(db);
}

void vSongEditor::on_actionClear_triggered()
{
	ui->TxtNumber->setText("");
	ui->TxtTitle->setText("");
	ui->TxtAlias->setText("");
	ui->TxtContent->setPlainText("");
	ui->TxtKey->setText("");
	ui->TxtAuthor->setText("");
}
