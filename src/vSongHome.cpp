#include "vSongHome.h"
#include "ui_vSongHome.h"
#include "vSongBook.h"

#include "sqlite.h"
#include "RunSql.h"
#include "sqlitetablemodel.h"

#include <QWhatsThis>
#include <QMessageBox>
#include <limits>
#include <QStandardItemModel>
#include <QObject>
#include "vItemData.h"
#include "vItemDelegate.h"
#include "AboutDialog.h"
#include "vSongBooks.h"
#include "vSongEdit.h"
#include "vSongPrefs.h"
#include "vSongView.h"

int homefont, songfont;
bool isReady, SearchAll, NightMode, isPreviewBold;
char* home_db = "Data/vSongBook.db";
QString selected_book, selected_song, search_term;
std::vector<QString> bookids, songids, booktitles, songtitles, songaliases, songcontents, songbooks, bookcodes, histories, homesets;

QFont HomeFontPreview, HomeFontGeneral;

vSongHome::vSongHome(QWidget *parent) : QMainWindow(parent), ui(new Ui::vSongHome)
{
    ui->setupUi(this);
	ui->SplitterMain->setStretchFactor(1, 3);
	isReady = isPreviewBold = false;

	GetSettings();
	ReloadSettings();
	if (PopulateSongbooks())
	{
		PopulateSonglists(bookids[0], "", false);
		isReady = true;
	}
	else {
        QMessageBox::warning(this, qApp->applicationName(), tr("Oops! vSongBook could not generate view due to unknown error at the moment"));
    }
}

bool vSongHome::GetSettings()
{
	bool retval = false;
	sqlite3* songsDb;
	char* err_msg = NULL, ** qryResult = NULL;
	int row, col, rc = sqlite3_open_v2(home_db, &songsDb, SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE, NULL);

	char* sqlQuery = "SELECT content FROM settings ORDER BY settingid";

	if (rc == SQLITE_OK)
	{
		rc = sqlite3_get_table(songsDb, sqlQuery, &qryResult, &row, &col, &err_msg);

		for (int i = 1; i < row + 1; i++)
		{
			homesets.push_back(*(qryResult + i * col + 0));
		}
		sqlite3_free_table(qryResult);
		sqlite3_close(songsDb);
		retval = true;
	}

	return retval;
}

void vSongHome::ReloadSettings()
{
	homefont = homesets[8].toInt();
	songfont = homesets[11].toInt();

	HomeFontPreview.setFamily(QString::fromUtf8("Trebuchet MS"));
	HomeFontPreview.setPointSize(songfont);
	HomeFontPreview.setBold(isPreviewBold);
	HomeFontPreview.setWeight(50);

	HomeFontGeneral.setFamily(QString::fromUtf8("Trebuchet MS"));
	HomeFontGeneral.setPointSize(homefont);
	HomeFontGeneral.setBold(false);
	HomeFontGeneral.setWeight(50);
	ReloadControls();
}

void vSongHome::ReloadControls()
{
	ui->TxtSearch->setFont(HomeFontGeneral);
	ui->CmbSongbooks->setFont(HomeFontGeneral);

	ui->TxtPreviewTitle->setFont(HomeFontPreview);
	ui->TxtPreviewContent->setFont(HomeFontPreview);
	ui->TxtPreviewAlias->setFont(HomeFontPreview);
}

void vSongHome::SongLast()
{
	int index = ui->CmbSongbooks->currentIndex();
	if ((index - 1) > ui->CmbSongbooks->count())
	{
		ui->CmbSongbooks->setCurrentIndex(index - 1);
	}
}

void vSongHome::FontSmaller()
{
	if ((songfont - 2) > 9)
	{
		songfont = songfont - 2;
		HomeFontPreview.setPointSize(songfont);
		vSongBook::SetOption("preview_font_size", QString::number(songfont));
		ReloadControls();
	}
}

void vSongHome::FontBigger()
{
	if ((songfont + 2) < 51)
	{
		songfont = songfont + 2;
		HomeFontPreview.setPointSize(songfont);
		vSongBook::SetOption("preview_font_size", QString::number(songfont));
		ReloadControls();
	}
}

void vSongHome::FontBold()
{
	if (isPreviewBold) isPreviewBold = false;
	else isPreviewBold = true;
	HomeFontPreview.setBold(isPreviewBold);
	ReloadControls();
}

void vSongHome::NewSong()
{
    vSongEdit editor(this, true);
    editor.exec();
}

void vSongHome::ManageBooks()
{
	vSongBooks books(this);
	books.exec();
}

void vSongHome::OpenEditor()
{
	vSongEdit editor(this, false);
	editor.exec();
}

void vSongHome::OpenSettings()
{
    vSongPrefs preferences(this);
    preferences.exec();
}

void vSongHome::on_CmbSongbooks_currentIndexChanged(int index)
{
	if (isReady) PopulateSonglists(bookids[index], "", false);
}

bool vSongHome::PopulateSongbooks()
{
	bool retval = false;
	if (ui->CmbSongbooks->count() > 0) ui->CmbSongbooks->clear();

	sqlite3* songsDb;
	char* err_msg = NULL, ** qryResult = NULL;
	int row, col, rc = sqlite3_open_v2(home_db, &songsDb, SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE, NULL);

	char* sqlQuery = "SELECT bookid, title, songs FROM books WHERE enabled=1 ORDER BY position;";

	if (rc == SQLITE_OK)
	{
		rc = sqlite3_get_table(songsDb, sqlQuery, &qryResult, &row, &col, &err_msg);

		for (int i = 1; i < row + 1; i++)
		{
			QString title = *(qryResult + i * col + 1);
			QString songs = *(qryResult + i * col + 2);

			ui->CmbSongbooks->addItem(title + " (" + songs + ")");

			bookids.push_back(*(qryResult + i * col + 0));
			booktitles.push_back(title);
		}
		sqlite3_free_table(qryResult);
		sqlite3_close(songsDb);
		ui->CmbSongbooks->setCurrentIndex(0);
		retval = true;
	}

    return retval;
}

void vSongHome::PopulateSonglists(QString setbook, QString searchstr, bool SearchAll)
{
	QStringList strList;

	QStandardItemModel* songModel = new QStandardItemModel();
	
	if (songids.size() > 0) {
		songids.clear();
		songtitles.clear();
		songaliases.clear();
		songcontents.clear();
		songbooks.clear();
	}

	QString searchtotals = " songs found in: " + booktitles[ui->CmbSongbooks->currentIndex()];

	QString SqlQuery = "SELECT songid, number, songs.title, alias, songs.content, key, author, books.title, code FROM songs";
	SqlQuery.append(" INNER JOIN books ON books.bookid = songs.bookid WHERE");

	if (searchstr.isEmpty()) SqlQuery.append(" songs.bookid=" + setbook);
	else
	{
		bool isNumeric;
		int searchint = searchstr.toInt(&isNumeric, 10);
		if (SearchAll)
		{
			if (isNumeric)
			{
				SqlQuery.append(" number=" + searchstr);
				searchtotals.append(" songs found with number: " + searchstr + "#");
			}
			else
			{
				SqlQuery.append(" songs.title LIKE '%" + searchstr + "%' OR alias LIKE '%" + searchstr +
					"%' OR songs.content LIKE '%" + searchstr + "%'");
				searchtotals.append(" songs found with words: \"" + searchstr + "\"");
			}
		}
		else
		{
			if (isNumeric)
			{
				SqlQuery.append(" songs.bookid=" + setbook + " AND number=" + searchstr);
				searchtotals.append(" songs found with number: " + searchstr + "#");
			}
			else
			{
				SqlQuery.append(" songs.bookid=" + setbook + " AND songs.title LIKE '%" + searchstr + "%' OR songs.bookid=" + setbook + " AND alias LIKE '%" + searchstr + "%' OR songs.bookid=" + setbook + " AND songs.content LIKE '%" + searchstr + "%'");
				searchtotals.append(" songs found with words: \"" + searchstr + "\"");
			}
		}
	}

	sqlite3* db;
	char* err_msg = NULL, ** qryResult = NULL;
	int row, col, rc = sqlite3_open_v2(home_db, &db, SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE, NULL);

	SqlQuery.append(" ORDER BY number ASC");
	QByteArray bar = SqlQuery.toLocal8Bit();
	char* sqlQuery = bar.data();

	rc = sqlite3_get_table(db, sqlQuery, &qryResult, &row, &col, &err_msg);

	int songcount = 0;
	for (int i = 1; i < row + 1; i++)
	{		
		QString numberstr = *(qryResult + i * col + 1);
		QString titlestr = *(qryResult + i * col + 2);
		QString titles = numberstr + "# " + titlestr;
		QString contents = *(qryResult + i * col + 4);

		if (searchstr.isEmpty()) strList.append(titles);
		else strList.append(titles + " (" + *(qryResult + i * col + 8) + ")");

		songids.push_back(*(qryResult + i * col + 0));
		songtitles.push_back(titles);
		songaliases.push_back(*(qryResult + i * col + 3));
		songcontents.push_back(contents);
		songbooks.push_back(*(qryResult + i * col + 7));

		contents = contents.replace("\\n", " ");

		QStandardItem* songItem = new QStandardItem;
		vItemData song;
		
		if (titles.length() > 40)
		{
			song.title = titles.left(35) + "...";
		}
		else song.title = titles;

		if (contents.length() > 40)
		{
			song.content = contents.left(35) + "...";
		}
		else song.content = contents;

		songItem->setData(QVariant::fromValue(song), Qt::UserRole + 1);
		songModel->appendRow(songItem);
		songcount++;
	}

	ui->LblResult->setText(QString::number(songcount) + searchtotals);
    vItemDelegate *itemDelegate = new vItemDelegate(this);
    ui->LstResults->setItemDelegate(itemDelegate);
    ui->LstResults->setModel(songModel);

	sqlite3_free_table(qryResult);
	sqlite3_close(db);

	ui->LstResults->setCurrentIndex(songModel->index(0, 0));
	OpenSongPreview(songModel->index(0, 0));
}

void vSongHome::SongNext()
{
	/*QStandardItemModel* songModel = new QStandardItemModel();
	QModelIndex index = ui->LstResults->currentIndex();
	int song = index.row();

	if ((song + 1) < ui->CmbSongbooks->count())
	{
		ui->CmbSongbooks->setCurrentIndex(index + 1);
	}*/
}

void vSongHome::OpenSongPreview(const QModelIndex& index)
{
	int song = index.row();
	QString songTitle = songtitles[song];
	QString songAlias = songaliases[song];
	QString songContent = songcontents[song].replace("\\n", "\r\n");
	vSongBook::SetOption("current_song", songids[song]);

	ui->TxtPreviewTitle->setText(songTitle);
	//ui->TxtEditorTitle->setText(songTitle);
	ui->TxtPreviewContent->setPlainText(songContent);
	//ui->TxtEditorContent->setPlainText(songContent);\

	if (songAlias.length() < 3)
	{
		ui->TxtPreviewAlias->hide();
	}
	else
	{
		ui->TxtPreviewAlias->show();
		ui->TxtPreviewAlias->setPlainText(songAlias);
	}
}

void vSongHome::on_TxtSearch_returnPressed()
{
    QString searchText = ui->TxtSearch->text();
    PopulateSonglists(bookids[0], searchText, true);
}

void vSongHome::on_TxtSearch_textChanged(const QString &searchstr)
{
	PopulateSonglists(bookids[0], searchstr, true);
}

void vSongHome::on_LstResults_clicked(const QModelIndex& index)
{
	OpenSongPreview(index);
}

void vSongHome::on_LstResults_activated(const QModelIndex& index)
{
	OpenSongPreview(index);
}

void vSongHome::on_LstResults_doubleClicked(const QModelIndex &index)
{
	OpenSongPreview(index);
    openPresentation();
}

void vSongHome::openPresentation()
{
	vSongView* present = new vSongView();
    present->showFullScreen();
}

vSongHome::~vSongHome()
{
	delete ui;
}


void vSongHome::on_actionPresent_triggered()
{
    openPresentation();
}

void vSongHome::on_actionPresent_Song_triggered()
{
	openPresentation();
}

void vSongHome::on_actionSave_triggered()
{

}

void vSongHome::on_actionBold_Text_triggered()
{

}

void vSongHome::on_actionChange_Font_triggered()
{

}

void vSongHome::on_actionSmaller_Font_triggered()
{

}

void vSongHome::on_actionBigger_Font_triggered()
{

}

void vSongHome::on_actionNext_Song_triggered()
{

}

void vSongHome::on_actionPrevious_Song_triggered()
{

}

void vSongHome::on_actionCheck_Updates_triggered()
{

}

void vSongHome::on_actionContribute_triggered()
{

}

void vSongHome::on_actionDonate_triggered()
{

}

void vSongHome::on_actionUpdate_Songbooks_triggered()
{

}

void vSongHome::on_actionManage_Songbooks_triggered()
{

}

void vSongHome::on_actionEdit_Songbook_triggered()
{

}

void vSongHome::on_actionNew_Songbook_triggered()
{

}

void vSongHome::on_actionDelete_Song_triggered()
{

}

void vSongHome::on_actionEdit_Song_triggered()
{

}

void vSongHome::on_actionNew_Song_triggered()
{
    NewSong();
}

void vSongHome::on_actionManage_Settings_triggered()
{    
	OpenSettings();
}

void vSongHome::on_actionReset_Settings_triggered()
{

}

void vSongHome::on_actionHow_it_Works_triggered()
{

}

void vSongHome::on_actionAbout_triggered()
{

}

void vSongHome::on_actionExit_triggered()
{
	this->close();
}

void vSongHome::on_actionBold_triggered()
{
	FontBold();
}

void vSongHome::on_actionSmaller_triggered()
{
	FontSmaller();
}

void vSongHome::on_actionBigger_triggered()
{
	FontBigger();
}

void vSongHome::on_actionNext_triggered()
{
	SongNext();
}

void vSongHome::on_actionPrevious_triggered()
{
	SongLast();
}

void vSongHome::on_actionCancel_triggered()
{

}

void vSongHome::on_actionDelete_triggered()
{

}

void vSongHome::on_actionPreferences_triggered()
{
	OpenSettings();
}


void vSongHome::on_actionEdit_triggered()
{
    OpenEditor();
}

void vSongHome::on_actionNewsong_triggered()
{
    NewSong();
}

void vSongHome::on_actionSongbooks_triggered()
{
	ManageBooks();
}
