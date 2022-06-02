#pragma once

#include "base_manager.h"

class BaseCreator {
public:
    ~BaseCreator() = default;
protected:
    virtual void createInstance() = 0;
};
