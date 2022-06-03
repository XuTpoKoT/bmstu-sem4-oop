#include "camera_add_manager.h"

std::shared_ptr<Camera> CameraAddManager::createCamera() {
    return CameraCreator().createCamera();
}
