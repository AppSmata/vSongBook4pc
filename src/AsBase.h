#ifndef ASBASE_H
#define ASBASE_H

#include <AsUtils.h>
#include <QtCore>
#include <vector>

#include <sqlite.h>
#include <RunSql.h>
#include <sqlitetablemodel.h>

class AsBase
{
public:
	static void WriteLogs(QString Source, QString Message, QString InnerException, QString StackTrace);

    static bool isTrue(int value);
    static QString ReplaceList(QString text);
    static QString ReplaceView(QString text);
    static QString booltoInt(bool value);

    static std::vector<QString> AppSettings();

    static int setCmbValue(std::vector<QString> values, QString value);
	static QString AsBase::GetOption(QString Title);
    static void SetOption(QString Title, QString Content);
    static void UpdateSongCount(QString Bookid, QString Count);

    static void execSql(QString SqlQuery);
    static void InitialDbOps();

    static void NewBook(QString Title, QString Category, QString Tags, QString Content, QString Songs, QString Position);
    static void NewSong(QString Bookid, QString Categoryid, QString Number, QString Postid, QString Title, QString Alias, QString Content, QString Key, QString Author);
	static QString CountSongs(QString Bookid);
	static QString LastValue(QString ColumnName, QString TableName, QString OrderColumn);

	static QString BaseUrl();

    static void ResetSettings();
};

#endif