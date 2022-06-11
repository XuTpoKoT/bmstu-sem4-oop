#include "model_load_manager.h"

void ModelLoadManager::setModelReader(std::shared_ptr<TextFileModelReader> reader) {
    this->reader = reader;
}

BaseModel ModelLoadManager::loadModel(std::string sourceName) {
    reader->open(sourceName);
    std::vector<Point> points = reader->readPoints();
    std::vector<Edge> edges = reader->readEdges();
    reader->close();

    CarcassModelBuilder builder;
    ModelDirector director = ModelDirector(std::make_shared<CarcassModelBuilder>(builder));
    return director.buildModel(points, edges);
}


