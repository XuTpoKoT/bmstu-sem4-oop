#ifndef TRANSFORMMANAGER_H
#define TRANSFORMMANAGER_H

#include "object.h"
#include <base_manager.h>
#include <memory>

class TransformManager : public BaseManager {
public:
    TransformManager() = default;
    TransformManager(const TransformManager&) = delete;

    ~TransformManager() = default;

    TransformManager& operator=(const TransformManager&) = delete;

    static void transform_object(const std::shared_ptr<Object>& object, const Vertice& move, const Vertice& scale, const Vertice& rotate);

    static void move_object(const std::shared_ptr<Object>& object, const double& dx, const double& dy, const double& dz);
    static void scale_object(const std::shared_ptr<Object>& object, const double& kx, const double& ky, const double& kz);
    static void turn_object(const std::shared_ptr<Object>& object, const double& ox, const double& oy, const double& oz);
};

#endif // TRANSFORMMANAGER_H
