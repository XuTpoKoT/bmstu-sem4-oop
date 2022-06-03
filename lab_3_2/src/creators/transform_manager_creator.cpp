#include "transform_manager_creator.h"

std::shared_ptr<TransformManager> TransformManagerCreator::createManager() {
    return manager;
}

void TransformManagerCreator::createInstance() {
    manager = std::make_shared<TransformManager>();
}
