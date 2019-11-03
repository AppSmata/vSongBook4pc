/////////////////////////////////////////////////////////////////////////////
// Name:        vSongBook.cpp
// Purpose:     vSongBook source
// Author:      Jacksiro
// Created:     25/09/19
// Copyright:   (c) 2019 AppSmata
// Licence:     wxWindows licence
/////////////////////////////////////////////////////////////////////////////

#include "AppSmata.h"
#include "AppSettings.h"
#include "vSongHome.h"
#include "vSongView.h"
#include "vSongBook.h"

wxIMPLEMENT_APP(vSongBook);

wxBEGIN_EVENT_TABLE(vSongBook, wxApp)
	EVT_MENU(wxID_EXIT, vSongHome::OnQuit)
	EVT_MENU(wxID_ABOUT, vSongHome::OnAbout)
wxEND_EVENT_TABLE()


bool vSongBook::OnInit()
{
	if (!wxApp::OnInit()) return false;

	const AppSettings::Preferences& _pref = wxGetApp().GetSettings();

	vSongHome* home = new vSongHome("vSongBook for Desktop!");//("vSongBook v" + _pref.vsb_version + " | " + _pref.app_user);
	home->SetSize(1000, 700);
	home->Show(true);
	home->Center();
	home->Maximize(true);

	return true;
}