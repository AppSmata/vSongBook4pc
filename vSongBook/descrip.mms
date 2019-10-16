#*****************************************************************************
#                                                                            *
# Make file for VMS                                                          *
# Author : J.Jansen (joukj@hrem.nano.tudelft.nl)                             *
# Date : 22 August 2013                                                      *
#                                                                            *
#*****************************************************************************
.first
	define wx [--.include.wx]

.ifdef __WXMOTIF__
CXX_DEFINE = /define=(__WXMOTIF__=1)/name=(as_is,short)\
	   /assume=(nostdnew,noglobal_array_new)
.else
.ifdef __WXGTK__
CXX_DEFINE = /define=(__WXGTK__=1)/float=ieee/name=(as_is,short)/ieee=denorm\
	   /assume=(nostdnew,noglobal_array_new)
.else
.ifdef __WXGTK2__
CXX_DEFINE = /define=(__WXGTK__=1,VMS_GTK2=1)/float=ieee/name=(as_is,short)/ieee=denorm\
	   /assume=(nostdnew,noglobal_array_new)
.else
.ifdef __WXX11__
CXX_DEFINE = /define=(__WXX11__=1,__WXUNIVERSAL__==1)/float=ieee\
	/name=(as_is,short)/assume=(nostdnew,noglobal_array_new)
.else
CXX_DEFINE =
.endif
.endif
.endif
.endif

.suffixes : .cpp

.cpp.obj :
	cxx $(CXXFLAGS)$(CXX_DEFINE) $(MMS$TARGET_NAME).cpp

all :
.ifdef __WXMOTIF__
	$(MMS)$(MMSQUALIFIERS) vSongBook.exe
.else
.ifdef __WXGTK__
	$(MMS)$(MMSQUALIFIERS) vSongBook_gtk.exe
.else
.ifdef __WXGTK2__
	$(MMS)$(MMSQUALIFIERS) vSongBook_gtk2.exe
.else
.ifdef __WXX11__
	$(MMS)$(MMSQUALIFIERS) vSongBook_x11.exe
.endif
.endif
.endif
.endif

.ifdef __WXMOTIF__
vSongBook.exe : vSongBook.obj
	cxxlink vSongBook,[--.lib]vms/opt
.else
.ifdef __WXGTK__
vSongBook_gtk.exe : vSongBook.obj
	cxxlink/exec=vSongBook_gtk.exe vSongBook,[--.lib]vms_gtk/opt
.else
.ifdef __WXGTK2__
vSongBook_gtk2.exe : vSongBook.obj
	cxxlink/exec=vSongBook_gtk2.exe vSongBook,[--.lib]vms_gtk2/opt
.else
.ifdef __WXX11__
vSongBook_x11.exe : vSongBook.obj
	cxxlink/exec=vSongBook_x11.exe vSongBook,[--.lib]vms_x11_univ/opt
.endif
.endif
.endif
.endif

vSongBook.obj : vSongBook.cpp
