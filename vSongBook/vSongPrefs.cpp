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
	
	wxBoxSizer* MainWrapper;
	MainWrapper = new wxBoxSizer(wxVERTICAL);

	TabMain = new wxNotebook(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0);
	TabMain->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOW));

	TabOne = new wxScrolledWindow(TabMain, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHSCROLL | wxVSCROLL);
	TabOne->SetScrollRate(5, 5);
	TabOne->SetFont(wxFont(12, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Trebuchet MS")));

	wxBoxSizer* WrapOne;
	WrapOne = new wxBoxSizer(wxVERTICAL);

	wxStaticBoxSizer* GrpTablet;
	GrpTablet = new wxStaticBoxSizer(new wxStaticBox(TabOne, wxID_ANY, wxT("label")), wxVERTICAL);

	BtnTablet = new wxRadioButton(GrpTablet->GetStaticBox(), wxID_ANY, wxT("RadioBtn"), wxDefaultPosition, wxDefaultSize, 0);
	GrpTablet->Add(BtnTablet, 0, wxALL, 5);


	WrapOne->Add(GrpTablet, 1, wxEXPAND, 5);

	wxStaticBoxSizer* GrpSearch;
	GrpSearch = new wxStaticBoxSizer(new wxStaticBox(TabOne, wxID_ANY, wxT("label")), wxVERTICAL);


	WrapOne->Add(GrpSearch, 1, wxEXPAND, 5);


	TabOne->SetSizer(WrapOne);
	TabOne->Layout();
	WrapOne->Fit(TabOne);
	TabMain->AddPage(TabOne, wxT("General Preferences"), true);
	TabTwo = new wxScrolledWindow(TabMain, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHSCROLL | wxVSCROLL);
	TabTwo->SetScrollRate(5, 5);
	TabTwo->SetFont(wxFont(12, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Trebuchet MS")));

	TabMain->AddPage(TabTwo, wxT("Text Preferences"), false);
	TabThree = new wxScrolledWindow(TabMain, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHSCROLL | wxVSCROLL);
	TabThree->SetScrollRate(5, 5);
	TabThree->SetFont(wxFont(12, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Trebuchet MS")));

	TabMain->AddPage(TabThree, wxT("Presentation Preferences"), false);
	TabFour = new wxScrolledWindow(TabMain, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHSCROLL | wxVSCROLL);
	TabFour->SetScrollRate(5, 5);
	TabFour->SetFont(wxFont(12, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Trebuchet MS")));

	TabMain->AddPage(TabFour, wxT("Reset Preferences"), false);

	MainWrapper->Add(TabMain, 1, wxEXPAND | wxALL, 5);


	this->SetSizer(MainWrapper);
	this->Layout();

	this->Centre(wxBOTH);
}

vSongPrefs::~vSongPrefs()
{
}
