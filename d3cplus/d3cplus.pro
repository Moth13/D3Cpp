#-------------------------------------------------
#
# Project created by QtCreator 2012-11-07T13:47:46
#
#-------------------------------------------------
VERSION     = 0.0.1
DEFINES     += d3cplus_VERSION=\'\"$$VERSION\"\'

OUT_DIR     = release

contains( CONFIG, debug )
{
    DEFINES += _DEBUG
    OUT_DIR = debug
}

#define output dir
INSTALL_DIR     = ../out/

QT              += core
QT              += network
QT              -= gui

TARGET          = d3cplus
TEMPLATE        = lib

OBJECTS_DIR     = ./build/objectfile/$$OUT_DIR
MOC_DIR         = ./build/moc/$$OUT_DIR
DESTDIR         = ../out/lib/

INCLUDEPATH     += include

# include qjson dependences
INCLUDEPATH     += ./resources/include
DEPENDPATH      += ./resources/lib
LIBS            += -L./resources/lib -lqjson

HEADERS += \
    include/d3cplus_data.h \
    include/d3cplus_engine.h

SOURCES += \
    src/d3cplus_data.cpp \
    src/d3cplus_engine.cpp


target_lib.files= ./resources/lib/*.so*
target_lib.path = $$DESTDIR
target_inc.files= ./resources/include/*
target_inc.files+= ./include/*
target_inc.path = $$INSTALL_DIR/include/
INSTALLS        += target_lib
INSTALLS        += target_inc
