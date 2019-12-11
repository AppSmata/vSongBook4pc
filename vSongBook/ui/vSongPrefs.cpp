/////////////////////////////////////////////////////////////////////////////
// Name:        vSongPrefs.cpp
// Purpose:     vSongBook for Desktop
// Author:      Jacksiro
// Modified by:
// Created:     27/07/19
// Copyright:   (c) AppSmata
// Licence:     wxWindows licence
/////////////////////////////////////////////////////////////////////////////

#include "AppSmata.h"
#include "vSongPrefs.h"
enum
{
	Button_bigger,
	Button_smaller,
	Button_max
};

wxBitmap PrefsButtonsBitmaps[Button_max];
vector<wxString> prefset, preflang, lang_list, font_general, font_preview, font_projection;
int general_fonts, preview_fonts, projection_fonts, preffontapp, pcrts;
wxString general_fonty, preview_fonty, projection_fonty;

#if USE_XPM_BITMAPS
#define PREFS_BTN_BMP(bmp) \
        PrefsButtonsBitmaps[Button_##bmp] = wxBitmap(bmp##_xpm)
#else // !USE_XPM_BITMAPS
#define PREFS_BTN_BMP(bmp) \
        PrefsButtonsBitmaps[Button_##bmp] = wxBITMAP(bmp)
#endif // USE_XPM_BITMAPS/!USE_XPM_BITMAPS

vSongPrefs::vSongPrefs(const wxString& title) : wxFrame(NULL, wxID_ANY, title)
{
	GetSettings();
	GetLanguages(prefset[3]);

	this->SetSizeHints(wxDefaultSize, wxDefaultSize);
	this->SetFont(wxFont(12, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, general_fonty));
	this->SetBackgroundColour(wxColour(255, 255, 255));
	this->SetLabel(preflang[65]);
	
	wxBoxSizer* MainWrapper;
	MainWrapper = new wxBoxSizer(wxVERTICAL);

	TabMain = new wxNotebook(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0);
	TabMain->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOW));

	MainWrapper->Add(TabMain, 1, wxEXPAND | wxALL, 5);

	PopulateTabOne();
	PopulateTabTwo();
	PopulateTabThree();
	PopulateTabFour();
	TabMain->SetSelection(1);
	this->SetSizer(MainWrapper);
	this->Layout();

	this->Centre(wxBOTH);

	InitializeLanguage();
	InitializeSettings();

	// Connect Events
	BtnSearchCriteria->Connect(wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler(vSongPrefs::BtnSearchCriteria_Click), NULL, this);
	BtnTabletMode->Connect(wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler(vSongPrefs::BtnTabletMode_Click), NULL, this);
	CmbLanguage->Connect(wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler(vSongPrefs::CmbLanguage_SelectionChange), NULL, this);
	TxtUserName->Connect(wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler(vSongPrefs::TxtUserName_TextChange), NULL, this);

	CmbGeneral->Connect(wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler(vSongPrefs::CmbGeneral_SelectionChange), NULL, this);
	SldGeneral->Connect(wxEVT_SCROLL_TOP, wxScrollEventHandler(vSongPrefs::SldGeneral_OnScroll), NULL, this);
	SldGeneral->Connect(wxEVT_SCROLL_BOTTOM, wxScrollEventHandler(vSongPrefs::SldGeneral_OnScroll), NULL, this);
	SldGeneral->Connect(wxEVT_SCROLL_LINEUP, wxScrollEventHandler(vSongPrefs::SldGeneral_OnScroll), NULL, this);
	SldGeneral->Connect(wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler(vSongPrefs::SldGeneral_OnScroll), NULL, this);
	SldGeneral->Connect(wxEVT_SCROLL_PAGEUP, wxScrollEventHandler(vSongPrefs::SldGeneral_OnScroll), NULL, this);
	SldGeneral->Connect(wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler(vSongPrefs::SldGeneral_OnScroll), NULL, this);
	SldGeneral->Connect(wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler(vSongPrefs::SldGeneral_OnScroll), NULL, this);
	SldGeneral->Connect(wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler(vSongPrefs::SldGeneral_OnScroll), NULL, this);
	SldGeneral->Connect(wxEVT_SCROLL_CHANGED, wxScrollEventHandler(vSongPrefs::SldGeneral_OnScroll), NULL, this);

	CmbPreview->Connect(wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler(vSongPrefs::CmbPreview_SelectionChange), NULL, this);
	SldPreview->Connect(wxEVT_SCROLL_TOP, wxScrollEventHandler(vSongPrefs::SldPreview_OnScroll), NULL, this);
	SldPreview->Connect(wxEVT_SCROLL_BOTTOM, wxScrollEventHandler(vSongPrefs::SldPreview_OnScroll), NULL, this);
	SldPreview->Connect(wxEVT_SCROLL_LINEUP, wxScrollEventHandler(vSongPrefs::SldPreview_OnScroll), NULL, this);
	SldPreview->Connect(wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler(vSongPrefs::SldPreview_OnScroll), NULL, this);
	SldPreview->Connect(wxEVT_SCROLL_PAGEUP, wxScrollEventHandler(vSongPrefs::SldPreview_OnScroll), NULL, this);
	SldPreview->Connect(wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler(vSongPrefs::SldPreview_OnScroll), NULL, this);
	SldPreview->Connect(wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler(vSongPrefs::SldPreview_OnScroll), NULL, this);
	SldPreview->Connect(wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler(vSongPrefs::SldPreview_OnScroll), NULL, this);
	SldPreview->Connect(wxEVT_SCROLL_CHANGED, wxScrollEventHandler(vSongPrefs::SldPreview_OnScroll), NULL, this);

	CmbProjection->Connect(wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler(vSongPrefs::CmbProjection_SelectionChange), NULL, this);
	SldProjection->Connect(wxEVT_SCROLL_TOP, wxScrollEventHandler(vSongPrefs::SldProjection_OnScroll), NULL, this);
	SldProjection->Connect(wxEVT_SCROLL_BOTTOM, wxScrollEventHandler(vSongPrefs::SldProjection_OnScroll), NULL, this);
	SldProjection->Connect(wxEVT_SCROLL_LINEUP, wxScrollEventHandler(vSongPrefs::SldProjection_OnScroll), NULL, this);
	SldProjection->Connect(wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler(vSongPrefs::SldProjection_OnScroll), NULL, this);
	SldProjection->Connect(wxEVT_SCROLL_PAGEUP, wxScrollEventHandler(vSongPrefs::SldProjection_OnScroll), NULL, this);
	SldProjection->Connect(wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler(vSongPrefs::SldProjection_OnScroll), NULL, this);
	SldProjection->Connect(wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler(vSongPrefs::SldProjection_OnScroll), NULL, this);
	SldProjection->Connect(wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler(vSongPrefs::SldProjection_OnScroll), NULL, this);
	SldProjection->Connect(wxEVT_SCROLL_CHANGED, wxScrollEventHandler(vSongPrefs::SldProjection_OnScroll), NULL, this);
}

void vSongPrefs::GetSettings()
{
	try {
		if (prefset.size() > 0) prefset.clear();

		sqlite3* db;
		char* err_msg = NULL, ** qryResult = NULL;
		int row, col, rc = sqlite3_open_v2("Data\\Settings.db", &db, SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE, NULL);

		wxString sqlQuery = _T("SELECT content FROM settings ORDER BY settingid");

		rc = sqlite3_get_table(db, sqlQuery, &qryResult, &row, &col, &err_msg);

		for (int i = 1; i < row + 1; i++)
		{
			prefset.push_back(*(qryResult + i * col + 0));
		}

		sqlite3_free_table(qryResult);
		sqlite3_close(db);
	}
	catch (exception & ex) {}
}

void vSongPrefs::GetLanguages(wxString Language)
{
	try {
		if (preflang.size() > 0) preflang.clear();

		sqlite3* db;
		char* err_msg = NULL, ** qryResult = NULL;
		int row, col, rc = sqlite3_open_v2("Data\\Language.db", &db, SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE, NULL);

		wxString sqlQuery = _T("SELECT content FROM " + Language + " ORDER BY stringid");

		rc = sqlite3_get_table(db, sqlQuery, &qryResult, &row, &col, &err_msg);

		for (int i = 1; i < row + 1; i++)
		{
			preflang.push_back(*(qryResult + i * col + 0));
		}

		sqlite3_free_table(qryResult);
		sqlite3_close(db);
	}
	catch (exception & ex) {}
}

void vSongPrefs::InitializeLanguage()
{
	LblTabletGrp->SetLabel(preflang[72]);
	LblTabletMode->SetLabel(preflang[73]);
	LblSearchGrp->SetLabel(preflang[61]);
	LblSearchCriteria->SetLabel(preflang[60]);
	LbLanguageGrp->SetLabel(preflang[51]);
	LbLanguage->SetLabel(preflang[52]);
	LblUserNameGrp->SetLabel(preflang[106]);

	pcrts = (100 - TxtUserName->GetValue().Length());
	LblUserName->SetLabel(wxString::Format(wxT("%i"), pcrts) + " " + preflang[7]);

	BtnTabletMode->SetLabel(preflang[107]);
	BtnSearchCriteria->SetLabel(preflang[107]);
	TxtUserName->SetValue(prefset[1]);
	
	LblSampleGrp->SetLabel(preflang[55]);
	LblGeneralGrp->SetLabel(preflang[20]);
	LblPreviewGrp->SetLabel(preflang[22]);
	LblProjectionGrp->SetLabel(preflang[23]);

	this->SetLabel(preflang[65]);
}

void vSongPrefs::InitializeSettings()
{
	general_fonts = wxAtoi(prefset[5]);
	preview_fonts = wxAtoi(prefset[11]);
	projection_fonts = wxAtoi(prefset[14]);
	preffontapp = AppSmata::PresenterFont(general_fonts);

	general_fonty = prefset[6];
	preview_fonty = prefset[12];
	projection_fonty = prefset[15];

	LblTabletMode->SetFont(wxFont(preffontapp, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, general_fonty));
	BtnTabletMode->SetFont(wxFont(general_fonts, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, general_fonty));
	LblSearchCriteria->SetFont(wxFont(general_fonts, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, general_fonty));
	BtnSearchCriteria->SetFont(wxFont(general_fonts, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, general_fonty));
	LbLanguage->SetFont(wxFont(general_fonts, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, general_fonty));
	CmbLanguage->SetFont(wxFont(general_fonts, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, general_fonty));
	TxtUserName->SetFont(wxFont(general_fonts, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, general_fonty));
	LblUserName->SetFont(wxFont(preffontapp, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, general_fonty));
	
	LblGeneral->SetFont(wxFont(general_fonts, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, general_fonty));
	BtnGeneral->SetFont(wxFont(general_fonts, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, general_fonty));
	CmbGeneral->SetFont(wxFont(general_fonts, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, general_fonty));
	TxtSample->SetFont(wxFont(general_fonts, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, general_fonty));
	LblGeneral->SetLabel(prefset[5]);

	LblPreview->SetFont(wxFont(general_fonts, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, general_fonty));
	BtnPreview->SetFont(wxFont(general_fonts, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, general_fonty));
	CmbPreview->SetFont(wxFont(general_fonts, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, general_fonty));
	LblPreview->SetLabel(prefset[11]);

	LblProjection->SetFont(wxFont(general_fonts, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, general_fonty));
	BtnProjection->SetFont(wxFont(general_fonts, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, general_fonty));
	CmbProjection->SetFont(wxFont(general_fonts, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, general_fonty));
	LblProjection->SetLabel(prefset[14]);
}

void vSongPrefs::PopulateTabOne()
{
	SetIcon(wxICON(appicon));

	TabOne = new wxScrolledWindow(TabMain, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHSCROLL | wxVSCROLL);
	TabOne->SetScrollRate(5, 5);
	TabOne->SetMinSize(wxSize(-1, 75));

	wxBoxSizer* WrapOne;
	WrapOne = new wxBoxSizer(wxVERTICAL);

	WrapOne->SetMinSize(wxSize(-1, 800));
	wxStaticBoxSizer* GrpTabletMode;
	LblTabletGrp = new wxStaticBox(TabOne, wxID_ANY, wxEmptyString);
	GrpTabletMode = new wxStaticBoxSizer(LblTabletGrp, wxHORIZONTAL);

	GrpTabletMode->SetMinSize(wxSize(-1, 75));
	LblTabletMode = new wxStaticText(GrpTabletMode->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
	LblTabletMode->Wrap(-1);

	GrpTabletMode->Add(LblTabletMode, 1, wxALL, 5);

	BtnTabletMode = new wxRadioButton(GrpTabletMode->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(100, -1), 0);

	GrpTabletMode->Add(BtnTabletMode, 0, wxALL, 5);

	WrapOne->Add(GrpTabletMode, 0, wxALL | wxEXPAND, 5);

	wxStaticBoxSizer* GrpSearchCriteria;
	LblSearchGrp = new wxStaticBox(TabOne, wxID_ANY, wxEmptyString);
	GrpSearchCriteria = new wxStaticBoxSizer(LblSearchGrp, wxHORIZONTAL);

	GrpSearchCriteria->SetMinSize(wxSize(-1, 75));
	LblSearchCriteria = new wxStaticText(GrpSearchCriteria->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
	LblSearchCriteria->Wrap(-1);

	GrpSearchCriteria->Add(LblSearchCriteria, 1, wxALL, 5);

	BtnSearchCriteria = new wxRadioButton(GrpSearchCriteria->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(100, -1), 0);
	BtnSearchCriteria->SetValue(true);

	GrpSearchCriteria->Add(BtnSearchCriteria, 0, wxALL, 5);

	WrapOne->Add(GrpSearchCriteria, 0, wxALL | wxEXPAND, 5);

	wxStaticBoxSizer* GrpLanguage;
	LbLanguageGrp = new wxStaticBox(TabOne, wxID_ANY, wxEmptyString);
	GrpLanguage = new wxStaticBoxSizer(LbLanguageGrp, wxHORIZONTAL);

	GrpLanguage->SetMinSize(wxSize(-1, 90));
	LbLanguage = new wxStaticText(GrpLanguage->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
	LbLanguage->Wrap(-1);

	GrpLanguage->Add(LbLanguage, 1, wxALL, 5);

	CmbLanguage = new wxComboBox(GrpLanguage->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(200, -1), 0, NULL, wxCB_READONLY);
	CmbLanguage->Append(wxT("English"));
	lang_list.push_back("English");
	CmbLanguage->Append(wxT("Swahili"));
	lang_list.push_back("Swahili");
	CmbLanguage->Append(wxT("French"));
	lang_list.push_back("French");
	CmbLanguage->Append(wxT("Spanish"));
	lang_list.push_back("Spanish");
	CmbLanguage->Append(wxT("Chichewa"));
	lang_list.push_back("Chichewa");
	CmbLanguage->Append(wxT("Portuguese"));
	lang_list.push_back("Portuguese");
	CmbLanguage->SetSelection(AppSmata::SelectedValue(prefset[3], lang_list));
	GrpLanguage->Add(CmbLanguage, 0, wxALL, 5);

	WrapOne->Add(GrpLanguage, 0, wxALL | wxEXPAND, 5);

	wxStaticBoxSizer* GrpUserName;
	LblUserNameGrp = new wxStaticBox(TabOne, wxID_ANY, wxEmptyString);
	GrpUserName = new wxStaticBoxSizer(LblUserNameGrp, wxVERTICAL);

	GrpUserName->SetMinSize(wxSize(-1, 100));
	TxtUserName = new wxTextCtrl(GrpUserName->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(-1, 50), 0);
	TxtUserName->SetMaxLength(100);
	GrpUserName->Add(TxtUserName, 1, wxALL | wxEXPAND, 5);

	LblUserName = new wxStaticText(GrpUserName->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
	LblUserName->Wrap(-1);

	GrpUserName->Add(LblUserName, 0, wxALL, 5);

	WrapOne->Add(GrpUserName, 0, wxALL | wxEXPAND, 5);

	TabOne->SetSizer(WrapOne);
	TabOne->Layout();
	WrapOne->Fit(TabOne);
	TabMain->AddPage(TabOne, preflang[24], true);
}

void vSongPrefs::PopulateTabTwo()
{
	TabTwo = new wxScrolledWindow(TabMain, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHSCROLL | wxVSCROLL);
	TabTwo->SetScrollRate(5, 5);
	TabTwo->SetFont(wxFont(12, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, general_fonty));

	wxBoxSizer* WrapTwo;
	WrapTwo = new wxBoxSizer(wxVERTICAL);

	wxStaticBoxSizer* GrpSample;
	LblSampleGrp = new wxStaticBox(TabTwo, wxID_ANY, wxEmptyString);
	GrpSample = new wxStaticBoxSizer(LblSampleGrp, wxVERTICAL);

	wxBoxSizer* WrapSample;
	WrapSample = new wxBoxSizer(wxHORIZONTAL);

	GrpSample->Add(WrapSample, 1, wxEXPAND, 5);

	TxtSample = new wxTextCtrl(GrpSample->GetStaticBox(), wxID_ANY, wxT("Only Believe"), wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE);
	TxtSample->SetFont(wxFont(12, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, general_fonty));
	GrpSample->Add(TxtSample, 1, wxEXPAND, 5);
	
	WrapTwo->Add(GrpSample, 1, wxEXPAND, 5);

	PopulateGrpGeneral(WrapTwo);
	PopulateGrpPreview(WrapTwo);
	PopulateGrpProjection(WrapTwo);

	wxStaticBoxSizer* GrpAppBottom;
	GrpAppBottom = new wxStaticBoxSizer(new wxStaticBox(TabTwo, wxID_ANY, wxEmptyString), wxHORIZONTAL);
	WrapTwo->Add(GrpAppBottom, 0, wxALL | wxEXPAND, 5);

	TabTwo->SetSizer(WrapTwo);
	TabTwo->Layout();
	WrapTwo->Fit(TabTwo);
	TabMain->AddPage(TabTwo, preflang[21], false);
}

void vSongPrefs::PopulateGrpGeneral(wxBoxSizer* WrapTwo)
{
	PREFS_BTN_BMP(bigger);
	PREFS_BTN_BMP(smaller);

	wxStaticBoxSizer* GrpAppText;
	LblGeneralGrp = new wxStaticBox(TabTwo, wxID_ANY, wxEmptyString);
	GrpAppText = new wxStaticBoxSizer(LblGeneralGrp, wxHORIZONTAL);

	LblGeneral = new wxStaticText(GrpAppText->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(35, -1), 0);
	LblGeneral->Wrap(-1);

	GrpAppText->Add(LblGeneral, 0, wxALIGN_CENTER | wxALL, 5);

	BtnGeneralSmaller = new wxBitmapButton(GrpAppText->GetStaticBox(), wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW | 0);

	BtnGeneralSmaller->SetBitmap(wxBitmap(PrefsButtonsBitmaps[Button_smaller]));
	GrpAppText->Add(BtnGeneralSmaller, 0, wxALL, 5);

	SldGeneral = new wxSlider(GrpAppText->GetStaticBox(), wxID_ANY, 15, 12, 50, wxDefaultPosition, wxDefaultSize, wxSL_BOTH | wxSL_HORIZONTAL);
	GrpAppText->Add(SldGeneral, 1, wxALIGN_CENTER | wxALL, 5);

	BtnGeneralBigger = new wxBitmapButton(GrpAppText->GetStaticBox(), wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW | 0);

	BtnGeneralBigger->SetBitmap(wxBitmap(PrefsButtonsBitmaps[Button_bigger]));
	GrpAppText->Add(BtnGeneralBigger, 0, wxALL, 5);

	CmbGeneral = new wxComboBox(GrpAppText->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, NULL, wxCB_READONLY);
	CmbGeneral->Append(wxT("Arial"));
	font_general.push_back("Arial");
	CmbGeneral->Append(wxT("Calibri"));
	font_general.push_back("Calibri");
	CmbGeneral->Append(wxT("Century Gothic"));
	font_general.push_back("Century Gothic");
	CmbGeneral->Append(wxT("Comic Sans MS"));
	font_general.push_back("Comic Sans MS");
	CmbGeneral->Append(wxT("Corbel"));
	font_general.push_back("Corbel");
	CmbGeneral->Append(wxT("Courier New"));
	font_general.push_back("Courier New");
	CmbGeneral->Append(wxT("Palatino Linotype"));
	font_general.push_back("Palatino Linotype");
	CmbGeneral->Append(wxT("Tahoma"));
	font_general.push_back("Tahoma");
	CmbGeneral->Append(wxT("Tempus Sans ITC"));
	font_general.push_back("Tempus Sans ITC");
	CmbGeneral->Append(wxT("Times New Roman"));
	font_general.push_back("Times New Roman");
	CmbGeneral->Append("Trebuchet MS");
	font_general.push_back("Trebuchet MS");
	CmbGeneral->Append(wxT("Verdana"));
	font_general.push_back("Verdana");
	CmbGeneral->SetSelection(AppSmata::SelectedValue(prefset[6], font_general));
	GrpAppText->Add(CmbGeneral, 0, wxALIGN_CENTER | wxALL, 5);

	BtnGeneral = new wxRadioButton(GrpAppText->GetStaticBox(), wxID_ANY, wxT("BOLD"), wxDefaultPosition, wxDefaultSize, 0);

	GrpAppText->Add(BtnGeneral, 0, wxALIGN_CENTER | wxALL, 5);

	WrapTwo->Add(GrpAppText, 0, wxALL | wxEXPAND, 5);
}

void vSongPrefs::PopulateGrpPreview(wxBoxSizer* WrapTwo)
{
	PREFS_BTN_BMP(bigger);
	PREFS_BTN_BMP(smaller);

	wxStaticBoxSizer* GrpAppText;
	LblPreviewGrp = new wxStaticBox(TabTwo, wxID_ANY, wxEmptyString);
	GrpAppText = new wxStaticBoxSizer(LblPreviewGrp, wxHORIZONTAL);

	LblPreview = new wxStaticText(GrpAppText->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(35, -1), 0);
	LblPreview->Wrap(-1);

	GrpAppText->Add(LblPreview, 0, wxALIGN_CENTER | wxALL, 5);

	BtnPreviewSmaller = new wxBitmapButton(GrpAppText->GetStaticBox(), wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW | 0);

	BtnPreviewSmaller->SetBitmap(wxBitmap(PrefsButtonsBitmaps[Button_smaller]));
	GrpAppText->Add(BtnPreviewSmaller, 0, wxALL, 5);

	SldPreview = new wxSlider(GrpAppText->GetStaticBox(), wxID_ANY, 15, 12, 50, wxDefaultPosition, wxDefaultSize, wxSL_BOTH | wxSL_HORIZONTAL);
	GrpAppText->Add(SldPreview, 1, wxALIGN_CENTER | wxALL, 5);

	BtnPreviewBigger = new wxBitmapButton(GrpAppText->GetStaticBox(), wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW | 0);

	BtnPreviewBigger->SetBitmap(wxBitmap(PrefsButtonsBitmaps[Button_bigger]));
	GrpAppText->Add(BtnPreviewBigger, 0, wxALL, 5);

	CmbPreview = new wxComboBox(GrpAppText->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, NULL, wxCB_READONLY);
	CmbPreview->Append(wxT("Arial"));
	font_preview.push_back("Arial");
	CmbPreview->Append(wxT("Calibri"));
	font_preview.push_back("Calibri");
	CmbPreview->Append(wxT("Century Gothic"));
	font_preview.push_back("Century Gothic");
	CmbPreview->Append(wxT("Comic Sans MS"));
	font_preview.push_back("Comic Sans MS");
	CmbPreview->Append(wxT("Corbel"));
	font_preview.push_back("Corbel");
	CmbPreview->Append(wxT("Courier New"));
	font_preview.push_back("Courier New");
	CmbPreview->Append(wxT("Palatino Linotype"));
	font_preview.push_back("Palatino Linotype");
	CmbPreview->Append(wxT("Tahoma"));
	font_preview.push_back("Tahoma");
	CmbPreview->Append(wxT("Tempus Sans ITC"));
	font_preview.push_back("Tempus Sans ITC");
	CmbPreview->Append(wxT("Times New Roman"));
	font_preview.push_back("Times New Roman");
	CmbPreview->Append("Trebuchet MS");
	font_preview.push_back("Trebuchet MS");
	CmbPreview->Append(wxT("Verdana"));
	font_preview.push_back("Verdana");
	CmbPreview->SetSelection(AppSmata::SelectedValue(prefset[6], font_preview));
	GrpAppText->Add(CmbPreview, 0, wxALIGN_CENTER | wxALL, 5);

	BtnPreview = new wxRadioButton(GrpAppText->GetStaticBox(), wxID_ANY, wxT("BOLD"), wxDefaultPosition, wxDefaultSize, 0);

	GrpAppText->Add(BtnPreview, 0, wxALIGN_CENTER | wxALL, 5);

	WrapTwo->Add(GrpAppText, 0, wxALL | wxEXPAND, 5);
}

void vSongPrefs::PopulateGrpProjection(wxBoxSizer* WrapTwo)
{
	PREFS_BTN_BMP(bigger);
	PREFS_BTN_BMP(smaller);

	wxStaticBoxSizer* GrpAppText;
	LblProjectionGrp = new wxStaticBox(TabTwo, wxID_ANY, wxEmptyString);
	GrpAppText = new wxStaticBoxSizer(LblProjectionGrp, wxHORIZONTAL);

	LblProjection = new wxStaticText(GrpAppText->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(35, -1), 0);
	LblProjection->Wrap(-1);

	GrpAppText->Add(LblProjection, 0, wxALIGN_CENTER | wxALL, 5);

	BtnProjectionSmaller = new wxBitmapButton(GrpAppText->GetStaticBox(), wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW | 0);

	BtnProjectionSmaller->SetBitmap(wxBitmap(PrefsButtonsBitmaps[Button_smaller]));
	GrpAppText->Add(BtnProjectionSmaller, 0, wxALL, 5);

	SldProjection = new wxSlider(GrpAppText->GetStaticBox(), wxID_ANY, 15, 12, 50, wxDefaultPosition, wxDefaultSize, wxSL_BOTH | wxSL_HORIZONTAL);
	GrpAppText->Add(SldProjection, 1, wxALIGN_CENTER | wxALL, 5);

	BtnProjectionBigger = new wxBitmapButton(GrpAppText->GetStaticBox(), wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW | 0);

	BtnProjectionBigger->SetBitmap(wxBitmap(PrefsButtonsBitmaps[Button_bigger]));
	GrpAppText->Add(BtnProjectionBigger, 0, wxALL, 5);

	CmbProjection = new wxComboBox(GrpAppText->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, NULL, wxCB_READONLY);
	CmbProjection->Append(wxT("Arial"));
	font_projection.push_back("Arial");
	CmbProjection->Append(wxT("Calibri"));
	font_projection.push_back("Calibri");
	CmbProjection->Append(wxT("Century Gothic"));
	font_projection.push_back("Century Gothic");
	CmbProjection->Append(wxT("Comic Sans MS"));
	font_projection.push_back("Comic Sans MS");
	CmbProjection->Append(wxT("Corbel"));
	font_projection.push_back("Corbel");
	CmbProjection->Append(wxT("Courier New"));
	font_projection.push_back("Courier New");
	CmbProjection->Append(wxT("Palatino Linotype"));
	font_projection.push_back("Palatino Linotype");
	CmbProjection->Append(wxT("Tahoma"));
	font_projection.push_back("Tahoma");
	CmbProjection->Append(wxT("Tempus Sans ITC"));
	font_projection.push_back("Tempus Sans ITC");
	CmbProjection->Append(wxT("Times New Roman"));
	font_projection.push_back("Times New Roman");
	CmbProjection->Append("Trebuchet MS");
	font_projection.push_back("Trebuchet MS");
	CmbProjection->Append(wxT("Verdana"));
	font_projection.push_back("Verdana");
	CmbProjection->SetSelection(AppSmata::SelectedValue(prefset[6], font_projection));
	GrpAppText->Add(CmbProjection, 0, wxALIGN_CENTER | wxALL, 5);

	BtnProjection = new wxRadioButton(GrpAppText->GetStaticBox(), wxID_ANY, wxT("BOLD"), wxDefaultPosition, wxDefaultSize, 0);

	GrpAppText->Add(BtnProjection, 0, wxALIGN_CENTER | wxALL, 5);

	WrapTwo->Add(GrpAppText, 0, wxALL | wxEXPAND, 5);
}

void vSongPrefs::PopulateGrpTextPrefs(wxBoxSizer* WrapTwo, const wxString& GrpLabel)
{
	PREFS_BTN_BMP(bigger);
	PREFS_BTN_BMP(smaller);

	wxStaticBoxSizer* GrpAppText;
	wxStaticBox* LblAppTextGrp = new wxStaticBox(TabTwo, wxID_ANY, wxEmptyString);
	GrpAppText = new wxStaticBoxSizer(LblAppTextGrp, wxHORIZONTAL);

	LblGeneral = new wxStaticText(GrpAppText->GetStaticBox(), wxID_ANY, wxT("15"), wxDefaultPosition, wxSize(25, -1), 0);
	LblGeneral->Wrap(-1);
	LblGeneral->SetFont(wxFont(12, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, general_fonty));

	GrpAppText->Add(LblGeneral, 0, wxALIGN_CENTER | wxALL, 5);

	BtnGeneralSmaller = new wxBitmapButton(GrpAppText->GetStaticBox(), wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW | 0);

	BtnGeneralSmaller->SetBitmap(wxBitmap(PrefsButtonsBitmaps[Button_smaller]));
	GrpAppText->Add(BtnGeneralSmaller, 0, wxALL, 5);

	SldGeneral = new wxSlider(GrpAppText->GetStaticBox(), wxID_ANY, 15, 12, 50, wxDefaultPosition, wxDefaultSize, wxSL_BOTH | wxSL_HORIZONTAL);
	GrpAppText->Add(SldGeneral, 1, wxALIGN_CENTER | wxALL, 5);

	BtnGeneralBigger = new wxBitmapButton(GrpAppText->GetStaticBox(), wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW | 0);

	BtnGeneralBigger->SetBitmap(wxBitmap(PrefsButtonsBitmaps[Button_bigger]));
	GrpAppText->Add(BtnGeneralBigger, 0, wxALL, 5);

	CmbGeneral = new wxComboBox(GrpAppText->GetStaticBox(), wxID_ANY, wxT("Font Type"), wxDefaultPosition, wxDefaultSize, 0, NULL, 0);
	CmbGeneral->Append(wxT("Arial"));
	CmbGeneral->Append(wxT("Calibri"));
	CmbGeneral->Append(wxT("Century Gothic"));
	CmbGeneral->Append(wxT("Comic Sans MS"));
	CmbGeneral->Append(wxT("Corbel"));
	CmbGeneral->Append(wxT("Courier New"));
	CmbGeneral->Append(wxT("Palatino Linotype"));
	CmbGeneral->Append(wxT("Tahoma"));
	CmbGeneral->Append(wxT("Tempus Sans ITC"));
	CmbGeneral->Append(wxT("Times New Roman"));
	CmbGeneral->Append(general_fonty);
	CmbGeneral->Append(wxT("Verdana"));
	CmbGeneral->SetSelection(10);
	GrpAppText->Add(CmbGeneral, 0, wxALIGN_CENTER | wxALL, 5);

	BtnGeneral = new wxRadioButton(GrpAppText->GetStaticBox(), wxID_ANY, wxT("BOLD"), wxDefaultPosition, wxDefaultSize, 0);

	GrpAppText->Add(BtnGeneral, 0, wxALIGN_CENTER | wxALL, 5);

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

	TabMain->AddPage(TabThree, preflang[53], false);
}

void vSongPrefs::PopulateGrpThemePrefs(wxWrapSizer* WrapThree, int ThemeID, const wxString& GrpLabel, const wxString& GrpColor, vector<int> forecolor, vector<int> backcolor)
{
	wxStaticBoxSizer* GrpTheme;
	GrpTheme = new wxStaticBoxSizer(new wxStaticBox(TabThree, wxID_ANY, GrpLabel), wxVERTICAL);

	GrpTheme->SetMinSize(wxSize(120, 170));
	BtnTheme = new wxButton(GrpTheme->GetStaticBox(), wxID_ANY, GrpColor, wxDefaultPosition, wxSize(110, 150), 0);
	BtnTheme->SetFont(wxFont(20, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, general_fonty));
	BtnTheme->SetForegroundColour(wxColour(forecolor[0], forecolor[1], forecolor[2]));
	BtnTheme->SetBackgroundColour(wxColour(backcolor[0], backcolor[1], backcolor[2]));
	GrpTheme->Add(BtnTheme, 0, wxALL, 5);

	WrapThree->Add(GrpTheme, 1, wxALL | wxEXPAND, 5);
}
void vSongPrefs::PopulateTabFour()
{
	TabFour = new wxScrolledWindow(TabMain, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHSCROLL | wxVSCROLL);
	TabFour->SetScrollRate(5, 5);
	TabFour->SetFont(wxFont(12, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, general_fonty));

	TabMain->AddPage(TabFour, preflang[54], false);
}

void vSongPrefs::BtnSearchCriteria_Click(wxCommandEvent&)
{
	if (BtnSearchCriteria->GetValue() == true) AppSmata::SetOption("tablet_mode", "1");
	else AppSmata::SetOption("tablet_mode", "0");
}

void vSongPrefs::BtnTabletMode_Click(wxCommandEvent&)
{
	if (BtnSearchCriteria->GetValue() == true) AppSmata::SetOption("search_allbooks", "1");
	else AppSmata::SetOption("search_allbooks", "0");
}

void vSongPrefs::CmbLanguage_SelectionChange(wxCommandEvent&)
{
	AppSmata::SetOption("language", lang_list[CmbLanguage->GetSelection()]);

	GetSettings();
	GetLanguages(prefset[3]);
	InitializeLanguage();
}

void vSongPrefs::TxtUserName_TextChange(wxCommandEvent&)
{
	pcrts = (100 - TxtUserName->GetValue().Length());
	LblUserName->SetLabel(wxString::Format(wxT("%i"), pcrts) + " " + preflang[7]);
	AppSmata::SetOption("app_user", TxtUserName->GetValue());
}

void vSongPrefs::CmbGeneral_SelectionChange(wxCommandEvent&)
{
	general_fonty = font_general[CmbGeneral->GetSelection()];
	AppSmata::SetOption("general_font_type", general_fonty);
	TxtSample->SetFont(wxFont(general_fonts, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, general_fonty));
}

void vSongPrefs::SldGeneral_OnScroll(wxScrollEvent&)
{
	general_fonts = SldGeneral->GetValue();
	TxtSample->SetFont(wxFont(general_fonts, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, general_fonty));
	LblGeneral->SetLabel(wxString::Format(wxT("%i"), general_fonts));
	AppSmata::SetOption("general_font_size", wxString::Format(wxT("%i"), general_fonts));
}

void vSongPrefs::CmbPreview_SelectionChange(wxCommandEvent&)
{
	preview_fonty = font_preview[CmbPreview->GetSelection()];
	AppSmata::SetOption("preview_font_type", preview_fonty);
	TxtSample->SetFont(wxFont(preview_fonts, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, preview_fonty));
}

void vSongPrefs::SldPreview_OnScroll(wxScrollEvent&)
{
	preview_fonts = SldPreview->GetValue();
	TxtSample->SetFont(wxFont(preview_fonts, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, preview_fonty));
	LblPreview->SetLabel(wxString::Format(wxT("%i"), preview_fonts));
	AppSmata::SetOption("preview_font_size", wxString::Format(wxT("%i"), preview_fonts));
}

void vSongPrefs::CmbProjection_SelectionChange(wxCommandEvent&)
{
	projection_fonty = font_projection[CmbProjection->GetSelection()];
	AppSmata::SetOption("projector_font_type", projection_fonty);
	TxtSample->SetFont(wxFont(projection_fonts, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, projection_fonty));
}

void vSongPrefs::SldProjection_OnScroll(wxScrollEvent&)
{
	projection_fonts = SldProjection->GetValue();
	TxtSample->SetFont(wxFont(projection_fonts, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, projection_fonty));
	LblProjection->SetLabel(wxString::Format(wxT("%i"), projection_fonts));
	AppSmata::SetOption("projector_font_size", wxString::Format(wxT("%i"), projection_fonts));
}

vSongPrefs::~vSongPrefs()
{
}
