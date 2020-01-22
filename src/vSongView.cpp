#include "vSongView.h"
#include "ui_vSongView.h"

#include "sqlite.h"
#include "RunSql.h"
#include "sqlitetablemodel.h"

char* app_db = "Data/vSongBook.db";
std::vector<QString> songverses1, songverses2, viewset, labels;
int this_book, this_song, slides, slideno, slideindex, mainfont, smallfont;
QString setsong, bookid, songid, number, title, alias, content, key, author, book, chorus, slide, view_fonty;
bool haschorus;

vSongView::vSongView(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::vSongView)
{
	GetSettings();
	ReloadSettings();

    ui->setupUi(this);
    ui->BtnClose->hide();
    ui->BtnDown->hide();
    ui->BtnUp->hide();

	PresentSong(viewset[23]);
}

bool vSongView::GetSettings()
{
	bool retval = false;
	sqlite3* songsDb;
	char* err_msg = NULL, ** qryResult = NULL;
	int row, col, rc = sqlite3_open_v2(app_db, &songsDb, SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE, NULL);

	char* sqlQuery = "SELECT content FROM settings ORDER BY settingid";

	if (rc == SQLITE_OK)
	{
		rc = sqlite3_get_table(songsDb, sqlQuery, &qryResult, &row, &col, &err_msg);

		for (int i = 1; i < row + 1; i++)
		{
			viewset.push_back(*(qryResult + i * col + 0));
		}
		sqlite3_free_table(qryResult);
		sqlite3_close(songsDb);
		retval = true;
	}

    return retval;
}

void vSongView::ReloadSettings()
{
	
}

void vSongView::PresentSong(QString setsongid)
{
	slides = 0;
	if (songverses1.size() > 0) songverses1.clear();
	if (songverses2.size() > 0) songverses2.clear();

	sqlite3* songsDb;
	char* err_msg = NULL, ** qryResult = NULL;
	int row, col, rc = sqlite3_open_v2(app_db, &songsDb, SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE, NULL);

	QString SqlQuery = "SELECT number, songs.title, alias, songs.content, key, author, books.title FROM songs";
	SqlQuery.append(" INNER JOIN books ON books.bookid = songs.bookid WHERE songs.songid=" + setsongid);
	QByteArray bar = SqlQuery.toLocal8Bit();
	char* sqlQuery = bar.data();

	if (rc == SQLITE_OK)
	{
		rc = sqlite3_get_table(songsDb, sqlQuery, &qryResult, &row, &col, &err_msg);

		number = *(qryResult + 1 * col + 0);
		title = number + ". " + *(qryResult + 1 * col + 1);
		alias = *(qryResult + 1 * col + 2);
		content = *(qryResult + 1 * col + 3);
		key = *(qryResult + 1 * col + 4);
		author = *(qryResult + 1 * col + 5);
		book = number + "# " + *(qryResult + 1 * col + 6);

		sqlite3_free_table(qryResult);
		sqlite3_close(songsDb);

		ContentPrepare();
	}
}

void vSongView::ContentPrepare()
{
	if (content.contains("CHORUS")) haschorus = true;
	else haschorus = false;

	QStringList tokens = content.split("\\n\\n");

	if (tokens.length() > 1)
	{
		for (int i = 0; i < tokens.length(); i++)
		{
			QString token = tokens[i];
			if (haschorus)
			{
				if (token.contains("CHORUS")) chorus = token.replace("CHORUS\\n", "");
				else songverses1.push_back(token);
			}
			else songverses2.push_back(token);
		}
	}
	
	if (haschorus)
	{
		int k = 1;
		for (std::vector<QString>::iterator i = songverses1.begin(); i != songverses1.end(); ++i) 
		{
			songverses2.push_back(*i);
			songverses2.push_back(chorus);
			slides = slides + 2;

			QString label = "VERSE " + k;
			label.append(" / " + songverses1.size());
			labels.push_back(label);
			labels.push_back("CHORUS ");
			k++;
		}
	}
	else slides = songverses2.size();
	slideindex = 0;
	SetPresentation();
}

void vSongView::SetPresentation()
{
	slideno = slideindex + 1;
	slide = songverses2[slideindex].replace("\\n", "\n\r");
	ui->LblTitle->setText(title);
	ui->LblContent->setText(slide);
	ui->LblKey->setText(key);
	ui->LblAuthor->setText(author);
	ui->LblSongInfo->setText(book);
	ui->LblVerse->setText(labels[slideindex]);

	if (slideindex == 0)
	{
		ui->BtnDown->show();
		ui->BtnUp->hide();
	}

	else if (slideindex == (slides - 1))
	{
		ui->BtnDown->hide();
		ui->BtnUp->show();
	}

	else
	{
		ui->BtnDown->show();
		ui->BtnUp->show();
	}
}

vSongView::~vSongView()
{
    delete ui;
}

void vSongView::on_actionClose_triggered()
{
    this->close();
}

void vSongView::on_BtnClose_clicked()
{
    this->close();
}

void vSongView::on_actionLeft_triggered()
{

}

void vSongView::on_actionRight_triggered()
{

}

void vSongView::on_actionBigger_triggered()
{

}

void vSongView::on_actionSmaller_triggered()
{

}

void vSongView::on_actionFont_triggered()
{

}

void vSongView::on_actionBold_triggered()
{

}

void vSongView::on_actionTheme_triggered()
{

}

void vSongView::on_actionChorus_triggered()
{

}

void vSongView::on_actionUp_triggered()
{

}

void vSongView::on_actionDown_triggered()
{

}


void vSongView::on_BtnDown_clicked()
{

}

void vSongView::on_BtnUp_clicked()
{

}
