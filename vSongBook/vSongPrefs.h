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
protected:
	wxStaticText* LblTitle;
	wxNotebook* TabMain;

	wxScrolledWindow* TabOne;

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


	wxScrolledWindow* TabTwo;

	wxStaticBox* LblSampleGrp;
	wxStaticText* LblSampleText;
	wxTextCtrl* TxtSample;

	wxStaticBox* LblGeneralGrp;
	wxStaticText* LblGeneral;
	wxBitmapButton* BtnGeneralSmaller;
	wxSlider* SldGeneral;
	wxBitmapButton* BtnGeneralBigger;
	wxComboBox* CmbGeneral;
	wxRadioButton* BtnGeneral;

	wxStaticBox* LblPreviewGrp;
	wxStaticText* LblPreview;	
	wxBitmapButton* BtnPreviewSmaller;
	wxSlider* SldPreview;
	wxBitmapButton* BtnPreviewBigger;
	wxComboBox* CmbPreview;
	wxRadioButton* BtnPreview;

	wxStaticBox* LblProjectionGrp;
	wxStaticText* LblProjection;
	wxBitmapButton* BtnProjectionSmaller;
	wxSlider* SldProjection;
	wxBitmapButton* BtnProjectionBigger;
	wxComboBox* CmbProjection;
	wxRadioButton* BtnProjection;

	wxScrolledWindow* TabThree;
	wxButton* BtnTheme;

	wxScrolledWindow* TabFour;
	wxStatusBar* StatusBar;

public:
	vSongPrefs(const wxString& title);

	void PopulateTabOne();
	void PopulateTabTwo();

	void PopulateGrpGeneral(wxBoxSizer* grpwrap);
	void PopulateGrpPreview(wxBoxSizer* grpwrap);
	void PopulateGrpProjection(wxBoxSizer* grpwrap);

	void PopulateGrpTextPrefs(wxBoxSizer* grpwrap, const wxString& grplabel);
	void PopulateTabThree();
	void PopulateGrpThemePrefs(wxWrapSizer* WrapThree, int ThemeID, const wxString& GrpLabel, const wxString& GrpColor, vector<int> forecolor, vector<int> backcolor);
	void PopulateTabFour();

	void BtnTabletMode_Click(wxCommandEvent& event);
	void BtnSearchCriteria_Click(wxCommandEvent& event);
	void CmbLanguage_SelectionChange(wxCommandEvent& event);
	void TxtUserName_TextChange(wxCommandEvent& event);

	void CmbGeneral_SelectionChange(wxCommandEvent& event);
	void CmbProjection_SelectionChange(wxCommandEvent& event);
	void CmbPreview_SelectionChange(wxCommandEvent& event);

	void SldGeneral_OnScroll(wxScrollEvent& event);
	void SldProjection_OnScroll(wxScrollEvent& event);
	void SldPreview_OnScroll(wxScrollEvent& event);

	void GetSettings();
	void InitializeSettings();
	void GetLanguages(wxString Language);
	void InitializeLanguage();

	~vSongPrefs();

};

