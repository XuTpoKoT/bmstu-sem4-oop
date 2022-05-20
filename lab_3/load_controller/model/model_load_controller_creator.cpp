#include "model_load_controller_creator.h"
#include "file_model_loader.h"

std::shared_ptr<Load::ModelLoadController> Load::ModelLoadControllerCreator::create_controller()
{
    if (!_controller)
        create_instance();

    return _controller;
}

std::shared_ptr<Load::ModelLoadController> Load::ModelLoadControllerCreator::create_controller(const std::shared_ptr<BaseModelLoader>& loader)
{
    if (!_controller)
        create_instance();

    _controller->set_loader(loader);

    return _controller;
}

void Load::ModelLoadControllerCreator::create_instance()
{
    static std::shared_ptr<ModelLoadController> controller;

    if (!controller) {
        std::shared_ptr<BaseModelLoader> loader;

        loader = std::shared_ptr<BaseModelLoader>(new FileModelLoader);

        controller = std::make_shared<ModelLoadController>(loader);
    }

    _controller = controller;
}
