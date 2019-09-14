/////////////////////////////////////////////////////////////////////////////
// Name:        frmProject.h
// Purpose:     vSongBook for Desktop
// Author:      Jacksiro
// Modified by:
// Created:     03/08/19
// Copyright:   (c) AppSmata
// Licence:     wxWindows licence
/////////////////////////////////////////////////////////////////////////////
#pragma once

#ifndef __FRMPROJECT_H__
#define __FRMPROJECT_H__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/textctrl.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/stattext.h>
#include <wx/button.h>
#include <wx/sizer.h>
#include <wx/statline.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/bmpbuttn.h>
#include <wx/statbmp.h>
#include <wx/statbox.h>
#include <wx/panel.h>
#include <wx/frame.h>

class FrmProject : public wxFrame
{
private:
	wxDECLARE_EVENT_TABLE();

protected:
	int fcl1;
	int fcl2;
	int fcl3;

	int bcl1;
	int bcl2;
	int bcl3;

	wxBoxSizer* BoxMain;
	wxStaticBoxSizer* BoxGroup;
	wxPanel* PanelMain;
	wxStaticBox* AppLabel;
	wxBoxSizer* BoxWrapper;
	wxBoxSizer* BoxTop;
	wxTextCtrl* TxtCommand;
	wxStaticText* LblKey;
	wxStaticText* LblTitle;
	wxButton* BtnClose;
	wxStaticLine* LineUp;
	wxBoxSizer* BoxMiddle;
	wxStaticText* LblContent;
	wxStaticLine* LineDown;
	wxBoxSizer* BoxBottom;
	wxStaticText* LblSongBook;
	wxStaticText* LblAurthor;
	wxStaticText* LblVerse;
	wxBitmapButton* BtnLast;
	wxBitmapButton* BtnNext;
	wxStaticBitmap* PicLast;
	wxStaticBitmap* PicNext;

public:
	FrmProject(const wxString& title);

};

#endif //__FRMPROJECT_H__
