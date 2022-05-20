#include "draw_manager.h"

#include "camera.h"
#include "model.h"
#include "scene.h"

void DrawManager::draw(const std::shared_ptr<Scene>& scene)
{
    auto visitor = std::make_shared<DrawVisitor>(this->_drawer, this->_camera);
    scene->accept(visitor);
}

void DrawManager::set_drawer(std::shared_ptr<AbstractDrawer> drawer)
{
    _drawer = std::move(drawer);
}

void DrawManager::set_camera(std::shared_ptr<Camera> camera)
{
    _camera = std::move(camera);
}
