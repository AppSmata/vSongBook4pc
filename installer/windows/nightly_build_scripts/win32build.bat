:: Destination path - specify where to move package after build
SET DEST_PATH=D:\\builds
MKDIR "%DEST_PATH%"

SET ZIP_EXE="C:\Program Files\7-Zip\7z.exe"
SET SQLITE_DIR=D:\\SQLite\\Win32

:: You need to change the date format in Windows settings to YYYY-MM-DD
:: before this will work properly. ;)
set RUN_DATE=%DATE%

:: If no branch given on the command line, use master
IF "%1"=="" (SET BRANCH="master") ELSE (SET BRANCH="%1")

CD /d "D:\"
if exist "%SQLITE_DIR%" rd /q /s "%SQLITE_DIR%"
if exist "D:\\builds\\release-sqlite-win32" rd /q /s "D:\\builds\\release-sqlite-win32"

:: Unpack SQLite
CD D:\SQLite
%ZIP_EXE% e sqlite*zip "-o%SQLITE_DIR%"

::git clone -b %BRANCH% https://github.com/Appsmata/vSongBook4PC.git "%DB4S_DIR%Win32"
::CD D:\\Cpp\\vSongBook4PC
::git clean -dffx
::git checkout -f HEAD
::git checkout master
::git pull
::git checkout %BRANCH%
::git clean -dffx
::git pull
::git clean -dffx

:: WIN32 SQLITE BUILD PROCEDURE

:: Set path variables
CALL "D:\PowerHouse\\Microsoft Visual Studio 14.0\\VC\\bin\\vcvars32.bat" 8.1

:: Build SQLite x86
CD %SQLITE_DIR%
cl sqlite3.c -DSQLITE_ENABLE_FTS5 -DSQLITE_ENABLE_FTS3 -DSQLITE_ENABLE_FTS3_PARENTHESIS -DSQLITE_ENABLE_STAT4 -DSQLITE_SOUNDEX -DSQLITE_ENABLE_JSON1 -DSQLITE_ENABLE_GEOPOLY -DSQLITE_ENABLE_RTREE -DSQLITE_MAX_ATTACHED=125 -DSQLITE_API=__declspec(dllexport) -link -dll -out:sqlite3.dll

:: Build extensions
COPY D:\Cpp\vSongBook4PC\src\extensions\extension-functions.c
COPY D:\Cpp\vSongBook4PC\src\extensions\extension-functions.def
cl /MD extension-functions.c -link -dll -def:extension-functions.def -out:math.dll
COPY D:\Cpp\vSongBook4PC\src\extensions\extension-formats.c
COPY D:\Cpp\vSongBook4PC\src\extensions\extension-formats.def
cl /MD extension-formats.c -link -dll -def:extension-formats.def -out:formats.dll
curl -L -o fileio.c "https://sqlite.org/src/raw?filename=ext/misc/fileio.c&ci=trunk"
curl -L -o test_windirent.c "https://sqlite.org/src/raw?filename=src/test_windirent.c&ci=trunk"
curl -L -o test_windirent.h "https://sqlite.org/src/raw?filename=src/test_windirent.h&ci=trunk"
cl /MD fileio.c test_windirent.c -link sqlite3.lib -dll -out:fileio.dll

:: Run CMake for SQLite x86
CD D:\\builds
MKDIR "release-sqlite-win32"
CD "release-sqlite-win32"
cmake -G "Visual Studio 14 2015" -Wno-dev D:\\Cpp\\vSongBook4PC

:: Build package
devenv /Build Release vSongBook.sln /project "ALL_BUILD"

:: Build MSI
CD D:\\Cpp\\vSongBook4PC\\installer\\windows
CALL build.cmd win32

:: Move package to DEST_PATH
MOVE /Y *.msi "%DEST_PATH%\vSongBook-%RUN_DATE%-win32.msi"

:: Create ZIP
CD %DEST_PATH%
msiexec /a "vSongBook-%RUN_DATE%-win32.msi" /q TARGETDIR=%CD%\zip
MOVE %CD%\zip\System\* "%CD%\zip\vSongBook"
%ZIP_EXE% a "vSongBook-%RUN_DATE%-win32.zip" "%CD%\zip\vSongBook"
RMDIR /S /Q %CD%\zip