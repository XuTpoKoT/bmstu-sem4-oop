#include "camera_creator.h"

void CameraCreator::createInstance() {
    camera = std::make_shared<Camera>();
}

std::shared_ptr<Camera> CameraCreator::createCamera() {
    createInstance();
    return camera;
}
