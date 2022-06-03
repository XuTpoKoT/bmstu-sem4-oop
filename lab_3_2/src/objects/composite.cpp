#include "composite.h"

//void Composite::accept(std::shared_ptr<BaseVisitor> visitor) {
//    for (auto &object: _objects)
//        object->accept(visitor);
//}

bool Composite::isComposite() const {
    return true;
}

bool Composite::add(std::shared_ptr<Object> obj) {
    _objects.push_back(obj);
    return false;
}

bool Composite::remove(IteratorObject &iter) {
    _objects.erase(iter);
    return true;
}

IteratorObject Composite::begin() {
    return _objects.begin();
}

IteratorObject Composite::end() {
    return _objects.end();
}

void Composite::move(const MoveParams &moveParams) {
    for (auto &obj: _objects)
        obj->move(moveParams);
}

void Composite::rotate(const RotateParams &rotateParams) {
    for (auto &obj: _objects)
        obj->rotate(rotateParams);
}

void Composite::scale(const ScaleParams &scaleParams) {
    for (auto &obj: _objects)
        obj->scale(scaleParams);
}


