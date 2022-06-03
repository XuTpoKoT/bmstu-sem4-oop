#pragma once

#include <map>

#include "command.h"
#include "scene_manager_creator.h"
#include "draw_manager_creator.h"
#include "transform_manager_creator.h"
#include "model_load_manager_creator.h"
#include "camera_manager_creator.h"
#include "model_reader_creator.h"

#define TRANSFORM_MANAGER "TRANSFORM_MANAGER"
#define DRAW_MANAGER "DRAW_MANAGER"
#define SCENE_MANAGER "SCENE_MANAGER"
#define MODEL_LOAD_MANAGER "MODEL_LOAD_MANAGER"
#define CAMERA_ADD_MANAGER "CAMERA_ADD_MANAGER"

class Facade {
public:
    using ManagersMap = std::map<std::string, std::shared_ptr<BaseManager>>;
    Facade(std::shared_ptr<ProjectConfig> config);
    ~Facade() = default;
    void setupDrawer();
    template<typename Manager>
    void runCommand(BaseCommand<Manager> &command, std::string managerKey);
private:
    std::shared_ptr<ProjectConfig> config;
    std::shared_ptr<Scene> scene;
    std::shared_ptr<SceneManager> sceneManager;
    std::shared_ptr<DrawManager> drawManager;
    std::shared_ptr<TransformManager> transformManager;
    std::shared_ptr<ModelLoadManager> modelLoadManager;
    std::shared_ptr<CameraAddManager> cameraAddManager;
    ManagersMap managersMap;
    std::vector<ManagersMap::value_type> initManagerPairs();
};

#include "facade.hpp"
