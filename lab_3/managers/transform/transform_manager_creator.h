#ifndef TRANSFORMMANAGERCREATOR_H
#define TRANSFORMMANAGERCREATOR_H

#include "transform_manager.h"
#include <memory>

class TransformManagerCreator {
public:
    std::shared_ptr<TransformManager> create_manager();

private:
    void create_instance();

    std::shared_ptr<TransformManager> _manager;
};

#endif // TRANSFORMMANAGERCREATOR_H
