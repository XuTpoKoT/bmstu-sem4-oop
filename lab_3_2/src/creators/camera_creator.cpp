#include "camera_creator.h"

void CameraCreator::createInstance() {
    _camera = std::make_shared<Camera>();
}

std::shared_ptr<Camera> CameraCreator::createCamera() {
    createInstance();
    return _camera;
}
