#include "camera_manager_creator.h"

std::shared_ptr<CameraAddManager> CameraManagerCreator::createManager() {
    if (_manager == nullptr)
        createInstance();
    return _manager;
}

void CameraManagerCreator::createInstance() {
    auto manager = std::make_shared<CameraAddManager>();
    _manager = manager;
}
