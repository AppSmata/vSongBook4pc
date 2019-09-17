#include "AppSmata.h"
#include "FrmSongSearch.h"
#include "FrmProject.h"
#include <wx/aboutdlg.h>
#include "Notebook/Notebook.h"
#include <wx/msgdlg.h>
#include <wx/stdpaths.h>

int selected_book, selected_song;
wxString search_term;
vector<int> bookids, songids;
vector<wxString> booktitles, songtitles, songaliases, songcontents;


FrmSongSearch::FrmSongSearch(const wxString& title) : wxFrame(NULL, wxID_ANY, title)
{
	SetIcon(wxICON(vsbicon));

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

void FrmSongSearch::PopulateSongbooks()
{
	try {
		int bookscount = cmbSongBooks->GetCount();
		if (bookscount > 0) {
			cmbSongBooks->Clear();
		}

		sqlite3pp::query qry(AppSmata::songDb(), "SELECT bookid, title, songs FROM books WHERE enabled=1 ORDER BY position");

		for (sqlite3pp::query::iterator i = qry.begin(); i != qry.end(); ++i) {
			int bookid, songs;
			char const* title;
			std::tie(bookid, title, songs) = (*i).get_columns<int, char const*, int>(0, 1, 2);
			wxString titles = std::string(title) + " (" + std::to_string(songs) + ")";
			cmbSongBooks->Append(titles);
			bookids.push_back(bookid);
			booktitles.push_back(title);
		}
		qry.reset();
		cmbSongBooks->SetSelection(0);
		PopulateSonglists(bookids[0], "", false);
	}
	catch (exception& ex) {
		SetStatusText(ex.what());
	}
}

void FrmSongSearch::PopulateSonglists(int setbook, wxString searchstr, bool searchall)
{
	try {
		int songcount = lstSongList->GetCount();
		if (songcount > 0) {
			songids.clear();
			songtitles.clear();
			songaliases.clear();
			songcontents.clear();
			lstSongList->Clear();
		}
		wxString sql_query = "SELECT songid, number, title, alias, content, key, author FROM songs WHERE";
		wxString bookstr = std::to_string(setbook);
		wxString searchtotals = " songs found in: " + booktitles[cmbSongBooks->GetSelection()];

		if (searchstr.empty()) sql_query = sql_query + " bookid=" + bookstr;
		else
		{
			if (searchall)
			{
				if (searchstr.IsNumber())
				{
					sql_query = sql_query + " number=" + searchstr;
					searchtotals = " songs found with number: " + searchstr + "#";
				}
				else
				{
					sql_query = sql_query + " title LIKE '%" + searchstr + "%' OR alias LIKE '%" + searchstr +
						"%' OR content LIKE '%" + searchstr + "%'";
					searchtotals = " songs found with words: \"" + searchstr + "\"";
				}
			}
			else
			{
				if (searchstr.IsNumber())
				{
					sql_query = sql_query + " bookid=" + bookstr + " AND number=" + searchstr;
					searchtotals = " songs found with number: " + searchstr + "#";
				}
				else
				{
					sql_query = sql_query + " bookid=" + bookstr + " AND title LIKE '%" + searchstr + "%' OR bookid=" + bookstr +
						" AND alias LIKE '%" + searchstr + "%' OR bookid=" + bookstr + " AND content LIKE '%" + searchstr + "%'";
					searchtotals = " songs found with words: \"" + searchstr + "\"";
				}
			}
		}
		sql_query = sql_query + " ORDER BY number ASC";

		sqlite3pp::query qry(AppSmata::songDb(), sql_query);
		for (sqlite3pp::query::iterator i = qry.begin(); i != qry.end(); ++i) {
			int songid, number;
			char const* title, * alias, * content, * key, * author;
			std::tie(songid, number, title, alias, content, key, author) =
				(*i).get_columns<int, int, char const*, char const*, char const*, char const*, char const*>(0, 1, 2, 3, 4, 5, 6);
			wxString titles = std::to_string(number) + "# " + title;
			lstSongList->Append(titles);
			songids.push_back(songid);
			songtitles.push_back(titles);
			songaliases.push_back(alias);
			songcontents.push_back(content);
		}
		songcount = lstSongList->GetCount();
		if (searchstr.size() > 0)
			GrpSonglist->SetLabelText(" " + std::to_string(songcount) + searchtotals + " ");
		else GrpSonglist->SetLabelText("Click on a song to Preview it and Project");
		qry.reset();
		OpenSongPreview(0);
	}
	catch (exception& ex) {
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
	TxtPreview->SetValue(AppSmata::ContentText(songcontents[setsong]));
	TxtExtras->SetValue(songaliases[setsong]);
}

void FrmSongSearch::Search_Clear(wxCommandEvent&)
{
	txtSearch->Clear();
}

void FrmSongSearch::Search_Song(wxCommandEvent&)
{
	int selected = bookids[cmbSongBooks->GetSelection()];
	wxString searchthis = txtSearch->GetValue();
	PopulateSonglists(selected, searchthis, chkSearchSongs->GetValue());
	SetStatusText("You searched for: \"" + searchthis + "\"");
}

void FrmSongSearch::btnProject_Click(wxCommandEvent&)
{
	FrmProject *frmProject = new FrmProject("vSongBook Projection", selected_song);
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
	/*frmSettings = new FrmSettings("vSongBook Preferences");
	frmSettings->SetSize(840, 600);
	frmSettings->Show(true);
	frmSettings->SetWindowStyle(wxCAPTION | wxCLOSE_BOX);
	frmSettings->Center();*/
}
