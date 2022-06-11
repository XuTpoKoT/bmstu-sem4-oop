#pragma once

#include <exception>
#include <string>

class BaseError : public std::exception
{
public:
    explicit BaseError(
        const std::string &filename,
        const std::string &classname,
        const int line,
        const char *time,
        const std::string &info)
    {
        _msg = "In: " + filename +
               "\n inside: " + classname +
               "\nat line: " + std::to_string(line) +
               "\nat: " + time +
               "\noccured: " + info;
    }
    const char *what() const noexcept override
    {
        return _msg.c_str();
    }

private:
    std::string _msg;
};
