#ifndef VISITOR_H
#define VISITOR_H

class Camera;
class Model;
class Composite;

class Visitor {
public:
    Visitor() = default;

    virtual ~Visitor() = default;

    virtual void visit(const Camera& camera) = 0;
    virtual void visit(const Model& model) = 0;
    virtual void visit(const Composite& composite) = 0;
};

#endif // VISITOR_H
