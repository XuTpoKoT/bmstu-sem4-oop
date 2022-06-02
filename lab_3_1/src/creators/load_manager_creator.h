#pragma once

#include "base_creator.h"
#include "model_load_manager.h"

class LoadManagerCreator: public BaseCreator {
public:
    std::shared_ptr<ModelLoadManager> createManager(std::shared_ptr<AbstractLoader> loader);
private:
    void createInstance() override;
    std::shared_ptr<ModelLoadManager> _manager;
};
