TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    file.cpp \
    utility.cpp \
    lof.cpp \
    itree.cpp \
    dataprocess.cpp \
    iforest.cpp \
    sort.cpp \
    printhelp.cpp \
    nndm.cpp
INCLUDEPATH += /usr/include/libxml2
#LIBS += -lmlpack
#LIBS += -larmadillo
#include(deployment.pri)
#qtcAddDeployment()


win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../download/lib/release/ -lmlpack
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../download/lib/debug/ -lmlpack
else:unix: LIBS += -L$$PWD/../download/lib/ -lmlpack

INCLUDEPATH += $$PWD/../download/include
DEPENDPATH += $$PWD/../download/include

HEADERS += \
    file.h \
    data_struct.h \
    utility.h \
    lof.h \
    itree.h \
    dataprocess.h \
    iforest.h \
    sort.h \
    printhelp.h \
    nndm.h
