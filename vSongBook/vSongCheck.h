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
	wxNotebook* TabMain;
	wxStaticText* LblTabletMode;
	wxRadioButton* BtnTabletMode;
	wxStaticText* LblTabletMode1;
	wxRadioButton* BtnSearchCriteria;
	wxStaticText* LbLanguage;
	wxComboBox* cmbLanguage;
	wxTextCtrl* TxtUserName;
	wxStaticText* LblUserName;
	wxStatusBar* StatusBar;
	wxStdDialogButtonSizer* okCancel;
	wxButton* okCancelSave;
	wxButton* okCancelCancel;

public:
	vSongCheck(const wxString& title);

	void QuickSettings(wxBoxSizer* MainWrapper);
	void BtnCancel_Click(wxCommandEvent& event);
	void BtnSave_Click(wxCommandEvent& event);

	~vSongCheck();

};

