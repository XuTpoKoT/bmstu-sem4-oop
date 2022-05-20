#ifndef ABSTRACT_DRAWER_FACTORY_H
#define ABSTRACT_DRAWER_FACTORY_H

#include "abstract_configuration.h"
#include "abstract_drawer.h"
#include <memory>

class AbstractDrawerFactory {
public:
    virtual std::unique_ptr<AbstractDrawer> create_drawer() = 0;
};

#endif // ABSTRACT_DRAWER_FACTORY_H
