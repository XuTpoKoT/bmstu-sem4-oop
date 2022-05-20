#ifndef LOADCONTROLLERSOLUTION_H
#define LOADCONTROLLERSOLUTION_H

#include "abstract_configuration.h"
#include "abstract_load_controller.h"
#include "base_loader.h"
#include <memory>

namespace Load {
class LoadControllerSolution {
public:
    LoadControllerSolution();
    std::shared_ptr<Load::AbstractLoadController> create_controller(AbstractConfiguration::object_t object);

private:
    std::shared_ptr<AbstractConfiguration> _configuration;
};
} // namespace Load

#endif // LOADCONTROLLERSOLUTION_H
