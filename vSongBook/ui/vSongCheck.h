/////////////////////////////////////////////////////////////////////////////
// Name:        vSongCheck.h
// Purpose:     vSongBook for Desktop
// Author:      Jacksiro
// Modified by:
// Created:     27/07/19
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
#include <wx/radiobut.h>
#include <wx/statbox.h>
#include <wx/combobox.h>
#include <wx/textctrl.h>
#include <wx/scrolwin.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/bmpbuttn.h>
#include <wx/button.h>
#include <wx/slider.h>
#include <wx/wrapsizer.h>
#include <wx/notebook.h>
#include <wx/statusbr.h>
#include <wx/frame.h>

#include <vector>

using namespace std;

class vSongCheck : public wxFrame
{
protected:
	wxStaticText* LblTitle;
	wxStaticBox* LblTabletGrp;
	wxStaticText* LblTabletMode;
	wxRadioButton* BtnTabletMode;
	wxStaticBox* LblSearchGrp;
	wxStaticText* LblSearchCriteria;
	wxRadioButton* BtnSearchCriteria;
	wxStaticBox* LbLanguageGrp;
	wxStaticText* LbLanguage;
	wxComboBox* CmbLanguage;
	wxTextCtrl* TxtUserName;
	wxStaticBox* LblUserNameGrp;
	wxStaticText* LblUserName;
	wxStatusBar* StatusBar;
	wxButton* BtnSave;
	wxButton* BtnCancel;

public:
	vSongCheck(const wxString& title);

	void BtnTabletMode_Click(wxCommandEvent& event);
	void BtnSearchCriteria_Click(wxCommandEvent& event);
	void CmbLanguage_SelectionChange(wxCommandEvent& event);
	void TxtUserName_TextChange(wxCommandEvent& event);
	void BtnSave_Click(wxCommandEvent& event);
	void BtnCancel_Click(wxCommandEvent& event);

	void QuickSettings(wxBoxSizer* MainWrapper);

	void GetSettings();
	void InitializeSettings();
	void GetLanguages(wxString Language);
	void InitializeLanguage();

	~vSongCheck();

};

