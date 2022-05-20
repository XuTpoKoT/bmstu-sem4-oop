#ifndef CAMERALOADCONTROLLER_H
#define CAMERALOADCONTROLLER_H

#include "base_camera_loader.h"
#include "scene_builder.h"
#include <abstract_load_controller.h>

namespace Load {
class CameraLoadController : public AbstractLoadController {
public:
    explicit CameraLoadController(std::shared_ptr<BaseCameraLoader> loader)
        : _builder(new CameraBuilder)
        , _loader(std::move(loader)) {};
    ~CameraLoadController() = default;

    std::shared_ptr<Object> load(std::string& fname) override;

private:
    std::shared_ptr<CameraBuilder> _builder;
    std::shared_ptr<BaseCameraLoader> _loader;
};
} // namespace Load

#endif // CAMERALOADCONTROLLER_H
