#include "model_load_controller.h"
#include "errors.h"

std::shared_ptr<Object> Load::ModelLoadController::load(std::string& fname)
{
    try {
        _loader->open(fname);
    } catch (LoadError& error) {
        throw LoadError((std::string&)"Can't open file.");
    }

    std::shared_ptr<Model> model;
    try {
        model = _loader->load(_builder);
    } catch (std::exception& error) {
        throw LoadError((std::string&)"Can't read model.");
    }

    _loader->close();

    return model;
}
