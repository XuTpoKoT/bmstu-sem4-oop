#pragma once

#include "scene_manager.h"
#include "base_creator.h"

class SceneManagerCreator: public BaseCreator {
public:
    SceneManagerCreator(): _manager(nullptr) {};
    ~SceneManagerCreator() = default;
    std::shared_ptr<SceneManager> createManager();
private:
    void createInstance() override;
    std::shared_ptr<SceneManager> _manager;
};
