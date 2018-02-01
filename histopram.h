#ifndef HISTOPRAM_H
#define HISTOPRAM_H

#include <QObject>
#include<QPainter>
#include <QGraphicsItem>
#include <QPixmap>
class Histopram : public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit Histopram(QObject *parent = nullptr);

signals:

public slots:
private:
    QPixmap *m_pixmap;
    QPainter *m_painter;

    QPoint m_x_axis_left;
    QPoint m_x_axis_right;
    QPoint m_y_axis_top;
    QPoint m_y_axis_bottom;
    int m_num_part;
    int m_rect_width;
//    std::vector<int> m_part_begin_points;
    bool m_draw_finished;
};

#endif // HISTOPRAM_H
