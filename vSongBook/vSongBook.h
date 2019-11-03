/////////////////////////////////////////////////////////////////////////////
// Name:        vSongBook.h
// Purpose:     vSongBook header
// Author:      Jacksiro
// Created:     25/09/19
// Copyright:   (c) 2019 AppSmata
// Licence:     wxWindows licence
/////////////////////////////////////////////////////////////////////////////

#include "wx/frame.h"

#if wxUSE_LOG
#define USE_LOG 1
#else
#define USE_LOG 0
#endif

// Define a new application

class vSongBook : public wxApp
{
private:
	wxDECLARE_EVENT_TABLE();

public:
	virtual bool OnInit() wxOVERRIDE;
	const AppSettings::Preferences& GetSettings() const { return _pref; }
	void UpdateSettings(const AppSettings::Preferences& settings);

private:
	wxScopedPtr<wxPreferencesEditor> _prefEditor;
	AppSettings::Preferences _pref;

};

wxDECLARE_APP(vSongBook);
