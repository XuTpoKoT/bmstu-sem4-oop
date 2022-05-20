#ifndef BASE_MODEL_LOADER_H
#define BASE_MODEL_LOADER_H

#include "base_loader.h"
#include "model_builder.h"

namespace Load {
class BaseModelLoader : public BaseLoader {
public:
    virtual std::shared_ptr<Model> load(std::shared_ptr<ModelBuilder> builder) = 0;
};
} // namespace Load

#endif // BASE_MODEL_LOADER_H
