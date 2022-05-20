#include "load_manager.h"
#include "abstract_load_controller.h"
#include "camera_load_controller_creator.h"

Load::LoadManager::LoadManager()
{
}

void Load::LoadManager::set_loader(std::shared_ptr<AbstractLoadController> loader)
{
    _loader = std::move(loader);
}

std::shared_ptr<Object> Load::LoadManager::load(std::string& fname)
{
    return _loader->load(fname);
}
