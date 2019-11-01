/////////////////////////////////////////////////////////////////////////////
// Name:        vSongPrefs.cpp
// Purpose:     vSongBook for Desktop
// Author:      Jacksiro
// Modified by:
// Created:     27/07/19
// Copyright:   (c) AppSmata
// Licence:     wxWindows licence
/////////////////////////////////////////////////////////////////////////////

#include "vSongPrefs.h"

vSongPrefs::vSongPrefs(const wxString& title) : wxFrame(NULL, wxID_ANY, title)
{
	this->SetSizeHints(wxDefaultSize, wxDefaultSize);
	this->SetFont(wxFont(12, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Trebuchet MS")));
	this->SetBackgroundColour(wxColour(255, 255, 255));
	
	wxBoxSizer* MainWarpper;
	MainWarpper = new wxBoxSizer(wxVERTICAL);

	TabMain = new wxNotebook(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0);
	TabMain->SetFont(wxFont(12, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Trebuchet MS")));

	TabOne = new wxScrolledWindow(TabMain, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHSCROLL | wxVSCROLL);
	TabOne->SetScrollRate(5, 5);
	TabOne->SetFont(wxFont(12, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Trebuchet MS")));

	TabMain->AddPage(TabOne, wxT("General Options"), false);
	TabTwo = new wxScrolledWindow(TabMain, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHSCROLL | wxVSCROLL);
	TabTwo->SetScrollRate(5, 5);
	TabTwo->SetFont(wxFont(12, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Trebuchet MS")));

	TabMain->AddPage(TabTwo, wxT("Text Display"), false);
	TabThree = new wxScrolledWindow(TabMain, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHSCROLL | wxVSCROLL);
	TabThree->SetScrollRate(5, 5);
	TabThree->SetFont(wxFont(12, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Trebuchet MS")));

	TabMain->AddPage(TabThree, wxT("Presentation Display"), false);
	TabFour = new wxScrolledWindow(TabMain, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHSCROLL | wxVSCROLL);
	TabFour->SetScrollRate(5, 5);
	TabFour->SetFont(wxFont(12, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Trebuchet MS")));

	TabMain->AddPage(TabFour, wxT("Reset Preferences"), false);

	MainWarpper->Add(TabMain, 1, wxEXPAND | wxALL, 5);


	this->SetSizer(MainWarpper);
	this->Layout();

	this->Centre(wxBOTH);
}

vSongPrefs::~vSongPrefs()
{
}
