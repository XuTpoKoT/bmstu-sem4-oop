#pragma once

#include "draw_manager.h"
#include "base_creator.h"

class DrawManagerCreator: public BaseCreator {
public:
    DrawManagerCreator(): _manager(nullptr) {};
    ~DrawManagerCreator() = default;
    std::shared_ptr<DrawManager> createManager();
private:
    void createInstance() override;
    std::shared_ptr<DrawManager> _manager;
};
