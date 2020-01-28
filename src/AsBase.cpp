#include "AsBase.h"

#include "sqlite.h"
#include "RunSql.h"
#include "sqlitetablemodel.h"

bool AsBase::isTrue(int value)
{
    if (value == 0) return false;
    else if (value == 1) return true;
}

QString AsBase::ReplaceList(QString text)
{
    text = text.replace("\\n", " ");
    text = text.replace("\\", "");
    return text;
}

QString AsBase::ReplaceView(QString text)
{
    text = text.replace("\\n", "\r\n");
    text = text.replace("\\", "");
    return text;
}

QString AsBase::booltoInt(bool value)
{
    if (value == true) return "1";
    else if (value == false) return "0";
}

int AsBase::setCmbValue(std::vector<QString> values, QString value)
{
    int retvalue;
    for (int v = 0; v < values.size(); v++)
    {
        if (value == values[v]) retvalue = v;
    }
    return retvalue;
}

void AsBase::SetOption(QString Title, QString Content)
{
    sqlite3* db;
    sqlite3_stmt* sqlqueryStmt;
    char* zErrMsg = NULL;
    int row, col, rc = sqlite3_open("Data/vSongBook.db", &db);

    QByteArray bar = AsUtils::UPDATE_SETTINGS_SQL(Title, Content).toLocal8Bit();
    char* sqlQuery = bar.data();

    rc = sqlite3_exec(db, sqlQuery, 0, 0, &zErrMsg);

    if (rc != SQLITE_OK) sqlite3_free(zErrMsg);
    sqlite3_close(db);
}

std::vector<QString> AsBase::AppSettings()
{
    std::vector<QString> settings;
    sqlite3* songsDb;
    char* err_msg = NULL, ** qryResult = NULL;
    int row, col;
    int rc = sqlite3_open_v2(AsUtils::APP_DB(), &songsDb, SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE, NULL);

    if (rc == SQLITE_OK)
    {
        rc = sqlite3_get_table(songsDb, AsUtils::SETTINGS_SELECT_SQL(), &qryResult, &row, &col, &err_msg);

        for (int i = 1; i < row + 1; i++)
        {
            settings.push_back(*(qryResult + i * col + 0));
        }
        sqlite3_free_table(qryResult);
        sqlite3_close(songsDb);
    }

    return settings;
}

void UpdateSongCount(QString Bookid, QString Count)
{
    sqlite3* db;
    sqlite3_stmt* sqlqueryStmt;
    char* zErrMsg = NULL;
    int row, col, rc = sqlite3_open(AsUtils::APP_DB(), &db);

    QByteArray bar = AsUtils::BOOK_SONGS_COUNT_SQL(Bookid, Count).toLocal8Bit();
    char* sqlQuery = bar.data();

    rc = sqlite3_exec(db, sqlQuery, 0, 0, &zErrMsg);

    if (rc != SQLITE_OK) sqlite3_free(zErrMsg);
    sqlite3_close(db);
}