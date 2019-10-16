#include <wx/string.h>
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

	/*
	static wxString GetOpt(wxString key)
	{
		wxString settvalue = "";
		wxString sql_query = "SELECT content FROM settings WHERE title='" + key + "' LIMIT 1";
		sqlite3pp::query qry(SettingsDB(), sql_query);
		for (sqlite3pp::query::iterator i = qry.begin(); i != qry.end(); ++i) {
			std::tie(settvalue) = (*i).get_columns<wxString>(0);
		}
		qry.reset();
		return settvalue;
	}

	static void SetOpt(wxString Key, wxString Value)
	{
		wxString sql_query = "UPDATE settings SET content='" + Value + "', updated='00-00-0000' WHERE title='" + Key + "'";
		sqlite3pp::query qry(SettingsDB(), sql_query);
	}*/
	
};

