#ifndef VECTOR_EXCEPTION_H
#define VECTOR_EXCEPTION_H

#include <exception>
#include <string>
#include <chrono>

class VectorException : public std::exception {
public:
    VectorException(const std::string& time, const std::string& filename,
        const std::string& classname, const std::string& method);

    virtual const char* what() const noexcept override;

protected:
    std::string message;
};

class MemoryAllocationVectorException : public VectorException {
public:
    MemoryAllocationVectorException(const std::string& time, const std::string& filename,
        const std::string& classname, const std::string& method);

    virtual const char* what() const noexcept override;
};

class SizeVectorException : public VectorException {
public:
    SizeVectorException(const std::string& time, const std::string& filename,
        const std::string& classname, const std::string& method);

    virtual const char* what() const noexcept override;
};

class IndexVectorException : public VectorException {
public:
    IndexVectorException(const std::string& time, const std::string& filename,
        const std::string& classname, const std::string& method);

    virtual const char* what() const noexcept override;
};

class DivisionByZeroVectorException : public VectorException {
public:
    DivisionByZeroVectorException(const std::string& time, const std::string& filename,
        const std::string& classname, const std::string& method);

    virtual const char* what() const noexcept override;
};

class ReferenceVectorException : public VectorException {
public:
    ReferenceVectorException(const std::string& time, const std::string& filename,
        const std::string& classname, const std::string& method);

    virtual const char* what() const noexcept override;
};

#endif
