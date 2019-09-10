#include <string>
#include "wx/wx.h"

#pragma once
class AppSettings
{
public:
	AppSettings();

	struct Preferences
	{
		Preferences()
		{
			install_date = "";
			app_user = "";
			theme = 0;
			language = "English";
			show_startpage = 1;
			selected_book = 1;
			selected_song = 1;
			current_song = 1;
			general_font_size = 15;
			general_font_type = "Trebuchet MS";
			general_font_bold = 0;
			preview_font_size = 15;
			preview_font_type = "Trebuchet MS";
			preview_font_bold = 0;
			project_font_size = 15;
			project_font_type = "Trebuchet MS";
			project_font_bold = 0;
			edit_mode = false;
			tablet_mode = false;
			show_help_first = true;
			search_allbooks = true;
			m_useMarkdown = true;
			m_spellcheck = false;
			vsb_version = "2.4.1";

		}

		bool m_useMarkdown;
		bool m_spellcheck;

		wxString install_date;
		wxString app_user;
		int theme;
		wxString language;
		int show_startpage;
		int general_font_size;
		wxString general_font_type;
		int general_font_bold;
		int preview_font_bold;
		int preview_font_size;
		wxString preview_font_type;
		int project_font_size;
		wxString project_font_type;
		int project_font_bold;
		bool edit_mode;
		wxString last_window_startup;
		int last_window_width;
		int last_window_height;
		bool tablet_mode;
		bool show_help_first;
		int selected_book;
		int selected_song;
		int current_song;
		bool search_allbooks;
		wxString vsb_version;
	};

	virtual ~AppSettings();
};

