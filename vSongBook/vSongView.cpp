/////////////////////////////////////////////////////////////////////////////
// Name:        vSongView.cpp
// Purpose:     vSongView for Desktop
// Author:      Jacksiro
// Modified by:
// Created:     27/07/19
// Copyright:   (c) AppSmata
// Licence:     wxWindows licence
/////////////////////////////////////////////////////////////////////////////

#include "AppSmata.h"
#include "vSongView.h"
#include <wx\tokenzr.h>

int this_book, this_song, slides, slideno, slideindex;
wxString setsong, bookid, songid, number, title, alias, content, key, author, book, chorus, slide;
vector<wxString> songverses1, songverses2;
bool haschorus;

enum
{
	Button_blackdown,
	Button_blackup,
	Button_max
};

wxBitmap ViewsButtonsBitmaps[Button_max];

#if USE_XPM_BITMAPS
#define VIEWS_BTN_BMP(bmp) \
        ViewsButtonsBitmaps[Button_##bmp] = wxBitmap(bmp##_xpm)
#else // !USE_XPM_BITMAPS
#define VIEWS_BTN_BMP(bmp) \
        ViewsButtonsBitmaps[Button_##bmp] = wxBITMAP(bmp)
#endif // USE_XPM_BITMAPS/!USE_XPM_BITMAPS

vSongView::vSongView(const wxString& title) : wxFrame(NULL, wxID_ANY, title)
{
	this->SetSizeHints(wxDefaultSize, wxDefaultSize);
	this->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_BTNHIGHLIGHT));

	wxBoxSizer* MainWrapper;
	MainWrapper = new wxBoxSizer(wxVERTICAL);
	
	AppLabel = new wxStaticBox(this, wxID_ANY, wxT(" vSongView for Desktop v2.4.1 "));
	//AppLabel->SetForegroundColour(wxColour(fcl1, fcl2, fcl3));
	wxStaticBoxSizer* GrpMain;
	GrpMain = new wxStaticBoxSizer(AppLabel, wxVERTICAL);

	wxBoxSizer* InnerWrapper;
	InnerWrapper = new wxBoxSizer(wxVERTICAL);

	wxBoxSizer* TopPanel;
	TopPanel = new wxBoxSizer(wxHORIZONTAL);
	SetTopPanel(GrpMain, TopPanel);
	InnerWrapper->Add(TopPanel, 0, wxALL | wxEXPAND, 5);

	LineUp = new wxStaticLine(GrpMain->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL);
	InnerWrapper->Add(LineUp, 0, wxEXPAND | wxALL, 5);


	wxBoxSizer* MidPanel;
	MidPanel = new wxBoxSizer(wxHORIZONTAL);

	SetMidPanel(GrpMain, MidPanel);
	InnerWrapper->Add(MidPanel, 1, wxALIGN_CENTER | wxALL, 0);

	LineDown = new wxStaticLine(GrpMain->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL);
	InnerWrapper->Add(LineDown, 0, wxEXPAND | wxALL, 5);

	wxBoxSizer* DownPanel;
	DownPanel = new wxBoxSizer(wxHORIZONTAL);
	SetDownPanel(GrpMain, DownPanel);

	InnerWrapper->Add(DownPanel, 0, wxALL | wxEXPAND, 5);

	GrpMain->Add(InnerWrapper, 1, wxEXPAND, 5);

	MainWrapper->Add(GrpMain, 1, wxALL | wxEXPAND, 5);

	this->SetSizer(MainWrapper);
	this->Layout();

	this->Centre(wxBOTH);

	TxtCommand->SetFocus();

	AppLabel->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(vSongView::Anywhere_Click), NULL, this);
	LblKey->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(vSongView::Anywhere_Click), NULL, this);
	LblTitle->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(vSongView::Anywhere_Click), NULL, this);
	LineUp->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(vSongView::Anywhere_Click), NULL, this);
	LblContent->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(vSongView::Anywhere_Click), NULL, this);
	LineDown->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(vSongView::Anywhere_Click), NULL, this);
	//LblSongBook->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(vSongView::Anywhere_Click), NULL, this);
	//LblAurthor->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(vSongView::Anywhere_Click), NULL, this);
	//LblVerse->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(vSongView::Anywhere_Click), NULL, this);
	//PicLast->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(vSongView::Anywhere_Click), NULL, this);
	//PicNext->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(vSongView::Anywhere_Click), NULL, this);

	TxtCommand->Connect(wxEVT_MOUSEWHEEL, wxMouseEventHandler(vSongView::TxtCommandLine_MouseWheel), NULL, this);

	TxtCommand->Connect(wxEVT_KEY_DOWN, wxKeyEventHandler(vSongView::TxtCommandLine_KeyDown), NULL, this);
	BtnClose->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(vSongView::BtnClose_Click), NULL, this);

	BtnClose->Hide();
}

void vSongView::SetTopPanel(wxStaticBoxSizer* GrpMain, wxBoxSizer* TopPanel)
{
	LblKey = new wxStaticText(GrpMain->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
	LblKey->SetFont(wxFont(25, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Trebuchet MS")));
	LblKey->Wrap(-1);
	TopPanel->Add(LblKey, 0, wxALL, 5);

	wxBoxSizer* WrapTitle;
	WrapTitle = new wxBoxSizer(wxVERTICAL);

	LblTitle = new wxStaticText(GrpMain->GetStaticBox(), wxID_ANY, wxT("Only Believe"), wxDefaultPosition, wxDefaultSize, 0);
	LblTitle->SetFont(wxFont(25, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Trebuchet MS")));
	LblTitle->Wrap(-1); 

	WrapTitle->Add(LblTitle, 0, wxALIGN_CENTER | wxALL, 0);
	
	TopPanel->Add(WrapTitle, 1, wxALIGN_CENTER | wxALL, 5);

	BtnClose = new wxButton(GrpMain->GetStaticBox(), wxID_ANY, wxT("X"), wxDefaultPosition, wxSize(40, 20), 0);
	BtnClose->SetFont(wxFont(12, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Trebuchet MS")));

	TopPanel->Add(BtnClose, 0, wxALL | wxEXPAND, 5);

	TxtCommand = new wxTextCtrl(GrpMain->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(1, -1), 0);
	TopPanel->Add(TxtCommand, 0, wxALL, 5);

}

void vSongView::SetMidPanel(wxStaticBoxSizer* GrpMain, wxBoxSizer* MidPanel)
{
	wxBoxSizer* WrapContent;
	WrapContent = new wxBoxSizer(wxVERTICAL);

	LblContent = new wxStaticText(GrpMain->GetStaticBox(), wxID_ANY, wxT("CHORUS\nOnly Believe,\nAll things are possible"), wxDefaultPosition, wxDefaultSize, 0);
	LblContent->SetFont(wxFont(25, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Trebuchet MS")));
	LblContent->Wrap(-1);
	WrapContent->Add(LblContent, 0, wxALIGN_CENTER | wxALL, 0);

	MidPanel->Add(WrapContent, 1, wxALIGN_CENTER | wxALL, 5);
}

void vSongView::SetDownPanel(wxStaticBoxSizer* GrpMain, wxBoxSizer* DownPanel)
{
	VIEWS_BTN_BMP(blackdown);
	VIEWS_BTN_BMP(blackup);

	LblSongInfo = new wxStaticText(GrpMain->GetStaticBox(), wxID_ANY, wxT("1# Songs of Worship"), wxDefaultPosition, wxDefaultSize, 0);
	LblSongInfo->SetFont(wxFont(20, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Trebuchet MS")));
	LblSongInfo->Wrap(-1);
	DownPanel->Add(LblSongInfo, 1, wxALL, 5);

	LblAuthor = new wxStaticText(GrpMain->GetStaticBox(), wxID_ANY, wxT("Public Domain"), wxDefaultPosition, wxDefaultSize, 0);
	LblAuthor->SetFont(wxFont(20, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Trebuchet MS")));
	LblAuthor->Wrap(-1);
	DownPanel->Add(LblAuthor, 1, wxALL, 5);

	LblVerse = new wxStaticText(GrpMain->GetStaticBox(), wxID_ANY, wxT("Verse 1/3"), wxDefaultPosition, wxDefaultSize, 0);
	LblVerse->SetFont(wxFont(20, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Trebuchet MS")));
	LblVerse->Wrap(-1);
	DownPanel->Add(LblVerse, 0, wxALL, 5);

	wxBoxSizer* WrapArrows;
	WrapArrows = new wxBoxSizer(wxHORIZONTAL);

	BtnLast = new wxBitmapButton(GrpMain->GetStaticBox(), wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW);
	BtnLast->SetBitmap(wxBitmap(ViewsButtonsBitmaps[Button_blackup]));
	//BtnLast->SetBackgroundColour(wxColour(bcl1, bcl2, bcl3));
	WrapArrows->Add(BtnLast, 0, wxALL, 5);

	BtnNext = new wxBitmapButton(GrpMain->GetStaticBox(), wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW);
	BtnNext->SetBitmap(wxBitmap(ViewsButtonsBitmaps[Button_blackdown]));
	//BtnNext->SetBackgroundColour(wxColour(bcl1, bcl2, bcl3));
	WrapArrows->Add(BtnNext, 0, wxALL, 5);

	PicLast = new wxStaticBitmap(GrpMain->GetStaticBox(), wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, 0);
	PicLast->SetBitmap(wxBitmap(ViewsButtonsBitmaps[Button_blackup]));
	//PicLast->SetBackgroundColour(wxColour(bcl1, bcl2, bcl3));
	WrapArrows->Add(PicLast, 0, wxALL, 0);

	PicNext = new wxStaticBitmap(GrpMain->GetStaticBox(), wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, 0);
	PicNext->SetBitmap(wxBitmap(ViewsButtonsBitmaps[Button_blackdown]));
	//PicNext->SetBackgroundColour(wxColour(bcl1, bcl2, bcl3));
	WrapArrows->Add(PicNext, 0, wxALL, 5);

	DownPanel->Add(WrapArrows, 0, wxALL, 5);
}

void vSongView::Anywhere_Click(wxCommandEvent&)
{
	TxtCommand->SetFocus();
}

void vSongView::BtnClose_Click(wxCommandEvent&)
{
	this->Close();
}

void vSongView::TxtCommandLine_KeyDown(wxKeyEvent& event)
{
	switch (event.GetKeyCode())
	{
		//When Escape Key is Pressed
		case WXK_ESCAPE:
			this->Close();
			break;
		
		//When Up Arrow Key is Pressed
		case WXK_UP:
			try
			{
				if (slideindex != 0)
				{
					slideindex = slideindex - 1;
					//SetPresentation();
				}
			}
			catch (exception & ex) {}
			break;

		//When Down Arrow Key is Pressed
		case WXK_DOWN:
			try
			{
				if (slideindex != (slides - 1))
				{
					slideindex = slideindex + 1;
					//SetPresentation();
				}
			}
			catch (exception & ex) {}
			break;

		//When Minus Key is Pressed
		case WXK_SUBTRACT:
			/*if (fontsize >= 10)
			{
				try
				{
					fontsize = fontsize - 3;
					settings.FontSizeProject = fontsize;
					lblSongText.Font = new Font(settings.FontTypeProject, settings.FontSizeProject, settings.FontBoldProject ? FontStyle.Bold : FontStyle.Regular, GraphicsUnit.Point, ((byte)(0)));
				}
				catch (Exception) {}
			}*/
			break;

		//When Plus Key is Pressed
		case WXK_ADD:
			/*if (fontsize >= 50)
			{
				try
				{
					fontsize = fontsize + 3;
					settings.FontSizeProject = fontsize;
					lblSongText.Font = new Font(settings.FontTypeProject, settings.FontSizeProject, settings.FontBoldProject ? FontStyle.Bold : FontStyle.Regular, GraphicsUnit.Point, ((byte)(0)));
				}
				catch (Exception) {}
			}*/
			break;

		//When Left Arrow Key is Pressed
		case WXK_LEFT:
			
			break;

		//When Right Arrow Key is Pressed
		case WXK_RIGHT:
			this->Close();
			break;

		//When Letter M Key is Pressed
		case WXK_CONTROL_M:
			/*if (apptheme >= 0)
			{
				try
				{
					apptheme = apptheme - 1;
					ThemeView(apptheme);
					settings.Theme = apptheme;
				}
				catch (Exception) {}
			}*/
			break;

		//When Letter N Key is Pressed
		case WXK_CONTROL_N:
			/*if (apptheme <= 8)
			{
				try
				{
					apptheme = apptheme + 1;
					ThemeView(apptheme);
					settings.Theme = apptheme;
				}
				catch (Exception) {}
			}*/
			break;

		//When Letter Z Key is Pressed
		case WXK_CONTROL_Z:
			/*if (fontno >= 0)
			{
				try
				{
					fontno = fontno - 1;
					settings.FontTypeProject = vsbf.fonTxt(fontno);
					lblSongText.Font = new Font(fontxt, fontsize, settings.FontBoldProject ? FontStyle.Bold : FontStyle.Regular, GraphicsUnit.Point, ((byte)(0)));
				}
				catch (Exception) {}
			}*/
			break;
		
		//When Letter X Key is Pressed
		case WXK_CONTROL_X:
			/*if (fontno <= 11)
			{
				try
				{
					fontno = fontno + 1;
					settings.FontTypeProject = vsbf.fonTxt(fontno);
					lblSongText.Font = new Font(fontxt, fontsize, isBold ? FontStyle.Bold : FontStyle.Regular, GraphicsUnit.Point, ((byte)(0)));
				}
				catch (Exception) {}
			}*/
			break;

		//When Number 0/HOme Key is Pressed
		case WXK_NUMPAD0:
		case WXK_HOME:
			//LoadStanza(0);
			break;

		//When Number 1 Key is Pressed
		case WXK_NUMPAD1:
		case WXK_SPECIAL1:
			//LoadStanza(0);
			break;

		//When Number 2 Key is Pressed
		case WXK_NUMPAD2:
		case WXK_SPECIAL2:
			/*if (stanzas >= 2)
			{
				if (hasChorus) LoadStanza(2);
				else if (!hasChorus && stanzas > 2) LoadStanza(1);
			}*/
			break;

		//When Number 3 Key is Pressed
		case WXK_NUMPAD3:
		case WXK_SPECIAL3:
			/*if (stanzas >= 4)
			{
				if (hasChorus) LoadStanza(4);
				else if (!hasChorus && stanzas > 3) LoadStanza(2);
			}*/
			break;

		//When Number 4 Key is Pressed
		case WXK_NUMPAD4:
		case WXK_SPECIAL4:
			/*if (stanzas >= 6)
			{
				if (hasChorus) LoadStanza(6);
				else if (!hasChorus && stanzas > 4) LoadStanza(3);
			}*/
			break;

		case WXK_NUMPAD5:
		case WXK_SPECIAL5:
			/*if (stanzas >= 8)
			{
				if (hasChorus) LoadStanza(8);
				else if (!hasChorus && stanzas > 5) LoadStanza(4);
			}*/
			break;

		//When Number 6 Key is Pressed
		case WXK_NUMPAD6:
		case WXK_SPECIAL6:
			/*if (stanzas >= 10)
			{
				if (hasChorus) LoadStanza(10);
				else if (!hasChorus && stanzas > 6) LoadStanza(5);
			}*/
			break;

		//When Number 7 Key is Pressed
		case WXK_NUMPAD7:
		case WXK_SPECIAL7:
			/*if (stanzas >= 12)
			{
				if (hasChorus) LoadStanza(12);
				else if (!hasChorus && stanzas > 7) LoadStanza(6);
			}*/
			break;

		//When Number 8 Key is Pressed
		case WXK_NUMPAD8:
		case WXK_SPECIAL8:
			/*if (stanzas >= 14)
			{
				if (hasChorus) LoadStanza(14);
				else if (!hasChorus && stanzas > 8) LoadStanza(7);
			}*/
			break;

		//When Number 9 Key is Pressed
		case WXK_NUMPAD9:
		case WXK_SPECIAL9:
			/*if (stanzas >= 16)
			{
				if (hasChorus) LoadStanza(16);
				else if (!hasChorus && stanzas > 9) LoadStanza(8);
			}*/
			break;

		//When Letter C Key is Pressed
		case WXK_CONTROL_C:
			//if (stanzas > 2 && hasChorus) LoadStanza(1);
			break;

		//When End Key is Pressed
		case WXK_END:
			/*if (hasChorus) LoadStanza(stanzas - 2);
			else LoadStanza(stanzas - 1);*/
			break;

		//When Letter V Key is Pressed
		case WXK_CONTROL_V:

			break;

		//When Control B Key is Pressed
		case WXK_CONTROL_B:
			/*try
			{
				if (isBold == true)
				{
					settings.FontBoldProject = false;
					isBold = false;
				}
				else if (isBold == false)
				{
					settings.FontBoldProject = true;
					isBold = true;
				}
				try { lblSongText.Font = new Font(fontxt, fontsize, isBold ? FontStyle.Bold : FontStyle.Regular, GraphicsUnit.Point, ((byte)(0))); }
				catch (Exception) {}
			}
			catch (Exception) {}*/
			break;

		/*case Keys.Oemcomma:
			/*if (fontsize >= 10)
			{
				try
				{
					fontsize = fontsize - 2;
					settings.FontSizeProject = fontsize;
					try { lblSongText.Font = new Font(fontxt, fontsize, settings.FontBoldProject ? FontStyle.Bold : FontStyle.Regular, GraphicsUnit.Point, ((byte)(0))); }
					catch (Exception) {}
				}
				catch (Exception) {}
			}* /
			break;

		case Keys.OemPeriod:
			/*if (fontsize <= 90)
			{
				try
				{
					fontsize = fontsize + 2;
					settings.FontSizeProject = fontsize;
					try { lblSongText.Font = new Font(fontxt, fontsize, settings.FontBoldProject ? FontStyle.Bold : FontStyle.Regular, GraphicsUnit.Point, ((byte)(0))); }
					catch (Exception) {}
				}
				catch (Exception) {}
			}* /
			break;*/
	}
}

void vSongView::TxtCommandLine_MouseWheel(wxMouseEvent&)
{

}
vSongView::~vSongView()
{
	// Disconnect Events
	BtnClose->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(vSongView::BtnClose_Click), NULL, this);

}
