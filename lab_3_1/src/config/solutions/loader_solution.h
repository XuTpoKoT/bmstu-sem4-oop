#pragma once

#include "abstract_loader_creator.h"
#include "configuration_creator.h"
#include "base_model_director.h"

#include "text_file_loader.h"
#include "model_director.h"
#include "model_loader_creator.h"

class LoaderSolution {
public:
    typedef std::shared_ptr<AbstractLoader> (AbstractLoaderCreator::*createSomeLoader)();
    using LoaderCreatorMap = std::map<std::string, createSomeLoader>;
    LoaderSolution();
    virtual ~LoaderSolution() = default;
    std::shared_ptr<AbstractLoader> createLoader(AbstractLoaderCreator *creator);
    bool isConfigured(std::string loaderKey);
    void configure(std::string loaderKey, createSomeLoader callback);
private:
    std::shared_ptr<AbstractConfiguration> _configuration;
    LoaderCreatorMap _creatorMap;
};
