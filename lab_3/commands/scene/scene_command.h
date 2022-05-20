#ifndef SCENECOMMAND_H
#define SCENECOMMAND_H

#include "abstract_drawer.h"
#include "base_command.h"
#include <memory>
#include <string>

class SceneBaseCommand : public BaseCommand {
};

class DrawScene : public SceneBaseCommand {
public:
    DrawScene() = delete;
    explicit DrawScene(std::shared_ptr<AbstractDrawer> drawer);
    ~DrawScene() override = default;

    void execute() override;

private:
    std::shared_ptr<AbstractDrawer> _drawer;
};

#endif // SCENECOMMAND_H
