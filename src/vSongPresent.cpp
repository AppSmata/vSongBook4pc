#include "AsBase.h"
#include "AsUtils.h"
#include "vSongPresent.h"
#include "vSongBook.h"
#include "ui_vSongPresent.h"

#include "sqlite.h"
#include "RunSql.h"
#include "sqlitetablemodel.h"

char* app_db = "Data/vSongBook.db";
std::vector<QString> songverses1, songverses2, viewset, labels;
int this_book, this_song, slides, slideno, slideindex, mainfont, smallfont;
QString setsong, bookid, songid, number, title, alias, content, key, author, book, chorus, slide, view_fonty;
bool haschorus;

vSongPresent::vSongPresent(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::vSongPresent)
{
	GetSettings();
	ReloadSettings();

    ui->setupUi(this);
    ui->BtnClose->hide();
    ui->BtnDown->hide();
    ui->BtnUp->hide();

	PresentSong(viewset[23]);
}

bool vSongPresent::GetSettings()
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

void vSongPresent::ReloadSettings()
{
	
}

void vSongPresent::PresentSong(QString setsongid)
{
	slides = 0;
	if (songverses1.size() > 0) songverses1.clear();
	if (songverses2.size() > 0) songverses2.clear();

	sqlite3* songsDb;
	char* err_msg = NULL, ** qryResult = NULL;
	int row, col, rc = sqlite3_open_v2(app_db, &songsDb, SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE, NULL);
	
	QByteArray bar = AsUtils::SONG_SINGLE_SQL(setsongid).toLocal8Bit();
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

void vSongPresent::ContentPrepare()
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

void vSongPresent::SetPresentation()
{
	slideno = slideindex + 1;
	slide = songverses2[slideindex];
	ui->LblTitle->setText(AsBase::ReplaceView(title));
	ui->LblContent->setText(AsBase::ReplaceView(slide));
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

vSongPresent::~vSongPresent()
{
    delete ui;
}

void vSongPresent::on_actionClose_triggered()
{
    this->close();
}

void vSongPresent::on_BtnClose_clicked()
{
    this->close();
}

void vSongPresent::on_actionLeft_triggered()
{

}

void vSongPresent::on_actionRight_triggered()
{

}

void vSongPresent::on_actionBigger_triggered()
{

}

void vSongPresent::on_actionSmaller_triggered()
{

}

void vSongPresent::on_actionFont_triggered()
{

}

void vSongPresent::on_actionBold_triggered()
{

}

void vSongPresent::on_actionTheme_triggered()
{

}

void vSongPresent::on_actionChorus_triggered()
{

}

void vSongPresent::on_actionUp_triggered()
{

}

void vSongPresent::on_actionDown_triggered()
{

}


void vSongPresent::on_BtnDown_clicked()
{

}

void vSongPresent::on_BtnUp_clicked()
{

}
