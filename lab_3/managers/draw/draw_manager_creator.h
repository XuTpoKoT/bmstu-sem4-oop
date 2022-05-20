#ifndef DRAWMANAGERCREATOR_H
#define DRAWMANAGERCREATOR_H

#include "draw_manager.h"

class DrawManagerCreator {
public:
    std::shared_ptr<DrawManager> create_manager();

private:
    void create_instance();

    std::shared_ptr<DrawManager> _manager;
};

#endif // DRAWMANAGERCREATOR_H
