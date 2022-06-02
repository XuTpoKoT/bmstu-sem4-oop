#pragma once

template<typename Manager>
void Facade::runCommand(BaseCommand<Manager> &command, std::string managerKey) {
    auto id = command.getId();
    auto compositeId = command.getCompositeId();
    std::shared_ptr<std::shared_ptr<Object>> objPointer = nullptr;
    if (id) {
       auto iter = _scene->getObject(*id);
       std::shared_ptr<Object> obj = (*id == -1) ? nullptr : *iter;
       objPointer = std::make_shared<std::shared_ptr<Object>>(obj);
    }
    command.run(objPointer, std::dynamic_pointer_cast<Manager>(_managersMap.find(managerKey)->second));
    if (id) {
       command.setId((*objPointer)->getId());
       if (managerKey == MODEL_LOAD_MANAGER || managerKey == CAMERA_ADD_MANAGER)
           _scene->addObject(compositeId, *objPointer);
    }
}
