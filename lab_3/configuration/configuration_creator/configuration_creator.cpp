#include "configuration_creator.h"
#include "libconf_configuration.h"

std::shared_ptr<AbstractConfiguration> ConfigurationCreator::get_configuration(std::shared_ptr<std::string> source)
{
    if (!_cfg)
        create_instance(source);
    else if (source)
        _cfg->read_configuration(source);

    return _cfg;
}

void ConfigurationCreator::create_instance(std::shared_ptr<std::string>& source)
{
    static std::shared_ptr<AbstractConfiguration> cfg(new LibconfConfiguration(source));

    _cfg = cfg;
}
