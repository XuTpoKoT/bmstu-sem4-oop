#include "loader_solution.h"

LoaderSolution::LoaderSolution(): _configuration(ConfigurationCreator().createConfiguration()) {
    loaderSource = _configuration->getLoader();
}

std::shared_ptr<BaseModelLoader> LoaderSolution::createLoader(BaseModelLoaderCreator *creator) {
    auto id = _configuration->getLoader();
    auto it = _creatorMap.find(id);
    std::shared_ptr<BaseModelLoader> loader = (creator->*(it->second))();
    return loader;
}

void LoaderSolution::configure(std::string loaderKey, createSomeLoader callback) {
    _creatorMap.insert(LoaderCreatorMap::value_type(loaderKey, callback));
}

bool LoaderSolution::isConfigured(std::string loaderKey) {
    return _creatorMap.find(loaderKey)->second;
}