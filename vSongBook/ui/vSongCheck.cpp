/////////////////////////////////////////////////////////////////////////////
// Name:        vSongCheck.cpp
// Purpose:     vSongBook for Desktop
// Author:      Jacksiro
// Modified by:
// Created:     27/07/19
// Copyright:   (c) AppSmata
// Licence:     wxWindows licence
/////////////////////////////////////////////////////////////////////////////

#include "AppSmata.h"
#include "vSongCheck.h"
#include "vSongHome.h"
enum
{
	Button_bigger,
	Button_smaller,
	Button_max
};

wxBitmap CheckButtonsBitmaps[Button_max];
vector<wxString> checkset, checklang, langlist;
int checkfontmain, checkfontapp, crts;
wxString check_fonty;

#if USE_XPM_BITMAPS
#define PREFS_BTN_BMP(bmp) \
        CheckButtonsBitmaps[Button_##bmp] = wxBitmap(bmp##_xpm)
#else // !USE_XPM_BITMAPS
#define PREFS_BTN_BMP(bmp) \
        CheckButtonsBitmaps[Button_##bmp] = wxBITMAP(bmp)
#endif // USE_XPM_BITMAPS/!USE_XPM_BITMAPS

vSongCheck::vSongCheck(const wxString& title) : wxFrame(NULL, wxID_ANY, title)
{
	GetSettings();
	GetLanguages(checkset[3]);

	this->SetSizeHints(wxDefaultSize, wxDefaultSize);
	this->SetFont(wxFont(12, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, check_fonty));
	this->SetBackgroundColour(wxColour(255, 255, 255));
	this->SetLabel(checklang[110]);

	wxBoxSizer* MainWrapper;
	MainWrapper = new wxBoxSizer(wxVERTICAL);

	QuickSettings(MainWrapper);

	this->SetSizer(MainWrapper);
	this->Layout();

	this->Centre(wxBOTH);

	InitializeLanguage();
	InitializeSettings();

	// Connect Events
	BtnSearchCriteria->Connect(wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler(vSongCheck::BtnSearchCriteria_Click), NULL, this);
	BtnTabletMode->Connect(wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler(vSongCheck::BtnTabletMode_Click), NULL, this);
	CmbLanguage->Connect(wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler(vSongCheck::CmbLanguage_SelectionChange), NULL, this);
	TxtUserName->Connect(wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler(vSongCheck::TxtUserName_TextChange), NULL, this);
	BtnSave->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(vSongCheck::BtnSave_Click), NULL, this);
	BtnCancel->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(vSongCheck::BtnCancel_Click), NULL, this);
}

void vSongCheck::GetSettings()
{
	try {
		if (checkset.size() > 0) checkset.clear();

		sqlite3* db;
		char* err_msg = NULL, ** qryResult = NULL;
		int row, col, rc = sqlite3_open_v2("Data\\Settings.db", &db, SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE, NULL);

		wxString sqlQuery = _T("SELECT content FROM settings ORDER BY settingid");

		rc = sqlite3_get_table(db, sqlQuery, &qryResult, &row, &col, &err_msg);

		for (int i = 1; i < row + 1; i++)
		{
			checkset.push_back(*(qryResult + i * col + 0));
		}

		sqlite3_free_table(qryResult);
		sqlite3_close(db);
	}
	catch (exception & ex) {}
}

void vSongCheck::GetLanguages(wxString Language)
{
	try {
		if (checklang.size() > 0) checklang.clear();

		sqlite3* db;
		char* err_msg = NULL, ** qryResult = NULL;
		int row, col, rc = sqlite3_open_v2("Data\\Language.db", &db, SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE, NULL);

		wxString sqlQuery = _T("SELECT content FROM " + Language + " ORDER BY stringid");

		rc = sqlite3_get_table(db, sqlQuery, &qryResult, &row, &col, &err_msg);

		for (int i = 1; i < row + 1; i++)
		{
			checklang.push_back(*(qryResult + i * col + 0));
		}

		sqlite3_free_table(qryResult);
		sqlite3_close(db);
	}
	catch (exception & ex) {}
}

void vSongCheck::InitializeLanguage()
{
	LblTabletGrp->SetLabel(checklang[72]);
	LblTabletMode->SetLabel(checklang[73]);
	LblSearchGrp->SetLabel(checklang[61]);
	LblSearchCriteria->SetLabel(checklang[60]);
	LbLanguageGrp->SetLabel(checklang[51]);
	LbLanguage->SetLabel(checklang[52]);
	LblUserNameGrp->SetLabel(checklang[106]);

	crts = (100 - TxtUserName->GetValue().Length());
	LblUserName->SetLabel(wxString::Format(wxT("%i"), crts) + " " + checklang[7]);

	BtnTabletMode->SetLabel(checklang[107]);
	BtnSearchCriteria->SetLabel(checklang[107]);
	BtnSave->SetLabel(checklang[108]);
	BtnCancel->SetLabel(checklang[109]);
	TxtUserName->SetValue(checkset[1]);
	this->SetLabel(checklang[110]);
}

void vSongCheck::InitializeSettings()
{
	check_fonty = checkset[6];
	checkfontmain = wxAtoi(checkset[5]);
	checkfontapp = AppSmata::PresenterFont(checkfontmain);

	LblTabletMode->SetFont(wxFont(checkfontapp, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, check_fonty));
	BtnTabletMode->SetFont(wxFont(checkfontmain, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, check_fonty));
	LblSearchCriteria->SetFont(wxFont(checkfontmain, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, check_fonty));
	BtnSearchCriteria->SetFont(wxFont(checkfontmain, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, check_fonty));
	LbLanguage->SetFont(wxFont(checkfontmain, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, check_fonty));
	CmbLanguage->SetFont(wxFont(checkfontmain, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, check_fonty));
	LblUserName->SetFont(wxFont(8, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, check_fonty));
	BtnSave->SetFont(wxFont(checkfontmain, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, check_fonty));
	BtnCancel->SetFont(wxFont(checkfontmain, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, check_fonty));
}

void vSongCheck::QuickSettings(wxBoxSizer* MainWrapper)
{
	SetIcon(wxICON(appicon));

	wxBoxSizer* InnerWrapper;
	InnerWrapper = new wxBoxSizer(wxVERTICAL);

	wxStaticBoxSizer* GrpTabletMode;
	LblTabletGrp = new wxStaticBox(this, wxID_ANY, wxEmptyString);
	GrpTabletMode = new wxStaticBoxSizer(LblTabletGrp, wxHORIZONTAL);

	GrpTabletMode->SetMinSize(wxSize(-1, 75));
	LblTabletMode = new wxStaticText(GrpTabletMode->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
	LblTabletMode->Wrap(-1);

	GrpTabletMode->Add(LblTabletMode, 1, wxALL, 5);

	BtnTabletMode = new wxRadioButton(GrpTabletMode->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(100, -1), 0);
	BtnTabletMode->SetValue(false);

	GrpTabletMode->Add(BtnTabletMode, 0, wxALL, 5);

	InnerWrapper->Add(GrpTabletMode, 0, wxALL | wxEXPAND, 5);

	wxStaticBoxSizer* GrpSearchCriteria;
	LblSearchGrp = new wxStaticBox(this, wxID_ANY, wxEmptyString);
	GrpSearchCriteria = new wxStaticBoxSizer(LblSearchGrp, wxHORIZONTAL);

	GrpSearchCriteria->SetMinSize(wxSize(-1, 75));
	LblSearchCriteria = new wxStaticText(GrpSearchCriteria->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
	LblSearchCriteria->Wrap(-1);

	GrpSearchCriteria->Add(LblSearchCriteria, 1, wxALL, 5);

	BtnSearchCriteria = new wxRadioButton(GrpSearchCriteria->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(100, -1), 0);
	BtnSearchCriteria->SetValue(true);

	GrpSearchCriteria->Add(BtnSearchCriteria, 0, wxALL, 5);

	InnerWrapper->Add(GrpSearchCriteria, 0, wxALL | wxEXPAND, 5);

	wxStaticBoxSizer* GrpLanguage;
	LbLanguageGrp = new wxStaticBox(this, wxID_ANY, wxEmptyString);
	GrpLanguage = new wxStaticBoxSizer(LbLanguageGrp, wxHORIZONTAL);

	GrpLanguage->SetMinSize(wxSize(-1, 90));
	LbLanguage = new wxStaticText(GrpLanguage->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
	LbLanguage->Wrap(-1);

	GrpLanguage->Add(LbLanguage, 1, wxALL, 5);

	CmbLanguage = new wxComboBox(GrpLanguage->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(200, -1), 0, NULL, wxCB_READONLY);
	CmbLanguage->Append(wxT("English"));
	langlist.push_back("English");
	CmbLanguage->Append(wxT("Swahili"));
	langlist.push_back("Swahili");
	CmbLanguage->Append(wxT("French"));
	langlist.push_back("French");
	CmbLanguage->Append(wxT("Spanish"));
	langlist.push_back("Spanish");
	CmbLanguage->Append(wxT("Chichewa"));
	langlist.push_back("Chichewa");
	CmbLanguage->Append(wxT("Portuguese"));
	langlist.push_back("Portuguese");
	CmbLanguage->SetSelection(AppSmata::SelectedValue(checkset[3], langlist));
	GrpLanguage->Add(CmbLanguage, 0, wxALL, 5);

	InnerWrapper->Add(GrpLanguage, 0, wxALL | wxEXPAND, 5);

	wxStaticBoxSizer* GrpUserName;
	LblUserNameGrp = new wxStaticBox(this, wxID_ANY, wxEmptyString);
	GrpUserName = new wxStaticBoxSizer(LblUserNameGrp, wxVERTICAL);

	GrpUserName->SetMinSize(wxSize(-1, 100));
	TxtUserName = new wxTextCtrl(GrpUserName->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(-1, 50), 0);
	TxtUserName->SetMaxLength(100);
	GrpUserName->Add(TxtUserName, 1, wxALL | wxEXPAND, 5);

	LblUserName = new wxStaticText(GrpUserName->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
	LblUserName->Wrap(-1);

	GrpUserName->Add(LblUserName, 0, wxALL, 5);

	InnerWrapper->Add(GrpUserName, 0, wxALL | wxEXPAND, 5);

	wxBoxSizer* OkCancelPanel;
	OkCancelPanel = new wxBoxSizer(wxHORIZONTAL);

	wxStaticText* LblOkCancel = new wxStaticText(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
	LblOkCancel->Wrap(-1);
	OkCancelPanel->Add(LblOkCancel, 1, wxALL, 5);

	wxBoxSizer* WrapOkCancel;
	WrapOkCancel = new wxBoxSizer(wxHORIZONTAL);

	BtnSave = new wxButton(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(175, 50), 0);
	WrapOkCancel->Add(BtnSave, 0, wxALL, 5);

	BtnCancel = new wxButton(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(175, 50), 0);
	WrapOkCancel->Add(BtnCancel, 0, wxALL, 5);


	OkCancelPanel->Add(WrapOkCancel, 0, wxALL, 5);


	InnerWrapper->Add(OkCancelPanel, 0, wxALIGN_CENTER | wxALL | wxEXPAND, 5);

	MainWrapper->Add(InnerWrapper, 1, wxALL | wxEXPAND, 5);
}

void vSongCheck::BtnSearchCriteria_Click(wxCommandEvent&)
{
	if (BtnSearchCriteria->GetValue() == true) AppSmata::SetOption("tablet_mode", "1");
	else AppSmata::SetOption("tablet_mode", "0");
}

void vSongCheck::BtnTabletMode_Click(wxCommandEvent&)
{
	if (BtnSearchCriteria->GetValue() == true) AppSmata::SetOption("search_allbooks", "1");
	else AppSmata::SetOption("search_allbooks", "0");
}

void vSongCheck::CmbLanguage_SelectionChange(wxCommandEvent&)
{
	AppSmata::SetOption("language", langlist[CmbLanguage->GetSelection()]);

	GetSettings();
	GetLanguages(checkset[3]);
	InitializeLanguage();
}

void vSongCheck::TxtUserName_TextChange(wxCommandEvent&)
{
	crts = (100 - TxtUserName->GetValue().Length());
	LblUserName->SetLabel(wxString::Format(wxT("%i"), crts) + " " + checklang[7]);
	AppSmata::SetOption("app_user", TxtUserName->GetValue());
}

void vSongCheck::BtnSave_Click(wxCommandEvent&)
{
	vSongHome* home = new vSongHome("vSongBook for Desktop v2.4.1 | " + checkset[1]);
	home->SetSize(1000, 800);
	home->Show(true);
	home->Center();
	home->Maximize(true);
	this->Close();

}

void vSongCheck::BtnCancel_Click(wxCommandEvent&)
{
	this->Close();
}

vSongCheck::~vSongCheck()
{
}
