/////////////////////////////////////////////////////////////////////////////
// Name:        frmProject.h
// Purpose:     vSongBook for Desktop
// Author:      Jacksiro
// Modified by:
// Created:     03/08/19
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
#include <wx/sizer.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/button.h>
#include <wx/statbox.h>
#include <wx/bmpbuttn.h>
#include <wx/statusbr.h>
#include <wx/frame.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class frmProject
///////////////////////////////////////////////////////////////////////////////

class FrmProject : public wxFrame
{
private:

protected:
	
public:

	FrmProject(const wxString& title);

	wxStaticText* lblCorner1;
	wxStaticText* lblKey;
	wxStaticText* lblTitle;
	wxButton* btnClose;
	wxStaticText* lblCorner2;
	wxStaticText* lblSongText;
	wxStaticText* lblCorner3;
	wxStaticText* lblNumber;
	wxStaticText* lblSongBook;
	wxStaticText* lblTitle2;
	wxBitmapButton* btnGoDown;
	wxBitmapButton* btnGoUp;
	wxStaticText* lblCorner4;
	wxStatusBar* StatusBarP;

	void btnClose_Click(wxCommandEvent& event);
	void btnPrevious_Click(wxCommandEvent& event);
	void btnNext_Click(wxCommandEvent& event);

};
