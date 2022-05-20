#ifndef BASEBUILDERCONTROLLER_H
#define BASEBUILDERCONTROLLER_H

#include <base_builder.h>
#include <memory>

class BaseBuilderController {
public:
    BaseBuilderController();
    ~BaseBuilderController();
    void build();

private:
    std::shared_ptr<BaseBuilder> _builder;
};

#endif // BASEBUILDERCONTROLLER_H
