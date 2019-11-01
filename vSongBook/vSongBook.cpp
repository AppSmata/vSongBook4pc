/////////////////////////////////////////////////////////////////////////////
// Name:        vsongbook.cpp
// Purpose:     vSongBook source
// Author:      Jacksiro
// Created:     25/09/19
// Copyright:   (c) 2019 AppSmata
// Licence:     wxWindows licence
/////////////////////////////////////////////////////////////////////////////

#include "AppSmata.h"
#include "AppSettings.h"
#include "vSongHome.h"
#include "vSongBook.h"

#ifndef wxHAS_IMAGES_IN_RESOURCES
#include "vsbicon.xpm"
#endif

wxBEGIN_EVENT_TABLE(vSongHome, wxFrame)
//EVT_MENU(Minimal_Quit, vSongHome::OnQuit)
//EVT_MENU(Minimal_About, vSongHome::OnAbout)
wxEND_EVENT_TABLE()

wxIMPLEMENT_APP(vSongBook);

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