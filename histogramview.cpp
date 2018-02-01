#include "histogramview.h"

histogramview::histogramview()
{
    m_scene_ptr = new QGraphicsScene();
    m_scene_ptr->setSceneRect(0,0, 500, 500);
    this->setScene(m_scene_ptr);
//    QPalette palette;
//    palette.setBrush(this->backgroundRole(), QColor("#0066FF"));
//    this->setPalette(palette);
    QPixmap pixmap = QPixmap("/home/cuizhou/Works/Histopramdemo/image/bg.png").scaled(this->size());
    QPalette palette(this->palette());
    palette.setBrush(this->backgroundRole(), QBrush(pixmap));
    this->setPalette(palette);
    histopram = new Histopram();
    m_scene_ptr->addItem(histopram);
}
