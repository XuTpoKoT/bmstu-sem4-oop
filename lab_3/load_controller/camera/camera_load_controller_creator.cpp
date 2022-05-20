#include "camera_load_controller_creator.h"

#include "configuration_creator.h"
#include "file_camera_loader.h"

std::shared_ptr<Load::CameraLoadController> Load::CameraLoadControllerCreator::create_controller()
{
    if (!_controller)
        create_instance();

    return _controller;
}

std::shared_ptr<Load::CameraLoadController> Load::CameraLoadControllerCreator::create_controller(const std::shared_ptr<BaseCameraLoader>& loader)
{
    if (!_controller)
        create_instance();

    _controller->set_loader(loader);

    return _controller;
}

void Load::CameraLoadControllerCreator::create_instance()
{
    static std::shared_ptr<CameraLoadController> controller;

    if (!controller) {
        std::shared_ptr<BaseCameraLoader> loader;

        loader = std::shared_ptr<BaseCameraLoader>(new FileCameraLoader);

        controller = std::make_shared<CameraLoadController>(loader);
    }

    _controller = controller;
}
