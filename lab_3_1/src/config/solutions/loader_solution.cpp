#include "loader_solution.h"

LoaderSolution::LoaderSolution(): _configuration(ConfigurationCreator().createConfiguration()) {}

std::shared_ptr<AbstractLoader> LoaderSolution::createLoader(AbstractLoaderCreator *creator) {
    auto id = _configuration->getLoader();
    auto it = _creatorMap.find(id);
    std::shared_ptr<AbstractLoader> loader = (creator->*(it->second))();
    return loader;
}

void LoaderSolution::configure(std::string loaderKey, createSomeLoader callback) {
    _creatorMap.insert(LoaderCreatorMap::value_type(loaderKey, callback));
}

bool LoaderSolution::isConfigured(std::string loaderKey) {
    return _creatorMap.find(loaderKey)->second;
}
