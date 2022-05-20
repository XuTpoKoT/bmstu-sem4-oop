#ifndef SCENE_BUILDER_H
#define SCENE_BUILDER_H

#include "base_builder.h"
#include "scene.h"

class SceneBuilder : public BaseBuilder {
public:
    SceneBuilder() = default;
    ~SceneBuilder() = default;

    bool is_build() const override;
    void build() override;
    void build_object(const std::shared_ptr<Object>& object);

    std::shared_ptr<Scene> get();

private:
    std::shared_ptr<Scene> _scene_ptr;
};

#endif // SCENE_BUILDER_H
