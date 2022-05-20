#ifndef MODELLOADCONTROLLER_H
#define MODELLOADCONTROLLER_H

#include "abstract_load_controller.h"
#include "base_loader.h"
#include "base_model_loader.h"
#include "model_builder.h"
#include <abstract_load_controller.h>

namespace Load {
class ModelLoadController : public AbstractLoadController {
public:
    explicit ModelLoadController(std::shared_ptr<BaseModelLoader> loader)
        : _builder(new ModelBuilder)
        , _loader(std::move(loader)) {};
    ~ModelLoadController() = default;

    std::shared_ptr<Object> load(std::string& fname) override;

private:
    std::shared_ptr<ModelBuilder> _builder;
    std::shared_ptr<BaseModelLoader> _loader;
};
} // namespace Load

#endif // MODELLOADCONTROLLER_H
