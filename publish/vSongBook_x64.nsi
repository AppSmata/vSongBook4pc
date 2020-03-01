############################################################################################
#      NSIS Installation Script created by NSIS Quick Setup Script Generator v1.09.18
#      Copyright AppSmata Solutions              
############################################################################################

!define APP_NAME "vSongBook"
!define COMP_NAME "AppSmata Solutions"
!define WEB_SITE "http://Appsmata.com/vSongBook"
!define VERSION "2.5.6.0"
!define COPYRIGHT "© AppSmata Solutions 2016 - 2020"
!define DESCRIPTION "${APP_NAME}"
!define INSTALLER_NAME "D:\QtP\vSongBook\publish\latest\${APP_NAME}_${VERSION}_x64.exe"
!define MAIN_APP_EXE "vSongBook.exe"
!define INSTALL_TYPE "SetShellVarContext current"
!define REG_ROOT "HKCU"
!define REG_APP_PATH "Software\Microsoft\Windows\CurrentVersion\App Paths\${MAIN_APP_EXE}"
!define UNINSTALL_PATH "Software\Microsoft\Windows\CurrentVersion\Uninstall\${APP_NAME}"

######################################################################

VIProductVersion  "${VERSION}"
VIAddVersionKey "ProductName"  "${APP_NAME}"
VIAddVersionKey "CompanyName"  "${COMP_NAME}"
VIAddVersionKey "LegalCopyright"  "${COPYRIGHT}"
VIAddVersionKey "FileDescription"  "${DESCRIPTION}"
VIAddVersionKey "FileVersion"  "${VERSION}"

######################################################################

SetCompressor ZLIB
Name "${APP_NAME}"
Caption "${APP_NAME}"
OutFile "${INSTALLER_NAME}"
BrandingText "${APP_NAME}"
XPStyle on
InstallDirRegKey "${REG_ROOT}" "${REG_APP_PATH}" ""
InstallDir "$LOCALAPPDATA\AppSmata\vSongBook"

######################################################################

!include "MUI.nsh"

!define MUI_ICON "D:\QtP\vSongBook\publish\vSongBook.ico"

!define MUI_ABORTWARNING
!define MUI_UNABORTWARNING

!insertmacro MUI_PAGE_WELCOME

!ifdef LICENSE_TXT
!insertmacro MUI_PAGE_LICENSE "${LICENSE_TXT}"
!endif

!ifdef REG_START_MENU
!define MUI_STARTMENUPAGE_NODISABLE
!define MUI_STARTMENUPAGE_DEFAULTFOLDER "vSongBook"
!define MUI_STARTMENUPAGE_REGISTRY_ROOT "${REG_ROOT}"
!define MUI_STARTMENUPAGE_REGISTRY_KEY "${UNINSTALL_PATH}"
!define MUI_STARTMENUPAGE_REGISTRY_VALUENAME "${REG_START_MENU}"
!insertmacro MUI_PAGE_STARTMENU Application $SM_Folder
!endif

!insertmacro MUI_PAGE_INSTFILES

!define MUI_FINISHPAGE_RUN "$INSTDIR\${MAIN_APP_EXE}"
!insertmacro MUI_PAGE_FINISH

!insertmacro MUI_UNPAGE_CONFIRM

!insertmacro MUI_UNPAGE_INSTFILES

!insertmacro MUI_UNPAGE_FINISH

!insertmacro MUI_LANGUAGE "English"

ShowInstDetails nevershow
ShowUninstDetails nevershow

Section
SetDetailsPrint none
SectionEnd
######################################################################

Section -MainProgram
${INSTALL_TYPE}
SetOverwrite ifnewer
SetOutPath "$INSTDIR"
File "D:\QtP\vSongBook\build_64\Qt5Concurrent.dll"
File "D:\QtP\vSongBook\build_64\Qt5Core.dll"
File "D:\QtP\vSongBook\build_64\Qt5Gui.dll"
File "D:\QtP\vSongBook\build_64\Qt5Network.dll"
File "D:\QtP\vSongBook\build_64\Qt5PrintSupport.dll"
File "D:\QtP\vSongBook\build_64\Qt5Widgets.dll"
File "D:\QtP\vSongBook\build_64\Qt5Xml.dll"
File "D:\QtP\vSongBook\build_64\sqlite3.dll"
File "D:\QtP\vSongBook\build_64\vSongBook.exe"
File "D:\QtP\vSongBook\build_64\vc_redist.x64.exe"
SetOutPath "$INSTDIR\res"
File "D:\QtP\vSongBook\build_64\res\check.png"
File "D:\QtP\vSongBook\build_64\res\icon.png"
File "D:\QtP\vSongBook\build_64\res\settings.png"
File "D:\QtP\vSongBook\build_64\res\splash.png"
File "D:\QtP\vSongBook\build_64\res\style.qss"
File "D:\QtP\vSongBook\build_64\res\vSongBook.png"
SetOutPath "$INSTDIR\platforms"
File "D:\QtP\vSongBook\build_64\platforms\qwindows.dll"
SetOutPath "$INSTDIR\printsupport"
File "D:\QtP\vSongBook\build_64\printsupport\windowsprintersupport.dll"
SetOutPath "$INSTDIR\licenses"
File "D:\QtP\vSongBook\build_64\licenses\LICENSE"
File "D:\QtP\vSongBook\build_64\licenses\LICENSE-PLUGINS"
SetOutPath "$INSTDIR\imageformats"
File "D:\QtP\vSongBook\build_64\imageformats\qgif.dll"
File "D:\QtP\vSongBook\build_64\imageformats\qicns.dll"
File "D:\QtP\vSongBook\build_64\imageformats\qico.dll"
File "D:\QtP\vSongBook\build_64\imageformats\qjpeg.dll"
File "D:\QtP\vSongBook\build_64\imageformats\qsvg.dll"
File "D:\QtP\vSongBook\build_64\imageformats\qtga.dll"
File "D:\QtP\vSongBook\build_64\imageformats\qtiff.dll"
File "D:\QtP\vSongBook\build_64\imageformats\qwbmp.dll"
File "D:\QtP\vSongBook\build_64\imageformats\qwebp.dll"
SetOutPath "$INSTDIR\Data"
File "D:\QtP\vSongBook\build_64\Data\init.log"
File "D:\QtP\vSongBook\build_64\Data\vSongBook.db"
        
DetailPrint "Installing Visual C++ 2015 Redistributable (x64)"     
File "D:\QtP\vSongBook\build_64\vc_redist.x64.exe" 
ExecWait "$INSTDIR\vc_redist.x64.exe /q"         
DetailPrint "Cleaning up"         
Delete "$INSTDIR\vc_redist.x64.exe"

SectionEnd

######################################################################

Section -Icons_Reg
SetOutPath "$INSTDIR"
WriteUninstaller "$INSTDIR\uninstall.exe"

!ifdef REG_START_MENU
!insertmacro MUI_STARTMENU_WRITE_BEGIN Application
CreateDirectory "$SMPROGRAMS\$SM_Folder"
CreateShortCut "$SMPROGRAMS\$SM_Folder\${APP_NAME}.lnk" "$INSTDIR\${MAIN_APP_EXE}"
CreateShortCut "$DESKTOP\${APP_NAME}.lnk" "$INSTDIR\${MAIN_APP_EXE}"
CreateShortCut "$SMPROGRAMS\$SM_Folder\Uninstall ${APP_NAME}.lnk" "$INSTDIR\uninstall.exe"

!ifdef WEB_SITE
WriteIniStr "$INSTDIR\${APP_NAME} website.url" "InternetShortcut" "URL" "${WEB_SITE}"
CreateShortCut "$SMPROGRAMS\$SM_Folder\${APP_NAME} Website.lnk" "$INSTDIR\${APP_NAME} website.url"
!endif
!insertmacro MUI_STARTMENU_WRITE_END
!endif

!ifndef REG_START_MENU
CreateDirectory "$SMPROGRAMS\AppSmata"
CreateShortCut "$SMPROGRAMS\AppSmata\${APP_NAME}.lnk" "$INSTDIR\${MAIN_APP_EXE}"
CreateShortCut "$DESKTOP\${APP_NAME}.lnk" "$INSTDIR\${MAIN_APP_EXE}"
CreateShortCut "$SMPROGRAMS\AppSmata\Uninstall ${APP_NAME}.lnk" "$INSTDIR\uninstall.exe"

!ifdef WEB_SITE
WriteIniStr "$INSTDIR\${APP_NAME} website.url" "InternetShortcut" "URL" "${WEB_SITE}"
CreateShortCut "$SMPROGRAMS\AppSmata\${APP_NAME} Website.lnk" "$INSTDIR\${APP_NAME} website.url"
!endif
!endif

WriteRegStr ${REG_ROOT} "${REG_APP_PATH}" "" "$INSTDIR\${MAIN_APP_EXE}"
WriteRegStr ${REG_ROOT} "${UNINSTALL_PATH}"  "DisplayName" "${APP_NAME}"
WriteRegStr ${REG_ROOT} "${UNINSTALL_PATH}"  "UninstallString" "$INSTDIR\uninstall.exe"
WriteRegStr ${REG_ROOT} "${UNINSTALL_PATH}"  "DisplayIcon" "$INSTDIR\${MAIN_APP_EXE}"
WriteRegStr ${REG_ROOT} "${UNINSTALL_PATH}"  "DisplayVersion" "${VERSION}"
WriteRegStr ${REG_ROOT} "${UNINSTALL_PATH}"  "Publisher" "${COMP_NAME}"

!ifdef WEB_SITE
WriteRegStr ${REG_ROOT} "${UNINSTALL_PATH}"  "URLInfoAbout" "${WEB_SITE}"
!endif
SectionEnd

######################################################################

Section Uninstall
${INSTALL_TYPE} 
RmDir /r /REBOOTOK "$INSTDIR\Data"
RmDir /r /REBOOTOK "$INSTDIR\imageformats"
RmDir /r /REBOOTOK "$INSTDIR\licenses"
RmDir /r /REBOOTOK "$INSTDIR\platforms"
RmDir /r /REBOOTOK "$INSTDIR\res"
 
Delete "$INSTDIR\uninstall.exe"
!ifdef WEB_SITE
Delete "$INSTDIR\${APP_NAME} website.url"
!endif

RmDir /r /REBOOTOK "$INSTDIR"

!ifdef REG_START_MENU
!insertmacro MUI_STARTMENU_GETFOLDER "Application" $SM_Folder
Delete "$SMPROGRAMS\$SM_Folder\${APP_NAME}.lnk"
Delete "$SMPROGRAMS\$SM_Folder\Uninstall ${APP_NAME}.lnk"
!ifdef WEB_SITE
Delete "$SMPROGRAMS\$SM_Folder\${APP_NAME} Website.lnk"
!endif
Delete "$DESKTOP\${APP_NAME}.lnk"

RmDir "$SMPROGRAMS\$SM_Folder"
!endif

!ifndef REG_START_MENU
Delete "$SMPROGRAMS\vSongBook\${APP_NAME}.lnk"
Delete "$SMPROGRAMS\vSongBook\Uninstall ${APP_NAME}.lnk"
!ifdef WEB_SITE
Delete "$SMPROGRAMS\vSongBook\${APP_NAME} Website.lnk"
!endif
Delete "$DESKTOP\${APP_NAME}.lnk"

RmDir "$SMPROGRAMS\vSongBook"
!endif

DeleteRegKey ${REG_ROOT} "${REG_APP_PATH}"
DeleteRegKey ${REG_ROOT} "${UNINSTALL_PATH}"
SectionEnd

######################################################################
