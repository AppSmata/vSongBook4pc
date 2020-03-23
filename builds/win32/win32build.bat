:: Destination path - specify where to move package after build
SET DEST_PATH=D:\\Cpp\\vSongBook4PC\\builds\\win32
MKDIR "%DEST_PATH%"

SET ZIP_EXE="C:\Program Files\7-Zip\7z.exe"
SET SQLITE_DIR=D:\\SQLite\\win32

:: You need to change the date format in Windows settings to YYYY-MM-DD
:: before this will work properly. ;)
set RUN_DATE=%DATE%

:: Unpack SQLite
CD D:\SQLite
%ZIP_EXE% e sqlite*zip "-o%SQLITE_DIR%"

:: WIN32 SQLITE BUILD PROCEDURE

:: Set path variables
CALL "D:\PowerHouse\\Microsoft Visual Studio 14.0\\VC\\bin\\vcvars32.bat" 8.1

:: Build SQLite x86
CD %SQLITE_DIR%
cl sqlite3.c -DSQLITE_ENABLE_FTS5 -DSQLITE_ENABLE_FTS3 -DSQLITE_ENABLE_FTS3_PARENTHESIS -DSQLITE_ENABLE_STAT4 -DSQLITE_SOUNDEX -DSQLITE_ENABLE_JSON1 -DSQLITE_ENABLE_GEOPOLY -DSQLITE_ENABLE_RTREE -DSQLITE_MAX_ATTACHED=125 -DSQLITE_API=__declspec(dllexport) -link -dll -out:sqlite3.dll

:: Run CMake for vSongBook x86
CD D:\Cpp\vSongBook4PC\builds\win32
cmake -G "Visual Studio 15 2017" -Wno-dev D:\\Cpp\\vSongBook4PC