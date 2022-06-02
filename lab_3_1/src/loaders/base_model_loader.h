#pragma once

#include "abstract_source_loader.h"
#include "base_model.h"

class BaseModelLoader
{
public:
    virtual ~BaseModelLoader() = default;
    virtual std::shared_ptr<BaseModel> loadModel(std::string sourceName) = 0;
protected:
    std::shared_ptr<AbstractSourceLoader> _loader;
};
