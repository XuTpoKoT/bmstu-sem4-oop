#include "model_command.h"
#include "load_controller_solution.h"
#include "load_manager_creator.h"
#include "scene_manager_creator.h"
#include "transform_manager_creator.h"

MoveModel::MoveModel(const double& dx, const double& dy, const double& dz, const std::size_t& _id)
    : _id(_id)
    , _dx(dx)
    , _dy(dy)
    , _dz(dz)
{
}

void MoveModel::execute()
{
    Vertice move(_dx, _dy, _dz);
    Vertice scale(1, 1, 1);
    Vertice rotate(0, 0, 0);

    auto scene_manager = SceneManagerCreator().create_manager();
    auto scene = scene_manager->get_scene();
    auto model = *(scene->get_object(_id));
    TransformManagerCreator().create_manager()->transform_object(model, move, scale, rotate);
}

ScaleModel::ScaleModel(const double& kx, const double& ky, const double& kz, const std::size_t& _id)
    : _id(_id)
    , _kx(kx)
    , _ky(ky)
    , _kz(kz)

{
}

void ScaleModel::execute()
{
    Vertice move(0, 0, 0);
    Vertice scale(_kx, _ky, _kz);
    Vertice rotate(0, 0, 0);

    auto scene_manager = SceneManagerCreator().create_manager();
    auto scene = scene_manager->get_scene();
    auto model = *(scene->get_object(_id));
    TransformManagerCreator().create_manager()->transform_object(model, move, scale, rotate);
}

RotateModel::RotateModel(const double& ox, const double& oy, const double& oz, const std::size_t& _id)
    : _id(_id)
    , _ox(ox)
    , _oy(oy)
    , _oz(oz)

{
}

void RotateModel::execute()
{
    Vertice move(0, 0, 0);
    Vertice scale(1, 1, 1);
    Vertice rotate(_ox, _oy, _oz);

    auto scene_manager = SceneManagerCreator().create_manager();
    auto scene = scene_manager->get_scene();
    auto model = *(scene->get_object(_id));
    TransformManagerCreator().create_manager()->transform_object(model, move, scale, rotate);
}

TransformModel::TransformModel(const std::size_t& _id, const Vertice& move, const Vertice& scale, const Vertice& rotate)

    : _id(_id)
    , _move(move)
    , _scale(scale)
    , _rotate(rotate)
{
}

void TransformModel::execute()
{
    auto scene_manager = SceneManagerCreator().create_manager();
    auto scene = scene_manager->get_scene();
    auto model = *(scene->get_object(_id));
    TransformManagerCreator().create_manager()->transform_object(model, _move, _scale, _rotate);
}

LoadModel::LoadModel(const ID& _id, std::string fname)
    : _id(_id)
    , fname(std::move(fname))
{
}

void LoadModel::execute()
{
    auto controller = Load::LoadControllerSolution().create_controller(AbstractConfiguration::MODEL);
    auto manager = Load::LoadManagerCreator().create_manager(controller);

    auto model = manager->load(fname);
    SceneManagerCreator().create_manager()->get_scene()->add_object(model);

    (*_id) = model->get_id();
}

ExportModel::ExportModel(std::string fname)
{
}

void ExportModel::execute()
{
}

AddModel::AddModel(std::shared_ptr<Object> model)
    : model(std::move(model))
{
}

void AddModel::execute()
{
    SceneManagerCreator().create_manager()->get_scene()->add_object(model);

    (*_id) = model->get_id();
}

RemoveModel::RemoveModel(const std::size_t& _id)
    : _id(_id)
{
}

void RemoveModel::execute()
{
    auto scene_manager = SceneManagerCreator().create_manager();
    auto scene = scene_manager->get_scene();
    auto model = scene->get_object(_id);
    scene->remove_object(model);
}
