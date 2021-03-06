#include <Application.h>
#include <src\ui\AppHome.h>
#include <ui_AppHome.h>

#include <AsBase.h>
#include <AsUtils.h>
#include <sqlite.h>
#include <RunSql.h>
#include <sqlitetablemodel.h>

#include <QWhatsThis>
#include <QMessageBox>
#include <limits>
#include <QStandardItemModel>
#include <QObject>

#include <AsItem.h>
#include <AsDelegate.h>

#include <src\AsException.h>
#include <src\ui\AppAbout.h>
#include <src\ui\AppSongbooks.h>
#include <src\ui\AppEditor.h>
#include <src\ui\AppPreferences.h>
#include <src\ui\AppOnline.h>
#include <src\ui\AppPresent.h>
#include <src\ui\AppTutorial.h>

int home_fontgen, home_fontprev, home_fonttype, selectedbook;
bool isReady, searchAll, isDarkMode, isPreviewBold;
QString selected_book, selected_song, search_term;
std::vector<QString> bookcats, songids, booktitles, songtitles, songaliases, songcontents, songbooks, bookcodes, histories, home_fonts, home_sets;
TabbedWindow* mtab;
QFont HomeFontPreview, HomeFontGeneral;

AppHome::AppHome(TabbedWindow* parent) :
	QMainWindow(parent), ui(new Ui::AppHome)
{
	ui->setupUi(this);
	ui->SplitterMain->setStretchFactor(1, 3);
	isReady = false;

	mtab = parent;
	ui->line->hide();
	ui->ChkDarkMode->hide();

	this->setWindowTitle(qApp->applicationName() + " v" + qApp->applicationVersion());

	if (QFile::exists(AsUtils::DbNameQstr())) HomeInit();
	else
	{
		AsBase::WriteLogs("Files", "Database was not found, resorting to creating a new one", "", "");
        QDir().mkdir("data");
		db.create(AsUtils::DbNameQstr());
		AsBase::InitialDbOps();
		HomeInit();
	}
}

// Initilizing Database Operations
void AsBase::InitialDbOps()
{
    AsBase::execSql(AsUtils::CreateBooksTableSql());
    AsBase::execSql(AsUtils::CreateHistoryTableSql());
    AsBase::execSql(AsUtils::CreateSettingsNaviTableSql());
    AsBase::execSql(AsUtils::CreateSettingsTableSql());
    AsBase::execSql(AsUtils::CreateSongsTableSql());

    AsBase::execSql(AsUtils::SettingsNaviSql());    
    AsBase::execSql(AsUtils::SettingsSql());
}

// Initializing Home Window
void AppHome::HomeInit()
{
	AsBase::WriteLogs("App Events", "Fetching App Settings", "", "");
	home_sets = AsBase::AppSettings();

	if (home_sets.size() != 0)
	{
		AsBase::WriteLogs("App Events", "App Settings fetched successfully", "", "");
		ReloadSettings();
	}
	else AsBase::WriteLogs("App Events", "App Settings fetching was unsuccessful", "", "");
	
	if (PopulateSongbooks())
	{
		if (ui->CmbSongbooks->count() > 0)
		{
			PopulateSonglists("");
			isReady = true;
		}
		else
		{
			AsBase::WriteLogs("Data", "Database is empty, resorting to going online", "", "");
			AppOnline online(this);
			online.exec();
			HomeResume();
		}
	}
	else {
		QMessageBox::warning(this, qApp->applicationName(), tr("Oops! vSongBook could not generate view due to an unknown error at the moment"));
		AsBase::WriteLogs("App Events", "Oops! vSongBook could not generate view due to an unknown error at the moment", "", "");
	}
}

void AppHome::HomeResume()
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
			AsBase::WriteLogs("Data", "Database is empty, resorting to user actions", "", "");
		}
	}
	else {
		QMessageBox::warning(this, qApp->applicationName(), tr("Oops! vSongBook could not generate view due to unknown error at the moment"));
	}
}

// Reload App Settings when changes are made
void AppHome::ReloadSettings()
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

	//ReloadControls();
}

// Reload controls with updated settings
void AppHome::ReloadControls()
{
	ui->ChkSearchCriteria->setChecked(searchAll);
	ui->actionSearchAll->setChecked(searchAll);
	ui->ChkDarkMode->setChecked(isDarkMode);
	ui->actionDarkMode->setChecked(isDarkMode);

	ui->TxtSearch->setFont(HomeFontGeneral);

	ui->TxtPreviewTitle->setFont(HomeFontPreview);
	ui->TxtPreviewContent->setFont(HomeFontPreview);
	ui->TxtPreviewAlias->setFont(HomeFontPreview);
}

// Changing of font of the song preview
void AppHome::FontChange()
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

// Reduce Preview Font Size
void AppHome::FontSmaller()
{
	if ((home_fontprev - 2) > 9)
	{
		home_fontprev = home_fontprev - 2;
		HomeFontPreview.setPointSize(home_fontprev);
		AsBase::SetOption("preview_font_size", QString::number(home_fontprev));
		ReloadControls();
	}
}

void AppHome::FontBigger()
{
	if ((home_fontprev + 2) < 51)
	{
		home_fontprev = home_fontprev + 2;
		HomeFontPreview.setPointSize(home_fontprev);
		AsBase::SetOption("preview_font_size", QString::number(home_fontprev));
		ReloadControls();
	}
}

void AppHome::FontBold()
{
	if (isPreviewBold) isPreviewBold = false;
	else isPreviewBold = true;
	HomeFontPreview.setBold(isPreviewBold);
	ReloadControls();
}

void AppHome::on_CmbSongbooks_currentIndexChanged(int index)
{
    selectedbook = index;
    if (isReady) PopulateSonglists("");
}

bool AppHome::PopulateSongbooks()
{
	bool retval = false;
	if (ui->CmbSongbooks->count() > 0) ui->CmbSongbooks->clear();

	sqlite3* songsDb;
	char* zErrMsg = NULL, ** qryResult = NULL;
    int row, col, rc = sqlite3_open_v2(AsUtils::DbNameChar(), &songsDb, SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE, NULL);

	QByteArray bar = AsUtils::BookListSql("1").toLocal8Bit();
	char* sqlQuery = bar.data();
	
	if (rc == SQLITE_OK)
	{
		rc = sqlite3_get_table(songsDb, sqlQuery, &qryResult, &row, &col, &zErrMsg);
		if (rc == SQLITE_OK)
			AsBase::WriteLogs("Database", "Db query to fetch books executed successfully", sqlQuery, zErrMsg);
		else
			AsBase::WriteLogs("Database", "Failed to execute db query to fetch books", sqlQuery, zErrMsg);

		for (int i = 1; i < row + 1; i++)
		{
			QString title = *(qryResult + i * col + 3);
			QString songs = *(qryResult + i * col + 5);

			ui->CmbSongbooks->addItem(title + " (" + songs + ")");

			bookcats.push_back(*(qryResult + i * col + 1));
			booktitles.push_back(title);
		}
		sqlite3_free_table(qryResult);
		sqlite3_free(zErrMsg);
		sqlite3_close(songsDb);
		ui->CmbSongbooks->setCurrentIndex(0);
		retval = true;
	}
	else AsBase::WriteLogs("Database Error", "Database operation failed to execute", sqlQuery, zErrMsg);
	return retval;
}

void AppHome::PopulateSonglists(QString SearchStr)
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

	QString ResultCount = " songs found in: " + booktitles[ui->CmbSongbooks->currentIndex()];

	sqlite3* songsDb;
    char* zErrMsg = NULL, ** qryResult = NULL;

	if (!SearchStr.isEmpty())
	{
        ResultCount = " ";
        bool isNumeric;
        SearchStr.toInt(&isNumeric, 10);
        if (isNumeric) ResultCount.append("songs found with number: " + SearchStr + "#");
        else ResultCount.append("songs found with: \"" + SearchStr + "\"");
    }
    int row, col, rc = sqlite3_open_v2(AsUtils::DbNameChar(), &songsDb, SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE, NULL);
    QString SqlQuery = AsUtils::SongSearchSql(SearchStr, bookcats[selectedbook], searchAll);
	QByteArray bar = SqlQuery.toLocal8Bit();
	char* sqlQuery = bar.data();

    if (rc == SQLITE_OK)
    {
        rc = sqlite3_get_table(songsDb, sqlQuery, &qryResult, &row, &col, &zErrMsg);
		if (rc == SQLITE_OK)
			AsBase::WriteLogs("Database", "Db query to fetch songs executed successfully", sqlQuery, zErrMsg);
		else
			AsBase::WriteLogs("Database", "Failed to execute db query to fetch songs", sqlQuery, zErrMsg);

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

            if (titles.length() > 40) song.title = titles.left(40) + " ...";
            else song.title = titles;

            song.content = contents.left(50) + "...";

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
		sqlite3_free(zErrMsg);
        sqlite3_close(songsDb);

        if (songcount > 0)
        {
            ui->LstResults->setCurrentIndex(songModel->index(0, 0));
            OpenSongPreview(songModel->index(0, 0));
        }
    }
	else AsBase::WriteLogs("Database Error", "Database operation failed to execute", sqlQuery, zErrMsg);
}

void AppHome::OpenSongPreview(const QModelIndex& index)
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

void AppHome::on_TxtSearch_returnPressed()
{
	PopulateSonglists(ui->TxtSearch->text());
}

void AppHome::on_TxtSearch_textChanged(const QString& SearchStr)
{
	PopulateSonglists(SearchStr);
}

void AppHome::on_LstResults_clicked(const QModelIndex& index)
{
	OpenSongPreview(index);
}

void AppHome::on_LstResults_activated(const QModelIndex& index)
{
	OpenSongPreview(index);
}

void AppHome::on_LstResults_doubleClicked(const QModelIndex& index)
{
	OpenSongPreview(index);
	AppPresent* present = new AppPresent();
	present->showFullScreen();
}

void AppHome::on_actionPresent_triggered()
{
	AppPresent* present = new AppPresent();
	present->showFullScreen();
}

void AppHome::on_actionBold_Text_triggered()
{
    FontBold();
}

void AppHome::on_actionChange_Font_triggered()
{
	FontChange();
}

void AppHome::on_actionSmaller_Font_triggered()
{
    FontSmaller();
}

void AppHome::on_actionBigger_Font_triggered()
{
    FontBigger();
}

void AppHome::on_actionCheck_Updates_triggered()
{

}

void AppHome::on_actionContribute_triggered()
{

}

void AppHome::on_actionDonate_triggered()
{

}

void AppHome::on_actionDelete_Song_triggered()
{

}

void AppHome::on_actionEdit_Song_triggered()
{
    AppEditor editor(this, false);
    editor.exec();
}

void AppHome::on_actionNew_Song_triggered()
{
	AppEditor editor(this, true);
	editor.exec();
}

void AppHome::on_actionManage_Settings_triggered()
{
	AppPreferences* preferences = new AppPreferences();
	mtab->addView(preferences, QString("Manage Preferences"));
}

void AppHome::on_actionReset_Settings_triggered()
{
    AsBase::ResetSettings();
	this->close();
}

void AppHome::on_actionAbout_triggered()
{
	AppAbout about(this);
	about.exec();
}

void AppHome::on_actionExit_triggered()
{
	this->close();
}

void AppHome::on_actionBold_triggered()
{
	FontBold();
}

void AppHome::on_actionSmaller_triggered()
{
	FontSmaller();
}

void AppHome::on_actionBigger_triggered()
{
	FontBigger();
}

void AppHome::on_actionPreferences_triggered()
{
	AppPreferences* preferences = new AppPreferences();
	mtab->addView(preferences, QString("Manage Preferences"));
}

void AppHome::on_actionEdit_triggered()
{
	AppEditor editor(this, false);
	editor.exec();
}

void AppHome::on_actionNewsong_triggered()
{
	AppEditor editor(this, true);
	editor.exec();
}

void AppHome::on_actionSongbooks_triggered()
{
	AppSongbooks books(this);
	books.exec();
}

void AppHome::on_actionOnline_triggered()
{
	AppOnline* online = new AppOnline();
	online->show();
}

void AppHome::on_actionTutorial_triggered()
{
	AppTutorial* tutorial = new AppTutorial();
	tutorial->show();
}

void AppHome::on_actionFont_triggered()
{
	FontChange();
}

void AppHome::on_actionSearch_triggered()
{
	ui->TxtSearch->setFocus();
}

void AppHome::on_actionSearchAll_triggered()
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


void AppHome::on_ChkSearchCriteria_clicked()
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

void AppHome::on_actionDarkMode_triggered()
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
}

void AppHome::on_ChkDarkMode_clicked()
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
}

AppHome::~AppHome()
{
	delete ui;
}
