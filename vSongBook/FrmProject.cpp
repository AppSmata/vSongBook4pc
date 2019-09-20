#include "AppSmata.h"
#include "FrmProject.h"
#include <wx\tokenzr.h>

int this_book, this_song, bookid, songid, number, slides, slideno, slideindex;
wxString title, alias, content, key, author, chorus, slide;
vector<wxString> songverses1, songverses2;
bool haschorus;

FrmProject::FrmProject(const wxString& title) : wxFrame(NULL, wxID_ANY, title)
{
	enum
	{
		Button_blackwhite_down,
		Button_blackwhite_up,
		Button_max
	};

	wxBitmap ButtonBitmaps[Button_max];

	fcl1 = 255;
	fcl2 = 255;
	fcl3 = 255;

	bcl1 = 0;
	bcl2 = 0;
	bcl3 = 0;

#if USE_XPM_BITMAPS
#define INIT_BTN_BMP(bmp) \
        ButtonBitmaps[Button_##bmp] = wxBitmap(bmp##_xpm)
#else // !USE_XPM_BITMAPS
#define INIT_BTN_BMP(bmp) \
        ButtonBitmaps[Button_##bmp] = wxBITMAP(bmp)
#endif // USE_XPM_BITMAPS/!USE_XPM_BITMAPS

	INIT_BTN_BMP(blackwhite_down);
	INIT_BTN_BMP(blackwhite_up);
	
	this->SetSizeHints(wxDefaultSize, wxDefaultSize);
	this->SetFont(wxFont(12, 75, 90, 92, false, wxT("Trebuchet MS")));
	this->SetBackgroundColour(wxColour(bcl1, bcl2, bcl3));

	BoxMain = new wxBoxSizer(wxVERTICAL);

	PanelMain = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
	AppLabel = new wxStaticBox(PanelMain, wxID_ANY, wxT(" vSongBook for Desktop v2.4.1"));
	AppLabel->SetForegroundColour(wxColour(fcl1, fcl2, fcl3));

	BoxGroup = new wxStaticBoxSizer(AppLabel, wxVERTICAL);

	BoxWrapper = new wxBoxSizer(wxVERTICAL);

	BoxTop = new wxBoxSizer(wxHORIZONTAL);

	TxtCommand = new wxTextCtrl(BoxGroup->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(50, -1), 0);
	TxtCommand->Hide();

	BoxTop->Add(TxtCommand, 1, wxALIGN_CENTER | wxALL, 5);

	LblKey = new wxStaticText(BoxGroup->GetStaticBox(), wxID_ANY, wxT(""), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE);
	LblKey->Wrap(-1);
	LblKey->SetFont(wxFont(20, 75, 90, 92, false, wxT("Trebuchet MS")));
	LblKey->SetForegroundColour(wxColour(fcl1, fcl2, fcl3));

	BoxTop->Add(LblKey, 0, wxALIGN_CENTER | wxALL, 5);

	LblTitle = new wxStaticText(BoxGroup->GetStaticBox(), wxID_ANY, wxT(""), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE);
	LblTitle->Wrap(-1);
	LblTitle->SetFont(wxFont(20, 75, 90, 92, false, wxT("Trebuchet MS")));
	LblTitle->SetForegroundColour(wxColour(fcl1, fcl2, fcl3));

	BoxTop->Add(LblTitle, 1, wxALL, 5);

	BtnClose = new wxButton(BoxGroup->GetStaticBox(), wxID_ANY, wxT("X"), wxDefaultPosition, wxSize(50, -1), 0);
	BtnClose->Hide();
	BoxTop->Add(BtnClose, 0, wxALIGN_CENTER | wxALL, 5);


	BoxWrapper->Add(BoxTop, 0, wxEXPAND, 5);

	LineUp = new wxStaticLine(BoxGroup->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL);
	LineUp->SetBackgroundColour(wxColour(0, 0, 0));

	BoxWrapper->Add(LineUp, 0, wxEXPAND | wxALL, 5);

	BoxMiddle = new wxBoxSizer(wxHORIZONTAL);

	LblContent = new wxStaticText(BoxGroup->GetStaticBox(), wxID_ANY, wxT(""), wxDefaultPosition, wxDefaultSize, 0);
	LblContent->Wrap(-1);
	LblContent->SetFont(wxFont(30, 75, 90, 92, false, wxT("Trebuchet MS")));
	LblContent->SetForegroundColour(wxColour(fcl1, fcl2, fcl3));

	BoxMiddle->Add(LblContent, 1, wxALIGN_CENTER | wxALL, 0);


	BoxWrapper->Add(BoxMiddle, 1, wxALIGN_CENTER | wxALL, 5);

	LineDown = new wxStaticLine(BoxGroup->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL);
	LineDown->SetBackgroundColour(wxColour(0, 0, 0));

	BoxWrapper->Add(LineDown, 0, wxEXPAND | wxALL, 5);

	BoxBottom = new wxBoxSizer(wxHORIZONTAL);

	LblSongBook = new wxStaticText(BoxGroup->GetStaticBox(), wxID_ANY, wxT(""), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE);
	LblSongBook->Wrap(-1);
	LblSongBook->SetFont(wxFont(20, 75, 90, 92, false, wxT("Trebuchet MS")));
	LblSongBook->SetForegroundColour(wxColour(fcl1, fcl2, fcl3));

	BoxBottom->Add(LblSongBook, 0, wxALIGN_CENTER | wxALL, 5);

	LblAurthor = new wxStaticText(BoxGroup->GetStaticBox(), wxID_ANY, wxT(""), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE);
	LblAurthor->Wrap(-1);
	LblAurthor->SetFont(wxFont(20, 75, 90, 92, false, wxT("Trebuchet MS")));
	LblAurthor->SetForegroundColour(wxColour(fcl1, fcl2, fcl3));

	BoxBottom->Add(LblAurthor, 1, wxALIGN_CENTER | wxALL, 5);

	LblVerse = new wxStaticText(BoxGroup->GetStaticBox(), wxID_ANY, wxT(""), wxDefaultPosition, wxDefaultSize, 0);
	LblVerse->Wrap(-1);
	LblVerse->SetFont(wxFont(20, 75, 90, 92, false, wxT("Trebuchet MS")));
	LblVerse->SetForegroundColour(wxColour(fcl1, fcl2, fcl3));

	BoxBottom->Add(LblVerse, 1, wxALIGN_CENTER | wxALL, 5);

	BtnLast = new wxBitmapButton(BoxGroup->GetStaticBox(), wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW);
	BtnLast->SetBitmap(wxBitmap(ButtonBitmaps[Button_blackwhite_up]));
	BtnLast->SetBackgroundColour(wxColour(bcl1, bcl2, bcl3));
	BoxBottom->Add(BtnLast, 0, wxALIGN_CENTER | wxALL, 5);

	BtnNext = new wxBitmapButton(BoxGroup->GetStaticBox(), wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW);
	BtnNext->SetBitmap(wxBitmap(ButtonBitmaps[Button_blackwhite_down]));
	BtnNext->SetBackgroundColour(wxColour(bcl1, bcl2, bcl3));
	BoxBottom->Add(BtnNext, 0, wxALIGN_CENTER | wxALL, 5);

	PicLast = new wxStaticBitmap(BoxGroup->GetStaticBox(), wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, 0);
	PicLast->SetBitmap(wxBitmap(ButtonBitmaps[Button_blackwhite_up]));
	PicLast->SetBackgroundColour(wxColour(bcl1, bcl2, bcl3));
	BoxBottom->Add(PicLast, 0, wxALIGN_CENTER | wxALL, 0);

	PicNext = new wxStaticBitmap(BoxGroup->GetStaticBox(), wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, 0);
	PicNext->SetBitmap(wxBitmap(ButtonBitmaps[Button_blackwhite_down]));
	PicNext->SetBackgroundColour(wxColour(bcl1, bcl2, bcl3));
	BoxBottom->Add(PicNext, 0, wxALIGN_CENTER | wxALL, 5);

	BoxWrapper->Add(BoxBottom, 0, wxEXPAND, 5);
	
	BoxGroup->Add(BoxWrapper, 1, wxEXPAND, 5);
	
	PanelMain->SetSizer(BoxGroup);
	PanelMain->Layout();
	BoxGroup->Fit(PanelMain);
	BoxMain->Add(PanelMain, 1, wxEXPAND | wxALL, 5);
	
	this->SetSizer(BoxMain);
	this->Layout();

	this->Centre(wxBOTH);

	TxtCommand->SetFocus();

	AppLabel->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(FrmProject::Anywhere_Click), NULL, this);
	LblKey->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(FrmProject::Anywhere_Click), NULL, this);
	LblTitle->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(FrmProject::Anywhere_Click), NULL, this);
	LineUp->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(FrmProject::Anywhere_Click), NULL, this);
	LblContent->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(FrmProject::Anywhere_Click), NULL, this);
	LineDown->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(FrmProject::Anywhere_Click), NULL, this);
	LblSongBook->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(FrmProject::Anywhere_Click), NULL, this);
	LblAurthor->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(FrmProject::Anywhere_Click), NULL, this);
	LblVerse->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(FrmProject::Anywhere_Click), NULL, this);
	PicLast->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(FrmProject::Anywhere_Click), NULL, this);
	PicNext->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(FrmProject::Anywhere_Click), NULL, this);

	BtnClose->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(FrmProject::BtnClose_Click), NULL, this);

	TxtCommand->Connect(wxEVT_KEY_DOWN, wxKeyEventHandler(FrmProject::TxtCommandLine_KeyDown), NULL, this);
	TxtCommand->Connect(wxEVT_MOUSEWHEEL, wxMouseEventHandler(FrmProject::TxtCommandLine_MouseWheel), NULL, this);
	
	BtnLast->Hide();
	BtnNext->Hide();

	//ProjectSong(AppSmata::GetOpt("current_song"));
	ProjectSong("30");
}

void FrmProject::ProjectSong(wxString setsong)
{
	slides = 0;
	try 
	{
		wxString sql_query = "SELECT songid, bookid, number, title, alias, content, key, author FROM songs WHERE songid=" + setsong;
		sqlite3pp::query qry(AppSmata::SongsDB(), sql_query);
		for (sqlite3pp::query::iterator i = qry.begin(); i != qry.end(); ++i) {
			std::tie(songid, bookid, number, title, alias, content, key, author) =
				(*i).get_columns<int, int, int, char const*, char const*, char const*, char const*, char const*>(0, 1, 2, 3, 4, 5, 6, 7);
		}
		
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
			for (vector<wxString>::iterator i = songverses1.begin(); i != songverses1.end(); ++i) {
				songverses2.push_back(*i);
				songverses2.push_back(chorus);
				slides = slides + 2;
			}
		}
		else slides = songverses2.size();
		slideindex = 0;
		SetProjection();
	}
	catch (exception& ex) {
		LblContent->SetLabel(ex.what());
	}
	
}

void FrmProject::SetProjection()
{
	try
	{
		slideno = slideindex + 1;
		slide = AppSmata::ContentText(songverses2[slideindex]);
		LblTitle->SetLabel(std::to_string(number) + "# " + title);
		LblKey->SetLabel(key);
		LblAurthor->SetLabel("Public Domain");
		LblSongBook->SetLabel(AppSmata::GetSongBook(bookid));
		LblContent->SetLabel(slide);

		if (haschorus)
		{
			if (slide == chorus) LblVerse->SetLabel(" chorus ");
			else LblVerse->SetLabel(" verse " + std::to_string(slideno) + "/" + std::to_string(slides));
		}
		else
		{
			LblVerse->SetLabel(" verse " + std::to_string(slideno) + "/" + std::to_string(slides));
		}

		/*if (slideindex == 0)
		{
			PicLast->Hide();
			PicNext->Show();
		}

		else if (slideindex == (slides - 1))
		{
			PicLast->Show();
			PicNext->Hide();
		}

		else
		{
			PicLast->Show();
			PicNext->Show();
		}*/
	}
	catch (exception& ex) {
		LblContent->SetLabel(ex.what());
	}
}

void FrmProject::Anywhere_Click(wxCommandEvent&)
{
	TxtCommand->SetFocus();
}

void FrmProject::BtnClose_Click(wxCommandEvent&)
{
	this->Close();
}

void FrmProject::TxtCommandLine_KeyDown(wxKeyEvent& event)
{
	switch (event.GetKeyCode()) 
	{
		case WXK_UP:
			try
			{
				if (slideindex != 0)
				{
					slideindex = slideindex - 1;
					SetProjection();
				}
			}
			catch (exception& ex) { }
			break;

		case WXK_DOWN:
			try
			{
				if (slideindex != (slides - 1))
				{
					slideindex = slideindex + 1;
					SetProjection();
				}
			}
			catch (exception& ex) {}
			break;

		case WXK_SUBTRACT:
			/*if (fontsize >= 10)
			{
				try
				{
					fontsize = fontsize - 3;
					settings.FontSizeProject = fontsize;
					lblSongText.Font = new Font(settings.FontTypeProject, settings.FontSizeProject, settings.FontBoldProject ? FontStyle.Bold : FontStyle.Regular, GraphicsUnit.Point, ((byte)(0)));
				}
				catch (Exception) {}
			}*/
			break;

		case WXK_ADD:
			/*if (fontsize >= 50)
			{
				try
				{
					fontsize = fontsize + 3;
					settings.FontSizeProject = fontsize;
					lblSongText.Font = new Font(settings.FontTypeProject, settings.FontSizeProject, settings.FontBoldProject ? FontStyle.Bold : FontStyle.Regular, GraphicsUnit.Point, ((byte)(0)));
				}
				catch (Exception) {}
			}*/
			break;

		case WXK_LEFT:

			break;

		case WXK_RIGHT:

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
		case WXK_NUMPAD0:
		case WXK_HOME:
			//LoadStanza(0);
			break;

		case WXK_NUMPAD1:
		case WXK_SPECIAL1:
			//LoadStanza(0);
			break;

		case WXK_NUMPAD2:
		case WXK_SPECIAL2:
			/*if (stanzas >= 2)
			{
				if (hasChorus) LoadStanza(2);
				else if (!hasChorus && stanzas > 2) LoadStanza(1);
			}*/
			break;

		case WXK_NUMPAD3:
		case WXK_SPECIAL3:
			/*if (stanzas >= 4)
			{
				if (hasChorus) LoadStanza(4);
				else if (!hasChorus && stanzas > 3) LoadStanza(2);
			}*/
			break;

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

		case WXK_NUMPAD6:
		case WXK_SPECIAL6:
			/*if (stanzas >= 10)
			{
				if (hasChorus) LoadStanza(10);
				else if (!hasChorus && stanzas > 6) LoadStanza(5);
			}*/
			break;

		case WXK_NUMPAD7:
		case WXK_SPECIAL7:
			/*if (stanzas >= 12)
			{
				if (hasChorus) LoadStanza(12);
				else if (!hasChorus && stanzas > 7) LoadStanza(6);
			}*/
			break;

		case WXK_NUMPAD8:
		case WXK_SPECIAL8:
			/*if (stanzas >= 14)
			{
				if (hasChorus) LoadStanza(14);
				else if (!hasChorus && stanzas > 8) LoadStanza(7);
			}*/
			break;

		case WXK_NUMPAD9:
		case WXK_SPECIAL9:
			/*if (stanzas >= 16)
			{
				if (hasChorus) LoadStanza(16);
				else if (!hasChorus && stanzas > 9) LoadStanza(8);
			}*/
			break;

		case WXK_CONTROL_C:
			//if (stanzas > 2 && hasChorus) LoadStanza(1);
			break;

		case WXK_END:
			/*if (hasChorus) LoadStanza(stanzas - 2);
			else LoadStanza(stanzas - 1);*/
			break;

		case WXK_CONTROL_V:

			break;

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

		case WXK_ESCAPE:
			this->Close();
			break;
	}
}

void FrmProject::TxtCommandLine_MouseWheel(wxMouseEvent&)
{
	
}