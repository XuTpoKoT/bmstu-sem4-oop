#pragma once

#include "base_manager.h"
#include "camera_creator.h"

class CameraAddManager: public BaseManager {
public:
    std::shared_ptr<Camera> createCamera();
};
