#include "vSongPrefs.h"
#include "ui_vSongPrefs.h"
#include "sqlite.h"
#include "RunSql.h"
#include "sqlitetablemodel.h"
#include <QStandardItemModel>
#include <QObject>

#include "vSongBook.h"
#include "vItemData.h"
#include "vItemDelegate.h"

char* pref_db = "Data/vSongBook.db";
int fontgeneral, fontpreview, fontpresent;
std::vector<QString> prefsets, navigations;
QFont PrefFontGeneral, PrefFontPreview, PrefFontPresent;

vSongPrefs::vSongPrefs(QWidget* parent) :
    QDialog(parent),
    ui(new Ui::vSongPrefs)
{
    ui->setupUi(this);

	GetSettings();
	ReloadSettings();
	LoadNavigation("");

	//ui->TabPage1->show();
	//ui->TabPage2->hide();
	//ui->TabPage3->hide();

    this->setFixedSize(this->width(), this->height());
    this->setWindowFlags(this->windowFlags() & ~Qt::WindowContextHelpButtonHint);

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
		vItemData navigation;
		navigation.title = *(qryResult + i * col + 2);
		navigation.content = *(qryResult + i * col + 3);

		naviItem->setData(QVariant::fromValue(navigation), Qt::UserRole + 1);
		naviModel->appendRow(naviItem);
	}

	vItemDelegate* itemDelegate = new vItemDelegate(this);
	ui->LstNavigation->setItemDelegate(itemDelegate);
	ui->LstNavigation->setModel(naviModel);

	sqlite3_free_table(qryResult);
	sqlite3_close(db);

	ui->LstNavigation->setCurrentIndex(naviModel->index(0, 0));
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

	PrefFontGeneral.setFamily(prefsets[9]);
	PrefFontGeneral.setPointSize(fontgeneral);
	PrefFontGeneral.setBold(false);
	PrefFontGeneral.setWeight(50);

	PrefFontPreview.setFamily(prefsets[12]);
	PrefFontPreview.setPointSize(fontpreview);
	PrefFontPreview.setBold(false);
	PrefFontPreview.setWeight(50);

	PrefFontPresent.setFamily(prefsets[15]);
	PrefFontPresent.setPointSize(fontpresent);
	PrefFontPresent.setBold(false);
	PrefFontPresent.setWeight(50);

	ui->GrpGeneralAppFont->setTitle(" App Genral Font " + prefsets[8] + " ");
	ui->GrpSongPreviewFont->setTitle(" Song Preview Font " + prefsets[11] + " ");
	//ui->GrpSongPresentFont->setTitle(" Song Presentation Font " + prefsets[14] + " ");

	ui->SldGeneralAppFont->setValue(fontgeneral);
	ui->SldSongPreviewFont->setValue(fontpreview);
	//ui->SldSongPresentFont->setValue(fontpresent);

	ReloadControls();
}

void vSongPrefs::ReloadControls()
{
	//PanelLeft
	ui->TxtSearch->setFont(PrefFontGeneral);
	
	//PanelRight >> PrefsTabs >> TabPage1 >> LayoutTabPage1
	ui->LabelTab1->setFont(PrefFontGeneral);

	ui->GrpTabletMode->setFont(PrefFontGeneral);
	ui->LblTabletMode->setFont(PrefFontGeneral);
	ui->BtnTabletMode->setFont(PrefFontGeneral);

	ui->GrpSearchCriteria->setFont(PrefFontGeneral);
	ui->LblSearchCriteria->setFont(PrefFontGeneral);
	ui->BtnSearchCriteria->setFont(PrefFontGeneral);

	ui->GrpLanguage->setFont(PrefFontGeneral);
	ui->LblLanguage->setFont(PrefFontGeneral);
	ui->CmbLanguage->setFont(PrefFontGeneral);

	ui->GrpYourName->setFont(PrefFontGeneral);
	ui->TxtYourName->setFont(PrefFontGeneral);
	
	//TabPage2 >> LayoutTabPage
	ui->LblTabPage2->setFont(PrefFontGeneral);
	ui->GrpSampleText->setFont(PrefFontGeneral);
	//ui->TxtSampleText->setFont(PrefFontGeneral);

	ui->GrpGeneralAppFont->setFont(PrefFontGeneral);
	ui->CmbGeneralAppFont->setFont(PrefFontGeneral);
	ui->BtnGeneralAppFont->setFont(PrefFontGeneral);

	ui->GrpSongPreviewFont->setFont(PrefFontGeneral);
	ui->CmbSongPreviewFont->setFont(PrefFontGeneral);
	ui->BtnSongPreviewFont->setFont(PrefFontGeneral);

	//ui->GrpSongPresentFont->setFont(PrefFontGeneral);
	//ui->CmbSongPresentFont->setFont(PrefFontGeneral);
	//ui->BtnSongPresentFont->setFont(PrefFontGeneral);
		
	//TabPage3	
	//TopLayout
	ui->BtnTheme1->setFont(PrefFontGeneral);
	ui->BtnTheme2->setFont(PrefFontGeneral);
	ui->BtnTheme3->setFont(PrefFontGeneral);
	ui->BtnTheme4->setFont(PrefFontGeneral);
	ui->BtnTheme5->setFont(PrefFontGeneral);
	
	//MidLayout
	ui->BtnTheme6->setFont(PrefFontGeneral);
	ui->BtnTheme7->setFont(PrefFontGeneral);
	ui->BtnTheme8->setFont(PrefFontGeneral);
	ui->BtnTheme9->setFont(PrefFontGeneral);
	ui->BtnTheme10->setFont(PrefFontGeneral);

	//DownLayout
	ui->BtnTheme11->setFont(PrefFontGeneral);
	ui->BtnTheme12->setFont(PrefFontGeneral);
	ui->BtnTheme13->setFont(PrefFontGeneral);
	ui->BtnTheme14->setFont(PrefFontGeneral);
	ui->BtnTheme15->setFont(PrefFontGeneral);
}

void vSongPrefs::ChangeGeneralFont(int newfont)
{
	PrefFontGeneral.setPointSize(newfont);
	vSongBook::SetOption("general_font_size", QString::number(newfont));
	GetSettings();
	ReloadSettings();
}

void vSongPrefs::ChangePreviewFont(int newfont)
{
	PrefFontPreview.setPointSize(newfont);
	vSongBook::SetOption("preview_font_size", QString::number(newfont));
	GetSettings();
	ReloadSettings();
}

void vSongPrefs::ChangePresentFont(int newfont)
{
	PrefFontPresent.setPointSize(newfont);
	vSongBook::SetOption("present_font_size", QString::number(newfont));
	GetSettings();
	ReloadSettings();
}

void vSongPrefs::on_LstNavigation_clicked(const QModelIndex &index)
{
	OpenSelectedTab(index);
}

void vSongPrefs::on_LstNavigation_doubleClicked(const QModelIndex &index)
{
	OpenSelectedTab(index);
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
void vSongPrefs::on_TxtSearch_textChanged(const QString & searchstr)
{
	LoadNavigation(searchstr);
}

void vSongPrefs::on_BtnTabletMode_clicked()
{

}

void vSongPrefs::on_BtnSearchCriteria_clicked()
{

}

void vSongPrefs::on_CmbLanguage_currentIndexChanged(int index)
{

}

void vSongPrefs::on_TxtYourName_textChanged(const QString &arg1)
{

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

}

void vSongPrefs::on_BtnGeneralAppFont_clicked()
{

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

}

void vSongPrefs::on_BtnSongPreviewFont_clicked()
{

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

}

void vSongPrefs::on_BtnSongPresentFont_clicked()
{

}

vSongPrefs::~vSongPrefs()
{
    delete ui;
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
