#ifndef SCENE_H
#define SCENE_H

#include "camera.h"
#include "composite.h"
#include <object.h>

class Scene {
public:
    Scene();
    ~Scene() = default;

    void add_object(const std::shared_ptr<Object>& object);
    void remove_object(const Iterator& iter);

    void accept(std::shared_ptr<Visitor> visitor);

    Iterator get_object(const size_t i);

    Iterator begin();
    Iterator end();

protected:
    std::shared_ptr<Composite> _objects;
};

#endif // SCENE_H
