#pragma once

#include "draw_manager.h"
#include "base_creator.h"
#include "project_config.h"

class DrawManagerCreator: public BaseCreator {
public:
    DrawManagerCreator(): manager(nullptr) {};
    ~DrawManagerCreator() = default;
    std::shared_ptr<DrawManager> createManager();
private:
    void createInstance() override;
    std::shared_ptr<DrawManager> manager;
};
