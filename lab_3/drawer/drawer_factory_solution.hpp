#include "configuration_creator.h"
#include "qt_drawer_factory.h"

template <typename SceneType>
DrawerFactorySolution<SceneType>::DrawerFactorySolution()
    : _configuration(ConfigurationCreator().get_configuration())
{
}

template <typename SceneType>
std::shared_ptr<AbstractDrawerFactory> DrawerFactorySolution<SceneType>::create_factory(SceneType* scene)
{
    auto frame = _configuration->get_frame();
    switch (frame) {
    case AbstractConfiguration::QT:
    default:
        std::shared_ptr<QtDrawerFactory> factory(new QtDrawerFactory(scene));
        return factory;
    }
}
