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
enum
{
	Button_bigger,
	Button_smaller,
	Button_max
};

wxBitmap PrefsButtonsBitmaps[Button_max];

#if USE_XPM_BITMAPS
#define PREFS_BTN_BMP(bmp) \
        PrefsButtonsBitmaps[Button_##bmp] = wxBitmap(bmp##_xpm)
#else // !USE_XPM_BITMAPS
#define PREFS_BTN_BMP(bmp) \
        PrefsButtonsBitmaps[Button_##bmp] = wxBITMAP(bmp)
#endif // USE_XPM_BITMAPS/!USE_XPM_BITMAPS

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
	//TabMain->SetSelection(0);
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
	cmbLanguage->SetSelection(0);
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
	

	TabTwo = new wxScrolledWindow(TabMain, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHSCROLL | wxVSCROLL);
	TabTwo->SetScrollRate(5, 5);
	TabTwo->SetFont(wxFont(12, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Trebuchet MS")));

	wxBoxSizer* WrapTwo;
	WrapTwo = new wxBoxSizer(wxVERTICAL);

	wxStaticBoxSizer* GrpSample;
	GrpSample = new wxStaticBoxSizer(new wxStaticBox(TabTwo, wxID_ANY, wxT(" Sample Text: ")), wxVERTICAL);

	wxBoxSizer* WrapSample;
	WrapSample = new wxBoxSizer(wxHORIZONTAL);

	GrpSample->Add(WrapSample, 1, wxEXPAND, 5);

	TxtSample = new wxTextCtrl(GrpSample->GetStaticBox(), wxID_ANY, wxT("Only Believe"), wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE);
	TxtSample->SetFont(wxFont(12, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxT("Trebuchet MS")));
	GrpSample->Add(TxtSample, 1, wxEXPAND, 5);
	
	WrapTwo->Add(GrpSample, 1, wxEXPAND, 5);

	PopulateGrpTextPrefs(WrapTwo, wxT(" General App Font: "));
	PopulateGrpTextPrefs(WrapTwo, wxT(" Song Preview Font: "));
	PopulateGrpTextPrefs(WrapTwo, wxT(" Song Projection Font: "));

	TabTwo->SetSizer(WrapTwo);
	TabTwo->Layout();
	WrapTwo->Fit(TabTwo);
	TabMain->AddPage(TabTwo, wxT("Font Management"), false);
}

void vSongPrefs::PopulateGrpTextPrefs(wxBoxSizer* WrapTwo, const wxString& GrpLabel)
{
	PREFS_BTN_BMP(bigger);
	PREFS_BTN_BMP(smaller);

	wxStaticBoxSizer* GrpAppText;
	GrpAppText = new wxStaticBoxSizer(new wxStaticBox(TabTwo, wxID_ANY, GrpLabel), wxHORIZONTAL);

	LblAppFont = new wxStaticText(GrpAppText->GetStaticBox(), wxID_ANY, wxT("15"), wxDefaultPosition, wxSize(25, -1), 0);
	LblAppFont->Wrap(-1);
	LblAppFont->SetFont(wxFont(12, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Trebuchet MS")));

	GrpAppText->Add(LblAppFont, 0, wxALIGN_CENTER | wxALL, 5);

	BtnAppFontSmaller = new wxBitmapButton(GrpAppText->GetStaticBox(), wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW | 0);

	BtnAppFontSmaller->SetBitmap(wxBitmap(PrefsButtonsBitmaps[Button_smaller]));
	GrpAppText->Add(BtnAppFontSmaller, 0, wxALL, 5);

	SldAppFont = new wxSlider(GrpAppText->GetStaticBox(), wxID_ANY, 15, 12, 50, wxDefaultPosition, wxDefaultSize, wxSL_BOTH | wxSL_HORIZONTAL);
	GrpAppText->Add(SldAppFont, 1, wxALIGN_CENTER | wxALL, 5);

	BtnAppFontBigger = new wxBitmapButton(GrpAppText->GetStaticBox(), wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW | 0);

	BtnAppFontBigger->SetBitmap(wxBitmap(PrefsButtonsBitmaps[Button_bigger]));
	GrpAppText->Add(BtnAppFontBigger, 0, wxALL, 5);

	cmbAppFont = new wxComboBox(GrpAppText->GetStaticBox(), wxID_ANY, wxT("Font Type"), wxDefaultPosition, wxDefaultSize, 0, NULL, 0);
	cmbAppFont->Append(wxT("Arial"));
	cmbAppFont->Append(wxT("Calibri"));
	cmbAppFont->Append(wxT("Century Gothic"));
	cmbAppFont->Append(wxT("Comic Sans MS"));
	cmbAppFont->Append(wxT("Corbel"));
	cmbAppFont->Append(wxT("Courier New"));
	cmbAppFont->Append(wxT("Palatino Linotype"));
	cmbAppFont->Append(wxT("Tahoma"));
	cmbAppFont->Append(wxT("Tempus Sans ITC"));
	cmbAppFont->Append(wxT("Times New Roman"));
	cmbAppFont->Append(wxT("Trebuchet MS"));
	cmbAppFont->Append(wxT("Verdana"));
	cmbAppFont->SetSelection(10);
	GrpAppText->Add(cmbAppFont, 0, wxALIGN_CENTER | wxALL, 5);

	BtnAppFont = new wxRadioButton(GrpAppText->GetStaticBox(), wxID_ANY, wxT("BOLD"), wxDefaultPosition, wxDefaultSize, 0);
	BtnAppFont->SetFont(wxFont(12, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxT("Trebuchet MS")));

	GrpAppText->Add(BtnAppFont, 0, wxALIGN_CENTER | wxALL, 5);

	WrapTwo->Add(GrpAppText, 0, wxALL | wxEXPAND, 5);
}

void vSongPrefs::PopulateTabThree()
{
	TabThree = new wxScrolledWindow(TabMain, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHSCROLL | wxVSCROLL);
	TabThree->SetScrollRate(5, 5);
	wxWrapSizer* WrapThree;
	WrapThree = new wxWrapSizer(wxHORIZONTAL, wxWRAPSIZER_DEFAULT_FLAGS);
	vector<int> whitecolor, blackcolor, bluecolor, greencolor, orangecolor, redcolor;

	whitecolor.push_back(255);
	whitecolor.push_back(255);
	whitecolor.push_back(255);

	blackcolor.push_back(0);
	blackcolor.push_back(0);
	blackcolor.push_back(0);

	bluecolor.push_back(0);
	bluecolor.push_back(0);
	bluecolor.push_back(255);

	greencolor.push_back(0);
	greencolor.push_back(128);
	greencolor.push_back(0);

	orangecolor.push_back(255);
	orangecolor.push_back(69);
	orangecolor.push_back(0);

	redcolor.push_back(255);
	redcolor.push_back(0);
	redcolor.push_back(0);

	PopulateGrpThemePrefs(WrapThree, 1, wxT(" Theme 1 "), wxT("Black\n&&\nWhite"), blackcolor, whitecolor);
	PopulateGrpThemePrefs(WrapThree, 2, wxT(" Theme 2 "), wxT("White\n&&\nBlack"), whitecolor, blackcolor);
	PopulateGrpThemePrefs(WrapThree, 3, wxT(" Theme 3 "), wxT("Blue\n&&\nWhite"), bluecolor, whitecolor);
	PopulateGrpThemePrefs(WrapThree, 4, wxT(" Theme 4 "), wxT("White\n&&\nBlue"), whitecolor, bluecolor);
	PopulateGrpThemePrefs(WrapThree, 5, wxT(" Theme 5 "), wxT("Green\n&&\nWhite"), greencolor, whitecolor);
	PopulateGrpThemePrefs(WrapThree, 6, wxT(" Theme 6 "), wxT("White\n&&\nGreen"), whitecolor, greencolor);
	PopulateGrpThemePrefs(WrapThree, 7, wxT(" Theme 7 "), wxT("Orange\n&&\nWhite"), orangecolor, whitecolor);
	PopulateGrpThemePrefs(WrapThree, 8, wxT(" Theme 8 "), wxT("White\n&&\nOrange"), whitecolor, orangecolor);
	PopulateGrpThemePrefs(WrapThree, 9, wxT(" Theme 9 "), wxT("Red\n&&\nWhite"), redcolor, whitecolor);
	PopulateGrpThemePrefs(WrapThree, 10, wxT(" Theme 10 "), wxT("White\n&&\nRed"), whitecolor, redcolor);
	//PopulateGrpThemePrefs(WrapThree, 11, wxT(" Theme 11 "), wxT("Custom\n&&\nTheme 1"), whitecolor, blackcolor);
	//PopulateGrpThemePrefs(WrapThree, 12, wxT(" Theme 12 "), wxT("Custom\n&&\nTheme 2"), whitecolor, blackcolor);

	TabThree->SetSizer(WrapThree);
	TabThree->Layout();
	WrapThree->Fit(TabThree);

	TabMain->AddPage(TabThree, wxT("Presentation Preferences"), false);
}

void vSongPrefs::PopulateGrpThemePrefs(wxWrapSizer* WrapThree, int ThemeID, const wxString& GrpLabel, const wxString& GrpColor, vector<int> forecolor, vector<int> backcolor)
{
	wxStaticBoxSizer* GrpTheme;
	GrpTheme = new wxStaticBoxSizer(new wxStaticBox(TabThree, wxID_ANY, GrpLabel), wxVERTICAL);

	GrpTheme->SetMinSize(wxSize(120, 170));
	BtnTheme = new wxButton(GrpTheme->GetStaticBox(), wxID_ANY, GrpColor, wxDefaultPosition, wxSize(110, 150), 0);
	BtnTheme->SetFont(wxFont(20, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Trebuchet MS")));
	BtnTheme->SetForegroundColour(wxColour(forecolor[0], forecolor[1], forecolor[2]));
	BtnTheme->SetBackgroundColour(wxColour(backcolor[0], backcolor[1], backcolor[2]));
	GrpTheme->Add(BtnTheme, 0, wxALL, 5);

	WrapThree->Add(GrpTheme, 1, wxALL | wxEXPAND, 5);
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
