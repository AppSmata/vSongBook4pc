#include "vSongPrefs.h"

vSongPrefs::vSongPrefs(const wxString& title) : wxFrame(NULL, wxID_ANY, title)
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

	this->SetSizeHints(wxDefaultSize, wxDefaultSize);
	this->SetBackgroundColour(wxColour(255, 255, 255));

	wxBoxSizer* MainWrapper;
	MainWrapper = new wxBoxSizer(wxVERTICAL);

	wxBoxSizer* PanelTop;
	PanelTop = new wxBoxSizer(wxVERTICAL);

	LblTitle = new wxStaticText(this, wxID_ANY, wxT("vSongBook Preferences"), wxDefaultPosition, wxSize(-1, 70), 0);
	LblTitle->Wrap(-1);
	LblTitle->SetFont(wxFont(20, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Trebuchet MS")));
	LblTitle->SetBackgroundColour(wxColour(255, 255, 255));

	PanelTop->Add(LblTitle, 1, wxALIGN_RIGHT | wxALL, 0);

	MainWrapper->Add(PanelTop, 0, wxEXPAND, 5);

	tabMain = new wxNotebook(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0);
	tabMain->SetFont(wxFont(15, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Trebuchet MS")));

	TabGeneral = new wxScrolledWindow(tabMain, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHSCROLL | wxVSCROLL);
	TabGeneral->SetScrollRate(5, 5);
	TabGeneral->SetMinSize(wxSize(-1, 75));

	wxBoxSizer* General_Wrapper;
	General_Wrapper = new wxBoxSizer(wxVERTICAL);

	General_Wrapper->SetMinSize(wxSize(-1, 800));
	wxStaticBoxSizer* GrpTabletMode;
	GrpTabletMode = new wxStaticBoxSizer(new wxStaticBox(TabGeneral, wxID_ANY, wxT(" Tablet Mode: ")), wxHORIZONTAL);

	GrpTabletMode->SetMinSize(wxSize(-1, 75));
	LblTabletMode = new wxStaticText(GrpTabletMode->GetStaticBox(), wxID_ANY, wxT("Tablet Mode is when you are using a touch screen input"), wxDefaultPosition, wxDefaultSize, 0);
	LblTabletMode->Wrap(-1);
	LblTabletMode->SetFont(wxFont(12, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Trebuchet MS")));

	GrpTabletMode->Add(LblTabletMode, 1, wxALL, 5);

	BtnTabletMode = new wxRadioButton(GrpTabletMode->GetStaticBox(), wxID_ANY, wxT("ON"), wxDefaultPosition, wxDefaultSize, 0);
	BtnTabletMode->SetFont(wxFont(12, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxT("Trebuchet MS")));

	GrpTabletMode->Add(BtnTabletMode, 0, wxALL, 5);

	General_Wrapper->Add(GrpTabletMode, 0, wxALL | wxEXPAND, 5);

	wxStaticBoxSizer* GrpSearchCriteria;
	GrpSearchCriteria = new wxStaticBoxSizer(new wxStaticBox(TabGeneral, wxID_ANY, wxT(" Search Criteria: ")), wxHORIZONTAL);

	GrpSearchCriteria->SetMinSize(wxSize(-1, 75));
	LblTabletMode1 = new wxStaticText(GrpSearchCriteria->GetStaticBox(), wxID_ANY, wxT("Search in All Songbooks"), wxDefaultPosition, wxDefaultSize, 0);
	LblTabletMode1->Wrap(-1);
	LblTabletMode1->SetFont(wxFont(12, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Trebuchet MS")));

	GrpSearchCriteria->Add(LblTabletMode1, 1, wxALL, 5);

	BtnSearchCriteria = new wxRadioButton(GrpSearchCriteria->GetStaticBox(), wxID_ANY, wxT("ON"), wxDefaultPosition, wxDefaultSize, 0);
	BtnSearchCriteria->SetValue(true);
	BtnSearchCriteria->SetFont(wxFont(12, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxT("Trebuchet MS")));

	GrpSearchCriteria->Add(BtnSearchCriteria, 0, wxALL, 5);

	General_Wrapper->Add(GrpSearchCriteria, 0, wxALL | wxEXPAND, 5);

	wxStaticBoxSizer* GrpLanguage;
	GrpLanguage = new wxStaticBoxSizer(new wxStaticBox(TabGeneral, wxID_ANY, wxT(" Preferred Language: ")), wxHORIZONTAL);

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

	General_Wrapper->Add(GrpLanguage, 0, wxALL | wxEXPAND, 5);

	wxStaticBoxSizer* GrpUserName;
	GrpUserName = new wxStaticBoxSizer(new wxStaticBox(TabGeneral, wxID_ANY, wxT("  Your Name / Name of your Church: ")), wxVERTICAL);

	GrpUserName->SetMinSize(wxSize(-1, 100));
	TxtUserName = new wxTextCtrl(GrpUserName->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
	GrpUserName->Add(TxtUserName, 1, wxALL | wxEXPAND, 5);

	LblUserName = new wxStaticText(GrpUserName->GetStaticBox(), wxID_ANY, wxT("100 characters remaining ..."), wxDefaultPosition, wxDefaultSize, 0);
	LblUserName->Wrap(-1);
	LblUserName->SetFont(wxFont(8, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Trebuchet MS")));

	GrpUserName->Add(LblUserName, 0, wxALL, 5);

	General_Wrapper->Add(GrpUserName, 0, wxALL | wxEXPAND, 5);

	TabGeneral->SetSizer(General_Wrapper);
	TabGeneral->Layout();
	General_Wrapper->Fit(TabGeneral);
	tabMain->AddPage(TabGeneral, wxT("General Options"), true);
	TabFonts = new wxScrolledWindow(tabMain, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHSCROLL | wxVSCROLL);
	TabFonts->SetScrollRate(5, 5);
	wxBoxSizer* FontWrapper;
	FontWrapper = new wxBoxSizer(wxVERTICAL);

	FontWrapper->SetMinSize(wxSize(-1, 600));
	wxStaticBoxSizer* GrpSampleText;
	GrpSampleText = new wxStaticBoxSizer(new wxStaticBox(TabFonts, wxID_ANY, wxT(" Sample Text: ")), wxVERTICAL);

	GrpSampleText->SetMinSize(wxSize(-1, 150));
	LblSampleText = new wxStaticText(GrpSampleText->GetStaticBox(), wxID_ANY, wxT("Only Believe"), wxDefaultPosition, wxSize(-1, 100), wxALIGN_CENTER_HORIZONTAL);
	LblSampleText->Wrap(-1);
	LblSampleText->SetFont(wxFont(40, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Trebuchet MS")));

	GrpSampleText->Add(LblSampleText, 1, wxALIGN_CENTER | wxALL | wxEXPAND, 5);

	FontWrapper->Add(GrpSampleText, 0, wxALIGN_CENTER | wxALIGN_CENTER_HORIZONTAL | wxALL | wxEXPAND, 5);

	wxStaticBoxSizer* GrpAppFont;
	GrpAppFont = new wxStaticBoxSizer(new wxStaticBox(TabFonts, wxID_ANY, wxT(" General App Font: ")), wxHORIZONTAL);

	GrpAppFont->SetMinSize(wxSize(-1, 100));
	LblAppFont = new wxStaticText(GrpAppFont->GetStaticBox(), wxID_ANY, wxT("15"), wxDefaultPosition, wxSize(25, -1), 0);
	LblAppFont->Wrap(-1);
	LblAppFont->SetFont(wxFont(12, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Trebuchet MS")));

	GrpAppFont->Add(LblAppFont, 0, wxALIGN_CENTER | wxALL, 5);

	BtnAppFontSmaller = new wxBitmapButton(GrpAppFont->GetStaticBox(), wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW | 0);

	BtnAppFontSmaller->SetBitmap(wxBitmap(ButtonBitmaps[Button_smaller]));
	GrpAppFont->Add(BtnAppFontSmaller, 0, wxALL, 5);

	SldAppFont = new wxSlider(GrpAppFont->GetStaticBox(), wxID_ANY, 15, 12, 50, wxDefaultPosition, wxDefaultSize, wxSL_BOTH | wxSL_HORIZONTAL);
	GrpAppFont->Add(SldAppFont, 1, wxALIGN_CENTER | wxALL, 5);

	BtnAppFontBigger = new wxBitmapButton(GrpAppFont->GetStaticBox(), wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW | 0);

	BtnAppFontBigger->SetBitmap(wxBitmap(ButtonBitmaps[Button_bigger]));
	GrpAppFont->Add(BtnAppFontBigger, 0, wxALL, 5);

	cmbAppFont = new wxComboBox(GrpAppFont->GetStaticBox(), wxID_ANY, wxT("Font Type"), wxDefaultPosition, wxDefaultSize, 0, NULL, 0);
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
	GrpAppFont->Add(cmbAppFont, 0, wxALIGN_CENTER | wxALL, 5);

	BtnAppFont = new wxRadioButton(GrpAppFont->GetStaticBox(), wxID_ANY, wxT("BOLD"), wxDefaultPosition, wxDefaultSize, 0);
	BtnAppFont->SetFont(wxFont(12, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxT("Trebuchet MS")));

	GrpAppFont->Add(BtnAppFont, 0, wxALIGN_CENTER | wxALL, 5);

	FontWrapper->Add(GrpAppFont, 0, wxALL | wxEXPAND, 5);

	wxStaticBoxSizer* GrpPreview;
	GrpPreview = new wxStaticBoxSizer(new wxStaticBox(TabFonts, wxID_ANY, wxT(" Song Preview Font: ")), wxHORIZONTAL);

	GrpPreview->SetMinSize(wxSize(-1, 100));
	LblPreview = new wxStaticText(GrpPreview->GetStaticBox(), wxID_ANY, wxT("15"), wxDefaultPosition, wxSize(25, -1), 0);
	LblPreview->Wrap(-1);
	LblPreview->SetFont(wxFont(12, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Trebuchet MS")));

	GrpPreview->Add(LblPreview, 0, wxALIGN_CENTER | wxALL, 5);

	BtnPreviewSmaller = new wxBitmapButton(GrpPreview->GetStaticBox(), wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW | 0);

	BtnPreviewSmaller->SetBitmap(wxBitmap(ButtonBitmaps[Button_smaller]));
	GrpPreview->Add(BtnPreviewSmaller, 0, wxALL, 5);

	SldPreview = new wxSlider(GrpPreview->GetStaticBox(), wxID_ANY, 15, 12, 50, wxDefaultPosition, wxDefaultSize, wxSL_BOTH | wxSL_HORIZONTAL);
	GrpPreview->Add(SldPreview, 1, wxALIGN_CENTER | wxALL, 5);

	BtnPreviewBigger = new wxBitmapButton(GrpPreview->GetStaticBox(), wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW | 0);

	BtnPreviewBigger->SetBitmap(wxBitmap(ButtonBitmaps[Button_bigger]));
	GrpPreview->Add(BtnPreviewBigger, 0, wxALL, 5);

	cmbPreview = new wxComboBox(GrpPreview->GetStaticBox(), wxID_ANY, wxT("Font Type"), wxDefaultPosition, wxDefaultSize, 0, NULL, 0);
	cmbPreview->Append(wxT("Arial"));
	cmbPreview->Append(wxT("Calibri"));
	cmbPreview->Append(wxT("Century Gothic"));
	cmbPreview->Append(wxT("Comic Sans MS"));
	cmbPreview->Append(wxT("Corbel"));
	cmbPreview->Append(wxT("Courier New"));
	cmbPreview->Append(wxT("Palatino Linotype"));
	cmbPreview->Append(wxT("Tahoma"));
	cmbPreview->Append(wxT("Tempus Sans ITC"));
	cmbPreview->Append(wxT("Times New Roman"));
	cmbPreview->Append(wxT("Trebuchet MS"));
	cmbPreview->Append(wxT("Verdana"));
	cmbPreview->SetSelection(10);
	GrpPreview->Add(cmbPreview, 0, wxALIGN_CENTER | wxALL, 5);

	BtnPreview = new wxRadioButton(GrpPreview->GetStaticBox(), wxID_ANY, wxT("BOLD"), wxDefaultPosition, wxDefaultSize, 0);
	BtnPreview->SetFont(wxFont(12, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxT("Trebuchet MS")));

	GrpPreview->Add(BtnPreview, 0, wxALIGN_CENTER | wxALL, 5);

	FontWrapper->Add(GrpPreview, 1, wxEXPAND, 5);

	wxStaticBoxSizer* GrpProjection;
	GrpProjection = new wxStaticBoxSizer(new wxStaticBox(TabFonts, wxID_ANY, wxT(" Song Projection Font: ")), wxHORIZONTAL);

	GrpProjection->SetMinSize(wxSize(-1, 100));
	LblProjection = new wxStaticText(GrpProjection->GetStaticBox(), wxID_ANY, wxT("15"), wxDefaultPosition, wxSize(25, -1), 0);
	LblProjection->Wrap(-1);
	LblProjection->SetFont(wxFont(12, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Trebuchet MS")));

	GrpProjection->Add(LblProjection, 0, wxALIGN_CENTER | wxALL, 5);

	BtnProjectionSmaller = new wxBitmapButton(GrpProjection->GetStaticBox(), wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW | 0);

	BtnProjectionSmaller->SetBitmap(wxBitmap(ButtonBitmaps[Button_smaller]));
	GrpProjection->Add(BtnProjectionSmaller, 0, wxALL, 5);

	SldProjection = new wxSlider(GrpProjection->GetStaticBox(), wxID_ANY, 15, 12, 50, wxDefaultPosition, wxDefaultSize, wxSL_BOTH | wxSL_HORIZONTAL);
	GrpProjection->Add(SldProjection, 1, wxALIGN_CENTER | wxALL, 5);

	BtnProjectionBigger = new wxBitmapButton(GrpProjection->GetStaticBox(), wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW | 0);

	BtnProjectionBigger->SetBitmap(wxBitmap(ButtonBitmaps[Button_bigger]));
	GrpProjection->Add(BtnProjectionBigger, 0, wxALL, 5);

	cmbProjection = new wxComboBox(GrpProjection->GetStaticBox(), wxID_ANY, wxT("Font Type"), wxDefaultPosition, wxDefaultSize, 0, NULL, 0);
	cmbProjection->Append(wxT("Arial"));
	cmbProjection->Append(wxT("Calibri"));
	cmbProjection->Append(wxT("Century Gothic"));
	cmbProjection->Append(wxT("Comic Sans MS"));
	cmbProjection->Append(wxT("Corbel"));
	cmbProjection->Append(wxT("Courier New"));
	cmbProjection->Append(wxT("Palatino Linotype"));
	cmbProjection->Append(wxT("Tahoma"));
	cmbProjection->Append(wxT("Tempus Sans ITC"));
	cmbProjection->Append(wxT("Times New Roman"));
	cmbProjection->Append(wxT("Trebuchet MS"));
	cmbProjection->Append(wxT("Verdana"));
	cmbProjection->SetSelection(10);
	GrpProjection->Add(cmbProjection, 0, wxALIGN_CENTER | wxALL, 5);

	BtnProjection = new wxRadioButton(GrpProjection->GetStaticBox(), wxID_ANY, wxT("BOLD"), wxDefaultPosition, wxDefaultSize, 0);
	BtnProjection->SetFont(wxFont(12, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxT("Trebuchet MS")));

	GrpProjection->Add(BtnProjection, 0, wxALIGN_CENTER | wxALL, 5);

	FontWrapper->Add(GrpProjection, 1, wxEXPAND, 5);

	TabFonts->SetSizer(FontWrapper);
	TabFonts->Layout();
	FontWrapper->Fit(TabFonts);
	tabMain->AddPage(TabFonts, wxT("Font Management"), false);
	TabTheme = new wxScrolledWindow(tabMain, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHSCROLL | wxVSCROLL);
	TabTheme->SetScrollRate(5, 5);
	wxWrapSizer* ThemeWrapper;
	ThemeWrapper = new wxWrapSizer(wxHORIZONTAL, wxWRAPSIZER_DEFAULT_FLAGS);

	wxStaticBoxSizer* Theme0;
	Theme0 = new wxStaticBoxSizer(new wxStaticBox(TabTheme, wxID_ANY, wxT(" Theme One ")), wxVERTICAL);

	Theme0->SetMinSize(wxSize(120, 170));
	BtnTheme0 = new wxButton(Theme0->GetStaticBox(), wxID_ANY, wxT("Black\n&&\nWhite"), wxDefaultPosition, wxDefaultSize, 0);
	BtnTheme0->SetFont(wxFont(20, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Trebuchet MS")));
	BtnTheme0->SetForegroundColour(wxColour(255, 255, 255));
	BtnTheme0->SetBackgroundColour(wxColour(0, 0, 0));
	BtnTheme0->SetMinSize(wxSize(110, 150));

	Theme0->Add(BtnTheme0, 0, wxALIGN_CENTER | wxALL | wxEXPAND, 5);

	ThemeWrapper->Add(Theme0, 1, wxALL | wxEXPAND, 5);

	wxStaticBoxSizer* Theme1;
	Theme1 = new wxStaticBoxSizer(new wxStaticBox(TabTheme, wxID_ANY, wxT(" Theme Two")), wxVERTICAL);

	Theme1->SetMinSize(wxSize(120, 170));
	BtnTheme1 = new wxButton(Theme1->GetStaticBox(), wxID_ANY, wxT("White\n&&\nBlack"), wxDefaultPosition, wxDefaultSize, 0);
	BtnTheme1->SetFont(wxFont(20, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Trebuchet MS")));
	BtnTheme1->SetForegroundColour(wxColour(0, 0, 0));
	BtnTheme1->SetBackgroundColour(wxColour(255, 255, 255));
	BtnTheme1->SetMinSize(wxSize(110, 150));

	Theme1->Add(BtnTheme1, 0, wxALIGN_CENTER | wxALL | wxEXPAND, 5);

	ThemeWrapper->Add(Theme1, 0, wxALL | wxEXPAND, 5);

	wxStaticBoxSizer* Theme2;
	Theme2 = new wxStaticBoxSizer(new wxStaticBox(TabTheme, wxID_ANY, wxT(" Theme Three")), wxVERTICAL);

	Theme2->SetMinSize(wxSize(120, 170));
	BtnTheme2 = new wxButton(Theme2->GetStaticBox(), wxID_ANY, wxT("Blue\n&&\nWhite"), wxDefaultPosition, wxDefaultSize, 0);
	BtnTheme2->SetFont(wxFont(20, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Trebuchet MS")));
	BtnTheme2->SetForegroundColour(wxColour(255, 255, 255));
	BtnTheme2->SetBackgroundColour(wxColour(0, 0, 255));
	BtnTheme2->SetMinSize(wxSize(110, 150));

	Theme2->Add(BtnTheme2, 0, wxALIGN_CENTER | wxALL | wxEXPAND, 5);

	ThemeWrapper->Add(Theme2, 1, wxALL | wxEXPAND, 5);

	wxStaticBoxSizer* Theme3;
	Theme3 = new wxStaticBoxSizer(new wxStaticBox(TabTheme, wxID_ANY, wxT(" Theme Four")), wxVERTICAL);

	Theme3->SetMinSize(wxSize(120, 170));
	BtnTheme3 = new wxButton(Theme3->GetStaticBox(), wxID_ANY, wxT("White\n&&\nBLue"), wxDefaultPosition, wxDefaultSize, 0);
	BtnTheme3->SetFont(wxFont(20, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Trebuchet MS")));
	BtnTheme3->SetForegroundColour(wxColour(0, 0, 255));
	BtnTheme3->SetBackgroundColour(wxColour(255, 255, 255));
	BtnTheme3->SetMinSize(wxSize(110, 150));

	Theme3->Add(BtnTheme3, 0, wxALIGN_CENTER | wxALL | wxEXPAND, 5);

	ThemeWrapper->Add(Theme3, 1, wxALL | wxEXPAND, 5);

	wxStaticBoxSizer* Theme4;
	Theme4 = new wxStaticBoxSizer(new wxStaticBox(TabTheme, wxID_ANY, wxT(" Theme Five ")), wxVERTICAL);

	Theme4->SetMinSize(wxSize(120, 170));
	BtnTheme4 = new wxButton(Theme4->GetStaticBox(), wxID_ANY, wxT("Green\n&&\nWhite"), wxDefaultPosition, wxDefaultSize, 0);
	BtnTheme4->SetFont(wxFont(20, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Trebuchet MS")));
	BtnTheme4->SetForegroundColour(wxColour(255, 255, 255));
	BtnTheme4->SetBackgroundColour(wxColour(0, 128, 0));
	BtnTheme4->SetMinSize(wxSize(110, 150));

	Theme4->Add(BtnTheme4, 0, wxALIGN_CENTER | wxALL | wxEXPAND, 5);

	ThemeWrapper->Add(Theme4, 1, wxALL | wxEXPAND, 5);

	wxStaticBoxSizer* Theme5;
	Theme5 = new wxStaticBoxSizer(new wxStaticBox(TabTheme, wxID_ANY, wxT(" Theme Six")), wxVERTICAL);

	Theme5->SetMinSize(wxSize(120, 170));
	BtnTheme5 = new wxButton(Theme5->GetStaticBox(), wxID_ANY, wxT("White\n&&\nGreen"), wxDefaultPosition, wxDefaultSize, 0);
	BtnTheme5->SetFont(wxFont(20, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Trebuchet MS")));
	BtnTheme5->SetForegroundColour(wxColour(0, 128, 0));
	BtnTheme5->SetBackgroundColour(wxColour(255, 255, 255));
	BtnTheme5->SetMinSize(wxSize(110, 150));

	Theme5->Add(BtnTheme5, 0, wxALIGN_CENTER | wxALL | wxEXPAND, 5);

	ThemeWrapper->Add(Theme5, 1, wxALL | wxEXPAND, 5);

	wxStaticBoxSizer* Theme6;
	Theme6 = new wxStaticBoxSizer(new wxStaticBox(TabTheme, wxID_ANY, wxT(" Theme Seven")), wxVERTICAL);

	Theme6->SetMinSize(wxSize(120, 170));
	BtnTheme6 = new wxButton(Theme6->GetStaticBox(), wxID_ANY, wxT("Orange\n&&\nWhite"), wxDefaultPosition, wxDefaultSize, 0);
	BtnTheme6->SetFont(wxFont(20, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Trebuchet MS")));
	BtnTheme6->SetForegroundColour(wxColour(255, 255, 255));
	BtnTheme6->SetBackgroundColour(wxColour(255, 69, 0));
	BtnTheme6->SetMinSize(wxSize(110, 150));

	Theme6->Add(BtnTheme6, 0, wxALIGN_CENTER | wxALL | wxEXPAND, 5);

	ThemeWrapper->Add(Theme6, 1, wxALL | wxEXPAND, 5);

	wxStaticBoxSizer* Theme7;
	Theme7 = new wxStaticBoxSizer(new wxStaticBox(TabTheme, wxID_ANY, wxT(" Theme Eight")), wxVERTICAL);

	Theme7->SetMinSize(wxSize(120, 170));
	BtnTheme7 = new wxButton(Theme7->GetStaticBox(), wxID_ANY, wxT("White\n&&\nOrange"), wxDefaultPosition, wxDefaultSize, 0);
	BtnTheme7->SetFont(wxFont(20, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Trebuchet MS")));
	BtnTheme7->SetForegroundColour(wxColour(255, 69, 0));
	BtnTheme7->SetBackgroundColour(wxColour(255, 255, 255));
	BtnTheme7->SetMinSize(wxSize(110, 150));

	Theme7->Add(BtnTheme7, 0, wxALIGN_CENTER | wxALL | wxEXPAND, 5);


	ThemeWrapper->Add(Theme7, 1, wxALL | wxEXPAND, 5);

	wxStaticBoxSizer* Theme8;
	Theme8 = new wxStaticBoxSizer(new wxStaticBox(TabTheme, wxID_ANY, wxT(" Theme Nine ")), wxVERTICAL);

	Theme8->SetMinSize(wxSize(120, 170));
	BtnTheme8 = new wxButton(Theme8->GetStaticBox(), wxID_ANY, wxT("Red\n&&\nWhite"), wxDefaultPosition, wxDefaultSize, 0);
	BtnTheme8->SetFont(wxFont(20, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Trebuchet MS")));
	BtnTheme8->SetForegroundColour(wxColour(255, 255, 255));
	BtnTheme8->SetBackgroundColour(wxColour(255, 0, 0));
	BtnTheme8->SetMinSize(wxSize(110, 150));

	Theme8->Add(BtnTheme8, 0, wxALIGN_CENTER | wxALL | wxEXPAND, 5);


	ThemeWrapper->Add(Theme8, 1, wxALL | wxEXPAND, 5);

	wxStaticBoxSizer* Theme9;
	Theme9 = new wxStaticBoxSizer(new wxStaticBox(TabTheme, wxID_ANY, wxT(" Theme Ten ")), wxVERTICAL);

	Theme9->SetMinSize(wxSize(120, 170));
	BtnTheme9 = new wxButton(Theme9->GetStaticBox(), wxID_ANY, wxT("White\n&&\nRed"), wxDefaultPosition, wxDefaultSize, 0);
	BtnTheme9->SetFont(wxFont(20, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Trebuchet MS")));
	BtnTheme9->SetForegroundColour(wxColour(255, 0, 0));
	BtnTheme9->SetBackgroundColour(wxColour(255, 255, 255));
	BtnTheme9->SetMinSize(wxSize(110, 150));

	Theme9->Add(BtnTheme9, 0, wxALIGN_CENTER | wxALL | wxEXPAND, 5);


	ThemeWrapper->Add(Theme9, 1, wxALL | wxEXPAND, 5);

	TabTheme->SetSizer(ThemeWrapper);
	TabTheme->Layout();
	ThemeWrapper->Fit(TabTheme);
	tabMain->AddPage(TabTheme, wxT("Projection Theme"), false);
	TabReset = new wxScrolledWindow(tabMain, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHSCROLL | wxVSCROLL);
	TabReset->SetScrollRate(5, 5);
	tabMain->AddPage(TabReset, wxT("Reset"), false);

	MainWrapper->Add(tabMain, 1, wxEXPAND | wxALL, 5);


	this->SetSizer(MainWrapper);
	this->Layout();
	StatusBar = this->CreateStatusBar(1, wxSTB_SIZEGRIP, wxID_ANY);

	this->Centre(wxBOTH);

	// Connect Events
	/*BtnTabletMode->Connect(wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler(vSongPrefs::BtnTablet_Click), NULL, this);
	BtnSearchCriteria->Connect(wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler(vSongPrefs::BtnSearch_Click), NULL, this);
	cmbLanguage->Connect(wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler(vSongPrefs::cmbLanguage_Select), NULL, this);
	TxtUserName->Connect(wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler(vSongPrefs::TxtUsername_Changed), NULL, this);
	BtnAppFontSmaller->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(vSongPrefs::BtnAppFontSmaller_Click), NULL, this);
	SldAppFont->Connect(wxEVT_SCROLL_TOP, wxScrollEventHandler(vSongPrefs::SldAppFont_Scroll), NULL, this);
	SldAppFont->Connect(wxEVT_SCROLL_BOTTOM, wxScrollEventHandler(vSongPrefs::SldAppFont_Scroll), NULL, this);
	SldAppFont->Connect(wxEVT_SCROLL_LINEUP, wxScrollEventHandler(vSongPrefs::SldAppFont_Scroll), NULL, this);
	SldAppFont->Connect(wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler(vSongPrefs::SldAppFont_Scroll), NULL, this);
	SldAppFont->Connect(wxEVT_SCROLL_PAGEUP, wxScrollEventHandler(vSongPrefs::SldAppFont_Scroll), NULL, this);
	SldAppFont->Connect(wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler(vSongPrefs::SldAppFont_Scroll), NULL, this);
	SldAppFont->Connect(wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler(vSongPrefs::SldAppFont_Scroll), NULL, this);
	SldAppFont->Connect(wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler(vSongPrefs::SldAppFont_Scroll), NULL, this);
	SldAppFont->Connect(wxEVT_SCROLL_CHANGED, wxScrollEventHandler(vSongPrefs::SldAppFont_Scroll), NULL, this);
	BtnAppFontBigger->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(vSongPrefs::BtnAppFontBigger_Click), NULL, this);
	cmbAppFont->Connect(wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler(vSongPrefs::CmbAppFont_Selected), NULL, this);
	BtnAppFont->Connect(wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler(vSongPrefs::BtnAppFont_Click), NULL, this);
	BtnPreviewSmaller->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(vSongPrefs::BtnAppFontSmaller_Click), NULL, this);
	SldPreview->Connect(wxEVT_SCROLL_TOP, wxScrollEventHandler(vSongPrefs::SldAppFont_Scroll), NULL, this);
	SldPreview->Connect(wxEVT_SCROLL_BOTTOM, wxScrollEventHandler(vSongPrefs::SldAppFont_Scroll), NULL, this);
	SldPreview->Connect(wxEVT_SCROLL_LINEUP, wxScrollEventHandler(vSongPrefs::SldAppFont_Scroll), NULL, this);
	SldPreview->Connect(wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler(vSongPrefs::SldAppFont_Scroll), NULL, this);
	SldPreview->Connect(wxEVT_SCROLL_PAGEUP, wxScrollEventHandler(vSongPrefs::SldAppFont_Scroll), NULL, this);
	SldPreview->Connect(wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler(vSongPrefs::SldAppFont_Scroll), NULL, this);
	SldPreview->Connect(wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler(vSongPrefs::SldAppFont_Scroll), NULL, this);
	SldPreview->Connect(wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler(vSongPrefs::SldAppFont_Scroll), NULL, this);
	SldPreview->Connect(wxEVT_SCROLL_CHANGED, wxScrollEventHandler(vSongPrefs::SldAppFont_Scroll), NULL, this);
	BtnPreviewBigger->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(vSongPrefs::BtnAppFontBigger_Click), NULL, this);
	cmbPreview->Connect(wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler(vSongPrefs::CmbAppFont_Selected), NULL, this);
	BtnPreview->Connect(wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler(vSongPrefs::BtnAppFont_Click), NULL, this);
	BtnProjectionSmaller->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(vSongPrefs::BtnAppFontSmaller_Click), NULL, this);
	SldProjection->Connect(wxEVT_SCROLL_TOP, wxScrollEventHandler(vSongPrefs::SldAppFont_Scroll), NULL, this);
	SldProjection->Connect(wxEVT_SCROLL_BOTTOM, wxScrollEventHandler(vSongPrefs::SldAppFont_Scroll), NULL, this);
	SldProjection->Connect(wxEVT_SCROLL_LINEUP, wxScrollEventHandler(vSongPrefs::SldAppFont_Scroll), NULL, this);
	SldProjection->Connect(wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler(vSongPrefs::SldAppFont_Scroll), NULL, this);
	SldProjection->Connect(wxEVT_SCROLL_PAGEUP, wxScrollEventHandler(vSongPrefs::SldAppFont_Scroll), NULL, this);
	SldProjection->Connect(wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler(vSongPrefs::SldAppFont_Scroll), NULL, this);
	SldProjection->Connect(wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler(vSongPrefs::SldAppFont_Scroll), NULL, this);
	SldProjection->Connect(wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler(vSongPrefs::SldAppFont_Scroll), NULL, this);
	SldProjection->Connect(wxEVT_SCROLL_CHANGED, wxScrollEventHandler(vSongPrefs::SldAppFont_Scroll), NULL, this);
	BtnProjectionBigger->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(vSongPrefs::BtnAppFontBigger_Click), NULL, this);
	cmbProjection->Connect(wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler(vSongPrefs::CmbAppFont_Selected), NULL, this);
	BtnProjection->Connect(wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler(vSongPrefs::BtnAppFont_Click), NULL, this);
	BtnTheme0->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(vSongPrefs::BtnThemOne_Click), NULL, this);
	BtnTheme1->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(vSongPrefs::BtnThemOne_Click), NULL, this);
	BtnTheme2->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(vSongPrefs::BtnThemOne_Click), NULL, this);
	BtnTheme3->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(vSongPrefs::BtnThemOne_Click), NULL, this);
	BtnTheme4->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(vSongPrefs::BtnThemOne_Click), NULL, this);
	BtnTheme5->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(vSongPrefs::BtnThemOne_Click), NULL, this);
	BtnTheme6->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(vSongPrefs::BtnThemOne_Click), NULL, this);
	BtnTheme7->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(vSongPrefs::BtnThemOne_Click), NULL, this);
	BtnTheme8->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(vSongPrefs::BtnThemOne_Click), NULL, this);
	BtnTheme9->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(vSongPrefs::BtnThemOne_Click), NULL, this);*/
}
