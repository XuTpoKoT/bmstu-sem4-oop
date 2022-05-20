#ifndef CAMERACOMMAND_H
#define CAMERACOMMAND_H

#include "base_command.h"
#include <cstdlib>
#include <memory>
#include <string>

using ID = std::shared_ptr<std::size_t>;

class CameraBaseCommand : public BaseCommand {
};

class AddCamera : public CameraBaseCommand {
public:
    AddCamera() = delete;
    AddCamera(const ID& _id, const double x, const double y, const double z);
    ~AddCamera() override = default;

    void execute() override;

private:
    ID _id;
    double _x_pos;
    double _y_pos;
    double _z_pos;
};

class RemoveCamera : public CameraBaseCommand {
public:
    RemoveCamera() = delete;
    explicit RemoveCamera(const size_t& _id);
    ~RemoveCamera() override = default;

    void execute() override;

private:
    size_t _id;
};

class MoveCamera : public CameraBaseCommand {
public:
    MoveCamera() = delete;
    MoveCamera(const std::size_t& _id, const double& shift_ox, const double& shift_oy);
    ~MoveCamera() override = default;

    void execute() override;

private:
    size_t _id;

    double _shift_ox;
    double _shift_oy;
};

class SetCamera : public CameraBaseCommand {
public:
    SetCamera() = delete;
    explicit SetCamera(const size_t& _id);
    ~SetCamera() override = default;

    void execute() override;

private:
    size_t _id;
};

class LoadCamera : public CameraBaseCommand {
public:
    LoadCamera() = delete;
    explicit LoadCamera(std::string fname);

    void execute() override;

private:
    std::string _fname;
};

#endif // CAMERACOMMAND_H
