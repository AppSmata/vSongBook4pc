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

#include "wx\preferences.h"
#include "wx/imaglist.h"
#include "wx/artprov.h"
#include "wx/cshelp.h"
#include "wx/utils.h"
#include "wx/string.h"
#include "wx/imaglist.h"
#include "wx/artprov.h"
#include "wx/cshelp.h"
#include "wx/utils.h"

#include "sqlite/sqlite3pp.h"

#include <string>
#include <iostream>
#include <ctime>
#include <vector>

using namespace std;

class AppSmata
{

public:

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

};

