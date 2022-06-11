#include "facade_creator.h"

std::shared_ptr<Facade> FacadeCreator::createFacade(std::shared_ptr<ProjectConfig> config) {
    if (facade == nullptr)
        createInstance(config);
    return facade;
}

void FacadeCreator::createInstance(std::shared_ptr<ProjectConfig> config) {
    std::shared_ptr<Facade> facade(new Facade(config));
    this->facade = facade;
}
