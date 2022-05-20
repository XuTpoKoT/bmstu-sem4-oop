#ifndef LOADMANAGER_H
#define LOADMANAGER_H

#include "abstract_load_controller.h"
#include "object.h"
#include <base_manager.h>

namespace Load {
class LoadManager : public BaseManager {
public:
    LoadManager();
    LoadManager(const LoadManager&) = delete;
    LoadManager& operator=(const LoadManager&) = delete;
    ~LoadManager() = default;

    virtual std::shared_ptr<Object> load(std::string& fname);
    virtual void set_loader(std::shared_ptr<AbstractLoadController> loader);

private:
    std::shared_ptr<AbstractLoadController> _loader;
};
} // namespace Load

#endif // LOADMANAGER_H
