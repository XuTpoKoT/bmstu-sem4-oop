#ifndef FILEMODELLOADER_H
#define FILEMODELLOADER_H

#include "base_model_loader.h"

namespace Load {
class FileModelLoader : public BaseModelLoader {
public:
    FileModelLoader();
    explicit FileModelLoader(std::shared_ptr<std::ifstream>& fin);
    ~FileModelLoader() override = default;
    std::shared_ptr<Model> load(std::shared_ptr<ModelBuilder> builder) override;
    void open(std::string& fname) override;
    void close() override;

protected:
    std::shared_ptr<std::ifstream> _file;
};
} // namespace Load

#endif // FILEMODELLOADER_H
