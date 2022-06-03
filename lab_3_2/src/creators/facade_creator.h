#pragma once

#include "base_creator.h"
#include "facade.h"

class FacadeCreator: public BaseCreator {
public:
    FacadeCreator() = default;
    ~FacadeCreator() = default;
    std::shared_ptr<Facade> createFacade();
private:
    void createInstance() override;
    std::shared_ptr<Facade> _facade;
};
