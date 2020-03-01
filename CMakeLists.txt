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
OPTION(FORCE_INTERNAL_QSCINTILLA "Don't use the distribution's QScintilla library even if there is one" OFF)
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
		set(QT5_PATH "D:/Qt/5.9.9/msvc2015_64" CACHE PATH "Qt5 Path")
	else()
		set(QT5_PATH "D:/Qt/5.9.9/msvc2015" CACHE PATH "Qt5 Path")
	endif()
	set(CMAKE_PREFIX_PATH "${QT5_PATH}")
endif()

find_package(Qt5 REQUIRED COMPONENTS Concurrent Gui LinguistTools Network PrintSupport Test Widgets Xml)

if(FORCE_INTERNAL_QCUSTOMPLOT)
    set(QCUSTOMPLOT_FOUND FALSE)
else()
    find_package(QCustomPlot)
endif()

if(NOT QCUSTOMPLOT_FOUND)
    set(QCUSTOMPLOT_DIR libs/qcustomplot-source)
    add_subdirectory(${QCUSTOMPLOT_DIR})
endif()

set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

if(ENABLE_TESTING)
    enable_testing()
endif()

set(APP_HDR
	src/version.h
)

set(APP_MOC_HDR
	src/AppAbout.h
	src/AppEditor.h
	src/AppMain.h
	src/AppOnline.h
	src/AppPreferences.h
	src/AppPresent.h
	src/AppSongbooks.h
	src/AppTutorial.h
	src/Settings.h
)

set(APP_SRC
	src/Application.cpp
	src/AppAbout.cpp
	src/AppEditor.cpp
	src/AppMain.cpp
	src/AppOnline.cpp
	src/AppPreferences.cpp
	src/AppPresent.cpp
	src/AppSongbooks.cpp
	src/AppTutorial.cpp
	src/main.cpp
	src/Settings.cpp
)

set(APP_FORMS
	src/AppAbout.ui
	src/AppEditor.ui
	src/AppMain.ui
	src/AppOnline.ui
	src/AppPreferences.ui
	src/AppPresent.ui
	src/AppSongbooks.ui
	src/AppTutorial.ui
)

set(APP_RESOURCES
	src/icons/icons.qrc
	src/translations/flags/flags.qrc
	src/translations/translations.qrc
	src/qdarkstyle/style.qrc
	src/qstyle/style.qrc
)

# Translation files
set(APP_TSS
	"${CMAKE_SOURCE_DIR}/src/translations/sqlb_de.ts"
	"${CMAKE_SOURCE_DIR}/src/translations/sqlb_es_ES.ts"
	"${CMAKE_SOURCE_DIR}/src/translations/sqlb_fr.ts"
	"${CMAKE_SOURCE_DIR}/src/translations/sqlb_en_GB.ts"
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

qt5_wrap_ui(APP_FORM_HDR ${APP_FORMS})
if(APP_TSS)
	# add translations
	foreach(APP_TS ${APP_TSS})
		SET_SOURCE_FILES_PROPERTIES("${APP_TS}" PROPERTIES OUTPUT_LOCATION "${CMAKE_SOURCE_DIR}/src/translations")
	endforeach(APP_TS ${APP_TSS})
	qt5_add_translation(APP_QMS ${APP_TSS})
endif(APP_TSS)
qt5_add_resources(APP_RESOURCES_RCC ${APP_RESOURCES})

#icon and correct libs/subsystem for windows
if(WIN32)
        #enable version check for windows
        add_definitions(-DCHECKNEWVERSION)

	IF( MINGW )
	# resource compilation for MinGW
		ADD_CUSTOM_COMMAND(OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/sqlbicon.o"
			COMMAND windres "-I${CMAKE_CURRENT_SOURCE_DIR}" "-i${CMAKE_CURRENT_SOURCE_DIR}/src/winapp.rc" -o "${CMAKE_CURRENT_BINARY_DIR}/sqlbicon.o" VERBATIM)
		set(APP_SRC ${APP_SRC} "${CMAKE_CURRENT_BINARY_DIR}/sqlbicon.o")
		set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,-subsystem,windows")
		set(WIN32_STATIC_LINK -Wl,-Bstatic -lssl -lcrypto -lws2_32)
		set(ADDITIONAL_LIBS lzma)
	ELSE( MINGW )
		set(APP_SRC ${APP_SRC} "${CMAKE_CURRENT_SOURCE_DIR}/src/winapp.rc")
	ENDIF( MINGW )
else()
	set(LPTHREAD pthread)
endif(WIN32)

#enable version check for MacOS
if(APPLE)
	add_definitions(-DCHECKNEWVERSION)
endif(APPLE)

# add extra library path for MacOS and FreeBSD
set(EXTRAPATH APPLE OR ${CMAKE_SYSTEM_NAME} MATCHES "FreeBSD")

include_directories(
		"${CMAKE_CURRENT_BINARY_DIR}"
		${ADDITIONAL_INCLUDE_PATHS}
		src)
if(QCUSTOMPLOT_FOUND)
    include_directories(${QCUSTOMPLOT_INCLUDE_DIR})
else()
    include_directories(${QCUSTOMPLOT_DIR})
endif()

add_executable(${PROJECT_NAME}
		${APP_HDR}
		${APP_SRC}
		${APP_FORM_HDR}
		${APP_MOC}
		${APP_RESOURCES_RCC})


# Warnings
if (ALL_WARNINGS AND CMAKE_COMPILER_IS_GNUCC)
    target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wshadow -Wnon-virtual-dtor -Wold-style-cast -Wcast-align -Wunused -Woverloaded-virtual -Wpedantic -Wconversion -Wsign-conversion)
    target_compile_options(${PROJECT_NAME} PRIVATE -Wdouble-promotion -Wformat=2 -Wlogical-op -Wuseless-cast)
    if(CMAKE_CXX_COMPILER_VERSION VERSION_GREATER_EQUAL 7.0)
        target_compile_options(${PROJECT_NAME} PRIVATE -Wnull-dereference -Wduplicated-cond -Wduplicated-branches)
    endif()
endif()

if(NOT QCUSTOMPLOT_FOUND)
    add_dependencies(${PROJECT_NAME} qcustomplot)
endif()
if(NOT QCUSTOMPLOT_FOUND)
    link_directories("${CMAKE_CURRENT_BINARY_DIR}/${QCUSTOMPLOT_DIR}")
endif()
set(QT_LIBS Qt5::Gui Qt5::Test Qt5::PrintSupport Qt5::Widgets Qt5::Network Qt5::Concurrent Qt5::Xml)

target_link_libraries(${PROJECT_NAME}
    ${LPTHREAD}
    ${QT_LIBS}
    ${WIN32_STATIC_LINK}
    ${ADDITIONAL_LIBS})
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
