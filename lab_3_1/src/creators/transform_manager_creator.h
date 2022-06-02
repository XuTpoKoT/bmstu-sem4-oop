#pragma once

#include "base_creator.h"
#include "transform_manager.h"

class TransformManagerCreator: public BaseCreator {
public:
    TransformManagerCreator() = default;
    ~TransformManagerCreator() = default;
    std::shared_ptr<TransformManager> createManager();
private:
    void createInstance() override;
    std::shared_ptr<TransformManager> _manager;
};
