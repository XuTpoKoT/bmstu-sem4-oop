#ifndef BASE_LOADER_H
#define BASE_LOADER_H

#include <string>

namespace Load {
class BaseLoader {
public:
    BaseLoader() = default;
    virtual ~BaseLoader() = default;

    virtual void open(std::string& fname) = 0;
    virtual void close() = 0;
};
} // namespace Load
#endif // BASE_LOADER_H
