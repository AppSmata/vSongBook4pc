/////////////////////////////////////////////////////////////////////////////
// Name:        vSongBook.h
// Purpose:     vSongBook header
// Author:      Jacksiro
// Created:     25/09/19
// Copyright:   (c) 2019 AppSmata
// Licence:     wxWindows licence
/////////////////////////////////////////////////////////////////////////////

#include "wx/frame.h"
#include "wx/image.h"

#include "ui/vAppSplash.h"

#if wxUSE_LOG
#define USE_LOG 1
#else
#define USE_LOG 0
#endif

// Define a new application

class vSongBook : public wxApp
{
protected:
	wxTimer* TmrSplash;
	wxGauge* AppGauge;
	vAppSplash* splash;

public:
	virtual bool OnInit() wxOVERRIDE;
	void GetSettings();
	void OnProgressTimer(wxTimerEvent& event);

private:
	wxDECLARE_EVENT_TABLE();
};

wxDECLARE_APP(vSongBook);
