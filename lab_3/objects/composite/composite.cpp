#include "composite.h"

Composite::Composite(std::shared_ptr<Object>& component)
{
    _objects.push_back(component);
}

Composite::Composite(const std::vector<std::shared_ptr<Object>>& vector)
    : _objects(vector)
{
}

bool Composite::add(const std::shared_ptr<Object>& obj)
{
    _objects.push_back(obj);
    return true;
}

bool Composite::remove(const Iterator& iterator)
{
    _objects.erase(iterator);
    return true;
}

Iterator Composite::begin()
{
    return _objects.begin();
}

Iterator Composite::end()
{
    return _objects.end();
}

bool Composite::is_visible()
{
    return false;
}

bool Composite::is_composite() const
{
    return true;
}

size_t Composite::size() const
{
    return _objects.size();
}

void Composite::transform(const Vertice& move, const Vertice& scale, const Vertice& rotate)
{
    for (const auto& elem : _objects) {
        elem->transform(move, scale, rotate);
    }
}

void Composite::accept(std::shared_ptr<Visitor> visitor)
{
    for (const auto& obj : _objects) {
        obj->accept(visitor);
    }
}

Vertice Composite::get_center() const
{
    Vertice center = Vertice(0, 0, 0);

    for (const auto& object : _objects)
        center = center + object->get_center();

    center = Vertice(center.get_x() / _objects.size(), center.get_y() / _objects.size(), center.get_z() / _objects.size());

    return center;
}
