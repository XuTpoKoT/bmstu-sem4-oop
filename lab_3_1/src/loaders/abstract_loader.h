#pragma once

#include "base_loader.h"
#include "base_model.h"

class AbstractLoader
{
public:
    virtual ~AbstractLoader() = default;
    virtual std::shared_ptr<BaseModel> loadModel(std::string sourceName) = 0;
protected:
    std::shared_ptr<BaseLoader> _loader;
};
