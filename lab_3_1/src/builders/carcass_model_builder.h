#pragma once

#include "base_model_builder.h"
#include "carcass_model.h"

class CarcassModelBuilder: public BaseModelBuilder {
public:
    CarcassModelBuilder();
    ~CarcassModelBuilder() = default;
    std::shared_ptr<CarcassModel> getModel() {
        return std::make_shared<CarcassModel>(structure);
    };
    void buildPoints(const Vector<Point> &points) override;
    void buildLinks(const Vector<Edge> &links) override;
    void reset() override;
protected:
    std::shared_ptr<CarcassModelStructure> structure;
};
