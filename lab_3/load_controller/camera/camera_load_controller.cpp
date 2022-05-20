#include "camera_load_controller.h"
#include "errors.h"

std::shared_ptr<Object> Load::CameraLoadController::load(std::string& fname)
{
    try {
        _loader->open(fname);
    } catch (LoadError& error) {
        throw LoadError((std::string&)"Can't open file.");
    }

    std::shared_ptr<Object> camera;
    try {
        camera = _loader->load(_builder);
    } catch (std::exception& error) {
        throw LoadError((std::string&)"Can't read model.");
    }

    _loader->close();

    return camera;
}
