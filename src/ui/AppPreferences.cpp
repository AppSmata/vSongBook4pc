#include <src\ui\AppPreferences.h>
#include <ui_AppPreferences.h>

#include <Application.h>
#include <sqlite.h>
#include <RunSql.h>
#include <sqlitetablemodel.h>

#include <AsBase.h>
#include <AsUtils.h>
#include <AsItem.h>
#include <AsPref.h>
#include <AsDelegate.h>
#include <AsPreference.h>

#include <QStandardItemModel>
#include <QObject>
#include <QGroupBox>
#include <QComboBox>
#include <QRadioButton>
#include <QScrollArea>
#include <QPushButton>
#include <QSlider>

int fontgeneral, fontpreview, fontpresent;
std::vector<QString> languages, pref_sets, navigations, pref_fonts;
QFont PrefFontGeneral, PrefFontPreview, PrefFontPresent, Font1, Font2;

QStandardItemModel *naviModel;
QStandardItemModel *prefModel;
AsDelegate *asDelegate;
AsPreference *asPreference;
QScrollArea *ScrollArea;
QWidget *ScrollPane;
QVBoxLayout* LstSettings;

AppPreferences::AppPreferences(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AppPreferences)
{
    ui->setupUi(this);

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

	Font1.setFamily(QString::fromUtf8("Trebuchet MS"));
	Font1.setPointSize(15);
	Font1.setBold(true);
	Font1.setWeight(50);

	Font2.setFamily(QString::fromUtf8("Trebuchet MS"));
	Font2.setPointSize(12);
	Font2.setBold(false);

	setStyleSheet("* { background-color: #FFFFFF; }");

	ui->LblWindowTitle->setStyleSheet("* { padding: 5px; font-size: 35px; border-bottom: 1px solid #000; }");

	ui->LblPageTitle->setStyleSheet("* { padding: 5px; font-size: 25px; border-bottom: 1px solid #000; }");

	QString WindowTitle = "<img src=\":/images/vSongBook.png\" width=\"50\" style=\"margin-bottom: -20px;\"> Manage Preferences";
	QByteArray window_title = WindowTitle.toLocal8Bit();
	ui->LblWindowTitle->setText(QApplication::translate("AppPreferences", window_title.data(), Q_NULLPTR));

	ui->TxtSearch->setStyleSheet("* { font-size: 18px; padding: 10px; background: #eee; 10px; margin: 5px; border-radius: 5px; border: 1px solid #000; }");
	
	ui->LstNavigation->setStyleSheet("* { border: 0px; padding: 5px; }");
	ui->PanelRight->setStyleSheet("#PanelRight { padding: 10px; border-left: 1px solid #000; }");
	ui->statusbar->setStyleSheet("* { border-top: 1px solid #000; }");

	naviModel = new QStandardItemModel();
	prefModel = new QStandardItemModel();
	asDelegate = new AsDelegate(this);
	asPreference = new AsPreference(this);

	ui->LstNavigation->setItemDelegate(asDelegate);
	ui->LstNavigation->setModel(naviModel);
	ui->LstNavigation->setSpacing(1);

	LoadNavigation("");
}

// Get the settings navigation
void AppPreferences::LoadNavigation(QString searchstr)
{
	QStringList strList;
	if (naviModel->rowCount() > 0) naviModel->clear();

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

	sqlite3_free_table(qryResult);
	sqlite3_close(db);

	ui->LstNavigation->setCurrentIndex(naviModel->index(0, 0));
	OpenSelectedPreference(naviModel->index(0, 0));

}

// On Click event function for LstNavigation
void AppPreferences::on_LstNavigation_clicked(const QModelIndex& index)
{
	OpenSelectedPreference(index);
}

// On Double Click event function for LstNavigation
void AppPreferences::on_LstNavigation_doubleClicked(const QModelIndex& index)
{
	OpenSelectedPreference(index);
}

void AppPreferences::CreateScrollArea()
{
	if (ScrollArea != NULL) delete ScrollArea;

	ScrollArea = new QScrollArea(ui->PanelRight);
	ScrollArea->setObjectName("ScrollArea");
	ScrollArea->setFrameShape(QFrame::NoFrame);
	ScrollArea->setFrameShadow(QFrame::Plain);
	ScrollArea->setWidgetResizable(true);
	ScrollPane = new QWidget();
	ScrollPane->setObjectName("ScrollPane");
	ScrollPane->setGeometry(QRect(0, 0, 528, 545));
	QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Preferred);
	sizePolicy1.setHorizontalStretch(0);
	sizePolicy1.setVerticalStretch(0);
	sizePolicy1.setHeightForWidth(ScrollPane->sizePolicy().hasHeightForWidth());
	ScrollPane->setSizePolicy(sizePolicy1);
	ScrollPane->setMinimumSize(QSize(500, 0));
	QVBoxLayout* InnerLayout = new QVBoxLayout(ScrollPane);
	InnerLayout->setSpacing(0);
	InnerLayout->setObjectName("InnerLayout");
	InnerLayout->setContentsMargins(0, 0, 0, 0);
	LstSettings = new QVBoxLayout();
	LstSettings->setObjectName("LstSettings");

	InnerLayout->addLayout(LstSettings);

	ScrollArea->setWidget(ScrollPane);

	ui->verticalLayout->addWidget(ScrollArea);
}

// Show the appropriate selected tab
void AppPreferences::OpenSelectedPreference(const QModelIndex& index)
{
	int setTab = navigations[index.row()].toInt();
	std::vector<QString> CmbOptions;

	if (prefModel->rowCount() > 0) prefModel->clear();
	CreateScrollArea();

	switch (setTab)
	{
		case 1:
			ui->LblPageTitle->setText("GENERAL OPTIONS");

			CmbOptions.push_back("English");
			CmbOptions.push_back("Swahili");
			CmbOptions.push_back("French");
			CmbOptions.push_back("Spanish");
			CmbOptions.push_back("Portuguesse");
			CmbOptions.push_back("Chichewa");

			AddSelect(" Language: ", "Prefferred Language", 0, CmbOptions);
			AddBlankWidget(); 
			AddRadio(" Tablet Mode: ", "Table Mode is when you are using a Touch Screen Input", 0);
			AddBlankWidget();
			AddRadio(" Search Criteria: ", "Search all songbooks", 1);
			AddBlankWidget();
			AddTextbox(" Your Name: ", "Your Name/Name of your Church", "");
			break;

		case 2:
			ui->LblPageTitle->setText("APP FONT OPTIONS");

			AddFontGroup(" General App Font: ", 18, "Trebuchet MS", false);
			AddBlankWidget();
			AddFontGroup(" Song Preview Font: ", 22, "Trebuchet MS", false);
			AddBlankWidget();
			AddFontGroup("Song Presentation Font: ", 35, "Trebuchet MS", true);
			break;

		case 3:
			ui->LblPageTitle->setText("PRESENTATION THEMES");
		
			break;
	}

	QVBoxLayout *vLayoutX = new QVBoxLayout();
	QWidget *widgetX = new QWidget(ScrollPane);
	vLayoutX->addWidget(widgetX);
	LstSettings->addLayout(vLayoutX);
}

void AppPreferences::AddBlankWidget()
{
	QWidget* widgetX = new QWidget(ScrollPane);
	QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
	sizePolicy1.setHorizontalStretch(0);
	sizePolicy1.setVerticalStretch(0);
	sizePolicy1.setHeightForWidth(widgetX->sizePolicy().hasHeightForWidth());
	widgetX->setSizePolicy(sizePolicy1);
	widgetX->setMinimumSize(QSize(0, 0));
	QHBoxLayout* Layout1 = new QHBoxLayout(widgetX);
	//widgetX->setStyleSheet("* { padding: 5px; }");
	LstSettings->addWidget(widgetX);
}

void AppPreferences::AddSelect(QString title, QString description, int value, std::vector<QString> options)
{
	QGroupBox *GrpSettings = new QGroupBox(ScrollPane);
	GrpSettings->setObjectName("GrpSettings");
	QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
	sizePolicy1.setHorizontalStretch(0);
	sizePolicy1.setVerticalStretch(0);
	sizePolicy1.setHeightForWidth(GrpSettings->sizePolicy().hasHeightForWidth());
	GrpSettings->setSizePolicy(sizePolicy1);
	GrpSettings->setMinimumSize(QSize(0, 0));
	QHBoxLayout *Layout1 = new QHBoxLayout(GrpSettings);
	QLabel *LblSettings = new QLabel(GrpSettings);

	QComboBox *CmbSettings = new QComboBox(GrpSettings);
	CmbSettings->setObjectName("CmbSettings");
	QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Fixed);
	sizePolicy2.setHorizontalStretch(0);
	sizePolicy2.setVerticalStretch(0);
	sizePolicy2.setHeightForWidth(CmbSettings->sizePolicy().hasHeightForWidth());
	CmbSettings->setSizePolicy(sizePolicy2);
	CmbSettings->setMinimumSize(QSize(100, 0));
	CmbSettings->setStyleSheet("* { font-size: 18px; padding: 5px; margin: 5px; background: #fff; border-radius: 5px; border: 1px solid #000; }");

	for (decltype(options.size()) i = 0; i < options.size(); ++i)
		CmbSettings->addItem(options[i]);

	GrpSettings->setFont(Font1);
	LblSettings->setFont(Font2);
	CmbSettings->setFont(Font2);

	GrpSettings->setTitle(title);
	LblSettings->setText(description);

	Layout1->addWidget(LblSettings);
	Layout1->addWidget(CmbSettings);
	LstSettings->addWidget(GrpSettings);
}

void AppPreferences::AddRadio(QString title, QString description, int value)
{
	QGroupBox *GrpSettings = new QGroupBox(ScrollPane);
	GrpSettings->setObjectName("GrpSettings");
	QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
	sizePolicy1.setHorizontalStretch(0);
	sizePolicy1.setVerticalStretch(0);
	sizePolicy1.setHeightForWidth(GrpSettings->sizePolicy().hasHeightForWidth());
	GrpSettings->setSizePolicy(sizePolicy1);
	GrpSettings->setMinimumSize(QSize(0, 0));
	QHBoxLayout *Layout1 = new QHBoxLayout(GrpSettings);
	QLabel *LblSettings = new QLabel(GrpSettings);
	QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Preferred);
	sizePolicy2.setHorizontalStretch(0);
	sizePolicy2.setVerticalStretch(0);
	sizePolicy2.setHeightForWidth(LblSettings->sizePolicy().hasHeightForWidth());
	LblSettings->setSizePolicy(sizePolicy2);

	QRadioButton *BtnSettings = new QRadioButton(GrpSettings);

	GrpSettings->setFont(Font1);
	LblSettings->setFont(Font2);
	BtnSettings->setFont(Font2);

	GrpSettings->setTitle(title);
	LblSettings->setText(description);
	BtnSettings->setText("ON");
	if (value == 1) BtnSettings->setChecked(true);

	Layout1->addWidget(LblSettings);
	Layout1->addWidget(BtnSettings);
	LstSettings->addWidget(GrpSettings);
}

void AppPreferences::AddTextbox(QString title, QString description, QString value)
{
	QGroupBox *GrpSettings = new QGroupBox(ScrollPane);
	GrpSettings->setObjectName("GrpSettings");
	QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
	sizePolicy1.setHorizontalStretch(0);
	sizePolicy1.setVerticalStretch(0);
	sizePolicy1.setHeightForWidth(GrpSettings->sizePolicy().hasHeightForWidth());
	GrpSettings->setSizePolicy(sizePolicy1);
	GrpSettings->setMinimumSize(QSize(0, 0));
	QVBoxLayout *Layout1 = new QVBoxLayout(GrpSettings);
	QLabel *LblSettings = new QLabel(GrpSettings);

	QLineEdit *TxtInput = new QLineEdit(GrpSettings);
	TxtInput->setObjectName(QString::fromUtf8("TxtInput"));
	QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Preferred);
	sizePolicy2.setHorizontalStretch(0);
	sizePolicy2.setVerticalStretch(0);
	sizePolicy2.setHeightForWidth(TxtInput->sizePolicy().hasHeightForWidth());
	TxtInput->setSizePolicy(sizePolicy2);
	TxtInput->setMinimumSize(QSize(400, 0));

	TxtInput->setStyleSheet("* { font-size: 18px; padding: 10px; background: #eee; margin: 5px; border-radius: 5px; border: 1px solid #000; }");

	GrpSettings->setFont(Font1);
	LblSettings->setFont(Font2);
	TxtInput->setFont(Font2);

	GrpSettings->setTitle(title);
	LblSettings->setText(description);
	TxtInput->setText(value);
	//if (value == 1) BtnSettings->setChecked(true);

	Layout1->addWidget(LblSettings);
	Layout1->addWidget(TxtInput);
	LstSettings->addWidget(GrpSettings);
}

void AppPreferences::AddFontGroup(QString title, int fontsize, QString fontfamily, bool isbold)
{
	QGroupBox* GrpSettings = new QGroupBox(ScrollPane);
	GrpSettings->setObjectName("GrpSettings");
	QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
	sizePolicy1.setHorizontalStretch(0);
	sizePolicy1.setVerticalStretch(0);
	sizePolicy1.setHeightForWidth(GrpSettings->sizePolicy().hasHeightForWidth());
	GrpSettings->setSizePolicy(sizePolicy1);
	GrpSettings->setMinimumSize(QSize(0, 0));
	QHBoxLayout *Layout1 = new QHBoxLayout(GrpSettings);
	QPushButton *BtnDown = new QPushButton(GrpSettings);
	BtnDown->setObjectName(QString::fromUtf8("BtnDown"));
	QIcon icon1;
	icon1.addFile(":/images/Down_Black.png", QSize(), QIcon::Normal, QIcon::Off);
	BtnDown->setIcon(icon1);

	QSlider *SldFont = new QSlider(GrpSettings);
	SldFont->setObjectName(QString::fromUtf8("SldFont"));
	SldFont->setOrientation(Qt::Horizontal);

	QPushButton *BtnUp = new QPushButton(GrpSettings);
	BtnUp->setObjectName(QString::fromUtf8("BtnUp"));
	QIcon icon2;
	icon2.addFile(":/images/Up_Black.png", QSize(), QIcon::Normal, QIcon::Off);
	BtnUp->setIcon(icon2);

	QComboBox *CmbFont = new QComboBox(GrpSettings);
	CmbFont->setObjectName("CmbFont");
	QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Fixed);
	sizePolicy2.setHorizontalStretch(0);
	sizePolicy2.setVerticalStretch(0);
	sizePolicy2.setHeightForWidth(CmbFont->sizePolicy().hasHeightForWidth());
	CmbFont->setSizePolicy(sizePolicy2);
	CmbFont->setMinimumSize(QSize(50, 0));

	BtnDown->setStyleSheet("* { font-size: 18px; padding: 5px; margin: 5px; background: #fff; border-radius: 5px; border: 1px solid #000; }");
	BtnUp->setStyleSheet("* { font-size: 18px; padding: 5px; margin: 5px; background: #fff; border-radius: 5px; border: 1px solid #000; }");
	CmbFont->setStyleSheet("* { font-size: 18px; padding: 5px; margin: 5px; background: #fff; border-radius: 5px; border: 1px solid #000; }");

	for (decltype(pref_fonts.size()) i = 0; i < pref_fonts.size(); ++i) 
		CmbFont->addItem(pref_fonts[i]);

	QRadioButton *BtnBold = new QRadioButton(GrpSettings);
	BtnBold->setObjectName("BtnBold");
	BtnBold->setText("BOLD");

	GrpSettings->setFont(Font1);
	BtnDown->setFont(Font2);
	SldFont->setFont(Font2);
	BtnUp->setFont(Font2);
	CmbFont->setFont(Font2);
	BtnBold->setFont(Font2);	

	GrpSettings->setTitle(title);
	if (isbold) BtnBold->setChecked(true);

	Layout1->addWidget(BtnDown);
	Layout1->addWidget(SldFont);
	Layout1->addWidget(BtnUp);
	Layout1->addWidget(CmbFont);
	Layout1->addWidget(BtnBold);
	LstSettings->addWidget(GrpSettings);
}

// On Text Change event function for TxtSearch
void AppPreferences::on_TxtSearch_textChanged(const QString& searchstr)
{
	LoadNavigation(searchstr);
}


// Class Destructor
AppPreferences::~AppPreferences()
{
    delete ui;
}


