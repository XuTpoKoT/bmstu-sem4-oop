#pragma once

#include "configuration_creator.h"
#include "map_configuration.h"

void ConfigurationCreator::createInstance() {
    static std::shared_ptr<AbstractConfiguration> cfg(new MapConfiguration());
    _configuration = cfg;
}

std::shared_ptr<AbstractConfiguration> ConfigurationCreator::createConfiguration() {
    if (_configuration == nullptr) {
        createInstance();
        _configuration->readConfiguration(CONFIG_SOURCE);
    }
    return _configuration;
}
