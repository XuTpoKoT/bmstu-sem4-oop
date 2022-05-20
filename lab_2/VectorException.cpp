#include "VectorException.h"

#include <cstring>

VectorException::VectorException(const std::string& time, const std::string& filename,
    const std::string& classname, const std::string& method)
{
    this->message = "\ntime: " + time + "file: " + filename + "\nclass: " + classname + "\nmethod: " + method;
}

const char* VectorException::what() const noexcept
{
    return message.c_str();
}

MemoryAllocationVectorException::MemoryAllocationVectorException(const std::string& time, const std::string& filename,
    const std::string& classname, const std::string& method)
    : VectorException(time, filename, classname, method) {};

const char* MemoryAllocationVectorException::what() const noexcept
{
    std::string msg = "\nMemory allocation Exception" + message;
    char* cmsg = new char[msg.size() + 1];
    strcpy(cmsg, msg.c_str());

    return cmsg;
}

SizeVectorException::SizeVectorException(const std::string& time, const std::string& filename,
    const std::string& classname, const std::string& method)
    : VectorException(time, filename, classname, method) {};

const char* SizeVectorException::what() const noexcept
{
    std::string msg = "\nVector size mismatch" + message;
    char* cmsg = new char[msg.size() + 1];
    strcpy(cmsg, msg.c_str());

    return cmsg;
}

IndexVectorException::IndexVectorException(const std::string& time, const std::string& filename,
    const std::string& classname, const std::string& method)
    : VectorException(time, filename, classname, method) {};

const char* IndexVectorException::what() const noexcept
{
    std::string msg = "\nIndex out of range" + message;
    char* cmsg = new char[msg.size() + 1];
    strcpy(cmsg, msg.c_str());

    return cmsg;
}

DivisionByZeroVectorException::DivisionByZeroVectorException(const std::string& time, const std::string& filename,
    const std::string& classname, const std::string& method)
    : VectorException(time, filename, classname, method) {};

const char* DivisionByZeroVectorException::what() const noexcept
{
    std::string msg = "\nDivision by zero" + message;
    char* cmsg = new char[msg.size() + 1];
    strcpy(cmsg, msg.c_str());

    return cmsg;
}

ReferenceVectorException::ReferenceVectorException(const std::string& time, const std::string& filename,
    const std::string& classname, const std::string& method)
    : VectorException(time, filename, classname, method) {};

const char* ReferenceVectorException::what() const noexcept
{
    std::string msg = "\nReference Exception" + message;
    char* cmsg = new char[msg.size() + 1];
    strcpy(cmsg, msg.c_str());

    return cmsg;
}
