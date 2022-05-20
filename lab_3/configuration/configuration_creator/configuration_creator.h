#ifndef CONFIGURATIONCREATOR_H
#define CONFIGURATIONCREATOR_H

#include "abstract_configuration.h"

class ConfigurationCreator {
public:
    std::shared_ptr<AbstractConfiguration> get_configuration(std::shared_ptr<std::string> source = nullptr);

private:
    void create_instance(std::shared_ptr<std::string>& source);

    std::shared_ptr<AbstractConfiguration> _cfg;
};

#endif // CONFIGURATIONCREATOR_H
