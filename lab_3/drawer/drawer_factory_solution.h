#ifndef DRAWERFACTORYSOLUTION_H
#define DRAWERFACTORYSOLUTION_H

#include "abstract_configuration.h"
#include "abstract_drawer.h"
#include "abstract_drawer_factory.h"

template <typename SceneType>
class DrawerFactorySolution {
public:
    DrawerFactorySolution();

    std::shared_ptr<AbstractDrawerFactory> create_factory(SceneType* scene);

private:
    std::shared_ptr<AbstractConfiguration> _configuration;
};

#include "drawer_factory_solution.hpp"

#endif // DRAWERFACTORYSOLUTION_H
