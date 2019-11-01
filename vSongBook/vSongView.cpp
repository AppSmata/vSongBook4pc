/////////////////////////////////////////////////////////////////////////////
// Name:        vSongView.cpp
// Purpose:     vSongBook for Desktop
// Author:      Jacksiro
// Modified by:
// Created:     27/07/19
// Copyright:   (c) AppSmata
// Licence:     wxWindows licence
/////////////////////////////////////////////////////////////////////////////

#include "AppSmata.h"
#include "AppSettings.h"
#include "vSongView.h"

int this_book, this_song;
vector<wxString> songverses;

wxBEGIN_EVENT_TABLE(vSongView, wxFrame)
//EVT_MENU(Minimal_Quit, vSongHome::OnQuit)
//EVT_MENU(Minimal_About, vSongHome::OnAbout)
wxEND_EVENT_TABLE()

vSongView::vSongView(const wxString& title) : wxFrame(NULL, wxID_ANY, title)
{
	SetIcon(wxICON(vsbicon));

}