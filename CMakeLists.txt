project(vSongBook)
cmake_minimum_required(VERSION 2.8.12.2)

# BUILD_VERSION is the current date in YYYYMMDD format. It is only
# used by the nightly version to add the date of the build.
string(TIMESTAMP BUILD_VERSION "%Y%m%d")

# Choose between building a stable version or nightly (the default), depending
# on whether '-DBUILD_STABLE_VERSION=1' is passed on the command line or not.
option(BUILD_STABLE_VERSION "Don't build the stable version by default" OFF)
if(NOT BUILD_STABLE_VERSION)
    add_definitions(-DBUILD_VERSION=${BUILD_VERSION})
endif()

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake" "${CMAKE_MODULE_PATH}")

OPTION(ENABLE_TESTING "Enable the unit tests" OFF)
OPTION(FORCE_INTERNAL_QCUSTOMPLOT "Don't use distribution's QCustomPlot even if available" ON)
OPTION(FORCE_INTERNAL_QHEXEDIT "Don't use distribution's QHexEdit even if available" ON)
OPTION(ALL_WARNINGS "Enable some useful warning flags" OFF)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Release")
endif()

add_definitions(-std=c++11)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Fix behavior of CMAKE_CXX_STANDARD when targeting macOS.
if (POLICY CMP0025)
    cmake_policy(SET CMP0025 NEW)
endif ()
# Fix warning of AUTOMOC behavior
if (POLICY CMP0071)
    # Use of AUTOMOC is set to old for now for consistency.
    # Affects of 'new' behavior is as yet to be determined.
    # https://cmake.org/cmake/help/latest/policy/CMP0071.html
    cmake_policy(SET CMP0071 OLD)
endif()

if(WIN32 AND MSVC)
	if(CMAKE_CL_64)
		# Paths for 64-bit windows builds
		set(OPENSSL_PATH "D:/OpenSSL-Win64" CACHE PATH "OpenSSL Path")
		set(QT5_PATH "D:/Qt/5.12.5/msvc2017_64" CACHE PATH "Qt5 Path")

                # Choose between SQLCipher or SQLite, depending whether
                # -Dsqlcipher=1 is passed on the command line
                if(sqlcipher)
                        set(SQLITE3_PATH "C:/QtP/SQLCipher-Win64" CACHE PATH "SQLCipher Path")
                else()
                        set(SQLITE3_PATH "D:/SQLite-Win64" CACHE PATH "SQLite Path")
                endif()
	else()
		# Paths for 32-bit windows builds
		set(OPENSSL_PATH "D:/OpenSSL-Win32" CACHE PATH "OpenSSL Path")
		set(QT5_PATH "D:/Qt/5.12.5/msvc2015" CACHE PATH "Qt5 Path")

                # Choose between SQLCipher or SQLite, depending whether
                # -Dsqlcipher=1 is passed on the command line
                if(sqlcipher)
                        set(SQLITE3_PATH "D:/QtP/SQLCipher-Win32" CACHE PATH "SQLCipher Path")
                else()
                        set(SQLITE3_PATH "D:/SQLite-Win32" CACHE PATH "SQLite Path")
                endif()
	endif()
	set(CMAKE_PREFIX_PATH "${QT5_PATH};${SQLITE3_PATH}")
endif()

find_package(Qt5 REQUIRED COMPONENTS Concurrent Gui LinguistTools Network PrintSupport Test Widgets Xml)
if(FORCE_INTERNAL_QCUSTOMPLOT)
    set(QCUSTOMPLOT_FOUND FALSE)
else()
    find_package(QCustomPlot)
endif()
if(FORCE_INTERNAL_QHEXEDIT)
    set(QHEXEDIT_FOUND FALSE)
else()
    find_package(QHexEdit)
endif()
set(JSON_DIR libs/json)

if(NOT QHEXEDIT_FOUND)
    set(QHEXEDIT_DIR libs/qhexedit)
    set(QHEXEDIT_INCL_DIR ${QHEXEDIT_DIR}/src)
    add_subdirectory(${QHEXEDIT_DIR})
endif()
add_subdirectory(${JSON_DIR})
if(NOT QCUSTOMPLOT_FOUND)
    set(QCUSTOMPLOT_DIR libs/qcustomplot-source)
    add_subdirectory(${QCUSTOMPLOT_DIR})
endif()

set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

if(ENABLE_TESTING)
    enable_testing()
endif()

set(VSB_HDR
	src/Data.h
	src/IconCache.h
	src/version.h
	src/sql/sqlitetypes.h
	src/sql/Query.h
	src/sql/ObjectIdentifier.h
	src/csvparser.h
	src/sqlite.h
	src/sql/parser/ParserDriver.h
	src/sql/parser/sqlite3_lexer.h
	src/sql/parser/sqlite3_location.h
	src/sql/parser/sqlite3_parser.hpp
)

set(VSB_MOC_HDR
	src/AboutDialog.h
	src/AsBase.h
	src/AsCheckable.h
	src/AsDelegate.h
	src/AsItem.h
	src/AsUtils.h
	src/CipherDialog.h
	src/CipherSettings.h
	src/CondFormat.h
	src/CondFormatManager.h
	src/DbStructureModel.h
	src/DotenvFormat.h
	src/ExportDataDialog.h
	src/ExportSqlDialog.h
	src/ExtendedTableWidget.h
	src/FileDialog.h
	src/FileExtensionManager.h
	src/FilterLineEdit.h
	src/FilterTableHeader.h
	src/ForeignKeyEditorDelegate.h
	src/ImportCsvDialog.h
	src/Palette.h
	src/PlotDock.h
	src/ProxyDialog.h
	src/RemoteDatabase.h
	src/RemoteModel.h
	src/RemotePushDialog.h
	src/RowCache.h
	src/RowLoader.h
	src/RunSql.h
	src/SelectItemsPopup.h
	src/Settings.h
	src/sqlitedb.h
	src/sqlitetablemodel.h
	src/AsUtils.h
	src/VacuumDialog.h
	src/vAppSplash.h
	src/vSongBook.h
	src/vSongBooklist.h
	src/vSongEditor.h
	src/vSongHome.h
	src/vSongOnline.h
	src/vSongPreferences.h
	src/vSongPresent.h
	src/vSongTutorial.h
)

set(VSB_SRC
	src/AboutDialog.cpp
	src/AsBase.cpp
	src/AsCheckable.cpp
	src/AsDelegate.cpp
	src/AsUtils.cpp
	src/CipherDialog.cpp
	src/CipherSettings.cpp
	src/CondFormat.cpp
	src/CondFormatManager.cpp
	src/csvparser.cpp
	src/Data.cpp
	src/DbStructureModel.cpp
	src/DotenvFormat.cpp
	src/ExportDataDialog.cpp
	src/ExportSqlDialog.cpp
	src/ExtendedTableWidget.cpp
	src/FileDialog.cpp
	src/FileExtensionManager.cpp
	src/FilterLineEdit.cpp
	src/FilterTableHeader.cpp
	src/ForeignKeyEditorDelegate.cpp
	src/IconCache.cpp
	src/ImportCsvDialog.cpp
	src/main.cpp
	src/Palette.cpp
	src/PlotDock.cpp
	src/ProxyDialog.cpp
	src/RemoteDatabase.cpp
	src/RemoteModel.cpp
	src/RemotePushDialog.cpp
	src/RowLoader.cpp
	src/RunSql.cpp
	src/SelectItemsPopup.cpp
	src/Settings.cpp
	src/sql/ObjectIdentifier.cpp
	src/sql/parser/ParserDriver.cpp
	src/sql/parser/sqlite3_lexer.cpp
	src/sql/parser/sqlite3_parser.cpp
	src/sql/Query.cpp
	src/sql/sqlitetypes.cpp
	src/sqlitedb.cpp
	src/sqlitetablemodel.cpp
	src/VacuumDialog.cpp
	src/vAppSplash.cpp
	src/vSongBook.cpp
	src/vSongBooklist.cpp
	src/vSongEditor.cpp
	src/vSongHome.cpp
	src/vSongOnline.cpp
	src/vSongPreferences.cpp
	src/vSongPresent.cpp
	src/vSongTutorial.cpp
)

set(VSB_FORMS
	src/AboutDialog.ui
	src/CipherDialog.ui
	src/CondFormatManager.ui
	src/ExportDataDialog.ui
	src/ExportSqlDialog.ui
	src/FileExtensionManager.ui
	src/ImportCsvDialog.ui
	src/PlotDock.ui
	src/ProxyDialog.ui
	src/RemotePushDialog.ui
	src/SelectItemsPopup.ui
	src/VacuumDialog.ui
	src/vAppSplash.ui
	src/vSongBooklist.ui
	src/vSongEditor.ui
	src/vSongHome.ui
	src/vSongOnline.ui
	src/vSongPreferences.ui
	src/vSongPresent.ui
	src/vSongTutorial.ui

)

set(VSB_RESOURCES
	src/images/images.qrc
	src/icons/icons.qrc
	src/translations/flags/flags.qrc
	src/translations/translations.qrc
	src/certs/CaCerts.qrc
	src/qdarkstyle/style.qrc
	src/qstyle/style.qrc
)

set(VSB_MISC
    src/sql/parser/sqlite3_parser.yy
    src/sql/parser/sqlite3_lexer.ll
)

# Translation files
set(VSB_TSS
	"${CMAKE_SOURCE_DIR}/src/translations/sqlb_ar_SA.ts"
	"${CMAKE_SOURCE_DIR}/src/translations/sqlb_cs.ts"
	"${CMAKE_SOURCE_DIR}/src/translations/sqlb_zh.ts"
	"${CMAKE_SOURCE_DIR}/src/translations/sqlb_zh_TW.ts"
	"${CMAKE_SOURCE_DIR}/src/translations/sqlb_de.ts"
	"${CMAKE_SOURCE_DIR}/src/translations/sqlb_es_ES.ts"
	"${CMAKE_SOURCE_DIR}/src/translations/sqlb_fr.ts"
	"${CMAKE_SOURCE_DIR}/src/translations/sqlb_ru.ts"
	"${CMAKE_SOURCE_DIR}/src/translations/sqlb_pl.ts"
	"${CMAKE_SOURCE_DIR}/src/translations/sqlb_pt_BR.ts"
	"${CMAKE_SOURCE_DIR}/src/translations/sqlb_en_GB.ts"
	"${CMAKE_SOURCE_DIR}/src/translations/sqlb_ko_KR.ts"
	"${CMAKE_SOURCE_DIR}/src/translations/sqlb_tr.ts"
	"${CMAKE_SOURCE_DIR}/src/translations/sqlb_uk_UA.ts"
	"${CMAKE_SOURCE_DIR}/src/translations/sqlb_it.ts"
)

# Windows image format plugin files
set(WIN_IMG_PLUGINS
	"${QT5_PATH}/plugins/imageformats/qgif.dll"
	"${QT5_PATH}/plugins/imageformats/qicns.dll"
	"${QT5_PATH}/plugins/imageformats/qico.dll"
	"${QT5_PATH}/plugins/imageformats/qjpeg.dll"
	"${QT5_PATH}/plugins/imageformats/qsvg.dll"
	"${QT5_PATH}/plugins/imageformats/qtga.dll"
	"${QT5_PATH}/plugins/imageformats/qtiff.dll"
	"${QT5_PATH}/plugins/imageformats/qwbmp.dll"
	"${QT5_PATH}/plugins/imageformats/qwebp.dll"
)
set(WIN_IMG_PLUGINS_DEBUG
	"${QT5_PATH}/plugins/imageformats/qgifd.dll"
	"${QT5_PATH}/plugins/imageformats/qicnsd.dll"
	"${QT5_PATH}/plugins/imageformats/qicod.dll"
	"${QT5_PATH}/plugins/imageformats/qjpegd.dll"
	"${QT5_PATH}/plugins/imageformats/qsvgd.dll"
	"${QT5_PATH}/plugins/imageformats/qtgad.dll"
	"${QT5_PATH}/plugins/imageformats/qtiffd.dll"
	"${QT5_PATH}/plugins/imageformats/qwbmpd.dll"
	"${QT5_PATH}/plugins/imageformats/qwebpd.dll"
)

# License files
set(LICENSE_FILES
	LICENSE
	LICENSE-PLUGINS
)

qt5_wrap_ui(VSB_FORM_HDR ${VSB_FORMS})
if(VSB_TSS)
	# add translations
	foreach(VSB_TS ${VSB_TSS})
		SET_SOURCE_FILES_PROPERTIES("${VSB_TS}" PROPERTIES OUTPUT_LOCATION "${CMAKE_SOURCE_DIR}/src/translations")
	endforeach(VSB_TS ${VSB_TSS})
	qt5_add_translation(VSB_QMS ${VSB_TSS})
endif(VSB_TSS)
qt5_add_resources(VSB_RESOURCES_RCC ${VSB_RESOURCES})

#icon and correct libs/subsystem for windows
if(WIN32)
        #enable version check for windows
        add_definitions(-DCHECKNEWVERSION)

	IF( MINGW )
	# resource compilation for MinGW
		ADD_CUSTOM_COMMAND(OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/sqlbicon.o"
			COMMAND windres "-I${CMAKE_CURRENT_SOURCE_DIR}" "-i${CMAKE_CURRENT_SOURCE_DIR}/src/winapp.rc" -o "${CMAKE_CURRENT_BINARY_DIR}/sqlbicon.o" VERBATIM)
		set(VSB_SRC ${VSB_SRC} "${CMAKE_CURRENT_BINARY_DIR}/sqlbicon.o")
		set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,-subsystem,windows")
		set(WIN32_STATIC_LINK -Wl,-Bstatic -lssl -lcrypto -lws2_32)
		set(ADDITIONAL_LIBS lzma)
	ELSE( MINGW )
		set(VSB_SRC ${VSB_SRC} "${CMAKE_CURRENT_SOURCE_DIR}/src/winapp.rc")
	ENDIF( MINGW )
else()
	set(LPTHREAD pthread)
endif(WIN32)

#enable version check for MacOS
if(APPLE)
	add_definitions(-DCHECKNEWVERSION)
endif(APPLE)

# SQLCipher option
if(sqlcipher)
	add_definitions(-DENABLE_SQLCIPHER)
	set(LIBSQLITE_NAME sqlcipher)
else(sqlcipher)
	set(LIBSQLITE_NAME sqlite3)
endif(sqlcipher)

# add extra library path for MacOS and FreeBSD
set(EXTRAPATH APPLE OR ${CMAKE_SYSTEM_NAME} MATCHES "FreeBSD")
if(EXTRAPATH)
	find_library(LIBSQLITE ${LIBSQLITE_NAME} HINTS /usr/local/lib /usr/local/opt/sqlite/lib)
	set(ADDITIONAL_INCLUDE_PATHS /usr/local/include /usr/local/opt/sqlite/include)
else(EXTRAPATH)
	find_library(LIBSQLITE ${LIBSQLITE_NAME})
endif(EXTRAPATH)

if(WIN32 AND MSVC)
	find_path(SQLITE3_INCLUDE_DIR sqlite3.h)
	if(sqlcipher)
		find_file(SQLITE3_DLL sqlcipher.dll)
	else(sqlcipher)
		find_file(SQLITE3_DLL sqlite3.dll)
	endif(sqlcipher)
	include_directories(${SQLITE3_INCLUDE_DIR})
endif()

include_directories(
		"${CMAKE_CURRENT_BINARY_DIR}"
		${JSON_DIR}
		${ADDITIONAL_INCLUDE_PATHS}
		src)
if(QHEXEDIT_FOUND)
    include_directories(${QHEXEDIT_INCLUDE_DIR})
else()
    include_directories(${QHEXEDIT_INCL_DIR})
endif()
if(QCUSTOMPLOT_FOUND)
    include_directories(${QCUSTOMPLOT_INCLUDE_DIR})
else()
    include_directories(${QCUSTOMPLOT_DIR})
endif()

add_executable(${PROJECT_NAME}
		${VSB_HDR}
		${VSB_SRC}
		${VSB_FORM_HDR}
		${VSB_MOC}
		${VSB_RESOURCES_RCC}
		${VSB_MISC})


# Warnings
if (ALL_WARNINGS AND CMAKE_COMPILER_IS_GNUCC)
    target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wshadow -Wnon-virtual-dtor -Wold-style-cast -Wcast-align -Wunused -Woverloaded-virtual -Wpedantic -Wconversion -Wsign-conversion)
    target_compile_options(${PROJECT_NAME} PRIVATE -Wdouble-promotion -Wformat=2 -Wlogical-op -Wuseless-cast)
    if(CMAKE_CXX_COMPILER_VERSION VERSION_GREATER_EQUAL 7.0)
        target_compile_options(${PROJECT_NAME} PRIVATE -Wnull-dereference -Wduplicated-cond -Wduplicated-branches)
    endif()
endif()

if(NOT QHEXEDIT_FOUND)
    add_dependencies(${PROJECT_NAME} qhexedit)
endif()
if(NOT QCUSTOMPLOT_FOUND)
    add_dependencies(${PROJECT_NAME} qcustomplot)
endif()

if(NOT QHEXEDIT_FOUND)
    link_directories("${CMAKE_CURRENT_BINARY_DIR}/${QHEXEDIT_DIR}")
endif()
if(NOT QCUSTOMPLOT_FOUND)
    link_directories("${CMAKE_CURRENT_BINARY_DIR}/${QCUSTOMPLOT_DIR}")
endif()

set(QT_LIBS Qt5::Gui Qt5::Test Qt5::PrintSupport Qt5::Widgets Qt5::Network Qt5::Concurrent Qt5::Xml)

target_link_libraries(${PROJECT_NAME}
    ${LPTHREAD}
    ${QT_LIBS}
    ${WIN32_STATIC_LINK}
    ${LIBSQLITE}
    ${ADDITIONAL_LIBS})
if(QHEXEDIT_FOUND)
    target_link_libraries(${PROJECT_NAME} ${QHEXEDIT_LIBRARIES})
else()
    target_link_libraries(${PROJECT_NAME} qhexedit)
endif()
if(QCUSTOMPLOT_FOUND)
    target_link_libraries(${PROJECT_NAME} ${QCUSTOMPLOT_LIBRARIES})
else()
    target_link_libraries(${PROJECT_NAME} qcustomplot)
endif()

if(WIN32 AND MSVC)
	set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME "vSongBook")
	set_target_properties(${PROJECT_NAME} PROPERTIES LINK_FLAGS_DEBUG "/SUBSYSTEM:CONSOLE")
	set_target_properties(${PROJECT_NAME} PROPERTIES COMPILE_DEFINITIONS_DEBUG "_CONSOLE")
	set_target_properties(${PROJECT_NAME} PROPERTIES LINK_FLAGS_RELWITHDEBINFO "/SUBSYSTEM:CONSOLE")
	set_target_properties(${PROJECT_NAME} PROPERTIES COMPILE_DEFINITIONS_RELWITHDEBINFO "_CONSOLE")
    if(CMAKE_CL_64)
        set_target_properties(${PROJECT_NAME} PROPERTIES LINK_FLAGS_RELEASE "/SUBSYSTEM:WINDOWS,5.02 /ENTRY:mainCRTStartup")
        set_target_properties(${PROJECT_NAME} PROPERTIES LINK_FLAGS_MINSIZEREL "/SUBSYSTEM:WINDOWS,5.02")
    else()
        set_target_properties(${PROJECT_NAME} PROPERTIES LINK_FLAGS_RELEASE "/SUBSYSTEM:WINDOWS,5.01 /ENTRY:mainCRTStartup")
        set_target_properties(${PROJECT_NAME} PROPERTIES LINK_FLAGS_MINSIZEREL "/SUBSYSTEM:WINDOWS,5.01")
    endif()
endif()

if(NOT WIN32)
	install(TARGETS ${PROJECT_NAME}
		RUNTIME DESTINATION bin
		LIBRARY DESTINATION lib)
endif()

if(ENABLE_TESTING)
	add_subdirectory(src/tests)
endif()

if(UNIX)
	install(FILES src/icons/${PROJECT_NAME}.png
		DESTINATION share/icons/hicolor/256x256/apps/)

	install(FILES distri/${PROJECT_NAME}.desktop
		DESTINATION share/applications/)

	install(FILES distri/${PROJECT_NAME}.desktop.appdata.xml
		DESTINATION share/appdata/)
endif(UNIX)

if(WIN32 AND MSVC)
	install(TARGETS ${PROJECT_NAME}
		RUNTIME DESTINATION "/"
		LIBRARY DESTINATION lib)

	set(QT5_BIN_PATH ${QT5_PATH}/bin)
	# The Qt5 Debug configuration library files have a 'd' postfix
	install(FILES
			${QT5_BIN_PATH}/Qt5Cored.dll
			${QT5_BIN_PATH}/Qt5Guid.dll
			${QT5_BIN_PATH}/Qt5Networkd.dll
			${QT5_BIN_PATH}/Qt5PrintSupportd.dll
			${QT5_BIN_PATH}/Qt5Widgetsd.dll
			${QT5_BIN_PATH}/Qt5Concurrentd.dll
		DESTINATION "/"
		CONFIGURATIONS Debug)
	# The Qt5 Release configuration files don't have a postfix
	install(FILES
			${QT5_BIN_PATH}/Qt5Core.dll
			${QT5_BIN_PATH}/Qt5Gui.dll
			${QT5_BIN_PATH}/Qt5Network.dll
			${QT5_BIN_PATH}/Qt5PrintSupport.dll
			${QT5_BIN_PATH}/Qt5Widgets.dll
			${QT5_BIN_PATH}/Qt5Concurrent.dll
		DESTINATION "/"
		CONFIGURATIONS Release)
	# The files below are common to all configurations
	install(FILES
			${SQLITE3_DLL}
			${OPENSSL_PATH}/libeay32.dll
			${OPENSSL_PATH}/ssleay32.dll
		DESTINATION "/")
	install(FILES
		${QT5_PATH}/plugins/platforms/qwindows.dll
		DESTINATION platforms)

	# The XML dll
	install(FILES
			"${QT5_PATH}/bin/Qt5Xmld.dll"
		DESTINATION "/"
		CONFIGURATIONS Debug)
	install(FILES
			"${QT5_PATH}/bin/Qt5Xml.dll"
		DESTINATION "/"
		CONFIGURATIONS Release)

	# The image format plugins
	install(FILES
			${WIN_IMG_PLUGINS_DEBUG}
		DESTINATION imageformats
		CONFIGURATIONS Debug)
	install(FILES
			${WIN_IMG_PLUGINS}
		DESTINATION imageformats
		CONFIGURATIONS Release)

	# The license files
	install(FILES
			${LICENSE_FILES}
		DESTINATION licenses)

	# The batch file launcher
	install(FILES
			distri/winlaunch.bat
		DESTINATION "/")
endif()
