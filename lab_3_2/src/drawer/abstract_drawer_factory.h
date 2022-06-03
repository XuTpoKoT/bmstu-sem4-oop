#pragma once

#include <memory>
#include "abstract_drawer.h"

class AbstractDrawerFactory {
public:
    virtual std::shared_ptr<AbstractDrawer> createDrawer() const = 0;
};
