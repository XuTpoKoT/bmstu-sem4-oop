#pragma once

#include <memory>
#include "object.h"
#include "camera.h"
#include "composite.h"
#include "vector.h"

class Scene {
public:
    Scene();
    ~Scene() = default;
    void addObject(int compositeId, std::shared_ptr<Object> object);
    void addObject(std::shared_ptr<Object> object);

    void removeObject(IteratorObject &iter);
    IteratorObject getObject(const int id);
    IteratorObject begin() { return _objects.begin(); }
    IteratorObject end() { return _objects.end(); }
private:
    Vector<std::shared_ptr<Object>> _objects;
};
