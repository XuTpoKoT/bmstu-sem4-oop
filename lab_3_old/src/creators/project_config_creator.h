#pragma once

#include "base_creator.h"
#include "project_config.h"

class ProjectConfigCreator: public BaseCreator {
public:
    ~ProjectConfigCreator() = default;
    std::shared_ptr<ProjectConfig> createConfiguration();
private:
    void createInstance() override;
    std::shared_ptr<ProjectConfig> config;
};
