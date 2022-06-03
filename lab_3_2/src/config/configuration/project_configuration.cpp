#include "project_configuration.h"

void ProjectConfiguration::readConfiguration(std::string sourceName) {
    time_t t_time = time(NULL);
    std::ifstream stream;

    stream.open(sourceName);
    if (!stream)
        throw OpenStreamError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));

    readFrameworkType(stream);
    readSourceStreamType(stream);

    stream.close();
}

void ProjectConfiguration::readFrameworkType(std::ifstream &stream) {
    std::string strFrameworkType;
    stream >> strFrameworkType;
    if (strFrameworkType == "QT") {
        frameworkType = FrameworkType::QT;
    } else {
        frameworkType = FrameworkType::QT; // exception
    }
}

void ProjectConfiguration::readSourceStreamType(std::ifstream &stream) {
    std::string strSourceStreamType;
    stream >> strSourceStreamType;
    if (strSourceStreamType == "TXT") {
        sourceStreamType = SourceStreamType::TXT;
    } else {
        sourceStreamType = SourceStreamType::TXT; // exception
    }
}

FrameworkType ProjectConfiguration::getFrameworkType() {
    return frameworkType;
}

SourceStreamType ProjectConfiguration::getSourceStreamType() {
    return sourceStreamType;
}
