/////////////////////////////////////////////////////////////////////////////
// Name:        vSongBook.cpp
// Purpose:     vSongBook for Desktop
// Author:      Jacksiro
// Modified by:
// Created:     27/07/19
// Copyright:   (c) AppSmata
// Licence:     wxWindows licence
/////////////////////////////////////////////////////////////////////////////

#ifdef __BORLANDC__
#pragma hdrstop
#endif

#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

#include "wx/preferences.h"
#include "wx/config.h"

#include "FrmSongSearch.h"

enum
{
	Minimal_Quit = wxID_EXIT,
	Minimal_About = wxID_ABOUT
};

wxScopedPtr<wxPreferencesEditor> _prefEditor;

class vSongBook : public wxApp
{
public:
	virtual bool OnInit() wxOVERRIDE;

private:
	wxScopedPtr<wxPreferencesEditor> _prefEditor;	
};

wxBEGIN_EVENT_TABLE(FrmSongSearch, wxFrame)
//EVT_MENU(Minimal_Quit, FrmSongSearch::OnQuit)
//EVT_MENU(Minimal_About, FrmSongSearch::OnAbout)
wxEND_EVENT_TABLE()

wxIMPLEMENT_APP(vSongBook);

bool vSongBook::OnInit()
{
	if (!wxApp::OnInit())
		return false;

	FrmSongSearch*frmSongSearch = new FrmSongSearch("vSongBook");

	frmSongSearch->SetSize(1000, 700);
	frmSongSearch->Show(true);
	frmSongSearch->Center();
	frmSongSearch->Maximize(true);
	return true;
}
