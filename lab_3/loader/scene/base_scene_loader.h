#ifndef BASE_SCENE_LOADER_H
#define BASE_SCENE_LOADER_H

#include "base_loader.h"
#include "scene_builder.h"
#include <memory>

namespace Load {
class BaseSceneLoader : public BaseLoader {
public:
    virtual std::shared_ptr<Scene> load(const std::shared_ptr<SceneBuilder>& builder) = 0;

protected:
    virtual void load_models(std::shared_ptr<SceneBuilder> builder) = 0;
    virtual void load_cameras(std::shared_ptr<SceneBuilder> builder) = 0;
};
} // namespace Load

#endif // BASE_SCENE_LOADER_H
