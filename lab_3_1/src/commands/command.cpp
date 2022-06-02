#include "command.h"

void DrawCommand::run(std::shared_ptr<std::shared_ptr<Object>> obj, std::shared_ptr<DrawManager> manager) {
    ((*manager).*_action)();
}

void SetupDrawerCommand::run(std::shared_ptr<std::shared_ptr<Object>> obj, std::shared_ptr<DrawManager> manager) {
    (*manager.*_action)(_drawer);
}

void SetCurrentCameraCommand::run(std::shared_ptr<std::shared_ptr<Object>> obj, std::shared_ptr<DrawManager> manager) {
    ((*manager).*_action)(*obj);
}

void SetCurrentModelCommand::run(std::shared_ptr<std::shared_ptr<Object>> obj, std::shared_ptr<DrawManager> manager) {
    ((*manager).*_action)(*obj);
}

void AddModelCommand::run(std::shared_ptr<std::shared_ptr<Object>> obj, std::shared_ptr<ModelLoadManager> manager) {
    *obj = ((*manager).*_action)(_sourceName);
}

void AddCameraCommand::run(std::shared_ptr<std::shared_ptr<Object>> obj, std::shared_ptr<CameraAddManager> manager) {
    *obj = ((*manager).*_action)();
}

void MoveModelCommand::run(std::shared_ptr<std::shared_ptr<Object>> obj, std::shared_ptr<TransformManager> manager) {
    ((*manager).*_action)(*obj, _move);
}

void RotateModelCommand::run(std::shared_ptr<std::shared_ptr<Object>> obj, std::shared_ptr<TransformManager> manager) {
    ((*manager).*_action)(*obj, _rotate);
}

void ScaleModelCommand::run(std::shared_ptr<std::shared_ptr<Object>> obj, std::shared_ptr<TransformManager> manager) {
    ((*manager).*_action)(*obj, _scale);
}

void MoveCameraCommand::run(std::shared_ptr<std::shared_ptr<Object>> obj, std::shared_ptr<TransformManager> manager) {
    ((*manager).*_action)(*obj, _move);
}

void RotateCameraCommand::run(std::shared_ptr<std::shared_ptr<Object>> obj, std::shared_ptr<TransformManager> manager) {
    ((*manager).*_action)(*obj, _rotate);
}

void RemoveCameraCommand::run(std::shared_ptr<std::shared_ptr<Object>> obj, std::shared_ptr<SceneManager> manager) {
    ((*manager).*_action)(*_id);
}

void RemoveModelCommand::run(std::shared_ptr<std::shared_ptr<Object>> obj, std::shared_ptr<SceneManager> manager) {
    ((*manager).*_action)(*_id);
}
