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
#include "vSongView.h"

wxIMPLEMENT_APP(vSongBook);

enum
{
	GaugePage_Reset = wxID_HIGHEST,
	GaugePage_Progress,
	GaugePage_IndeterminateProgress,
	GaugePage_Clear,
	GaugePage_SetValue,
	GaugePage_SetRange,
	GaugePage_CurValueText,
	GaugePage_ValueText,
	GaugePage_RangeText,
	GaugePage_Timer,
	GaugePage_IndeterminateTimer,
	GaugePage_Gauge
};

wxBEGIN_EVENT_TABLE(vSongBook, wxApp)
	EVT_MENU(wxID_EXIT, vSongHome::OnQuit)
	EVT_MENU(wxID_ABOUT, vSongHome::OnAbout)
	EVT_TIMER(GaugePage_Timer, vSongBook::OnProgressTimer)
wxEND_EVENT_TABLE()

vector<wxString> appsets;
unsigned long m_range;

bool vSongBook::OnInit()
{
	if (!wxApp::OnInit()) return false;
	GetSettings();

	TmrSplash = new wxTimer(this, GaugePage_Timer);
	TmrSplash->Start(5000);

	splash = new vAppSplash("vSongBook");
	splash->SetSize(800, 500);
	splash->SetWindowStyle(0 | wxTAB_TRAVERSAL);
	splash->Show(true);
	splash->Center();

	return true;
}

void vSongBook::OnProgressTimer(wxTimerEvent& WXUNUSED(event))
{
	TmrSplash->Stop();
	splash->Close();

	if (appsets[1] == "null")
	{
		vSongCheck* check = new vSongCheck("Set Up your vSongBook to start!");
		check->SetSize(700, 550);
		check->Show(true);
		check->SetWindowStyle(wxCAPTION | wxCLOSE_BOX);
		check->Center();
	}
	else
	{
		vSongHome* home = new vSongHome("vSongBook for Desktop v2.5.2 | " + appsets[1]);
		home->SetSize(1000, 800);
		home->Show(true);
		home->Center();
		home->Maximize(true);
	}
}

void vSongBook::GetSettings()
{
	try {
		sqlite3* db;
		char* err_msg = NULL, ** qryResult = NULL;
		int row, col, rc = sqlite3_open_v2("Data\\Settings.db", &db, SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE, NULL);

		wxString sqlQuery = _T("SELECT content FROM settings ORDER BY settingid");

		rc = sqlite3_get_table(db, sqlQuery, &qryResult, &row, &col, &err_msg);

		for (int i = 1; i < row + 1; i++)
		{
			appsets.push_back(*(qryResult + i * col + 0));
		}

		sqlite3_free_table(qryResult);
		sqlite3_close(db);
	}
	catch (exception & ex) {}
}
