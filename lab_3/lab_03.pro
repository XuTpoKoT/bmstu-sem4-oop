QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17
# LIBS += -L$$PWD/libconfig/lib -llibconfig++

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    builder/camera/camera_builder.cpp \
    builder/model/model_builder.cpp \
    builder/scene/scene_builder.cpp \
    commands/model/model_command.cpp \
    commands/scene/scene_command.cpp \
    configuration/configuration_creator/configuration_creator.cpp \
    configuration/libconf/libconf_configuration.cpp \
    drawer/drawer_factory_solution.hpp \
    facade/facade.cpp \
    load_controller/abstract_load_controller.cpp \
    load_controller/camera/camera_load_controller.cpp \
    load_controller/camera/camera_load_controller_creator.cpp \
    load_controller/load_controller_solution.cpp \
    load_controller/model/model_load_controller.cpp \
    load_controller/model/model_load_controller_creator.cpp \
    loader/camera/file_camera_loader.cpp \
    loader/model/file_model_loader.cpp \
    loader/scene/file_scene_loader.cpp \
    main.cpp \
    gui/mainwindow.cpp \
    managers/draw/draw_manager.cpp \
    managers/draw/draw_manager_creator.cpp \
    managers/load/load_manager.cpp \
    managers/load/load_manager_creator.cpp \
    managers/scene/scene_manager.cpp \
    managers/scene/scene_manager_creator.cpp \
    managers/transform/transform_manager.cpp \
    managers/transform/transform_manager_creator.cpp \
    objects/camera/camera.cpp \
    objects/composite/composite.cpp \
    objects/model/base_model.cpp \
    objects/model/model_structure/edge/edge.cpp \
    objects/model/model_structure/model_structure.cpp \
    objects/model/model_structure/vertice/vertice.cpp \
    qt/drawer/qt_drawer.cpp \
    qt/qt_drawer_factory.cpp \
	objects/model/model.cpp \
    scene/scene.cpp \
    visitor/draw_visitor/draw_visitor.cpp \
	commands/camera/camera_command.cpp

HEADERS += \
    builder/base_builder.h \
    builder/camera/camera_builder.h \
    builder/model/model_builder.h \
    builder/scene/scene_builder.h \
    commands/model/model_command.h \
    commands/scene/scene_command.h \
    configuration/abstract_configuration.h \
    configuration/configuration_creator/configuration_creator.h \
    configuration/libconf/libconf_configuration.h \
    drawer/abstract_drawer.h \
    drawer/abstract_drawer_factory.h \
    drawer/drawer_factory_solution.h \
    errors/errors.h \
    facade/facade.h \
    gui/mainwindow.h \
    load_controller/abstract_load_controller.h \
    load_controller/camera/camera_load_controller.h \
    load_controller/camera/camera_load_controller_creator.h \
    load_controller/load_controller_solution.h \
    load_controller/model/model_load_controller.h \
    load_controller/model/model_load_controller_creator.h \
    loader/base_loader.h \
    loader/camera/base_camera_loader.h \
    loader/camera/file_camera_loader.h \
    loader/model/base_model_loader.h \
    loader/model/file_model_loader.h \
    loader/scene/base_scene_loader.h \
    loader/scene/file_scene_loader.h \
    managers/base_manager.h \
    managers/draw/draw_manager.h \
    managers/draw/draw_manager_creator.h \
    managers/load/load_manager.h \
    managers/load/load_manager_creator.h \
    managers/scene/scene_manager.h \
    managers/scene/scene_manager_creator.h \
    managers/transform/transform_manager.h \
    managers/transform/transform_manager_creator.h \
    objects/camera/camera.h \
    objects/composite/composite.h \
    objects/model/base_model.h \
    objects/model/model_structure/edge/edge.h \
    objects/model/model_structure/model_structure.h \
    objects/model/model_structure/vertice/vertice.h \
    objects/object.h \
    qt/drawer/qt_drawer.h \
    qt/qt_drawer_factory.h \
    scene/scene.h \
    visitor/draw_visitor/draw_visitor.h \
    visitor/visitor.h \
	objects/model/model.h \
	commands/base_command.h \
	commands/camera/camera_command.h

FORMS += \
    gui/mainwindow.ui

INCLUDEPATH += gui configuration \ 
			   objects/model/model_structure/edge \
			   objects/model/model_structure/vertice \
			   visitor drawer qt/drawer \
			   objects \
			   objects/model/model_structure \
			   managers \
			   objects/composite \
			   objects/model \
			   managers/draw \
			   objects/camera \
			   scene \
			   loader \
			   builder \ 
			   builder/scene \
			   builder/camera \
			   builder/model \
			   errors \
			   loader/camera \
			   loader/scene \
			   loader/model \
			   visitor/draw_visitor \
			   load_controller \
			   configuration/libconf \
			   configuration/configuration_creator \
			   load_controller/model \
			   load_controller/camera \
			   commands \
			   commands/camera \
			   commands/model \
			   commands/scene \
			   managers/scene \
			   managers/camera \
			   managers/transform \
			   managers/load \
			   load_controller/camera \
			   facade \
			   qt \
			   drawer

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
