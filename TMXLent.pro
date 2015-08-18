TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += c++11

SOURCES += main.cpp \
    tmxlent.cpp

INCLUDEPATH += $$PWD/include
SOURCES += $$PWD/src/*.cpp

HEADERS += \
    tmxlent.hpp
