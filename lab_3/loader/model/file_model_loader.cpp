#include "file_model_loader.h"
#include "errors.h"
#include "model_builder.h"
#include <fstream>

Load::FileModelLoader::FileModelLoader()
    : _file(std::make_shared<std::ifstream>())
{
}

Load::FileModelLoader::FileModelLoader(std::shared_ptr<std::ifstream>& fin)
    : _file(fin)
{
}

std::shared_ptr<Model> Load::FileModelLoader::load(std::shared_ptr<ModelBuilder> builder)
{
    builder->build();

    std::size_t points_count;
    *_file >> points_count;

    for (std::size_t i = 0; i < points_count; i++) {
        double x, y, z;
        *_file >> x >> y >> z;
        builder->build_point(x, y, z);
    }

    std::size_t links_count;
    *_file >> links_count;

    for (std::size_t i = 0; i < links_count; i++) {
        std::size_t pt1, pt2;
        *_file >> pt1 >> pt2;
        builder->build_edge(pt1, pt2);
    }

    return builder->get();
}

void Load::FileModelLoader::open(std::string& fname)
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

void Load::FileModelLoader::close()
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
