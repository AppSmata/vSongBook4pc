#include "Application.h"
#include "AppMain.h"
#include "ui_AppMain.h"

/*#include "AsBase.h"
#include "AsUtils.h"
#include "sqlite.h"
#include "RunSql.h"
#include "sqlitetablemodel.h"

#include <QWhatsThis>
#include <QMessageBox>
#include <limits>
#include <QStandardItemModel>
#include <QObject>

#include "AsItem.h"
#include "AsDelegate.h"

#include "AppSongbooks.h"
#include "AppEditor.h"
#include "AppPreferences.h"
#include "AppOnline.h"
#include "AppPresent.h"*/

#include "AppAbout.h"
#include "AppTutorial.h"

int home_fontgen, home_fontprev, home_fonttype;
bool isReady, searchAll, isDarkMode, isPreviewBold;
QString selected_book, selected_song, search_term;
std::vector<QString> bookids, songids, booktitles, songtitles, songaliases, songcontents, songbooks, bookcodes, histories;
std::vector<QString> home_fonts, home_sets;

QFont HomeFontPreview, HomeFontGeneral;

AppMain::AppMain(QWidget* parent) : QMainWindow(parent), ui(new Ui::AppMain)
{
	ui->setupUi(this);
	ui->SplitterMain->setStretchFactor(1, 3);
	isReady = false;

	ui->line->hide();
	ui->ChkDarkMode->hide();

	this->setWindowTitle(qApp->applicationName() + " v" + qApp->applicationVersion());

	/*if (QFile::exists(AsUtils::DB_FILE())) HomeInit();
	else
	{
        QDir().mkdir("Data");
		db.create(AsUtils::DB_FILE());
		AsBase::InitialDbOps();
		HomeInit();
	}*/
}

/*void AppMain::HomeInit()
{
	home_sets = AsBase::AppSettings();
	ReloadSettings();

	if (PopulateSongbooks())
	{
		if (ui->CmbSongbooks->count() > 0)
		{
			PopulateSonglists("");
			isReady = true;
		}
		else
		{
			AppOnline online(this);
			online.exec();
		}
	}
	else {
		QMessageBox::warning(this, qApp->applicationName(), tr("Oops! vSongBook could not generate view due to unknown error at the moment"));
	}
}

void AppMain::ReloadSettings()
{
	isPreviewBold = AsBase::isTrue(home_sets[13].toInt());
	searchAll = AsBase::isTrue(home_sets[24].toInt());
	isDarkMode = AsBase::isTrue(home_sets[26].toInt());

	home_fontgen = home_sets[8].toInt();
	home_fontprev = home_sets[11].toInt();

	HomeFontGeneral.setFamily(home_sets[9]);
	HomeFontGeneral.setPointSize(home_fontgen);
	HomeFontGeneral.setBold(AsBase::isTrue(home_sets[10].toInt()));
	HomeFontGeneral.setWeight(50);

	HomeFontPreview.setFamily(home_sets[12]);
	HomeFontPreview.setPointSize(home_fontprev);
	HomeFontPreview.setBold(isPreviewBold);
	HomeFontPreview.setWeight(50);

	home_fonts.push_back("Arial");
	home_fonts.push_back("Calibri");
	home_fonts.push_back("Century Gothic");
	home_fonts.push_back("Comic Sans MS");
	home_fonts.push_back("Corbel");
	home_fonts.push_back("Courier New");
	home_fonts.push_back("Palatino");
	home_fonts.push_back("Linotype");
	home_fonts.push_back("Tahoma");
	home_fonts.push_back("Tempus Sans ITC");
	home_fonts.push_back("Times New Roman");
	home_fonts.push_back("Trebuchet MS");
	home_fonts.push_back("Verdana");

	if (home_sets[12] == "Arial") home_fonttype = 1;
	else if (home_sets[12] == "Calibri") home_fonttype = 2;
	else if (home_sets[12] == "Century Gothic") home_fonttype = 3;
	else if (home_sets[12] == "Comic Sans MS") home_fonttype = 4;
	else if (home_sets[12] == "Corbel") home_fonttype = 5;
	else if (home_sets[12] == "Courier New") home_fonttype = 6;
	else if (home_sets[12] == "Palatino") home_fonttype = 7;
	else if (home_sets[12] == "Linotype") home_fonttype = 8;
	else if (home_sets[12] == "Tahoma") home_fonttype = 9;
	else if (home_sets[12] == "Tempus Sans ITC") home_fonttype = 10;
	else if (home_sets[12] == "Trebuchet MS") home_fonttype = 11;
	else if (home_sets[12] == "Verdana") home_fonttype = 12;

	ReloadControls();
	SetDarkMode();
}

void AppMain::ReloadControls()
{
	ui->ChkSearchCriteria->setChecked(searchAll);
	ui->actionSearchAll->setChecked(searchAll);
	ui->ChkDarkMode->setChecked(isDarkMode);
	ui->actionDarkMode->setChecked(isDarkMode);

	ui->TxtSearch->setFont(HomeFontGeneral);
	ui->CmbSongbooks->setFont(HomeFontGeneral);

	ui->TxtPreviewTitle->setFont(HomeFontPreview);
	ui->TxtPreviewContent->setFont(HomeFontPreview);
	ui->TxtPreviewAlias->setFont(HomeFontPreview);
}

void AppMain::FontChange()
{
	switch (home_fonttype)
	{
		case 12:
			home_fonttype = 1;
			HomeFontPreview.setFamily(home_fonts[home_fonttype]);
			AsBase::SetOption("preview_font_type", home_fonts[home_fonttype]);
			ReloadControls();
                        break;

		default:
			home_fonttype = home_fonttype + 1;
			HomeFontPreview.setFamily(home_fonts[home_fonttype]);
			AsBase::SetOption("preview_font_type", home_fonts[home_fonttype]);
			ReloadControls();
                        break;
	}
}

void AppMain::FontSmaller()
{
	if ((home_fontprev - 2) > 9)
	{
		home_fontprev = home_fontprev - 2;
		HomeFontPreview.setPointSize(home_fontprev);
		AsBase::SetOption("preview_font_size", QString::number(home_fontprev));
		ReloadControls();
	}
}

void AppMain::FontBigger()
{
	if ((home_fontprev + 2) < 51)
	{
		home_fontprev = home_fontprev + 2;
		HomeFontPreview.setPointSize(home_fontprev);
		AsBase::SetOption("preview_font_size", QString::number(home_fontprev));
		ReloadControls();
	}
}

void AppMain::FontBold()
{
	if (isPreviewBold) isPreviewBold = false;
	else isPreviewBold = true;
	HomeFontPreview.setBold(isPreviewBold);
	ReloadControls();
}

void AppMain::on_CmbSongbooks_currentIndexChanged(int index)
{
	if (isReady) PopulateSonglists("");
}

bool AppMain::PopulateSongbooks()
{
	bool retval = false;
	if (ui->CmbSongbooks->count() > 0) ui->CmbSongbooks->clear();

	sqlite3* songsDb;
	char* err_msg = NULL, ** qryResult = NULL;
	int row, col;
	int rc = sqlite3_open_v2(AsUtils::APP_DB(), &songsDb, SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE, NULL);

	QByteArray bar = AsUtils::BOOK_LIST_SQL("1").toLocal8Bit();
	char* sqlQuery = bar.data();
	
	if (rc == SQLITE_OK)
	{
		rc = sqlite3_get_table(songsDb, sqlQuery, &qryResult, &row, &col, &err_msg);

		for (int i = 1; i < row + 1; i++)
		{
			QString title = *(qryResult + i * col + 3);
			QString songs = *(qryResult + i * col + 5);

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

void AppMain::SetDarkMode()
{
	/ *if (isDarkMode)
	{
		ui->WidgetCentral->setStyleSheet("* { background-color: #000000; color: #FFFFFF; }");
		ui->statusbar->setStyleSheet("* { background-color: #000000; color: #FFFFFF; }");
	}
	else
	{
		ui->WidgetCentral->setStyleSheet("* { background-color: #FFFFFF; color: #000000; }");
		ui->statusbar->setStyleSheet("* { background-color: #FFFFFF; color: #000000; }");
	}
	delete ui;
	ui->setupUi(this);
	ui->SplitterMain->setStretchFactor(1, 3);
	isReady = false;

	this->setWindowTitle(qApp->applicationName() + " " + qApp->applicationVersion());

	if (QFile::exists(AsUtils::DB_FILE())) HomeInit();
	else
	{
		db.create(AsUtils::DB_FILE());
		AsBase::InitialDbOps();
		HomeInit();
	}* /
}

void AppMain::PopulateSonglists(QString SearchStr)
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

	QString ResultCount = " songs in: " + booktitles[ui->CmbSongbooks->currentIndex()];

	sqlite3* db;
	char* err_msg = NULL, ** qryResult = NULL;
	int row, col, rc = sqlite3_open_v2(AsUtils::APP_DB(), &db, SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE, NULL);

	if (!SearchStr.isEmpty())
	{
            ResultCount = " ";
            bool isNumeric;
            SearchStr.toInt(&isNumeric, 10);
            if (isNumeric) ResultCount.append("songs found with number: " + SearchStr + "#");
            else ResultCount.append("songs found with: \"" + SearchStr + "\"");
	}

	QString SqlQuery = AsUtils::SONG_SEARCH_SQL(SearchStr, bookids[ui->CmbSongbooks->currentIndex()], searchAll);
	QByteArray bar = SqlQuery.toLocal8Bit();
	char* sqlQuery = bar.data();

	rc = sqlite3_get_table(db, sqlQuery, &qryResult, &row, &col, &err_msg);

	int songcount = 0;
	for (int i = 1; i < row + 1; i++)
	{
		QString numberstr = *(qryResult + i * col + 2);
		QString titlestr = *(qryResult + i * col + 4);
		QString titles = numberstr + "# " + titlestr;
		QString contents = *(qryResult + i * col + 6);

		if (SearchStr.isEmpty()) strList.append(titles);
		else strList.append(titles + " (" + *(qryResult + i * col + 10) + ")");

		songids.push_back(*(qryResult + i * col + 0));
		songtitles.push_back(titles);
		songaliases.push_back(*(qryResult + i * col + 3));
		songcontents.push_back(contents);
		songbooks.push_back(*(qryResult + i * col + 10));

		titles = AsBase::ReplaceList(titles);
		contents = AsBase::ReplaceList(contents);

		QStandardItem* songItem = new QStandardItem;
		AsItem song;

		if (titles.length() > 40) song.title = titles.left(35) + "...";
		else song.title = titles;

		if (contents.length() > 40) song.content = contents.left(35) + "...";
		else song.content = contents;

		songItem->setData(QVariant::fromValue(song), Qt::UserRole + 1);
		songModel->appendRow(songItem);
		songcount++;
	}

	ui->LblResult->setText(QString::number(songcount) + ResultCount);
	AsDelegate* itemDelegate = new AsDelegate(this);
	ui->LstResults->setItemDelegate(itemDelegate);
	ui->LstResults->setModel(songModel);
	ui->LstResults->setSpacing(1);
	ui->LstResults->setStyleSheet("* { background-color: #D3D3D3; }");

	sqlite3_free_table(qryResult);
	sqlite3_close(db);

	if (songcount > 0)
	{
		ui->LstResults->setCurrentIndex(songModel->index(0, 0));
		OpenSongPreview(songModel->index(0, 0));
	}
}

void AppMain::OpenSongPreview(const QModelIndex& index)
{
	int song = index.row();
	QString songTitle = AsBase::ReplaceView(songtitles[song]);
	QString songAlias = AsBase::ReplaceView(songaliases[song]);
	QString songContent = AsBase::ReplaceView(songcontents[song]);

	AsBase::SetOption("current_song", songids[song]);

	ui->TxtPreviewTitle->setText(songTitle);
	ui->TxtPreviewContent->setPlainText(songContent);

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

void AppMain::on_TxtSearch_returnPressed()
{
	PopulateSonglists(ui->TxtSearch->text());
}

void AppMain::on_TxtSearch_textChanged(const QString& SearchStr)
{
	PopulateSonglists(SearchStr);
}

void AppMain::on_LstResults_clicked(const QModelIndex& index)
{
	OpenSongPreview(index);
}

void AppMain::on_LstResults_activated(const QModelIndex& index)
{
	OpenSongPreview(index);
}

void AppMain::on_LstResults_doubleClicked(const QModelIndex& index)
{
	OpenSongPreview(index);
	AppPresent* present = new AppPresent();
	present->showFullScreen();
}

void AppMain::on_actionPresent_triggered()
{
	AppPresent* present = new AppPresent();
	present->showFullScreen();
}

void AppMain::on_actionBold_Text_triggered()
{
    FontBold();
}

void AppMain::on_actionChange_Font_triggered()
{
	FontChange();
}

void AppMain::on_actionSmaller_Font_triggered()
{
    FontSmaller();
}

void AppMain::on_actionBigger_Font_triggered()
{
    FontBigger();
}

void AppMain::on_actionCheck_Updates_triggered()
{

}

void AppMain::on_actionContribute_triggered()
{

}

void AppMain::on_actionDonate_triggered()
{

}

void AppMain::on_actionDelete_Song_triggered()
{

}

void AppMain::on_actionEdit_Song_triggered()
{
    AppEditor editor(this, false);
    editor.exec();
}

void AppMain::on_actionNew_Song_triggered()
{
	AppEditor editor(this, true);
	editor.exec();
}

void AppMain::on_actionManage_Settings_triggered()
{
	AppPreferences options(this);
	options.exec();
}

void AppMain::on_actionReset_Settings_triggered()
{
    AsBase::ResetSettings();
	this->close();
}

void AppMain::on_actionBold_triggered()
{
	FontBold();
}

void AppMain::on_actionSmaller_triggered()
{
	FontSmaller();
}

void AppMain::on_actionBigger_triggered()
{
	FontBigger();
}

void AppMain::on_actionDelete_triggered()
{

}

void AppMain::on_actionPreferences_triggered()
{
	AppPreferences options(this);
	options.exec();
}


void AppMain::on_actionEdit_triggered()
{
	AppEditor editor(this, false);
	editor.exec();
}

void AppMain::on_actionNewsong_triggered()
{
	AppEditor editor(this, true);
	editor.exec();
}

void AppMain::on_actionSongbooks_triggered()
{
	AppSongbooks books(this);
	books.exec();
}

void AppMain::on_actionOnline_triggered()
{
	AppOnline online(this);
	online.exec();
}

void AppMain::on_actionFont_triggered()
{
	FontChange();
}

void AppMain::on_actionSearch_triggered()
{
	ui->TxtSearch->setFocus();
}

void AppMain::on_actionSearchAll_triggered()
{
	if (searchAll)
	{
		searchAll = false;
		AsBase::SetOption("search_allbooks", "0");
	}
	else
	{
		searchAll = true;
		AsBase::SetOption("search_allbooks", "1");
	}
	ui->ChkSearchCriteria->setChecked(searchAll);
	ui->actionSearchAll->setChecked(searchAll);
}


void AppMain::on_ChkSearchCriteria_clicked()
{
	if (searchAll)
	{
		searchAll = false;
		AsBase::SetOption("search_allbooks", "0");
	}
	else
	{
		searchAll = true;
		AsBase::SetOption("search_allbooks", "1");
	}
	ui->ChkSearchCriteria->setChecked(searchAll);
	ui->actionSearchAll->setChecked(searchAll);
}

void AppMain::on_actionDarkMode_triggered()
{
	if (isDarkMode)
	{
		isDarkMode = false;
		AsBase::SetOption("dark_mode", "0");
	}
	else
	{
		isDarkMode = true;
		AsBase::SetOption("dark_mode", "1");
	}
	ui->ChkDarkMode->setChecked(isDarkMode);
	ui->actionDarkMode->setChecked(isDarkMode);
	SetDarkMode();
}

void AppMain::on_ChkDarkMode_clicked()
{
	if (isDarkMode)
	{
		isDarkMode = false;
		AsBase::SetOption("dark_mode", "0");
	}
	else
	{
		isDarkMode = true;
		AsBase::SetOption("dark_mode", "1");
	}
	ui->ChkDarkMode->setChecked(isDarkMode);
	ui->actionDarkMode->setChecked(isDarkMode);
	SetDarkMode();
}*/

void AppMain::on_actionAbout_triggered()
{
	AppAbout about(this);
	about.exec();
}

void AppMain::on_actionTutorial_triggered()
{
	AppTutorial tutorial(this);
	tutorial.exec();
}

void AppMain::on_actionExit_triggered()
{
	this->close();
}

AppMain::~AppMain()
{
	delete ui;
}
