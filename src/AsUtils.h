#ifndef ASUTILS_H
#define ASUTILS_H

#include <QtCore>

class AsUtils
{
public:
	static QString DbNameQstr();
    static char const *DbNameChar();

	static QString TableBooks();
	static QString TableHistory();
	static QString TableSettings();
	static QString TableSettingsNavi();
	static QString TableSongs();
	
	
	static QString ColumnBookid();
	static QString ColumnCategoryid();
	static QString ColumnEnabled();
	static QString ColumnTitle();
	static QString ColumnContent();
	static QString ColumnQcount();
	static QString ColumnPosition();
	static QString ColumnBackpath();
	static QString ColumnNotes();
	static QString ColumnCreated();
	static QString ColumnUpdated();

	static QString ColumnEntry();
	static QString ColumnType();
	static QString ColumnItem();
	static QString ColumnExtra();

	static QString ColumnSettingid();

	static QString ColumnNavid();
	static QString ColumnTags();

	static QString ColumnSongid();
	static QString ColumnPostid();
	static QString ColumnNumber();
	static QString ColumnBasetype();
	static QString ColumnAlias();
	static QString ColumnViews();
	static QString ColumnKey();
	static QString ColumnIsfav();
	static QString ColumnAuthor();
	static QString ColumnWhat();
	static QString ColumnWhen();
	static QString ColumnWhere();
	static QString ColumnWho();
	static QString ColumnNetthumbs();
	static QString ColumnAcount();
	static QString ColumnUserid();

	static QString TimeNow();
	static QString TimeDateNow();

	static QString CreateBooksTableSql();
	static QString CreateHistoryTableSql();
	static QString CreateSettingsTableSql();
	static QString CreateSettingsNaviTableSql();
	static QString CreateSongsTableSql();

	static QString BookSelectSql();
	static QString BookListSql(QString State);
	static QString BookSingleSql(QString Book);
	static QString BookSearchSql(QString Search);
	static QString BookInsertSql(QString Title, QString Category, QString Tags, QString Content, QString Position, QString Songs);
	static QString BookUpdateSql(QString Bookid, QString Title, QString Tags, QString Content, QString Songs);
	static QString BookSongsCountSql(QString Bookid, QString Songs);
	static char* BookDeleteSql(QString Bookid);

    static QString HistorySelectSql();

	static QString SettingsSql();
	static char* SettingsSelectSql();
	static QString SettingsNaviSql();
	static QString SettingsNaviSelectSql(QString Search);

	static QString SongSelectSql();
	static QString SongSearchSql(QString SearchStr, QString Bookid, bool SearchAll);
	static QString SongSingleSql(QString Song);
	static QString SongInsertSql(QString Bookid, QString Categoryid, QString Number, QString Postid, QString Title, QString Alias, QString Content, QString Key, QString Author);
	static QString SongUpdateSql(QString Number, QString Title, QString Alias, QString Content, QString Key, QString Author, QString Songid);
    static char const *SongDeleteSql(QString Songid);

	static QString AsUtils::GetSettingsSql(QString Title);
	static QString UpdateSettingsSql(QString Title, QString Value);

	static QString PostsLists();
	static QString PostsSelect();
	static QString PostsSingle();
	static QString PostsAnswers();
	static QString PostsSearch();
	static QString PostsSlider();
	static QString PostsByCategory();
	static QString CategoriesAll();
	static QString BooksSelect();
	static QString Feedback();
	static QString ShowComment();
	static QString CountComment();
	static QString BackgroundDrawer();
	static QString UserSignin();
	static QString UserSignup();
	static QString UserLastseen();
};

#endif
