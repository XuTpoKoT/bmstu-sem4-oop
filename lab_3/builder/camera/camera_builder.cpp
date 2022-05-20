#include "camera_builder.h"

bool CameraBuilder::is_build() const
{
    return _camera_ptr != nullptr;
}
void CameraBuilder::build()
{
    _camera_ptr = std::make_shared<Camera>();
}

void CameraBuilder::build_position(double x, double y, double z)
{
}

std::shared_ptr<Camera> CameraBuilder::get()
{
    return _camera_ptr;
}
