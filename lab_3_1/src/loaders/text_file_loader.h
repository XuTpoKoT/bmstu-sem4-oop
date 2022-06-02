#pragma once

#include <fstream>
#include <istream>
#include "object.h"
#include "abstract_loader.h"
#include "base_loader.h"
#include "vector.h"
#include "model_director.h"

class TextFileLoader: public BaseLoader {
public:
    ~TextFileLoader();
    Vector<Point<double>> readPoints() override;
    Vector<Link<int>> readLinks() override;
    bool isOpen() const override;
    void open(std::string) override;
    void close() override;
private:
    std::ifstream _sourceStream;
};

class ModelLoader: public AbstractLoader {
public:
    ModelLoader(std::shared_ptr<BaseLoader> loader, std::shared_ptr<BaseModelDirector> director);
    ~ModelLoader() = default;
    std::shared_ptr<BaseModel> loadModel(std::string sourceName) override;
private:
    std::shared_ptr<BaseModelDirector> _director;
};
