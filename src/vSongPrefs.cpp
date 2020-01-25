#include "vSongPrefs.h"
#include "vSongBook.h"
#include "ui_vSongPrefs.h"
#include "sqlite.h"
#include "RunSql.h"
#include "sqlitetablemodel.h"
#include <QStandardItemModel>
#include <QObject>

#include "ItemData.h"
#include "ItemDelegate.h"

char* pref_db = "Data/vSongBook.db";
int fontgeneral, fontpreview, fontpresent;
std::vector<QString> prefsets, navigations, languages, fontFamily;
QFont PrefFontGeneral, PrefFontPreview, PrefFontPresent;

vSongPrefs::vSongPrefs(QWidget* parent) :
    QDialog(parent),
    ui(new Ui::vSongPrefs)
{
    ui->setupUi(this);
	GetSettings();
	ReloadSettings();
	SetUpStuff();
}

vSongPrefs::~vSongPrefs()
{
	delete ui;
}

bool vSongPrefs::GetSettings()
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

void vSongPrefs::ReloadSettings()
{
	fontgeneral = prefsets[8].toInt();
	fontpreview = prefsets[11].toInt();
	fontpresent = prefsets[14].toInt();

	ui->BtnTabletMode->setChecked(vSongBook::isTrue(prefsets[21].toInt()));
	ui->BtnSearchCriteria->setChecked(vSongBook::isTrue(prefsets[24].toInt()));
	ui->BtnGeneralAppFont->setChecked(vSongBook::isTrue(prefsets[10].toInt()));
	ui->BtnSongPreviewFont->setChecked(vSongBook::isTrue(prefsets[13].toInt()));
	ui->BtnSongPresentFont->setChecked(vSongBook::isTrue(prefsets[16].toInt()));

	ui->CmbLanguage->setCurrentIndex(vSongBook::setCmbValue(languages, prefsets[3]));
	ui->CmbGeneralAppFont->setCurrentIndex(vSongBook::setCmbValue(fontFamily, prefsets[9]));
	ui->CmbSongPreviewFont->setCurrentIndex(vSongBook::setCmbValue(fontFamily, prefsets[12]));
	ui->CmbSongPresentFont->setCurrentIndex(vSongBook::setCmbValue(fontFamily, prefsets[15]));

	ui->TxtYourName->setText(prefsets[1]);

	PrefFontGeneral.setFamily(prefsets[9]);
	PrefFontGeneral.setPointSize(fontgeneral);
	PrefFontGeneral.setBold(vSongBook::isTrue(prefsets[10].toInt()));
	PrefFontGeneral.setWeight(50);

	PrefFontPreview.setFamily(prefsets[12]);
	PrefFontPreview.setPointSize(fontpreview);
	PrefFontPreview.setBold(vSongBook::isTrue(prefsets[13].toInt()));
	PrefFontPreview.setWeight(50);

	PrefFontPresent.setFamily(prefsets[15]);
	PrefFontPresent.setPointSize(fontpresent);
	PrefFontPresent.setBold(vSongBook::isTrue(prefsets[16].toInt()));
	PrefFontPresent.setWeight(50);

	ui->GrpGeneralAppFont->setTitle(" App General Font " + prefsets[8] + " ");
	ui->GrpSongPreviewFont->setTitle(" Song Preview Font " + prefsets[11] + " ");
	ui->GrpSongPresentFont->setTitle(" Song Presentation Font " + prefsets[14] + " ");

	ui->SldGeneralAppFont->setValue(fontgeneral);
	ui->SldSongPreviewFont->setValue(fontpreview);
	ui->SldSongPresentFont->setValue(fontpresent);
}

void vSongPrefs::SetUpStuff()
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

void vSongPrefs::LoadNavigation(QString searchstr)
{
	QStringList strList;

	QStandardItemModel* naviModel = new QStandardItemModel();

	if (navigations.size() > 0) navigations.clear();

	QString SqlQuery = "SELECT navid, enabled, title, content, extra, tags FROM settings_navi";

	if (!searchstr.isEmpty())
	{
		SqlQuery.append(" WHERE title LIKE '%" + searchstr + "%' OR content LIKE '%" + searchstr + "%'");
	}

	sqlite3* db;
	char* err_msg = NULL, ** qryResult = NULL;
	int row, col, rc = sqlite3_open_v2(pref_db, &db, SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE, NULL);

	SqlQuery.append(" ORDER BY navid ASC");
	QByteArray bar = SqlQuery.toLocal8Bit();
	char* sqlQuery = bar.data();

	rc = sqlite3_get_table(db, sqlQuery, &qryResult, &row, &col, &err_msg);

	for (int i = 1; i < row + 1; i++)
	{
		navigations.push_back(*(qryResult + i * col + 0));

		QStandardItem* naviItem = new QStandardItem;
		ItemData navigation;
		navigation.image = "res/settings.png";
		navigation.title = *(qryResult + i * col + 2);
		navigation.content = *(qryResult + i * col + 3);

		naviItem->setData(QVariant::fromValue(navigation), Qt::UserRole + 1);
		naviModel->appendRow(naviItem);
	}

	ItemDelegate* itemDelegate = new ItemDelegate(this);
	ui->LstNavigation->setItemDelegate(itemDelegate);
	ui->LstNavigation->setModel(naviModel);
	ui->LstNavigation->setSpacing(1);
	ui->LstNavigation->setStyleSheet("* { background-color: #D3D3D3; }");

	sqlite3_free_table(qryResult);
	sqlite3_close(db);

	ui->LstNavigation->setCurrentIndex(naviModel->index(0, 0));
}

void vSongPrefs::OpenSelectedTab(const QModelIndex& index)
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

void vSongPrefs::ChangeGeneralFont(int newfont)
{
	PrefFontGeneral.setPointSize(newfont);
	ui->TxtSampleText->setFont(PrefFontGeneral);
	vSongBook::SetOption("general_font_size", QString::number(newfont));
	ui->GrpGeneralAppFont->setTitle(" App General Font " + QString::number(newfont) + " ");
}

void vSongPrefs::ChangePreviewFont(int newfont)
{
	PrefFontPreview.setPointSize(newfont);
	ui->TxtSampleText->setFont(PrefFontPreview);
	vSongBook::SetOption("preview_font_size", QString::number(newfont));
	ui->GrpSongPreviewFont->setTitle(" Song Preview Font " + QString::number(newfont) + " ");
}

void vSongPrefs::ChangePresentFont(int newfont)
{
	PrefFontPresent.setPointSize(newfont);
	ui->TxtSampleText->setFont(PrefFontPresent);
	vSongBook::SetOption("present_font_size", QString::number(newfont));
	ui->GrpSongPresentFont->setTitle(" Song Presentation Font " + QString::number(newfont) + " ");
}

void vSongPrefs::on_TxtSearch_textChanged(const QString& searchstr)
{
	LoadNavigation(searchstr);
}

void vSongPrefs::on_LstNavigation_clicked(const QModelIndex& index)
{
	OpenSelectedTab(index);
}

void vSongPrefs::on_LstNavigation_doubleClicked(const QModelIndex& index)
{
	OpenSelectedTab(index);
}

void vSongPrefs::on_BtnTabletMode_clicked()
{
	vSongBook::SetOption("tablet_mode", vSongBook::booltoInt(ui->BtnTabletMode->isChecked()));
}

void vSongPrefs::on_BtnSearchCriteria_clicked()
{
	vSongBook::SetOption("search_allbooks", vSongBook::booltoInt(ui->BtnSearchCriteria->isChecked()));
}

void vSongPrefs::on_CmbLanguage_currentIndexChanged(int index)
{
	vSongBook::SetOption("language", languages[index]);
}

void vSongPrefs::on_TxtYourName_textChanged(const QString& newname)
{
	vSongBook::SetOption("app_user", newname);
}

void vSongPrefs::on_BtnDownGeneralAppFont_clicked()
{
	if ((fontgeneral - 2) > 9)
	{
		fontgeneral = fontgeneral - 2;
		ChangeGeneralFont(fontgeneral);
	}
}

void vSongPrefs::on_BtnUpGeneralAppFont_clicked()
{
	if ((fontgeneral + 2) < 51)
	{
		fontgeneral = fontgeneral + 2;
		ChangeGeneralFont(fontgeneral);
	}
}

void vSongPrefs::on_SldGeneralAppFont_valueChanged(int value)
{
	ChangeGeneralFont(value);
}

void vSongPrefs::on_CmbGeneralAppFont_currentIndexChanged(int index)
{
	QString newfont = fontFamily[index];
	PrefFontGeneral.setFamily(newfont);
	ui->TxtSampleText->setFont(PrefFontGeneral);
	vSongBook::SetOption("general_font_type", newfont);
}

void vSongPrefs::on_BtnGeneralAppFont_clicked()
{
	PrefFontGeneral.setBold(ui->BtnGeneralAppFont->isChecked());
	ui->TxtSampleText->setFont(PrefFontGeneral);
	vSongBook::SetOption("general_font_bold", vSongBook::booltoInt(ui->BtnGeneralAppFont->isChecked()));
}

void vSongPrefs::on_BtnDownSongPreviewFont_clicked()
{
	if ((fontpreview - 2) > 9)
	{
		fontpreview = fontpreview - 2;
		ChangePreviewFont(fontpreview);
	}
}

void vSongPrefs::on_BtnUpSongPreviewFont_clicked()
{
	if ((fontpreview + 2) < 51)
	{
		fontpreview = fontpreview + 2;
		ChangePreviewFont(fontpreview);
	}
}

void vSongPrefs::on_SldSongPreviewFont_valueChanged(int value)
{
	ChangePreviewFont(value);
}

void vSongPrefs::on_CmbSongPreviewFont_currentIndexChanged(int index)
{
	QString newfont = fontFamily[index];
	PrefFontPreview.setFamily(newfont);
	ui->TxtSampleText->setFont(PrefFontPreview);
	vSongBook::SetOption("preview_font_type", newfont);
}

void vSongPrefs::on_BtnSongPreviewFont_clicked()
{
	PrefFontPreview.setBold(ui->BtnSongPreviewFont->isChecked());
	ui->TxtSampleText->setFont(PrefFontPreview);
	vSongBook::SetOption("preview_font_bold", vSongBook::booltoInt(ui->BtnSongPreviewFont->isChecked()));
}

void vSongPrefs::on_BtnDownSongPresentFont_clicked()
{
	if ((fontpresent - 2) > 9)
	{
		fontpresent = fontpresent - 2;
		ChangePresentFont(fontpresent);
	}
}

void vSongPrefs::on_BtnUpSongPresentFont_clicked()
{
	if ((fontpresent + 2) < 99)
	{
		fontpresent = fontpresent + 2;
		ChangePresentFont(fontpresent);
	}
}

void vSongPrefs::on_SldSongPresentFont_valueChanged(int value)
{
	ChangePresentFont(value);
}

void vSongPrefs::on_CmbSongPresentFont_currentIndexChanged(int index)
{
	QString newfont = fontFamily[index];
	PrefFontPresent.setFamily(newfont);
	ui->TxtSampleText->setFont(PrefFontPresent);
	vSongBook::SetOption("present_font_type", newfont);
}

void vSongPrefs::on_BtnSongPresentFont_clicked()
{
	PrefFontPresent.setBold(ui->BtnSongPresentFont->isChecked());
	ui->TxtSampleText->setFont(PrefFontPresent);
	vSongBook::SetOption("present_font_bold", vSongBook::booltoInt(ui->BtnSongPresentFont->isChecked()));
}

void vSongPrefs::on_BtnTheme1_clicked()
{

}

void vSongPrefs::on_BtnTheme2_clicked()
{

}

void vSongPrefs::on_BtnTheme3_clicked()
{

}

void vSongPrefs::on_BtnTheme4_clicked()
{

}

void vSongPrefs::on_BtnTheme5_clicked()
{

}

void vSongPrefs::on_BtnTheme6_clicked()
{

}

void vSongPrefs::on_BtnTheme7_clicked()
{

}

void vSongPrefs::on_BtnTheme8_clicked()
{

}

void vSongPrefs::on_BtnTheme9_clicked()
{

}

void vSongPrefs::on_BtnTheme10_clicked()
{

}

void vSongPrefs::on_BtnTheme11_clicked()
{

}

void vSongPrefs::on_BtnTheme12_clicked()
{

}

void vSongPrefs::on_BtnTheme13_clicked()
{

}

void vSongPrefs::on_BtnTheme14_clicked()
{

}

void vSongPrefs::on_BtnTheme15_clicked()
{

}
