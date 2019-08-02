/////////////////////////////////////////////////////////////////////////////
// Name:        vSongBook.h
// Purpose:     vSongBook for Desktop
// Author:      Jacksiro
// Modified by:
// Created:     27/07/19
// Copyright:   (c) AppSmata
// Licence:     wxWindows licence
/////////////////////////////////////////////////////////////////////////////

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

class vSongBook : public wxApp
{
	public:
		virtual bool OnInit() wxOVERRIDE;
};

class MainFramex : public wxFrame
{
	public:
		//MainFrame(const wxString& title);

		void RecreateToolbar();

		void OnQuit(wxCommandEvent& event);
		void OnAbout(wxCommandEvent& event);

	private:
		wxDECLARE_EVENT_TABLE();
};
class MainFrame : public wxFrame
{
private:
	wxDECLARE_EVENT_TABLE();

protected:
	wxSplitterWindow* WndSplitter;
	wxPanel* PanelLeft;
	wxComboBox* cmbSongBooks;
	wxCheckBox* chkSearchSongs;
	wxListBox* lstSongResults;
	wxPanel* PanelRight;
	wxSearchCtrl* txtSearch;
	wxToolBar* toolBarSong;
	wxToolBarToolBase* btnProject;
	wxToolBarToolBase* btnEdit;
	wxToolBarToolBase* btnLast;
	wxToolBarToolBase* btnNext;
	wxToolBarToolBase* btnBigger;
	wxToolBarToolBase* btnSmaller;
	wxToolBarToolBase* btnFont;
	wxToolBarToolBase* btnBold;
	wxToolBarToolBase* btnBooks;
	wxToolBarToolBase* btnSettings;
	wxTextCtrl* TxtSongTitle;
	wxTextCtrl* TxtPreview;
	wxTextCtrl* TxtExtras;

	bool                m_smallToolbar,
		m_horzText,
		m_useCustomDisabled,
		m_showTooltips;
	size_t              m_rows;             // 1 or 2 only

	// the number of print buttons we have (they're added/removed dynamically)
	size_t              m_nPrint;

	// store toolbar position for future use
	//Positions           m_toolbarPosition;

public:
	MainFrame(const wxString& title);


	//MainFrame(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("vSongBook for Desktop"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(800, 500), long style = wxDEFAULT_FRAME_STYLE | wxTAB_TRAVERSAL);

	//~MainFrame();
	void PopulateToolbar(wxToolBarBase* toolBarSong);

	void WndSplitterOnIdle(wxIdleEvent&)
	{
		WndSplitter->SetSashPosition(350);
		WndSplitter->Disconnect(wxEVT_IDLE, wxIdleEventHandler(MainFrame::WndSplitterOnIdle), NULL, this);
	}

	void OnQuit(wxCommandEvent& event);
	void OnAbout(wxCommandEvent& event);
};