#pragma once

#include "base_creator.h"
#include "facade.h"

class FacadeCreator {
public:
    FacadeCreator() = default;
    ~FacadeCreator() = default;
    std::shared_ptr<Facade> createFacade(std::shared_ptr<ProjectConfig> config);
private:
    void createInstance(std::shared_ptr<ProjectConfig> config);
    std::shared_ptr<Facade> facade;
};
