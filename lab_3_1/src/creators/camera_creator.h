#pragma once

#include "base_creator.h"
#include "camera.h"

class CameraCreator: public BaseCreator {
public:
    ~CameraCreator() = default;
    std::shared_ptr<Camera> createCamera();
private:
    void createInstance() override;
    std::shared_ptr<Camera> _camera;
};
