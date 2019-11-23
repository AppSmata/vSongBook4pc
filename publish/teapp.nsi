SetCompress auto
SetCompressor lzma
SetCompressorDictSize 64 ; Sets the dictionary size in megabytes
#FileSize 4000 ; Sets the max single file size in megabytes, 0 means no limit.
;SetDataFile force ; it can be off/auto/force, default is auto.
; if SetDataFile set to auto,and FileSize set to be 0, it means once the total length reaches 4GB, it will use data file ,and the data file is single
; if SetDataFile set to auto,and FileSize set to be none-zero, it means once the total length reaches FileSize, it will use data file, and the data file is stored per FileSize.

!define APP_NAME "TechElimu"
!define COMP_NAME "TechElimu"
!define WEB_SITE "http://www.techelimu.ac.ke"
!define VERSION "0.0.1.2"
!define COPYRIGHT "© TechElimu 2019"
!define DESCRIPTION "TechElimu"
!define INSTALLER_NAME "D:\wpf\TechElimu\publish\outputs\TechElimu${VERSION}.exe"
!define MAIN_APP_EXE "TechElimu.exe"
!define INSTALL_TYPE "SetShellVarContext all"
!define REG_ROOT "HKLM"
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
InstallDir "$LOCALAPPDATA\TechElimu"

######################################################################

!include "MUI.nsh"

!define MUI_ICON "D:\wpf\TechElimu\publish\teapp.ico"

!define MUI_ABORTWARNING
!define MUI_UNABORTWARNING

!insertmacro MUI_PAGE_WELCOME

!ifdef LICENSE_TXT
!insertmacro MUI_PAGE_LICENSE "${LICENSE_TXT}"
!endif

!ifdef REG_START_MENU
!define MUI_STARTMENUPAGE_NODISABLE
!define MUI_STARTMENUPAGE_DEFAULTFOLDER "TechElimu"
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

######################################################################

Section -MainProgram
SetDetailsPrint none
${INSTALL_TYPE}
SetOverwrite ifnewer
SetOutPath "$INSTDIR"
FileOpen $9 TechPackage.tef w
FileWrite $9 "$EXEDIR\TechPackage.tef"
FileClose $9
SetOutPath "$INSTDIR"
File "D:\wpf\TechElimu\TechElimu\bin\Latest\ControlzEx.dll"
File "D:\wpf\TechElimu\TechElimu\bin\Latest\DotNetZip.dll"
File "D:\wpf\TechElimu\TechElimu\bin\Latest\Dragablz.dll"
File "D:\wpf\TechElimu\TechElimu\bin\Latest\EntityFramework.dll"
File "D:\wpf\TechElimu\TechElimu\bin\Latest\EntityFramework.SqlServer.dll"
File "D:\wpf\TechElimu\TechElimu\bin\Latest\Geckofx-Core.dll"
File "D:\wpf\TechElimu\TechElimu\bin\Latest\Geckofx-Winforms.dll"
File "D:\wpf\TechElimu\TechElimu\bin\Latest\libmupdf.dll"
File "D:\wpf\TechElimu\TechElimu\bin\Latest\MahApps.Metro.dll"
File "D:\wpf\TechElimu\TechElimu\bin\Latest\MaterialDesignColors.dll"
File "D:\wpf\TechElimu\TechElimu\bin\Latest\MaterialDesignThemes.MahApps.dll"
File "D:\wpf\TechElimu\TechElimu\bin\Latest\MaterialDesignThemes.Wpf.dll"
File "D:\wpf\TechElimu\TechElimu\bin\Latest\Microsoft.Threading.Tasks.dll"
File "D:\wpf\TechElimu\TechElimu\bin\Latest\Microsoft.Threading.Tasks.Extensions.Desktop.dll"
File "D:\wpf\TechElimu\TechElimu\bin\Latest\Microsoft.Threading.Tasks.Extensions.dll"
File "D:\wpf\TechElimu\TechElimu\bin\Latest\Mono.Cecil.dll"
File "D:\wpf\TechElimu\TechElimu\bin\Latest\Mono.Cecil.Mdb.dll"
File "D:\wpf\TechElimu\TechElimu\bin\Latest\Mono.Cecil.Pdb.dll"
File "D:\wpf\TechElimu\TechElimu\bin\Latest\Mono.Cecil.Rocks.dll"
File "D:\wpf\TechElimu\TechElimu\bin\Latest\MoonPdfLib.dll"
File "D:\wpf\TechElimu\TechElimu\bin\Latest\MouseKeyboardActivityMonitor.dll"
File "D:\wpf\TechElimu\TechElimu\bin\Latest\Newtonsoft.Json.dll"
File "D:\wpf\TechElimu\TechElimu\bin\Latest\RestSharp.dll"
File "D:\wpf\TechElimu\TechElimu\bin\Latest\Splat.dll"
File "D:\wpf\TechElimu\TechElimu\bin\Latest\SQLite-net.dll"
File "D:\wpf\TechElimu\TechElimu\bin\Latest\SQLitePCLRaw.batteries_green.dll"
File "D:\wpf\TechElimu\TechElimu\bin\Latest\SQLitePCLRaw.batteries_v2.dll"
File "D:\wpf\TechElimu\TechElimu\bin\Latest\SQLitePCLRaw.core.dll"
File "D:\wpf\TechElimu\TechElimu\bin\Latest\SQLitePCLRaw.provider.e_sqlite3.dll"
File "D:\wpf\TechElimu\TechElimu\bin\Latest\System.Data.SQLite.dll"
File "D:\wpf\TechElimu\TechElimu\bin\Latest\System.Windows.Interactivity.dll"
File "D:\wpf\TechElimu\TechElimu\bin\Latest\TechElimu.application"
File "D:\wpf\TechElimu\TechElimu\bin\Latest\TechElimu.exe"
File "D:\wpf\TechElimu\TechElimu\bin\Latest\TechElimu.exe.manifest"
File "D:\wpf\TechElimu\TechElimu\bin\Latest\TechElimu.Helper.dll"
File "D:\wpf\TechElimu\TechElimu\bin\Latest\TechSoftware.tef"
File "D:\wpf\TechElimu\TechElimu\bin\Latest\TechUninstaller.exe"
File "D:\wpf\TechElimu\TechElimu\bin\Latest\TechUnzipper.exe"
File "D:\wpf\TechElimu\TechElimu\bin\Latest\WinSparkle.dll"
SetOutPath "$INSTDIR\x86"
File "D:\wpf\TechElimu\TechElimu\bin\Latest\x86\e_sqlite3.dll"
File "D:\wpf\TechElimu\TechElimu\bin\Latest\x86\SQLite.Interop.dll"
SetOutPath "$INSTDIR\x64"
File "D:\wpf\TechElimu\TechElimu\bin\Latest\x64\e_sqlite3.dll"
File "D:\wpf\TechElimu\TechElimu\bin\Latest\x64\SQLite.Interop.dll"
SetOutPath "$INSTDIR\Resources"
File "D:\wpf\TechElimu\TechElimu\bin\Latest\Resources\techelimu.html"
File "D:\wpf\TechElimu\TechElimu\bin\Latest\Resources\techelimu.pdf"
SetOutPath "$INSTDIR\Firefox64"
File "D:\wpf\TechElimu\TechElimu\bin\Latest\Firefox64\AccessibleHandler.dll"
File "D:\wpf\TechElimu\TechElimu\bin\Latest\Firefox64\AccessibleMarshal.dll"
File "D:\wpf\TechElimu\TechElimu\bin\Latest\Firefox64\d3dcompiler_47.dll"
File "D:\wpf\TechElimu\TechElimu\bin\Latest\Firefox64\freebl3.dll"
File "D:\wpf\TechElimu\TechElimu\bin\Latest\Firefox64\IA2Marshal.dll"
File "D:\wpf\TechElimu\TechElimu\bin\Latest\Firefox64\lgpllibs.dll"
File "D:\wpf\TechElimu\TechElimu\bin\Latest\Firefox64\libEGL.dll"
File "D:\wpf\TechElimu\TechElimu\bin\Latest\Firefox64\libGLESv2.dll"
File "D:\wpf\TechElimu\TechElimu\bin\Latest\Firefox64\mozavcodec.dll"
File "D:\wpf\TechElimu\TechElimu\bin\Latest\Firefox64\mozavutil.dll"
File "D:\wpf\TechElimu\TechElimu\bin\Latest\Firefox64\mozglue.dll"
File "D:\wpf\TechElimu\TechElimu\bin\Latest\Firefox64\nss3.dll"
File "D:\wpf\TechElimu\TechElimu\bin\Latest\Firefox64\nssckbi.dll"
File "D:\wpf\TechElimu\TechElimu\bin\Latest\Firefox64\nssdbm3.dll"
File "D:\wpf\TechElimu\TechElimu\bin\Latest\Firefox64\omni.ja"
File "D:\wpf\TechElimu\TechElimu\bin\Latest\Firefox64\plugin-container.exe"
File "D:\wpf\TechElimu\TechElimu\bin\Latest\Firefox64\plugin-hang-ui.exe"
File "D:\wpf\TechElimu\TechElimu\bin\Latest\Firefox64\qipcap64.dll"
File "D:\wpf\TechElimu\TechElimu\bin\Latest\Firefox64\softokn3.dll"
File "D:\wpf\TechElimu\TechElimu\bin\Latest\Firefox64\xul.dll"
SetOutPath "$INSTDIR\Firefox"
File "D:\wpf\TechElimu\TechElimu\bin\Latest\Firefox\AccessibleHandler.dll"
File "D:\wpf\TechElimu\TechElimu\bin\Latest\Firefox\AccessibleMarshal.dll"
File "D:\wpf\TechElimu\TechElimu\bin\Latest\Firefox\breakpadinjector.dll"
File "D:\wpf\TechElimu\TechElimu\bin\Latest\Firefox\d3dcompiler_47.dll"
File "D:\wpf\TechElimu\TechElimu\bin\Latest\Firefox\freebl3.dll"
File "D:\wpf\TechElimu\TechElimu\bin\Latest\Firefox\IA2Marshal.dll"
File "D:\wpf\TechElimu\TechElimu\bin\Latest\Firefox\lgpllibs.dll"
File "D:\wpf\TechElimu\TechElimu\bin\Latest\Firefox\libEGL.dll"
File "D:\wpf\TechElimu\TechElimu\bin\Latest\Firefox\libGLESv2.dll"
File "D:\wpf\TechElimu\TechElimu\bin\Latest\Firefox\mozavcodec.dll"
File "D:\wpf\TechElimu\TechElimu\bin\Latest\Firefox\mozavutil.dll"
File "D:\wpf\TechElimu\TechElimu\bin\Latest\Firefox\mozglue.dll"
File "D:\wpf\TechElimu\TechElimu\bin\Latest\Firefox\nss3.dll"
File "D:\wpf\TechElimu\TechElimu\bin\Latest\Firefox\nssckbi.dll"
File "D:\wpf\TechElimu\TechElimu\bin\Latest\Firefox\nssdbm3.dll"
File "D:\wpf\TechElimu\TechElimu\bin\Latest\Firefox\omni.ja"
File "D:\wpf\TechElimu\TechElimu\bin\Latest\Firefox\plugin-container.exe"
File "D:\wpf\TechElimu\TechElimu\bin\Latest\Firefox\plugin-hang-ui.exe"
File "D:\wpf\TechElimu\TechElimu\bin\Latest\Firefox\qipcap.dll"
File "D:\wpf\TechElimu\TechElimu\bin\Latest\Firefox\softokn3.dll"
File "D:\wpf\TechElimu\TechElimu\bin\Latest\Firefox\xul.dll"
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
WriteIniStr "$INSTDIR\TechElimu website.url" "InternetShortcut" "URL" "${WEB_SITE}"
CreateShortCut "$SMPROGRAMS\$SM_Folder\KEC Website.lnk" "$INSTDIR\KEC website.url"
!endif
!insertmacro MUI_STARTMENU_WRITE_END
!endif

!ifndef REG_START_MENU
CreateDirectory "$SMPROGRAMS\TechElimu"
CreateShortCut "$SMPROGRAMS\TechElimu\${APP_NAME}.lnk" "$INSTDIR\${MAIN_APP_EXE}"
CreateShortCut "$DESKTOP\${APP_NAME}.lnk" "$INSTDIR\${MAIN_APP_EXE}"
CreateShortCut "$SMPROGRAMS\TechElimu\Uninstall ${APP_NAME}.lnk" "$INSTDIR\uninstall.exe"

!ifdef WEB_SITE
WriteIniStr "$INSTDIR\${APP_NAME} website.url" "InternetShortcut" "URL" "${WEB_SITE}"
CreateShortCut "$SMPROGRAMS\TechElimu\${APP_NAME} Website.lnk" "$INSTDIR\${APP_NAME} website.url"
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

WriteRegStr HKCR ".ice" "" "TechElimu"
WriteRegStr HKCR "TechElimu\shell\open\command" "" "$INSTDIR\${MAIN_APP_EXE}"

SectionEnd

######################################################################

Section Uninstall
SetDetailsPrint none
ExecWait '"$INSTDIR\TechUninstall.exe" /S _?=$INSTDIR'

${INSTALL_TYPE}
Delete "$INSTDIR\ControlzEx.dll"
Delete "$INSTDIR\DotNetZip.dll"
Delete "$INSTDIR\Dragablz.dll"
Delete "$INSTDIR\EntityFramework.dll"
Delete "$INSTDIR\EntityFramework.SqlServer.dll"
Delete "$INSTDIR\Geckofx-Core.dll"
Delete "$INSTDIR\Geckofx-Winforms.dll"
Delete "$INSTDIR\libmupdf.dll"
Delete "$INSTDIR\MahApps.Metro.dll"
Delete "$INSTDIR\MaterialDesignColors.dll"
Delete "$INSTDIR\MaterialDesignThemes.MahApps.dll"
Delete "$INSTDIR\MaterialDesignThemes.Wpf.dll"
Delete "$INSTDIR\Microsoft.Threading.Tasks.dll"
Delete "$INSTDIR\Microsoft.Threading.Tasks.Extensions.Desktop.dll"
Delete "$INSTDIR\Microsoft.Threading.Tasks.Extensions.dll"
Delete "$INSTDIR\Mono.Cecil.dll"
Delete "$INSTDIR\Mono.Cecil.Mdb.dll"
Delete "$INSTDIR\Mono.Cecil.Pdb.dll"
Delete "$INSTDIR\Mono.Cecil.Rocks.dll"
Delete "$INSTDIR\MoonPdfLib.dll"
Delete "$INSTDIR\MouseKeyboardActivityMonitor.dll"
Delete "$INSTDIR\Newtonsoft.Json.dll"
Delete "$INSTDIR\RestSharp.dll"
Delete "$INSTDIR\Splat.dll"
Delete "$INSTDIR\SQLite-net.dll"
Delete "$INSTDIR\SQLitePCLRaw.batteries_green.dll"
Delete "$INSTDIR\SQLitePCLRaw.batteries_v2.dll"
Delete "$INSTDIR\SQLitePCLRaw.core.dll"
Delete "$INSTDIR\SQLitePCLRaw.provider.e_sqlite3.dll"
Delete "$INSTDIR\System.Data.SQLite.dll"
Delete "$INSTDIR\System.Windows.Interactivity.dll"
Delete "$INSTDIR\TechElimu.application"
Delete "$INSTDIR\TechElimu.exe"
Delete "$INSTDIR\TechElimu.exe.manifest"
Delete "$INSTDIR\TechElimu.Helper.dll"
Delete "$INSTDIR\TechSoftware.tef"
Delete "$INSTDIR\TechUninstaller.exe"
Delete "$INSTDIR\TechUnzipper.exe"
Delete "$INSTDIR\WinSparkle.dll"
Delete "$INSTDIR\x86\e_sqlite3.dll"
Delete "$INSTDIR\x86\SQLite.Interop.dll"
Delete "$INSTDIR\x64\e_sqlite3.dll"
Delete "$INSTDIR\x64\SQLite.Interop.dll"
Delete "$INSTDIR\Resources\techelimu.html"
Delete "$INSTDIR\Resources\techelimu.pdf"
Delete "$INSTDIR\Firefox64\AccessibleHandler.dll"
Delete "$INSTDIR\Firefox64\AccessibleMarshal.dll"
Delete "$INSTDIR\Firefox64\d3dcompiler_47.dll"
Delete "$INSTDIR\Firefox64\freebl3.dll"
Delete "$INSTDIR\Firefox64\IA2Marshal.dll"
Delete "$INSTDIR\Firefox64\lgpllibs.dll"
Delete "$INSTDIR\Firefox64\libEGL.dll"
Delete "$INSTDIR\Firefox64\libGLESv2.dll"
Delete "$INSTDIR\Firefox64\mozavcodec.dll"
Delete "$INSTDIR\Firefox64\mozavutil.dll"
Delete "$INSTDIR\Firefox64\mozglue.dll"
Delete "$INSTDIR\Firefox64\nss3.dll"
Delete "$INSTDIR\Firefox64\nssckbi.dll"
Delete "$INSTDIR\Firefox64\nssdbm3.dll"
Delete "$INSTDIR\Firefox64\omni.ja"
Delete "$INSTDIR\Firefox64\plugin-container.exe"
Delete "$INSTDIR\Firefox64\plugin-hang-ui.exe"
Delete "$INSTDIR\Firefox64\qipcap64.dll"
Delete "$INSTDIR\Firefox64\softokn3.dll"
Delete "$INSTDIR\Firefox64\xul.dll"
Delete "$INSTDIR\Firefox\AccessibleHandler.dll"
Delete "$INSTDIR\Firefox\AccessibleMarshal.dll"
Delete "$INSTDIR\Firefox\breakpadinjector.dll"
Delete "$INSTDIR\Firefox\d3dcompiler_47.dll"
Delete "$INSTDIR\Firefox\freebl3.dll"
Delete "$INSTDIR\Firefox\IA2Marshal.dll"
Delete "$INSTDIR\Firefox\lgpllibs.dll"
Delete "$INSTDIR\Firefox\libEGL.dll"
Delete "$INSTDIR\Firefox\libGLESv2.dll"
Delete "$INSTDIR\Firefox\mozavcodec.dll"
Delete "$INSTDIR\Firefox\mozavutil.dll"
Delete "$INSTDIR\Firefox\mozglue.dll"
Delete "$INSTDIR\Firefox\nss3.dll"
Delete "$INSTDIR\Firefox\nssckbi.dll"
Delete "$INSTDIR\Firefox\nssdbm3.dll"
Delete "$INSTDIR\Firefox\omni.ja"
Delete "$INSTDIR\Firefox\plugin-container.exe"
Delete "$INSTDIR\Firefox\plugin-hang-ui.exe"
Delete "$INSTDIR\Firefox\qipcap.dll"
Delete "$INSTDIR\Firefox\softokn3.dll"
Delete "$INSTDIR\Firefox\xul.dll"
 
RmDir "$INSTDIR\Firefox"
RmDir "$INSTDIR\Firefox64"
RmDir "$INSTDIR\Resources"
RmDir "$INSTDIR\x64"
RmDir "$INSTDIR\x86"

Delete "$INSTDIR\uninstall.exe"
!ifdef WEB_SITE
Delete "$INSTDIR\${APP_NAME} website.url"
!endif

RmDir "$INSTDIR"

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
Delete "$SMPROGRAMS\TechElimu\${APP_NAME}.lnk"
Delete "$SMPROGRAMS\TechElimu\Uninstall ${APP_NAME}.lnk"
!ifdef WEB_SITE
Delete "$SMPROGRAMS\TechElimu\${APP_NAME} Website.lnk"
!endif
Delete "$DESKTOP\${APP_NAME}.lnk"

RmDir "$SMPROGRAMS\TechElimu"
!endif

DeleteRegKey ${REG_ROOT} "${REG_APP_PATH}"
DeleteRegKey ${REG_ROOT} "${UNINSTALL_PATH}"

DeleteRegKey HKCR ".eldc"
DeleteRegKey HKCR "TechElimu\shell\open\command"

SectionEnd

######################################################################

