#pragma once

#include <fstream>
#include <istream>
#include "object.h"
#include "base_model_loader.h"
#include "abstract_source_loader.h"
#include "vector.h"
#include "carcass_model_director.h"

class TextFileLoader: public AbstractSourceLoader {
public:
    ~TextFileLoader();
    Vector<Point> readPoints() override;
    Vector<Edge> readLinks() override;
    bool isOpen() const override;
    void open(std::string) override;
    void close() override;
private:
    std::ifstream _sourceStream;
};

class ModelLoader: public BaseModelLoader {
public:
    ModelLoader(std::shared_ptr<AbstractSourceLoader> loader, std::shared_ptr<BaseModelDirector> director);
    ~ModelLoader() = default;
    std::shared_ptr<BaseModel> loadModel(std::string sourceName) override;
private:
    std::shared_ptr<BaseModelDirector> _director;
};
