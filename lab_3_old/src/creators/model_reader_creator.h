#ifndef MODELREADERCREATOR_H
#define MODELREADERCREATOR_H

#include "project_config.h"
#include "text_file_model_reader.h"

class ModelReaderCreator {
public:
    std::shared_ptr<TextFileModelReader> create(SourceStreamType sourceStreamType);
private:
    void createInstance(SourceStreamType sourceStreamType);
    std::shared_ptr<TextFileModelReader> reader;
};

#endif // MODELREADERCREATOR_H
