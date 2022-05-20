#include "scene_builder.h"

bool SceneBuilder::is_build() const
{
    return nullptr != _scene_ptr;
}

void SceneBuilder::build()
{
    _scene_ptr = std::make_shared<Scene>();
}

std::shared_ptr<Scene> SceneBuilder::get()
{
    return _scene_ptr;
}

void SceneBuilder::build_object(const std::shared_ptr<Object>& object)
{
    if (!is_build()) { }

    _scene_ptr->add_object(object);
}
