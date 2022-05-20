#include "draw_visitor.h"
#include "camera.h"
#include "model.h"

DrawVisitor::DrawVisitor(const std::shared_ptr<AbstractDrawer>& drawer, const std::shared_ptr<Camera>& camera)
    : _drawer(drawer)
    , _camera(camera)
{
}

void DrawVisitor::visit(const Model& model)
{
    auto vertices = model.get_structure()->get_vertices();
    auto center = model.get_structure()->get_center();
    for (auto edge : model.get_structure()->get_edges())
        _drawer->draw_line(
            proection_vertice(vertices.at(edge.get_first_vertice()) + center),
            proection_vertice(vertices.at(edge.get_last_vertice()) + center));
}

Vertice DrawVisitor::proection_vertice(const Vertice& vertice)
{
    Vertice new_vertice(vertice);
    Vertice camera_pos(_camera->get_center());
    new_vertice.set_x(new_vertice.get_x() + camera_pos.get_x());
    new_vertice.set_y(new_vertice.get_y() + camera_pos.get_y());

    return new_vertice;
}

void DrawVisitor::visit(const Camera& camera) { }

void DrawVisitor::visit(const Composite& composite) { }
