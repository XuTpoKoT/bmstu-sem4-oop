#include "map_configuration.h"

void MapConfiguration::readConfiguration(std::string sourceName) {
    time_t t_time = time(NULL);
    std::ifstream sourceStream;

    sourceStream.open(sourceName);
    if (!sourceStream)
        throw OpenStreamError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));

    std::string uiFramework;
    std::string loader;

    std::getline(sourceStream, uiFramework);
    std::getline(sourceStream, loader);

    _configurationImpl[FRAMEWORK] = uiFramework;
    _configurationImpl[LOADER] = loader;
    sourceStream.close();
}

std::string MapConfiguration::getFramework() {
    return _configurationImpl.at(FRAMEWORK);
}

std::string MapConfiguration::getLoader() {
    return _configurationImpl.at(LOADER);
}
