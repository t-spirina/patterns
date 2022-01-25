TEMPLATE = app
CONFIG += c++17
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
QMAKE_CXXFLAGS += -std=c++17 -pthread

LIBS += -pthread

SOURCES += *.cpp

HEADERS += *.h

DISTFILES +=
