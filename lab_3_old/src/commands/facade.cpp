#include "facade.h"

std::vector<Facade::ManagersMap::value_type> Facade::initManagerPairs() {
    std::vector<ManagersMap::value_type> managerPairs;
    managerPairs.push_back(ManagersMap::value_type(TRANSFORM_MANAGER, transformManager));
    managerPairs.push_back(ManagersMap::value_type(DRAW_MANAGER, drawManager));
    managerPairs.push_back(ManagersMap::value_type(SCENE_MANAGER, sceneManager));
    managerPairs.push_back(ManagersMap::value_type(MODEL_LOAD_MANAGER, modelLoadManager));
    managerPairs.push_back(ManagersMap::value_type(CAMERA_ADD_MANAGER, cameraAddManager));
    return managerPairs;
}

Facade::Facade(std::shared_ptr<ProjectConfig> config) {
    this->config = config;
    transformManager = TransformManagerCreator().createManager();
    cameraAddManager = CameraManagerCreator().createManager();
    drawManager = DrawManagerCreator().createManager();
    auto reader = ModelReaderCreator().create(this->config->getSourceStreamType());
    modelLoadManager = ModelLoadManagerCreator().createManager(reader);
    sceneManager = SceneManagerCreator().createManager();
    scene = sceneManager->getScene();

    std::vector<ManagersMap::value_type> managerPairs = initManagerPairs();

    for (auto &managerPair: managerPairs)
        managersMap.insert(managerPair);
}
