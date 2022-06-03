#pragma once

#include <memory>
#include "base_model_loader.h"
#include "base_creator.h"

class BaseModelLoaderCreator: public BaseCreator {
public:
    virtual std::shared_ptr<BaseModelLoader> createLoader() = 0;
protected:
    std::shared_ptr<BaseModelLoader> _loader;
};
