#include "load_manager_creator.h"

std::shared_ptr<ModelLoadManager> LoadManagerCreator::createManager(std::shared_ptr<AbstractLoader> loader) {
    if (_manager == nullptr)
        createInstance();
    _manager->setLoader(loader);
    return _manager;
}

void LoadManagerCreator::createInstance() {
    auto manager = std::make_shared<ModelLoadManager>();
    _manager = manager;
}
