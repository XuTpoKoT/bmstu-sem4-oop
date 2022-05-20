#ifndef SCENEMANAGERCREATOR_H
#define SCENEMANAGERCREATOR_H

#include "scene_manager.h"

class SceneManagerCreator {
public:
    std::shared_ptr<SceneManager> create_manager();

private:
    void create_instance();

    std::shared_ptr<SceneManager> _manager;
};

#endif // SCENEMANAGERCREATOR_H
