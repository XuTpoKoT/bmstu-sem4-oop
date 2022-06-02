#include "model_loader_creator.h"

void ModelLoaderCreator::createInstance() {
    std::shared_ptr<AbstractSourceLoader> loader(new TextFileLoader());
    std::shared_ptr<BaseModelDirector> director(new CarcassModelDirector());
    _loader = std::make_shared<ModelLoader>(loader, director);
}

std::shared_ptr<BaseModelLoader> ModelLoaderCreator::createLoader() {
    if (_loader == nullptr)
        createInstance();
    return _loader;
};
