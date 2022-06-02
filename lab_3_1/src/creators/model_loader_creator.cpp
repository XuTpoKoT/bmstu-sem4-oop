#include "model_loader_creator.h"

void ModelLoaderCreator::createInstance() {
    std::shared_ptr<BaseLoader> loader(new TextFileLoader());
    std::shared_ptr<BaseModelDirector> director(new ModelDirector());
    _loader = std::make_shared<ModelLoader>(loader, director);
}

std::shared_ptr<AbstractLoader> ModelLoaderCreator::createLoader() {
    if (_loader == nullptr)
        createInstance();
    return _loader;
};
