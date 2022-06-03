#include "model_load_manager.h"

void ModelLoadManager::setModelReader(std::shared_ptr<AbstractSourceModelReader> reader) {
    this->reader = reader;
}

BaseModel ModelLoadManager::loadModel(std::string sourceName) {
    reader->open(sourceName);
    std::vector<Point> points = reader->readPoints();
    std::vector<Edge> edges = reader->readEdges();
    reader->close();

    ModelDirector director = ModelDirector(std::make_shared<BaseModelBuilder>(CarcassModelBuilder()));
    return director.buildModel(points, edges);
}
