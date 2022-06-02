#pragma once

#include "abstract_configuration.h"
#include <iostream>
#include <fstream>
#include <map>
#include "errors.h"

class MapConfiguration: public AbstractConfiguration {
public:
    ~MapConfiguration() = default;
    void readConfiguration(std::string sourceName) override;
    std::string getFramework() override;
    std::string getLoader() override;
private:
    std::map<std::string, std::string> _configurationImpl;
};
