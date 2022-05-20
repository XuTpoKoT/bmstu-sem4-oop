#include "file_scene_loader.h"
#include "errors.h"
#include "file_camera_loader.h"
#include "file_model_loader.h"
#include "model_builder.h"
#include "scene_builder.h"
#include <fstream>

Load::FileSceneLoader::FileSceneLoader()
    : _file(std::make_shared<std::ifstream>())
{
}

std::shared_ptr<Scene> Load::FileSceneLoader::load(const std::shared_ptr<SceneBuilder>& builder)
{
    builder->build();

    load_models(builder);

    load_cameras(builder);

    return builder->get();
}

void Load::FileSceneLoader::open(std::string& fname)
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

void Load::FileSceneLoader::close()
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

void Load::FileSceneLoader::load_models(std::shared_ptr<SceneBuilder> builder)
{
    std::size_t models_count;
    *_file >> models_count;

    auto m_builder = std::make_shared<ModelBuilder>();
    for (size_t i = 0; i < models_count; ++i)
        builder->build_object(FileModelLoader(_file).load(m_builder));
}

void Load::FileSceneLoader::load_cameras(std::shared_ptr<SceneBuilder> builder)
{
    std::size_t cameras_count;
    *_file >> cameras_count;

    auto c_builder = std::make_shared<CameraBuilder>();
    for (size_t i = 0; i < cameras_count; ++i) {
        auto camera = std::dynamic_pointer_cast<Camera>(FileCameraLoader(_file).load(c_builder));
        builder->build_object(camera);
    }
}
