#include "wx/config.h"
#include "sqlite/sqlite3pp.h"

#ifndef wxHAS_IMAGES_IN_RESOURCES
#include "vSongBook.xpm"
#endif

#include <string>
#include <iostream>
#include <vector>

using namespace std;

class AppSmata
{
public:
	static wxString ContentText(wxString songstr)
	{
		songstr = ReplaceAll(songstr, "\\n", " \r\n");
		songstr = ReplaceAll(songstr, "ũ", "u");
		songstr = ReplaceAll(songstr, "ĩ", "u");
		songstr = ReplaceAll(songstr, "Ũ", "U");
		return songstr;
	}

	static sqlite3pp::database songDb()
	{
		sqlite3pp::database db("Songs.db");
		sqlite3pp::transaction xct(db, true);
		return db;
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

	static wxString GetSongBook(int bookid)
	{
		try
		{
			wxString sql_query = "SELECT title FROM books WHERE bookid=" + std::to_string(bookid);
			sqlite3pp::query qry(AppSmata::songDb(), sql_query);
			wxString title; 
			for (sqlite3pp::query::iterator i = qry.begin(); i != qry.end(); ++i) {
				std::tie(title) = (*i).get_columns<char const*>(0);
			}
			return title;
		}
		catch (exception& ex) {
			return "";
		}

	}

};

