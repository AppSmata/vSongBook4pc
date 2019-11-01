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
#include <wx/radiobut.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/sizer.h>
#include <wx/statbox.h>
#include <wx/scrolwin.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/notebook.h>
#include <wx/frame.h>

class vSongPrefs : public wxFrame
{
private:

protected:
	wxNotebook* TabMain;
	wxScrolledWindow* TabOne;
	wxRadioButton* BtnTablet;
	wxScrolledWindow* TabTwo;
	wxScrolledWindow* TabThree;
	wxScrolledWindow* TabFour;

public:

	vSongPrefs(const wxString& title);

	~vSongPrefs();

};

