#pragma once

#include "base_creator.h"
#include "abstract_configuration.h"

class ConfigurationCreator: public BaseCreator {
public:
    ~ConfigurationCreator() = default;
    std::shared_ptr<AbstractConfiguration> createConfiguration();
private:
    void createInstance() override;
    std::shared_ptr<AbstractConfiguration> _configuration;
};
