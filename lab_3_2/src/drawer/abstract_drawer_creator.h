#pragma once

#include <memory>
#include "abstract_drawer.h"

class AbstractDrawerCreator {
public:
    virtual std::shared_ptr<AbstractDrawer> createDrawer() const = 0;
};
