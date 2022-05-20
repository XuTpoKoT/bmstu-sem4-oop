#ifndef BASE_CAMERA_LOADER_H
#define BASE_CAMERA_LOADER_H

#include "base_loader.h"
#include "camera_builder.h"

namespace Load {
class BaseCameraLoader : public BaseLoader {
public:
    virtual std::shared_ptr<Object> load(const std::shared_ptr<CameraBuilder>& builder) = 0;
};
} // namespace Load

#endif // BASE_CAMERA_LOADER_H
