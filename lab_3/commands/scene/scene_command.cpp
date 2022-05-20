#include "scene_command.h"

#include "draw_manager_creator.h"
#include "scene_manager_creator.h"

DrawScene::DrawScene(std::shared_ptr<AbstractDrawer> drawer)
    : _drawer(std::move(drawer))
{
}

void DrawScene::execute()
{
    auto draw_manager = DrawManagerCreator().create_manager();
    auto scene_manager = SceneManagerCreator().create_manager();

    _drawer->clear_scene();
    draw_manager->set_drawer(_drawer);
    draw_manager->set_camera(scene_manager->get_camera());
    draw_manager->draw(scene_manager->get_scene());
}
