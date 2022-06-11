#pragma once

#include "base_manager.h"
#include "text_file_model_reader.h"
#include "model_director.h"
#include "carcass_model_builder.h"

class ModelLoadManager: public BaseManager {
public:
    void setModelReader(std::shared_ptr<TextFileModelReader> reader);
    BaseModel loadModel(std::string sourceName);
private:
    std::shared_ptr<TextFileModelReader> reader;
};
