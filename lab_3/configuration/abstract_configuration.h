#ifndef ABSTRACT_CONFIGUTAION_H
#define ABSTRACT_CONFIGUTAION_H

#include <memory>
#include <string>

class AbstractConfiguration {
public:
    enum frame_t { QT };

    enum source_t { FILE };

    enum object_t {
        CAMERA,
        MODEL
    };

    explicit AbstractConfiguration(std::shared_ptr<std::string> source = nullptr)
        : _source(std::move(source)) {};

    virtual void read_configuration(std::shared_ptr<std::string> source = nullptr) = 0;

    virtual frame_t get_frame() = 0;

    virtual source_t get_source() = 0;

protected:
    std::shared_ptr<std::string> _source;
};

#endif // ABSTRACT_CONFIGUTAION_H
