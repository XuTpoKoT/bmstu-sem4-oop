#ifndef FILECAMERALOADER_H
#define FILECAMERALOADER_H

#include "base_camera_loader.h"
#include "camera_builder.h"

namespace Load {
class FileCameraLoader : public BaseCameraLoader {
public:
    FileCameraLoader();
    explicit FileCameraLoader(const std::shared_ptr<std::ifstream>& fin);
    ~FileCameraLoader() override = default;
    std::shared_ptr<Object> load(const std::shared_ptr<CameraBuilder>& builder) override;

    void open(std::string& fname) override;
    void close() override;

protected:
    std::shared_ptr<std::ifstream> _file;
};
} // namespace Load

#endif // FILECAMERALOADER_H
