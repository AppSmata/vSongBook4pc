/////////////////////////////////////////////////////////////////////////////
// Name:        vSongView.h
// Purpose:     vSongBook for Desktop
// Author:      Jacksiro
// Modified by:
// Created:     27/07/19
// Copyright:   (c) AppSmata
// Licence:     wxWindows licence
/////////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/button.h>
#include <wx/sizer.h>
#include <wx/statline.h>
#include <wx/statbox.h>
#include <wx/textctrl.h>
#include <wx/frame.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class vSongView
///////////////////////////////////////////////////////////////////////////////
class vSongView : public wxFrame
{
private:
	//wxDECLARE_EVENT_TABLE();

protected:
	wxStaticBox* AppLabel;
	wxStaticText* LblKey;
	wxStaticText* LblTitle;
	wxTextCtrl* TxtCommand;
	wxButton* BtnClose;
	wxStaticLine* LineUp;
	wxStaticText* LblContent;
	wxStaticLine* LineDown;
	wxStaticText* LblSongInfo;
	wxStaticText* LblAuthor;
	wxStaticText* LblVerse;
	wxBitmapButton* BtnLast;
	wxBitmapButton* BtnNext;
	wxStaticBitmap* PicLast;
	wxStaticBitmap* PicLastNull;
	wxStaticBitmap* PicNext;
	wxStaticBitmap* PicNextNull;
	void BtnClose_Click(wxCommandEvent& event);
	void TxtCommandLine_KeyDown(wxKeyEvent& event);
	void TxtCommandLine_MouseWheel(wxMouseEvent& event);
	void Anywhere_Click(wxCommandEvent& event);

public:
	vSongView(const wxString& title);


	void SetTopPanel(wxStaticBoxSizer* GrpMain, wxBoxSizer* TopPanel);
	void SetMidPanel(wxStaticBoxSizer* GrpMain, wxBoxSizer* MidPanel);
	void SetDownPanel(wxStaticBoxSizer* GrpMain, wxBoxSizer* DownPanel);

	void PresentSong(wxString setsong);
	void GetSettings();
	void SetPresentation();

	~vSongView();

};

