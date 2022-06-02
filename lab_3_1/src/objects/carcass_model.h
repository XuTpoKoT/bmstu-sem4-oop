#ifndef CARCASS_MODEL_H
#define CARCASS_MODEL_H

#include "base_model.h"
#include "carcass_model_structure.h"

class CarcassModel : BaseModel {
public:
    CarcassModel();
    const std::shared_ptr<CarcassModelStructure> getStructure() const { return structure; };

protected:
    std::shared_ptr<CarcassModelStructure> structure;
};

#endif // CARCASS_MODEL_H
