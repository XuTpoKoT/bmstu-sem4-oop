TEMPLATE = app
CONFIG += console c++20
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        BaseVector.cpp \
        BaseVectorIterator.cpp \
        VectorException.cpp \
        main.cpp

HEADERS += \
    BaseVector.h \
    BaseVectorIterator.h \
    ConstVectorIterator.h \
    RegularVectorIterator.h \
    Vector.h \
    Vector.hpp \
    VectorException.h
