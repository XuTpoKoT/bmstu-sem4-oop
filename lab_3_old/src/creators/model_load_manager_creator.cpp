#include "model_load_manager_creator.h"

std::shared_ptr<ModelLoadManager> ModelLoadManagerCreator::createManager(std::shared_ptr<TextFileModelReader> reader) {
    if (manager == nullptr)
        createInstance();
    manager->setModelReader(reader);
    return manager;
}

void ModelLoadManagerCreator::createInstance() {
    auto manager = std::make_shared<ModelLoadManager>();
    this->manager = manager;
}
