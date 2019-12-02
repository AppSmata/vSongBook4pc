﻿/////////////////////////////////////////////////////////////////////////////
// Name:        vSongBook.cpp
// Purpose:     vSongBook for Desktop
// Author:      Jacksiro
// Modified by:
// Created:     27/07/19
// Copyright:   (c) AppSmata
// Licence:     wxWindows licence
/////////////////////////////////////////////////////////////////////////////

#ifdef __BORLANDC__
#pragma hdrstop
#endif

#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

#include "wx/preferences.h"
#include "wx/config.h"
//#include "wx/scopedptr.h"
//#include "wx/stattext.h"
//#include "wx/artprov.h"

#include "frmSongSearch.h"
#include "frmProject.h"
#include "frmSettings.h"
#include "AppSettings.h"
#include "sqlite/sqlite3pp.h"

#ifndef wxHAS_IMAGES_IN_RESOURCES
#include "vSongBook.xpm"
#endif

#include <string>
#include <iostream>
#include <vector>

using namespace std;

FrmSongSearch *frmSongSearch;
FrmProject *frmProject;
FrmSettings *frmSettings;

wxString SongDatabase = "Data\\Songs.db", PrefsDatabase = "Data\\Settings.db", selected_book, selected_song, search_term;
vector<wxString> bookids, songids, booktitles, songtitles, songaliases, songcontents, songbooks, bookcodes;

wxScopedPtr<wxPreferencesEditor> _prefEditor;

enum
{
	Minimal_Quit = wxID_EXIT,
	Minimal_About = wxID_ABOUT
};

/*class vSongBook : public wxApp
{
public:
	virtual bool OnInit() wxOVERRIDE;
	const AppSettings::Preferences& GetSettings() const { return _pref; }
	void UpdateSettings(const AppSettings::Preferences& settings);

private:
	wxScopedPtr<wxPreferencesEditor> _prefEditor;
	AppSettings::Preferences _pref;

};

wxBEGIN_EVENT_TABLE(FrmSongSearch, wxFrame)
EVT_MENU(Minimal_Quit, FrmSongSearch::OnQuit)
EVT_MENU(Minimal_About, FrmSongSearch::OnAbout)
wxEND_EVENT_TABLE()

wxIMPLEMENT_APP(vSongBook);

bool vSongBook::OnInit()
{
	if (!wxApp::OnInit())
		return false;
	const AppSettings::Preferences& _pref = wxGetApp().GetSettings();

	frmSongSearch = new FrmSongSearch("vSongBook v" + _pref.vsb_version + " | " + _pref.app_user);
	
	frmSongSearch->SetSize(1000, 700);
	frmSongSearch->Show(true);
	frmSongSearch->Center();
	frmSongSearch->Maximize(true);
	return true;
}*/

wxString ReplaceAll(wxString str, const wxString from, const wxString to)
{
	size_t start_pos = 0;
	while ((start_pos = str.find(from, start_pos)) != string::npos)
	{
		str.replace(start_pos, from.length(), to);
		start_pos += to.length();
	}
	return str;
}


wxString ContentText(wxString songstr)
{
	songstr = ReplaceAll(songstr, "\\n", "\r\n");
	songstr = ReplaceAll(songstr, "Å©", "u");
	songstr = ReplaceAll(songstr, "Ä©", "u");
	songstr = ReplaceAll(songstr, "Å¨", "U");
	return songstr;
}

FrmSongSearch::FrmSongSearch(const wxString& title) : wxFrame(NULL, wxID_ANY, title)
{
	SetIcon(wxICON(appicon));

#if wxUSE_MENUS
	wxMenu *fileMenu = new wxMenu;

	// the "About" item should be in the help menu
	wxMenu *helpMenu = new wxMenu;
	helpMenu->Append(Minimal_About, "&About\tF1", "Show about dialog");

	fileMenu->Append(Minimal_Quit, "E&xit\tAlt-X", "Quit vSongBook");

	wxMenuBar *menuBar = new wxMenuBar();
	menuBar->Append(fileMenu, "&File");
	menuBar->Append(helpMenu, "&Help");

	// ... and attach this menu bar to the FrmSongSearch
	//SetMenuBar(menuBar);
#else // !wxUSE_MENUS
	// If menus are not available add a button to access the about box
	wxSizer* sizer = new wxBoxSizer(wxHORIZONTAL);
	wxButton* aboutBtn = new wxButton(this, wxID_ANY, "About...");
	aboutBtn->Bind(wxEVT_BUTTON, &FrmSongSearch::OnAbout, this);
	sizer->Add(aboutBtn, wxSizerFlags().Center());
#endif // wxUSE_MENUS/!wxUSE_MENUS

#if wxUSE_STATUSBAR
	CreateStatusBar(2);
	SetStatusText("Welcome to vSongBook for Desktop!");
#endif // wxUSE_STATUSBAR
	this->SetSizeHints(wxDefaultSize, wxDefaultSize);
	this->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_BTNTEXT));

	wxBoxSizer* MainWrapper;
	MainWrapper = new wxBoxSizer(wxVERTICAL);

	WndSplitter = new wxSplitterWindow(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSP_3D);
	WndSplitter->Connect(wxEVT_IDLE, wxIdleEventHandler(FrmSongSearch::WndSplitterOnIdle), NULL, this);

	WndSplitter->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_BTNTEXT));

	PanelLeft = new wxPanel(WndSplitter, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
	PanelLeft->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOW));

	wxBoxSizer* SizerLeft;
	SizerLeft = new wxBoxSizer(wxVERTICAL);

	cmbSongBooks = new wxComboBox(PanelLeft, wxID_ANY, wxT("Songbooks"), wxDefaultPosition, wxSize(-1, -1), 0, NULL, wxCB_READONLY);
	cmbSongBooks->SetFont(wxFont(12, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Trebuchet MS")));

	SizerLeft->Add(cmbSongBooks, 0, wxALL | wxEXPAND, 5);

	chkSearchSongs = new wxCheckBox(PanelLeft, wxID_ANY, wxT("Search All SongBooks"), wxDefaultPosition, wxSize(-1, -1), 0);
	chkSearchSongs->SetValue(true);
	chkSearchSongs->SetFont(wxFont(12, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Trebuchet MS")));

	SizerLeft->Add(chkSearchSongs, 0, wxALL | wxEXPAND, 5);
		
	GrpSonglist = new wxStaticBox(PanelLeft, wxID_ANY, wxT(""));
	ListWrapper = new wxStaticBoxSizer(GrpSonglist, wxVERTICAL);

	lstSongList = new wxListBox(PanelLeft, wxID_ANY, wxDefaultPosition, wxSize(-1, -1), 0, NULL, wxLB_HSCROLL);
	lstSongList->SetFont(wxFont(12, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Trebuchet MS")));
	
	ListWrapper->Add(lstSongList, 1, wxALL | wxEXPAND, 1);

	SizerLeft->Add(ListWrapper, 1, wxEXPAND, 5);

	PanelLeft->SetSizer(SizerLeft);
	PanelLeft->Layout();
	SizerLeft->Fit(PanelLeft);
	PanelRight = new wxPanel(WndSplitter, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
	PanelRight->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_HIGHLIGHTTEXT));

	wxBoxSizer* SizerRight;
	SizerRight = new wxBoxSizer(wxVERTICAL);

	txtSearch = new wxSearchCtrl(PanelRight, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(-1, -1), wxTE_PROCESS_ENTER);

#ifndef __WXMAC__
	txtSearch->ShowSearchButton(true);
#endif
	txtSearch->ShowCancelButton(true);
	txtSearch->SetFont(wxFont(12, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Trebuchet MS")));

	SizerRight->Add(txtSearch, 0, wxALL | wxEXPAND, 5);

	toolBarSong = new wxToolBar(PanelRight, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTB_HORIZONTAL);
	toolBarSong->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOW));

	SizerRight->Add(toolBarSong, 0, wxEXPAND, 5);

	TxtSongTitle = new wxTextCtrl(PanelRight, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(-1, -1), wxTE_READONLY | wxTE_RICH);
	TxtSongTitle->SetFont(wxFont(20, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Trebuchet MS")));
	SizerRight->Add(TxtSongTitle, 0, wxALL | wxEXPAND, 5);

	wxStaticBoxSizer* GroupPreview;
	GroupPreview = new wxStaticBoxSizer(new wxStaticBox(PanelRight, wxID_ANY, wxEmptyString), wxVERTICAL);

	TxtPreview = new wxTextCtrl(GroupPreview->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(-1, -1), wxTE_MULTILINE | wxTE_READONLY | wxTE_RICH);
	TxtPreview->SetFont(wxFont(15, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Trebuchet MS")));
	GroupPreview->Add(TxtPreview, 1, wxALL | wxEXPAND, 0);


	SizerRight->Add(GroupPreview, 1, wxEXPAND, 0);

	TxtExtras = new wxTextCtrl(PanelRight, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(-1, -1), wxTE_MULTILINE | wxTE_READONLY);
	TxtExtras->SetFont(wxFont(12, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Trebuchet MS")));
	TxtExtras->SetFont(wxFont(12, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Trebuchet MS")));

	SizerRight->Add(TxtExtras, 0, wxALL | wxEXPAND, 5);

	PanelRight->SetSizer(SizerRight);
	PanelRight->Layout();
	SizerRight->Fit(PanelRight);
	WndSplitter->SplitVertically(PanelLeft, PanelRight, 350);
	MainWrapper->Add(WndSplitter, 1, wxEXPAND, 0);

	PopulateToolbar();
	PopulateSongbooks();

	this->SetSizer(MainWrapper);
	this->Layout();

	this->Centre(wxBOTH);

	// Connect Events
	cmbSongBooks->Connect(wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler(FrmSongSearch::GetSelectedBook), NULL, this);
	lstSongList->Connect(wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler(FrmSongSearch::GetSelectedSong), NULL, this);
	txtSearch->Connect(wxEVT_COMMAND_SEARCHCTRL_CANCEL_BTN, wxCommandEventHandler(FrmSongSearch::Search_Clear), NULL, this);
	txtSearch->Connect(wxEVT_COMMAND_SEARCHCTRL_SEARCH_BTN, wxCommandEventHandler(FrmSongSearch::Search_Song), NULL, this);
	txtSearch->Connect(wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler(FrmSongSearch::Search_Song), NULL, this);
	//txtSearch->Bind(wxEVT_COMMAND_TEXT_ENTER, &FrmSongSearch::Search_Song, this);
	this->Connect(btnProject->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler(FrmSongSearch::btnProject_Click));
	this->Connect(btnEdit->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler(FrmSongSearch::btnEdit_Click));
	this->Connect(btnLast->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler(FrmSongSearch::btnLast_Click));
	this->Connect(btnNext->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler(FrmSongSearch::btnNext_Click));
	this->Connect(btnBigger->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler(FrmSongSearch::btnBigger_Click));
	this->Connect(btnSmaller->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler(FrmSongSearch::btnSmaller_Click));
	this->Connect(btnFontset->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler(FrmSongSearch::btnFontset_Click));
	this->Connect(btnBold->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler(FrmSongSearch::btnBold_Click));
	this->Connect(btnBooks->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler(FrmSongSearch::btnBooks_Click));
	this->Connect(btnSettings->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler(FrmSongSearch::btnSettings_Click));
}

void FrmSongSearch::PopulateToolbar()
{
	// Set up toolbar
	enum
	{
		Tool_project,
		Tool_edit,
		Tool_last,
		Tool_next,
		Tool_bigger,
		Tool_smaller,
		Tool_font,
		Tool_bold,
		Tool_books,
		Tool_settings,
		Tool_max
	};

	wxBitmap toolBarBitmaps[Tool_max];

#if USE_XPM_BITMAPS
#define INIT_TOOL_BMP(bmp) \
        toolBarBitmaps[Tool_##bmp] = wxBitmap(bmp##_xpm)
#else // !USE_XPM_BITMAPS
#define INIT_TOOL_BMP(bmp) \
        toolBarBitmaps[Tool_##bmp] = wxBITMAP(bmp)
#endif // USE_XPM_BITMAPS/!USE_XPM_BITMAPS

	INIT_TOOL_BMP(project);
	INIT_TOOL_BMP(edit);
	INIT_TOOL_BMP(last);
	INIT_TOOL_BMP(next);
	INIT_TOOL_BMP(bigger);
	INIT_TOOL_BMP(smaller);
	INIT_TOOL_BMP(font);
	INIT_TOOL_BMP(bold);
	INIT_TOOL_BMP(books);
	INIT_TOOL_BMP(settings);

	int w = toolBarBitmaps[Tool_project].GetWidth(),
		h = toolBarBitmaps[Tool_project].GetHeight();

	toolBarSong->SetToolBitmapSize(wxSize(w, h));

	btnProject = toolBarSong->AddTool(wxID_ANY, wxT("Project"), toolBarBitmaps[Tool_project], wxNullBitmap, wxITEM_NORMAL, 
		wxT("Project this Song"), wxT("Project this Song"), NULL);

	btnEdit = toolBarSong->AddTool(wxID_ANY, wxT("Edit"), toolBarBitmaps[Tool_edit], wxNullBitmap, wxITEM_NORMAL, 
		wxT("Edit this Song"), wxT("Edit this Song"), NULL);

	toolBarSong->AddSeparator();

	btnLast = toolBarSong->AddTool(wxID_ANY, wxT("Previous"), toolBarBitmaps[Tool_last], wxNullBitmap, wxITEM_NORMAL, 
		wxT("Go to the Previous Song"), wxT("Go to the Previous Song"), NULL);

	btnNext = toolBarSong->AddTool(wxID_ANY, wxT("Next"), toolBarBitmaps[Tool_next], wxNullBitmap, wxITEM_NORMAL, 
		wxT("Go to the Next Song"), wxT("Go to the Next Song"), NULL);

	toolBarSong->AddSeparator();

	btnBigger = toolBarSong->AddTool(wxID_ANY, wxT("Bigger"), toolBarBitmaps[Tool_bigger], wxNullBitmap, 
		wxITEM_NORMAL, wxT("Bigger Font Size"), wxT("Bigger Font Size"), NULL);

	btnSmaller = toolBarSong->AddTool(wxID_ANY, wxT("Smaller"), toolBarBitmaps[Tool_smaller], wxNullBitmap, wxITEM_NORMAL, 
		wxT("Smaller Font Size"), wxT("Smaller Font Size"), NULL);

	btnFontset = toolBarSong->AddTool(wxID_ANY, wxT("Font"), toolBarBitmaps[Tool_font], wxNullBitmap, wxITEM_NORMAL, 
		wxT("Change Font Type"), wxT("Change Font Type"), NULL);

	btnBold = toolBarSong->AddTool(wxID_ANY, wxT("Bold"), toolBarBitmaps[Tool_bold], wxNullBitmap, wxITEM_NORMAL, 
		wxT("Make Bold"), wxT("Make Bold"), NULL);

	toolBarSong->AddSeparator();

	btnBooks = toolBarSong->AddTool(wxID_ANY, wxT("SongBooks"), toolBarBitmaps[Tool_books], wxNullBitmap, wxITEM_NORMAL, 
		wxT("View SongBooks"), wxT("View SongBooks"), NULL);

	btnSettings = toolBarSong->AddTool(wxID_ANY, wxT("Settings"), toolBarBitmaps[Tool_settings], wxNullBitmap, wxITEM_NORMAL, 
		wxT("Manage App Preferences"), wxT("Manage App Preferences"), NULL);

	toolBarSong->Realize();

	//toolBarSong->SetRows(toolBarSong->IsVertical() ? toolBarSong->GetToolsCount() / m_rows : m_rows);
}

void FrmSongSearch::OnAbout(wxCommandEvent& WXUNUSED(event))
{
	wxMessageBox(wxString::Format
	(
		"Welcome to %s!\n"
		"\n"
		"This is the vSongBook\n"
		"running under %s.",
		wxVERSION_STRING,
		wxGetOsDescription()
	),
		"About vSongBook for Desktop",
		wxOK | wxICON_INFORMATION,
		this);
}

void FrmSongSearch::OnQuit(wxCommandEvent& WXUNUSED(event))
{
	Close(true);
}

sqlite3pp::database songDb()
{
	sqlite3pp::database db("Songs.db");
	sqlite3pp::transaction xct(db, true);
	return db;
}

void FrmSongSearch::PopulateSongbooks()
{
	try {
		int bookscount = cmbSongBooks->GetCount();
		if (bookscount > 0) {
			//bookids->Clear();
			//booktitles->Clear();
			cmbSongBooks->Clear();
		}

		sqlite3* db;
		char* err_msg = NULL, ** qryResult = NULL;
		int row, col, rc = sqlite3_open_v2(SongDatabase, &db, SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE, NULL);

		wxString sqlQuery = _T("SELECT bookid, title, songs FROM books WHERE enabled=1 ORDER BY position");

		rc = sqlite3_get_table(db, sqlQuery, &qryResult, &row, &col, &err_msg);

		for (int i = 1; i < row + 1; i++)
		{
			wxString title = *(qryResult + i * col + 1);
			wxString songs = *(qryResult + i * col + 2);

			cmbSongBooks->Append(wxString::FromUTF8(std::string(title) + " (" + songs + ")"));
			bookids.push_back(*(qryResult + i * col + 0));
			booktitles.push_back(title);
		}

		sqlite3_free_table(qryResult);
		sqlite3_close(db);
		cmbSongBooks->SetSelection(0);
		PopulateSonglists(bookids[0], "", false);
	}
	catch (exception& ex) {
		SetStatusText(ex.what());
	}
}

void FrmSongSearch::PopulateSonglists(wxString setbook, wxString searchstr, bool searchall)
{
	try {
		if (lstSongList->GetCount() > 0) {
			songids.clear();
			songtitles.clear();
			songaliases.clear();
			songcontents.clear();
			songbooks.clear();
			lstSongList->Clear();
		}
		wxString searchtotals = " songs found in: " + booktitles[cmbSongBooks->GetSelection()];

		wxString SqlQuery = "SELECT songid, number, songs.title, alias, songs.content, key, author, books.title, code FROM songs";
		SqlQuery = SqlQuery + " INNER JOIN books ON books.bookid = songs.bookid WHERE";


		if (searchstr.empty()) SqlQuery = SqlQuery + " songs.bookid=" + setbook;
		else
		{
			if (searchall)
			{
				if (searchstr.IsNumber())
				{
					SqlQuery = SqlQuery + " number=" + searchstr;
					searchtotals = " songs found with number: " + searchstr + "#";
				}
				else
				{
					SqlQuery = SqlQuery + " songs.title LIKE '%" + searchstr + "%' OR alias LIKE '%" + searchstr +
						"%' OR songs.content LIKE '%" + searchstr + "%'";
					searchtotals = " songs found with words: \"" + searchstr + "\"";
				}
			}
			else
			{
				if (searchstr.IsNumber())
				{
					SqlQuery = SqlQuery + " songs.bookid=" + setbook + " AND number=" + searchstr;
					searchtotals = " songs found with number: " + searchstr + "#";
				}
				else
				{
					SqlQuery = SqlQuery + " songs.bookid=" + setbook + " AND songs.title LIKE '%" + searchstr + "%' OR songs.bookid=" + setbook +
						" AND alias LIKE '%" + searchstr + "%' OR songs.bookid=" + setbook + " AND songs.content LIKE '%" + searchstr + "%'";
					searchtotals = " songs found with words: \"" + searchstr + "\"";
				}
			}
		}

		sqlite3* db;
		char* err_msg = NULL, ** qryResult = NULL;
		int row, col, rc = sqlite3_open_v2(SongDatabase, &db, SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE, NULL);

		wxString sqlQuery = SqlQuery + " ORDER BY number ASC";

		rc = sqlite3_get_table(db, sqlQuery, &qryResult, &row, &col, &err_msg);

		for (int i = 1; i < row + 1; i++)
		{
			wxString titles = std::string(*(qryResult + i * col + 1)) + "# " + *(qryResult + i * col + 2);

			if (searchstr.empty()) lstSongList->Append(titles);
			else lstSongList->Append(wxString::FromUTF8(titles + " (" + *(qryResult + i * col + 8) + ")"));

			songids.push_back(*(qryResult + i * col + 0));
			songtitles.push_back(titles);
			songaliases.push_back(*(qryResult + i * col + 3));
			songcontents.push_back(*(qryResult + i * col + 4));
			songbooks.push_back(std::string(*(qryResult + i * col + 7)) + " (" + *(qryResult + i * col + 8) + ")");
		}

		sqlite3_free_table(qryResult);
		sqlite3_close(db);

		lstSongList->SetSelection(0);
		OpenSongPreview(0);
	}
	catch (exception & ex) {
		SetStatusText(ex.what());
	}
}

void FrmSongSearch::GetSelectedBook(wxCommandEvent&)
{
	PopulateSonglists(bookids[cmbSongBooks->GetSelection()], "", false);
}

void FrmSongSearch::GetSelectedSong(wxCommandEvent&)
{
	OpenSongPreview(lstSongList->GetSelection());
}

void FrmSongSearch::OpenSongPreview(int setsong)
{
	selected_song = songids[setsong];
	TxtSongTitle->SetValue(songtitles[setsong]);
	TxtPreview->SetValue(ContentText(songcontents[setsong]));
	TxtExtras->SetValue(songaliases[setsong]);
}

void FrmSongSearch::Search_Clear(wxCommandEvent&)
{
	txtSearch->Clear();
}

void FrmSongSearch::Search_Song(wxCommandEvent&)
{
	wxString searchthis = txtSearch->GetValue();
	PopulateSonglists(bookids[cmbSongBooks->GetSelection()], searchthis, chkSearchSongs->GetValue());
	SetStatusText("You searched for: \"" + searchthis + "\"");
}

void FrmSongSearch::btnProject_Click(wxCommandEvent&)
{
	frmProject = new FrmProject("vSongBook Projection");

	frmProject->SetSize(1000, 700);
	frmProject->SetWindowStyle(0 | wxTAB_TRAVERSAL);
	frmProject->Show(true);
	frmProject->Center();
	frmProject->Maximize(true);
}

void FrmSongSearch::btnEdit_Click(wxCommandEvent&)
{

}

void FrmSongSearch::btnLast_Click(wxCommandEvent&)
{

}

void FrmSongSearch::btnNext_Click(wxCommandEvent&)
{

}

void FrmSongSearch::btnBigger_Click(wxCommandEvent&)
{

}

void FrmSongSearch::btnSmaller_Click(wxCommandEvent&)
{

}

void FrmSongSearch::btnFontset_Click(wxCommandEvent&)
{

}

void FrmSongSearch::btnBold_Click(wxCommandEvent&)
{

}

void FrmSongSearch::btnBooks_Click(wxCommandEvent&)
{

}

void FrmSongSearch::btnSettings_Click(wxCommandEvent&)
{
	frmSettings = new FrmSettings("vSongBook Preferences");
	frmSettings->SetSize(840, 600);
	frmSettings->Show(true);
	frmSettings->SetWindowStyle(wxCAPTION | wxCLOSE_BOX);
	frmSettings->Center();
}

FrmProject::FrmProject(const wxString& title) : wxFrame(NULL, wxID_ANY, title)
{
	enum
	{
		Button_blackdown,
		Button_blackup,
		Button_max
	};

	wxBitmap ButtonBitmaps[Button_max];

#if USE_XPM_BITMAPS
#define INIT_BTN_BMP(bmp) \
        ButtonBitmaps[Button_##bmp] = wxBitmap(bmp##_xpm)
#else // !USE_XPM_BITMAPS
#define INIT_BTN_BMP(bmp) \
        ButtonBitmaps[Button_##bmp] = wxBITMAP(bmp)
#endif // USE_XPM_BITMAPS/!USE_XPM_BITMAPS

	INIT_BTN_BMP(blackdown);
	INIT_BTN_BMP(blackup);

	this->SetSizeHints(wxDefaultSize, wxDefaultSize);
	this->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_BTNHIGHLIGHT));

	wxBoxSizer* MainWrapper;
	MainWrapper = new wxBoxSizer(wxVERTICAL);

	wxStaticBoxSizer* GrpMain;
	GrpMain = new wxStaticBoxSizer(new wxStaticBox(this, wxID_ANY, wxT(" vSongBook for Desktop v2.4.1 ")), wxVERTICAL);

	wxBoxSizer* TopPanel;
	TopPanel = new wxBoxSizer(wxHORIZONTAL);

	lblCorner1 = new wxStaticText(GrpMain->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(20, -1), 0);
	lblCorner1->Wrap(-1);
	lblCorner1->SetFont(wxFont(15, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Trebuchet MS")));

	TopPanel->Add(lblCorner1, 0, wxALIGN_CENTER | wxALL | wxEXPAND, 5);

	lblKey = new wxStaticText(GrpMain->GetStaticBox(), wxID_ANY, wxT("Key: E"), wxDefaultPosition, wxSize(-1, -1), wxALIGN_CENTER_HORIZONTAL);
	lblKey->Wrap(-1);
	lblKey->SetFont(wxFont(20, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Trebuchet MS")));

	TopPanel->Add(lblKey, 0, wxALL, 5);

	lblTitle = new wxStaticText(GrpMain->GetStaticBox(), wxID_ANY, wxT("1# Only Believe"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER_HORIZONTAL);
	lblTitle->Wrap(-1);
	lblTitle->SetFont(wxFont(25, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Trebuchet MS")));

	TopPanel->Add(lblTitle, 1, wxALL, 5);

	wxBoxSizer* PanelTitle;
	PanelTitle = new wxBoxSizer(wxVERTICAL);


	TopPanel->Add(PanelTitle, 1, wxEXPAND, 5);

	btnClose = new wxButton(GrpMain->GetStaticBox(), wxID_ANY, wxT("X"), wxDefaultPosition, wxSize(30, -1), 0);
	btnClose->SetFont(wxFont(12, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Trebuchet MS")));

	TopPanel->Add(btnClose, 0, wxALL, 5);

	lblCorner2 = new wxStaticText(GrpMain->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(20, -1), wxALIGN_CENTER_HORIZONTAL);
	lblCorner2->Wrap(-1);
	lblCorner2->SetFont(wxFont(25, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Trebuchet MS")));

	TopPanel->Add(lblCorner2, 0, wxALL, 5);


	GrpMain->Add(TopPanel, 0, wxEXPAND, 5);

	wxStaticBoxSizer* MidPanel;
	MidPanel = new wxStaticBoxSizer(new wxStaticBox(GrpMain->GetStaticBox(), wxID_ANY, wxEmptyString), wxVERTICAL);

	lblSongText = new wxStaticText(MidPanel->GetStaticBox(), wxID_ANY, wxT("CHORUS\nOnly believe, only believe,\nAll things are possible,\nOnly believe, Only believe,\nonly believe,\nAll things are possible,\nonly believe."), wxDefaultPosition, wxDefaultSize, 0);
	lblSongText->Wrap(-1);
	lblSongText->SetFont(wxFont(40, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Trebuchet MS")));

	MidPanel->Add(lblSongText, 1, wxALIGN_CENTER | wxALL, 0);


	GrpMain->Add(MidPanel, 1, wxALIGN_CENTER | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL | wxALL | wxEXPAND, 0);

	wxBoxSizer* BottomPanel;
	BottomPanel = new wxBoxSizer(wxHORIZONTAL);

	lblCorner3 = new wxStaticText(GrpMain->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(20, -1), 0);
	lblCorner3->Wrap(-1);
	lblCorner3->SetFont(wxFont(15, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Trebuchet MS")));

	BottomPanel->Add(lblCorner3, 0, wxALL, 5);

	lblNumber = new wxStaticText(GrpMain->GetStaticBox(), wxID_ANY, wxT("Song 1#"), wxDefaultPosition, wxSize(-1, -1), wxALIGN_CENTER_HORIZONTAL);
	lblNumber->Wrap(-1);
	lblNumber->SetFont(wxFont(25, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Trebuchet MS")));

	BottomPanel->Add(lblNumber, 0, wxALL, 5);

	lblSongBook = new wxStaticText(GrpMain->GetStaticBox(), wxID_ANY, wxT("Songs of Worship"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER_HORIZONTAL);
	lblSongBook->Wrap(-1);
	lblSongBook->SetFont(wxFont(25, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Trebuchet MS")));

	BottomPanel->Add(lblSongBook, 1, wxALL, 5);

	lblTitle2 = new wxStaticText(GrpMain->GetStaticBox(), wxID_ANY, wxT("Verse 1/3"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER_HORIZONTAL);
	lblTitle2->Wrap(-1);
	lblTitle2->SetFont(wxFont(25, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Trebuchet MS")));

	BottomPanel->Add(lblTitle2, 0, wxALL, 5);

	btnGoDown = new wxBitmapButton(GrpMain->GetStaticBox(), wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW | wxBORDER_NONE);
	btnGoDown->SetBitmap(wxBitmap(ButtonBitmaps[Button_blackdown]));
	BottomPanel->Add(btnGoDown, 0, wxALL, 5);

	btnGoUp = new wxBitmapButton(GrpMain->GetStaticBox(), wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW | wxBORDER_NONE);
	btnGoUp->SetBitmap(wxBitmap(ButtonBitmaps[Button_blackup]));
	BottomPanel->Add(btnGoUp, 0, wxALL, 5);
	
	lblCorner4 = new wxStaticText(GrpMain->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(20, -1), wxALIGN_CENTER_HORIZONTAL);
	lblCorner4->Wrap(-1);
	lblCorner4->SetFont(wxFont(15, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Trebuchet MS")));

	BottomPanel->Add(lblCorner4, 0, wxALL, 5);

	GrpMain->Add(BottomPanel, 0, wxEXPAND, 5);

	MainWrapper->Add(GrpMain, 1, wxEXPAND, 5);

	this->SetSizer(MainWrapper);
	this->Layout();
	StatusBarP = this->CreateStatusBar(1, wxSTB_SIZEGRIP, wxID_ANY);

	this->Centre(wxBOTH);

	// Connect Events
	btnClose->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(FrmProject::btnClose_Click), NULL, this);
	btnGoDown->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(FrmProject::btnNext_Click), NULL, this);
	btnGoUp->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(FrmProject::btnPrevious_Click), NULL, this);
}

void FrmProject::btnClose_Click(wxCommandEvent&)
{
	Close(true);
}

void FrmProject::btnPrevious_Click(wxCommandEvent&)
{

}

void FrmProject::btnNext_Click(wxCommandEvent&)
{

}

FrmSettings::FrmSettings(const wxString& title) : wxFrame(NULL, wxID_ANY, title)
{
	enum
	{
		Button_bigger,
		Button_smaller,
		Button_max
	};

	wxBitmap ButtonBitmaps[Button_max];

#if USE_XPM_BITMAPS
#define INIT_BTN_BMP(bmp) \
        ButtonBitmaps[Button_##bmp] = wxBitmap(bmp##_xpm)
#else // !USE_XPM_BITMAPS
#define INIT_BTN_BMP(bmp) \
        ButtonBitmaps[Button_##bmp] = wxBITMAP(bmp)
#endif // USE_XPM_BITMAPS/!USE_XPM_BITMAPS

	INIT_BTN_BMP(bigger);
	INIT_BTN_BMP(smaller);

	this->SetSizeHints(wxDefaultSize, wxDefaultSize);
	this->SetBackgroundColour(wxColour(255, 255, 255));

	wxBoxSizer* MainWrapper;
	MainWrapper = new wxBoxSizer(wxVERTICAL);

	wxBoxSizer* PanelTop;
	PanelTop = new wxBoxSizer(wxVERTICAL);

	LblTitle = new wxStaticText(this, wxID_ANY, wxT("vSongBook Preferences"), wxDefaultPosition, wxSize(-1, 70), 0);
	LblTitle->Wrap(-1);
	LblTitle->SetFont(wxFont(20, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Trebuchet MS")));
	LblTitle->SetBackgroundColour(wxColour(255, 255, 255));

	PanelTop->Add(LblTitle, 1, wxALIGN_RIGHT | wxALL, 0);

	MainWrapper->Add(PanelTop, 0, wxEXPAND, 5);

	tabMain = new wxNotebook(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0);
	tabMain->SetFont(wxFont(15, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Trebuchet MS")));

	TabGeneral = new wxScrolledWindow(tabMain, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHSCROLL | wxVSCROLL);
	TabGeneral->SetScrollRate(5, 5);
	TabGeneral->SetMinSize(wxSize(-1, 75));

	wxBoxSizer* General_Wrapper;
	General_Wrapper = new wxBoxSizer(wxVERTICAL);

	General_Wrapper->SetMinSize(wxSize(-1, 800));
	wxStaticBoxSizer* GrpTabletMode;
	GrpTabletMode = new wxStaticBoxSizer(new wxStaticBox(TabGeneral, wxID_ANY, wxT(" Tablet Mode: ")), wxHORIZONTAL);

	GrpTabletMode->SetMinSize(wxSize(-1, 75));
	LblTabletMode = new wxStaticText(GrpTabletMode->GetStaticBox(), wxID_ANY, wxT("Tablet Mode is when you are using a touch screen input"), wxDefaultPosition, wxDefaultSize, 0);
	LblTabletMode->Wrap(-1);
	LblTabletMode->SetFont(wxFont(12, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Trebuchet MS")));

	GrpTabletMode->Add(LblTabletMode, 1, wxALL, 5);

	BtnTabletMode = new wxRadioButton(GrpTabletMode->GetStaticBox(), wxID_ANY, wxT("ON"), wxDefaultPosition, wxDefaultSize, 0);
	BtnTabletMode->SetFont(wxFont(12, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxT("Trebuchet MS")));

	GrpTabletMode->Add(BtnTabletMode, 0, wxALL, 5);

	General_Wrapper->Add(GrpTabletMode, 0, wxALL | wxEXPAND, 5);

	wxStaticBoxSizer* GrpSearchCriteria;
	GrpSearchCriteria = new wxStaticBoxSizer(new wxStaticBox(TabGeneral, wxID_ANY, wxT(" Search Criteria: ")), wxHORIZONTAL);

	GrpSearchCriteria->SetMinSize(wxSize(-1, 75));
	LblTabletMode1 = new wxStaticText(GrpSearchCriteria->GetStaticBox(), wxID_ANY, wxT("Search in All Songbooks"), wxDefaultPosition, wxDefaultSize, 0);
	LblTabletMode1->Wrap(-1);
	LblTabletMode1->SetFont(wxFont(12, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Trebuchet MS")));

	GrpSearchCriteria->Add(LblTabletMode1, 1, wxALL, 5);

	BtnSearchCriteria = new wxRadioButton(GrpSearchCriteria->GetStaticBox(), wxID_ANY, wxT("ON"), wxDefaultPosition, wxDefaultSize, 0);
	BtnSearchCriteria->SetValue(true);
	BtnSearchCriteria->SetFont(wxFont(12, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxT("Trebuchet MS")));

	GrpSearchCriteria->Add(BtnSearchCriteria, 0, wxALL, 5);

	General_Wrapper->Add(GrpSearchCriteria, 0, wxALL | wxEXPAND, 5);

	wxStaticBoxSizer* GrpLanguage;
	GrpLanguage = new wxStaticBoxSizer(new wxStaticBox(TabGeneral, wxID_ANY, wxT(" Preferred Language: ")), wxHORIZONTAL);

	GrpLanguage->SetMinSize(wxSize(-1, 90));
	LbLanguage = new wxStaticText(GrpLanguage->GetStaticBox(), wxID_ANY, wxT("Use vSongBook in"), wxDefaultPosition, wxDefaultSize, 0);
	LbLanguage->Wrap(-1);
	LbLanguage->SetFont(wxFont(12, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Trebuchet MS")));

	GrpLanguage->Add(LbLanguage, 1, wxALL, 5);

	cmbLanguage = new wxComboBox(GrpLanguage->GetStaticBox(), wxID_ANY, wxT("Portuguese"), wxDefaultPosition, wxDefaultSize, 0, NULL, wxCB_READONLY);
	cmbLanguage->Append(wxT("English"));
	cmbLanguage->Append(wxT("Swahili"));
	cmbLanguage->Append(wxT("French"));
	cmbLanguage->Append(wxT("Spanish"));
	cmbLanguage->Append(wxT("Chichewa"));
	cmbLanguage->Append(wxT("Portuguese"));
	cmbLanguage->SetSelection(5);
	GrpLanguage->Add(cmbLanguage, 0, wxALL, 5);

	General_Wrapper->Add(GrpLanguage, 0, wxALL | wxEXPAND, 5);

	wxStaticBoxSizer* GrpUserName;
	GrpUserName = new wxStaticBoxSizer(new wxStaticBox(TabGeneral, wxID_ANY, wxT("  Your Name / Name of your Church: ")), wxVERTICAL);

	GrpUserName->SetMinSize(wxSize(-1, 100));
	TxtUserName = new wxTextCtrl(GrpUserName->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
	GrpUserName->Add(TxtUserName, 1, wxALL | wxEXPAND, 5);

	LblUserName = new wxStaticText(GrpUserName->GetStaticBox(), wxID_ANY, wxT("100 characters remaining ..."), wxDefaultPosition, wxDefaultSize, 0);
	LblUserName->Wrap(-1);
	LblUserName->SetFont(wxFont(8, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Trebuchet MS")));

	GrpUserName->Add(LblUserName, 0, wxALL, 5);

	General_Wrapper->Add(GrpUserName, 0, wxALL | wxEXPAND, 5);

	TabGeneral->SetSizer(General_Wrapper);
	TabGeneral->Layout();
	General_Wrapper->Fit(TabGeneral);
	tabMain->AddPage(TabGeneral, wxT("General Options"), true);
	TabFonts = new wxScrolledWindow(tabMain, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHSCROLL | wxVSCROLL);
	TabFonts->SetScrollRate(5, 5);
	wxBoxSizer* FontWrapper;
	FontWrapper = new wxBoxSizer(wxVERTICAL);

	FontWrapper->SetMinSize(wxSize(-1, 600));
	wxStaticBoxSizer* GrpSampleText;
	GrpSampleText = new wxStaticBoxSizer(new wxStaticBox(TabFonts, wxID_ANY, wxT(" Sample Text: ")), wxVERTICAL);

	GrpSampleText->SetMinSize(wxSize(-1, 150));
	LblSampleText = new wxStaticText(GrpSampleText->GetStaticBox(), wxID_ANY, wxT("Only Believe"), wxDefaultPosition, wxSize(-1, 100), wxALIGN_CENTER_HORIZONTAL);
	LblSampleText->Wrap(-1);
	LblSampleText->SetFont(wxFont(40, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Trebuchet MS")));

	GrpSampleText->Add(LblSampleText, 1, wxALIGN_CENTER | wxALL | wxEXPAND, 5);

	FontWrapper->Add(GrpSampleText, 0, wxALIGN_CENTER | wxALIGN_CENTER_HORIZONTAL | wxALL | wxEXPAND, 5);

	wxStaticBoxSizer* GrpAppFont;
	GrpAppFont = new wxStaticBoxSizer(new wxStaticBox(TabFonts, wxID_ANY, wxT(" General App Font: ")), wxHORIZONTAL);

	GrpAppFont->SetMinSize(wxSize(-1, 100));
	LblAppFont = new wxStaticText(GrpAppFont->GetStaticBox(), wxID_ANY, wxT("15"), wxDefaultPosition, wxSize(25, -1), 0);
	LblAppFont->Wrap(-1);
	LblAppFont->SetFont(wxFont(12, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Trebuchet MS")));

	GrpAppFont->Add(LblAppFont, 0, wxALIGN_CENTER | wxALL, 5);

	BtnAppFontSmaller = new wxBitmapButton(GrpAppFont->GetStaticBox(), wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW | 0);

	BtnAppFontSmaller->SetBitmap(wxBitmap(ButtonBitmaps[Button_smaller]));
	GrpAppFont->Add(BtnAppFontSmaller, 0, wxALL, 5);

	SldAppFont = new wxSlider(GrpAppFont->GetStaticBox(), wxID_ANY, 15, 12, 50, wxDefaultPosition, wxDefaultSize, wxSL_BOTH | wxSL_HORIZONTAL);
	GrpAppFont->Add(SldAppFont, 1, wxALIGN_CENTER | wxALL, 5);

	BtnAppFontBigger = new wxBitmapButton(GrpAppFont->GetStaticBox(), wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW | 0);

	BtnAppFontBigger->SetBitmap(wxBitmap(ButtonBitmaps[Button_bigger]));
	GrpAppFont->Add(BtnAppFontBigger, 0, wxALL, 5);

	cmbAppFont = new wxComboBox(GrpAppFont->GetStaticBox(), wxID_ANY, wxT("Font Type"), wxDefaultPosition, wxDefaultSize, 0, NULL, 0);
	cmbAppFont->Append(wxT("Arial"));
	cmbAppFont->Append(wxT("Calibri"));
	cmbAppFont->Append(wxT("Century Gothic"));
	cmbAppFont->Append(wxT("Comic Sans MS"));
	cmbAppFont->Append(wxT("Corbel"));
	cmbAppFont->Append(wxT("Courier New"));
	cmbAppFont->Append(wxT("Palatino Linotype"));
	cmbAppFont->Append(wxT("Tahoma"));
	cmbAppFont->Append(wxT("Tempus Sans ITC"));
	cmbAppFont->Append(wxT("Times New Roman"));
	cmbAppFont->Append(wxT("Trebuchet MS"));
	cmbAppFont->Append(wxT("Verdana"));
	cmbAppFont->SetSelection(10);
	GrpAppFont->Add(cmbAppFont, 0, wxALIGN_CENTER | wxALL, 5);

	BtnAppFont = new wxRadioButton(GrpAppFont->GetStaticBox(), wxID_ANY, wxT("BOLD"), wxDefaultPosition, wxDefaultSize, 0);
	BtnAppFont->SetFont(wxFont(12, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxT("Trebuchet MS")));

	GrpAppFont->Add(BtnAppFont, 0, wxALIGN_CENTER | wxALL, 5);

	FontWrapper->Add(GrpAppFont, 0, wxALL | wxEXPAND, 5);

	wxStaticBoxSizer* GrpPreview;
	GrpPreview = new wxStaticBoxSizer(new wxStaticBox(TabFonts, wxID_ANY, wxT(" Song Preview Font: ")), wxHORIZONTAL);

	GrpPreview->SetMinSize(wxSize(-1, 100));
	LblPreview = new wxStaticText(GrpPreview->GetStaticBox(), wxID_ANY, wxT("15"), wxDefaultPosition, wxSize(25, -1), 0);
	LblPreview->Wrap(-1);
	LblPreview->SetFont(wxFont(12, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Trebuchet MS")));

	GrpPreview->Add(LblPreview, 0, wxALIGN_CENTER | wxALL, 5);

	BtnPreviewSmaller = new wxBitmapButton(GrpPreview->GetStaticBox(), wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW | 0);

	BtnPreviewSmaller->SetBitmap(wxBitmap(ButtonBitmaps[Button_smaller]));
	GrpPreview->Add(BtnPreviewSmaller, 0, wxALL, 5);

	SldPreview = new wxSlider(GrpPreview->GetStaticBox(), wxID_ANY, 15, 12, 50, wxDefaultPosition, wxDefaultSize, wxSL_BOTH | wxSL_HORIZONTAL);
	GrpPreview->Add(SldPreview, 1, wxALIGN_CENTER | wxALL, 5);

	BtnPreviewBigger = new wxBitmapButton(GrpPreview->GetStaticBox(), wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW | 0);

	BtnPreviewBigger->SetBitmap(wxBitmap(ButtonBitmaps[Button_bigger]));
	GrpPreview->Add(BtnPreviewBigger, 0, wxALL, 5);

	cmbPreview = new wxComboBox(GrpPreview->GetStaticBox(), wxID_ANY, wxT("Font Type"), wxDefaultPosition, wxDefaultSize, 0, NULL, 0);
	cmbPreview->Append(wxT("Arial"));
	cmbPreview->Append(wxT("Calibri"));
	cmbPreview->Append(wxT("Century Gothic"));
	cmbPreview->Append(wxT("Comic Sans MS"));
	cmbPreview->Append(wxT("Corbel"));
	cmbPreview->Append(wxT("Courier New"));
	cmbPreview->Append(wxT("Palatino Linotype"));
	cmbPreview->Append(wxT("Tahoma"));
	cmbPreview->Append(wxT("Tempus Sans ITC"));
	cmbPreview->Append(wxT("Times New Roman"));
	cmbPreview->Append(wxT("Trebuchet MS"));
	cmbPreview->Append(wxT("Verdana"));
	cmbPreview->SetSelection(10);
	GrpPreview->Add(cmbPreview, 0, wxALIGN_CENTER | wxALL, 5);

	BtnPreview = new wxRadioButton(GrpPreview->GetStaticBox(), wxID_ANY, wxT("BOLD"), wxDefaultPosition, wxDefaultSize, 0);
	BtnPreview->SetFont(wxFont(12, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxT("Trebuchet MS")));

	GrpPreview->Add(BtnPreview, 0, wxALIGN_CENTER | wxALL, 5);

	FontWrapper->Add(GrpPreview, 1, wxEXPAND, 5);

	wxStaticBoxSizer* GrpProjection;
	GrpProjection = new wxStaticBoxSizer(new wxStaticBox(TabFonts, wxID_ANY, wxT(" Song Projection Font: ")), wxHORIZONTAL);

	GrpProjection->SetMinSize(wxSize(-1, 100));
	LblProjection = new wxStaticText(GrpProjection->GetStaticBox(), wxID_ANY, wxT("15"), wxDefaultPosition, wxSize(25, -1), 0);
	LblProjection->Wrap(-1);
	LblProjection->SetFont(wxFont(12, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Trebuchet MS")));

	GrpProjection->Add(LblProjection, 0, wxALIGN_CENTER | wxALL, 5);

	BtnProjectionSmaller = new wxBitmapButton(GrpProjection->GetStaticBox(), wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW | 0);

	BtnProjectionSmaller->SetBitmap(wxBitmap(ButtonBitmaps[Button_smaller]));
	GrpProjection->Add(BtnProjectionSmaller, 0, wxALL, 5);

	SldProjection = new wxSlider(GrpProjection->GetStaticBox(), wxID_ANY, 15, 12, 50, wxDefaultPosition, wxDefaultSize, wxSL_BOTH | wxSL_HORIZONTAL);
	GrpProjection->Add(SldProjection, 1, wxALIGN_CENTER | wxALL, 5);

	BtnProjectionBigger = new wxBitmapButton(GrpProjection->GetStaticBox(), wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW | 0);

	BtnProjectionBigger->SetBitmap(wxBitmap(ButtonBitmaps[Button_bigger]));
	GrpProjection->Add(BtnProjectionBigger, 0, wxALL, 5);

	cmbProjection = new wxComboBox(GrpProjection->GetStaticBox(), wxID_ANY, wxT("Font Type"), wxDefaultPosition, wxDefaultSize, 0, NULL, 0);
	cmbProjection->Append(wxT("Arial"));
	cmbProjection->Append(wxT("Calibri"));
	cmbProjection->Append(wxT("Century Gothic"));
	cmbProjection->Append(wxT("Comic Sans MS"));
	cmbProjection->Append(wxT("Corbel"));
	cmbProjection->Append(wxT("Courier New"));
	cmbProjection->Append(wxT("Palatino Linotype"));
	cmbProjection->Append(wxT("Tahoma"));
	cmbProjection->Append(wxT("Tempus Sans ITC"));
	cmbProjection->Append(wxT("Times New Roman"));
	cmbProjection->Append(wxT("Trebuchet MS"));
	cmbProjection->Append(wxT("Verdana"));
	cmbProjection->SetSelection(10);
	GrpProjection->Add(cmbProjection, 0, wxALIGN_CENTER | wxALL, 5);

	BtnProjection = new wxRadioButton(GrpProjection->GetStaticBox(), wxID_ANY, wxT("BOLD"), wxDefaultPosition, wxDefaultSize, 0);
	BtnProjection->SetFont(wxFont(12, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxT("Trebuchet MS")));

	GrpProjection->Add(BtnProjection, 0, wxALIGN_CENTER | wxALL, 5);

	FontWrapper->Add(GrpProjection, 1, wxEXPAND, 5);

	TabFonts->SetSizer(FontWrapper);
	TabFonts->Layout();
	FontWrapper->Fit(TabFonts);
	tabMain->AddPage(TabFonts, wxT("Font Management"), false);
	TabTheme = new wxScrolledWindow(tabMain, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHSCROLL | wxVSCROLL);
	TabTheme->SetScrollRate(5, 5);
	wxWrapSizer* ThemeWrapper;
	ThemeWrapper = new wxWrapSizer(wxHORIZONTAL, wxWRAPSIZER_DEFAULT_FLAGS);

	wxStaticBoxSizer* Theme0;
	Theme0 = new wxStaticBoxSizer(new wxStaticBox(TabTheme, wxID_ANY, wxT(" Theme One ")), wxVERTICAL);

	Theme0->SetMinSize(wxSize(120, 170));
	BtnTheme0 = new wxButton(Theme0->GetStaticBox(), wxID_ANY, wxT("Black\n&&\nWhite"), wxDefaultPosition, wxDefaultSize, 0);
	BtnTheme0->SetFont(wxFont(20, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Trebuchet MS")));
	BtnTheme0->SetForegroundColour(wxColour(255, 255, 255));
	BtnTheme0->SetBackgroundColour(wxColour(0, 0, 0));
	BtnTheme0->SetMinSize(wxSize(110, 150));

	Theme0->Add(BtnTheme0, 0, wxALIGN_CENTER | wxALL | wxEXPAND, 5);

	ThemeWrapper->Add(Theme0, 1, wxALL | wxEXPAND, 5);

	wxStaticBoxSizer* Theme1;
	Theme1 = new wxStaticBoxSizer(new wxStaticBox(TabTheme, wxID_ANY, wxT(" Theme Two")), wxVERTICAL);

	Theme1->SetMinSize(wxSize(120, 170));
	BtnTheme1 = new wxButton(Theme1->GetStaticBox(), wxID_ANY, wxT("White\n&&\nBlack"), wxDefaultPosition, wxDefaultSize, 0);
	BtnTheme1->SetFont(wxFont(20, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Trebuchet MS")));
	BtnTheme1->SetForegroundColour(wxColour(0, 0, 0));
	BtnTheme1->SetBackgroundColour(wxColour(255, 255, 255));
	BtnTheme1->SetMinSize(wxSize(110, 150));

	Theme1->Add(BtnTheme1, 0, wxALIGN_CENTER | wxALL | wxEXPAND, 5);

	ThemeWrapper->Add(Theme1, 0, wxALL | wxEXPAND, 5);

	wxStaticBoxSizer* Theme2;
	Theme2 = new wxStaticBoxSizer(new wxStaticBox(TabTheme, wxID_ANY, wxT(" Theme Three")), wxVERTICAL);

	Theme2->SetMinSize(wxSize(120, 170));
	BtnTheme2 = new wxButton(Theme2->GetStaticBox(), wxID_ANY, wxT("Blue\n&&\nWhite"), wxDefaultPosition, wxDefaultSize, 0);
	BtnTheme2->SetFont(wxFont(20, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Trebuchet MS")));
	BtnTheme2->SetForegroundColour(wxColour(255, 255, 255));
	BtnTheme2->SetBackgroundColour(wxColour(0, 0, 255));
	BtnTheme2->SetMinSize(wxSize(110, 150));

	Theme2->Add(BtnTheme2, 0, wxALIGN_CENTER | wxALL | wxEXPAND, 5);

	ThemeWrapper->Add(Theme2, 1, wxALL | wxEXPAND, 5);

	wxStaticBoxSizer* Theme3;
	Theme3 = new wxStaticBoxSizer(new wxStaticBox(TabTheme, wxID_ANY, wxT(" Theme Four")), wxVERTICAL);

	Theme3->SetMinSize(wxSize(120, 170));
	BtnTheme3 = new wxButton(Theme3->GetStaticBox(), wxID_ANY, wxT("White\n&&\nBLue"), wxDefaultPosition, wxDefaultSize, 0);
	BtnTheme3->SetFont(wxFont(20, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Trebuchet MS")));
	BtnTheme3->SetForegroundColour(wxColour(0, 0, 255));
	BtnTheme3->SetBackgroundColour(wxColour(255, 255, 255));
	BtnTheme3->SetMinSize(wxSize(110, 150));

	Theme3->Add(BtnTheme3, 0, wxALIGN_CENTER | wxALL | wxEXPAND, 5);

	ThemeWrapper->Add(Theme3, 1, wxALL | wxEXPAND, 5);

	wxStaticBoxSizer* Theme4;
	Theme4 = new wxStaticBoxSizer(new wxStaticBox(TabTheme, wxID_ANY, wxT(" Theme Five ")), wxVERTICAL);

	Theme4->SetMinSize(wxSize(120, 170));
	BtnTheme4 = new wxButton(Theme4->GetStaticBox(), wxID_ANY, wxT("Green\n&&\nWhite"), wxDefaultPosition, wxDefaultSize, 0);
	BtnTheme4->SetFont(wxFont(20, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Trebuchet MS")));
	BtnTheme4->SetForegroundColour(wxColour(255, 255, 255));
	BtnTheme4->SetBackgroundColour(wxColour(0, 128, 0));
	BtnTheme4->SetMinSize(wxSize(110, 150));

	Theme4->Add(BtnTheme4, 0, wxALIGN_CENTER | wxALL | wxEXPAND, 5);

	ThemeWrapper->Add(Theme4, 1, wxALL | wxEXPAND, 5);

	wxStaticBoxSizer* Theme5;
	Theme5 = new wxStaticBoxSizer(new wxStaticBox(TabTheme, wxID_ANY, wxT(" Theme Six")), wxVERTICAL);

	Theme5->SetMinSize(wxSize(120, 170));
	BtnTheme5 = new wxButton(Theme5->GetStaticBox(), wxID_ANY, wxT("White\n&&\nGreen"), wxDefaultPosition, wxDefaultSize, 0);
	BtnTheme5->SetFont(wxFont(20, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Trebuchet MS")));
	BtnTheme5->SetForegroundColour(wxColour(0, 128, 0));
	BtnTheme5->SetBackgroundColour(wxColour(255, 255, 255));
	BtnTheme5->SetMinSize(wxSize(110, 150));

	Theme5->Add(BtnTheme5, 0, wxALIGN_CENTER | wxALL | wxEXPAND, 5);

	ThemeWrapper->Add(Theme5, 1, wxALL | wxEXPAND, 5);

	wxStaticBoxSizer* Theme6;
	Theme6 = new wxStaticBoxSizer(new wxStaticBox(TabTheme, wxID_ANY, wxT(" Theme Seven")), wxVERTICAL);

	Theme6->SetMinSize(wxSize(120, 170));
	BtnTheme6 = new wxButton(Theme6->GetStaticBox(), wxID_ANY, wxT("Orange\n&&\nWhite"), wxDefaultPosition, wxDefaultSize, 0);
	BtnTheme6->SetFont(wxFont(20, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Trebuchet MS")));
	BtnTheme6->SetForegroundColour(wxColour(255, 255, 255));
	BtnTheme6->SetBackgroundColour(wxColour(255, 69, 0));
	BtnTheme6->SetMinSize(wxSize(110, 150));

	Theme6->Add(BtnTheme6, 0, wxALIGN_CENTER | wxALL | wxEXPAND, 5);

	ThemeWrapper->Add(Theme6, 1, wxALL | wxEXPAND, 5);

	wxStaticBoxSizer* Theme7;
	Theme7 = new wxStaticBoxSizer(new wxStaticBox(TabTheme, wxID_ANY, wxT(" Theme Eight")), wxVERTICAL);

	Theme7->SetMinSize(wxSize(120, 170));
	BtnTheme7 = new wxButton(Theme7->GetStaticBox(), wxID_ANY, wxT("White\n&&\nOrange"), wxDefaultPosition, wxDefaultSize, 0);
	BtnTheme7->SetFont(wxFont(20, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Trebuchet MS")));
	BtnTheme7->SetForegroundColour(wxColour(255, 69, 0));
	BtnTheme7->SetBackgroundColour(wxColour(255, 255, 255));
	BtnTheme7->SetMinSize(wxSize(110, 150));

	Theme7->Add(BtnTheme7, 0, wxALIGN_CENTER | wxALL | wxEXPAND, 5);


	ThemeWrapper->Add(Theme7, 1, wxALL | wxEXPAND, 5);

	wxStaticBoxSizer* Theme8;
	Theme8 = new wxStaticBoxSizer(new wxStaticBox(TabTheme, wxID_ANY, wxT(" Theme Nine ")), wxVERTICAL);

	Theme8->SetMinSize(wxSize(120, 170));
	BtnTheme8 = new wxButton(Theme8->GetStaticBox(), wxID_ANY, wxT("Red\n&&\nWhite"), wxDefaultPosition, wxDefaultSize, 0);
	BtnTheme8->SetFont(wxFont(20, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Trebuchet MS")));
	BtnTheme8->SetForegroundColour(wxColour(255, 255, 255));
	BtnTheme8->SetBackgroundColour(wxColour(255, 0, 0));
	BtnTheme8->SetMinSize(wxSize(110, 150));

	Theme8->Add(BtnTheme8, 0, wxALIGN_CENTER | wxALL | wxEXPAND, 5);


	ThemeWrapper->Add(Theme8, 1, wxALL | wxEXPAND, 5);

	wxStaticBoxSizer* Theme9;
	Theme9 = new wxStaticBoxSizer(new wxStaticBox(TabTheme, wxID_ANY, wxT(" Theme Ten ")), wxVERTICAL);

	Theme9->SetMinSize(wxSize(120, 170));
	BtnTheme9 = new wxButton(Theme9->GetStaticBox(), wxID_ANY, wxT("White\n&&\nRed"), wxDefaultPosition, wxDefaultSize, 0);
	BtnTheme9->SetFont(wxFont(20, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Trebuchet MS")));
	BtnTheme9->SetForegroundColour(wxColour(255, 0, 0));
	BtnTheme9->SetBackgroundColour(wxColour(255, 255, 255));
	BtnTheme9->SetMinSize(wxSize(110, 150));

	Theme9->Add(BtnTheme9, 0, wxALIGN_CENTER | wxALL | wxEXPAND, 5);


	ThemeWrapper->Add(Theme9, 1, wxALL | wxEXPAND, 5);

	TabTheme->SetSizer(ThemeWrapper);
	TabTheme->Layout();
	ThemeWrapper->Fit(TabTheme);
	tabMain->AddPage(TabTheme, wxT("Projection Theme"), false);
	TabReset = new wxScrolledWindow(tabMain, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHSCROLL | wxVSCROLL);
	TabReset->SetScrollRate(5, 5);
	tabMain->AddPage(TabReset, wxT("Reset"), false);

	MainWrapper->Add(tabMain, 1, wxEXPAND | wxALL, 5);


	this->SetSizer(MainWrapper);
	this->Layout();
	StatusBar = this->CreateStatusBar(1, wxSTB_SIZEGRIP, wxID_ANY);

	this->Centre(wxBOTH);

	// Connect Events
	BtnTabletMode->Connect(wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler(FrmSettings::BtnTablet_Click), NULL, this);
	BtnSearchCriteria->Connect(wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler(FrmSettings::BtnSearch_Click), NULL, this);
	cmbLanguage->Connect(wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler(FrmSettings::cmbLanguage_Select), NULL, this);
	TxtUserName->Connect(wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler(FrmSettings::TxtUsername_Changed), NULL, this);
	BtnAppFontSmaller->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(FrmSettings::BtnAppFontSmaller_Click), NULL, this);
	SldAppFont->Connect(wxEVT_SCROLL_TOP, wxScrollEventHandler(FrmSettings::SldAppFont_Scroll), NULL, this);
	SldAppFont->Connect(wxEVT_SCROLL_BOTTOM, wxScrollEventHandler(FrmSettings::SldAppFont_Scroll), NULL, this);
	SldAppFont->Connect(wxEVT_SCROLL_LINEUP, wxScrollEventHandler(FrmSettings::SldAppFont_Scroll), NULL, this);
	SldAppFont->Connect(wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler(FrmSettings::SldAppFont_Scroll), NULL, this);
	SldAppFont->Connect(wxEVT_SCROLL_PAGEUP, wxScrollEventHandler(FrmSettings::SldAppFont_Scroll), NULL, this);
	SldAppFont->Connect(wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler(FrmSettings::SldAppFont_Scroll), NULL, this);
	SldAppFont->Connect(wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler(FrmSettings::SldAppFont_Scroll), NULL, this);
	SldAppFont->Connect(wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler(FrmSettings::SldAppFont_Scroll), NULL, this);
	SldAppFont->Connect(wxEVT_SCROLL_CHANGED, wxScrollEventHandler(FrmSettings::SldAppFont_Scroll), NULL, this);
	BtnAppFontBigger->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(FrmSettings::BtnAppFontBigger_Click), NULL, this);
	cmbAppFont->Connect(wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler(FrmSettings::CmbAppFont_Selected), NULL, this);
	BtnAppFont->Connect(wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler(FrmSettings::BtnAppFont_Click), NULL, this);
	BtnPreviewSmaller->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(FrmSettings::BtnAppFontSmaller_Click), NULL, this);
	SldPreview->Connect(wxEVT_SCROLL_TOP, wxScrollEventHandler(FrmSettings::SldAppFont_Scroll), NULL, this);
	SldPreview->Connect(wxEVT_SCROLL_BOTTOM, wxScrollEventHandler(FrmSettings::SldAppFont_Scroll), NULL, this);
	SldPreview->Connect(wxEVT_SCROLL_LINEUP, wxScrollEventHandler(FrmSettings::SldAppFont_Scroll), NULL, this);
	SldPreview->Connect(wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler(FrmSettings::SldAppFont_Scroll), NULL, this);
	SldPreview->Connect(wxEVT_SCROLL_PAGEUP, wxScrollEventHandler(FrmSettings::SldAppFont_Scroll), NULL, this);
	SldPreview->Connect(wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler(FrmSettings::SldAppFont_Scroll), NULL, this);
	SldPreview->Connect(wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler(FrmSettings::SldAppFont_Scroll), NULL, this);
	SldPreview->Connect(wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler(FrmSettings::SldAppFont_Scroll), NULL, this);
	SldPreview->Connect(wxEVT_SCROLL_CHANGED, wxScrollEventHandler(FrmSettings::SldAppFont_Scroll), NULL, this);
	BtnPreviewBigger->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(FrmSettings::BtnAppFontBigger_Click), NULL, this);
	cmbPreview->Connect(wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler(FrmSettings::CmbAppFont_Selected), NULL, this);
	BtnPreview->Connect(wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler(FrmSettings::BtnAppFont_Click), NULL, this);
	BtnProjectionSmaller->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(FrmSettings::BtnAppFontSmaller_Click), NULL, this);
	SldProjection->Connect(wxEVT_SCROLL_TOP, wxScrollEventHandler(FrmSettings::SldAppFont_Scroll), NULL, this);
	SldProjection->Connect(wxEVT_SCROLL_BOTTOM, wxScrollEventHandler(FrmSettings::SldAppFont_Scroll), NULL, this);
	SldProjection->Connect(wxEVT_SCROLL_LINEUP, wxScrollEventHandler(FrmSettings::SldAppFont_Scroll), NULL, this);
	SldProjection->Connect(wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler(FrmSettings::SldAppFont_Scroll), NULL, this);
	SldProjection->Connect(wxEVT_SCROLL_PAGEUP, wxScrollEventHandler(FrmSettings::SldAppFont_Scroll), NULL, this);
	SldProjection->Connect(wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler(FrmSettings::SldAppFont_Scroll), NULL, this);
	SldProjection->Connect(wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler(FrmSettings::SldAppFont_Scroll), NULL, this);
	SldProjection->Connect(wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler(FrmSettings::SldAppFont_Scroll), NULL, this);
	SldProjection->Connect(wxEVT_SCROLL_CHANGED, wxScrollEventHandler(FrmSettings::SldAppFont_Scroll), NULL, this);
	BtnProjectionBigger->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(FrmSettings::BtnAppFontBigger_Click), NULL, this);
	cmbProjection->Connect(wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler(FrmSettings::CmbAppFont_Selected), NULL, this);
	BtnProjection->Connect(wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler(FrmSettings::BtnAppFont_Click), NULL, this);
	BtnTheme0->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(FrmSettings::BtnThemOne_Click), NULL, this);
	BtnTheme1->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(FrmSettings::BtnThemOne_Click), NULL, this);
	BtnTheme2->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(FrmSettings::BtnThemOne_Click), NULL, this);
	BtnTheme3->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(FrmSettings::BtnThemOne_Click), NULL, this);
	BtnTheme4->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(FrmSettings::BtnThemOne_Click), NULL, this);
	BtnTheme5->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(FrmSettings::BtnThemOne_Click), NULL, this);
	BtnTheme6->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(FrmSettings::BtnThemOne_Click), NULL, this);
	BtnTheme7->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(FrmSettings::BtnThemOne_Click), NULL, this);
	BtnTheme8->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(FrmSettings::BtnThemOne_Click), NULL, this);
	BtnTheme9->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(FrmSettings::BtnThemOne_Click), NULL, this);
}
