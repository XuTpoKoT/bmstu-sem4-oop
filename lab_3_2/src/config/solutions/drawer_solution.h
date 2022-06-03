#pragma once

#include "qt_drawer_factory.h"
#include "text_file_model_reader.h"
#include "model_director.h"
#include <QGraphicsScene>
#include "errors.h"
#include "configuration_creator.h"
#include <map>

class MainWindow;

class DrawerSolution {
public:
    typedef std::shared_ptr<AbstractDrawerFactory> (MainWindow::*createDrawerFactory)();
    using DrawerFactoryMap = std::map<std::string, createDrawerFactory>;
    DrawerSolution();
    ~DrawerSolution() = default;
    std::shared_ptr<AbstractDrawerFactory> createFactory(MainWindow *mainWindow);
    void configure(std::string framework, createDrawerFactory callback);
    bool isConfigured(std::string framework);
private:
    DrawerFactoryMap _factoryMap;
    std::shared_ptr<AbstractConfiguration> _configuration;
};
