OBJECTS_DIR     =   .obj
MOC_DIR         =   .moc
RCC_DIR         =   .rcc
UI_DIR          =   .ui

CONFIG          *=  c++11

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
