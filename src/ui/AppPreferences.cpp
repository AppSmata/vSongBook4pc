#include "ui/AppPreferences.h"
#include "ui_AppPreferences.h"

#include "Application.h"
#include "sqlite.h"
#include "RunSql.h"
#include "sqlitetablemodel.h"

#include "AsBase.h"
#include "AsUtils.h"
#include "AsItem.h"
#include "AsDelegate.h"

#include <QStandardItemModel>
#include <QObject>

int fontgeneral, fontpreview, fontpresent;
std::vector<QString> pref_sets, navigations, languages, pref_fonts;
QFont PrefFontGeneral, PrefFontPreview, PrefFontPresent;

// AppPreferences Window Initiliser
AppPreferences::AppPreferences(QWidget* parent) :
    QDialog(parent),
    ui(new Ui::AppPreferences)
{
    ui->setupUi(this);
	GetSettings();
	ReloadSettings();
	SetUpStuff();
}

// Get App Settings with relation to the current active window
bool AppPreferences::GetSettings()
{
	bool retval = false;
	sqlite3* songsDb;
	char* err_msg = NULL, ** qryResult = NULL;
    int row, col, rc = sqlite3_open_v2(AsUtils::DbNameChar(), &songsDb, SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE, NULL);

    char const *sqlQuery = "SELECT content FROM settings ORDER BY settingid";

	if (rc == SQLITE_OK)
	{
		rc = sqlite3_get_table(songsDb, sqlQuery, &qryResult, &row, &col, &err_msg);

		for (int i = 1; i < row + 1; i++)
		{
			pref_sets.push_back(*(qryResult + i * col + 0));
		}
		sqlite3_free_table(qryResult);
		sqlite3_close(songsDb);
		retval = true;
	}

	return retval;
}

// Reload App Settings 
void AppPreferences::ReloadSettings()
{
	fontgeneral = pref_sets[8].toInt();
	fontpreview = pref_sets[11].toInt();
	fontpresent = pref_sets[14].toInt();

	ui->BtnTabletMode->setChecked(AsBase::isTrue(pref_sets[21].toInt()));
	ui->BtnSearchCriteria->setChecked(AsBase::isTrue(pref_sets[24].toInt()));
	ui->BtnGeneralAppFont->setChecked(AsBase::isTrue(pref_sets[10].toInt()));
	ui->BtnSongPreviewFont->setChecked(AsBase::isTrue(pref_sets[13].toInt()));
	ui->BtnSongPresentFont->setChecked(AsBase::isTrue(pref_sets[16].toInt()));

	ui->CmbLanguage->setCurrentIndex(AsBase::setCmbValue(languages, pref_sets[3]));
	ui->CmbGeneralAppFont->setCurrentIndex(AsBase::setCmbValue(pref_fonts, pref_sets[9]));
	ui->CmbSongPreviewFont->setCurrentIndex(AsBase::setCmbValue(pref_fonts, pref_sets[12]));
	ui->CmbSongPresentFont->setCurrentIndex(AsBase::setCmbValue(pref_fonts, pref_sets[15]));

	ui->TxtYourName->setText(pref_sets[1]);

	PrefFontGeneral.setFamily(pref_sets[9]);
	PrefFontGeneral.setPointSize(fontgeneral);
	PrefFontGeneral.setBold(AsBase::isTrue(pref_sets[10].toInt()));
	PrefFontGeneral.setWeight(50);

	PrefFontPreview.setFamily(pref_sets[12]);
	PrefFontPreview.setPointSize(fontpreview);
	PrefFontPreview.setBold(AsBase::isTrue(pref_sets[13].toInt()));
	PrefFontPreview.setWeight(50);

	PrefFontPresent.setFamily(pref_sets[15]);
	PrefFontPresent.setPointSize(fontpresent);
	PrefFontPresent.setBold(AsBase::isTrue(pref_sets[16].toInt()));
	PrefFontPresent.setWeight(50);

	ui->GrpGeneralAppFont->setTitle(" App General Font " + pref_sets[8] + " ");
	ui->GrpSongPreviewFont->setTitle(" Song Preview Font " + pref_sets[11] + " ");
	ui->GrpSongPresentFont->setTitle(" Song Presentation Font " + pref_sets[14] + " ");

	ui->SldGeneralAppFont->setValue(fontgeneral);
	ui->SldSongPreviewFont->setValue(fontpreview);
	ui->SldSongPresentFont->setValue(fontpresent);

	SelectedTheme(pref_sets[25].toInt());

}

// Basic Custom setup of UI
void AppPreferences::SetUpStuff()
{
	LoadNavigation("");
	languages.clear();
	ui->CmbLanguage->clear();

	languages.push_back("English");
	languages.push_back("Swahili");
	languages.push_back("French");
	languages.push_back("Spanish");
	languages.push_back("Portuguesse");
	languages.push_back("Chichewa");

    for (decltype(languages.size()) l = 0; l < languages.size(); ++l)
	{
		ui->CmbLanguage->addItem(languages[l]);
	}

	pref_fonts.clear();
	ui->CmbGeneralAppFont->clear();
	ui->CmbSongPreviewFont->clear();
	ui->CmbSongPresentFont->clear();

	pref_fonts.push_back("Arial");
	pref_fonts.push_back("Calibri");
	pref_fonts.push_back("Century Gothic");
	pref_fonts.push_back("Comic Sans MS");
	pref_fonts.push_back("Corbel");
	pref_fonts.push_back("Courier New");
	pref_fonts.push_back("Palatino");
	pref_fonts.push_back("Linotype");
	pref_fonts.push_back("Tahoma");
	pref_fonts.push_back("Tempus Sans ITC");
	pref_fonts.push_back("Times New Roman");
	pref_fonts.push_back("Trebuchet MS");
	pref_fonts.push_back("Verdana");

    for (decltype(pref_fonts.size()) f = 0; f < pref_fonts.size(); ++f)
	{
		ui->CmbGeneralAppFont->addItem(pref_fonts[f]);
		ui->CmbSongPreviewFont->addItem(pref_fonts[f]);
		ui->CmbSongPresentFont->addItem(pref_fonts[f]);
	}
}

// Getting the currently selected theme
void AppPreferences::SelectedTheme(int theme)
{
	switch (theme)
	{
		case 1: //Theme One
			ui->BtnTheme1->setChecked(true);
			ui->BtnTheme2->setChecked(false);
			ui->BtnTheme3->setChecked(false);
			ui->BtnTheme4->setChecked(false);
			ui->BtnTheme5->setChecked(false);
			ui->BtnTheme6->setChecked(false);
			ui->BtnTheme7->setChecked(false);
			ui->BtnTheme8->setChecked(false);
			ui->BtnTheme9->setChecked(false);
			ui->BtnTheme10->setChecked(false);
			ui->BtnTheme11->setChecked(false);
			ui->BtnTheme12->setChecked(false);
			ui->BtnTheme13->setChecked(false);
			ui->BtnTheme14->setChecked(false);
			ui->BtnTheme15->setChecked(false);
			break;

		case 2: //Theme Two
			ui->BtnTheme1->setChecked(false);
			ui->BtnTheme2->setChecked(true);
			ui->BtnTheme3->setChecked(false);
			ui->BtnTheme4->setChecked(false);
			ui->BtnTheme5->setChecked(false);
			ui->BtnTheme6->setChecked(false);
			ui->BtnTheme7->setChecked(false);
			ui->BtnTheme8->setChecked(false);
			ui->BtnTheme9->setChecked(false);
			ui->BtnTheme10->setChecked(false);
			ui->BtnTheme11->setChecked(false);
			ui->BtnTheme12->setChecked(false);
			ui->BtnTheme13->setChecked(false);
			ui->BtnTheme14->setChecked(false);
			ui->BtnTheme15->setChecked(false);
			break;

		case 3: //Theme Three
			ui->BtnTheme1->setChecked(false);
			ui->BtnTheme2->setChecked(false);
			ui->BtnTheme3->setChecked(true);
			ui->BtnTheme4->setChecked(false);
			ui->BtnTheme5->setChecked(false);
			ui->BtnTheme6->setChecked(false);
			ui->BtnTheme7->setChecked(false);
			ui->BtnTheme8->setChecked(false);
			ui->BtnTheme9->setChecked(false);
			ui->BtnTheme10->setChecked(false);
			ui->BtnTheme11->setChecked(false);
			ui->BtnTheme12->setChecked(false);
			ui->BtnTheme13->setChecked(false);
			ui->BtnTheme14->setChecked(false);
			ui->BtnTheme15->setChecked(false);
			break;

		case 4: //Theme Four
			ui->BtnTheme1->setChecked(false);
			ui->BtnTheme2->setChecked(false);
			ui->BtnTheme3->setChecked(false);
			ui->BtnTheme4->setChecked(true);
			ui->BtnTheme5->setChecked(false);
			ui->BtnTheme6->setChecked(false);
			ui->BtnTheme7->setChecked(false);
			ui->BtnTheme8->setChecked(false);
			ui->BtnTheme9->setChecked(false);
			ui->BtnTheme10->setChecked(false);
			ui->BtnTheme11->setChecked(false);
			ui->BtnTheme12->setChecked(false);
			ui->BtnTheme13->setChecked(false);
			ui->BtnTheme14->setChecked(false);
			ui->BtnTheme15->setChecked(false);
			break;

		case 5: //Theme Five
			ui->BtnTheme1->setChecked(false);
			ui->BtnTheme2->setChecked(false);
			ui->BtnTheme3->setChecked(false);
			ui->BtnTheme4->setChecked(false);
			ui->BtnTheme5->setChecked(true);
			ui->BtnTheme6->setChecked(false);
			ui->BtnTheme7->setChecked(false);
			ui->BtnTheme8->setChecked(false);
			ui->BtnTheme9->setChecked(false);
			ui->BtnTheme10->setChecked(false);
			ui->BtnTheme11->setChecked(false);
			ui->BtnTheme12->setChecked(false);
			ui->BtnTheme13->setChecked(false);
			ui->BtnTheme14->setChecked(false);
			ui->BtnTheme15->setChecked(false);
			break;

		case 6: //Theme Six
			ui->BtnTheme1->setChecked(false);
			ui->BtnTheme2->setChecked(false);
			ui->BtnTheme3->setChecked(false);
			ui->BtnTheme4->setChecked(false);
			ui->BtnTheme5->setChecked(false);
			ui->BtnTheme6->setChecked(true);
			ui->BtnTheme7->setChecked(false);
			ui->BtnTheme8->setChecked(false);
			ui->BtnTheme9->setChecked(false);
			ui->BtnTheme10->setChecked(false);
			ui->BtnTheme11->setChecked(false);
			ui->BtnTheme12->setChecked(false);
			ui->BtnTheme13->setChecked(false);
			ui->BtnTheme14->setChecked(false);
			ui->BtnTheme15->setChecked(false);
			break;

		case 7: //Theme Seven
			ui->BtnTheme1->setChecked(false);
			ui->BtnTheme2->setChecked(false);
			ui->BtnTheme3->setChecked(false);
			ui->BtnTheme4->setChecked(false);
			ui->BtnTheme5->setChecked(false);
			ui->BtnTheme6->setChecked(false);
			ui->BtnTheme7->setChecked(true);
			ui->BtnTheme8->setChecked(false);
			ui->BtnTheme9->setChecked(false);
			ui->BtnTheme10->setChecked(false);
			ui->BtnTheme11->setChecked(false);
			ui->BtnTheme12->setChecked(false);
			ui->BtnTheme13->setChecked(false);
			ui->BtnTheme14->setChecked(false);
			ui->BtnTheme15->setChecked(false);
			break;

		case 8: //Theme Eight
			ui->BtnTheme1->setChecked(false);
			ui->BtnTheme2->setChecked(false);
			ui->BtnTheme3->setChecked(false);
			ui->BtnTheme4->setChecked(false);
			ui->BtnTheme5->setChecked(false);
			ui->BtnTheme6->setChecked(false);
			ui->BtnTheme7->setChecked(false);
			ui->BtnTheme8->setChecked(true);
			ui->BtnTheme9->setChecked(false);
			ui->BtnTheme10->setChecked(false);
			ui->BtnTheme11->setChecked(false);
			ui->BtnTheme12->setChecked(false);
			ui->BtnTheme13->setChecked(false);
			ui->BtnTheme14->setChecked(false);
			ui->BtnTheme15->setChecked(false);
			break;

		case 9: //Theme Nine
			ui->BtnTheme1->setChecked(false);
			ui->BtnTheme2->setChecked(false);
			ui->BtnTheme3->setChecked(false);
			ui->BtnTheme4->setChecked(false);
			ui->BtnTheme5->setChecked(false);
			ui->BtnTheme6->setChecked(false);
			ui->BtnTheme7->setChecked(false);
			ui->BtnTheme8->setChecked(false);
			ui->BtnTheme9->setChecked(true);
			ui->BtnTheme10->setChecked(false);
			ui->BtnTheme11->setChecked(false);
			ui->BtnTheme12->setChecked(false);
			ui->BtnTheme13->setChecked(false);
			ui->BtnTheme14->setChecked(false);
			ui->BtnTheme15->setChecked(false);
			break;

		case 10: //Theme Ten
			ui->BtnTheme1->setChecked(false);
			ui->BtnTheme2->setChecked(false);
			ui->BtnTheme3->setChecked(false);
			ui->BtnTheme4->setChecked(false);
			ui->BtnTheme5->setChecked(false);
			ui->BtnTheme6->setChecked(false);
			ui->BtnTheme7->setChecked(false);
			ui->BtnTheme8->setChecked(false);
			ui->BtnTheme9->setChecked(false);
			ui->BtnTheme10->setChecked(true);
			ui->BtnTheme11->setChecked(false);
			ui->BtnTheme12->setChecked(false);
			ui->BtnTheme13->setChecked(false);
			ui->BtnTheme14->setChecked(false);
			ui->BtnTheme15->setChecked(false);
			break;

		case 11: //Theme Eleven
			ui->BtnTheme1->setChecked(false);
			ui->BtnTheme2->setChecked(false);
			ui->BtnTheme3->setChecked(false);
			ui->BtnTheme4->setChecked(false);
			ui->BtnTheme5->setChecked(false);
			ui->BtnTheme6->setChecked(false);
			ui->BtnTheme7->setChecked(false);
			ui->BtnTheme8->setChecked(false);
			ui->BtnTheme9->setChecked(false);
			ui->BtnTheme10->setChecked(false);
			ui->BtnTheme11->setChecked(true);
			ui->BtnTheme12->setChecked(false);
			ui->BtnTheme13->setChecked(false);
			ui->BtnTheme14->setChecked(false);
			ui->BtnTheme15->setChecked(false);
			break;

		case 12: //Theme Twelve
			ui->BtnTheme1->setChecked(false);
			ui->BtnTheme2->setChecked(false);
			ui->BtnTheme3->setChecked(false);
			ui->BtnTheme4->setChecked(false);
			ui->BtnTheme5->setChecked(false);
			ui->BtnTheme6->setChecked(false);
			ui->BtnTheme7->setChecked(false);
			ui->BtnTheme8->setChecked(false);
			ui->BtnTheme9->setChecked(false);
			ui->BtnTheme10->setChecked(false);
			ui->BtnTheme11->setChecked(false);
			ui->BtnTheme12->setChecked(true);
			ui->BtnTheme13->setChecked(false);
			ui->BtnTheme14->setChecked(false);
			ui->BtnTheme15->setChecked(false);
			break;

		case 13: //Theme Thirteen
			ui->BtnTheme1->setChecked(false);
			ui->BtnTheme2->setChecked(false);
			ui->BtnTheme3->setChecked(false);
			ui->BtnTheme4->setChecked(false);
			ui->BtnTheme5->setChecked(false);
			ui->BtnTheme6->setChecked(false);
			ui->BtnTheme7->setChecked(false);
			ui->BtnTheme8->setChecked(false);
			ui->BtnTheme9->setChecked(false);
			ui->BtnTheme10->setChecked(false);
			ui->BtnTheme11->setChecked(false);
			ui->BtnTheme12->setChecked(false);
			ui->BtnTheme13->setChecked(true);
			ui->BtnTheme14->setChecked(false);
			ui->BtnTheme15->setChecked(false);
			break;

		case 14: //Theme Fourteen
			ui->BtnTheme1->setChecked(false);
			ui->BtnTheme2->setChecked(false);
			ui->BtnTheme3->setChecked(false);
			ui->BtnTheme4->setChecked(false);
			ui->BtnTheme5->setChecked(false);
			ui->BtnTheme6->setChecked(false);
			ui->BtnTheme7->setChecked(false);
			ui->BtnTheme8->setChecked(false);
			ui->BtnTheme9->setChecked(false);
			ui->BtnTheme10->setChecked(false);
			ui->BtnTheme11->setChecked(false);
			ui->BtnTheme12->setChecked(false);
			ui->BtnTheme13->setChecked(false);
			ui->BtnTheme14->setChecked(true);
			ui->BtnTheme15->setChecked(false);
			break;

		case 15: //Theme Fifteen
			ui->BtnTheme1->setChecked(false);
			ui->BtnTheme2->setChecked(false);
			ui->BtnTheme3->setChecked(false);
			ui->BtnTheme4->setChecked(false);
			ui->BtnTheme5->setChecked(false);
			ui->BtnTheme6->setChecked(false);
			ui->BtnTheme7->setChecked(false);
			ui->BtnTheme8->setChecked(false);
			ui->BtnTheme9->setChecked(false);
			ui->BtnTheme10->setChecked(false);
			ui->BtnTheme11->setChecked(false);
			ui->BtnTheme12->setChecked(false);
			ui->BtnTheme13->setChecked(false);
			ui->BtnTheme14->setChecked(false);
			ui->BtnTheme15->setChecked(true);
			break;

	}
}

// Get the settings navigation
void AppPreferences::LoadNavigation(QString searchstr)
{
	QStringList strList;
	QStandardItemModel* naviModel = new QStandardItemModel();

	if (navigations.size() > 0) navigations.clear();

	sqlite3* db;
    char* err_msg = NULL, ** qryResult = NULL;

	QByteArray bar = AsUtils::SettingsNaviSelectSql(searchstr).toLocal8Bit();
	char* sqlQuery = bar.data();

    int row, col, rc = sqlite3_open_v2(AsUtils::DbNameChar(), &db, SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE, NULL);
	rc = sqlite3_get_table(db, sqlQuery, &qryResult, &row, &col, &err_msg);

	for (int i = 1; i < row + 1; i++)
	{
		navigations.push_back(*(qryResult + i * col + 0));

		QStandardItem* naviItem = new QStandardItem;
		AsItem navigation;
		navigation.image = "res/settings.png";
		navigation.title = *(qryResult + i * col + 2);
		navigation.content = *(qryResult + i * col + 3);

		naviItem->setData(QVariant::fromValue(navigation), Qt::UserRole + 1);
		naviModel->appendRow(naviItem);
	}

	AsDelegate* asDelegate = new AsDelegate(this);
	ui->LstNavigation->setItemDelegate(asDelegate);
	ui->LstNavigation->setModel(naviModel);
	ui->LstNavigation->setSpacing(1);
	ui->LstNavigation->setStyleSheet("* { background-color: #D3D3D3; }");

	sqlite3_free_table(qryResult);
	sqlite3_close(db);

	ui->LstNavigation->setCurrentIndex(naviModel->index(0, 0));
}

// Show the appropriate selected tab
void AppPreferences::OpenSelectedTab(const QModelIndex& index)
{
	int setTab = navigations[index.row()].toInt();
	switch (setTab)
	{
		case 1:
			ui->TabPage1->show();
			ui->TabPage2->hide();
			ui->TabPage3->hide();
			break;

		case 2:
			ui->TabPage1->hide();
			ui->TabPage2->show();
			ui->TabPage3->hide();
			break;

		case 3:
			ui->TabPage1->hide();
			ui->TabPage2->hide();
			ui->TabPage3->show();
			break;
	}
}

// Change the General Font Size of the App
void AppPreferences::ChangeGeneralFont(int newfont)
{
	PrefFontGeneral.setPointSize(newfont);
	ui->TxtSampleText->setFont(PrefFontGeneral);
	AsBase::SetOption("general_font_size", QString::number(newfont));
	ui->GrpGeneralAppFont->setTitle(" App General Font " + QString::number(newfont) + " ");
}

// Change the Preview Font Size of the App
void AppPreferences::ChangePreviewFont(int newfont)
{
	PrefFontPreview.setPointSize(newfont);
	ui->TxtSampleText->setFont(PrefFontPreview);
	AsBase::SetOption("preview_font_size", QString::number(newfont));
	ui->GrpSongPreviewFont->setTitle(" Song Preview Font " + QString::number(newfont) + " ");
}

// Change the Presentation Font Size of the App
void AppPreferences::ChangePresentFont(int newfont)
{
	PrefFontPresent.setPointSize(newfont);
	ui->TxtSampleText->setFont(PrefFontPresent);
	AsBase::SetOption("present_font_size", QString::number(newfont));
	ui->GrpSongPresentFont->setTitle(" Song Presentation Font " + QString::number(newfont) + " ");
}

// On Text Change event function for TxtSearch
void AppPreferences::on_TxtSearch_textChanged(const QString& searchstr)
{
	LoadNavigation(searchstr);
}

// On Click event function for LstNavigation
void AppPreferences::on_LstNavigation_clicked(const QModelIndex& index)
{
	OpenSelectedTab(index);
}

// On Double Click event function for LstNavigation
void AppPreferences::on_LstNavigation_doubleClicked(const QModelIndex& index)
{
	OpenSelectedTab(index);
}

// On Click event function for BtnTabletMode
void AppPreferences::on_BtnTabletMode_clicked()
{
	AsBase::SetOption("tablet_mode", AsBase::booltoInt(ui->BtnTabletMode->isChecked()));
}

// On Click event function for BtnSearchCriteria
void AppPreferences::on_BtnSearchCriteria_clicked()
{
	AsBase::SetOption("search_allbooks", AsBase::booltoInt(ui->BtnSearchCriteria->isChecked()));
}

// On Current Index Changed event function for CmbLanguage
void AppPreferences::on_CmbLanguage_currentIndexChanged(int index)
{
	AsBase::SetOption("language", languages[index]);
}

// On Text Changed event function for TxtYourName
void AppPreferences::on_TxtYourName_textChanged(const QString& newname)
{
	AsBase::SetOption("app_user", newname);
}

// On Click event function for BtnDownGeneralAppFont
void AppPreferences::on_BtnDownGeneralAppFont_clicked()
{
	if ((fontgeneral - 2) > 9)
	{
		fontgeneral = fontgeneral - 2;
		ChangeGeneralFont(fontgeneral);
	}
}

// On Click event function for BtnUpGeneralAppFont
void AppPreferences::on_BtnUpGeneralAppFont_clicked()
{
	if ((fontgeneral + 2) < 51)
	{
		fontgeneral = fontgeneral + 2;
		ChangeGeneralFont(fontgeneral);
	}
}

// On Value Changed event function for SldGeneralAppFont
void AppPreferences::on_SldGeneralAppFont_valueChanged(int value)
{
	ChangeGeneralFont(value);
}

// On Current Index Changed event function for CmbGeneralAppFont
void AppPreferences::on_CmbGeneralAppFont_currentIndexChanged(int index)
{
	QString newfont = pref_fonts[index];
	PrefFontGeneral.setFamily(newfont);
	ui->TxtSampleText->setFont(PrefFontGeneral);
	AsBase::SetOption("general_font_type", newfont);
}

// On Click event function for BtnGeneralAppFont
void AppPreferences::on_BtnGeneralAppFont_clicked()
{
	PrefFontGeneral.setBold(ui->BtnGeneralAppFont->isChecked());
	ui->TxtSampleText->setFont(PrefFontGeneral);
	AsBase::SetOption("general_font_bold", AsBase::booltoInt(ui->BtnGeneralAppFont->isChecked()));
}

// On Click event function for BtnDownSongPreviewFont
void AppPreferences::on_BtnDownSongPreviewFont_clicked()
{
	if ((fontpreview - 2) > 9)
	{
		fontpreview = fontpreview - 2;
		ChangePreviewFont(fontpreview);
	}
}

// On Click event function for BtnUpSongPreviewFont
void AppPreferences::on_BtnUpSongPreviewFont_clicked()
{
	if ((fontpreview + 2) < 51)
	{
		fontpreview = fontpreview + 2;
		ChangePreviewFont(fontpreview);
	}
}

// On Value Changed event function for SldSongPreviewFont
void AppPreferences::on_SldSongPreviewFont_valueChanged(int value)
{
	ChangePreviewFont(value);
}

// On Current Index Changed event function for CmbSongPreviewFont
void AppPreferences::on_CmbSongPreviewFont_currentIndexChanged(int index)
{
	QString newfont = pref_fonts[index];
	PrefFontPreview.setFamily(newfont);
	ui->TxtSampleText->setFont(PrefFontPreview);
	AsBase::SetOption("preview_font_type", newfont);
}

// On Click event function for BtnSongPreviewFont
void AppPreferences::on_BtnSongPreviewFont_clicked()
{
	PrefFontPreview.setBold(ui->BtnSongPreviewFont->isChecked());
	ui->TxtSampleText->setFont(PrefFontPreview);
	AsBase::SetOption("preview_font_bold", AsBase::booltoInt(ui->BtnSongPreviewFont->isChecked()));
}

// On Click event function for BtnDownSongPresentFont
void AppPreferences::on_BtnDownSongPresentFont_clicked()
{
	if ((fontpresent - 2) > 9)
	{
		fontpresent = fontpresent - 2;
		ChangePresentFont(fontpresent);
	}
}

// On Click event function for BtnUpSongPresentFont
void AppPreferences::on_BtnUpSongPresentFont_clicked()
{
	if ((fontpresent + 2) < 99)
	{
		fontpresent = fontpresent + 2;
		ChangePresentFont(fontpresent);
	}
}

// On Value Changed event function for SldSongPresentFont
void AppPreferences::on_SldSongPresentFont_valueChanged(int value)
{
	ChangePresentFont(value);
}

// On Current Index Changed event function for CmbSongPresentFont
void AppPreferences::on_CmbSongPresentFont_currentIndexChanged(int index)
{
	QString newfont = pref_fonts[index];
	PrefFontPresent.setFamily(newfont);
	ui->TxtSampleText->setFont(PrefFontPresent);
	AsBase::SetOption("present_font_type", newfont);
}

// On Click event function for BtnSongPresentFont
void AppPreferences::on_BtnSongPresentFont_clicked()
{
	PrefFontPresent.setBold(ui->BtnSongPresentFont->isChecked());
	ui->TxtSampleText->setFont(PrefFontPresent);
	AsBase::SetOption("present_font_bold", AsBase::booltoInt(ui->BtnSongPresentFont->isChecked()));
}

// On Click event function for BtnTheme1
void AppPreferences::on_BtnTheme1_clicked()
{
	AsBase::SetOption("app_theme", "1");
	SelectedTheme(1);
}

// On Click event function for BtnTheme2
void AppPreferences::on_BtnTheme2_clicked()
{
	AsBase::SetOption("app_theme", "2");
	SelectedTheme(2);
}

// On Click event function for BtnTheme3
void AppPreferences::on_BtnTheme3_clicked()
{
	AsBase::SetOption("app_theme", "3");
	SelectedTheme(3);
}

// On Click event function for BtnTheme4
void AppPreferences::on_BtnTheme4_clicked()
{
	AsBase::SetOption("app_theme", "4");
	SelectedTheme(4);
}

// On Click event function for BtnTheme5
void AppPreferences::on_BtnTheme5_clicked()
{
	AsBase::SetOption("app_theme", "5");
	SelectedTheme(5);
}

// On Click event function for BtnTheme6
void AppPreferences::on_BtnTheme6_clicked()
{
	AsBase::SetOption("app_theme", "6");
	SelectedTheme(6);
}

// On Click event function for BtnTheme7
void AppPreferences::on_BtnTheme7_clicked()
{
	AsBase::SetOption("app_theme", "7");
	SelectedTheme(7);
}

// On Click event function for BtnTheme8
void AppPreferences::on_BtnTheme8_clicked()
{
	AsBase::SetOption("app_theme", "8");
	SelectedTheme(8);
}

// On Click event function for BtnTheme9
void AppPreferences::on_BtnTheme9_clicked()
{
	AsBase::SetOption("app_theme", "9");
	SelectedTheme(9);
}

// On Click event function for BtnTheme10
void AppPreferences::on_BtnTheme10_clicked()
{
	AsBase::SetOption("app_theme", "10");
	SelectedTheme(10);
}

// On Click event function for BtnTheme11
void AppPreferences::on_BtnTheme11_clicked()
{
	AsBase::SetOption("app_theme", "11");
	SelectedTheme(11);
}

// On Click event function for BtnTheme12
void AppPreferences::on_BtnTheme12_clicked()
{
	AsBase::SetOption("app_theme", "12");
	SelectedTheme(12);
}

// On Click event function for BtnTheme13
void AppPreferences::on_BtnTheme13_clicked()
{
	AsBase::SetOption("app_theme", "13");
	SelectedTheme(13);
}

// On Click event function for BtnTheme14
void AppPreferences::on_BtnTheme14_clicked()
{
	AsBase::SetOption("app_theme", "14");
	SelectedTheme(14);
}

// On Click event function for BtnTheme15
void AppPreferences::on_BtnTheme15_clicked()
{
	AsBase::SetOption("app_theme", "15");
	SelectedTheme(15);
}

// Class Destructor
AppPreferences::~AppPreferences()
{
	delete ui;
}
