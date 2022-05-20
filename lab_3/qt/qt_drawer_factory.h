#ifndef QTDRAWERFACTORY_H
#define QTDRAWERFACTORY_H

#include "abstract_configuration.h"
#include "qt_drawer.h"
#include <abstract_drawer_factory.h>

class QtDrawerFactory : public AbstractDrawerFactory {
public:
    explicit QtDrawerFactory(QGraphicsScene* scene);

    std::unique_ptr<AbstractDrawer> create_drawer() override;

private:
    QGraphicsScene* _scene;
};

#endif // QTDRAWERFACTORY_H
