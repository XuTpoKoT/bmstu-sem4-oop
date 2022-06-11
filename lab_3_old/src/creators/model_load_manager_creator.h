#pragma once

#include "base_creator.h"
#include "abstract_source_model_reader.h"
#include "model_load_manager.h"

class ModelLoadManagerCreator: public BaseCreator {
public:
    std::shared_ptr<ModelLoadManager> createManager(std::shared_ptr<TextFileModelReader> reader);
private:
    void createInstance() override;
    std::shared_ptr<ModelLoadManager> manager;
};
