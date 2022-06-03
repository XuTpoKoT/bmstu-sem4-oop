#include "transform_manager_creator.h"

std::shared_ptr<TransformManager> TransformManagerCreator::createManager() {
    return _manager;
}

void TransformManagerCreator::createInstance() {
    _manager = std::make_shared<TransformManager>();
}
