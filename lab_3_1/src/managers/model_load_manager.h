#pragma once

#include "base_manager.h"
#include "abstract_loader.h"

class ModelLoadManager: public BaseManager {
public:
    void setLoader(std::shared_ptr<AbstractLoader> loader);
    std::shared_ptr<BaseModel> loadModel(std::string sourceName);
private:
    std::shared_ptr<AbstractLoader> _loader;
};
