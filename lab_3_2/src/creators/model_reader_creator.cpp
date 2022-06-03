#include "model_reader_creator.h"

std::shared_ptr<AbstractSourceModelReader> ModelReaderCreator::create(SourceStreamType sourceStreamType) {
    if (reader == nullptr)
        createInstance(sourceStreamType);;
    return reader;
}

void ModelReaderCreator::createInstance(SourceStreamType sourceStreamType) {
    switch (sourceStreamType) {
    case SourceStreamType::TXT:
    default:
        reader = std::make_shared<AbstractSourceModelReader>(TextFileModelReader());
    }
}
