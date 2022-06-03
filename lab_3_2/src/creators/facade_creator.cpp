#include "facade_creator.h"

std::shared_ptr<Facade> FacadeCreator::createFacade() {
    if (_facade == nullptr)
        createInstance();
    return _facade;
}

void FacadeCreator::createInstance() {
    std::shared_ptr<Facade> facade(new Facade());
    _facade = facade;
}
