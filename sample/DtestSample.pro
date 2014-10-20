TEMPLATE    =   app
CONFIG      -=  qt
CONFIG      *=  console

LIBS            *=  -L$$PWD/../bin
INCLUDEPATH     *=  $$PWD/etc $$PWD/../include
DESTDIR         =   $$PWD/bin

DEFINES         *=  _VARIADIC_MAX=10

CONFIG(debug, debug|release) {
    TARGET                  =   DtestSampled
} else {
    TARGET                  =   DtestSample
}

win32-msvc2012 {
    CONFIG(debug, debug|release) {
        LIBS                *=  -ldtestd
    } else {
        LIBS                *=  -ldtest
    }
}
win32-g++|unix {
    LIBS                    *=  -ldtest
}

SOURCES += \
    src/main.cpp

include($$PWD/../common.pri)

