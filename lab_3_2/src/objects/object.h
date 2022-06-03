#pragma once

#include "vector.h"
#include "base_visitor.h"
#include "point.h"

struct MoveParams {
    double dx;
    double dy;
    double dz;
};

struct ScaleParams {
    double kx;
    double ky;
    double kz;
};

struct RotateParams {
    double ox;
    double oy;
    double oz;
};

class Object;

using VectorObject = Vector<std::shared_ptr<Object>>;
using IteratorObject = VectorObject::iterator;

class Object {
public:
        Object();
        virtual ~Object() = 0;

        //virtual void accept(std::shared_ptr<BaseVisitor> visitor) = 0;

        virtual void move(const MoveParams &moveParams);
        virtual void rotate(const RotateParams &rotateParams);
        virtual void scale(const ScaleParams &scaleParams);

        virtual MoveParams getPosition() { return moveParams; };
        virtual RotateParams getRotation() { return rotateParams; };
        virtual ScaleParams getScale() { return scaleParams; };

        virtual bool isVisible() const { return false; };
        virtual bool isComposite() const { return false; }
        virtual bool add(std::shared_ptr<Object> obj) { return false; }
        virtual bool remove(IteratorObject &iter) { return false; }
        virtual int getId() { return id; }

        virtual IteratorObject begin() { return IteratorObject(); }
        virtual IteratorObject end() { return IteratorObject(); }
protected:
        void init();
        MoveParams moveParams;
        RotateParams rotateParams;
        ScaleParams scaleParams;
        inline static int nextId;
        int id;
};
