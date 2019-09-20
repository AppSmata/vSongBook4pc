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

#include "FrmSongSearch.h"

enum
{
	Minimal_Quit = wxID_EXIT,
	Minimal_About = wxID_ABOUT
};

class vSongBook : public wxApp
{
public:
	virtual bool OnInit() wxOVERRIDE;

private:	
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
