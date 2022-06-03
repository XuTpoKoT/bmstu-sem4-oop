#pragma once

#include "base_creator.h"
#include "camera_add_manager.h"

class CameraManagerCreator: public BaseCreator {
public:
    std::shared_ptr<CameraAddManager> createManager();
private:
    void createInstance() override;
    std::shared_ptr<CameraAddManager> manager;
};
