#pragma once

#include <iostream>
#include <fstream>
#include "errors.h"

#define CONFIG_SOURCE "../lab_3_2/assets/config.txt"

enum class FrameworkType {
    QT
};

enum class SourceStreamType {
    TXT
};

class ProjectConfig {
public:
    ~ProjectConfig() = default;
    void readConfiguration(std::string sourceName);
    FrameworkType getFrameworkType();
    SourceStreamType getSourceStreamType();
private:
    void readFrameworkType(std::ifstream &stream);
    void readSourceStreamType(std::ifstream &stream);
    FrameworkType frameworkType;
    SourceStreamType sourceStreamType;
};
