#pragma once

#include "configuration_creator.h"
#include "project_configuration.h"

void ConfigurationCreator::createInstance() {
    static std::shared_ptr<AbstractConfiguration> cfg(new ProjectConfiguration());
    _configuration = cfg;
}

std::shared_ptr<AbstractConfiguration> ConfigurationCreator::createConfiguration() {
    if (_configuration == nullptr) {
        createInstance();
        _configuration->readConfiguration(CONFIG_SOURCE);
    }
    return _configuration;
}
