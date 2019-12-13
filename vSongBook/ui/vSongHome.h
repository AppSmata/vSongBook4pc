/////////////////////////////////////////////////////////////////////////////
// Name:        vSongHome.h
// Purpose:     vSongBook for Desktop
// Author:      Jacksiro
// Modified by:
// Created:     27/07/19
// Copyright:   (c) AppSmata
// Licence:     wxWindows licence
/////////////////////////////////////////////////////////////////////////////

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/statusbr.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/string.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/menu.h>
#include <wx/srchctrl.h>
#include <wx/choice.h>
#include <wx/radiobut.h>
#include <wx/listbox.h>
#include <wx/sizer.h>
#include <wx/statbox.h>
#include <wx/panel.h>
#include <wx/toolbar.h>
#include <wx/textctrl.h>
#include <wx/splitter.h>
#include <wx/frame.h>

///////////////////////////////////////////////////////////////////////////////
/// Class vSongHome
///////////////////////////////////////////////////////////////////////////////

class vSongHome : public wxFrame
{
private:

protected:
	vSongHome* home;
	wxBoxSizer* MainWrapper;

	wxStatusBar* AppStatusbar;
	wxSplitterWindow* AppSplitter;
	wxComboBox* CmbSongBooks;
	wxMenuBar* Mnu_Menu;
	wxMenu* Mnu_File, * Mnu_Songs, * Mnu_Books, * Mnu_Search, * Mnu_Settings, * Mnu_Help, * Mnu_Support;

	wxMenuItem* Mnu_Restart, * Mnu_Exit, * Mnu_SongNew, * Mnu_SongEdit, * Mnu_SongFav, * Mnu_SongDelete, * Mnu_BookEdit;
	wxMenuItem* Mnu_BookFav, * Mnu_BooksManage, * Mnu_SearchToday, * Mnu_SearchYesterday, * Mnu_SearchOlder;
	wxMenuItem* Mnu_SettingsAll, * Mnu_SettingsReset, * Mnu_About, * Mnu_Contacts, * Mnu_Donate;

	wxPanel* PanelLeft, * PanelRight;
	wxCheckBox* ChkSearchSongs, * ChkNightMode;
	wxStaticBoxSizer* ListWrapper;
	wxStaticBox* GrpSonglist;
	wxListBox* LstSongList;
	wxSearchCtrl* TxtSearch;
	wxToolBar* AppToolBar;
	wxToolBarToolBase* BtnProject, * BtnEdit, * BtnLast, * BtnNext, * BtnBigger, * BtnSmaller, * BtnFontset, * BtnBold, * BtnBooks, * BtnSettings;
	wxTextCtrl* TxtSongTitle, * TxtPreview, * TxtExtras;

	bool m_smallToolbar, m_horzText, m_useCustomDisabled, m_showTooltips;
	size_t m_rows, m_nPrint;

public:

	vSongHome(const wxString& title);
	void SetupMenu();

	void PopulateToolbar();
	void PopulateSongbooks();
	void SetAppTheme(int apptheme);
	void PopulateSonglists(wxString setbook, wxString searchstr, bool searchall);
	void OpenSongPreview(int setsong);
	void PopulateSongresults(wxString searchstr);

	void GetSelectedBook(wxCommandEvent& event);
	void GetSelectedSong(wxCommandEvent& event);
	void Search_Clear(wxCommandEvent& event);
	void Search_Focus(wxCommandEvent& event);
	void Search_Song(wxCommandEvent& event);
	void BtnProject_Click(wxCommandEvent& event);
	void BtnEdit_Click(wxCommandEvent& event);
	void BtnLast_Click(wxCommandEvent& event);
	void BtnNext_Click(wxCommandEvent& event);
	void BtnBigger_Click(wxCommandEvent& event);
	void BtnSmaller_Click(wxCommandEvent& event);
	void BtnFontset_Click(wxCommandEvent& event);
	void BtnBold_Click(wxCommandEvent& event);
	void BtnBooks_Click(wxCommandEvent& event);
	void BtnSettings_Click(wxCommandEvent& event);

	void ChkNightMode_Click(wxCommandEvent& event);

	void AppSplitterOnIdle(wxIdleEvent&)
	{
		AppSplitter->SetSashPosition(400);
		AppSplitter->Disconnect(wxEVT_IDLE, wxIdleEventHandler(vSongHome::AppSplitterOnIdle), NULL, this);
	}

	void OnQuit(wxCommandEvent& event);
	void OnAbout(wxCommandEvent& event);
	void GetSettings();
	void InitializeSettings();

	~vSongHome();

};