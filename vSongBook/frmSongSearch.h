/////////////////////////////////////////////////////////////////////////////
// Name:        FrmSongSearch.h
// Purpose:     vSongBook for Desktop
// Author:      Jacksiro
// Modified by:
// Created:     27/07/19
// Copyright:   (c) AppSmata
// Licence:     wxWindows licence
/////////////////////////////////////////////////////////////////////////////

#include "wx/wx.h"
#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/combobox.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/checkbox.h>
#include <wx/listbox.h>
#include <wx/sizer.h>
#include <wx/statbox.h>
#include <wx/panel.h>
#include <wx/srchctrl.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/toolbar.h>
#include <wx/textctrl.h>
#include <wx/splitter.h>
#include <wx/frame.h>

#include "FrmProject.h"

class FrmSongSearch : public wxFrame
{
private:
	wxDECLARE_EVENT_TABLE();

protected:
	wxSplitterWindow* WndSplitter;

	bool m_smallToolbar, m_horzText, m_useCustomDisabled, m_showTooltips;
	size_t m_rows, m_nPrint;

public:
	FrmSongSearch(const wxString& title);

	void PopulateToolbar();
	void PopulateSongbooks();
	void PopulateSonglists(int setbook, wxString searchstr, bool searchall);
	void OpenSongPreview(int setsong);
	void PopulateSongresults(wxString searchstr);

	void GetSelectedBook(wxCommandEvent& event);
	void GetSelectedSong(wxCommandEvent& event);
	void Search_Clear(wxCommandEvent& event);
	void Search_Focus(wxCommandEvent& event);
	void Search_Song(wxCommandEvent& event);
	void btnProject_Click(wxCommandEvent& event);
	void btnEdit_Click(wxCommandEvent& event);
	void btnLast_Click(wxCommandEvent& event);
	void btnNext_Click(wxCommandEvent& event);
	void btnBigger_Click(wxCommandEvent& event);
	void btnSmaller_Click(wxCommandEvent& event);
	void btnFontset_Click(wxCommandEvent& event);
	void btnBold_Click(wxCommandEvent& event);
	void btnBooks_Click(wxCommandEvent& event);
	void btnSettings_Click(wxCommandEvent& event);

	void WndSplitterOnIdle(wxIdleEvent&)
	{
		WndSplitter->SetSashPosition(350);
		WndSplitter->Disconnect(wxEVT_IDLE, wxIdleEventHandler(FrmSongSearch::WndSplitterOnIdle), NULL, this);
	}

	void OnQuit(wxCommandEvent& event);
	void OnAbout(wxCommandEvent& event);

	FrmSongSearch *frmSongSearch;
	wxPanel* PanelLeft, *PanelRight;
	wxComboBox* cmbSongBooks;
	wxCheckBox* chkSearchSongs;
	wxStaticBoxSizer* ListWrapper;
	wxStaticBox* GrpSonglist;
	wxListBox* lstSongList;
	wxSearchCtrl* txtSearch;
	wxToolBar* toolBarSong;
	wxToolBarToolBase* btnProject, *btnEdit, *btnLast, *btnNext, *btnBigger, *btnSmaller, *btnFontset, *btnBold, *btnBooks, *btnSettings;
	wxTextCtrl* TxtSongTitle, *TxtPreview, *TxtExtras;

};