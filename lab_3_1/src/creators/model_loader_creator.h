#pragma once

#include "abstract_loader_creator.h"

#include "text_file_loader.h"
#include "model_director.h"

class ModelLoaderCreator: public AbstractLoaderCreator {
public:
    ~ModelLoaderCreator() = default;
    std::shared_ptr<AbstractLoader> createLoader() override;
private:
    void createInstance() override;
    std::shared_ptr<BaseLoader> _fileLoader;
    std::shared_ptr<BaseModelDirector> _modelDirector;
};
