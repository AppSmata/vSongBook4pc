#include "vSongBook.h"
#include "vSongHome.h"
#include "ui_vSongHome.h"
#include "vSongBook.h"

#include "AsBase.h"
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
#include "AboutDialog.h"
#include "vSongBooklist.h"
#include "vSongEditor.h"
#include "vSongPreferences.h"
#include "vSongOnline.h"
#include "vSongPresent.h"
#include "vSongTutorial.h"

int home_fontgen, home_fontprev;
bool isReady, SearchAll, NightMode, isPreviewBold;
QString selected_book, selected_song, search_term;
std::vector<QString> bookids, songids, booktitles, songtitles, songaliases, songcontents, songbooks, bookcodes, histories, home_sets;

QFont HomeFontPreview, HomeFontGeneral;

vSongHome::vSongHome(QWidget* parent) : QMainWindow(parent), ui(new Ui::vSongHome)
{
	ui->setupUi(this);
	ui->SplitterMain->setStretchFactor(1, 3);
	isReady = isPreviewBold = false;

	this->setWindowTitle(qApp->applicationName() + " " + qApp->applicationVersion());

	if (QFile::exists(AsUtils::DB_FILE())) HomeInit();
	else
	{
		db.create(AsUtils::DB_FILE());
		AsBase::InitialDbOps();
		HomeInit();
	}
}

void vSongHome::HomeInit()
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
			//ui->MainTabRight->hide();
			OpenOnline();
		}
	}
	else {
		QMessageBox::warning(this, qApp->applicationName(), tr("Oops! vSongBook could not generate view due to unknown error at the moment"));
	}
}

void vSongHome::ReloadSettings()
{
	home_fontgen = home_sets[8].toInt();
	home_fontprev = home_sets[11].toInt();

	HomeFontGeneral.setFamily(home_sets[9]);
	HomeFontGeneral.setPointSize(home_fontgen);
	HomeFontGeneral.setBold(AsBase::isTrue(home_sets[10].toInt()));
	HomeFontGeneral.setWeight(50);

	HomeFontPreview.setFamily(home_sets[12]);
	HomeFontPreview.setPointSize(home_fontprev);
	HomeFontPreview.setBold(AsBase::isTrue(home_sets[13].toInt()));
	HomeFontPreview.setWeight(50);

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

void vSongHome::FontSmaller()
{
	if ((home_fontprev - 2) > 9)
	{
		home_fontprev = home_fontprev - 2;
		HomeFontPreview.setPointSize(home_fontprev);
		AsBase::SetOption("preview_font_size", QString::number(home_fontprev));
		ReloadControls();
	}
}

void vSongHome::FontBigger()
{
	if ((home_fontprev + 2) < 51)
	{
		home_fontprev = home_fontprev + 2;
		HomeFontPreview.setPointSize(home_fontprev);
		AsBase::SetOption("preview_font_size", QString::number(home_fontprev));
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
	vSongEditor editor(this, true);
	editor.exec();
}

void vSongHome::ManageBooks()
{
	vSongBooklist books(this);
	books.exec();
}

void vSongHome::OpenEditor()
{
	vSongEditor editor(this, false);
	editor.exec();
}

void vSongHome::OpenOnline()
{
	vSongOnline online(this);
	online.exec();
}

void vSongHome::OpenSettings()
{
	vSongPreferences preferences(this);
	preferences.exec();
}

void vSongHome::on_CmbSongbooks_currentIndexChanged(int index)
{
	if (isReady) PopulateSonglists("");
}

bool vSongHome::PopulateSongbooks()
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

void vSongHome::PopulateSonglists(QString SearchStr)
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
		int searchint = SearchStr.toInt(&isNumeric, 10);
		if (isNumeric) ResultCount.append("songs found with number: " + SearchStr + "#");
		else ResultCount.append("songs found with: \"" + SearchStr + "\"");
	}

	QString SqlQuery = AsUtils::SONG_SEARCH_SQL(SearchStr, bookids[ui->CmbSongbooks->currentIndex()], ui->ChkSearchCriteria->isChecked());
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
	AsDelegate* itemDelegate = new AsDelegate(this, home_sets[9], home_fontgen);
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

void vSongHome::OpenSongPreview(const QModelIndex& index)
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

void vSongHome::on_TxtSearch_returnPressed()
{
	PopulateSonglists(ui->TxtSearch->text());
}

void vSongHome::on_TxtSearch_textChanged(const QString& SearchStr)
{
	PopulateSonglists(SearchStr);
}

void vSongHome::on_LstResults_clicked(const QModelIndex& index)
{
	OpenSongPreview(index);
}

void vSongHome::on_LstResults_activated(const QModelIndex& index)
{
	OpenSongPreview(index);
}

void vSongHome::on_LstResults_doubleClicked(const QModelIndex& index)
{
	OpenSongPreview(index);
	openPresentation();
}

void vSongHome::openPresentation()
{
	vSongPresent* present = new vSongPresent();
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

void vSongHome::on_actionAbout_triggered()
{
	AboutDialog about(this);
	about.exec();
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
	
}

void vSongHome::on_actionPrevious_triggered()
{

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

void vSongHome::on_actionOnline_triggered()
{
	OpenOnline();
}

void vSongHome::on_actionTutorial_triggered()
{
	vSongTutorial* tutorial = new vSongTutorial();
	tutorial->show();
}
