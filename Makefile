#############################################################################
# Makefile for building: mlpack2
# Generated by qmake (3.0) (Qt 5.3.2)
# Project:  mlpack2.pro
# Template: app
# Command: /opt/Qt5.3.2/5.3/gcc_64/bin/qmake -spec linux-g++ CONFIG+=debug -o Makefile mlpack2.pro
#############################################################################

MAKEFILE      = Makefile

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = 
CFLAGS        = -pipe -g -Wall -W -fPIE $(DEFINES)
CXXFLAGS      = -pipe -g -Wall -W -fPIE $(DEFINES)
INCPATH       = -I/opt/Qt5.3.2/5.3/gcc_64/mkspecs/linux-g++ -I. -I/usr/include/libxml2 -I/home/HaiQW/projects/QT/anomalytree/../download/include
LINK          = g++
LFLAGS        = -Wl,-rpath,/opt/Qt5.3.2/5.3/gcc_64
LIBS          = $(SUBLIBS) -L/home/HaiQW/projects/QT/anomalytree/../download/lib/ -lmlpack 
AR            = ar cqs
RANLIB        = 
QMAKE         = /opt/Qt5.3.2/5.3/gcc_64/bin/qmake
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = cp -f
COPY_DIR      = cp -f -R
STRIP         = strip
INSTALL_FILE  = install -m 644 -p
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = install -m 755 -p
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p

####### Output directory

OBJECTS_DIR   = ./

####### Files

SOURCES       = main.cpp \
		file.cpp \
		utility.cpp \
		lof.cpp \
		itree.cpp \
		dataprocess.cpp \
		iforest.cpp \
		sort.cpp \
		printhelp.cpp \
		nndm.cpp 
OBJECTS       = main.o \
		file.o \
		utility.o \
		lof.o \
		itree.o \
		dataprocess.o \
		iforest.o \
		sort.o \
		printhelp.o \
		nndm.o
DIST          = /opt/Qt5.3.2/5.3/gcc_64/mkspecs/features/spec_pre.prf \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/common/shell-unix.conf \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/common/unix.conf \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/common/linux.conf \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/common/gcc-base.conf \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/common/gcc-base-unix.conf \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/common/g++-base.conf \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/common/g++-unix.conf \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/qconfig.pri \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_bluetooth.pri \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_bluetooth_private.pri \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_bootstrap_private.pri \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_clucene_private.pri \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_concurrent.pri \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_concurrent_private.pri \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_core.pri \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_core_private.pri \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_dbus.pri \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_dbus_private.pri \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_declarative.pri \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_declarative_private.pri \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_designer.pri \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_designer_private.pri \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_designercomponents_private.pri \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_enginio.pri \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_enginio_private.pri \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_gui.pri \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_gui_private.pri \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_help.pri \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_help_private.pri \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_multimedia.pri \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_multimedia_private.pri \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_multimediawidgets.pri \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_multimediawidgets_private.pri \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_network.pri \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_network_private.pri \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_nfc.pri \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_nfc_private.pri \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_opengl.pri \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_opengl_private.pri \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_openglextensions.pri \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_openglextensions_private.pri \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_platformsupport_private.pri \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_positioning.pri \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_positioning_private.pri \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_printsupport.pri \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_printsupport_private.pri \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_qml.pri \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_qml_private.pri \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_qmldevtools_private.pri \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_qmltest.pri \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_qmltest_private.pri \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_qtmultimediaquicktools_private.pri \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_quick.pri \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_quick_private.pri \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_quickparticles_private.pri \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_quickwidgets.pri \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_quickwidgets_private.pri \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_script.pri \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_script_private.pri \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_scripttools.pri \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_scripttools_private.pri \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_sensors.pri \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_sensors_private.pri \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_serialport.pri \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_serialport_private.pri \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_sql.pri \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_sql_private.pri \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_svg.pri \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_svg_private.pri \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_testlib.pri \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_testlib_private.pri \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_uitools.pri \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_uitools_private.pri \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_webkit.pri \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_webkit_private.pri \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_webkitwidgets.pri \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_webkitwidgets_private.pri \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_websockets.pri \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_websockets_private.pri \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_widgets.pri \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_widgets_private.pri \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_x11extras.pri \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_x11extras_private.pri \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_xml.pri \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_xml_private.pri \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_xmlpatterns.pri \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_xmlpatterns_private.pri \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/features/qt_functions.prf \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/features/qt_config.prf \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/linux-g++/qmake.conf \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/features/spec_post.prf \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/features/exclusive_builds.prf \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/features/default_pre.prf \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/features/resolve_config.prf \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/features/default_post.prf \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/features/warn_on.prf \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/features/testcase_targets.prf \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/features/exceptions.prf \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/features/yacc.prf \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/features/lex.prf \
		mlpack2.pro main.cpp \
		file.cpp \
		utility.cpp \
		lof.cpp \
		itree.cpp \
		dataprocess.cpp \
		iforest.cpp \
		sort.cpp \
		printhelp.cpp \
		nndm.cpp
QMAKE_TARGET  = mlpack2
DESTDIR       = #avoid trailing-slash linebreak
TARGET        = mlpack2


first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

all: Makefile $(TARGET)

$(TARGET):  $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: mlpack2.pro /opt/Qt5.3.2/5.3/gcc_64/mkspecs/linux-g++/qmake.conf /opt/Qt5.3.2/5.3/gcc_64/mkspecs/features/spec_pre.prf \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/common/shell-unix.conf \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/common/unix.conf \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/common/linux.conf \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/common/gcc-base.conf \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/common/gcc-base-unix.conf \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/common/g++-base.conf \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/common/g++-unix.conf \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/qconfig.pri \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_bluetooth.pri \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_bluetooth_private.pri \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_bootstrap_private.pri \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_clucene_private.pri \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_concurrent.pri \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_concurrent_private.pri \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_core.pri \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_core_private.pri \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_dbus.pri \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_dbus_private.pri \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_declarative.pri \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_declarative_private.pri \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_designer.pri \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_designer_private.pri \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_designercomponents_private.pri \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_enginio.pri \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_enginio_private.pri \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_gui.pri \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_gui_private.pri \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_help.pri \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_help_private.pri \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_multimedia.pri \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_multimedia_private.pri \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_multimediawidgets.pri \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_multimediawidgets_private.pri \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_network.pri \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_network_private.pri \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_nfc.pri \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_nfc_private.pri \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_opengl.pri \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_opengl_private.pri \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_openglextensions.pri \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_openglextensions_private.pri \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_platformsupport_private.pri \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_positioning.pri \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_positioning_private.pri \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_printsupport.pri \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_printsupport_private.pri \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_qml.pri \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_qml_private.pri \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_qmldevtools_private.pri \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_qmltest.pri \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_qmltest_private.pri \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_qtmultimediaquicktools_private.pri \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_quick.pri \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_quick_private.pri \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_quickparticles_private.pri \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_quickwidgets.pri \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_quickwidgets_private.pri \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_script.pri \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_script_private.pri \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_scripttools.pri \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_scripttools_private.pri \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_sensors.pri \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_sensors_private.pri \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_serialport.pri \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_serialport_private.pri \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_sql.pri \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_sql_private.pri \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_svg.pri \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_svg_private.pri \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_testlib.pri \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_testlib_private.pri \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_uitools.pri \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_uitools_private.pri \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_webkit.pri \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_webkit_private.pri \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_webkitwidgets.pri \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_webkitwidgets_private.pri \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_websockets.pri \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_websockets_private.pri \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_widgets.pri \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_widgets_private.pri \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_x11extras.pri \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_x11extras_private.pri \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_xml.pri \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_xml_private.pri \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_xmlpatterns.pri \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_xmlpatterns_private.pri \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/features/qt_functions.prf \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/features/qt_config.prf \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/linux-g++/qmake.conf \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/features/spec_post.prf \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/features/exclusive_builds.prf \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/features/default_pre.prf \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/features/resolve_config.prf \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/features/default_post.prf \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/features/warn_on.prf \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/features/testcase_targets.prf \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/features/exceptions.prf \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/features/yacc.prf \
		/opt/Qt5.3.2/5.3/gcc_64/mkspecs/features/lex.prf \
		mlpack2.pro
	$(QMAKE) -spec linux-g++ CONFIG+=debug -o Makefile mlpack2.pro
/opt/Qt5.3.2/5.3/gcc_64/mkspecs/features/spec_pre.prf:
/opt/Qt5.3.2/5.3/gcc_64/mkspecs/common/shell-unix.conf:
/opt/Qt5.3.2/5.3/gcc_64/mkspecs/common/unix.conf:
/opt/Qt5.3.2/5.3/gcc_64/mkspecs/common/linux.conf:
/opt/Qt5.3.2/5.3/gcc_64/mkspecs/common/gcc-base.conf:
/opt/Qt5.3.2/5.3/gcc_64/mkspecs/common/gcc-base-unix.conf:
/opt/Qt5.3.2/5.3/gcc_64/mkspecs/common/g++-base.conf:
/opt/Qt5.3.2/5.3/gcc_64/mkspecs/common/g++-unix.conf:
/opt/Qt5.3.2/5.3/gcc_64/mkspecs/qconfig.pri:
/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_bluetooth.pri:
/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_bluetooth_private.pri:
/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_bootstrap_private.pri:
/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_clucene_private.pri:
/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_concurrent.pri:
/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_concurrent_private.pri:
/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_core.pri:
/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_core_private.pri:
/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_dbus.pri:
/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_dbus_private.pri:
/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_declarative.pri:
/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_declarative_private.pri:
/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_designer.pri:
/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_designer_private.pri:
/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_designercomponents_private.pri:
/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_enginio.pri:
/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_enginio_private.pri:
/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_gui.pri:
/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_gui_private.pri:
/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_help.pri:
/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_help_private.pri:
/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_multimedia.pri:
/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_multimedia_private.pri:
/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_multimediawidgets.pri:
/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_multimediawidgets_private.pri:
/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_network.pri:
/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_network_private.pri:
/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_nfc.pri:
/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_nfc_private.pri:
/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_opengl.pri:
/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_opengl_private.pri:
/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_openglextensions.pri:
/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_openglextensions_private.pri:
/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_platformsupport_private.pri:
/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_positioning.pri:
/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_positioning_private.pri:
/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_printsupport.pri:
/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_printsupport_private.pri:
/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_qml.pri:
/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_qml_private.pri:
/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_qmldevtools_private.pri:
/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_qmltest.pri:
/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_qmltest_private.pri:
/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_qtmultimediaquicktools_private.pri:
/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_quick.pri:
/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_quick_private.pri:
/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_quickparticles_private.pri:
/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_quickwidgets.pri:
/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_quickwidgets_private.pri:
/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_script.pri:
/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_script_private.pri:
/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_scripttools.pri:
/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_scripttools_private.pri:
/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_sensors.pri:
/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_sensors_private.pri:
/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_serialport.pri:
/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_serialport_private.pri:
/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_sql.pri:
/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_sql_private.pri:
/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_svg.pri:
/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_svg_private.pri:
/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_testlib.pri:
/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_testlib_private.pri:
/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_uitools.pri:
/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_uitools_private.pri:
/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_webkit.pri:
/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_webkit_private.pri:
/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_webkitwidgets.pri:
/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_webkitwidgets_private.pri:
/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_websockets.pri:
/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_websockets_private.pri:
/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_widgets.pri:
/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_widgets_private.pri:
/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_x11extras.pri:
/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_x11extras_private.pri:
/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_xml.pri:
/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_xml_private.pri:
/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_xmlpatterns.pri:
/opt/Qt5.3.2/5.3/gcc_64/mkspecs/modules/qt_lib_xmlpatterns_private.pri:
/opt/Qt5.3.2/5.3/gcc_64/mkspecs/features/qt_functions.prf:
/opt/Qt5.3.2/5.3/gcc_64/mkspecs/features/qt_config.prf:
/opt/Qt5.3.2/5.3/gcc_64/mkspecs/linux-g++/qmake.conf:
/opt/Qt5.3.2/5.3/gcc_64/mkspecs/features/spec_post.prf:
/opt/Qt5.3.2/5.3/gcc_64/mkspecs/features/exclusive_builds.prf:
/opt/Qt5.3.2/5.3/gcc_64/mkspecs/features/default_pre.prf:
/opt/Qt5.3.2/5.3/gcc_64/mkspecs/features/resolve_config.prf:
/opt/Qt5.3.2/5.3/gcc_64/mkspecs/features/default_post.prf:
/opt/Qt5.3.2/5.3/gcc_64/mkspecs/features/warn_on.prf:
/opt/Qt5.3.2/5.3/gcc_64/mkspecs/features/testcase_targets.prf:
/opt/Qt5.3.2/5.3/gcc_64/mkspecs/features/exceptions.prf:
/opt/Qt5.3.2/5.3/gcc_64/mkspecs/features/yacc.prf:
/opt/Qt5.3.2/5.3/gcc_64/mkspecs/features/lex.prf:
mlpack2.pro:
qmake: FORCE
	@$(QMAKE) -spec linux-g++ CONFIG+=debug -o Makefile mlpack2.pro

qmake_all: FORCE

dist: 
	@test -d .tmp/mlpack21.0.0 || mkdir -p .tmp/mlpack21.0.0
	$(COPY_FILE) --parents $(DIST) .tmp/mlpack21.0.0/ && (cd `dirname .tmp/mlpack21.0.0` && $(TAR) mlpack21.0.0.tar mlpack21.0.0 && $(COMPRESS) mlpack21.0.0.tar) && $(MOVE) `dirname .tmp/mlpack21.0.0`/mlpack21.0.0.tar.gz . && $(DEL_FILE) -r .tmp/mlpack21.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


distclean: clean 
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) Makefile


####### Sub-libraries

check: first

compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: 

####### Compile

main.o: main.cpp file.h \
		data_struct.h \
		itree.h \
		dataprocess.h \
		utility.h \
		iforest.h \
		sort.h \
		printhelp.h \
		nndm.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o main.o main.cpp

file.o: file.cpp file.h \
		data_struct.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o file.o file.cpp

utility.o: utility.cpp utility.h \
		data_struct.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o utility.o utility.cpp

lof.o: lof.cpp lof.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o lof.o lof.cpp

itree.o: itree.cpp itree.h \
		data_struct.h \
		dataprocess.h \
		utility.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o itree.o itree.cpp

dataprocess.o: dataprocess.cpp dataprocess.h \
		utility.h \
		data_struct.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o dataprocess.o dataprocess.cpp

iforest.o: iforest.cpp iforest.h \
		itree.h \
		data_struct.h \
		dataprocess.h \
		utility.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o iforest.o iforest.cpp

sort.o: sort.cpp sort.h \
		data_struct.h \
		utility.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o sort.o sort.cpp

printhelp.o: printhelp.cpp printhelp.h \
		data_struct.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o printhelp.o printhelp.cpp

nndm.o: nndm.cpp nndm.h \
		file.h \
		data_struct.h \
		utility.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o nndm.o nndm.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:

