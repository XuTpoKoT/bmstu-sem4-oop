#include "model_load_manager.h"

void ModelLoadManager::setLoader(std::shared_ptr<BaseModelLoader> loader) {
    _loader = loader;
}

std::shared_ptr<BaseModel> ModelLoadManager::loadModel(std::string sourceName) {
    return _loader->loadModel(sourceName);
}
