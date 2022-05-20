#ifndef DRAWMANAGER_H
#define DRAWMANAGER_H

#include "abstract_drawer.h"
#include "base_manager.h"
#include "composite.h"
#include "scene.h"
#include "vertice.h"
#include "visitor.h"
#include <memory>

class DrawManager : public BaseManager {
public:
    DrawManager() = default;
    DrawManager(const DrawManager&) = delete;
    ~DrawManager() = default;

    DrawManager& operator=(const DrawManager&) = delete;

    void draw(const std::shared_ptr<Scene>& scene);

    void set_drawer(std::shared_ptr<AbstractDrawer>);
    void set_camera(std::shared_ptr<Camera>);

private:
    std::shared_ptr<AbstractDrawer> _drawer;
    std::shared_ptr<Camera> _camera;
};

#endif // DRAWMANAGER_H
