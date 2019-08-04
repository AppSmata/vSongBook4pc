/////////////////////////////////////////////////////////////////////////////
// Name:        FrmSettings.h
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

class FrmSettings : public wxFrame
{
private:

protected:

	// Virtual event handlers, overide them in your derived class
	virtual void BtnTablet_Click(wxCommandEvent& event) { event.Skip(); }
	virtual void BtnSearch_Click(wxCommandEvent& event) { event.Skip(); }
	virtual void cmbLanguage_Select(wxCommandEvent& event) { event.Skip(); }
	virtual void TxtUsername_Changed(wxCommandEvent& event) { event.Skip(); }
	virtual void BtnAppFontSmaller_Click(wxCommandEvent& event) { event.Skip(); }
	virtual void SldAppFont_Scroll(wxScrollEvent& event) { event.Skip(); }
	virtual void BtnAppFontBigger_Click(wxCommandEvent& event) { event.Skip(); }
	virtual void CmbAppFont_Selected(wxCommandEvent& event) { event.Skip(); }
	virtual void BtnAppFont_Click(wxCommandEvent& event) { event.Skip(); }
	virtual void BtnThemOne_Click(wxCommandEvent& event) { event.Skip(); }


public:

	FrmSettings(const wxString& title);

	~FrmSettings();

};
