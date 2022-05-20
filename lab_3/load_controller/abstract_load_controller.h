#ifndef ABSTRACTLOADCONTROLLER_H
#define ABSTRACTLOADCONTROLLER_H

#include "base_builder.h"
#include "base_loader.h"
#include <memory>

namespace Load {
class AbstractLoadController {
public:
    AbstractLoadController() = default;
    virtual ~AbstractLoadController() = default;

    virtual std::shared_ptr<Object> load(std::string& fname) = 0;
    virtual void set_loader(std::shared_ptr<BaseLoader> loader);

protected:
    std::shared_ptr<BaseLoader> _loader;
};
} // namespace Load

#endif // ABSTRACTLOADCONTROLLER_H
