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
enum
{
	Button_bigger,
	Button_smaller,
	Button_max
};

wxBitmap CheckButtonsBitmaps[Button_max];
vector<wxString> checkset, checklang;
int checkfontmain, checkfontapp;

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
	this->SetFont(wxFont(12, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Trebuchet MS")));
	this->SetBackgroundColour(wxColour(255, 255, 255));

	wxBoxSizer* MainWrapper;
	MainWrapper = new wxBoxSizer(wxVERTICAL);

	QuickSettings(MainWrapper);

	this->SetSizer(MainWrapper);
	this->Layout();

	this->Centre(wxBOTH);

	// Connect Events
	BtnSearchCriteria->Connect(wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler(vSongCheck::BtnSearchCriteria_Click), NULL, this);
	BtnTabletMode->Connect(wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler(vSongCheck::BtnTabletMode_Click), NULL, this);
	CmbLanguage->Connect(wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler(vSongCheck::CmbLanguage_SelectionChange), NULL, this);
	TxtUserName->Connect(wxEVT_KEY_DOWN, wxKeyEventHandler(vSongCheck::TxtUserName_TextChange), NULL, this);
}

void vSongCheck::GetSettings()
{
	try {
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

void vSongCheck::InitializeSettings()
{
	checkfontmain = wxAtoi(checkset[5]);
	checkfontapp = AppSmata::PresenterFont(checkfontmain);
}

void vSongCheck::GetLanguages(wxString Language)
{
	try {
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

void vSongCheck::QuickSettings(wxBoxSizer* MainWrapper)
{
	SetIcon(wxICON(vsbicon));

	wxBoxSizer* InnerWrapper;
	InnerWrapper = new wxBoxSizer(wxVERTICAL);

	wxStaticBoxSizer* GrpTabletMode;
	GrpTabletMode = new wxStaticBoxSizer(new wxStaticBox(this, wxID_ANY, checklang[72]), wxHORIZONTAL);

	GrpTabletMode->SetMinSize(wxSize(-1, 75));
	LblTabletMode = new wxStaticText(GrpTabletMode->GetStaticBox(), wxID_ANY, checklang[73], wxDefaultPosition, wxDefaultSize, 0);
	LblTabletMode->Wrap(-1);
	LblTabletMode->SetFont(wxFont(checkfontapp, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Trebuchet MS")));

	GrpTabletMode->Add(LblTabletMode, 1, wxALL, 5);

	BtnTabletMode = new wxRadioButton(GrpTabletMode->GetStaticBox(), wxID_ANY, wxT("ON"), wxDefaultPosition, wxDefaultSize, 0);
	BtnTabletMode->SetFont(wxFont(checkfontmain, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxT("Trebuchet MS")));

	GrpTabletMode->Add(BtnTabletMode, 0, wxALL, 5);

	InnerWrapper->Add(GrpTabletMode, 0, wxALL | wxEXPAND, 5);

	wxStaticBoxSizer* GrpSearchCriteria;
	GrpSearchCriteria = new wxStaticBoxSizer(new wxStaticBox(this, wxID_ANY, checklang[61]), wxHORIZONTAL);

	GrpSearchCriteria->SetMinSize(wxSize(-1, 75));
	LblTabletMode1 = new wxStaticText(GrpSearchCriteria->GetStaticBox(), wxID_ANY, checklang[60], wxDefaultPosition, wxDefaultSize, 0);
	LblTabletMode1->Wrap(-1);
	LblTabletMode1->SetFont(wxFont(checkfontmain, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Trebuchet MS")));

	GrpSearchCriteria->Add(LblTabletMode1, 1, wxALL, 5);

	BtnSearchCriteria = new wxRadioButton(GrpSearchCriteria->GetStaticBox(), wxID_ANY, wxT("ON"), wxDefaultPosition, wxDefaultSize, 0);
	BtnSearchCriteria->SetValue(true);
	BtnSearchCriteria->SetFont(wxFont(checkfontmain, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxT("Trebuchet MS")));

	GrpSearchCriteria->Add(BtnSearchCriteria, 0, wxALL, 5);

	InnerWrapper->Add(GrpSearchCriteria, 0, wxALL | wxEXPAND, 5);

	wxStaticBoxSizer* GrpLanguage;
	GrpLanguage = new wxStaticBoxSizer(new wxStaticBox(this, wxID_ANY, checklang[51]), wxHORIZONTAL);

	GrpLanguage->SetMinSize(wxSize(-1, 90));
	LbLanguage = new wxStaticText(GrpLanguage->GetStaticBox(), wxID_ANY, checklang[52], wxDefaultPosition, wxDefaultSize, 0);
	LbLanguage->Wrap(-1);
	LbLanguage->SetFont(wxFont(checkfontmain, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Trebuchet MS")));

	GrpLanguage->Add(LbLanguage, 1, wxALL, 5);

	CmbLanguage = new wxComboBox(GrpLanguage->GetStaticBox(), wxID_ANY, wxT("English"), wxDefaultPosition, wxDefaultSize, 0, NULL, wxCB_READONLY);
	CmbLanguage->Append(wxT("English"));
	CmbLanguage->Append(wxT("Swahili"));
	CmbLanguage->Append(wxT("French"));
	CmbLanguage->Append(wxT("Spanish"));
	CmbLanguage->Append(wxT("Chichewa"));
	CmbLanguage->Append(wxT("Portuguese"));
	CmbLanguage->SetSelection(0);
	GrpLanguage->Add(CmbLanguage, 0, wxALL, 5);

	InnerWrapper->Add(GrpLanguage, 0, wxALL | wxEXPAND, 5);

	wxStaticBoxSizer* GrpUserName;
	GrpUserName = new wxStaticBoxSizer(new wxStaticBox(this, wxID_ANY, checklang[106]), wxVERTICAL);

	GrpUserName->SetMinSize(wxSize(-1, 100));
	TxtUserName = new wxTextCtrl(GrpUserName->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(-1, 50), 0);
	GrpUserName->Add(TxtUserName, 1, wxALL | wxEXPAND, 5);

	LblUserName = new wxStaticText(GrpUserName->GetStaticBox(), wxID_ANY, "100 " + checklang[7], wxDefaultPosition, wxDefaultSize, 0);
	LblUserName->Wrap(-1);
	LblUserName->SetFont(wxFont(8, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Trebuchet MS")));

	GrpUserName->Add(LblUserName, 0, wxALL, 5);

	InnerWrapper->Add(GrpUserName, 0, wxALL | wxEXPAND, 5);

	MainWrapper->Add(InnerWrapper, 1, wxALL | wxEXPAND, 5);
}

void vSongCheck::BtnSearchCriteria_Click(wxCommandEvent&)
{

}

void vSongCheck::BtnTabletMode_Click(wxCommandEvent&)
{

}

void vSongCheck::CmbLanguage_SelectionChange(wxCommandEvent&)
{

}

void vSongCheck::TxtUserName_TextChange(wxKeyEvent&)
{

}

vSongCheck::~vSongCheck()
{
}
