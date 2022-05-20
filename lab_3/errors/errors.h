#ifndef ERRORS_H
#define ERRORS_H

#include <exception>
#include <string>

class BaseError : public std::exception {
public:
    BaseError() = default;
    explicit BaseError(std::string& message)
        : error_info(message) {};

    const char* what() const noexcept override
    {
        return "ERROR. Wrong viewer.";
    }

    const std::string& get_info() const noexcept
    {
        return error_info;
    }

protected:
    std::string error_info;
};

class CameraError : public BaseError {
public:
    CameraError() = default;
    explicit CameraError(std::string& message)
        : BaseError(message) {};

    const char* what() const noexcept override
    {
        return "ERROR. Camera does not set.";
    }
};

class ModelError : public BaseError {
public:
    ModelError() = default;
    explicit ModelError(std::string& message)
        : BaseError(message) {};

    const char* what() const noexcept override
    {
        return "ERROR. Wrong model.";
    }
};

class LoadError : public BaseError {
public:
    LoadError() = default;
    explicit LoadError(std::string& message)
        : BaseError(message) {};

    const char* what() const noexcept override
    {
        return "ERROR. Load failure.";
    }
};

class FileError : public LoadError {
public:
    FileError() = default;
    explicit FileError(std::string& message)
        : LoadError(message) {};

    const char* what() const noexcept override
    {
        return error_info.c_str();
    }
};

#endif // ERRORS_H
