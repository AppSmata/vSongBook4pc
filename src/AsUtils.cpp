#include "AsUtils.h"

QString AsUtils::DB_FILE() { return R"(Data/vSongBook.db)"; }
char* AsUtils::APP_DB() { return R"(Data/vSongBook.db)"; }

QString AsUtils::TBL_BOOKS() { return "books"; }
QString AsUtils::TBL_HISTORY() { return "history"; }
QString AsUtils::TBL_SETTINGS() { return "settings"; }
QString AsUtils::TBL_SETTINGS_NAVI() { return "settings_navi"; }
QString AsUtils::TBL_SONGS() { return "songs"; }


QString AsUtils::BOOKID() { return "bookid"; }
QString AsUtils::CATEGORYID() { return "categoryid"; }
QString AsUtils::ENABLED() { return "enabled"; }
QString AsUtils::TITLE() { return "title"; }
QString AsUtils::CONTENT() { return "content"; }
QString AsUtils::QCOUNT() { return "qcount"; }
QString AsUtils::POSITION() { return "position"; }
QString AsUtils::BACKPATH() { return "backpath"; }
QString AsUtils::NOTES() { return "notes"; }
QString AsUtils::CREATED() { return "created"; }
QString AsUtils::UPDATED() { return "updated"; }

QString AsUtils::ENTRY() { return "entry"; }
QString AsUtils::TYPE() { return "type"; }
QString AsUtils::ITEM() { return "item"; }
QString AsUtils::EXTRA() { return "extra"; }

QString AsUtils::SETTINGID() { return "settingid"; }

QString AsUtils::NAVID() { return "navid"; }
QString AsUtils::TAGS() { return "tags"; }

QString AsUtils::SONGID() { return "songid"; }
QString AsUtils::POSTID() { return "postid"; }
QString AsUtils::NUMBER() { return "number"; }
QString AsUtils::BASETYPE() { return "basetype"; }
QString AsUtils::ALIAS() { return "alias"; }
QString AsUtils::VIEWS() { return "views"; }
QString AsUtils::KEY() { return "key"; }
QString AsUtils::ISFAV() { return "isfav"; }
QString AsUtils::AUTHOR() { return "author"; }
QString AsUtils::WHAT() { return "metawhat"; }
QString AsUtils::WHEN() { return "metawhen"; }
QString AsUtils::WHERE() { return "metawhere"; }
QString AsUtils::WHO() { return "metawho"; }
QString AsUtils::NETTHUMBS() { return "netthumbs"; }
QString AsUtils::ACOUNT() { return "acount"; }
QString AsUtils::USERID() { return "userid"; }

QString AsUtils::TIMENOW()
{
	uint timenow = QDateTime::currentSecsSinceEpoch();
	return QString::number(timenow);
}

QString AsUtils::CREATE_BOOKS_TABLE_SQL()
{
	return "CREATE TABLE " + TBL_BOOKS() + " (" +
		BOOKID() + " INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT, " +
		CATEGORYID() + " INTEGER, " +
		ENABLED() + " INTEGER NOT NULL DEFAULT '0', " +
		TITLE() + " VARCHAR(100), " +
		TAGS() + " VARCHAR(250), " +
		QCOUNT() + " INTEGER NOT NULL DEFAULT '0', " +
		POSITION() + " INTEGER NOT NULL DEFAULT '0', " +
		CONTENT() + " VARCHAR(1000), " +
		BACKPATH() + " VARCHAR(250), " +
		CREATED() + " VARCHAR(20), " +
		UPDATED() + " VARCHAR(20));";
}

QString AsUtils::CREATE_HISTORY_TABLE_SQL()
{
	return "CREATE TABLE " + TBL_HISTORY() + " (" +
		ENTRY() + " INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT, " +
		TYPE() + " VARCHAR(50) NOT NULL DEFAULT 'SONG', " +
		ITEM() + " INTEGER NOT NULL DEFAULT '0', " +
		TITLE() + " VARCHAR(100), " +
		EXTRA() + " VARCHAR(200));";
	CREATED() + " VARCHAR(20));";
}

QString AsUtils::CREATE_SETTINGS_TABLE_SQL()
{
	return "CREATE TABLE " + TBL_SETTINGS() + " (" +
		SETTINGID() + " INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT, " +
		TITLE() + " VARCHAR(100), " +
		CONTENT() + " VARCHAR(1000), " +
		CREATED() + " VARCHAR(20), " +
		UPDATED() + " VARCHAR(20));";
}

QString AsUtils::CREATE_SETTINGS_NAVI_TABLE_SQL()
{
	return "CREATE TABLE " + TBL_SETTINGS_NAVI() + " (" +
		NAVID() + " INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT, " +
		ENABLED() + " INTEGER NOT NULL DEFAULT '0', " +
		TITLE() + " VARCHAR(100), " +
		EXTRA() + " VARCHAR(100), " +
		TAGS() + " VARCHAR(50));";
}

QString AsUtils::CREATE_SONGS_TABLE_SQL()
{
	return "CREATE TABLE " + TBL_SONGS() + " (" +
		SONGID() + " INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT, " +
		POSTID() + " INTEGER, " +
		BOOKID() + " INTEGER, " +
		CATEGORYID() + " INTEGER, " +
		BASETYPE() + " VARCHAR(10), " +
		NUMBER() + " INTEGER NOT NULL DEFAULT '0', " +
		ALIAS() + " VARCHAR(250), " +
		TITLE() + " VARCHAR(100), " +
		TAGS() + " VARCHAR(100), " +
		CONTENT() + " VARCHAR(10000), " +
		KEY() + " VARCHAR(10), " +
		AUTHOR() + " VARCHAR(100), " +
		NOTES() + " VARCHAR(250), " +
		CREATED() + " VARCHAR(20), " +
		UPDATED() + " VARCHAR(20), " +
		WHAT() + " VARCHAR(20), " +
		WHEN() + " VARCHAR(20), " +
		WHERE() + " VARCHAR(20), " +
		WHO() + " VARCHAR(20), " +
		NETTHUMBS() + " INTEGER, " +
		VIEWS() + " INTEGER NOT NULL DEFAULT '0', " +
		ISFAV() + " INTEGER NOT NULL DEFAULT '0', " +
		ACOUNT() + " INTEGER, " +
		USERID() + " INTEGER));";
}

QString AsUtils::BOOK_SELECT_SQL()
{
	return "SELECT " +
		BOOKID() + ", " +
		CATEGORYID() + ", " +
		ENABLED() + ", " +
		TITLE() + ", " +
		TAGS() + ", " +
		QCOUNT() + ", " +
		POSITION() + ", " +
		CONTENT() + ", " +
		BACKPATH() + ", " +
		CREATED() + ", " +
		UPDATED() +
		" FROM " + TBL_BOOKS();
}

QString AsUtils::BOOK_LIST_SQL(QString State)
{
	return BOOK_SELECT_SQL() + " WHERE " + ENABLED() + "=" + State + " ORDER BY " + POSITION();
}

QString AsUtils::BOOK_SINGLE_SQL(QString Book)
{
	return BOOK_SELECT_SQL() + " WHERE " + BOOKID() + "=" + Book;
}

QString AsUtils::BOOK_SEARCH_SQL(QString Search)
{
	QString SqlQuery = BOOK_SELECT_SQL();

	if (!Search.isEmpty())
	{
		SqlQuery.append(" WHERE " + TITLE() + " LIKE '%" + Search + "%' " +
			"OR " + TAGS() + " LIKE '%" + Search + "%'");
	}

	SqlQuery.append(" ORDER BY " + POSITION() + " ASC");
	return SqlQuery;
}

QString AsUtils::BOOK_INSERT_SQL(QString Title, QString Tags, QString Content)
{
	return "INSERT INTO " + TBL_BOOKS() +
		"( " + TITLE() + ", " + TAGS() + ", " + CONTENT() + ", " + QCOUNT() + ", " + CREATED() +
		" ) VALUES ( " + Title + "', " + Tags + "', " + Content + "', 0, " + TIMENOW() + ")";
}

QString AsUtils::BOOK_UPDATE_SQL(QString Bookid, QString Title, QString Tags, QString Content)
{
	return "UPDATE " + TBL_BOOKS() + " SET " + TITLE() + "='" + Title + "', " + TAGS() + "='" + Tags +
		"', " + CONTENT() + "='" + Content + "', " + UPDATED() + "='" + TIMENOW() +
		"' WHERE " + BOOKID() + "='" + Bookid + "'";
}

QString AsUtils::BOOK_SONGS_COUNT_SQL(QString Bookid, QString Songs)
{
	return "UPDATE " + TBL_BOOKS() + " SET " + QCOUNT() + "='" + Songs + "', " + UPDATED() + "='" + TIMENOW() +
		"' WHERE " + BOOKID() + "='" + Bookid + "'";
}

char* AsUtils::BOOK_DELETE_SQL(QString Bookid)
{
	QString SqlQuery = "DELETE FROM " + TBL_BOOKS() + " WHERE " + BOOKID() + "= " + Bookid + "; " +
		"DELETE FROM " + TBL_SONGS() + " WHERE " + BOOKID() + "=" + Bookid;
	QByteArray bar = SqlQuery.toLocal8Bit();
	return bar.data();
}

QString AsUtils::HISTORY_SELECT_SQL(QString STATE)
{
	return "SELECT " +
		ENTRY() + ", " +
		TYPE() + ", " +
		ITEM() + ", " +
		TITLE() + ", " +
		EXTRA() + ", " +
		CREATED() +
		" FROM " + TBL_HISTORY(); //" WHERE " + CREATED() + "=" + STATE;
}

char* AsUtils::SETTINGS_SELECT_SQL()
{
	QString SettingsQry = "SELECT " + CONTENT() + " FROM " + TBL_SETTINGS() + " ORDER BY " + SETTINGID();
	QByteArray bar = SettingsQry.toLocal8Bit();
	return bar.data();
}

QString AsUtils::SETTINGS_NAVI_SELECT_SQL(QString Search)
{
	QString SqlQuery = "SELECT " + NAVID() + ", " + ENABLED() + ", " + TITLE() + ", " + CONTENT() + ", " +
		EXTRA() + ", " + TAGS() + " FROM " + TBL_SETTINGS_NAVI();

	if (!Search.isEmpty())
	{
		SqlQuery.append(" WHERE " + TITLE() + " LIKE '%" + Search + "%' " +
			"OR " + CONTENT() + " LIKE '%" + Search + "%'");
	}

	SqlQuery.append(" ORDER BY " + NAVID() + " ASC");
	return SqlQuery;
}

QString AsUtils::SONG_SELECT_SQL()
{
	return "SELECT " +
		SONGID() + ", " +
		TBL_SONGS() + "." + BOOKID() + ", " +
		NUMBER() + ", " +
		ALIAS() + ", " +
		TBL_SONGS() + "." + TITLE() + ", " +
		TBL_SONGS() + "." + TAGS() + ", " +
		TBL_SONGS() + "." + CONTENT() + ", " +
		ISFAV() + ", " +
		TBL_SONGS() + "." + CREATED() + ", " +
		TBL_SONGS() + "." + UPDATED() + ", " +
		TBL_BOOKS() + "." + TITLE() +
		" FROM " + TBL_SONGS() +
		" INNER JOIN " + TBL_BOOKS() + " ON " +
		TBL_BOOKS() + "." + CATEGORYID() + "=" + TBL_SONGS() + "." + CATEGORYID();
}

QString AsUtils::SONG_SEARCH_SQL(QString SearchStr, QString Bookid, bool SearchAll)
{

	QString SqlQuery = SONG_SELECT_SQL() + " WHERE ";

	if (SearchStr.isEmpty())
		SqlQuery.append(TBL_SONGS() + "." + BOOKID() + "=" + Bookid);
	else
	{
		bool isNumeric;
		int searchint = SearchStr.toInt(&isNumeric, 10);
		if (SearchAll)
		{
			if (isNumeric)
			{
				SqlQuery.append(NUMBER() + "=" + SearchStr);
			}
			else
			{
				SqlQuery.append(TBL_SONGS() + "." + TITLE() + " LIKE '%" + SearchStr + "%'");
				SqlQuery.append(" OR " + TBL_SONGS() + "." + ALIAS() + " LIKE '%" + SearchStr + "%'");
				SqlQuery.append(" OR " + TBL_SONGS() + "." + CONTENT() + " LIKE '%" + SearchStr + "%'");
			}
		}
		else
		{
			if (isNumeric)
			{
				SqlQuery.append(TBL_SONGS() + "." + NUMBER() + "=" + SearchStr);
				SqlQuery.append(" AND " + TBL_SONGS() + "." + BOOKID() + "=" + Bookid);
			}
			else
			{
				SqlQuery.append(TBL_SONGS() + "." + TITLE() + " LIKE '%" + SearchStr + "%'");
				SqlQuery.append(" AND " + TBL_SONGS() + "." + BOOKID() + "=" + Bookid);
				SqlQuery.append(" OR " + TBL_SONGS() + "." + ALIAS() + " LIKE '%" + SearchStr + "%'");
				SqlQuery.append(" AND " + TBL_SONGS() + "." + BOOKID() + "=" + Bookid);
				SqlQuery.append(" OR " + TBL_SONGS() + "." + CONTENT() + " LIKE '%" + SearchStr + "%'");
				SqlQuery.append(" AND " + TBL_SONGS() + "." + BOOKID() + "=" + Bookid);
			}
		}
	}

	SqlQuery.append(" ORDER BY number ASC");
	return SqlQuery;
}

QString AsUtils::SONG_SINGLE_SQL(QString Song)
{
	return SONG_SELECT_SQL() + " WHERE " + SONGID() + "=" + Song;
}

QString AsUtils::SONG_INSERT_SQL(QString Number, QString Title, QString Alias, QString Content, QString Key, QString Author, QString Bookid)
{
	return "INSERT INTO " + TBL_SONGS() +
		"( " + NUMBER() + ", " + TITLE() + ", " + ALIAS() + ", " + CONTENT() + ", " + KEY() + ", " +
		BOOKID() + ", " + CREATED() + " ) VALUES ( " + Number + "', " + Title + "', " + Alias + "', " + Content.replace("\r\n", "\n") + "', " + Key + "', " +
		Author + "', " + Bookid + ", " + TIMENOW() + ")";
}

QString AsUtils::SONG_UPDATE_SQL(QString Number, QString Title, QString Alias, QString Content, QString Key, QString Author, QString Songid)
{
	return "UPDATE " + TBL_SONGS() + " SET " + NUMBER() + "='" + Number + "', " + TITLE() + "='" + Title +
		"', " + ALIAS() + "='" + Alias + "', " + CONTENT() + "='" + Content + "', " + KEY() + "='" + Key +
		"', " + UPDATED() + "='" + TIMENOW() + "' WHERE " + SONGID() + "='" + Songid + "'";
}

char* AsUtils::SONG_DELETE_SQL(QString Songid)
{
	QString SqlQuery = "DELETE FROM " + TBL_SONGS() + " WHERE " + SONGID() + "= " + Songid;
	QByteArray bar = SqlQuery.toLocal8Bit();
	return bar.data();
}

QString AsUtils::UPDATE_SETTINGS_SQL(QString Title, QString Value)
{
	return "UPDATE " + TBL_SETTINGS() + " SET " + CONTENT() + "='" + Value + "', " +
		UPDATED() + "='" + TIMENOW() + "' WHERE " + TITLE() + "='" + Title + "'";
}