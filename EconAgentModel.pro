TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    agent.cpp \
    market.cpp \
    system.cpp

HEADERS += \
    agent.h \
    market.h \
    system.h \
    RandomNumberGenerator/random.h
