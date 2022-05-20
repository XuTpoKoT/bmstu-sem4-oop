#ifndef QTDRAWER_H
#define QTDRAWER_H

#include <abstract_drawer.h>

#include <QGraphicsScene>

class QtDrawer : public AbstractDrawer {
public:
    QtDrawer() = delete;
    explicit QtDrawer(QGraphicsScene* scene);
    QtDrawer(const QtDrawer& drawer);

    void draw_line(const Vertice& v1, const Vertice& v2) override;
    void clear_scene() override;

private:
    QGraphicsScene* _scene;
};

#endif // QTDRAWER_H
