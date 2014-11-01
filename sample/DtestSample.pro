TEMPLATE    =   app
CONFIG      -=  qt
CONFIG      *=  console

LIBS            *=  -L$$PWD/../bin
INCLUDEPATH     *=  $$PWD/etc $$PWD/../include
DESTDIR         =   $$PWD/bin

win32-g++|unix {
    DEFINES             *=  _DTEST_VARIADIC_TEMPLATE
}


CONFIG(debug, debug|release) {
    TARGET              =   DtestSampled
    LIBS                *=  -ldtestd
} else {
    TARGET              =   DtestSample
    LIBS                *=  -ldtest
}

SOURCES += \
    src/main.cpp

include($$PWD/../common.pri)

