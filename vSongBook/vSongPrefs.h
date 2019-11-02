/////////////////////////////////////////////////////////////////////////////
// Name:        vSongPrefs.h
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

class vSongPrefs : public wxFrame
{
private:

protected:
	wxStaticText* LblTitle;
	wxNotebook* TabMain;
	wxScrolledWindow* TabOne;
	wxStaticText* LblTabletMode;
	wxRadioButton* BtnTabletMode;
	wxStaticText* LblTabletMode1;
	wxRadioButton* BtnSearchCriteria;
	wxStaticText* LbLanguage;
	wxComboBox* cmbLanguage;
	wxTextCtrl* TxtUserName;
	wxStaticText* LblUserName;
	wxScrolledWindow* TabTwo;
	wxStaticText* LblSampleText;
	wxStaticText* LblAppFont;
	wxBitmapButton* BtnAppFontSmaller;
	wxSlider* SldAppFont;
	wxBitmapButton* BtnAppFontBigger;
	wxComboBox* cmbAppFont;
	wxRadioButton* BtnAppFont;
	wxStaticText* LblPreview;
	wxTextCtrl* TxtSample;
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
	wxScrolledWindow* TabThree;
	wxButton* BtnTheme;
	wxScrolledWindow* TabFour;
	wxStatusBar* StatusBar;

public:
	vSongPrefs(const wxString& title);

	void PopulateTabOne();
	void PopulateTabTwo();
	void PopulateGrpTextPrefs(wxBoxSizer* grpwrap, const wxString& grplabel);
	void PopulateTabThree();
	void PopulateGrpThemePrefs(wxWrapSizer* WrapThree, int ThemeID, const wxString& GrpLabel, const wxString& GrpColor, vector<int> forecolor, vector<int> backcolor);
	void PopulateTabFour();

	~vSongPrefs();

};

