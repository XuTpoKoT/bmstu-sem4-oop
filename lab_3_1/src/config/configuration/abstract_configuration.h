#pragma once

#include <string>

#define FRAMEWORK "Framework"
#define LOADER "Loader"

#define QT "QT"
#define TXT "TXT"

#define CONFIG_SOURCE "../lab_3_1/assets/config.txt"

class AbstractConfiguration {
public:
    ~AbstractConfiguration() = default;
    virtual void readConfiguration(std::string sourceName) = 0;
    virtual std::string getFramework() = 0;
    virtual std::string getLoader() = 0;
};
