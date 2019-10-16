/////////////////////////////////////////////////////////////////////////////
// Name:        vSongPrefs.h
// Purpose:     vSongBook for Desktop
// Author:      Jacksiro
// Modified by:
// Created:     03/08/19
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

class vSongPrefs : public wxFrame
{
private:
	//wxDECLARE_EVENT_TABLE();

protected:

	// Virtual event handlers, overide them in your derived class
	void BtnTablet_Click(wxCommandEvent& event) { event.Skip(); }
	void BtnSearch_Click(wxCommandEvent& event) { event.Skip(); }
	void cmbLanguage_Select(wxCommandEvent& event) { event.Skip(); }
	void TxtUsername_Changed(wxCommandEvent& event) { event.Skip(); }
	void BtnAppFontSmaller_Click(wxCommandEvent& event) { event.Skip(); }
	void SldAppFont_Scroll(wxScrollEvent& event) { event.Skip(); }
	void BtnAppFontBigger_Click(wxCommandEvent& event) { event.Skip(); }
	void CmbAppFont_Selected(wxCommandEvent& event) { event.Skip(); }
	void BtnAppFont_Click(wxCommandEvent& event) { event.Skip(); }
	void BtnThemOne_Click(wxCommandEvent& event) { event.Skip(); }


public:
	wxStaticText* LblTitle;
	wxNotebook* tabMain;
	wxScrolledWindow* TabGeneral;
	wxStaticText* LblTabletMode;
	wxRadioButton* BtnTabletMode;
	wxStaticText* LblTabletMode1;
	wxRadioButton* BtnSearchCriteria;
	wxStaticText* LbLanguage;
	wxComboBox* cmbLanguage;
	wxTextCtrl* TxtUserName;
	wxStaticText* LblUserName;
	wxScrolledWindow* TabFonts;
	wxStaticText* LblSampleText;
	wxStaticText* LblAppFont;
	wxBitmapButton* BtnAppFontSmaller;
	wxSlider* SldAppFont;
	wxBitmapButton* BtnAppFontBigger;
	wxComboBox* cmbAppFont;
	wxRadioButton* BtnAppFont;
	wxStaticText* LblPreview;
	wxBitmapButton* BtnPreviewSmaller;
	wxSlider* SldPreview;
	wxBitmapButton* BtnPreviewBigger;
	wxComboBox* cmbPreview;
	wxRadioButton* BtnPreview;
	wxStaticText* LblProjection;
	wxBitmapButton* BtnProjectionSmaller;
	wxSlider* SldProjection;
	wxBitmapButton* BtnProjectionBigger;
	wxComboBox* cmbProjection;
	wxRadioButton* BtnProjection;
	wxScrolledWindow* TabTheme;
	wxButton* BtnTheme0;
	wxButton* BtnTheme1;
	wxButton* BtnTheme2;
	wxButton* BtnTheme3;
	wxButton* BtnTheme4;
	wxButton* BtnTheme5;
	wxButton* BtnTheme6;
	wxButton* BtnTheme7;
	wxButton* BtnTheme8;
	wxButton* BtnTheme9;
	wxScrolledWindow* TabReset;
	wxStatusBar* StatusBar;

	vSongPrefs(const wxString& title);

};
