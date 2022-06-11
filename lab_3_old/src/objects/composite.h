#pragma once

#include "object.h"

class Composite: public Object {
public:
    Composite() = default;
    ~Composite() = default;
    bool isComposite() const override;
    bool add(std::shared_ptr<Object> obj) override;
    bool remove(IteratorObject &iter) override;
    // void accept(std::shared_ptr<BaseVisitor> visitor) override;

    void move(const MoveParams &rotateParams) override;
    void rotate(const RotateParams &rotateParams) override;
    void scale(const ScaleParams &rotateParams) override;

    IteratorObject begin() override;
    IteratorObject end() override;
private:
    VectorObject _objects;
};
