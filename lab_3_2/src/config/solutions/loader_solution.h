#pragma once

#include "base_model_loader_creator.h"
#include "configuration_creator.h"
#include "base_model_director.h"
#include "base_model_loader.h"

#include "text_file_model_reader.h"
#include "model_director.h"
#include "carcass_model_loader_creator.h"

class LoaderSolution {
public:
    typedef std::shared_ptr<BaseModelLoader> (BaseModelLoaderCreator::*createSomeLoader)();
    using LoaderCreatorMap = std::map<std::string, createSomeLoader>;
    LoaderSolution();
    virtual ~LoaderSolution() = default;
    std::shared_ptr<BaseModelLoader> createLoader(BaseModelLoaderCreator *creator);
    bool isConfigured(std::string loaderKey);
    void configure(std::string loaderKey, createSomeLoader callback);
private:
    std::shared_ptr<AbstractConfiguration> _configuration;
    std::string loaderSource;
    LoaderCreatorMap _creatorMap;
};
