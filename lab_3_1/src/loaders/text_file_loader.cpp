#include "text_file_loader.h"

TextFileLoader::~TextFileLoader() {
    close();
}

ModelLoader::ModelLoader(std::shared_ptr<AbstractSourceLoader> loader, std::shared_ptr<BaseModelDirector> director) {
    _loader = loader;
    _director = director;
}

void TextFileLoader::close() {
    _sourceStream.close();
    _sourceStream.clear();
}

bool TextFileLoader::isOpen() const {
    return _sourceStream.is_open();
}

bool readPoint(std::istream &is, Point &point)
{
    double x, y, z;
    if (!(is >> x >> y >> z))
        return false;
    point = Point(x, y, z);
    return true;
}

bool readLink(std::istream &is, Edge &link)
{
    int p1, p2;
    if (!(is >> p1 >> p2))
        return false;
    link = Edge(p1, p2);
    return true;
}

void TextFileLoader::open(std::string sourceName) {
    if (isOpen())
        close();
    time_t t_time = time(NULL);

    _sourceStream.open(sourceName);
    if (!_sourceStream)
        throw OpenStreamError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
}

Vector<Point> TextFileLoader::readPoints() {
    time_t t_time = time(NULL);
    if (!isOpen())
        throw ReadStreamError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    int n_points = 0;
    _sourceStream >> n_points;
    if (n_points < 1)
        throw FileFormatError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    Vector<Point> points(n_points, Point(0, 0, 0));
    for (size_t i = 0; i < n_points; ++i)
        if (!readPoint(_sourceStream, points[i]))
            throw FileFormatError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    return points;
}

Vector<Edge> TextFileLoader::readLinks() {
    time_t t_time = time(NULL);
    if (!isOpen())
        throw ReadStreamError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    int n_links = 0;
    _sourceStream >> n_links;
    if (n_links < 1)
        throw FileFormatError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    Vector<Edge> links(n_links, Edge());
    for (size_t i = 0; i < n_links; ++i)
        if (!(readLink(_sourceStream, links[i])))
            throw FileFormatError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    return links;
}

std::shared_ptr<BaseModel> ModelLoader::loadModel(std::string sourceName)
{
    _loader->open(sourceName);
    const Vector<Point> points = _loader->readPoints();
    const Vector<Edge> links = _loader->readLinks();
    _loader->close();

    CarcassModelDirector director;
    auto model = director.buildModel(points, links);
    return model;
}
