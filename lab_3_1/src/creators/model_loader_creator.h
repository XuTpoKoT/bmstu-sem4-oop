#pragma once

#include "abstract_loader_creator.h"

#include "text_file_loader.h"
#include "carcass_model_director.h"

class ModelLoaderCreator: public BaseModelLoaderCreator {
public:
    ~ModelLoaderCreator() = default;
    std::shared_ptr<BaseModelLoader> createLoader() override;
private:
    void createInstance() override;
    std::shared_ptr<AbstractSourceLoader> _fileLoader;
    std::shared_ptr<BaseModelDirector> _modelDirector;
};
