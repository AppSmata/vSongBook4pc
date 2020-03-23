#include "AsUtils.h"

/*
	QString of the path to the database:: data/vSongBook.db
*/
QString AsUtils::DbNameQstr() { return R"(data/vSongBook.db)"; }

/*
	char of the path to the database:: data/vSongBook.db
*/
char const *AsUtils::DbNameChar() { return R"(data/vSongBook.db)"; }

QString AsUtils::TableBooks() { return "books"; }
QString AsUtils::TableHistory() { return "history"; }
QString AsUtils::TableSettings() { return "settings"; }
QString AsUtils::TableSettingsNavi() { return "settings_navi"; }
QString AsUtils::TableSongs() { return "songs"; }


QString AsUtils::ColumnBookid() { return "bookid"; }
QString AsUtils::ColumnCategoryid() { return "categoryid"; }
QString AsUtils::ColumnEnabled() { return "enabled"; }
QString AsUtils::ColumnTitle() { return "title"; }
QString AsUtils::ColumnContent() { return "content"; }
QString AsUtils::ColumnQcount() { return "qcount"; }
QString AsUtils::ColumnPosition() { return "position"; }
QString AsUtils::ColumnBackpath() { return "backpath"; }
QString AsUtils::ColumnNotes() { return "notes"; }
QString AsUtils::ColumnCreated() { return "created"; }
QString AsUtils::ColumnUpdated() { return "updated"; }

QString AsUtils::ColumnEntry() { return "entry"; }
QString AsUtils::ColumnType() { return "type"; }
QString AsUtils::ColumnItem() { return "item"; }
QString AsUtils::ColumnExtra() { return "extra"; }

QString AsUtils::ColumnSettingid() { return "settingid"; }

QString AsUtils::ColumnNavid() { return "navid"; }
QString AsUtils::ColumnTags() { return "tags"; }

QString AsUtils::ColumnSongid() { return "songid"; }
QString AsUtils::ColumnPostid() { return "postid"; }
QString AsUtils::ColumnNumber() { return "number"; }
QString AsUtils::ColumnBasetype() { return "basetype"; }
QString AsUtils::ColumnAlias() { return "alias"; }
QString AsUtils::ColumnViews() { return "views"; }
QString AsUtils::ColumnKey() { return "key"; }
QString AsUtils::ColumnIsfav() { return "isfav"; }
QString AsUtils::ColumnAuthor() { return "author"; }
QString AsUtils::ColumnWhat() { return "metawhat"; }
QString AsUtils::ColumnWhen() { return "metawhen"; }
QString AsUtils::ColumnWhere() { return "metawhere"; }
QString AsUtils::ColumnWho() { return "metawho"; }
QString AsUtils::ColumnNetthumbs() { return "netthumbs"; }
QString AsUtils::ColumnAcount() { return "acount"; }
QString AsUtils::ColumnUserid() { return "userid"; }

/*
	QString of the time currently
*/
QString AsUtils::TimeNow()
{
	QDateTime qdt(QDateTime::currentDateTime());
	uint time_now = qdt.toTime_t();
	return QString::number(time_now);
}

/*
	QString of the Time Date currently
*/
QString AsUtils::TimeDateNow()
{
	QDate cd = QDate::currentDate();
	QTime ct = QTime::currentTime();
	return cd.toString() + " " + ct.toString();
}

QString AsUtils::CreateBooksTableSql()
{
	return "CREATE TABLE " + TableBooks() + " (" +
		ColumnBookid() + " INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT, " +
		ColumnCategoryid() + " INTEGER, " +
		ColumnEnabled() + " INTEGER NOT NULL DEFAULT '0', " +
		ColumnTitle() + " VARCHAR(100) UNIQUE, " +
		ColumnTags() + " VARCHAR(250) UNIQUE, " +
		ColumnQcount() + " INTEGER NOT NULL DEFAULT '0', " +
		ColumnPosition() + " INTEGER NOT NULL DEFAULT '0', " +
		ColumnContent() + " VARCHAR(1000), " +
		ColumnBackpath() + " VARCHAR(250) UNIQUE, " +
		ColumnCreated() + " VARCHAR(20), " +
		ColumnUpdated() + " VARCHAR(20));";
}

QString AsUtils::CreateHistoryTableSql()
{
	return "CREATE TABLE " + TableHistory() + " (" +
		ColumnEntry() + " INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT, " +
		ColumnType() + " VARCHAR(50) NOT NULL DEFAULT 'SONG', " +
		ColumnItem() + " INTEGER NOT NULL DEFAULT '0', " +
		ColumnTitle() + " VARCHAR(100), " +
		ColumnExtra() + " VARCHAR(200));";
	ColumnCreated() + " VARCHAR(20));";
}

QString AsUtils::CreateSettingsTableSql()
{
	return "CREATE TABLE " + TableSettings() + " (" +
		ColumnSettingid() + " INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT, " +
		ColumnTitle() + " VARCHAR(100), " +
		ColumnContent() + " VARCHAR(1000), " +
		ColumnCreated() + " VARCHAR(20), " +
		ColumnUpdated() + " VARCHAR(20));";
}

QString AsUtils::CreateSettingsNaviTableSql()
{
	return "CREATE TABLE " + TableSettingsNavi() + " (" +
		ColumnNavid() + " INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT, " +
		ColumnEnabled() + " INTEGER NOT NULL DEFAULT '0', " +
		ColumnTitle() + " VARCHAR(100), " +
		ColumnContent() + " VARCHAR(1000), " +
		ColumnExtra() + " VARCHAR(100), " +
		ColumnTags() + " VARCHAR(50));";
}

QString AsUtils::CreateSongsTableSql()
{
	return "CREATE TABLE " + TableSongs() + " (" +
		ColumnSongid() + " INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT, " +
		ColumnPostid() + " INTEGER UNIQUE, " +
		ColumnBookid() + " INTEGER, " +
		ColumnCategoryid() + " INTEGER, " +
		ColumnBasetype() + " VARCHAR(10), " +
		ColumnNumber() + " INTEGER NOT NULL DEFAULT '0', " +
		ColumnAlias() + " VARCHAR(250), " +
		ColumnTitle() + " VARCHAR(100), " +
		ColumnTags() + " VARCHAR(100), " +
		ColumnContent() + " VARCHAR(10000), " +
		ColumnKey() + " VARCHAR(10), " +
		ColumnAuthor() + " VARCHAR(100), " +
		ColumnNotes() + " VARCHAR(250), " +
		ColumnCreated() + " VARCHAR(20), " +
		ColumnUpdated() + " VARCHAR(20), " +
		ColumnWhat() + " VARCHAR(20), " +
		ColumnWhen() + " VARCHAR(20), " +
		ColumnWhere() + " VARCHAR(20), " +
		ColumnWho() + " VARCHAR(20), " +
		ColumnNetthumbs() + " INTEGER, " +
		ColumnViews() + " INTEGER NOT NULL DEFAULT '0', " +
		ColumnIsfav() + " INTEGER NOT NULL DEFAULT '0', " +
		ColumnAcount() + " INTEGER, " +
		ColumnUserid() + " INTEGER);";
}

QString AsUtils::BookSelectSql()
{
	return "SELECT " +
		ColumnBookid() + ", " +
		ColumnCategoryid() + ", " +
		ColumnEnabled() + ", " +
		ColumnTitle() + ", " +
		ColumnTags() + ", " +
		ColumnQcount() + ", " +
		ColumnPosition() + ", " +
		ColumnContent() + ", " +
		ColumnBackpath() + ", " +
		ColumnCreated() + ", " +
		ColumnUpdated() +
		" FROM " + TableBooks();
}

QString AsUtils::BookListSql(QString State)
{
	return BookSelectSql() + " WHERE " + ColumnEnabled() + "=" + State + " ORDER BY " + ColumnPosition();
}

QString AsUtils::BookSingleSql(QString Book)
{
	return BookSelectSql() + " WHERE " + ColumnBookid() + "=" + Book;
}

QString AsUtils::BookSearchSql(QString Search)
{
	QString SqlQuery = BookSelectSql();

	if (!Search.isEmpty())
	{
		SqlQuery.append(" WHERE " + ColumnTitle() + " LIKE '%" + Search + "%' " +
			"OR " + ColumnTags() + " LIKE '%" + Search + "%'");
	}

	SqlQuery.append(" ORDER BY " + ColumnPosition() + " ASC");
	return SqlQuery;
}

QString AsUtils::BookInsertSql(QString Title, QString Category, QString Tags, QString Content, QString Position, QString Songs)
{
	return "INSERT INTO " + TableBooks() +
		"( " + ColumnTitle() + ", " + ColumnCategoryid() + ", " + ColumnTags() + ", " + ColumnContent() + ", " + ColumnPosition() + ", " + ColumnQcount() + ", " + ColumnEnabled() + ", " + ColumnCreated() +
		" ) VALUES ( '" + Title + "', '" + Category + "', '" + Tags + "', '" + Content + "', " + Position + ", " + Songs + ", 1, " + TimeNow() + ")";
}

QString AsUtils::BookUpdateSql(QString Bookid, QString Title, QString Tags, QString Content, QString Songs)
{
	return "UPDATE " + TableBooks() + " SET " + ColumnTitle() + "='" + Title + "', " + ColumnTags() + "='" + Tags +
		"', " + ColumnContent() + "='" + Content + "', " + ColumnQcount() + "='" + Songs + "', " + ColumnUpdated() + "='" + TimeNow() +
		"' WHERE " + ColumnBookid() + "=" + Bookid;
}

QString AsUtils::BookSongsCountSql(QString Bookid, QString Songs)
{
	return "UPDATE " + TableBooks() + " SET " + ColumnQcount() + "='" + Songs + "', " + ColumnUpdated() + "='" + TimeNow() +
		"' WHERE " + ColumnBookid() + "='" + Bookid + "'";
}

char* AsUtils::BookDeleteSql(QString Bookid)
{
	QString SqlQuery = "DELETE FROM " + TableBooks() + " WHERE " + ColumnBookid() + "= " + Bookid + "; " +
		"DELETE FROM " + TableSongs() + " WHERE " + ColumnBookid() + "=" + Bookid;
	QByteArray bar = SqlQuery.toLocal8Bit();
	return bar.data();
}

QString AsUtils::HistorySelectSql()
{
	return "SELECT " +
		ColumnEntry() + ", " +
		ColumnType() + ", " +
		ColumnItem() + ", " +
		ColumnTitle() + ", " +
		ColumnExtra() + ", " +
		ColumnCreated() +
		" FROM " + TableHistory(); //" WHERE " + ColumnCreated() + "=" + STATE;
}

char* AsUtils::SettingsSelectSql()
{
	QString SettingsQry = "SELECT " + ColumnContent() + " FROM " + TableSettings() + " ORDER BY " + ColumnSettingid();
	QByteArray bar = SettingsQry.toLocal8Bit();
	return bar.data();
}

QString AsUtils::SettingsNaviSelectSql(QString Search)
{
	QString SqlQuery = "SELECT " + ColumnNavid() + ", " + ColumnEnabled() + ", " + ColumnTitle() + ", " + ColumnContent() + ", " +
		ColumnExtra() + ", " + ColumnTags() + " FROM " + TableSettingsNavi();

	if (!Search.isEmpty())
	{
		SqlQuery.append(" WHERE " + ColumnTitle() + " LIKE '%" + Search + "%' " +
			"OR " + ColumnContent() + " LIKE '%" + Search + "%'");
	}

	SqlQuery.append(" ORDER BY " + ColumnNavid() + " ASC");
	return SqlQuery;
}

QString AsUtils::SongSelectSql()
{
	return "SELECT " +
		ColumnSongid() + ", " +
		TableSongs() + "." + ColumnBookid() + ", " +
		ColumnNumber() + ", " +
		ColumnAlias() + ", " +
		TableSongs() + "." + ColumnTitle() + ", " +
		TableSongs() + "." + ColumnTags() + ", " +
		TableSongs() + "." + ColumnContent() + ", " +
		ColumnKey() + ", " +
		ColumnAuthor() + ", " +
		ColumnIsfav() + ", " +  
		TableSongs() + "." + ColumnCreated() + ", " +
		TableSongs() + "." + ColumnUpdated() + ", " +
		TableBooks() + "." + ColumnTitle() +
		" FROM " + TableSongs() +
		" INNER JOIN " + TableBooks() + " ON " +
		TableBooks() + "." + ColumnCategoryid() + "=" + TableSongs() + "." + ColumnCategoryid();
}

QString AsUtils::SongSearchSql(QString SearchStr, QString Bookid, bool SearchAll)
{

	QString SqlQuery = SongSelectSql() + " WHERE ";

	if (SearchStr.isEmpty())
		SqlQuery.append(TableSongs() + "." + ColumnCategoryid() + "=" + Bookid);
	else
	{
		bool isNumeric;
        SearchStr.toInt(&isNumeric, 10);
		if (SearchAll)
		{
			if (isNumeric)
			{
				SqlQuery.append(ColumnNumber() + "=" + SearchStr);
			}
			else
			{
				SqlQuery.append(TableSongs() + "." + ColumnTitle() + " LIKE '%" + SearchStr + "%'");
				SqlQuery.append(" OR " + TableSongs() + "." + ColumnAlias() + " LIKE '%" + SearchStr + "%'");
				SqlQuery.append(" OR " + TableSongs() + "." + ColumnContent() + " LIKE '%" + SearchStr + "%'");
			}
		}
		else
		{
			if (isNumeric)
			{
				SqlQuery.append(TableSongs() + "." + ColumnNumber() + "=" + SearchStr);
				SqlQuery.append(" AND " + TableSongs() + "." + ColumnBookid() + "=" + Bookid);
			}
			else
			{
				SqlQuery.append(TableSongs() + "." + ColumnTitle() + " LIKE '%" + SearchStr + "%'");
				SqlQuery.append(" AND " + TableSongs() + "." + ColumnBookid() + "=" + Bookid);
				SqlQuery.append(" OR " + TableSongs() + "." + ColumnAlias() + " LIKE '%" + SearchStr + "%'");
				SqlQuery.append(" AND " + TableSongs() + "." + ColumnBookid() + "=" + Bookid);
				SqlQuery.append(" OR " + TableSongs() + "." + ColumnContent() + " LIKE '%" + SearchStr + "%'");
				SqlQuery.append(" AND " + TableSongs() + "." + ColumnBookid() + "=" + Bookid);
			}
		}
	}

	SqlQuery.append(" ORDER BY number ASC");
	return SqlQuery;
}

QString AsUtils::SongSingleSql(QString Song)
{
	return SongSelectSql() + " WHERE " + ColumnSongid() + "=" + Song;
}

QString AsUtils::SongInsertSql(QString Bookid, QString Categoryid, QString Number, QString Title, QString Alias, QString Content, QString Key, QString Author)
{
	return "INSERT INTO " + TableSongs() +
		"( " + ColumnNumber() + ", " + ColumnTitle() + ", " + ColumnAlias() + ", " + ColumnContent() + ", " + ColumnKey() + 
		", " + ColumnAuthor() + ", " + ColumnBookid() + ", " + ColumnCategoryid() + ", " + ColumnCreated() + " ) VALUES ( " +
		Number + ", '" + Title + "', '" + Alias + "', '" + Content + "', '" + Key + "', '" + 
		Author + "', " + Bookid + ", " + Categoryid + ", " + TimeNow() + ")";
}

QString AsUtils::SongUpdateSql(QString Number, QString Title, QString Alias, QString Content, QString Key, QString Author, QString Songid)
{
	return "UPDATE " + TableSongs() + " SET " + ColumnNumber() + "=" + Number + ", " + ColumnTitle() + "='" + Title +
		"', " + ColumnAlias() + "='" + Alias + "', " + ColumnContent() + "='" + Content + "', " + ColumnKey() + "='" + Key + 
		"', " + ColumnAuthor() + "='" + Author + "', " + ColumnUpdated() + "='" + TimeNow() + "' WHERE " + ColumnSongid() + "=" + Songid;
}

char const *AsUtils::SongDeleteSql(QString Songid)
{
	QString SqlQuery = "DELETE FROM " + TableSongs() + " WHERE " + ColumnSongid() + "=" + Songid;
	QByteArray bar = SqlQuery.toLocal8Bit();
	return bar.data();
}

QString AsUtils::GetSettingsSql(QString Title)
{
	return "SELECT Content FROM " + TableSettings() + " WHERE " + ColumnTitle() + "='" + Title + "'";
}

QString AsUtils::UpdateSettingsSql(QString Title, QString Value)
{
	return "UPDATE " + TableSettings() + " SET " + ColumnContent() + "='" + Value + "', " +
		ColumnUpdated() + "='" + TimeNow() + "' WHERE " + ColumnTitle() + "='" + Title + "'";
}

QString AsUtils::SettingsNaviSql()
{
	QString SqlQuery = "INSERT INTO " + TableSettingsNavi() + "(" + ColumnEnabled() + ", " + ColumnTitle() + ", " + ColumnContent() + 
		", " + ColumnExtra() + ", " + ColumnTags() + ") VALUES ";
	SqlQuery.append("('1', 'General Options', 'Essential preferences', 'general, overrall', NULL),");
	SqlQuery.append("('1', 'App Font Options', 'Font Management for the app, preview, presentation', 'fonts, app', NULL),");
	SqlQuery.append("('1', 'Presentation Themes', 'Set your prefferred theme for presentation', 'projector, projection, presentation', NULL);");
	return SqlQuery;
}

QString AsUtils::SettingsSql()
{
	QString SqlQuery = "INSERT INTO " + TableSettings() + "(" + ColumnTitle() + ", " + ColumnContent() + ", " + ColumnCreated() + ") VALUES ";
	SqlQuery.append("('install_date', NULL, " + TimeNow() + "),");
	SqlQuery.append("('app_user', 'Your Church', " + TimeNow() + "),");
	SqlQuery.append("('theme', '3', " + TimeNow() + "),");
	SqlQuery.append("('language', 'English', " + TimeNow() + "),");
	SqlQuery.append("('show_startpage', '1', " + TimeNow() + "),");
	SqlQuery.append("('selected_book', NULL, " + TimeNow() + "),");
	SqlQuery.append("('selected_song', NULL, " + TimeNow() + "),");
	SqlQuery.append("('list_font_bold', '0', " + TimeNow() + "),");
	SqlQuery.append("('general_font_size', '18', " + TimeNow() + "),");
	SqlQuery.append("('general_font_type', 'Trebuchet MS', " + TimeNow() + "),");
	SqlQuery.append("('general_font_bold','1'," + TimeNow() + "),");
	SqlQuery.append("('preview_font_size', '20', " + TimeNow() + "),");
	SqlQuery.append("('preview_font_type', 'Trebuchet MS', " + TimeNow() + "),");
	SqlQuery.append("('preview_font_bold', '0', " + TimeNow() + "),");
	SqlQuery.append("('present_font_size', '40', " + TimeNow() + "),");
	SqlQuery.append("('present_font_type', 'Trebuchet MS', " + TimeNow() + "),");
	SqlQuery.append("('present_font_bold', '1', " + TimeNow() + "),");
	SqlQuery.append("('edit_mode', '0', " + TimeNow() + "),");
	SqlQuery.append("('last_window_startup', '1', " + TimeNow() + "),");
	SqlQuery.append("('last_window_width', '14085', " + TimeNow() + "),");
	SqlQuery.append("('last_window_height', '8655', " + TimeNow() + "),");
	SqlQuery.append("('tablet_mode', '0', " + TimeNow() + "),");
	SqlQuery.append("('show_help_first', '1', " + TimeNow() + "),");
	SqlQuery.append("('current_song', NULL, " + TimeNow() + "),");
	SqlQuery.append("('search_allbooks', '1', " + TimeNow() + "),");
	SqlQuery.append("('app_theme', '2', " + TimeNow() + "),");
	SqlQuery.append("('dark_mode', '0', " + TimeNow() + ");");
	SqlQuery.append("('base_url', 'http://sing.appsmata.com/', " + TimeNow() + ");");
	return SqlQuery;
}

QString AsUtils::PostsLists()
{
	return "as-api/posts-lists.php";
}

QString AsUtils::PostsSelect()
{
	return "as-api/posts-select.php";
}

QString AsUtils::PostsSingle()
{
	return "as-api/posts-single.php";
}

QString AsUtils::PostsAnswers()
{
	return "as-api/posts-answers.php";
}

QString AsUtils::PostsSearch()
{
	return "as-api/posts-search.php";
}

QString AsUtils::PostsSlider()
{
	return "as-api/posts-slider.php";
}

QString AsUtils::PostsByCategory()
{
	return "as-api/posts-by-category.php";
}

QString AsUtils::CategoriesAll()
{
	return "as-api/categories.php";
}

QString AsUtils::BooksSelect()
{
	return "as-api/book-select.php";
}

QString AsUtils::Feedback()
{
	return "as-api/feedback.php";
}

QString AsUtils::ShowComment()
{
	return "as-api/comment-by-id.php";
}

QString AsUtils::CountComment()
{
	return "as-api/comment-submit.php";
}

QString AsUtils::BackgroundDrawer()
{
	return "as-api/bg-drawer.php";
}

QString AsUtils::UserSignin()
{
	return "as-api/user-signin.php";
}

QString AsUtils::UserSignup()
{
	return "as-api/user-signup.php";
}

QString AsUtils::UserLastseen()
{
	return "as-api/user-lastseen.php";
}
