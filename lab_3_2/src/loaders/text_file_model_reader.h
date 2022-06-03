#pragma once

#include <fstream>
#include <istream>
#include "object.h"
#include "abstract_source_model_reader.h"
#include <vector>
#include "model_director.h"

class TextFileModelReader: public AbstractSourceModelReader {
public:
    ~TextFileModelReader();
    void open(std::string) override;
    void close() override;
    bool isOpen() const override;
    virtual ModelType readModelType() override;
    std::vector<Point> readPoints() override;
    std::vector<Edge> readEdges() override;
private:
    std::ifstream sourceStream;
};


