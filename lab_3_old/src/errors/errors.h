#pragma once

#include "base_error.h"

#include <cstring>
#include <exception>
#include <string>

class MemoryAllocationError : public BaseError {
public:
    MemoryAllocationError(
        const std::string &filename,
        const std::string &classname,
        const int line,
        const char *time,
        const std::string &info = "A memory allocation error"
    ): BaseError(filename, classname, line, time, info) {}
};

class IndexOutOfRangeError : public BaseError {
public:
    IndexOutOfRangeError(
        const std::string &filename,
        const std::string &classname,
        const int line,
        const char *time,
        const std::string &info = "Index out error"
    ): BaseError(filename, classname, line, time, info) {}
};

class ReferenceError : public BaseError {
public:
    ReferenceError(
        const std::string &filename,
        const std::string &classname,
        const int line,
        const char *time,
        const std::string &info = "Reference error"
    ): BaseError(filename, classname, line, time, info) {}
};

class InitListError : public BaseError {
public:
    InitListError(
        const std::string &filename,
        const std::string &classname,
        const int line,
        const char *time,
        const std::string &info = "Init list error"
    ): BaseError(filename, classname, line, time, info) {}
};

class DifferentSizesError : public BaseError {
public:
    DifferentSizesError(
        const std::string &filename,
        const std::string &classname,
        const int line,
        const char *time,
        const std::string &info = "Different sizes error"
    ): BaseError(filename, classname, line, time, info) {}
};

class NotSquareMatrixError : public BaseError {
public:
    NotSquareMatrixError(
        const std::string &filename,
        const std::string &classname,
        const int line,
        const char *time,
        const std::string &info = "Not square matrix error"
    ): BaseError(filename, classname, line, time, info) {}
};

class InputSizeError : public BaseError {
public:
    InputSizeError(
        const std::string &filename,
        const std::string &classname,
        const int line,
        const char *time,
        const std::string &info = "Input size error"
    ): BaseError(filename, classname, line, time, info) {}
};

class InputMatrixError : public BaseError {
public:
    InputMatrixError(
        const std::string &filename,
        const std::string &classname,
        const int line,
        const char *time,
        const std::string &info = "Input matrix error"
    ): BaseError(filename, classname, line, time, info) {}
};

class MemoryError: public BaseError {
public:
    MemoryError(
        const std::string &filename,
        const std::string &classname,
        const int line,
        const char *time,
        const std::string &info = "A memory allocation error"
    ): BaseError(filename, classname, line, time, info) {}
};

class RangeError: public BaseError {
public:
    RangeError(
        const std::string &filename,
        const std::string &classname,
        const int line,
        const char *time,
        const std::string &info = "Out of range error"
    ): BaseError(filename, classname, line, time, info) {}
};

class DefaultError: public BaseError {
public:
    DefaultError(
        const std::string &filename,
        const std::string &classname,
        const int line,
        const char *time,
        const std::string &info = "Default error"
    ): BaseError(filename, classname, line, time, info) {}
};

class DrawerError: public BaseError {
public:
    DrawerError(
        const std::string &filename,
        const std::string &classname,
        const int line,
        const char *time,
        const std::string &info = "Drawer wasn't set"
    ) : BaseError(filename, classname, line, time, info) {}
};

class OpenStreamError: public BaseError {
public:
    OpenStreamError(
        const std::string &filename,
        const std::string &classname,
        const int line,
        const char *time,
        const std::string &info = "Error while opening stream"
    ) : BaseError(filename, classname, line, time, info) {}
};

class ReadStreamError: public BaseError {
public:
    ReadStreamError(
        const std::string &filename,
        const std::string &classname,
        const int line,
        const char *time,
        const std::string &info = "Error while reading stream"
    ) : BaseError(filename, classname, line, time, info) {}
};

class FileFormatError: public BaseError {
public:
    FileFormatError(
        const std::string &filename,
        const std::string &classname,
        const int line,
        const char *time,
        const std::string &info = "Wrong format of file"
    ) : BaseError(filename, classname, line, time, info) {}
};

class ModelOutOfRangeError: public BaseError {
public:
    ModelOutOfRangeError(
        const std::string &filename,
        const std::string &classname,
        const int line,
        const char *time,
        const std::string &info = "Model is out of range"
    ) : BaseError(filename, classname, line, time, info) {}
};

class CameraError: public BaseError {
public:
    CameraError(
        const std::string &filename,
        const std::string &classname,
        const int line,
        const char *time,
        const std::string &info = "Camera wasn't set"
    ) : BaseError(filename, classname, line, time, info) {}
};

class ObjectError: public BaseError {
public:
    ObjectError(
        const std::string &filename,
        const std::string &classname,
        const int line,
        const char *time,
        const std::string &info = "Object wasn't found."
    ) : BaseError(filename, classname, line, time, info) {}
};

class ConfigError: public BaseError {
public:
    ConfigError(
            const std::string &filename,
            const std::string &classname,
            const int line,
            const char *time,
            const std::string &info = "Config wasn't inited."
    ) : BaseError(filename, classname, line, time, info) {}
};
