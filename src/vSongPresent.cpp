#include "AsBase.h"
#include "AsUtils.h"
#include "vSongPresent.h"
#include "vSongBook.h"
#include "ui_vSongPresent.h"

#include "sqlite.h"
#include "RunSql.h"
#include "sqlitetablemodel.h"

std::vector<QString> songverses1, songverses2, view_set, labels;
int this_book, this_song, slides, slideno, slideindex, mainfont, smallfont, view_font_size;
QString setsong, bookid, songid, number, title, alias, content, key, author, book, chorus, slide, view_fonty;
bool haschorus, isBold;
QFont PresentFont;
QIcon iconWhite, iconBlack;

vSongPresent::vSongPresent(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::vSongPresent)
{
    ui->setupUi(this);
	
	iconWhite.addFile(QString::fromUtf8(":/Down_White.png"), QSize(), QIcon::Normal, QIcon::Off);
	iconBlack.addFile(QString::fromUtf8(":/Down_Black.png"), QSize(), QIcon::Normal, QIcon::Off);

	view_set = AsBase::AppSettings();
	ui->LblApp->setText(qApp->applicationName() + " " + qApp->applicationVersion() + " - " + view_set[1]);
	ReloadSettings();
	if (!AsBase::isTrue(view_set[21].toInt()))
	{
		ui->BtnClose->hide();
	}
    ui->BtnDown->hide();
    ui->BtnUp->hide();
	this_song = view_set[23].toInt();
	PresentSong(view_set[23]);
	SetTheme();
}

void vSongPresent::SetTheme()
{
	int theme = view_set[25].toInt();

	switch (theme)
	{
		case 1:
			ui->WidgetCentral->setStyleSheet("* { background-color: #000000; }");
			ui->statusbar->setStyleSheet("* { background-color: #000000; }");
			ui->LblApp->setStyleSheet("* { color: #FFFFFF; }");
			ui->LblKey->setStyleSheet("* { color: #FFFFFF; }");
			ui->LblTitle->setStyleSheet("* { color: #FFFFFF; }");
			ui->LblContent->setStyleSheet("* { color: #FFFFFF; }");
			ui->LblSongInfo->setStyleSheet("* { color: #FFFFFF; }");
			ui->LblAuthor->setStyleSheet("* { color: #FFFFFF; }");
			ui->LblVerse->setStyleSheet("* { color: #FFFFFF; }");
			ui->BtnDown->setIcon(iconWhite);
			ui->BtnUp->setIcon(iconWhite);
			break;

		case 2:
			ui->WidgetCentral->setStyleSheet("* { background-color: #FFFFFF; }");
			ui->statusbar->setStyleSheet("* { background-color: #FFFFFF; }");
			ui->LblApp->setStyleSheet("* { color: #000000; }");
			ui->LblKey->setStyleSheet("* { color: #000000; }");
			ui->LblTitle->setStyleSheet("* { color: #000000; }");
			ui->LblContent->setStyleSheet("* { color: #000000; }");
			ui->LblSongInfo->setStyleSheet("* { color: #000000; }");
			ui->LblAuthor->setStyleSheet("* { color: #000000; }");
			ui->LblVerse->setStyleSheet("* { color: #000000; }");
			ui->BtnDown->setIcon(iconBlack);
			ui->BtnUp->setIcon(iconBlack);
			break;

		case 3:
			ui->WidgetCentral->setStyleSheet("* { background-color: #000000; }");
			ui->statusbar->setStyleSheet("* { background-color: #000000; }");
			ui->LblApp->setStyleSheet("* { color: #FFFFFF; }");
			ui->LblKey->setStyleSheet("* { color: #FFFFFF; }");
			ui->LblTitle->setStyleSheet("* { color: #FFFFFF; }");
			ui->LblContent->setStyleSheet("* { color: #FFFFFF; }");
			ui->LblSongInfo->setStyleSheet("* { color: #FFFFFF; }");
			ui->LblAuthor->setStyleSheet("* { color: #FFFFFF; }");
			ui->LblVerse->setStyleSheet("* { color: #FFFFFF; }");
			ui->BtnDown->setIcon(iconWhite);
			ui->BtnUp->setIcon(iconWhite);
			break;

		case 4:
			ui->WidgetCentral->setStyleSheet("* { background-color: #FFFFFF; }");
			ui->statusbar->setStyleSheet("* { background-color: #FFFFFF; }");
			ui->LblApp->setStyleSheet("* { color: #000000; }");
			ui->LblKey->setStyleSheet("* { color: #000000; }");
			ui->LblTitle->setStyleSheet("* { color: #000000; }");
			ui->LblContent->setStyleSheet("* { color: #000000; }");
			ui->LblSongInfo->setStyleSheet("* { color: #000000; }");
			ui->LblAuthor->setStyleSheet("* { color: #000000; }");
			ui->LblVerse->setStyleSheet("* { color: #000000; }");
			ui->BtnDown->setIcon(iconBlack);
			ui->BtnUp->setIcon(iconBlack);
			break;

		case 5:
			ui->WidgetCentral->setStyleSheet("* { background-color: #000000; }");
			ui->statusbar->setStyleSheet("* { background-color: #000000; }");
			ui->LblApp->setStyleSheet("* { color: #FFFFFF; }");
			ui->LblKey->setStyleSheet("* { color: #FFFFFF; }");
			ui->LblTitle->setStyleSheet("* { color: #FFFFFF; }");
			ui->LblContent->setStyleSheet("* { color: #FFFFFF; }");
			ui->LblSongInfo->setStyleSheet("* { color: #FFFFFF; }");
			ui->LblAuthor->setStyleSheet("* { color: #FFFFFF; }");
			ui->LblVerse->setStyleSheet("* { color: #FFFFFF; }");
			ui->BtnDown->setIcon(iconWhite);
			ui->BtnUp->setIcon(iconWhite);
			break;

		case 6:
			ui->WidgetCentral->setStyleSheet("* { background-color: #FFFFFF; }");
			ui->statusbar->setStyleSheet("* { background-color: #FFFFFF; }");
			ui->LblApp->setStyleSheet("* { color: #000000; }");
			ui->LblKey->setStyleSheet("* { color: #000000; }");
			ui->LblTitle->setStyleSheet("* { color: #000000; }");
			ui->LblContent->setStyleSheet("* { color: #000000; }");
			ui->LblSongInfo->setStyleSheet("* { color: #000000; }");
			ui->LblAuthor->setStyleSheet("* { color: #000000; }");
			ui->LblVerse->setStyleSheet("* { color: #000000; }");
			ui->BtnDown->setIcon(iconBlack);
			ui->BtnUp->setIcon(iconBlack);
			break;

		case 7:
			ui->WidgetCentral->setStyleSheet("* { background-color: #000000; }");
			ui->statusbar->setStyleSheet("* { background-color: #000000; }");
			ui->LblApp->setStyleSheet("* { color: #FFFFFF; }");
			ui->LblKey->setStyleSheet("* { color: #FFFFFF; }");
			ui->LblTitle->setStyleSheet("* { color: #FFFFFF; }");
			ui->LblContent->setStyleSheet("* { color: #FFFFFF; }");
			ui->LblSongInfo->setStyleSheet("* { color: #FFFFFF; }");
			ui->LblAuthor->setStyleSheet("* { color: #FFFFFF; }");
			ui->LblVerse->setStyleSheet("* { color: #FFFFFF; }");
			ui->BtnDown->setIcon(iconWhite);
			ui->BtnUp->setIcon(iconWhite);
			break;

		case 8:
			ui->WidgetCentral->setStyleSheet("* { background-color: #FFFFFF; }");
			ui->statusbar->setStyleSheet("* { background-color: #FFFFFF; }");
			ui->LblApp->setStyleSheet("* { color: #000000; }");
			ui->LblKey->setStyleSheet("* { color: #000000; }");
			ui->LblTitle->setStyleSheet("* { color: #000000; }");
			ui->LblContent->setStyleSheet("* { color: #000000; }");
			ui->LblSongInfo->setStyleSheet("* { color: #000000; }");
			ui->LblAuthor->setStyleSheet("* { color: #000000; }");
			ui->LblVerse->setStyleSheet("* { color: #000000; }");
			ui->BtnDown->setIcon(iconBlack);
			ui->BtnUp->setIcon(iconBlack);
			break;

		case 9:
			ui->WidgetCentral->setStyleSheet("* { background-color: #000000; }");
			ui->statusbar->setStyleSheet("* { background-color: #000000; }");
			ui->LblApp->setStyleSheet("* { color: #FFFFFF; }");
			ui->LblKey->setStyleSheet("* { color: #FFFFFF; }");
			ui->LblTitle->setStyleSheet("* { color: #FFFFFF; }");
			ui->LblContent->setStyleSheet("* { color: #FFFFFF; }");
			ui->LblSongInfo->setStyleSheet("* { color: #FFFFFF; }");
			ui->LblAuthor->setStyleSheet("* { color: #FFFFFF; }");
			ui->LblVerse->setStyleSheet("* { color: #FFFFFF; }");
			ui->BtnDown->setIcon(iconWhite);
			ui->BtnUp->setIcon(iconWhite);
			break;

		case 10:
			ui->WidgetCentral->setStyleSheet("* { background-color: #FFFFFF; }");
			ui->statusbar->setStyleSheet("* { background-color: #FFFFFF; }");
			ui->LblApp->setStyleSheet("* { color: #000000; }");
			ui->LblKey->setStyleSheet("* { color: #000000; }");
			ui->LblTitle->setStyleSheet("* { color: #000000; }");
			ui->LblContent->setStyleSheet("* { color: #000000; }");
			ui->LblSongInfo->setStyleSheet("* { color: #000000; }");
			ui->LblAuthor->setStyleSheet("* { color: #000000; }");
			ui->LblVerse->setStyleSheet("* { color: #000000; }");
			ui->BtnDown->setIcon(iconBlack);
			ui->BtnUp->setIcon(iconBlack);
			break;

		case 11:
			ui->WidgetCentral->setStyleSheet("* { background-color: #000000; }");
			ui->statusbar->setStyleSheet("* { background-color: #000000; }");
			ui->LblApp->setStyleSheet("* { color: #FFFFFF; }");
			ui->LblKey->setStyleSheet("* { color: #FFFFFF; }");
			ui->LblTitle->setStyleSheet("* { color: #FFFFFF; }");
			ui->LblContent->setStyleSheet("* { color: #FFFFFF; }");
			ui->LblSongInfo->setStyleSheet("* { color: #FFFFFF; }");
			ui->LblAuthor->setStyleSheet("* { color: #FFFFFF; }");
			ui->LblVerse->setStyleSheet("* { color: #FFFFFF; }");
			ui->BtnDown->setIcon(iconWhite);
			ui->BtnUp->setIcon(iconWhite);
			break;

		case 12:
			ui->WidgetCentral->setStyleSheet("* { background-color: #FFFFFF; }");
			ui->statusbar->setStyleSheet("* { background-color: #FFFFFF; }");
			ui->LblApp->setStyleSheet("* { color: #000000; }");
			ui->LblKey->setStyleSheet("* { color: #000000; }");
			ui->LblTitle->setStyleSheet("* { color: #000000; }");
			ui->LblContent->setStyleSheet("* { color: #000000; }");
			ui->LblSongInfo->setStyleSheet("* { color: #000000; }");
			ui->LblAuthor->setStyleSheet("* { color: #000000; }");
			ui->LblVerse->setStyleSheet("* { color: #000000; }");
			ui->BtnDown->setIcon(iconBlack);
			ui->BtnUp->setIcon(iconBlack);
			break;

		case 13:
			ui->WidgetCentral->setStyleSheet("* { background-color: #000000; }");
			ui->statusbar->setStyleSheet("* { background-color: #000000; }");
			ui->LblApp->setStyleSheet("* { color: #FFFFFF; }");
			ui->LblKey->setStyleSheet("* { color: #FFFFFF; }");
			ui->LblTitle->setStyleSheet("* { color: #FFFFFF; }");
			ui->LblContent->setStyleSheet("* { color: #FFFFFF; }");
			ui->LblSongInfo->setStyleSheet("* { color: #FFFFFF; }");
			ui->LblAuthor->setStyleSheet("* { color: #FFFFFF; }");
			ui->LblVerse->setStyleSheet("* { color: #FFFFFF; }");
			ui->BtnDown->setIcon(iconWhite);
			ui->BtnUp->setIcon(iconWhite);
			break;

		case 14:
			ui->WidgetCentral->setStyleSheet("* { background-color: #FFFFFF; }");
			ui->statusbar->setStyleSheet("* { background-color: #FFFFFF; }");
			ui->LblApp->setStyleSheet("* { color: #000000; }");
			ui->LblKey->setStyleSheet("* { color: #000000; }");
			ui->LblTitle->setStyleSheet("* { color: #000000; }");
			ui->LblContent->setStyleSheet("* { color: #000000; }");
			ui->LblSongInfo->setStyleSheet("* { color: #000000; }");
			ui->LblAuthor->setStyleSheet("* { color: #000000; }");
			ui->LblVerse->setStyleSheet("* { color: #000000; }");
			ui->BtnDown->setIcon(iconBlack);
			ui->BtnUp->setIcon(iconBlack);
			break;

		case 15:
			ui->WidgetCentral->setStyleSheet("* { background-color: #000000; }");
			ui->statusbar->setStyleSheet("* { background-color: #000000; }");
			ui->LblApp->setStyleSheet("* { color: #FFFFFF; }");
			ui->LblKey->setStyleSheet("* { color: #FFFFFF; }");
			ui->LblTitle->setStyleSheet("* { color: #FFFFFF; }");
			ui->LblContent->setStyleSheet("* { color: #FFFFFF; }");
			ui->LblSongInfo->setStyleSheet("* { color: #FFFFFF; }");
			ui->LblAuthor->setStyleSheet("* { color: #FFFFFF; }");
			ui->LblVerse->setStyleSheet("* { color: #FFFFFF; }");
			ui->BtnDown->setIcon(iconWhite);
			ui->BtnUp->setIcon(iconWhite);
			break;

	}
}

void vSongPresent::ReloadSettings()
{
	view_font_size = view_set[14].toInt();

	PresentFont.setFamily(view_set[15]);
	PresentFont.setPointSize(view_font_size);
	PresentFont.setBold(AsBase::isTrue(view_set[16].toInt()));
	PresentFont.setWeight(50);

	ReloadControls();	
}

void vSongPresent::ReloadControls()
{
	//ui->LblKey->setFont(PresentFont);
	ui->LblTitle->setFont(PresentFont);
	//ui->LblSongInfo->setFont(PresentFont);
	//ui->LblVerse->setFont(PresentFont);
	ui->LblContent->setFont(PresentFont);
}

void vSongPresent::PresentSong(QString setsongid)
{
	slides = 0;
	if (songverses1.size() > 0) songverses1.clear();
	if (songverses2.size() > 0) songverses2.clear();

	sqlite3* songsDb;
	char* err_msg = NULL, ** qryResult = NULL;
	int row, col, rc = sqlite3_open_v2(AsUtils::APP_DB(), &songsDb, SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE, NULL);
	
	QByteArray bar = AsUtils::SONG_SINGLE_SQL(setsongid).toLocal8Bit();
	char* sqlQuery = bar.data();
	rc = sqlite3_get_table(songsDb, sqlQuery, &qryResult, &row, &col, &err_msg);

	if (rc == SQLITE_OK)
	{
		number = *(qryResult + 1 * col + 2);
		title = number + ". " + *(qryResult + 1 * col + 4);
		alias = *(qryResult + 1 * col + 3);
		content = *(qryResult + 1 * col + 6);
		key = *(qryResult + 1 * col + 7);
		author = *(qryResult + 1 * col + 8);
		book = number + "# " + *(qryResult + 1 * col + 12);

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

			QString label = "VERSE " + QString::number(k);
			label.append(" / " + QString::number(songverses1.size()));
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
		ui->LblBottom->show();
		ui->BtnUp->hide();
	}

	else if (slideindex == (slides - 1))
	{
		ui->BtnDown->hide();
		ui->LblBottom->show();
		ui->BtnUp->show();
	}

	else
	{
		ui->BtnDown->show();
		ui->LblBottom->hide();
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
	if ((view_font_size - 2) > 9)
	{
		view_font_size = view_font_size - 2;
		PresentFont.setPointSize(view_font_size);
		AsBase::SetOption("present_font_size", QString::number(view_font_size));
		ReloadControls();
	}
}

void vSongPresent::on_actionRight_triggered()
{
	if ((view_font_size + 2) < 99)
	{
		view_font_size = view_font_size + 2;
		PresentFont.setPointSize(view_font_size);
		AsBase::SetOption("present_font_size", QString::number(view_font_size));
		ReloadControls();
	}
}

void vSongPresent::on_actionBigger_triggered()
{
	if ((view_font_size + 2) < 99)
	{
		view_font_size = view_font_size + 2;
		PresentFont.setPointSize(view_font_size);
		AsBase::SetOption("present_font_size", QString::number(view_font_size));
		ReloadControls();
	}
}

void vSongPresent::on_actionSmaller_triggered()
{
	if ((view_font_size - 2) > 9)
	{
		view_font_size = view_font_size - 2;
		PresentFont.setPointSize(view_font_size);
		AsBase::SetOption("present_font_size", QString::number(view_font_size));
		ReloadControls();
	}
}

void vSongPresent::on_actionFont_triggered()
{

}

void vSongPresent::on_actionBold_triggered()
{
	if (isBold) isBold = false;
	else isBold = true;
	PresentFont.setBold(isBold);
	ReloadControls();
}

void vSongPresent::on_actionTheme_triggered()
{

}

void vSongPresent::on_actionChorus_triggered()
{

}

void vSongPresent::on_actionUp_triggered()
{
	if (slideindex != 0)
	{
		slideindex = slideindex - 1;
		SetPresentation();
	}
}

void vSongPresent::on_actionDown_triggered()
{
	if (slideindex != (slides - 1))
	{
		slideindex = slideindex + 1;
		SetPresentation();
	}
}

void vSongPresent::on_BtnUp_clicked()
{
	if (slideindex != 0)
	{
		slideindex = slideindex - 1;
		SetPresentation();
	}
}

void vSongPresent::on_BtnDown_clicked()
{
	if (slideindex != (slides - 1))
	{
		slideindex = slideindex + 1;
		SetPresentation();
	}
}

