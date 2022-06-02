#pragma once

#include <memory>
#include "abstract_loader.h"
#include "base_creator.h"

class AbstractLoaderCreator: public BaseCreator {
public:
    virtual std::shared_ptr<AbstractLoader> createLoader() = 0;
protected:
    std::shared_ptr<AbstractLoader> _loader;
};
