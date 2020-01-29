#include "AsBase.h"
#include "AsUtils.h"
#include "vSongPreferences.h"
#include "vSongBook.h"
#include "ui_vSongPreferences.h"
#include "sqlite.h"
#include "RunSql.h"
#include "sqlitetablemodel.h"
#include <QStandardItemModel>
#include <QObject>

#include "AsItem.h"
#include "AsDelegate.h"

char* pref_db = "Data/vSongBook.db";
int fontgeneral, fontpreview, fontpresent;
std::vector<QString> prefsets, navigations, languages, fontFamily;
QFont PrefFontGeneral, PrefFontPreview, PrefFontPresent;

vSongPreferences::vSongPreferences(QWidget* parent) :
    QDialog(parent),
    ui(new Ui::vSongPreferences)
{
    ui->setupUi(this);
	GetSettings();
	ReloadSettings();
	SetUpStuff();
}

vSongPreferences::~vSongPreferences()
{
	delete ui;
}

bool vSongPreferences::GetSettings()
{
	bool retval = false;
	sqlite3* songsDb;
	char* err_msg = NULL, ** qryResult = NULL;
	int row, col, rc = sqlite3_open_v2(pref_db, &songsDb, SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE, NULL);

	char* sqlQuery = "SELECT content FROM settings ORDER BY settingid";

	if (rc == SQLITE_OK)
	{
		rc = sqlite3_get_table(songsDb, sqlQuery, &qryResult, &row, &col, &err_msg);

		for (int i = 1; i < row + 1; i++)
		{
			prefsets.push_back(*(qryResult + i * col + 0));
		}
		sqlite3_free_table(qryResult);
		sqlite3_close(songsDb);
		retval = true;
	}

	return retval;
}

void vSongPreferences::ReloadSettings()
{
	fontgeneral = prefsets[8].toInt();
	fontpreview = prefsets[11].toInt();
	fontpresent = prefsets[14].toInt();

	ui->BtnTabletMode->setChecked(AsBase::isTrue(prefsets[21].toInt()));
	ui->BtnSearchCriteria->setChecked(AsBase::isTrue(prefsets[24].toInt()));
	ui->BtnGeneralAppFont->setChecked(AsBase::isTrue(prefsets[10].toInt()));
	ui->BtnSongPreviewFont->setChecked(AsBase::isTrue(prefsets[13].toInt()));
	ui->BtnSongPresentFont->setChecked(AsBase::isTrue(prefsets[16].toInt()));

	ui->CmbLanguage->setCurrentIndex(AsBase::setCmbValue(languages, prefsets[3]));
	ui->CmbGeneralAppFont->setCurrentIndex(AsBase::setCmbValue(fontFamily, prefsets[9]));
	ui->CmbSongPreviewFont->setCurrentIndex(AsBase::setCmbValue(fontFamily, prefsets[12]));
	ui->CmbSongPresentFont->setCurrentIndex(AsBase::setCmbValue(fontFamily, prefsets[15]));

	ui->TxtYourName->setText(prefsets[1]);

	PrefFontGeneral.setFamily(prefsets[9]);
	PrefFontGeneral.setPointSize(fontgeneral);
	PrefFontGeneral.setBold(AsBase::isTrue(prefsets[10].toInt()));
	PrefFontGeneral.setWeight(50);

	PrefFontPreview.setFamily(prefsets[12]);
	PrefFontPreview.setPointSize(fontpreview);
	PrefFontPreview.setBold(AsBase::isTrue(prefsets[13].toInt()));
	PrefFontPreview.setWeight(50);

	PrefFontPresent.setFamily(prefsets[15]);
	PrefFontPresent.setPointSize(fontpresent);
	PrefFontPresent.setBold(AsBase::isTrue(prefsets[16].toInt()));
	PrefFontPresent.setWeight(50);

	ui->GrpGeneralAppFont->setTitle(" App General Font " + prefsets[8] + " ");
	ui->GrpSongPreviewFont->setTitle(" Song Preview Font " + prefsets[11] + " ");
	ui->GrpSongPresentFont->setTitle(" Song Presentation Font " + prefsets[14] + " ");

	ui->SldGeneralAppFont->setValue(fontgeneral);
	ui->SldSongPreviewFont->setValue(fontpreview);
	ui->SldSongPresentFont->setValue(fontpresent);
}

void vSongPreferences::SetUpStuff()
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

	for (int l = 0; l < languages.size(); l++)
	{
		ui->CmbLanguage->addItem(languages[l]);
	}

	fontFamily.clear();
	ui->CmbGeneralAppFont->clear();
	ui->CmbSongPreviewFont->clear();
	ui->CmbSongPresentFont->clear();

	fontFamily.push_back("Arial");
	fontFamily.push_back("Calibri");
	fontFamily.push_back("Century Gothic");
	fontFamily.push_back("Comic Sans MS");
	fontFamily.push_back("Corbel");
	fontFamily.push_back("Courier New");
	fontFamily.push_back("Palatino");
	fontFamily.push_back("Linotype");
	fontFamily.push_back("Tahoma");
	fontFamily.push_back("Tempus Sans ITC");
	fontFamily.push_back("Times New Roman");
	fontFamily.push_back("Trebuchet MS");
	fontFamily.push_back("Verdana");

	for (int f = 0; f < fontFamily.size(); f++)
	{
		ui->CmbGeneralAppFont->addItem(fontFamily[f]);
		ui->CmbSongPreviewFont->addItem(fontFamily[f]);
		ui->CmbSongPresentFont->addItem(fontFamily[f]);
	}
}

void vSongPreferences::LoadNavigation(QString searchstr)
{
	QStringList strList;

	QStandardItemModel* naviModel = new QStandardItemModel();

	if (navigations.size() > 0) navigations.clear();

	sqlite3* db;
	char* err_msg = NULL, ** qryResult = NULL;
	int row, col, rc = sqlite3_open_v2(pref_db, &db, SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE, NULL);

	QByteArray bar = AsUtils::SETTINGS_NAVI_SELECT_SQL(searchstr).toLocal8Bit();
	char* sqlQuery = bar.data();

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

void vSongPreferences::OpenSelectedTab(const QModelIndex& index)
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

void vSongPreferences::ChangeGeneralFont(int newfont)
{
	PrefFontGeneral.setPointSize(newfont);
	ui->TxtSampleText->setFont(PrefFontGeneral);
	AsBase::SetOption("general_font_size", QString::number(newfont));
	ui->GrpGeneralAppFont->setTitle(" App General Font " + QString::number(newfont) + " ");
}

void vSongPreferences::ChangePreviewFont(int newfont)
{
	PrefFontPreview.setPointSize(newfont);
	ui->TxtSampleText->setFont(PrefFontPreview);
	AsBase::SetOption("preview_font_size", QString::number(newfont));
	ui->GrpSongPreviewFont->setTitle(" Song Preview Font " + QString::number(newfont) + " ");
}

void vSongPreferences::ChangePresentFont(int newfont)
{
	PrefFontPresent.setPointSize(newfont);
	ui->TxtSampleText->setFont(PrefFontPresent);
	AsBase::SetOption("present_font_size", QString::number(newfont));
	ui->GrpSongPresentFont->setTitle(" Song Presentation Font " + QString::number(newfont) + " ");
}

void vSongPreferences::on_TxtSearch_textChanged(const QString& searchstr)
{
	LoadNavigation(searchstr);
}

void vSongPreferences::on_LstNavigation_clicked(const QModelIndex& index)
{
	OpenSelectedTab(index);
}

void vSongPreferences::on_LstNavigation_doubleClicked(const QModelIndex& index)
{
	OpenSelectedTab(index);
}

void vSongPreferences::on_BtnTabletMode_clicked()
{
	AsBase::SetOption("tablet_mode", AsBase::booltoInt(ui->BtnTabletMode->isChecked()));
}

void vSongPreferences::on_BtnSearchCriteria_clicked()
{
	AsBase::SetOption("search_allbooks", AsBase::booltoInt(ui->BtnSearchCriteria->isChecked()));
}

void vSongPreferences::on_CmbLanguage_currentIndexChanged(int index)
{
	AsBase::SetOption("language", languages[index]);
}

void vSongPreferences::on_TxtYourName_textChanged(const QString& newname)
{
	AsBase::SetOption("app_user", newname);
}

void vSongPreferences::on_BtnDownGeneralAppFont_clicked()
{
	if ((fontgeneral - 2) > 9)
	{
		fontgeneral = fontgeneral - 2;
		ChangeGeneralFont(fontgeneral);
	}
}

void vSongPreferences::on_BtnUpGeneralAppFont_clicked()
{
	if ((fontgeneral + 2) < 51)
	{
		fontgeneral = fontgeneral + 2;
		ChangeGeneralFont(fontgeneral);
	}
}

void vSongPreferences::on_SldGeneralAppFont_valueChanged(int value)
{
	ChangeGeneralFont(value);
}

void vSongPreferences::on_CmbGeneralAppFont_currentIndexChanged(int index)
{
	QString newfont = fontFamily[index];
	PrefFontGeneral.setFamily(newfont);
	ui->TxtSampleText->setFont(PrefFontGeneral);
	AsBase::SetOption("general_font_type", newfont);
}

void vSongPreferences::on_BtnGeneralAppFont_clicked()
{
	PrefFontGeneral.setBold(ui->BtnGeneralAppFont->isChecked());
	ui->TxtSampleText->setFont(PrefFontGeneral);
	AsBase::SetOption("general_font_bold", AsBase::booltoInt(ui->BtnGeneralAppFont->isChecked()));
}

void vSongPreferences::on_BtnDownSongPreviewFont_clicked()
{
	if ((fontpreview - 2) > 9)
	{
		fontpreview = fontpreview - 2;
		ChangePreviewFont(fontpreview);
	}
}

void vSongPreferences::on_BtnUpSongPreviewFont_clicked()
{
	if ((fontpreview + 2) < 51)
	{
		fontpreview = fontpreview + 2;
		ChangePreviewFont(fontpreview);
	}
}

void vSongPreferences::on_SldSongPreviewFont_valueChanged(int value)
{
	ChangePreviewFont(value);
}

void vSongPreferences::on_CmbSongPreviewFont_currentIndexChanged(int index)
{
	QString newfont = fontFamily[index];
	PrefFontPreview.setFamily(newfont);
	ui->TxtSampleText->setFont(PrefFontPreview);
	AsBase::SetOption("preview_font_type", newfont);
}

void vSongPreferences::on_BtnSongPreviewFont_clicked()
{
	PrefFontPreview.setBold(ui->BtnSongPreviewFont->isChecked());
	ui->TxtSampleText->setFont(PrefFontPreview);
	AsBase::SetOption("preview_font_bold", AsBase::booltoInt(ui->BtnSongPreviewFont->isChecked()));
}

void vSongPreferences::on_BtnDownSongPresentFont_clicked()
{
	if ((fontpresent - 2) > 9)
	{
		fontpresent = fontpresent - 2;
		ChangePresentFont(fontpresent);
	}
}

void vSongPreferences::on_BtnUpSongPresentFont_clicked()
{
	if ((fontpresent + 2) < 99)
	{
		fontpresent = fontpresent + 2;
		ChangePresentFont(fontpresent);
	}
}

void vSongPreferences::on_SldSongPresentFont_valueChanged(int value)
{
	ChangePresentFont(value);
}

void vSongPreferences::on_CmbSongPresentFont_currentIndexChanged(int index)
{
	QString newfont = fontFamily[index];
	PrefFontPresent.setFamily(newfont);
	ui->TxtSampleText->setFont(PrefFontPresent);
	AsBase::SetOption("present_font_type", newfont);
}

void vSongPreferences::on_BtnSongPresentFont_clicked()
{
	PrefFontPresent.setBold(ui->BtnSongPresentFont->isChecked());
	ui->TxtSampleText->setFont(PrefFontPresent);
	AsBase::SetOption("present_font_bold", AsBase::booltoInt(ui->BtnSongPresentFont->isChecked()));
}

void vSongPreferences::on_BtnTheme1_clicked()
{
	AsBase::SetOption("app_theme", "1");
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
}

void vSongPreferences::on_BtnTheme2_clicked()
{
	AsBase::SetOption("app_theme", "2");
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
}

void vSongPreferences::on_BtnTheme3_clicked()
{
	AsBase::SetOption("app_theme", "3");
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
}

void vSongPreferences::on_BtnTheme4_clicked()
{
	AsBase::SetOption("app_theme", "4");
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
}

void vSongPreferences::on_BtnTheme5_clicked()
{
	AsBase::SetOption("app_theme", "5");
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
}

void vSongPreferences::on_BtnTheme6_clicked()
{
	AsBase::SetOption("app_theme", "6");
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
}

void vSongPreferences::on_BtnTheme7_clicked()
{
	AsBase::SetOption("app_theme", "7");
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
}

void vSongPreferences::on_BtnTheme8_clicked()
{
	AsBase::SetOption("app_theme", "8");
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
}

void vSongPreferences::on_BtnTheme9_clicked()
{
	AsBase::SetOption("app_theme", "9");
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
}

void vSongPreferences::on_BtnTheme10_clicked()
{
	AsBase::SetOption("app_theme", "10");
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
}

void vSongPreferences::on_BtnTheme11_clicked()
{
	AsBase::SetOption("app_theme", "11");
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
}

void vSongPreferences::on_BtnTheme12_clicked()
{
	AsBase::SetOption("app_theme", "12");
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
}

void vSongPreferences::on_BtnTheme13_clicked()
{
	AsBase::SetOption("app_theme", "13");
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
}

void vSongPreferences::on_BtnTheme14_clicked()
{
	AsBase::SetOption("app_theme", "14");
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
}

void vSongPreferences::on_BtnTheme15_clicked()
{
	AsBase::SetOption("app_theme", "15");
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
}
