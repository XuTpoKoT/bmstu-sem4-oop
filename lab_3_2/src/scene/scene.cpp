#include "scene.h"

Scene::Scene() {
    auto comp = std::shared_ptr<Object>(new Composite());
    _objects.push_back(comp);
}

void Scene::addObject(int compositeId, std::shared_ptr<Object> object) {
    time_t t_time = time(NULL);
    if (begin() + compositeId >= end())
        throw IndexOutOfRangeError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    _objects.at(compositeId)->add(object);
}

void Scene::addObject(std::shared_ptr<Object> object) {
    _objects.push_back(object);
}

IteratorObject Scene::getObject(const int id) {
    auto compositeIter = begin();
    auto objIter = (*compositeIter)->begin();
    for (; compositeIter != end(); compositeIter++) {
            for (; objIter != (*compositeIter)->end() && (*objIter)->getId() != id; objIter++);
    }
    return objIter;
}

void Scene::removeObject(IteratorObject &iter) {
    auto compositeIter = begin();
    auto objIter = (*compositeIter)->begin();
    for (; compositeIter != end(); compositeIter++) {
            for (; objIter != (*compositeIter )->end() && objIter != iter; objIter++);
    }
    (*objIter)->remove(iter);
}
