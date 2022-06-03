#pragma once

#include <map>

#include "command.h"
#include "scene_manager_creator.h"
#include "draw_manager_creator.h"
#include "transform_manager_creator.h"
#include "load_manager_creator.h"
#include "camera_manager_creator.h"

#define TRANSFORM_MANAGER "TRANSFORM_MANAGER"
#define DRAW_MANAGER "DRAW_MANAGER"
#define SCENE_MANAGER "SCENE_MANAGER"
#define MODEL_LOAD_MANAGER "MODEL_LOAD_MANAGER"
#define CAMERA_ADD_MANAGER "CAMERA_ADD_MANAGER"

class Facade {
public:
    using ManagersMap = std::map<std::string, std::shared_ptr<BaseManager>>;
    Facade();
    ~Facade() = default;
    template<typename Manager>
    void runCommand(BaseCommand<Manager> &command, std::string managerKey);
private:
    std::shared_ptr<Scene> _scene;
    std::shared_ptr<SceneManager> _sceneManager;
    std::shared_ptr<DrawManager> _drawManager;
    std::shared_ptr<TransformManager> _transformManager;
    std::shared_ptr<ModelLoadManager> _modelLoadManager;
    std::shared_ptr<CameraAddManager> _cameraAddManager;
    ManagersMap _managersMap;
    std::vector<ManagersMap::value_type> initManagerPairs();
};

#include "facade.hpp"
