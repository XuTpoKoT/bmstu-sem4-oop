#ifndef MODEL_H
#define MODEL_H

#include "base_model.h"
#include "draw_visitor.h"
#include "edge.h"
#include "model_structure.h"
#include "vertice.h"
#include <memory>

class Model : public BaseModel {
    friend void DrawVisitor::visit(const Model& model);

public:
    Model()
        : _structure(new ModelStructure) {};
    explicit Model(std::shared_ptr<ModelStructure> structure)
        : _structure(std::move(structure)) {};
    Model(const Model& model);
    ~Model() override = default;

    void transform(const Vertice& move, const Vertice& scale, const Vertice& rotate) override;
    void accept(std::shared_ptr<Visitor> visitor) override;

    virtual Vertice get_center() const override;

protected:
    const std::shared_ptr<ModelStructure> get_structure() const { return _structure; };

private:
    std::shared_ptr<ModelStructure> _structure;
};

#endif // MODEL_H
