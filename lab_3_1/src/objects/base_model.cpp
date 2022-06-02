#include "base_model.h"

BaseModel::BaseModel(const MoveParams &moveParams, const RotateParams &rotateParams, const ScaleParams &scaleParams, std::shared_ptr<BaseModelStructure> impl):
    VisibleObject(moveParams, rotateParams, scaleParams),
    structure(impl)
{};

BaseModel::BaseModel(std::shared_ptr<BaseModelStructure> impl):
    VisibleObject(),
    structure(impl)
{};

BaseModel::BaseModel(const BaseModel &other) {
    moveParams = other.moveParams;
    rotateParams = other.rotateParams;
    scaleParams = other.scaleParams;
    structure = other.structure;
}

BaseModel::BaseModel(BaseModel &&other) noexcept {
    moveParams = other.moveParams;
    rotateParams = other.rotateParams;
    scaleParams = other.scaleParams;
    structure = other.structure;
    other.~BaseModel();
}

void BaseModel::accept(std::shared_ptr<BaseVisitor> visitor) {
    visitor->visit(*this);
}
