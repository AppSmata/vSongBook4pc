/////////////////////////////////////////////////////////////////////////////
// Name:        vSongView.cpp
// Purpose:     vSongBook for Desktop
// Author:      Jacksiro
// Modified by:
// Created:     27/07/19
// Copyright:   (c) AppSmata
// Licence:     wxWindows licence
/////////////////////////////////////////////////////////////////////////////

#include "vSongView.h"

///////////////////////////////////////////////////////////////////////////

vSongView::vSongView(const wxString& title) : wxFrame(NULL, wxID_ANY, title)
{
	this->SetSizeHints(wxDefaultSize, wxDefaultSize);
	this->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_BTNHIGHLIGHT));

	wxBoxSizer* MainWrapper;
	MainWrapper = new wxBoxSizer(wxVERTICAL);

	wxStaticBoxSizer* GrpMain;
	GrpMain = new wxStaticBoxSizer(new wxStaticBox(this, wxID_ANY, wxT(" vSongBook for Desktop v2.4.1 ")), wxVERTICAL);

	wxBoxSizer* InnerWrapper;
	InnerWrapper = new wxBoxSizer(wxVERTICAL);

	wxBoxSizer* TopPanel;
	TopPanel = new wxBoxSizer(wxHORIZONTAL);
	SetTopPanel(GrpMain, TopPanel);
	InnerWrapper->Add(TopPanel, 0, wxALL | wxEXPAND, 5);

	LineUp = new wxStaticLine(GrpMain->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL);
	InnerWrapper->Add(LineUp, 0, wxEXPAND | wxALL, 5);

	wxStaticBoxSizer* MidPanel;
	MidPanel = new wxStaticBoxSizer(new wxStaticBox(GrpMain->GetStaticBox(), wxID_ANY, wxEmptyString), wxVERTICAL);
	SetMidPanel(MidPanel);
	InnerWrapper->Add(MidPanel, 1, wxALIGN_CENTER | wxALL, 0);

	LineDown = new wxStaticLine(GrpMain->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL);
	InnerWrapper->Add(LineDown, 0, wxEXPAND | wxALL, 5);

	wxBoxSizer* DownPanel;
	DownPanel = new wxBoxSizer(wxHORIZONTAL);
	SetDownPanel(GrpMain, DownPanel);

	InnerWrapper->Add(DownPanel, 0, wxALL | wxEXPAND, 5);

	GrpMain->Add(InnerWrapper, 1, wxEXPAND, 5);


	MainWrapper->Add(GrpMain, 1, wxEXPAND, 5);

	this->SetSizer(MainWrapper);
	this->Layout();

	this->Centre(wxBOTH);
}

void vSongView::SetTopPanel(wxStaticBoxSizer* GrpMain, wxBoxSizer* TopPanel)
{
	LblKey = new wxStaticText(GrpMain->GetStaticBox(), wxID_ANY, wxT("Key"), wxDefaultPosition, wxDefaultSize, 0);
	LblKey->SetFont(wxFont(20, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Trebuchet MS")));
	LblKey->Wrap(-1);
	TopPanel->Add(LblKey, 0, wxALL, 5);

	LblTitle = new wxStaticText(GrpMain->GetStaticBox(), wxID_ANY, wxT("Only Believe"), wxDefaultPosition, wxDefaultSize, 0);
	LblTitle->SetFont(wxFont(25, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Trebuchet MS")));
	LblTitle->Wrap(-1);
	TopPanel->Add(LblTitle, 1, wxALL | wxEXPAND, 5);

	CmdClose = new wxButton(GrpMain->GetStaticBox(), wxID_ANY, wxT("X"), wxDefaultPosition, wxDefaultSize, 0);
	TopPanel->Add(CmdClose, 0, wxALL, 5);
}

void vSongView::SetMidPanel(wxStaticBoxSizer* MidPanel)
{
	LblContent = new wxStaticText(MidPanel->GetStaticBox(), wxID_ANY, wxT("CHORUS\nOnly ieve,"), wxDefaultPosition, wxDefaultSize, 0);
	LblContent->Wrap(-1);
	LblContent->SetFont(wxFont(30, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Trebuchet MS")));

	MidPanel->Add(LblContent, 0, 0, 5);
}

void vSongView::SetDownPanel(wxStaticBoxSizer* GrpMain, wxBoxSizer* DownPanel)
{
	LblNumber = new wxStaticText(GrpMain->GetStaticBox(), wxID_ANY, wxT("MyLabel"), wxDefaultPosition, wxDefaultSize, 0);
	LblNumber->SetFont(wxFont(20, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Trebuchet MS")));
	LblNumber->Wrap(-1);
	DownPanel->Add(LblNumber, 0, wxALL, 5);

	TxtCommand = new wxTextCtrl(GrpMain->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
	DownPanel->Add(TxtCommand, 1, wxALL, 5);

	LblVerse = new wxStaticText(GrpMain->GetStaticBox(), wxID_ANY, wxT("MyLabel"), wxDefaultPosition, wxDefaultSize, 0);
	LblVerse->SetFont(wxFont(20, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Trebuchet MS")));
	LblVerse->Wrap(-1);
	DownPanel->Add(LblVerse, 0, wxALL, 5);

	wxBoxSizer* WrapArrows;
	WrapArrows = new wxBoxSizer(wxHORIZONTAL);

	CmdUp = new wxButton(GrpMain->GetStaticBox(), wxID_ANY, wxT("Up"), wxDefaultPosition, wxDefaultSize, 0);
	WrapArrows->Add(CmdUp, 0, wxALL, 5);

	CmdDown = new wxButton(GrpMain->GetStaticBox(), wxID_ANY, wxT("Down"), wxDefaultPosition, wxDefaultSize, 0);
	WrapArrows->Add(CmdDown, 0, wxALL, 5);
	
	DownPanel->Add(WrapArrows, 0, wxEXPAND, 5);
}

vSongView::~vSongView()
{
}
