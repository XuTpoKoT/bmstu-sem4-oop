#pragma once

class BaseModel;
class Composite;
class Camera;

class BaseVisitor {
public:
    virtual void visit(BaseModel &model) = 0;
    virtual void visit(Camera &camera) = 0;
    virtual void visit(Composite &composite) = 0;
};
