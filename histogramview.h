#ifndef HISTOGRAMVIEW_H
#define HISTOGRAMVIEW_H
#include <QObject>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include "histopram.h"
class histogramview : public QGraphicsView
{
public:
    histogramview();
private:
    QGraphicsScene *m_scene_ptr;
    Histopram *histopram;
};

#endif // HISTOGRAMVIEW_H
