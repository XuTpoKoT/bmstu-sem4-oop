#include "facade.h"

std::vector<Facade::ManagersMap::value_type> Facade::initManagerPairs() {
    std::vector<ManagersMap::value_type> managerPairs;
    managerPairs.push_back(ManagersMap::value_type(TRANSFORM_MANAGER, _transformManager));
    managerPairs.push_back(ManagersMap::value_type(DRAW_MANAGER, _drawManager));
    managerPairs.push_back(ManagersMap::value_type(SCENE_MANAGER, _sceneManager));
    managerPairs.push_back(ManagersMap::value_type(MODEL_LOAD_MANAGER, _modelLoadManager));
    managerPairs.push_back(ManagersMap::value_type(CAMERA_ADD_MANAGER, _cameraAddManager));
    return managerPairs;
}

Facade::Facade() {
    _sceneManager = SceneManagerCreator().createManager();
    _drawManager = DrawManagerCreator().createManager();
    _transformManager = TransformManagerCreator().createManager();
    _cameraAddManager = CameraManagerCreator().createManager();

    _scene = _sceneManager->getScene();

    LoaderSolution solution;
    solution.configure(TXT, BaseModelLoaderCreator::createLoader);
    std::shared_ptr<BaseModelLoaderCreator> creator(new CarcassModelLoaderCreator());
    auto loader = solution.createLoader(creator.get());
    _modelLoadManager = LoadManagerCreator().createManager(loader);

    std::vector<ManagersMap::value_type> managerPairs = initManagerPairs();

    for (auto &managerPair: managerPairs)
        _managersMap.insert(managerPair);
}