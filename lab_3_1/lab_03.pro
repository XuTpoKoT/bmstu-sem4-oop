QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++20

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    src/builders/carcass_model_builder.cpp \
    src/builders/carcass_model_director.cpp \
    src/commands/command.cpp \
    src/commands/facade.cpp \
    src/config/configuration/map_configuration.cpp \
    src/config/solutions/drawer_solution.cpp \
    src/config/solutions/loader_solution.cpp \
    src/creators/base_creator.cpp \
    src/creators/camera_creator.cpp \
    src/creators/camera_manager_creator.cpp \
    src/creators/configuration_creator.cpp \
    src/creators/draw_manager_creator.cpp \
    src/creators/facade_creator.cpp \
    src/creators/load_manager_creator.cpp \
    src/creators/model_loader_creator.cpp \
    src/creators/scene_manager_creator.cpp \
    src/creators/transform_manager_creator.cpp \
    src/drawer/qt_drawer.cpp \
    src/drawer/qt_drawer_factory.cpp \
    src/loaders/text_file_loader.cpp \
    src/main.cpp \
    src/mainwindow.cpp \
    src/managers/camera_add_manager.cpp \
    src/managers/draw_manager.cpp \
    src/managers/model_load_manager.cpp \
    src/managers/scene_manager.cpp \
    src/managers/transform_manager.cpp \
    src/objects/base_model.cpp \
    src/objects/base_model_structure.cpp \
    src/objects/camera.cpp \
    src/objects/carcass_model.cpp \
    src/objects/carcass_model_structure.cpp \
    src/objects/composite.cpp \
    src/objects/object.cpp \
    src/scene/scene.cpp \
    src/structures/edge/edge.cpp \
    src/structures/point/point.cpp \
    src/visitors/draw_visitor.cpp

INCLUDEPATH += \
    src/ \
    src/builders \
    src/commands \
    src/config/solutions \
    src/config/configuration \
    src/creators \
    src/drawer \
    src/errors \
    src/loaders \
    src/managers \
    src/objects \
    src/scene \
    src/structures/iterators \
    src/structures/edge \
    src/structures/point \
    src/structures/vector \
    src/visitors

HEADERS += \
    src/builders/base_model_builder.h \
    src/builders/base_model_director.h \
    src/builders/carcass_model_builder.h \
    src/builders/carcass_model_director.h \
    src/commands/command.h \
    src/commands/facade.h \
    src/commands/facade.hpp \
    src/config/configuration/abstract_configuration.h \
    src/config/configuration/map_configuration.h \
    src/config/solutions/drawer_solution.h \
    src/config/solutions/loader_solution.h \
    src/creators/abstract_loader_creator.h \
    src/creators/base_creator.h \
    src/creators/camera_creator.h \
    src/creators/camera_manager_creator.h \
    src/creators/configuration_creator.h \
    src/creators/draw_manager_creator.h \
    src/creators/facade_creator.h \
    src/creators/load_manager_creator.h \
    src/creators/model_loader_creator.h \
    src/creators/scene_manager_creator.h \
    src/creators/transform_manager_creator.h \
    src/drawer/abstract_drawer.h \
    src/drawer/abstract_drawer_factory.h \
    src/drawer/qt_drawer.h \
    src/drawer/qt_drawer_factory.h \
    src/errors/base_error.h \
    src/errors/errors.h \
    src/loaders/abstract_source_loader.h \
    src/loaders/base_model_loader.h \
    src/loaders/text_file_loader.h \
    src/mainwindow.h \
    src/managers/base_manager.h \
    src/managers/camera_add_manager.h \
    src/managers/draw_manager.h \
    src/managers/model_load_manager.h \
    src/managers/scene_manager.h \
    src/managers/transform_manager.h \
    src/objects/base_model.h \
    src/objects/base_model_structure.h \
    src/objects/camera.h \
    src/objects/carcass_model.h \
    src/objects/carcass_model_structure.h \
    src/objects/composite.h \
    src/objects/invisible_object.h \
    src/objects/object.h \
    src/objects/visible_object.h \
    src/scene/scene.h \
    src/structures/edge/edge.h \
    src/structures/iterators/base_iterator.h \
    src/structures/iterators/base_iterator.hpp \
    src/structures/iterators/const_iterator.h \
    src/structures/iterators/const_iterator.hpp \
    src/structures/iterators/iterator.h \
    src/structures/iterators/iterator.hpp \
    src/structures/edge/edge.h \
    src/structures/point/point.h \
    src/structures/vector/vector.h \
    src/visitors/base_visitor.h \
    src/visitors/draw_visitor.h
FORMS += \
    forms/mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    assets/config.txt \
    assets/cube.txt \
    assets/figure2.txt
