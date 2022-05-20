#include "transform_manager.h"

void TransformManager::transform_object(const std::shared_ptr<Object>& object, const Vertice& move, const Vertice& scale, const Vertice& rotate)
{
    object->transform(move, scale, rotate);
}

void TransformManager::move_object(const std::shared_ptr<Object>& object, const double& dx, const double& dy, const double& dz)
{
    Vertice move(dx, dy, dz);
    Vertice scale(1, 1, 1);
    Vertice turn(0, 0, 0);

    object->transform(move, scale, turn);
}

void TransformManager::scale_object(const std::shared_ptr<Object>& object, const double& kx, const double& ky, const double& kz)
{
    Vertice move(0, 0, 0);
    Vertice scale(kx, ky, kz);
    Vertice turn(0, 0, 0);

    object->transform(move, scale, turn);
}

void TransformManager::turn_object(const std::shared_ptr<Object>& object, const double& ox, const double& oy, const double& oz)
{
    Vertice move(0, 0, 0);
    Vertice scale(1, 1, 1);
    Vertice turn(ox, oy, oz);

    object->transform(move, scale, turn);
}
