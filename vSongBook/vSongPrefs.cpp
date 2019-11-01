/////////////////////////////////////////////////////////////////////////////
// Name:        vSongPrefs.cpp
// Purpose:     vSongBook for Desktop
// Author:      Jacksiro
// Modified by:
// Created:     27/07/19
// Copyright:   (c) AppSmata
// Licence:     wxWindows licence
/////////////////////////////////////////////////////////////////////////////

#include "vSongPrefs.h"

vSongPrefs::vSongPrefs(const wxString& title) : wxFrame(NULL, wxID_ANY, title)
{
	this->SetSizeHints(wxDefaultSize, wxDefaultSize);
	this->SetFont(wxFont(12, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Trebuchet MS")));
	this->SetBackgroundColour(wxColour(255, 255, 255));
	
	wxBoxSizer* MainWrapper;
	MainWrapper = new wxBoxSizer(wxVERTICAL);

	TabMain = new wxNotebook(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0);
	TabMain->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOW));

	MainWrapper->Add(TabMain, 1, wxEXPAND | wxALL, 5);

	PopulateTabOne();
	PopulateTabTwo();
	PopulateTabThree();
	PopulateTabFour();

	this->SetSizer(MainWrapper);
	this->Layout();

	this->Centre(wxBOTH);
}

void vSongPrefs::PopulateTabOne()
{
	TabOne = new wxScrolledWindow(TabMain, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHSCROLL | wxVSCROLL);
	TabOne->SetScrollRate(5, 5);
	TabOne->SetMinSize(wxSize(-1, 75));

	wxBoxSizer* WrapOne;
	WrapOne = new wxBoxSizer(wxVERTICAL);

	WrapOne->SetMinSize(wxSize(-1, 800));
	wxStaticBoxSizer* GrpTabletMode;
	GrpTabletMode = new wxStaticBoxSizer(new wxStaticBox(TabOne, wxID_ANY, wxT(" Tablet Mode: ")), wxHORIZONTAL);

	GrpTabletMode->SetMinSize(wxSize(-1, 75));
	LblTabletMode = new wxStaticText(GrpTabletMode->GetStaticBox(), wxID_ANY, wxT("Tablet Mode is when you are using a touch screen input"), wxDefaultPosition, wxDefaultSize, 0);
	LblTabletMode->Wrap(-1);
	LblTabletMode->SetFont(wxFont(12, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Trebuchet MS")));

	GrpTabletMode->Add(LblTabletMode, 1, wxALL, 5);

	BtnTabletMode = new wxRadioButton(GrpTabletMode->GetStaticBox(), wxID_ANY, wxT("ON"), wxDefaultPosition, wxDefaultSize, 0);
	BtnTabletMode->SetFont(wxFont(12, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxT("Trebuchet MS")));

	GrpTabletMode->Add(BtnTabletMode, 0, wxALL, 5);

	WrapOne->Add(GrpTabletMode, 0, wxALL | wxEXPAND, 5);

	wxStaticBoxSizer* GrpSearchCriteria;
	GrpSearchCriteria = new wxStaticBoxSizer(new wxStaticBox(TabOne, wxID_ANY, wxT(" Search Criteria: ")), wxHORIZONTAL);

	GrpSearchCriteria->SetMinSize(wxSize(-1, 75));
	LblTabletMode1 = new wxStaticText(GrpSearchCriteria->GetStaticBox(), wxID_ANY, wxT("Search in All Songbooks"), wxDefaultPosition, wxDefaultSize, 0);
	LblTabletMode1->Wrap(-1);
	LblTabletMode1->SetFont(wxFont(12, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Trebuchet MS")));

	GrpSearchCriteria->Add(LblTabletMode1, 1, wxALL, 5);

	BtnSearchCriteria = new wxRadioButton(GrpSearchCriteria->GetStaticBox(), wxID_ANY, wxT("ON"), wxDefaultPosition, wxDefaultSize, 0);
	BtnSearchCriteria->SetValue(true);
	BtnSearchCriteria->SetFont(wxFont(12, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxT("Trebuchet MS")));

	GrpSearchCriteria->Add(BtnSearchCriteria, 0, wxALL, 5);

	WrapOne->Add(GrpSearchCriteria, 0, wxALL | wxEXPAND, 5);

	wxStaticBoxSizer* GrpLanguage;
	GrpLanguage = new wxStaticBoxSizer(new wxStaticBox(TabOne, wxID_ANY, wxT(" Preferred Language: ")), wxHORIZONTAL);

	GrpLanguage->SetMinSize(wxSize(-1, 90));
	LbLanguage = new wxStaticText(GrpLanguage->GetStaticBox(), wxID_ANY, wxT("Use vSongBook in"), wxDefaultPosition, wxDefaultSize, 0);
	LbLanguage->Wrap(-1);
	LbLanguage->SetFont(wxFont(12, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Trebuchet MS")));

	GrpLanguage->Add(LbLanguage, 1, wxALL, 5);

	cmbLanguage = new wxComboBox(GrpLanguage->GetStaticBox(), wxID_ANY, wxT("Portuguese"), wxDefaultPosition, wxDefaultSize, 0, NULL, wxCB_READONLY);
	cmbLanguage->Append(wxT("English"));
	cmbLanguage->Append(wxT("Swahili"));
	cmbLanguage->Append(wxT("French"));
	cmbLanguage->Append(wxT("Spanish"));
	cmbLanguage->Append(wxT("Chichewa"));
	cmbLanguage->Append(wxT("Portuguese"));
	cmbLanguage->SetSelection(5);
	GrpLanguage->Add(cmbLanguage, 0, wxALL, 5);

	WrapOne->Add(GrpLanguage, 0, wxALL | wxEXPAND, 5);

	wxStaticBoxSizer* GrpUserName;
	GrpUserName = new wxStaticBoxSizer(new wxStaticBox(TabOne, wxID_ANY, wxT("  Your Name / Name of your Church: ")), wxVERTICAL);

	GrpUserName->SetMinSize(wxSize(-1, 100));
	TxtUserName = new wxTextCtrl(GrpUserName->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
	GrpUserName->Add(TxtUserName, 1, wxALL | wxEXPAND, 5);

	LblUserName = new wxStaticText(GrpUserName->GetStaticBox(), wxID_ANY, wxT("100 characters remaining ..."), wxDefaultPosition, wxDefaultSize, 0);
	LblUserName->Wrap(-1);
	LblUserName->SetFont(wxFont(8, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Trebuchet MS")));

	GrpUserName->Add(LblUserName, 0, wxALL, 5);

	WrapOne->Add(GrpUserName, 0, wxALL | wxEXPAND, 5);

	TabOne->SetSizer(WrapOne);
	TabOne->Layout();
	WrapOne->Fit(TabOne);
	TabMain->AddPage(TabOne, wxT("General Preferences"), true);
}

void vSongPrefs::PopulateTabTwo()
{
	enum
	{
		Button_bigger,
		Button_smaller,
		Button_max
	};

	wxBitmap ButtonBitmaps[Button_max];

#if USE_XPM_BITMAPS
#define INIT_BTN_BMP(bmp) \
        ButtonBitmaps[Button_##bmp] = wxBitmap(bmp##_xpm)
#else // !USE_XPM_BITMAPS
#define INIT_BTN_BMP(bmp) \
        ButtonBitmaps[Button_##bmp] = wxBITMAP(bmp)
#endif // USE_XPM_BITMAPS/!USE_XPM_BITMAPS

	INIT_BTN_BMP(bigger);
	INIT_BTN_BMP(smaller);

	TabTwo = new wxScrolledWindow(TabMain, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHSCROLL | wxVSCROLL);
	TabTwo->SetScrollRate(5, 5);
	TabTwo->SetFont(wxFont(12, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Trebuchet MS")));
	
	TabMain->AddPage(TabTwo, wxT("Font Management"), false);
}

void vSongPrefs::PopulateTabThree()
{
	TabThree = new wxScrolledWindow(TabMain, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHSCROLL | wxVSCROLL);
	TabThree->SetScrollRate(5, 5);
	wxWrapSizer* WrapThree;
	WrapThree = new wxWrapSizer(wxHORIZONTAL, wxWRAPSIZER_DEFAULT_FLAGS);

	wxStaticBoxSizer* Theme0;
	Theme0 = new wxStaticBoxSizer(new wxStaticBox(TabThree, wxID_ANY, wxT(" Theme One ")), wxVERTICAL);

	Theme0->SetMinSize(wxSize(120, 170));
	BtnTheme0 = new wxButton(Theme0->GetStaticBox(), wxID_ANY, wxT("Black\n&&\nWhite"), wxDefaultPosition, wxDefaultSize, 0);
	BtnTheme0->SetFont(wxFont(20, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Trebuchet MS")));
	BtnTheme0->SetForegroundColour(wxColour(255, 255, 255));
	BtnTheme0->SetBackgroundColour(wxColour(0, 0, 0));
	BtnTheme0->SetMinSize(wxSize(110, 150));

	Theme0->Add(BtnTheme0, 0, wxALIGN_CENTER | wxALL | wxEXPAND, 5);

	WrapThree->Add(Theme0, 1, wxALL | wxEXPAND, 5);

	wxStaticBoxSizer* Theme1;
	Theme1 = new wxStaticBoxSizer(new wxStaticBox(TabThree, wxID_ANY, wxT(" Theme Two")), wxVERTICAL);

	Theme1->SetMinSize(wxSize(120, 170));
	BtnTheme1 = new wxButton(Theme1->GetStaticBox(), wxID_ANY, wxT("White\n&&\nBlack"), wxDefaultPosition, wxDefaultSize, 0);
	BtnTheme1->SetFont(wxFont(20, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Trebuchet MS")));
	BtnTheme1->SetForegroundColour(wxColour(0, 0, 0));
	BtnTheme1->SetBackgroundColour(wxColour(255, 255, 255));
	BtnTheme1->SetMinSize(wxSize(110, 150));

	Theme1->Add(BtnTheme1, 0, wxALIGN_CENTER | wxALL | wxEXPAND, 5);

	WrapThree->Add(Theme1, 0, wxALL | wxEXPAND, 5);

	wxStaticBoxSizer* Theme2;
	Theme2 = new wxStaticBoxSizer(new wxStaticBox(TabThree, wxID_ANY, wxT(" Theme Three")), wxVERTICAL);

	Theme2->SetMinSize(wxSize(120, 170));
	BtnTheme2 = new wxButton(Theme2->GetStaticBox(), wxID_ANY, wxT("Blue\n&&\nWhite"), wxDefaultPosition, wxDefaultSize, 0);
	BtnTheme2->SetFont(wxFont(20, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Trebuchet MS")));
	BtnTheme2->SetForegroundColour(wxColour(255, 255, 255));
	BtnTheme2->SetBackgroundColour(wxColour(0, 0, 255));
	BtnTheme2->SetMinSize(wxSize(110, 150));

	Theme2->Add(BtnTheme2, 0, wxALIGN_CENTER | wxALL | wxEXPAND, 5);

	WrapThree->Add(Theme2, 1, wxALL | wxEXPAND, 5);

	wxStaticBoxSizer* Theme3;
	Theme3 = new wxStaticBoxSizer(new wxStaticBox(TabThree, wxID_ANY, wxT(" Theme Four")), wxVERTICAL);

	Theme3->SetMinSize(wxSize(120, 170));
	BtnTheme3 = new wxButton(Theme3->GetStaticBox(), wxID_ANY, wxT("White\n&&\nBLue"), wxDefaultPosition, wxDefaultSize, 0);
	BtnTheme3->SetFont(wxFont(20, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Trebuchet MS")));
	BtnTheme3->SetForegroundColour(wxColour(0, 0, 255));
	BtnTheme3->SetBackgroundColour(wxColour(255, 255, 255));
	BtnTheme3->SetMinSize(wxSize(110, 150));

	Theme3->Add(BtnTheme3, 0, wxALIGN_CENTER | wxALL | wxEXPAND, 5);

	WrapThree->Add(Theme3, 1, wxALL | wxEXPAND, 5);

	wxStaticBoxSizer* Theme4;
	Theme4 = new wxStaticBoxSizer(new wxStaticBox(TabThree, wxID_ANY, wxT(" Theme Five ")), wxVERTICAL);

	Theme4->SetMinSize(wxSize(120, 170));
	BtnTheme4 = new wxButton(Theme4->GetStaticBox(), wxID_ANY, wxT("Green\n&&\nWhite"), wxDefaultPosition, wxDefaultSize, 0);
	BtnTheme4->SetFont(wxFont(20, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Trebuchet MS")));
	BtnTheme4->SetForegroundColour(wxColour(255, 255, 255));
	BtnTheme4->SetBackgroundColour(wxColour(0, 128, 0));
	BtnTheme4->SetMinSize(wxSize(110, 150));

	Theme4->Add(BtnTheme4, 0, wxALIGN_CENTER | wxALL | wxEXPAND, 5);

	WrapThree->Add(Theme4, 1, wxALL | wxEXPAND, 5);

	wxStaticBoxSizer* Theme5;
	Theme5 = new wxStaticBoxSizer(new wxStaticBox(TabThree, wxID_ANY, wxT(" Theme Six")), wxVERTICAL);

	Theme5->SetMinSize(wxSize(120, 170));
	BtnTheme5 = new wxButton(Theme5->GetStaticBox(), wxID_ANY, wxT("White\n&&\nGreen"), wxDefaultPosition, wxDefaultSize, 0);
	BtnTheme5->SetFont(wxFont(20, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Trebuchet MS")));
	BtnTheme5->SetForegroundColour(wxColour(0, 128, 0));
	BtnTheme5->SetBackgroundColour(wxColour(255, 255, 255));
	BtnTheme5->SetMinSize(wxSize(110, 150));

	Theme5->Add(BtnTheme5, 0, wxALIGN_CENTER | wxALL | wxEXPAND, 5);

	WrapThree->Add(Theme5, 1, wxALL | wxEXPAND, 5);

	wxStaticBoxSizer* Theme6;
	Theme6 = new wxStaticBoxSizer(new wxStaticBox(TabThree, wxID_ANY, wxT(" Theme Seven")), wxVERTICAL);

	Theme6->SetMinSize(wxSize(120, 170));
	BtnTheme6 = new wxButton(Theme6->GetStaticBox(), wxID_ANY, wxT("Orange\n&&\nWhite"), wxDefaultPosition, wxDefaultSize, 0);
	BtnTheme6->SetFont(wxFont(20, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Trebuchet MS")));
	BtnTheme6->SetForegroundColour(wxColour(255, 255, 255));
	BtnTheme6->SetBackgroundColour(wxColour(255, 69, 0));
	BtnTheme6->SetMinSize(wxSize(110, 150));

	Theme6->Add(BtnTheme6, 0, wxALIGN_CENTER | wxALL | wxEXPAND, 5);

	WrapThree->Add(Theme6, 1, wxALL | wxEXPAND, 5);

	wxStaticBoxSizer* Theme7;
	Theme7 = new wxStaticBoxSizer(new wxStaticBox(TabThree, wxID_ANY, wxT(" Theme Eight")), wxVERTICAL);

	Theme7->SetMinSize(wxSize(120, 170));
	BtnTheme7 = new wxButton(Theme7->GetStaticBox(), wxID_ANY, wxT("White\n&&\nOrange"), wxDefaultPosition, wxDefaultSize, 0);
	BtnTheme7->SetFont(wxFont(20, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Trebuchet MS")));
	BtnTheme7->SetForegroundColour(wxColour(255, 69, 0));
	BtnTheme7->SetBackgroundColour(wxColour(255, 255, 255));
	BtnTheme7->SetMinSize(wxSize(110, 150));

	Theme7->Add(BtnTheme7, 0, wxALIGN_CENTER | wxALL | wxEXPAND, 5);


	WrapThree->Add(Theme7, 1, wxALL | wxEXPAND, 5);

	wxStaticBoxSizer* Theme8;
	Theme8 = new wxStaticBoxSizer(new wxStaticBox(TabThree, wxID_ANY, wxT(" Theme Nine ")), wxVERTICAL);

	Theme8->SetMinSize(wxSize(120, 170));
	BtnTheme8 = new wxButton(Theme8->GetStaticBox(), wxID_ANY, wxT("Red\n&&\nWhite"), wxDefaultPosition, wxDefaultSize, 0);
	BtnTheme8->SetFont(wxFont(20, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Trebuchet MS")));
	BtnTheme8->SetForegroundColour(wxColour(255, 255, 255));
	BtnTheme8->SetBackgroundColour(wxColour(255, 0, 0));
	BtnTheme8->SetMinSize(wxSize(110, 150));

	Theme8->Add(BtnTheme8, 0, wxALIGN_CENTER | wxALL | wxEXPAND, 5);


	WrapThree->Add(Theme8, 1, wxALL | wxEXPAND, 5);

	wxStaticBoxSizer* Theme9;
	Theme9 = new wxStaticBoxSizer(new wxStaticBox(TabThree, wxID_ANY, wxT(" Theme Ten ")), wxVERTICAL);

	Theme9->SetMinSize(wxSize(120, 170));
	BtnTheme9 = new wxButton(Theme9->GetStaticBox(), wxID_ANY, wxT("White\n&&\nRed"), wxDefaultPosition, wxDefaultSize, 0);
	BtnTheme9->SetFont(wxFont(20, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Trebuchet MS")));
	BtnTheme9->SetForegroundColour(wxColour(255, 0, 0));
	BtnTheme9->SetBackgroundColour(wxColour(255, 255, 255));
	BtnTheme9->SetMinSize(wxSize(110, 150));

	Theme9->Add(BtnTheme9, 0, wxALIGN_CENTER | wxALL | wxEXPAND, 5);


	WrapThree->Add(Theme9, 1, wxALL | wxEXPAND, 5);

	TabThree->SetSizer(WrapThree);
	TabThree->Layout();
	WrapThree->Fit(TabThree);
	TabMain->AddPage(TabThree, wxT("Projection Theme"), false);
	TabFour = new wxScrolledWindow(TabMain, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHSCROLL | wxVSCROLL);
	TabFour->SetScrollRate(5, 5);

	TabMain->AddPage(TabThree, wxT("Presentation Preferences"), false);
}

void vSongPrefs::PopulateTabFour()
{
	TabFour = new wxScrolledWindow(TabMain, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHSCROLL | wxVSCROLL);
	TabFour->SetScrollRate(5, 5);
	TabFour->SetFont(wxFont(12, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Trebuchet MS")));

	TabMain->AddPage(TabFour, wxT("Reset Preferences"), false);
}

vSongPrefs::~vSongPrefs()
{
}
