/////////////////////////////////////////////////////////////////////////////
// Name:        vSongView.cpp
// Purpose:     vSongView for Desktop
// Author:      Jacksiro
// Modified by:
// Created:     27/07/19
// Copyright:   (c) AppSmata
// Licence:     wxWindows licence
/////////////////////////////////////////////////////////////////////////////

#include "AppSmata.h"
#include "vSongView.h"
#include <wx\tokenzr.h>

int this_book, this_song, slides, slideno, slideindex, mainfont, smallfont;
wxString setsong, bookid, songid, number, title, alias, content, key, author, book, chorus, slide, view_fonty;
vector<wxString> songverses1, songverses2, viewset, labels;
bool haschorus;

enum
{
	Button_white,
	Button_white_black_down,
	Button_white_black_up,
	Button_white_blue_down,
	Button_white_blue_up,
	Button_white_red_down,
	Button_white_red_up,
	Button_white_green_down,
	Button_white_green_up,
	Button_white_orange_down,
	Button_white_orange_up,

	Button_black,
	Button_black_white_down,
	Button_black_white_up,

	Button_blue,
	Button_blue_white_down,
	Button_blue_white_up,

	Button_red,
	Button_red_white_down,
	Button_red_white_up,

	Button_green,
	Button_green_white_down,
	Button_green_white_up,

	Button_orange,
	Button_orange_white_down,
	Button_orange_white_up,

	Button_max
};

wxBitmap ViewsButtonsBitmaps[Button_max];

#if USE_XPM_BITMAPS
#define VIEWS_BTN_BMP(bmp) \
        ViewsButtonsBitmaps[Button_##bmp] = wxBitmap(bmp##_xpm)
#else // !USE_XPM_BITMAPS
#define VIEWS_BTN_BMP(bmp) \
        ViewsButtonsBitmaps[Button_##bmp] = wxBITMAP(bmp)
#endif // USE_XPM_BITMAPS/!USE_XPM_BITMAPS

void vSongView::GetSettings()
{
	try {
		if (viewset.size() > 0) viewset.clear();
		sqlite3* db;
		char* err_msg = NULL, ** qryResult = NULL;
		int row, col, rc = sqlite3_open_v2("Data\\Settings.db", &db, SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE, NULL);

		wxString sqlQuery = _T("SELECT content FROM settings ORDER BY settingid");

		rc = sqlite3_get_table(db, sqlQuery, &qryResult, &row, &col, &err_msg);

		for (int i = 1; i < row + 1; i++)
		{
			viewset.push_back(*(qryResult + i * col + 0));
		}

		sqlite3_free_table(qryResult);
		sqlite3_close(db);
	}
	catch (exception & ex) {}
}

void vSongView::InitializeSettings()
{
	view_fonty = viewset[15];
	mainfont = wxAtoi(viewset[14]);
	//smallfont = AppSmata::PresenterFont(mainfont);

	smallfont = 35;

	LblKey->SetFont(wxFont(smallfont, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, view_fonty));
	LblTitle->SetFont(wxFont(smallfont, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, view_fonty));
	BtnClose->SetFont(wxFont(12, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, view_fonty));
	LblContent->SetFont(wxFont(mainfont, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, view_fonty));
	LblSongInfo->SetFont(wxFont(smallfont, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, view_fonty));
	LblAuthor->SetFont(wxFont(smallfont, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, view_fonty));
	LblVerse->SetFont(wxFont(smallfont, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, view_fonty));
}

vSongView::vSongView(const wxString& title) : wxFrame(NULL, wxID_ANY, title)
{
	GetSettings();

	this->SetSizeHints(wxDefaultSize, wxDefaultSize);
	this->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_BTNHIGHLIGHT));

	wxBoxSizer* MainWrapper;
	MainWrapper = new wxBoxSizer(wxVERTICAL);
	
	AppLabel = new wxStaticBox(this, wxID_ANY, wxT(" vSongBook for Desktop v2.5.2 | " + viewset[1]));
	//AppLabel->SetForegroundColour(wxColour(fcl1, fcl2, fcl3));
	wxStaticBoxSizer* GrpMain;
	GrpMain = new wxStaticBoxSizer(AppLabel, wxVERTICAL);

	wxBoxSizer* InnerWrapper;
	InnerWrapper = new wxBoxSizer(wxVERTICAL);

	wxBoxSizer* TopPanel;
	TopPanel = new wxBoxSizer(wxHORIZONTAL);
	SetTopPanel(GrpMain, TopPanel);
	InnerWrapper->Add(TopPanel, 0, wxALL | wxEXPAND, 5);

	LineUp = new wxStaticLine(GrpMain->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL);
	InnerWrapper->Add(LineUp, 0, wxEXPAND | wxALL, 5);


	wxBoxSizer* MidPanel;
	MidPanel = new wxBoxSizer(wxHORIZONTAL);

	SetMidPanel(GrpMain, MidPanel);
	InnerWrapper->Add(MidPanel, 1, wxALIGN_CENTER | wxALL, 0);

	LineDown = new wxStaticLine(GrpMain->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL);
	InnerWrapper->Add(LineDown, 0, wxEXPAND | wxALL, 5);

	wxBoxSizer* DownPanel;
	DownPanel = new wxBoxSizer(wxHORIZONTAL);
	SetDownPanel(GrpMain, DownPanel);

	InnerWrapper->Add(DownPanel, 0, wxALL | wxEXPAND, 5);

	GrpMain->Add(InnerWrapper, 1, wxEXPAND, 5);

	MainWrapper->Add(GrpMain, 1, wxALL | wxEXPAND, 5);

	this->SetSizer(MainWrapper);
	this->Layout();

	this->Centre(wxBOTH);

	InitializeSettings();
	TxtCommand->SetFocus();

	AppLabel->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(vSongView::Anywhere_Click), NULL, this);
	LblKey->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(vSongView::Anywhere_Click), NULL, this);
	LblTitle->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(vSongView::Anywhere_Click), NULL, this);
	LineUp->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(vSongView::Anywhere_Click), NULL, this);
	LblContent->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(vSongView::Anywhere_Click), NULL, this);
	LineDown->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(vSongView::Anywhere_Click), NULL, this);
	LblSongInfo->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(vSongView::Anywhere_Click), NULL, this);
	LblAuthor->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(vSongView::Anywhere_Click), NULL, this);
	LblVerse->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(vSongView::Anywhere_Click), NULL, this);

	//BtnLast->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(vSongView::Anywhere_Click), NULL, this);
	//BtnNext->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(vSongView::Anywhere_Click), NULL, this);

	//PicLast->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(vSongView::Anywhere_Click), NULL, this);
	//PicLastNull->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(vSongView::Anywhere_Click), NULL, this);
	//PicNext->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(vSongView::Anywhere_Click), NULL, this);
	//PicNextNull->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(vSongView::Anywhere_Click), NULL, this);
	BtnClose->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(vSongView::BtnClose_Click), NULL, this);

	//TxtCommand->Connect(wxEVT_MOUSEWHEEL, wxMouseEventHandler(vSongView::TxtCommandLine_MouseWheel), NULL, this);

	TxtCommand->Connect(wxEVT_KEY_DOWN, wxKeyEventHandler(vSongView::TxtCommandLine_KeyDown), NULL, this);

	BtnClose->Hide();
	PresentSong(viewset[23]);
}

void vSongView::SetTopPanel(wxStaticBoxSizer* GrpMain, wxBoxSizer* TopPanel)
{
	LblKey = new wxStaticText(GrpMain->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
	LblKey->Wrap(-1);
	TopPanel->Add(LblKey, 0, wxALL, 5);

	wxBoxSizer* WrapTitle;
	WrapTitle = new wxBoxSizer(wxVERTICAL);

	LblTitle = new wxStaticText(GrpMain->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
	LblTitle->Wrap(-1); 

	WrapTitle->Add(LblTitle, 0, wxALIGN_CENTER | wxALL, 0);
	
	TopPanel->Add(WrapTitle, 1, wxALIGN_CENTER | wxALL, 5);

	BtnClose = new wxButton(GrpMain->GetStaticBox(), wxID_ANY, wxT("X"), wxDefaultPosition, wxSize(40, 20), 0);

	TopPanel->Add(BtnClose, 0, wxALL | wxEXPAND, 5);

	TxtCommand = new wxTextCtrl(GrpMain->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(1, -1), 0);
	TopPanel->Add(TxtCommand, 0, wxALL, 5);

}

void vSongView::SetMidPanel(wxStaticBoxSizer* GrpMain, wxBoxSizer* MidPanel)
{
	wxBoxSizer* WrapContent;
	WrapContent = new wxBoxSizer(wxVERTICAL);

	LblContent = new wxStaticText(GrpMain->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
	LblContent->Wrap(-1);
	WrapContent->Add(LblContent, 0, wxALIGN_CENTER | wxALL, 0);

	MidPanel->Add(WrapContent, 1, wxALIGN_CENTER | wxALL, 5);
}

void vSongView::SetDownPanel(wxStaticBoxSizer* GrpMain, wxBoxSizer* DownPanel)
{
	VIEWS_BTN_BMP(white);
	VIEWS_BTN_BMP(white_black_down);
	VIEWS_BTN_BMP(white_black_up);
	VIEWS_BTN_BMP(white_blue_down);
	VIEWS_BTN_BMP(white_blue_up);
	VIEWS_BTN_BMP(white_red_down);
	VIEWS_BTN_BMP(white_red_up);
	VIEWS_BTN_BMP(white_green_down);
	VIEWS_BTN_BMP(white_green_up);
	VIEWS_BTN_BMP(white_orange_down);
	VIEWS_BTN_BMP(white_orange_up);

	VIEWS_BTN_BMP(black);
	VIEWS_BTN_BMP(black_white_down);
	VIEWS_BTN_BMP(black_white_up);

	VIEWS_BTN_BMP(blue);
	VIEWS_BTN_BMP(black_white_down);
	VIEWS_BTN_BMP(black_white_up);

	VIEWS_BTN_BMP(red);
	VIEWS_BTN_BMP(red_white_down);
	VIEWS_BTN_BMP(red_white_up);

	VIEWS_BTN_BMP(green);
	VIEWS_BTN_BMP(green_white_down);
	VIEWS_BTN_BMP(green_white_up);

	VIEWS_BTN_BMP(orange);
	VIEWS_BTN_BMP(orange_white_down);
	VIEWS_BTN_BMP(orange_white_up);

	LblSongInfo = new wxStaticText(GrpMain->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
	LblSongInfo->Wrap(-1);
	DownPanel->Add(LblSongInfo, 1, wxALL, 5);

	LblAuthor = new wxStaticText(GrpMain->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
	LblAuthor->Wrap(-1);
	DownPanel->Add(LblAuthor, 1, wxALL, 5);

	LblVerse = new wxStaticText(GrpMain->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
	LblVerse->Wrap(-1);
	DownPanel->Add(LblVerse, 0, wxALL, 5);

	wxBoxSizer* WrapArrows;
	WrapArrows = new wxBoxSizer(wxHORIZONTAL);

	/*BtnLast = new wxBitmapButton(GrpMain->GetStaticBox(), wxID_ANY, wxNullBitmap, wxDefaultPosition, wxSize(50, 50), wxBU_AUTODRAW);
	BtnLast->SetBitmap(wxBitmap(ViewsButtonsBitmaps[Button_white_black_up]));
	WrapArrows->Add(BtnLast, 0, wxALL, 5);

	BtnNext = new wxBitmapButton(GrpMain->GetStaticBox(), wxID_ANY, wxNullBitmap, wxDefaultPosition, wxSize(50, 50), wxBU_AUTODRAW);
	BtnNext->SetBitmap(wxBitmap(ViewsButtonsBitmaps[Button_white_black_down]));
	WrapArrows->Add(BtnNext, 0, wxALL, 5);*/

	PicLast = new wxStaticBitmap(GrpMain->GetStaticBox(), wxID_ANY, wxNullBitmap, wxDefaultPosition, wxSize(50, 50), 0);
	PicLast->SetBitmap(wxBitmap(ViewsButtonsBitmaps[Button_white_black_up]));
	WrapArrows->Add(PicLast, 0, wxALL, 5);

	PicNext = new wxStaticBitmap(GrpMain->GetStaticBox(), wxID_ANY, wxNullBitmap, wxDefaultPosition, wxSize(50, 50), 0);
	PicNext->SetBitmap(wxBitmap(ViewsButtonsBitmaps[Button_white_black_down]));
	WrapArrows->Add(PicNext, 0, wxALL, 5);

	DownPanel->Add(WrapArrows, 0, wxALL, 5);
}

void vSongView::PresentSong(wxString setsongid)
{
	slides = 0;
	if (songverses1.size() > 0) songverses1.clear();
	if (songverses2.size() > 0) songverses2.clear();

	try
	{
		sqlite3* db;
		char* err_msg = NULL, ** qryResult = NULL;
		int row, col, rc = sqlite3_open_v2("Data\\Songs.db", &db, SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE, NULL);

		wxString sqlQuery = "SELECT number, songs.title, alias, songs.content, key, author, books.title FROM songs";
			sqlQuery = sqlQuery + " INNER JOIN books ON books.bookid = songs.bookid WHERE songs.songid=" + setsongid;

		rc = sqlite3_get_table(db, sqlQuery, &qryResult, &row, &col, &err_msg);

		number = *(qryResult + 1 * col + 0);
		title = std::string(number + ". " + *(qryResult + 1 * col + 1));
		alias = *(qryResult + 1 * col + 2);
		content = *(qryResult + 1 * col + 3);
		key = *(qryResult + 1 * col + 4);
		author = *(qryResult + 1 * col + 5);
		book = std::string(number + "# " + *(qryResult + 1 * col + 6));

		sqlite3_free_table(qryResult);
		sqlite3_close(db);

		if (content.Contains("CHORUS")) haschorus = true;
		else haschorus = false;

		content = AppSmata::ReplaceAll(content, "\\n\\n", "xxx");

		wxStringTokenizer tokenizer(content, "xxx");
		while (tokenizer.HasMoreTokens())
		{
			wxString token = tokenizer.GetNextToken();
			if (token.Length() > 0)
			{
				if (haschorus)
				{
					if (token.Contains("CHORUS")) {
						token.Replace("CHORUS\\n", "", true);
						chorus = token;
					}
					else songverses1.push_back(token);
				}
				else songverses2.push_back(token);
			}
		}

		if (haschorus)
		{
			int k = 1;
			for (vector<wxString>::iterator i = songverses1.begin(); i != songverses1.end(); ++i) {
				songverses2.push_back(*i);
				songverses2.push_back(chorus);
				slides = slides + 2;

				wxString label = " VERSE " + std::to_string(k) + " / " + std::to_string(songverses1.size());
				labels.push_back(label);
				labels.push_back(" CHORUS ");
				k++;
			}
		}
		else slides = songverses2.size();
		slideindex = 0;
		SetPresentation();		
	}
	catch (exception & ex) {
		LblContent->SetLabel(ex.what());
	}
}

void vSongView::SetPresentation()
{
	try
	{
		slideno = slideindex + 1;
		slide = AppSmata::ContentText(songverses2[slideindex]);
		LblTitle->SetLabel(title);
		LblKey->SetLabel(key);
		LblAuthor->SetLabel(author);
		LblSongInfo->SetLabel(book);
		LblContent->SetLabel(slide);
		LblVerse->SetLabel(labels[slideindex]);

		if (slideindex == 0)
		{
			PicLast->SetBitmap(wxBitmap(ViewsButtonsBitmaps[Button_white]));
			PicNext->SetBitmap(wxBitmap(ViewsButtonsBitmaps[Button_white_black_down]));
		}

		else if (slideindex == (slides - 1))
		{
			PicLast->SetBitmap(wxBitmap(ViewsButtonsBitmaps[Button_white_black_up]));
			PicNext->SetBitmap(wxBitmap(ViewsButtonsBitmaps[Button_white]));
		}

		else
		{
			PicLast->SetBitmap(wxBitmap(ViewsButtonsBitmaps[Button_white_black_up]));
			PicNext->SetBitmap(wxBitmap(ViewsButtonsBitmaps[Button_white_black_down]));
		}
	}
	catch (exception & ex) {
		LblContent->SetLabel(ex.what());
	}
}

void vSongView::Anywhere_Click(wxCommandEvent&)
{
	TxtCommand->SetFocus();
}

void vSongView::BtnClose_Click(wxCommandEvent&)
{
	this->Close();
}

void vSongView::TxtCommandLine_KeyDown(wxKeyEvent& event)
{
	switch (event.GetKeyCode())
	{
		//When Escape Key is Pressed
		case WXK_ESCAPE:
			this->Close();
			break;
		
		//When Up Arrow Key is Pressed
		case WXK_UP:
		case WXK_NUMPAD_UP:
			try
			{
				if (slideindex != 0)
				{
					slideindex = slideindex - 1;
					SetPresentation();
				}
			}
			catch (exception & ex) {}
			break;

		//When Down Arrow Key is Pressed
		case WXK_DOWN:
		case WXK_NUMPAD_DOWN:
			try
			{
				if (slideindex != (slides - 1))
				{
					slideindex = slideindex + 1;
					SetPresentation();
				}
			}
			catch (exception & ex) {}
			break;

		//When Left Arrow Key is Pressed
		case WXK_LEFT:
			if (mainfont >= 10)
			{
				try
				{
					mainfont = mainfont - 2;
					AppSmata::SetOption("projector_font_size", wxString::Format(wxT("%i"), mainfont));
					GetSettings();
					InitializeSettings();
				}
				catch (exception ex) {}
			}
			break;

		//When Right Arrow Key is Pressed
		case WXK_RIGHT:
			if (mainfont <= 100)
			{
				try
				{
					mainfont = mainfont + 2;
					AppSmata::SetOption("projector_font_size", wxString::Format(wxT("%i"), mainfont));
					GetSettings();
					InitializeSettings();
				}
				catch (exception ex) {}
			}
			break;

		//When Letter M Key is Pressed
		case WXK_CONTROL_M:
			/*if (apptheme >= 0)
			{
				try
				{
					apptheme = apptheme - 1;
					ThemeView(apptheme);
					settings.Theme = apptheme;
				}
				catch (Exception) {}
			}*/
			break;

		//When Letter N Key is Pressed
		case WXK_CONTROL_N:
			/*if (apptheme <= 8)
			{
				try
				{
					apptheme = apptheme + 1;
					ThemeView(apptheme);
					settings.Theme = apptheme;
				}
				catch (Exception) {}
			}*/
			break;

		//When Letter Z Key is Pressed
		case WXK_CONTROL_Z:
			/*if (fontno >= 0)
			{
				try
				{
					fontno = fontno - 1;
					settings.FontTypeProject = vsbf.fonTxt(fontno);
					lblSongText.Font = new Font(fontxt, fontsize, settings.FontBoldProject ? FontStyle.Bold : FontStyle.Regular, GraphicsUnit.Point, ((byte)(0)));
				}
				catch (Exception) {}
			}*/
			break;
		
		//When Letter X Key is Pressed
		case WXK_CONTROL_X:
			/*if (fontno <= 11)
			{
				try
				{
					fontno = fontno + 1;
					settings.FontTypeProject = vsbf.fonTxt(fontno);
					lblSongText.Font = new Font(fontxt, fontsize, isBold ? FontStyle.Bold : FontStyle.Regular, GraphicsUnit.Point, ((byte)(0)));
				}
				catch (Exception) {}
			}*/
			break;

		//When Number 0/HOme Key is Pressed
		case WXK_NUMPAD1:
		case WXK_SPECIAL1:
		case WXK_HOME:
		case WXK_PAGEUP:
			try
			{
				if (slideindex != 0)
				{
					slideindex = 0;
					SetPresentation();
				}
			}
			catch (exception & ex) {}
			break;

		//When Number 2 Key is Pressed
		case WXK_NUMPAD2:
		case WXK_SPECIAL2:
			/*if (stanzas >= 2)
			{
				if (hasChorus) LoadStanza(2);
				else if (!hasChorus && stanzas > 2) LoadStanza(1);
			}*/
			break;

		//When Number 3 Key is Pressed
		case WXK_NUMPAD3:
		case WXK_SPECIAL3:
			/*if (stanzas >= 4)
			{
				if (hasChorus) LoadStanza(4);
				else if (!hasChorus && stanzas > 3) LoadStanza(2);
			}*/
			break;

		//When Number 4 Key is Pressed
		case WXK_NUMPAD4:
		case WXK_SPECIAL4:
			/*if (stanzas >= 6)
			{
				if (hasChorus) LoadStanza(6);
				else if (!hasChorus && stanzas > 4) LoadStanza(3);
			}*/
			break;

		case WXK_NUMPAD5:
		case WXK_SPECIAL5:
			/*if (stanzas >= 8)
			{
				if (hasChorus) LoadStanza(8);
				else if (!hasChorus && stanzas > 5) LoadStanza(4);
			}*/
			break;

		//When Number 6 Key is Pressed
		case WXK_NUMPAD6:
		case WXK_SPECIAL6:
			/*if (stanzas >= 10)
			{
				if (hasChorus) LoadStanza(10);
				else if (!hasChorus && stanzas > 6) LoadStanza(5);
			}*/
			break;

		//When Number 7 Key is Pressed
		case WXK_NUMPAD7:
		case WXK_SPECIAL7:
			/*if (stanzas >= 12)
			{
				if (hasChorus) LoadStanza(12);
				else if (!hasChorus && stanzas > 7) LoadStanza(6);
			}*/
			break;

		//When Number 8 Key is Pressed
		case WXK_NUMPAD8:
		case WXK_SPECIAL8:
			/*if (stanzas >= 14)
			{
				if (hasChorus) LoadStanza(14);
				else if (!hasChorus && stanzas > 8) LoadStanza(7);
			}*/
			break;

		//When Number 9 Key is Pressed
		case WXK_NUMPAD9:
		case WXK_SPECIAL9:
			/*if (stanzas >= 16)
			{
				if (hasChorus) LoadStanza(16);
				else if (!hasChorus && stanzas > 9) LoadStanza(8);
			}*/
			break;

		//When Letter C Key is Pressed
		case WXK_CONTROL_C:
			//if (stanzas > 2 && hasChorus) LoadStanza(1);
			break;

		//When End Key is Pressed
		case WXK_END:
		case WXK_PAGEDOWN:
			try
			{
				if (slideindex != (slides - 1))
				{
					slideindex = slides - 1;
					SetPresentation();
				}
			}
			catch (exception & ex) {}
			break;

		//When Letter V Key is Pressed
		case WXK_CONTROL_V:

			break;

		//When Control B Key is Pressed
		case WXK_CONTROL_B:
			/*try
			{
				if (isBold == true)
				{
					settings.FontBoldProject = false;
					isBold = false;
				}
				else if (isBold == false)
				{
					settings.FontBoldProject = true;
					isBold = true;
				}
				try { lblSongText.Font = new Font(fontxt, fontsize, isBold ? FontStyle.Bold : FontStyle.Regular, GraphicsUnit.Point, ((byte)(0))); }
				catch (Exception) {}
			}
			catch (Exception) {}*/
			break;

		/*case Keys.Oemcomma:
			/*if (fontsize >= 10)
			{
				try
				{
					fontsize = fontsize - 2;
					settings.FontSizeProject = fontsize;
					try { lblSongText.Font = new Font(fontxt, fontsize, settings.FontBoldProject ? FontStyle.Bold : FontStyle.Regular, GraphicsUnit.Point, ((byte)(0))); }
					catch (Exception) {}
				}
				catch (Exception) {}
			}* /
			break;

		case Keys.OemPeriod:
			/*if (fontsize <= 90)
			{
				try
				{
					fontsize = fontsize + 2;
					settings.FontSizeProject = fontsize;
					try { lblSongText.Font = new Font(fontxt, fontsize, settings.FontBoldProject ? FontStyle.Bold : FontStyle.Regular, GraphicsUnit.Point, ((byte)(0))); }
					catch (Exception) {}
				}
				catch (Exception) {}
			}* /
			break;*/
	}
}

void vSongView::TxtCommandLine_MouseWheel(wxMouseEvent&)
{

}
vSongView::~vSongView()
{
	// Disconnect Events
	BtnClose->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(vSongView::BtnClose_Click), NULL, this);

}
