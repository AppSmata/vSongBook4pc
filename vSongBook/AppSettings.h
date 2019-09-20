class AppSettings
{
	/*const wxString install_date_Key = "install_date";
	const wxString app_user_Key = "app_user";
	const wxString theme_Key = "theme";
	const wxString language_Key = "language";
	const wxString show_startpage_Key = "show_startpage";
	const wxString general_font_size_Key = "general_font_size";
	const wxString general_font_type_Key = "general_font_type";
	const wxString general_font_bold_Key = "general_font_bold";
	const wxString selected_book_Key = "selected_book";
	const wxString selected_song_Key = "selected_song";
	const wxString list_font_bold_Key = "list_font_bold";
	const wxString preview_font_size_Key = "preview_font_size";
	const wxString preview_font_type_Key = "preview_font_type";
	const wxString preview_font_bold_Key = "preview_font_bold";
	const wxString project_font_size_Key = "project_font_size";
	const wxString project_font_type_Key = "project_font_type";
	const wxString project_font_bold_Key = "project_font_bold";
	const wxString edit_mode_Key = "edit_mode";
	const wxString last_window_startup_Key = "last_window_startup";
	const wxString last_window_width_Key = "last_window_width";
	const wxString last_window_height_Key = "last_window_height";
	const wxString tablet_mode_Key = "tablet_mode";
	const wxString show_help_first_Key = "show_help_first";
	const wxString current_song_Key = "current_song";
	const wxString search_allbooks_Key = "search_allbooks";
	const wxString vsb_version_Key = "vsb_version";

	// The default value of our settings
	const wxString install_date_Default = "null";
	const wxString app_user_Default = "null";
	const wxString theme_Default = "1";
	const wxString language_Default = "English";
	const wxString show_startpage_Default = "1";
	const wxString general_font_size_Default = "20";
	const wxString general_font_type_Default = "Trebuchet MS";
	const wxString general_font_bold_Default = "0";
	const wxString selected_book_Default = "0";
	const wxString selected_song_Default = "0";
	const wxString list_font_bold_Default = "0";
	const wxString preview_font_size_Default = "11";
	const wxString preview_font_type_Default = "Trebuchet MS";
	const wxString preview_font_bold_Default = "0";
	const wxString project_font_size_Default = "33";
	const wxString project_font_type_Default = "Trebuchet MS";
	const wxString project_font_bold_Default = "0";
	const wxString edit_mode_Default = "1";
	const wxString last_window_startup_Default = "1";
	const wxString last_window_width_Default = "14085";
	const wxString last_window_height_Default = "8655";
	const wxString tablet_mode_Default = "0";
	const wxString show_help_first_Default = "1";
	const wxString current_song_Default = "3";
	const wxString search_allbooks_Default = "1";
	const wxString vsb_version_Default = "0.1";
private:
	sqlite3pp::database SettingsDB()
	{
		sqlite3pp::database db("Data/Songs.db");
		sqlite3pp::transaction xct(db, true);
		return db;
	}

	void SetNew(const wxString Key, const wxString Value)
	{
		wxString sql_query = "INSERT INTO settings (title, content, created) VALUES('" + Key + "', '" + Value + "', '00-00-0000')";
		sqlite3pp::query qry(SettingsDB(), sql_query);
	}

	bool SetBool(const wxString key)
	{
		long value;
		if (key.ToLong(&value) == 1) return true;
		else return false;
	}

	wxString GetBool(bool key)
	{
		if (key == true) return "1";
		else return "0";
	}

	bool SetCheck(const wxString key)
	{
		int settingid;
		wxString sql_query = "SELECT settingid FROM settings WHERE title='" + key + "' LIMIT 1";
		sqlite3pp::query qry(SettingsDB(), sql_query);
		for (sqlite3pp::query::iterator i = qry.begin(); i != qry.end(); ++i) {
			std::tie(settingid) = (*i).get_columns<int>(0);
		}
		qry.reset();

		if (settingid != 0) return true;
		else return false;
	}

	wxString GetValue(const wxString key)
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

	wxString GetValueOrDefault(const wxString Key, const wxString defaultValue)
	{
		// If the key exists, retrieve the value.
		if (SetCheck(Key))
		{
			wxString value = GetValue(Key);
			if (wxIsEmpty(value)) return defaultValue;
			else return value;
		}
		// Otherwise, use the default value.
		else return defaultValue;
	}

	void SetValue(const wxString Key, const wxString Value)
	{
		wxString sql_query = "UPDATE settings SET content='" + Value + "', updated='00-00-0000' WHERE title='" + Key + "'";
		sqlite3pp::query qry(SettingsDB(), sql_query);
	}


public:
	AppSettings() {}
	virtual ~AppSettings() {}

	// Date the app was installed
	wxString Installed(wxString Value = "")
	{
		if (Value.Length == 0) 
			return GetValueOrDefault(install_date_Key, install_date_Default);
		else {
			SetValue(install_date_Key, Value);
			return Value;
		}
	}
		
	// Name of the User of vSongBook for PC App
	wxString AppUser(wxString Value = "")
	{
		if (Value.Length == 0)
			return GetValueOrDefault(app_user_Key, app_user_Default);
		else {
			SetValue(app_user_Key, Value);
			return Value;
		}
	}

	// Theme of vSongBook for PC App
	int Theme(int Value = 0)
	{
		if (Value == 0) {
			long lgvalue;
			wxString vsb_option = GetValueOrDefault(theme_Key, theme_Default);
			return vsb_option.ToLong(&lgvalue);
		}
		else {
			SetValue(theme_Key, std::to_string(Value));
			return Value;
		}
	}

	// Version of vSongBook for PC App
	wxString VsbVersion(wxString Value = "")
	{
		if (Value.Length == 0)
			return GetValueOrDefault(vsb_version_Key, vsb_version_Default);
		else {
			SetValue(vsb_version_Key, Value);
			return Value;
		}
	}

	// Prefferred language for the user
	wxString Language(wxString Value = "")
	{
		if (Value.Length == 0)
			return GetValueOrDefault(language_Key, language_Default);
		else {
			SetValue(language_Key, Value);
			return Value;
		}
	}

	// Show the startup page for a first time user
	bool ShowStartpage(bool Value = false)
	{
		if (!Value) {
			wxString vsb_option = GetValueOrDefault(show_startpage_Key, show_startpage_Default);
			return SetBool(vsb_option);
		}
		else {
			SetValue(show_startpage_Key, GetBool(Value));
			return Value;
		}
	}

	///General font size for the rest of this app 
	int FontSizeGeneral(int Value = 0)
	{
		if (Value == 0) {
			long lgvalue;
			wxString vsb_option = GetValueOrDefault(general_font_size_Key, general_font_size_Default);
			return vsb_option.ToLong(&lgvalue);
		}
		else {
			SetValue(general_font_size_Key, std::to_string(Value));
			return Value;
		}
	}

	// General font type for the rest of the app
	wxString FontTypeGeneral(wxString Value = "")
	{
		if (Value.Length == 0)
			return GetValueOrDefault(general_font_type_Key, general_font_type_Default);
		else {
			SetValue(general_font_type_Key, Value);
			return Value;
		}
	}

	// General Make text bold for this app.
	bool FontBoldGeneral(bool Value = false)
	{
		if (!Value) {
			wxString vsb_option = GetValueOrDefault(general_font_bold_Key, general_font_bold_Default);
			return SetBool(vsb_option);
		}
		else {
			SetValue(general_font_bold_Key, GetBool(Value));
			return Value;
		}
	}

	// Selected book for editting 
	int SelectedBook(int Value = 0)
	{
		if (Value == 0) {
			long lgvalue;
			wxString vsb_option = GetValueOrDefault(selected_book_Key, selected_book_Default);
			return vsb_option.ToLong(&lgvalue);
		}
		else {
			SetValue(selected_book_Key, std::to_string(Value));
			return Value;
		}
	}

	// Selected song for editting
	int SelectedSong(int Value = 0)
	{
		if (Value == 0) {
			long lgvalue;
			wxString vsb_option = GetValueOrDefault(selected_song_Key, selected_song_Default);
			return vsb_option.ToLong(&lgvalue);
		}
		else {
			SetValue(selected_song_Key, std::to_string(Value));
			return Value;
		}
	}

	// Make text bold for the listed items
	bool FontBoldList(bool Value = false)
	{
		if (!Value) {
			wxString vsb_option = GetValueOrDefault(list_font_bold_Key, list_font_bold_Default);
			return SetBool(vsb_option);
		}
		else {
			SetValue(list_font_bold_Key, GetBool(Value));
			return Value;
		}
	}

	// Font size for the song preview
	int FontSizePreview(int Value = 0)
	{
		if (Value == 0) {
			long lgvalue;
			wxString vsb_option = GetValueOrDefault(preview_font_size_Key, preview_font_size_Default);
			return vsb_option.ToLong(&lgvalue);
		}
		else {
			SetValue(preview_font_size_Key, std::to_string(Value));
			return Value;
		}
	}

	// Font type for song preview
	wxString FontTypePreview(wxString Value = "")
	{
		if (Value.Length == 0)
			return GetValueOrDefault(preview_font_type_Key, preview_font_type_Default);
		else {
			SetValue(preview_font_type_Key, Value);
			return Value;
		}
	}

	// Make text bold for song preview
	bool FontBoldPreview(bool Value = false)
	{
		if (!Value) {
			wxString vsb_option = GetValueOrDefault(project_font_bold_Key, project_font_bold_Default);
			return SetBool(vsb_option);
		}
		else {
			SetValue(project_font_bold_Key, GetBool(Value));
			return Value;
		}
	}

	// Font size for song projection
	int FontSizeProject(int Value = 0)
	{
		if (Value == 0) {
			long lgvalue;
			wxString vsb_option = GetValueOrDefault(project_font_size_Key, project_font_size_Default);
			return vsb_option.ToLong(&lgvalue);
		}
		else {
			SetValue(project_font_size_Key, std::to_string(Value));
			return Value;
		}
	}

	// Font type for song Projection
	wxString FontTypeProject(wxString Value = "")
	{
		if (Value.Length == 0)
			return GetValueOrDefault(project_font_type_Key, project_font_type_Default);
		else {
			SetValue(project_font_type_Key, Value);
			return Value;
		}
	}

	// Make text bold for song projection
	bool FontBoldProject(bool Value = false)
	{
		if (!Value) {
			wxString vsb_option = GetValueOrDefault(project_font_bold_Key, project_font_bold_Default);
			return SetBool(vsb_option);
		}
		else {
			SetValue(project_font_bold_Key, GetBool(Value));
			return Value;
		}
	}

	// Mode of editting songs
	bool ModeEdit(bool Value = false)
	{
		if (!Value) {
			wxString vsb_option = GetValueOrDefault(edit_mode_Key, edit_mode_Default);
			return SetBool(vsb_option);
		}
		else {
			SetValue(edit_mode_Key, GetBool(Value));
			return Value;
		}
	}

	// Mode of startup from last window closed
	int LastWindowStartup(int Value = 0)
	{
		if (Value == 0) {
			long lgvalue;
			wxString vsb_option = GetValueOrDefault(last_window_startup_Key, last_window_startup_Default);
			return vsb_option.ToLong(&lgvalue);
		}
		else {
			SetValue(last_window_startup_Key, std::to_string(Value));
			return Value;
		}
	}

	// Width of last window when closed
	int LastWindowWidth(int Value = 0)
	{
		if (Value == 0) {
			long lgvalue;
			wxString vsb_option = GetValueOrDefault(last_window_width_Key, last_window_width_Default);
			return vsb_option.ToLong(&lgvalue);
		}
		else {
			SetValue(last_window_width_Key, std::to_string(Value));
			return Value;
		}
	}

	// Height of last window closed
	int LastWindowHeight(int Value = 0)
	{
		if (Value == 0) {
			long lgvalue;
			wxString vsb_option = GetValueOrDefault(last_window_height_Key, last_window_height_Default);
			return vsb_option.ToLong(&lgvalue);
		}
		else {
			SetValue(last_window_height_Key, std::to_string(Value));
			return Value;
		}
	}

	// Mode of the user input i.e tablet or normal screen
	bool ModeTablet(bool Value = false)
	{
		if (!Value) {
			wxString vsb_option = GetValueOrDefault(tablet_mode_Key, tablet_mode_Default);
			return SetBool(vsb_option);
		}
		else {
			SetValue(tablet_mode_Key, GetBool(Value));
			return Value;
		}
	}

	// Show help first every time vSongBook is opened
	bool ShowHelpFirst(bool Value = false)
	{
		if (!Value) {
			wxString vsb_option = GetValueOrDefault(show_help_first_Key, show_help_first_Default);
			return SetBool(vsb_option);
		}
		else {
			SetValue(show_help_first_Key, GetBool(Value));
			return Value;
		}
	}

	// The song currently opened 
	int CurrentSong(int Value = 0)
	{
		if (Value == 0) {
			long lgvalue;
			wxString vsb_option = GetValueOrDefault(current_song_Key, current_song_Default);
			return vsb_option.ToLong(&lgvalue);
		}
		else {
			SetValue(current_song_Key, std::to_string(Value));
			return Value;
		}
	}

	// Allow all books to be searched when enabled
	bool SearchAllBooks(bool Value = false)
	{
		if (!Value) {
			wxString vsb_option = GetValueOrDefault(search_allbooks_Key, search_allbooks_Default);
			return SetBool(vsb_option);
		}
		else {
			SetValue(search_allbooks_Key, GetBool(Value));
			return Value;
		}
	}*/
};
