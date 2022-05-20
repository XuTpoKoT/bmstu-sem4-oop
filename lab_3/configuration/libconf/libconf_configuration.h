#ifndef LIBCONFCONFIGURATION_H
#define LIBCONFCONFIGURATION_H

#include "abstract_configuration.h"
// #include <libconfig.h>

#define DEFAULT_FILE "../lab_03/driver.cfg"

class LibconfConfiguration : public AbstractConfiguration {
public:
    explicit LibconfConfiguration(std::shared_ptr<std::string>& source);

    void read_configuration(std::shared_ptr<std::string> source = nullptr) override;

    AbstractConfiguration::frame_t get_frame() override;

    AbstractConfiguration::source_t get_source() override;

//private:
//    std::shared_ptr<libconfig::Config> _cfg;
};

#endif // LIBCONFCONFIGURATION_H
