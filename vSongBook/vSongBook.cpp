/////////////////////////////////////////////////////////////////////////////
// Name:        vSongBook.cpp
// Purpose:     vSongBook source
// Author:      Jacksiro
// Created:     25/09/19
// Copyright:   (c) 2019 AppSmata
// Licence:     wxWindows licence
/////////////////////////////////////////////////////////////////////////////

#include "AppSmata.h"
#include "AppSettings.h"
#include "vSongHome.h"
#include "vSongView.h"
#include "vSongCheck.h"
#include "vSongBook.h"

wxIMPLEMENT_APP(vSongBook);

wxBEGIN_EVENT_TABLE(vSongBook, wxApp)
	EVT_MENU(wxID_EXIT, vSongHome::OnQuit)
	EVT_MENU(wxID_ABOUT, vSongHome::OnAbout)
wxEND_EVENT_TABLE()

vector<wxString> appsets;

bool vSongBook::OnInit()
{
	if (!wxApp::OnInit()) return false;
	GetSettings();

	/*if (appsets[1] == "null") 
	{
		vSongCheck* check = new vSongCheck("Set Up your vSongBook to start!");
		check->SetSize(500, 500);
		check->Show(true);
		check->SetWindowStyle(wxCAPTION | wxCLOSE_BOX);
		check->Center();
	}
	else {*/
		/*vSongHome* home = new vSongHome("vSongBook for Desktop v1.1.4 | " + appsets[1]);
		home->SetSize(1000, 800);
		home->Show(true);
		home->Center();
		home->Maximize(true);*/
		vSongView* present = new vSongView("vSongBook Presentation");
		present->SetSize(1000, 700);
		present->SetWindowStyle(0 | wxTAB_TRAVERSAL);
		present->Show(true);
		present->Center();
		present->Maximize(true);
	//}
	
	return true;
}

void vSongBook::GetSettings()
{
	try {
		SQLiteDB* pSQLite = new SQLiteDB();
		if (pSQLite->OpenConnection("Settings.db", "Data\\"))
		{
			IResult* res = pSQLite->ExcuteSelect("SELECT content FROM settings ORDER BY settingid;");
			if (res)
			{
				while (res->Next()) appsets.push_back(res->ColomnData(0));
				res->Release();
			}
		}
		pSQLite->CloseConnection();
	}
	catch (exception & ex) {}
}
