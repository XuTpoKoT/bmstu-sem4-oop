#include "drawer_solution.h"

DrawerSolution::DrawerSolution(): _configuration(ConfigurationCreator().createConfiguration()) {}

std::shared_ptr<AbstractDrawerFactory> DrawerSolution::createFactory(MainWindow *mainWindow) {
    auto id = _configuration->getFramework();
    auto it = _factoryMap.find(id);
    std::shared_ptr<AbstractDrawerFactory> factory = (mainWindow->*(it->second))();
    return factory;
}

void DrawerSolution::configure(std::string framework, createDrawerFactory callback) {
    _factoryMap.insert(DrawerFactoryMap::value_type(framework, callback));
}

bool DrawerSolution::isConfigured(std::string framework) {
    return _factoryMap.find(framework)->second;
}
