#pragma once

#include <QGraphicsScene>
#include <camera.h>

#include "base_model_loader.h"

#include "drawer_solution.h"
#include "loader_solution.h"

#include "draw_manager_creator.h"
#include "scene_manager_creator.h"
#include "transform_manager_creator.h"
#include "load_manager_creator.h"
#include "camera_manager_creator.h"

template<typename Manager>
class BaseCommand {
public:
    BaseCommand(): id(nullptr) {};
    BaseCommand(std::shared_ptr<int> id) {
        id = id;
    };
    BaseCommand(std::shared_ptr<int> id, int compositeId) {
        id = id;
        _compositeId = compositeId;
    }
    ~BaseCommand() = default;
    void setId(int id) { *id = id; };
    std::shared_ptr<int> getId() { return id; };
    int getCompositeId() {return _compositeId;};
    virtual void run(std::shared_ptr<std::shared_ptr<Object>> obj, std::shared_ptr<Manager> manager) = 0;
protected:
    std::shared_ptr<int> id;
    int _compositeId;
};

class SetupDrawerCommand: public BaseCommand<DrawManager> {
public:
    using Action = void(DrawManager::*)(std::shared_ptr<AbstractDrawer>);
    SetupDrawerCommand() = delete;
    explicit SetupDrawerCommand(Action a, std::shared_ptr<AbstractDrawer> drawer):
        BaseCommand<DrawManager>(),
        _drawer(drawer),
        _action(a)
    {};
    ~SetupDrawerCommand() = default;
    void run(std::shared_ptr<std::shared_ptr<Object>> obj, std::shared_ptr<DrawManager> manager) override;
private:
    Action _action;
    std::shared_ptr<AbstractDrawer> _drawer;
};

class DrawCommand: public BaseCommand<DrawManager> {
public:
    using Action = void(DrawManager::*)();
    DrawCommand() = delete;
    explicit DrawCommand(Action a, std::shared_ptr<AbstractDrawer> drawer):
        BaseCommand<DrawManager>(),
        _drawer(drawer),
        _action(a)
    {};
    ~DrawCommand() = default;
    void run(std::shared_ptr<std::shared_ptr<Object>> obj, std::shared_ptr<DrawManager> manager) override;
private:
    Action _action;
    std::shared_ptr<AbstractDrawer> _drawer;
};

class SetCurrentCameraCommand: public BaseCommand<DrawManager> {
public:
    using Action = void(DrawManager::*)(std::shared_ptr<Object>);
    SetCurrentCameraCommand() = delete;
    explicit SetCurrentCameraCommand(std::shared_ptr<int> id, Action a):
        BaseCommand<DrawManager>(id),
        _action(a)
    {};
    ~SetCurrentCameraCommand() = default;
    void run(std::shared_ptr<std::shared_ptr<Object>> obj, std::shared_ptr<DrawManager> manager) override;
private:
    Action _action;
};

class SetCurrentModelCommand: public BaseCommand<DrawManager> {
public:
    using Action = void(DrawManager::*)(std::shared_ptr<Object>);
    SetCurrentModelCommand() = delete;
    explicit SetCurrentModelCommand(std::shared_ptr<int> id, Action a):
        BaseCommand<DrawManager>(id),
        _action(a)
    {};
    ~SetCurrentModelCommand() = default;
    void run(std::shared_ptr<std::shared_ptr<Object>> obj, std::shared_ptr<DrawManager> manager) override;
private:
    Action _action;
};

class AddModelCommand: public BaseCommand<ModelLoadManager> {
public:
    using Action = std::shared_ptr<BaseModel>(ModelLoadManager::*)(std::string);
    AddModelCommand() = delete;
    explicit AddModelCommand(std::shared_ptr<int> id, Action a, std::string sourceName, int compositeId):
        BaseCommand<ModelLoadManager>(id, compositeId),
        _sourceName(sourceName),
        _action(a)
    {};
    ~AddModelCommand() = default;
    void run(std::shared_ptr<std::shared_ptr<Object>> obj, std::shared_ptr<ModelLoadManager> manager) override;
private:
    Action _action;
    std::string _sourceName;
};

class RemoveModelCommand: public BaseCommand<SceneManager> {
public:
    using Action = void(SceneManager::*)(int);
    RemoveModelCommand() = delete;
    explicit RemoveModelCommand(std::shared_ptr<int> id, Action a):
        BaseCommand<SceneManager>(id),
        _action(a)
    {};
    ~RemoveModelCommand() = default;
    void run(std::shared_ptr<std::shared_ptr<Object>> obj, std::shared_ptr<SceneManager> manager) override;
private:
    Action _action;
};

class AddCameraCommand: public BaseCommand<CameraAddManager> {
public:
    using Action = std::shared_ptr<Camera>(CameraAddManager::*)();
    AddCameraCommand() = delete;
    explicit AddCameraCommand(std::shared_ptr<int> id, Action a, int compositeId):
        BaseCommand<CameraAddManager>(id, compositeId),
        _action(a)
    {}
    ~AddCameraCommand() = default;
    void run(std::shared_ptr<std::shared_ptr<Object>> obj, std::shared_ptr<CameraAddManager> manager) override;
private:
    Action _action;
};

class RemoveCameraCommand: public BaseCommand<SceneManager> {
public:
    using Action = void(SceneManager::*)(int);
    RemoveCameraCommand() = delete;
    explicit RemoveCameraCommand(std::shared_ptr<int> id, Action a):
        BaseCommand<SceneManager>(id),
        _action(a)
    {};
    ~RemoveCameraCommand() = default;
    void run(std::shared_ptr<std::shared_ptr<Object>> obj, std::shared_ptr<SceneManager> manager) override;
private:
    Action _action;
    int _index;
};

class MoveModelCommand: public BaseCommand<TransformManager> {
public:
    using Action = void(TransformManager::*)(std::shared_ptr<Object>, const MoveParams &);
    MoveModelCommand() = delete;
    explicit MoveModelCommand(std::shared_ptr<int> id, Action a, const MoveParams &pos):
        BaseCommand<TransformManager>(id),
        _action(a)
    {
        _move = pos;
    };
    void run(std::shared_ptr<std::shared_ptr<Object>> obj, std::shared_ptr<TransformManager> manager) override;
    ~MoveModelCommand() = default;
private:
    Action _action;
    int _index;
    MoveParams _move;
};
class RotateModelCommand: public BaseCommand<TransformManager> {
public:
    using Action = void(TransformManager::*)(std::shared_ptr<Object>, const RotateParams &);
    RotateModelCommand() = delete;
    explicit RotateModelCommand(std::shared_ptr<int> id, Action a, const RotateParams &rot):
        BaseCommand<TransformManager>(id),
        _action(a)
    {
        _rotate = rot;
    };
    void run(std::shared_ptr<std::shared_ptr<Object>> obj, std::shared_ptr<TransformManager> manager) override;
    ~RotateModelCommand() = default;
private:
    Action _action;
    int _index;
    RotateParams _rotate;
};

class ScaleModelCommand: public BaseCommand<TransformManager> {
public:
    using Action = void(TransformManager::*)(std::shared_ptr<Object>, const ScaleParams &);
    ScaleModelCommand() = delete;
    explicit ScaleModelCommand(std::shared_ptr<int> id, Action a, const ScaleParams &sc):
        BaseCommand<TransformManager>(id),
        _action(a)
    {
        _scale = sc;
    };
    void run(std::shared_ptr<std::shared_ptr<Object>> obj, std::shared_ptr<TransformManager> manager) override;
    ~ScaleModelCommand() = default;
private:
    Action _action;
    int _index;
    ScaleParams _scale;
};

class MoveCameraCommand: public BaseCommand<TransformManager> {
public:
    using Action = void(TransformManager::*)(std::shared_ptr<Object>, const MoveParams &);
    MoveCameraCommand() = delete;
    explicit MoveCameraCommand(std::shared_ptr<int> id, Action a, const MoveParams &pos):
        BaseCommand<TransformManager>(id),
        _action(a)
    {
        _move = pos;
    };
    void run(std::shared_ptr<std::shared_ptr<Object>> obj, std::shared_ptr<TransformManager> manager) override;
    ~MoveCameraCommand() = default;
private:
    Action _action;
    int _index;
    MoveParams _move;
};
class RotateCameraCommand: public BaseCommand<TransformManager> {
public:
    using Action = void(TransformManager::*)(std::shared_ptr<Object>, const RotateParams &);
    RotateCameraCommand() = delete;
    explicit RotateCameraCommand(std::shared_ptr<int> id, Action a, const RotateParams &rot):
        BaseCommand<TransformManager>(id),
        _action(a)
    {
        _rotate = rot;
    };
    void run(std::shared_ptr<std::shared_ptr<Object>> obj, std::shared_ptr<TransformManager> manager) override;
    ~RotateCameraCommand() = default;
private:
    Action _action;
    int _index;
    RotateParams _rotate;
};
