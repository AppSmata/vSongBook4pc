/////////////////////////////////////////////////////////////////////////////
// Name:        vSongHome.cpp
// Purpose:     vSongBook for Desktop
// Author:      Jacksiro
// Modified by:
// Created:     27/07/19
// Copyright:   (c) AppSmata
// Licence:     wxWindows licence
/////////////////////////////////////////////////////////////////////////////

#include "AppSmata.h"
#include "AppSettings.h"
#include "vSongHome.h"

wxString SongDatabase = "Data\\Songs.db", PrefsDatabase = "Data\\Settings.db", selected_book, selected_song, search_term;
vector<wxString> bookids, songids, booktitles, songtitles, songaliases, songcontents, songbooks, bookcodes;

wxScopedPtr<wxPreferencesEditor> _prefEditor;

vSongHome::vSongHome(const wxString& title) : wxFrame(NULL, wxID_ANY, title)
{
	SetIcon(wxICON(vsbicon));

#if wxUSE_MENUS
	wxMenu* fileMenu = new wxMenu;

	// the "About" item should be in the help menu
	wxMenu* helpMenu = new wxMenu;
	//helpMenu->Append(Minimal_About, "&About\tF1", "Show about dialog");

	//fileMenu->Append(Minimal_Quit, "E&xit\tAlt-X", "Quit vSongBook");

	wxMenuBar* menuBar = new wxMenuBar();
	menuBar->Append(fileMenu, "&File");
	menuBar->Append(helpMenu, "&Help");

	// ... and attach this menu bar to the vSongHome
	//SetMenuBar(menuBar);
#else // !wxUSE_MENUS
	// If menus are not available add a button to access the about box
	wxSizer* sizer = new wxBoxSizer(wxHORIZONTAL);
	wxButton* aboutBtn = new wxButton(this, wxID_ANY, "About...");
	aboutBtn->Bind(wxEVT_BUTTON, &vSongHome::OnAbout, this);
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
	WndSplitter->Connect(wxEVT_IDLE, wxIdleEventHandler(vSongHome::WndSplitterOnIdle), NULL, this);

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
	cmbSongBooks->Connect(wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler(vSongHome::GetSelectedBook), NULL, this);
	lstSongList->Connect(wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler(vSongHome::GetSelectedSong), NULL, this);
	txtSearch->Connect(wxEVT_COMMAND_SEARCHCTRL_CANCEL_BTN, wxCommandEventHandler(vSongHome::Search_Clear), NULL, this);
	txtSearch->Connect(wxEVT_COMMAND_SEARCHCTRL_SEARCH_BTN, wxCommandEventHandler(vSongHome::Search_Song), NULL, this);
	txtSearch->Connect(wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler(vSongHome::Search_Song), NULL, this);
	//txtSearch->Bind(wxEVT_COMMAND_TEXT_ENTER, &vSongHome::Search_Song, this);
	this->Connect(btnProject->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler(vSongHome::btnProject_Click));
	this->Connect(btnEdit->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler(vSongHome::btnEdit_Click));
	this->Connect(btnLast->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler(vSongHome::btnLast_Click));
	this->Connect(btnNext->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler(vSongHome::btnNext_Click));
	this->Connect(btnBigger->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler(vSongHome::btnBigger_Click));
	this->Connect(btnSmaller->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler(vSongHome::btnSmaller_Click));
	this->Connect(btnFontset->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler(vSongHome::btnFontset_Click));
	this->Connect(btnBold->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler(vSongHome::btnBold_Click));
	this->Connect(btnBooks->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler(vSongHome::btnBooks_Click));
	this->Connect(btnSettings->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler(vSongHome::btnSettings_Click));
}

void vSongHome::PopulateToolbar()
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

void vSongHome::OnAbout(wxCommandEvent& WXUNUSED(event))
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

void vSongHome::OnQuit(wxCommandEvent& WXUNUSED(event))
{
	Close(true);
}

sqlite3pp::database songDb()
{
	sqlite3pp::database db("Songs.db");
	sqlite3pp::transaction xct(db, true);
	return db;
}

void vSongHome::PopulateSongbooks()
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
	catch (exception & ex) {
		SetStatusText(ex.what());
	}
}

void vSongHome::PopulateSonglists(wxString setbook, wxString searchstr, bool searchall)
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

			if (searchstr.empty()) lstSongList->Append(wxString::FromUTF8(titles));
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

void vSongHome::GetSelectedBook(wxCommandEvent&)
{
	PopulateSonglists(bookids[cmbSongBooks->GetSelection()], "", false);
}

void vSongHome::GetSelectedSong(wxCommandEvent&)
{
	OpenSongPreview(lstSongList->GetSelection());
}

void vSongHome::OpenSongPreview(int setsong)
{
	selected_song = songids[setsong];
	TxtSongTitle->SetValue(songtitles[setsong]);
	TxtPreview->SetValue(AppSmata::ContentText(songcontents[setsong]));
	TxtExtras->SetValue(songaliases[setsong]);
}

void vSongHome::Search_Clear(wxCommandEvent&)
{
	txtSearch->Clear();
}

void vSongHome::Search_Song(wxCommandEvent&)
{
	wxString searchthis = txtSearch->GetValue();
	PopulateSonglists(bookids[cmbSongBooks->GetSelection()], searchthis, chkSearchSongs->GetValue());
	SetStatusText("You searched for: \"" + searchthis + "\"");
}

void vSongHome::btnProject_Click(wxCommandEvent&)
{
	/*frmProject = new FrmProject("vSongBook Projection");

	frmProject->SetSize(1000, 700);
	frmProject->SetWindowStyle(0 | wxTAB_TRAVERSAL);
	frmProject->Show(true);
	frmProject->Center();
	frmProject->Maximize(true);*/
}

void vSongHome::btnEdit_Click(wxCommandEvent&)
{

}

void vSongHome::btnLast_Click(wxCommandEvent&)
{

}

void vSongHome::btnNext_Click(wxCommandEvent&)
{

}

void vSongHome::btnBigger_Click(wxCommandEvent&)
{

}

void vSongHome::btnSmaller_Click(wxCommandEvent&)
{

}

void vSongHome::btnFontset_Click(wxCommandEvent&)
{

}

void vSongHome::btnBold_Click(wxCommandEvent&)
{

}

void vSongHome::btnBooks_Click(wxCommandEvent&)
{

}

void vSongHome::btnSettings_Click(wxCommandEvent&)
{
	/*frmSettings = new FrmSettings("vSongBook Preferences");
	frmSettings->SetSize(840, 600);
	frmSettings->Show(true);
	frmSettings->SetWindowStyle(wxCAPTION | wxCLOSE_BOX);
	frmSettings->Center();*/
}