/////////////////////////////////////////////////////////////////////////////
// Name:        AppSmata.h
// Purpose:     vSongBook for Desktop
// Author:      Jacksiro
// Modified by:
// Created:     27/07/19
// Copyright:   (c) AppSmata
// Licence:     wxWindows licence
/////////////////////////////////////////////////////////////////////////////

// For compilers that support precompilation, includes "wx.h".
#include "wx/wxprec.h"

#ifdef __BORLANDC__
#pragma hdrstop
#endif

#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

#include "wx/imaglist.h"
#include "wx/artprov.h"
#include "wx/cshelp.h"
#include "wx/utils.h"
#include "wx/string.h"
#include "wx/imaglist.h"
#include "wx/artprov.h"
#include "wx/cshelp.h"
#include "wx/utils.h"


#include <string>
#include <iostream>
#include <ctime>
#include <vector>

#include "sqlite/sqlite3pp.h"

using namespace std;

//std::string DBDir = "Data\\";
//std::string SongsDB = "Songs.db";
//std::string LanguageDB = "Language.db";
//std::string SettingsDB = "Settings.db";

class AppSmata
{
public:
	static void SetOption(wxString title, wxString content)
	{
		sqlite3* db;
		sqlite3_stmt* sqlqueryStmt;
		char* zErrMsg = NULL;
		int row, col, rc = sqlite3_open("Data\\Settings.db", &db);

		wxString sqlQuery = _T("UPDATE settings SET content = '" + content + "' WHERE title = '" + title + "'");

		rc = sqlite3_exec(db, sqlQuery, 0, 0, &zErrMsg);

		if (rc != SQLITE_OK) {
			sqlite3_free(zErrMsg);
		}
		sqlite3_close(db);
	}

	static wxString Today(wxString type)
	{
		//return DateTime.Today.Year + "-" + DateTime.Today.Month + "-" + DateTime.Today.Day;
		//time_t now = time(0);
		//tm* ltm = localtime(&now);
		//wxString TimeStr;
		// print various components of tm structure.
		/*if (type == "T") return "Year" << 1900 + ltm->tm_year << ;
		cout << "Year" << 1900 + ltm->tm_year << endl;
		cout << "Month: " << 1 + ltm->tm_mon << endl;
		cout << "Day: " << ltm->tm_mday << endl;
		cout << "Time: " << 1 + ltm->tm_hour << ":";
		cout << 1 + ltm->tm_min << ":";
		cout << 1 + ltm->tm_sec << endl;*/
		return "";
	}

	static wxString ContentText(wxString songstr)
	{
		songstr = ReplaceAll(songstr, "\\n", " \r\n");
		return wxString::FromUTF8(songstr);
	}

	static wxString ReplaceAll(wxString str, const wxString from, const wxString to)
	{
		size_t start_pos = 0;
		while ((start_pos = str.find(from, start_pos)) != wxString::npos)
		{
			str.replace(start_pos, from.length(), to);
			start_pos += to.length();
		}
		return str;
	}

	static int PresenterFont(int fontint)
	{
		int fontsize = 0.75 * fontint;
		return fontsize;
	}

	static int SelectedValue(wxString value, vector<wxString> values)
	{
		int setvalue = 0;
		for (int i = 1; i < values.size(); i++)
		{
			if (values[i] == value) setvalue = i;
		}
		return setvalue;
	}

};

