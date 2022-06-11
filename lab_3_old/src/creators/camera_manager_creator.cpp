#include "camera_manager_creator.h"

std::shared_ptr<CameraAddManager> CameraManagerCreator::createManager() {
    if (manager == nullptr)
        createInstance();
    return manager;
}

void CameraManagerCreator::createInstance() {
    auto manager = std::make_shared<CameraAddManager>();
    manager = manager;
}
