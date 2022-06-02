#pragma once

#include "base_manager.h"
#include "base_model_loader.h"

class ModelLoadManager: public BaseManager {
public:
    void setLoader(std::shared_ptr<BaseModelLoader> loader);
    std::shared_ptr<BaseModel> loadModel(std::string sourceName);
private:
    std::shared_ptr<BaseModelLoader> _loader;
};
