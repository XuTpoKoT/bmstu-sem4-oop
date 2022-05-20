#include "abstract_load_controller.h"

void Load::AbstractLoadController::set_loader(std::shared_ptr<Load::BaseLoader> loader)
{
    _loader = std::move(loader);
}
