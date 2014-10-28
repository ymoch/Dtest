TEMPLATE    =   app
CONFIG      -=  qt
CONFIG      *=  console

LIBS            *=  -L$$PWD/../bin
INCLUDEPATH     *=  $$PWD/etc $$PWD/../include
DESTDIR         =   $$PWD/bin

DEFINES         *=  _VARIADIC_MAX=10

CONFIG(debug, debug|release) {
    TARGET                  =   DtestSampled
    LIBS                    *=  -ldtestd
} else {
    TARGET                  =   DtestSample
    LIBS                    *=  -ldtest
}

SOURCES += \
    src/main.cpp

include($$PWD/../common.pri)

