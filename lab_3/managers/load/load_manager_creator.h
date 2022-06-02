#ifndef LOADMANAGERCREATOR_H
#define LOADMANAGERCREATOR_H

#include "load_manager.h"

namespace Load {
class LoadManagerCreator {
public:
    std::shared_ptr<LoadManager> create_manager();
    std::shared_ptr<LoadManager> create_manager(const std::shared_ptr<AbstractLoadController>& loader);

private:
    void create_instance();

    std::shared_ptr<LoadManager> _manager;
};
} // namespace Load

#endif // LOADMANAGERCREATOR_H