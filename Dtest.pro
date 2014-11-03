TEMPLATE                =   app
CONFIG                  -=  qt
CONFIG                  *=  console c++11

INCLUDEPATH             *=  $$PWD/etc $$PWD/include

DESTDIR                 =   $$PWD/bin
OBJECTS_DIR             =   .obj
MOC_DIR                 =   .moc
RCC_DIR                 =   .rcc
UI_DIR                  =   .ui

CONFIG(debug, debug|release) {
    TARGET                  =   DtestSampled
} else {
    TARGET                  =   DtestSample
}

QMAKE_CFLAGS_WARN_ON
QMAKE_CXXFLAGS_WARN_ON

win32-msvc2012 {
    QMAKE_CFLAGS_RELEASE    -=  -MD -O1
    QMAKE_CFLAGS_RELEASE    *=  -MT -O2
    QMAKE_CXXFLAGS_RELEASE  -=  -MD -O1
    QMAKE_CXXFLAGS_RELEASE  *=  -MT -O2
    QMAKE_CFLAGS_DEBUG      -=  -MDd
    QMAKE_CFLAGS_DEBUG      *=  -MTd
    QMAKE_CXXFLAGS_DEBUG    -=  -MDd
    QMAKE_CXXFLAGS_DEBUG    *=  -MTd
}
win32-g++ {
    QMAKE_CFLAGS_RELEASE    -=  -O1 -O2
    QMAKE_CFLAGS_RELEASE    *=  -O3
    QMAKE_CXXFLAGS_RELEASE  -=  -O1 -O2
    QMAKE_CXXFLAGS_RELEASE  *=  -O3
    QMAKE_LFLAGS            *=  -static -static-libgcc -static-libstdc++
}
unix {
    QMAKE_CFLAGS_RELEASE    -=  -O1 -O2
    QMAKE_CFLAGS_RELEASE    *=  -O3
    QMAKE_CXXFLAGS_RELEASE  -=  -O1 -O2
    QMAKE_CXXFLAGS_RELEASE  *=  -O3
}
win32-g++|unix {
    DEFINES                 *=  _DTEST_VARIADIC_TEMPLATE
}

HEADERS += \
    include/dtest/dtest.h \
    include/dtest/dtest-manager.h \
    include/dtest/dtest-manager-base.h \
    include/dtest/dtest-manager-tuple-generated.h \
    include/dtest/dtest-manager-variadic-template.h \
    include/dtest/dtest-matcher.h \
    include/dtest/dtest-matcher-single.h \
    include/dtest/dtest-matcher-multi-tuple-generated.h \
    include/dtest/dtest-matcher-multi-variadic-template.h \
    include/dtest/internal/dtest-utils.h \
    include/dtest/internal/dtest-comparators.h \
    include/dtest/internal/dtest-combiners.h

SOURCES += \
    src/dtest-sample.cpp

