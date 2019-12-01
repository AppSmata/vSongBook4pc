/////////////////////////////////////////////////////////////////////////////
// Name:        AppSplash.cpp
// Purpose:     vSongBook for Desktop
// Author:      Jacksiro
// Modified by:
// Created:     27/07/19
// Copyright:   (c) AppSmata
// Licence:     wxWindows licence
/////////////////////////////////////////////////////////////////////////////

#include "AppSplash.h"
enum
{
	Button_bigger,
	Button_smaller,
	Button_max
};

AppSplash::AppSplash(const wxString& title) : wxFrame(NULL, wxID_ANY, title)
{
	this->SetSizeHints(wxDefaultSize, wxDefaultSize);

	wxBoxSizer* MainWrapper;
	MainWrapper = new wxBoxSizer(wxVERTICAL);

	ImgSplash = new wxStaticBitmap(this, wxID_ANY, wxBitmap(wxT("res/splash.bmp"), wxBITMAP_TYPE_ANY), wxDefaultPosition, wxSize(-1, -1), 0);
	MainWrapper->Add(ImgSplash, 1, wxALIGN_CENTER | wxALL, 0);


	this->SetSizer(MainWrapper);
	this->Layout();

	this->Centre(wxBOTH);
}


AppSplash::~AppSplash()
{
}
