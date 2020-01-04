#include "vSongHome.h"
#include "ui_vSongHome.h"

#include "sqlite.h"
#include "vSongBook.h"
#include "RunSql.h"
#include "sqlitetablemodel.h"

#include <QWhatsThis>
#include <QMessageBox>
#include <limits>
#include <QStandardItemModel>
#include <QObject>
#include "vSongItemData.h"
#include "vSongItemDelegate.h"

int homefont, songfont;
bool searchall, nightmode;
QString selected_book, selected_song, search_term;
std::vector<QString> bookids, songids, booktitles, songtitles, songaliases, songcontents, songbooks, bookcodes, homesets;

vSongHome::vSongHome(QWidget *parent) : QMainWindow(parent), ui(new Ui::vSongHome)
{
    ui->setupUi(this);

    if (PopulateSongbooks())
    {
		PopulateSonglists(bookids[0], "", false);
    }
    else
    {
        QMessageBox::warning(this, qApp->applicationName(), tr("Oops! vSongBook could not generate view due to unknown error at the moment"));
    }
}

bool vSongHome::PopulateSongbooks()
{
    bool retval = false;

    QString wFile = "Data\\Songs.db";

    if (db.open(wFile, true))
    {
        int bookscount = ui->CmbSongbooks->count();
        if (bookscount > 0) ui->CmbSongbooks->clear();

        sqlite3* songsDb;
        char* err_msg = NULL, ** qryResult = NULL;
        int row, col, rc = sqlite3_open_v2("Data\\Songs.db", &songsDb, SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE, NULL);

        char* sqlQuery = "SELECT bookid, title, songs FROM books WHERE enabled=1 ORDER BY position;";

        if(rc == SQLITE_OK)
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
        }
        retval = true;
    } else retval = false;

    return retval;
}

void vSongHome::PopulateSonglists(QString setbook, QString searchstr, bool searchall)
{
	/*if (songModel->item-> > 0) {
		songids.clear();
		songtitles.clear();
		songaliases.clear();
		songcontents.clear();
		songbooks.clear();
		//ui->LstResults->clear();
	}*/

	QString searchtotals = " songs found in: " + booktitles[ui->CmbSongbooks->currentIndex()];

	QString SqlQuery = "SELECT songid, number, songs.title, alias, songs.content, key, author, books.title, code FROM songs";
	SqlQuery.append(" INNER JOIN books ON books.bookid = songs.bookid WHERE");

	if (searchstr.isEmpty()) SqlQuery.append(" songs.bookid=" + setbook);
	else
	{
		bool isNumeric;
		int searchint = searchstr.toInt(&isNumeric, 10);
		if (searchall)
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
	int row, col, rc = sqlite3_open_v2("Data\\Songs.db", &db, SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE, NULL);

	SqlQuery.append(" ORDER BY number ASC");
	QByteArray bar = SqlQuery.toLocal8Bit();
	char* sqlQuery = bar.data();

	rc = sqlite3_get_table(db, sqlQuery, &qryResult, &row, &col, &err_msg);

	QStringList strList;

	QStandardItemModel* songModel = new QStandardItemModel();

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
		//songbooks.push_back(*(qryResult + i * col + 7) + " (" + *(qryResult + i * col + 8) + ")");

		QStandardItem* songItem = new QStandardItem;
		vSongItemData song;
		song.title = titles;
		song.content = contents.replace("\\n", " ");
		song.detail = "Songs of Worship; Has Chorus; 3 Verses; Key -;";
		songItem->setData(QVariant::fromValue(song), Qt::UserRole + 1);
		songModel->appendRow(songItem);
	}
    
    vSongItemDelegate *vItemDelegate = new vSongItemDelegate(this);
    ui->LstResults->setItemDelegate(vItemDelegate);
    ui->LstResults->setModel(songModel);

	sqlite3_free_table(qryResult);
	sqlite3_close(db);
	
	ui->LstResults->setCurrentIndex(songModel->item);
	//OpenSongPreview(0);
}

vSongHome::~vSongHome()
{
    delete ui;
}

void vSongHome::reloadSettings()
{
	//songModel->reloadData();

}

void vSongHome::on_TxtSearch_textChanged(const QString &arg1)
{

}
