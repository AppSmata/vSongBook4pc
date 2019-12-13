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
#include "vSongHome.h"
#include "vSongView.h"
#include "vSongPrefs.h"

int homefont, songfont;
wxString selected_book, selected_song, search_term;
vector<wxString> bookids, songids, booktitles, songtitles, songaliases, songcontents, songbooks, bookcodes, homesets;

vSongHome::vSongHome(const wxString& title) : wxFrame(NULL, wxID_ANY, title)
{
	SetIcon(wxICON(appicon));
	this->SetSizeHints(wxDefaultSize, wxDefaultSize);

	GetSettings();
	InitializeSettings();

	//CreateStatusBar(2);
	//SetStatusText("Welcome to vSongBook for Desktop! " + homesets[1]);

	AppStatusbar = this->CreateStatusBar(1, wxST_SIZEGRIP, wxID_ANY);
	
	SetupMenu();

	wxBoxSizer* MainWrapper;
	MainWrapper = new wxBoxSizer(wxVERTICAL);

	AppSplitter = new wxSplitterWindow(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSP_3D | wxSP_BORDER);
	AppSplitter->Connect(wxEVT_IDLE, wxIdleEventHandler(vSongHome::AppSplitterOnIdle), NULL, this);
	AppSplitter->SetMinimumPaneSize(350);

	PanelLeft = new wxPanel(AppSplitter, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
	wxBoxSizer* WrapLeft;
	WrapLeft = new wxBoxSizer(wxVERTICAL);

	TxtSearch = new wxSearchCtrl(PanelLeft, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
#ifndef __WXMAC__
	TxtSearch->ShowSearchButton(true);
#endif
	TxtSearch->ShowCancelButton(true);
	TxtSearch->SetFont(wxFont(18, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Trebuchet MS")));
	WrapLeft->Add(TxtSearch, 0, wxALL | wxEXPAND, 5);

	CmbSongBooks = new wxComboBox(PanelLeft, wxID_ANY, wxT("Songbooks"), wxDefaultPosition, wxSize(-1, -1), 0, NULL, wxCB_READONLY);
	CmbSongBooks->SetFont(wxFont(homefont, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Trebuchet MS")));
	WrapLeft->Add(CmbSongBooks, 0, wxALL | wxEXPAND, 5);

	ChkSearchSongs = new wxCheckBox(PanelLeft, wxID_ANY, wxT("Search All SongBooks"), wxDefaultPosition, wxSize(-1, -1), 0);
	ChkSearchSongs->SetValue(true);
	ChkSearchSongs->SetFont(wxFont(homefont, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Trebuchet MS")));
	WrapLeft->Add(ChkSearchSongs, 0, wxALL | wxEXPAND, 5);

	wxStaticBoxSizer* GrpSearch;
	GrpSearch = new wxStaticBoxSizer(new wxStaticBox(PanelLeft, wxID_ANY, wxT("0 Songs found")), wxVERTICAL);

	LstSongList = new wxListBox(GrpSearch->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, 0);
	LstSongList->SetFont(wxFont(homefont, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Trebuchet MS")));
	GrpSearch->Add(LstSongList, 1, wxALL | wxEXPAND, 5);
	
	WrapLeft->Add(GrpSearch, 1, wxALL | wxEXPAND, 5);

	PanelLeft->SetSizer(WrapLeft);
	PanelLeft->Layout();
	WrapLeft->Fit(PanelLeft);
	PanelRight = new wxPanel(AppSplitter, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
	wxBoxSizer* WrapRight;
	WrapRight = new wxBoxSizer(wxVERTICAL);

	AppToolBar = new wxToolBar(PanelRight, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTB_HORIZONTAL);
	AppToolBar->Realize();

	WrapRight->Add(AppToolBar, 0, wxEXPAND, 5);

	TxtSongTitle = new wxTextCtrl(PanelRight, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY);
	TxtSongTitle->SetFont(wxFont(homefont, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Trebuchet MS")));
	WrapRight->Add(TxtSongTitle, 0, wxALL | wxEXPAND, 5);

	wxStaticBoxSizer* GrpContent;
	GrpContent = new wxStaticBoxSizer(new wxStaticBox(PanelRight, wxID_ANY, wxEmptyString), wxVERTICAL);

	TxtPreview = new wxTextCtrl(GrpContent->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE | wxTE_READONLY);
	TxtPreview->SetFont(wxFont(homefont, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Trebuchet MS")));
	GrpContent->Add(TxtPreview, 1, wxALL | wxEXPAND, 5);

	WrapRight->Add(GrpContent, 1, wxALL | wxEXPAND, 5);

	TxtExtras = new wxTextCtrl(PanelRight, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE | wxTE_READONLY);
	TxtExtras->SetFont(wxFont(homefont, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Trebuchet MS")));
	WrapRight->Add(TxtExtras, 0, wxALL | wxEXPAND, 5);

	PanelRight->SetSizer(WrapRight);
	PanelRight->Layout();
	WrapRight->Fit(PanelRight);
	AppSplitter->SplitVertically(PanelLeft, PanelRight, 450);
	MainWrapper->Add(AppSplitter, 1, wxEXPAND, 5);

	PopulateToolbar();
	PopulateSongbooks();
	SetAppTheme(wxAtoi(homesets[25]));

	this->SetSizer(MainWrapper);
	this->Layout();

	this->Centre(wxBOTH);

	// Connect Events
	CmbSongBooks->Connect(wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler(vSongHome::GetSelectedBook), NULL, this);
	LstSongList->Connect(wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler(vSongHome::GetSelectedSong), NULL, this);
	TxtSearch->Connect(wxEVT_COMMAND_SEARCHCTRL_CANCEL_BTN, wxCommandEventHandler(vSongHome::Search_Clear), NULL, this);
	TxtSearch->Connect(wxEVT_COMMAND_SEARCHCTRL_SEARCH_BTN, wxCommandEventHandler(vSongHome::Search_Song), NULL, this);
	TxtSearch->Connect(wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler(vSongHome::Search_Song), NULL, this);
	//TxtSearch->Bind(wxEVT_COMMAND_TEXT_ENTER, &vSongHome::Search_Song, this);
	this->Connect(BtnProject->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler(vSongHome::BtnProject_Click));
	this->Connect(BtnEdit->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler(vSongHome::BtnEdit_Click));
	this->Connect(BtnLast->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler(vSongHome::BtnLast_Click));
	this->Connect(BtnNext->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler(vSongHome::BtnNext_Click));
	this->Connect(BtnBigger->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler(vSongHome::BtnBigger_Click));
	this->Connect(BtnSmaller->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler(vSongHome::BtnSmaller_Click));
	this->Connect(BtnFontset->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler(vSongHome::BtnFontset_Click));
	this->Connect(BtnBold->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler(vSongHome::BtnBold_Click));
	this->Connect(BtnBooks->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler(vSongHome::BtnBooks_Click));
	this->Connect(BtnSettings->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler(vSongHome::BtnSettings_Click));
	
	ChkNightMode->Connect(wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler(vSongHome::ChkNightMode_Click), NULL, this);
}

void vSongHome::SetupMenu()
{
	Mnu_Menu = new wxMenuBar(0);
	Mnu_File = new wxMenu();
	Mnu_Restart = new wxMenuItem(Mnu_File, wxID_ANY, wxString(wxT("Restart App")), wxEmptyString, wxITEM_NORMAL);
	Mnu_File->Append(Mnu_Restart);

	Mnu_Exit = new wxMenuItem(Mnu_File, wxID_ANY, wxString(wxT("Exit")) + wxT('\t') + wxT("Alt + F4"), wxEmptyString, wxITEM_NORMAL);
	Mnu_File->Append(Mnu_Exit);

	Mnu_Menu->Append(Mnu_File, wxT("File"));

	Mnu_Songs = new wxMenu();
	Mnu_SongNew = new wxMenuItem(Mnu_Songs, wxID_ANY, wxString(wxT("New Song")) + wxT('\t') + wxT("Ctrl + N"), wxEmptyString, wxITEM_NORMAL);
	Mnu_Songs->Append(Mnu_SongNew);

	Mnu_SongEdit = new wxMenuItem(Mnu_Songs, wxID_ANY, wxString(wxT("Edit Song")), wxEmptyString, wxITEM_NORMAL);
	Mnu_Songs->Append(Mnu_SongEdit);

	Mnu_SongFav = new wxMenuItem(Mnu_Songs, wxID_ANY, wxString(wxT("Favorite Song")), wxEmptyString, wxITEM_NORMAL);
	Mnu_Songs->Append(Mnu_SongFav);

	Mnu_SongDelete = new wxMenuItem(Mnu_Songs, wxID_ANY, wxString(wxT("Delete Song")), wxEmptyString, wxITEM_NORMAL);
	Mnu_Songs->Append(Mnu_SongDelete);

	Mnu_Menu->Append(Mnu_Songs, wxT("Songs"));

	Mnu_Books = new wxMenu();
	Mnu_BookEdit = new wxMenuItem(Mnu_Books, wxID_ANY, wxString(wxT("Edit Songbook")), wxEmptyString, wxITEM_NORMAL);
	Mnu_Books->Append(Mnu_BookEdit);

	Mnu_BookFav = new wxMenuItem(Mnu_Books, wxID_ANY, wxString(wxT("Favourite Songbook")), wxEmptyString, wxITEM_NORMAL);
	Mnu_Books->Append(Mnu_BookFav);

	Mnu_BooksManage = new wxMenuItem(Mnu_Books, wxID_ANY, wxString(wxT("Manage Songbooks")) + wxT('\t') + wxT("Ctrl + B"), wxEmptyString, wxITEM_NORMAL);
	Mnu_Books->Append(Mnu_BooksManage);

	Mnu_Menu->Append(Mnu_Books, wxT("Songbooks"));

	Mnu_Search = new wxMenu();
	Mnu_SearchToday = new wxMenuItem(Mnu_Search, wxID_ANY, wxString(wxT("Today")), wxEmptyString, wxITEM_NORMAL);
	Mnu_Search->Append(Mnu_SearchToday);

	Mnu_SearchYesterday = new wxMenuItem(Mnu_Search, wxID_ANY, wxString(wxT("Yesterday")), wxEmptyString, wxITEM_NORMAL);
	Mnu_Search->Append(Mnu_SearchYesterday);

	Mnu_SearchOlder = new wxMenuItem(Mnu_Search, wxID_ANY, wxString(wxT("Older")), wxEmptyString, wxITEM_NORMAL);
	Mnu_Search->Append(Mnu_SearchOlder);

	Mnu_Menu->Append(Mnu_Search, wxT("Search"));

	Mnu_Settings = new wxMenu();
	Mnu_SettingsAll = new wxMenuItem(Mnu_Settings, wxID_ANY, wxString(wxT("Manage Settings")), wxEmptyString, wxITEM_NORMAL);
	Mnu_Settings->Append(Mnu_SettingsAll);

	Mnu_SettingsReset = new wxMenuItem(Mnu_Settings, wxID_ANY, wxString(wxT("Reset Settings")), wxEmptyString, wxITEM_NORMAL);
	Mnu_Settings->Append(Mnu_SettingsReset);

	Mnu_Menu->Append(Mnu_Settings, wxT("Settings"));

	Mnu_Help = new wxMenu();
	Mnu_About = new wxMenuItem(Mnu_Help, wxID_ANY, wxString(wxT("About vSongBook")) + wxT('\t') + wxT("F1"), wxEmptyString, wxITEM_NORMAL);
	Mnu_Help->Append(Mnu_About);

	Mnu_Contacts = new wxMenuItem(Mnu_Help, wxID_ANY, wxString(wxT("Contact Us")), wxEmptyString, wxITEM_NORMAL);
	Mnu_Help->Append(Mnu_Contacts);

	Mnu_Menu->Append(Mnu_Help, wxT("Help"));

	Mnu_Support = new wxMenu();
	Mnu_Donate = new wxMenuItem(Mnu_Support, wxID_ANY, wxString(wxT("How to Donate")), wxEmptyString, wxITEM_NORMAL);
	Mnu_Support->Append(Mnu_Donate);

	Mnu_Menu->Append(Mnu_Support, wxT("Support Us"));

	this->SetMenuBar(Mnu_Menu);
}

void vSongHome::GetSettings()
{
	try {
		sqlite3* db;
		char* err_msg = NULL, ** qryResult = NULL;
		int row, col, rc = sqlite3_open_v2("Data\\Settings.db", &db, SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE, NULL);

		wxString sqlQuery = _T("SELECT content FROM settings ORDER BY settingid");

		rc = sqlite3_get_table(db, sqlQuery, &qryResult, &row, &col, &err_msg);

		for (int i = 1; i < row + 1; i++)
		{
			homesets.push_back(*(qryResult + i * col + 0));
		}

		sqlite3_free_table(qryResult);
		sqlite3_close(db);
	}
	catch (exception & ex) {}
}

void vSongHome::InitializeSettings()
{
	homefont = wxAtoi(homesets[5]);
	songfont = wxAtoi(homesets[11]);
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

	AppToolBar->SetToolBitmapSize(wxSize(w, h));

	BtnProject = AppToolBar->AddTool(wxID_ANY, wxT("Project"), toolBarBitmaps[Tool_project], wxNullBitmap, wxITEM_NORMAL,
		wxT("Project this Song"), wxT("Project this Song"), NULL);

	BtnEdit = AppToolBar->AddTool(wxID_ANY, wxT("Edit"), toolBarBitmaps[Tool_edit], wxNullBitmap, wxITEM_NORMAL,
		wxT("Edit this Song"), wxT("Edit this Song"), NULL);

	AppToolBar->AddSeparator();

	BtnLast = AppToolBar->AddTool(wxID_ANY, wxT("Previous"), toolBarBitmaps[Tool_last], wxNullBitmap, wxITEM_NORMAL,
		wxT("Go to the Previous Song"), wxT("Go to the Previous Song"), NULL);

	BtnNext = AppToolBar->AddTool(wxID_ANY, wxT("Next"), toolBarBitmaps[Tool_next], wxNullBitmap, wxITEM_NORMAL,
		wxT("Go to the Next Song"), wxT("Go to the Next Song"), NULL);

	AppToolBar->AddSeparator();

	BtnBigger = AppToolBar->AddTool(wxID_ANY, wxT("Bigger"), toolBarBitmaps[Tool_bigger], wxNullBitmap,
		wxITEM_NORMAL, wxT("Bigger Font Size"), wxT("Bigger Font Size"), NULL);

	BtnSmaller = AppToolBar->AddTool(wxID_ANY, wxT("Smaller"), toolBarBitmaps[Tool_smaller], wxNullBitmap, wxITEM_NORMAL,
		wxT("Smaller Font Size"), wxT("Smaller Font Size"), NULL);

	BtnFontset = AppToolBar->AddTool(wxID_ANY, wxT("Font"), toolBarBitmaps[Tool_font], wxNullBitmap, wxITEM_NORMAL,
		wxT("Change Font Type"), wxT("Change Font Type"), NULL);

	BtnBold = AppToolBar->AddTool(wxID_ANY, wxT("Bold"), toolBarBitmaps[Tool_bold], wxNullBitmap, wxITEM_NORMAL,
		wxT("Make Bold"), wxT("Make Bold"), NULL);

	AppToolBar->AddSeparator();

	BtnBooks = AppToolBar->AddTool(wxID_ANY, wxT("SongBooks"), toolBarBitmaps[Tool_books], wxNullBitmap, wxITEM_NORMAL,
		wxT("View SongBooks"), wxT("View SongBooks"), NULL);

	BtnSettings = AppToolBar->AddTool(wxID_ANY, wxT("Settings"), toolBarBitmaps[Tool_settings], wxNullBitmap, wxITEM_NORMAL,
		wxT("Manage App Preferences"), wxT("Manage App Preferences"), NULL);
	
	ChkNightMode = new wxCheckBox(AppToolBar, wxID_ANY, wxT("Night Mode"), wxDefaultPosition, wxSize(250, 40), 0);
	ChkNightMode->SetValue(false);
	ChkNightMode->SetFont(wxFont(25, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Trebuchet MS")));
	AppToolBar->AddControl(ChkNightMode);
	
	AppToolBar->Realize();

	//ToolBarSong->SetRows(ToolBarSong->IsVertical() ? ToolBarSong->GetToolsCount() / m_rows : m_rows);
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

void vSongHome::PopulateSongbooks()
{
	try {
		int bookscount = CmbSongBooks->GetCount();
		if (bookscount > 0) CmbSongBooks->Clear();

		sqlite3* db;
		char* err_msg = NULL, ** qryResult = NULL;
		int row, col, rc = sqlite3_open_v2("Data\\Songs.db", &db, SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE, NULL);

		wxString sqlQuery = _T("SELECT bookid, title, songs FROM books WHERE enabled=1 ORDER BY position");

		rc = sqlite3_get_table(db, sqlQuery, &qryResult, &row, &col, &err_msg);

		for (int i = 1; i < row + 1; i++)
		{
			wxString title = *(qryResult + i * col + 1);
			wxString songs = *(qryResult + i * col + 2);

			CmbSongBooks->Append(wxString::FromUTF8(std::string(title) + " (" + songs + ")"));
			bookids.push_back(*(qryResult + i * col + 0));
			booktitles.push_back(title);
		}

		sqlite3_free_table(qryResult);
		sqlite3_close(db);
		CmbSongBooks->SetSelection(0);
		PopulateSonglists(bookids[0], "", false);
	}
	catch (exception & ex) {
		SetStatusText(ex.what());
	}
}

void vSongHome::PopulateSonglists(wxString setbook, wxString searchstr, bool searchall)
{
	try {
		if (LstSongList->GetCount() > 0) {
			songids.clear();
			songtitles.clear();
			songaliases.clear();
			songcontents.clear();
			songbooks.clear();
			LstSongList->Clear();
		}
		wxString searchtotals = " songs found in: " + booktitles[CmbSongBooks->GetSelection()];

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
		int row, col, rc = sqlite3_open_v2("Data\\Songs.db", &db, SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE, NULL);

		wxString sqlQuery = SqlQuery + " ORDER BY number ASC";

		rc = sqlite3_get_table(db, sqlQuery, &qryResult, &row, &col, &err_msg);

		for (int i = 1; i < row + 1; i++)
		{
			wxString titles = std::string(*(qryResult + i * col + 1)) + "# " + *(qryResult + i * col + 2);

			if (searchstr.empty()) LstSongList->Append(wxString::FromUTF8(titles));
			else LstSongList->Append(wxString::FromUTF8(titles + " (" + *(qryResult + i * col + 8) + ")"));

			songids.push_back(*(qryResult + i * col + 0));
			songtitles.push_back(titles);
			songaliases.push_back(*(qryResult + i * col + 3));
			songcontents.push_back(*(qryResult + i * col + 4));
			songbooks.push_back(std::string(*(qryResult + i * col + 7)) + " (" + *(qryResult + i * col + 8) + ")");
		}

		sqlite3_free_table(qryResult);
		sqlite3_close(db);

		LstSongList->SetSelection(0);
		OpenSongPreview(0);
	}
	catch (exception & ex) {
		SetStatusText(ex.what());
	}
}

void vSongHome::GetSelectedBook(wxCommandEvent&)
{
	PopulateSonglists(bookids[CmbSongBooks->GetSelection()], "", false);
}

void vSongHome::GetSelectedSong(wxCommandEvent&)
{
	OpenSongPreview(LstSongList->GetSelection());
}

void vSongHome::OpenSongPreview(int setsong)
{
	selected_song = songids[setsong];
	AppSmata::SetOption("current_song", selected_song);
	TxtSongTitle->SetValue(songtitles[setsong]);
	TxtPreview->SetValue(AppSmata::ContentText(songcontents[setsong]));
	TxtExtras->SetValue(songaliases[setsong]);
}

void vSongHome::Search_Clear(wxCommandEvent&)
{
	TxtSearch->Clear();
}

void vSongHome::Search_Song(wxCommandEvent&)
{
	wxString searchthis = TxtSearch->GetValue();
	PopulateSonglists(bookids[CmbSongBooks->GetSelection()], searchthis, ChkSearchSongs->GetValue());
	SetStatusText("You searched for: \"" + searchthis + "\"");
}

void vSongHome::BtnProject_Click(wxCommandEvent&)
{
	vSongView* present = new vSongView("vSongBook Presentation");
	present->SetSize(1000, 700);
	present->SetWindowStyle(0 | wxTAB_TRAVERSAL);
	present->Show(true);
	present->Center();
	present->Maximize(true);
}

void vSongHome::BtnEdit_Click(wxCommandEvent&)
{

}

void vSongHome::BtnLast_Click(wxCommandEvent&)
{

}

void vSongHome::BtnNext_Click(wxCommandEvent&)
{

}

void vSongHome::BtnBigger_Click(wxCommandEvent&)
{

}

void vSongHome::BtnSmaller_Click(wxCommandEvent&)
{

}

void vSongHome::BtnFontset_Click(wxCommandEvent&)
{

}

void vSongHome::BtnBold_Click(wxCommandEvent&)
{

}

void vSongHome::BtnBooks_Click(wxCommandEvent&)
{

}

void vSongHome::BtnSettings_Click(wxCommandEvent&)
{
	vSongPrefs* settings = new vSongPrefs("vSongBook Preferences");
	settings->SetSize(840, 600);
	settings->Show(true);
	settings->SetWindowStyle(wxCAPTION | wxCLOSE_BOX);
	settings->Center();
}

void vSongHome::ChkNightMode_Click(wxCommandEvent&)
{
	if (ChkNightMode->GetValue() == true)
	{
		AppSmata::SetOption("app_theme", "2");
		SetAppTheme(2);
	}
	else
	{
		AppSmata::SetOption("app_theme", "1");
		SetAppTheme(1);
	}
}

void vSongHome::SetAppTheme(int theme)
{
	switch (theme)
	{
		case 2:
			this->SetBackgroundColour(wxColour(0, 0, 0));
			PanelLeft->SetBackgroundColour(wxColour(0, 0, 0));
			PanelRight->SetBackgroundColour(wxColour(0, 0, 0));
			AppToolBar->SetBackgroundColour(wxColour(0, 0, 0));
			CmbSongBooks->SetBackgroundColour(wxColour(0, 0, 0));
			LstSongList->SetBackgroundColour(wxColour(0, 0, 0));
			TxtSongTitle->SetBackgroundColour(wxColour(0, 0, 0));
			TxtPreview->SetBackgroundColour(wxColour(0, 0, 0));
			TxtExtras->SetBackgroundColour(wxColour(0, 0, 0));

			TxtSearch->SetForegroundColour(wxColour(255, 255, 255));
			CmbSongBooks->SetForegroundColour(wxColour(255, 255, 255));
			ChkSearchSongs->SetForegroundColour(wxColour(255, 255, 255));
			LstSongList->SetForegroundColour(wxColour(255, 255, 255));
			ChkNightMode->SetForegroundColour(wxColour(255, 255, 255));
			TxtSongTitle->SetForegroundColour(wxColour(255, 255, 255));
			TxtPreview->SetForegroundColour(wxColour(255, 255, 255));
			TxtExtras->SetForegroundColour(wxColour(255, 255, 255));
			AppStatusbar->SetForegroundColour(wxColour(255, 255, 255));
			break;

		default:
			this->SetBackgroundColour(wxColour(255, 255, 255));
			PanelLeft->SetBackgroundColour(wxColour(255, 255, 255));
			PanelRight->SetBackgroundColour(wxColour(255, 255, 255));
			AppToolBar->SetBackgroundColour(wxColour(255, 255, 255));
			CmbSongBooks->SetBackgroundColour(wxColour(255, 255, 255));
			LstSongList->SetBackgroundColour(wxColour(255, 255, 255));
			TxtSongTitle->SetBackgroundColour(wxColour(255, 255, 255));
			TxtPreview->SetBackgroundColour(wxColour(255, 255, 255));
			TxtExtras->SetBackgroundColour(wxColour(255, 255, 255));

			TxtSearch->SetForegroundColour(wxColour(0, 0, 0));
			CmbSongBooks->SetForegroundColour(wxColour(0, 0, 0));
			ChkSearchSongs->SetForegroundColour(wxColour(0, 0, 0));
			LstSongList->SetForegroundColour(wxColour(0, 0, 0));
			ChkNightMode->SetForegroundColour(wxColour(0, 0, 0));
			TxtSongTitle->SetForegroundColour(wxColour(0, 0, 0));
			TxtPreview->SetForegroundColour(wxColour(0, 0, 0));
			TxtExtras->SetForegroundColour(wxColour(0, 0, 0));
			AppStatusbar->SetForegroundColour(wxColour(0, 0, 0));
			break;
	}
}

vSongHome::~vSongHome()
{
}
