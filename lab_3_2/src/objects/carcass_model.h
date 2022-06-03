#ifndef CARCASS_MODEL_H
#define CARCASS_MODEL_H

#include "base_model.h"

class CarcassModel : BaseModel {
    friend class CarcassModelBuilder;
    friend class DrawVisitor;
public:
    ~CarcassModel();
protected:
    CarcassModel();
    std::vector<Point> points;
    std::vector<Edge> edges;
};

#endif // CARCASS_MODEL_H
