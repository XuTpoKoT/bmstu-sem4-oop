#pragma once

#include <fstream>
#include <istream>
#include <vector>

#include "abstract_source_model_reader.h"
#include "errors.h"
#include "object.h"

class TextFileModelReader: public AbstractSourceModelReader {
public:
    TextFileModelReader();
    ~TextFileModelReader() override;
    void open(std::string) override;
    void close() override;
    bool isOpen() const override;
    virtual ModelType readModelType() override;
    std::vector<Point> readPoints() override;
    std::vector<Edge> readEdges() override;
private:
    std::ifstream sourceStream;
};


