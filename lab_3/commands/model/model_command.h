#ifndef MODELCOMMAND_H
#define MODELCOMMAND_H

#include "base_command.h"
#include "object.h"
#include <string>

using ID = std::shared_ptr<std::size_t>;

class ModelBaseCommand : public BaseCommand {
};

class MoveModel : public ModelBaseCommand {
public:
    MoveModel() = delete;
    MoveModel(const double& dx, const double& dy, const double& dz, const std::size_t& _id);
    ~MoveModel() override = default;

    void execute() override;

private:
    size_t _id;

    double _dx, _dy, _dz;
};

class ScaleModel : public ModelBaseCommand {
public:
    ScaleModel() = delete;
    ScaleModel(const double& kx, const double& ky, const double& kz, const std::size_t& _id);
    ~ScaleModel() override = default;

    void execute() override;

private:
    size_t _id;

    double _kx, _ky, _kz;
};

class RotateModel : public ModelBaseCommand {
public:
    RotateModel() = delete;
    RotateModel(const double& ox, const double& oy, const double& oz, const std::size_t& _id);
    ~RotateModel() override = default;

    void execute() override;

private:
    size_t _id;

    double _ox, _oy, _oz;
};

class TransformModel : public ModelBaseCommand {
public:
    TransformModel() = delete;
    TransformModel(const std::size_t& _id, const Vertice& move, const Vertice& scale, const Vertice& rotate);
    ~TransformModel() override = default;

    void execute() override;

private:
    size_t _id;

    Vertice _move, _scale, _rotate;
};

class LoadModel : public ModelBaseCommand {
public:
    LoadModel() = delete;
    explicit LoadModel(const ID& _id, std::string fname);
    ~LoadModel() override = default;

    void execute() override;

private:
    ID _id;
    std::string fname;
};

class ExportModel : public ModelBaseCommand {
public:
    ExportModel() = delete;
    explicit ExportModel(std::string fname);
    ~ExportModel() override = default;

    void execute() override;

private:
    std::string fname;
};

class AddModel : public ModelBaseCommand {
public:
    AddModel() = delete;
    explicit AddModel(std::shared_ptr<Object> model);
    ~AddModel() override = default;

    void execute() override;

private:
    std::shared_ptr<Object> model;
    ID _id;
};

class RemoveModel : public ModelBaseCommand {
public:
    RemoveModel() = delete;
    explicit RemoveModel(const size_t& _id);
    ~RemoveModel() override = default;

    void execute() override;

private:
    size_t _id;
};

#endif // MODELCOMMAND_H
