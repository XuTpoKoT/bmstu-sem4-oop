#include "scene.h"

#include <iterator>

Scene::Scene()
    : _objects(new Composite)
{
}

void Scene::add_object(const std::shared_ptr<Object>& object)
{
    _objects->add(object);
}

void Scene::remove_object(const Iterator& iter)
{
    _objects->remove(iter);
}

void Scene::accept(std::shared_ptr<Visitor> visitor)
{
    this->_objects->accept(std::move(visitor));
}

Iterator Scene::get_object(const size_t i)
{
    auto iter = begin();

    for (; iter != end() && (*iter)->get_id() != i; ++iter)
        ;

    return iter;
}

Iterator Scene::begin()
{
    return _objects->begin();
}

Iterator Scene::end()
{
    return _objects->end();
}
