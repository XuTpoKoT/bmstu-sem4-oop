#ifndef CAMERALOADCONTROLLERCREATOR_H
#define CAMERALOADCONTROLLERCREATOR_H

#include "camera_load_controller.h"

namespace Load {
class CameraLoadControllerCreator {
public:
    std::shared_ptr<CameraLoadController> create_controller();
    std::shared_ptr<CameraLoadController> create_controller(const std::shared_ptr<BaseCameraLoader>& loader);

private:
    void create_instance();

    std::shared_ptr<CameraLoadController> _controller;
};
} // namespace Load

#endif // CAMERALOADCONTROLLERCREATOR_H
