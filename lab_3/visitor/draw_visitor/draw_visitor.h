#ifndef DRAWVISITOR_H
#define DRAWVISITOR_H

#include "abstract_drawer.h"
#include "camera.h"
#include "vertice.h"
#include <memory>
#include <visitor.h>

class DrawVisitor : public Visitor {
public:
    DrawVisitor(const std::shared_ptr<AbstractDrawer>& drawer, const std::shared_ptr<Camera>& camera);

    void visit(const Camera& camera) override;
    void visit(const Composite& composite) override;
    void visit(const Model& model) override;

private:
    std::shared_ptr<AbstractDrawer> _drawer;
    std::shared_ptr<Camera> _camera;
    Vertice proection_vertice(const Vertice& vertice);
};

#endif // DRAWVISITOR_H
