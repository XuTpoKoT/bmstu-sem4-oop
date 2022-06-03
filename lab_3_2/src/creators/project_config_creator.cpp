#pragma once

#include "project_config_creator.h"
#include "project_config.h"

void ProjectConfigCreator::createInstance() {
    static std::shared_ptr<ProjectConfig> cfg(new ProjectConfig());
    config = cfg;
}

std::shared_ptr<ProjectConfig> ProjectConfigCreator::createConfiguration() {
    if (config == nullptr) {
        createInstance();
        config->readConfiguration(CONFIG_SOURCE);
    }
    return config;
}
