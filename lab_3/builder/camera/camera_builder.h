#ifndef CAMERABUILDER_H
#define CAMERABUILDER_H

#include "base_builder.h"

#include "camera.h"

class CameraBuilder : public BaseBuilder {
public:
    CameraBuilder() = default;
    ~CameraBuilder() = default;

    bool is_build() const override;
    void build() override;
    void build_position(double x, double y, double z);

    std::shared_ptr<Camera> get();

private:
    std::shared_ptr<Camera> _camera_ptr;
};

#endif // CAMERABUILDER_H
