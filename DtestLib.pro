TEMPLATE        =   lib
CONFIG          -=  qt dll
CONFIG          *=  staticlib

LIBS            *=  -L$$PWD/lib
INCLUDEPATH     *=  $$PWD/include
DESTDIR         =   $$PWD/bin

CONFIG(debug, debug|release) {
    TARGET          =   dtestd
} else {
    TARGET          =   dtest
}

HEADERS += \
    include/dtest/dtest.h \
    include/dtest/dtest-manager.h \
    include/dtest/internal/dtest-utils.h \
    include/dtest/dtest-matcher.h \
    include/dtest/internal/dtest-comparators.h \
    include/dtest/internal/dtest-combiners.h

SOURCES += \
    src/dtest-manager.cpp

include($$PWD/common.pri)

