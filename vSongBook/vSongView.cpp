/////////////////////////////////////////////////////////////////////////////
// Name:        vSongView.cpp
// Purpose:     vSongBook for Desktop
// Author:      Jacksiro
// Modified by:
// Created:     27/07/19
// Copyright:   (c) AppSmata
// Licence:     wxWindows licence
/////////////////////////////////////////////////////////////////////////////

#include <wx\tokenzr.h>
#include "AppSmata.h"
#include "vSongView.h"

///////////////////////////////////////////////////////////////////////////

int this_book, this_song, slides, slideno, slideindex;
wxString setsong, bookid, songid, number, title, alias, content, key, author, book, chorus, slide;
vector<wxString> songverses1, songverses2;
bool haschorus;

vSongView::vSongView(const wxString& title) : wxFrame(NULL, wxID_ANY, title)
{
	this->SetSizeHints(wxDefaultSize, wxDefaultSize);
	this->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_BTNHIGHLIGHT));

	wxBoxSizer* MainWrapper;
	MainWrapper = new wxBoxSizer(wxVERTICAL);

	PanelMain = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
	AppLabel = new wxStaticBox(PanelMain, wxID_ANY, wxT(" vSongBook for Desktop v2.4.1 "));

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
	LblVerse->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(vSongView::Anywhere_Click), NULL, this);
	//PicLast->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(vSongView::Anywhere_Click), NULL, this);
	//PicNext->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(vSongView::Anywhere_Click), NULL, this);

	BtnClose->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(vSongView::BtnClose_Click), NULL, this);

	TxtCommand->Connect(wxEVT_KEY_DOWN, wxKeyEventHandler(vSongView::TxtCommandLine_KeyDown), NULL, this);
	TxtCommand->Connect(wxEVT_MOUSEWHEEL, wxMouseEventHandler(vSongView::TxtCommandLine_MouseWheel), NULL, this);

	//BtnLast->Hide();
	//BtnNext->Hide();
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

	BtnClose = new wxButton(GrpMain->GetStaticBox(), wxID_ANY, wxT("X"), wxDefaultPosition, wxSize(40, -1), 0);
	BtnClose->SetFont(wxFont(12, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Trebuchet MS")));

	TopPanel->Add(BtnClose, 0, wxALL | wxEXPAND, 5);

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
	LblNumber = new wxStaticText(GrpMain->GetStaticBox(), wxID_ANY, wxT("MyLabel"), wxDefaultPosition, wxDefaultSize, 0);
	LblNumber->SetFont(wxFont(20, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Trebuchet MS")));
	LblNumber->Wrap(-1);
	DownPanel->Add(LblNumber, 0, wxALL, 5);

	TxtCommand = new wxTextCtrl(GrpMain->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
	DownPanel->Add(TxtCommand, 1, wxALL, 5);

	LblVerse = new wxStaticText(GrpMain->GetStaticBox(), wxID_ANY, wxT("MyLabel"), wxDefaultPosition, wxDefaultSize, 0);
	LblVerse->SetFont(wxFont(20, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Trebuchet MS")));
	LblVerse->Wrap(-1);
	DownPanel->Add(LblVerse, 0, wxALL, 5);

	wxBoxSizer* WrapArrows;
	WrapArrows = new wxBoxSizer(wxHORIZONTAL);

	BtnUp = new wxButton(GrpMain->GetStaticBox(), wxID_ANY, wxT("Up"), wxDefaultPosition, wxDefaultSize, 0);
	WrapArrows->Add(BtnUp, 0, wxALL, 5);

	BtnDown = new wxButton(GrpMain->GetStaticBox(), wxID_ANY, wxT("Down"), wxDefaultPosition, wxDefaultSize, 0);
	WrapArrows->Add(BtnDown, 0, wxALL, 5);
	
	DownPanel->Add(WrapArrows, 0, wxEXPAND, 5);

	BtnClose->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(vSongView::BtnClose_Click), NULL, this);
}

void vSongView::BtnClose_Click(wxCommandEvent&)
{
	this->Close();
}

void vSongView::Anywhere_Click(wxCommandEvent&)
{
	TxtCommand->SetFocus();
}

void vSongView::TxtCommandLine_KeyDown(wxKeyEvent& event)
{
	switch (event.GetKeyCode())
	{
	case WXK_ESCAPE:
		this->Close();
		break;

	case WXK_UP:
		/*try
		{
			if (slideindex != 0)
			{
				slideindex = slideindex - 1;
				SetProjection();
			}
		}
		catch (exception & ex) {}*/
		break;

	case WXK_DOWN:
		/*try
		{
			if (slideindex != (slides - 1))
			{
				slideindex = slideindex + 1;
				SetProjection();
			}
		}
		catch (exception & ex) {}*/
		break;

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

	case WXK_LEFT:

		break;

	case WXK_RIGHT:

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
	case WXK_NUMPAD0:
	case WXK_HOME:
		//LoadStanza(0);
		break;

	case WXK_NUMPAD1:
	case WXK_SPECIAL1:
		//LoadStanza(0);
		break;

	case WXK_NUMPAD2:
	case WXK_SPECIAL2:
		/*if (stanzas >= 2)
		{
			if (hasChorus) LoadStanza(2);
			else if (!hasChorus && stanzas > 2) LoadStanza(1);
		}*/
		break;

	case WXK_NUMPAD3:
	case WXK_SPECIAL3:
		/*if (stanzas >= 4)
		{
			if (hasChorus) LoadStanza(4);
			else if (!hasChorus && stanzas > 3) LoadStanza(2);
		}*/
		break;

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

	case WXK_NUMPAD6:
	case WXK_SPECIAL6:
		/*if (stanzas >= 10)
		{
			if (hasChorus) LoadStanza(10);
			else if (!hasChorus && stanzas > 6) LoadStanza(5);
		}*/
		break;

	case WXK_NUMPAD7:
	case WXK_SPECIAL7:
		/*if (stanzas >= 12)
		{
			if (hasChorus) LoadStanza(12);
			else if (!hasChorus && stanzas > 7) LoadStanza(6);
		}*/
		break;

	case WXK_NUMPAD8:
	case WXK_SPECIAL8:
		/*if (stanzas >= 14)
		{
			if (hasChorus) LoadStanza(14);
			else if (!hasChorus && stanzas > 8) LoadStanza(7);
		}*/
		break;

	case WXK_NUMPAD9:
	case WXK_SPECIAL9:
		/*if (stanzas >= 16)
		{
			if (hasChorus) LoadStanza(16);
			else if (!hasChorus && stanzas > 9) LoadStanza(8);
		}*/
		break;

	case WXK_CONTROL_C:
		//if (stanzas > 2 && hasChorus) LoadStanza(1);
		break;

	case WXK_END:
		/*if (hasChorus) LoadStanza(stanzas - 2);
		else LoadStanza(stanzas - 1);*/
		break;

	case WXK_CONTROL_V:

		break;

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
