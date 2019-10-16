#include "wx/wxprec.h"

#ifdef __BORLANDC__
#pragma hdrstop
#endif

#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

#include "wx/imaglist.h"
#include "wx/artprov.h"
#include "wx/cshelp.h"
#include "wx/utils.h"

#include "vSongBook.h"
#include "vSongView.h"

using namespace std;

int this_book, this_song;
vector<wxString> songverses;

wxBEGIN_EVENT_TABLE(vSongView, wxFrame)
//EVT_MENU(Minimal_Quit, vSongHome::OnQuit)
//EVT_MENU(Minimal_About, vSongHome::OnAbout)
wxEND_EVENT_TABLE()

vSongView::vSongView(const wxString& title) : wxFrame(NULL, wxID_ANY, title)
{
	enum
	{
		Button_blackwhite_down,
		Button_blackwhite_up,
		Button_max
	};

	wxBitmap ButtonBitmaps[Button_max];

	fcl1 = 255;
	fcl2 = 255;
	fcl3 = 255;

	bcl1 = 0;
	bcl2 = 0;
	bcl3 = 0;

#if USE_XPM_BITMAPS
#define INIT_BTN_BMP(bmp) \
        ButtonBitmaps[Button_##bmp] = wxBitmap(bmp##_xpm)
#else // !USE_XPM_BITMAPS
#define INIT_BTN_BMP(bmp) \
        ButtonBitmaps[Button_##bmp] = wxBITMAP(bmp)
#endif // USE_XPM_BITMAPS/!USE_XPM_BITMAPS

	INIT_BTN_BMP(blackwhite_down);
	INIT_BTN_BMP(blackwhite_up);

	this->SetSizeHints(wxDefaultSize, wxDefaultSize);
	this->SetFont(wxFont(12, 75, 90, 92, false, wxT("Trebuchet MS")));
	this->SetBackgroundColour(wxColour(bcl1, bcl2, bcl3));

	BoxMain = new wxBoxSizer(wxVERTICAL);

	PanelMain = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
	AppLabel = new wxStaticBox(PanelMain, wxID_ANY, wxT(" vSongBook for Desktop v2.4.1"));
	AppLabel->SetForegroundColour(wxColour(fcl1, fcl2, fcl3));

	BoxGroup = new wxStaticBoxSizer(AppLabel, wxVERTICAL);

	BoxWrapper = new wxBoxSizer(wxVERTICAL);

	BoxTop = new wxBoxSizer(wxHORIZONTAL);

	TxtCommand = new wxTextCtrl(BoxGroup->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(50, -1), 0);
	TxtCommand->Hide();

	BoxTop->Add(TxtCommand, 1, wxALIGN_CENTER | wxALL, 5);

	LblKey = new wxStaticText(BoxGroup->GetStaticBox(), wxID_ANY, wxT("Key:"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE);
	LblKey->Wrap(-1);
	LblKey->SetFont(wxFont(20, 75, 90, 92, false, wxT("Trebuchet MS")));
	LblKey->SetForegroundColour(wxColour(fcl1, fcl2, fcl3));

	BoxTop->Add(LblKey, 0, wxALIGN_CENTER | wxALL, 5);

	LblTitle = new wxStaticText(BoxGroup->GetStaticBox(), wxID_ANY, wxT("1# Only Believe"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE);
	LblTitle->Wrap(-1);
	LblTitle->SetFont(wxFont(20, 75, 90, 92, false, wxT("Trebuchet MS")));
	LblTitle->SetForegroundColour(wxColour(fcl1, fcl2, fcl3));

	BoxTop->Add(LblTitle, 1, wxALL, 5);

	BtnClose = new wxButton(BoxGroup->GetStaticBox(), wxID_ANY, wxT("X"), wxDefaultPosition, wxSize(50, -1), 0);
	BoxTop->Add(BtnClose, 0, wxALIGN_CENTER | wxALL, 5);


	BoxWrapper->Add(BoxTop, 0, wxEXPAND, 5);

	LineUp = new wxStaticLine(BoxGroup->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL);
	LineUp->SetBackgroundColour(wxColour(0, 0, 0));

	BoxWrapper->Add(LineUp, 0, wxEXPAND | wxALL, 5);

	BoxMiddle = new wxBoxSizer(wxHORIZONTAL);

	LblContent = new wxStaticText(BoxGroup->GetStaticBox(), wxID_ANY, wxT("Only believe, only believe,\nAll things are possible,\nOnly believe, Only believe,\nonly believe,\nAll things are possible,\nonly believe."), wxDefaultPosition, wxDefaultSize, 0);
	LblContent->Wrap(-1);
	LblContent->SetFont(wxFont(30, 75, 90, 92, false, wxT("Trebuchet MS")));
	LblContent->SetForegroundColour(wxColour(fcl1, fcl2, fcl3));

	BoxMiddle->Add(LblContent, 1, wxALIGN_CENTER | wxALL, 0);


	BoxWrapper->Add(BoxMiddle, 1, wxALIGN_CENTER | wxALL, 5);

	LineDown = new wxStaticLine(BoxGroup->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL);
	LineDown->SetBackgroundColour(wxColour(0, 0, 0));

	BoxWrapper->Add(LineDown, 0, wxEXPAND | wxALL, 5);

	BoxBottom = new wxBoxSizer(wxHORIZONTAL);

	LblSongBook = new wxStaticText(BoxGroup->GetStaticBox(), wxID_ANY, wxT("Songs of Worship"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE);
	LblSongBook->Wrap(-1);
	LblSongBook->SetFont(wxFont(20, 75, 90, 92, false, wxT("Trebuchet MS")));
	LblSongBook->SetForegroundColour(wxColour(fcl1, fcl2, fcl3));

	BoxBottom->Add(LblSongBook, 1, wxALIGN_CENTER | wxALL, 5);

	LblAurthor = new wxStaticText(BoxGroup->GetStaticBox(), wxID_ANY, wxT("Public Domain"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE);
	LblAurthor->Wrap(-1);
	LblAurthor->SetFont(wxFont(20, 75, 90, 92, false, wxT("Trebuchet MS")));
	LblAurthor->SetForegroundColour(wxColour(fcl1, fcl2, fcl3));

	BoxBottom->Add(LblAurthor, 1, wxALIGN_CENTER | wxALL, 5);

	LblVerse = new wxStaticText(BoxGroup->GetStaticBox(), wxID_ANY, wxT("Verse 1/3"), wxDefaultPosition, wxDefaultSize, 0);
	LblVerse->Wrap(-1);
	LblVerse->SetFont(wxFont(20, 75, 90, 92, false, wxT("Trebuchet MS")));
	LblVerse->SetForegroundColour(wxColour(fcl1, fcl2, fcl3));

	BoxBottom->Add(LblVerse, 0, wxALIGN_CENTER | wxALL, 5);

	BtnLast = new wxBitmapButton(BoxGroup->GetStaticBox(), wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW);
	BtnLast->SetBitmap(wxBitmap(ButtonBitmaps[Button_blackwhite_up]));
	BtnLast->SetBackgroundColour(wxColour(bcl1, bcl2, bcl3));
	BoxBottom->Add(BtnLast, 0, wxALIGN_CENTER | wxALL, 5);

	BtnNext = new wxBitmapButton(BoxGroup->GetStaticBox(), wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW);
	BtnNext->SetBitmap(wxBitmap(ButtonBitmaps[Button_blackwhite_down]));
	BtnNext->SetBackgroundColour(wxColour(bcl1, bcl2, bcl3));
	BoxBottom->Add(BtnNext, 0, wxALIGN_CENTER | wxALL, 5);

	PicLast = new wxStaticBitmap(BoxGroup->GetStaticBox(), wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, 0);
	PicLast->SetBitmap(wxBitmap(ButtonBitmaps[Button_blackwhite_up]));
	PicLast->SetBackgroundColour(wxColour(bcl1, bcl2, bcl3));
	BoxBottom->Add(PicLast, 0, wxALIGN_CENTER | wxALL, 0);

	PicNext = new wxStaticBitmap(BoxGroup->GetStaticBox(), wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, 0);
	PicNext->SetBitmap(wxBitmap(ButtonBitmaps[Button_blackwhite_down]));
	PicNext->SetBackgroundColour(wxColour(bcl1, bcl2, bcl3));
	BoxBottom->Add(PicNext, 0, wxALIGN_CENTER | wxALL, 5);

	BoxWrapper->Add(BoxBottom, 0, wxEXPAND, 5);

	BoxGroup->Add(BoxWrapper, 1, wxEXPAND, 5);

	PanelMain->SetSizer(BoxGroup);
	PanelMain->Layout();
	BoxGroup->Fit(PanelMain);
	BoxMain->Add(PanelMain, 1, wxEXPAND | wxALL, 5);

	this->SetSizer(BoxMain);
	this->Layout();

	this->Centre(wxBOTH);
}