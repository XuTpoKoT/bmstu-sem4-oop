#include "camera_command.h"
#include "camera.h"
#include "camera_load_controller_creator.h"
#include "load_manager_creator.h"
#include "scene_manager_creator.h"
#include "transform_manager_creator.h"

AddCamera::AddCamera(const ID& _id, const double x, const double y, const double z)
    : _id(_id)
    , _x_pos(x)
    , _y_pos(y)
    , _z_pos(z)
{
}

void AddCamera::execute()
{
    Vertice camera_pos(_x_pos, _y_pos, _z_pos);
    std::shared_ptr<Camera> camera(new Camera);
    camera->transform(camera_pos, camera_pos, camera_pos);

    auto _scene_manager = SceneManagerCreator().create_manager();
    auto scene = _scene_manager->get_scene();
    scene->add_object(camera);

    (*_id) = camera->get_id();
}

RemoveCamera::RemoveCamera(const std::size_t& _id)
    : _id(_id)
{
}

void RemoveCamera::execute()
{
    auto _scene_manager = SceneManagerCreator().create_manager();
    auto scene = _scene_manager->get_scene();
    scene->remove_object(scene->get_object(_id));
}

MoveCamera::MoveCamera(const std::size_t& _id, const double& shift_ox, const double& shift_oy)
    : _id(_id)
    , _shift_ox(shift_ox)
    , _shift_oy(shift_oy)
{
}

void MoveCamera::execute()
{
    Vertice shift(_shift_ox, _shift_oy, 0);
    auto scene_manager = SceneManagerCreator().create_manager();
    auto scene = scene_manager->get_scene();
    auto camera = *(scene->get_object(_id));
    TransformManagerCreator().create_manager()->transform_object(camera, shift, shift, shift);
}

SetCamera::SetCamera(const size_t& _id)
    : _id(_id)
{
}

void SetCamera::execute()
{
    SceneManagerCreator().create_manager()->set_camera(_id);
}

LoadCamera::LoadCamera(std::string fname)
    : _fname(std::move(fname))
{
}

void LoadCamera::execute()
{
    auto controller = Load::CameraLoadControllerCreator().create_controller();

    auto manager = Load::LoadManagerCreator().create_manager(controller);

    auto scene = std::dynamic_pointer_cast<Scene>(manager->load(_fname));
    SceneManagerCreator().create_manager()->set_scene(scene);
}
