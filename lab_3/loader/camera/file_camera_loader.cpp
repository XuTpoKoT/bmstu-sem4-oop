#include "file_camera_loader.h"
#include "errors.h"
#include "scene_builder.h"
#include <fstream>

Load::FileCameraLoader::FileCameraLoader()
    : _file(std::make_shared<std::ifstream>())
{
}

Load::FileCameraLoader::FileCameraLoader(const std::shared_ptr<std::ifstream>& fin)
    : _file(fin)
{
}

std::shared_ptr<Object> Load::FileCameraLoader::load(const std::shared_ptr<CameraBuilder>& builder)
{
    builder->build();

    double x, y, z;
    *_file >> x >> y >> z;

    builder->build_position(x, y, z);

    return builder->get();
}

void Load::FileCameraLoader::open(std::string& fname)
{
    if (!_file) {
        std::string message = "Error while open file.";
        throw FileError(message);
    }
    _file->open(fname);

    if (!_file) {
        std::string message = "Error while open file.";
        throw FileError(message);
    }
}

void Load::FileCameraLoader::close()
{
    if (!_file) {
        std::string message = "Error while open file.";
        throw FileError(message);
    }

    try {
        _file->close();
    } catch (std::ifstream::failure& error) {
        error.what();
    }
}
