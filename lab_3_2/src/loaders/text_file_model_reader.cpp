#include "text_file_model_reader.h"

TextFileModelReader::~TextFileModelReader() {
    close();
}

void TextFileModelReader::open(std::string sourceName) {
    if (isOpen())
        close();
    time_t t_time = time(NULL);

    sourceStream.open(sourceName);
    if (!sourceStream)
        throw OpenStreamError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
}

void TextFileModelReader::close() {
    sourceStream.close();
    sourceStream.clear();
}

bool TextFileModelReader::isOpen() const {
    return sourceStream.is_open();
}

ModelType TextFileModelReader::readModelType()
{
    time_t t_time = time(NULL);
    if (!isOpen())
        throw ReadStreamError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    std::string strType;
    sourceStream >> strType;
    if (strType == "carcass")
        return ModelType::Carcass;
    // throw ReadStreamError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    return ModelType::Carcass;
}

bool readPoint(std::istream &stream, Point &point)
{
    double x, y, z;
    if (!(stream >> x >> y >> z))
        return false;
    point = Point(x, y, z);
    return true;
}

bool readEdge(std::istream &stream, Edge &edge)
{
    int p1, p2;
    if (!(stream >> p1 >> p2))
        return false;
    edge = Edge(p1, p2);
    return true;
}

std::vector<Point> TextFileModelReader::readPoints() {
    time_t t_time = time(NULL);
    if (!isOpen())
        throw ReadStreamError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    int n_points = 0;
    sourceStream >> n_points;
    if (n_points < 1)
        throw FileFormatError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    std::vector<Point> points(n_points, Point(0, 0, 0));
    for (size_t i = 0; i < n_points; ++i)
        if (!readPoint(sourceStream, points[i]))
            throw FileFormatError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    return points;
}

std::vector<Edge> TextFileModelReader::readEdges() {
    time_t t_time = time(NULL);
    if (!isOpen())
        throw ReadStreamError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    int n_edges = 0;
    sourceStream >> n_edges;
    if (n_edges < 1)
        throw FileFormatError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    std::vector<Edge> edges(n_edges, Edge());
    for (size_t i = 0; i < n_edges; ++i)
        if (!(readEdge(sourceStream, edges[i])))
            throw FileFormatError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    return edges;
}


