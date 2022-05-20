#include "load_controller_solution.h"
#include "abstract_load_controller.h"
#include "camera_load_controller_creator.h"
#include "configuration_creator.h"
#include "model_load_controller_creator.h"

Load::LoadControllerSolution::LoadControllerSolution()
    : _configuration(ConfigurationCreator().get_configuration())
{
}

std::shared_ptr<Load::AbstractLoadController> Load::LoadControllerSolution::create_controller(AbstractConfiguration::object_t object)
{
    switch (_configuration->get_source()) {
    case AbstractConfiguration::FILE:
    default:
        if (object == AbstractConfiguration::MODEL)
            return Load::ModelLoadControllerCreator().create_controller();
        else if (object == AbstractConfiguration::CAMERA)
            return Load::CameraLoadControllerCreator().create_controller();
    }
}
