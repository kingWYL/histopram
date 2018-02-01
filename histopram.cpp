#include "histopram.h"
#include<QtGui>
#define PI 3.1415926
Histopram::Histopram(QObject *parent) : QObject(parent)
{
    m_pixmap = new QPixmap(500, 500);
    m_pixmap->fill(Qt::transparent);

    m_painter = new QPainter(m_pixmap);
    m_painter->translate(30,400);

    m_painter->setPen(Qt::black);
    m_x_axis_left = QPoint(-20, 0);
    m_x_axis_right = QPoint(400, 0);
    m_y_axis_bottom = QPoint(0, 20);
    m_y_axis_top = QPoint(0, -320);


    m_painter->drawLine(m_y_axis_bottom, m_y_axis_top);
    m_painter->drawLine(m_x_axis_left, m_x_axis_right);

    // paint axis arrow
    int arrow_length = 15;
    int arrow_angle = 20;
    int arrow_dist_short = arrow_length * sin(arrow_angle*PI/180);
    int arrow_dist_long = arrow_length * cos(arrow_angle*PI/180);

    QPoint arrow_y1(m_y_axis_top.x() - arrow_dist_short, m_y_axis_top.y() + arrow_dist_long);
    m_painter->drawLine(m_y_axis_top, arrow_y1);
    QPoint arrow_y2(m_y_axis_top.x() + arrow_dist_short, m_y_axis_top.y() + arrow_dist_long);
    m_painter->drawLine(m_y_axis_top, arrow_y2);

    QPoint arrow_x1(m_x_axis_right.x() - arrow_dist_long, m_x_axis_right.y() - arrow_dist_short);
    m_painter->drawLine(m_x_axis_right, arrow_x1);
    QPoint arrow_x2(m_x_axis_right.x() - arrow_dist_long, m_x_axis_right.y() + arrow_dist_short);
    m_painter->drawLine(m_x_axis_right, arrow_x2);


    m_painter->save();
    QFont font;
    font.setPointSize(10);
    font.setBold(true);
    m_painter->setFont(font);
    int axis_label_width = 30;
    m_painter->drawText(m_x_axis_right.x() - axis_label_width/2, m_x_axis_right.y()+axis_label_width/1.5, "商品");
    m_painter->drawText(axis_label_width/4, m_y_axis_top.y() + axis_label_width/2, tr("数量"));

    // paint scale
    font.setPointSize(10);
    font.setBold(false);
    m_painter->setFont(font);
    int y_scale = 0;
    int y_scale_add = -m_y_axis_top.y()/8;
    int num = 0;
    for(int i=0;i<8;i++)
    {
        if(num==0)
        {
            m_painter->drawText(m_y_axis_bottom.x()-10,m_y_axis_bottom.y()-5-y_scale,QString::number(num));
            m_painter->drawLine(m_y_axis_bottom.x(),m_y_axis_bottom.y()-20-y_scale,m_y_axis_bottom.x()+10,m_y_axis_bottom.y()-20-y_scale);
        }
        else
        {
            m_painter->drawText(m_y_axis_bottom.x()-20,m_y_axis_bottom.y()-15-y_scale,QString::number(num));

            m_painter->drawLine(m_y_axis_bottom.x(),m_y_axis_bottom.y()-20-y_scale,m_y_axis_bottom.x()+10,m_y_axis_bottom.y()-20-y_scale);
        }
        y_scale = y_scale_add + y_scale;
        num=num+10;
    }

    // paint grid
    m_painter->setPen(QPen(QColor(0, 160, 230,50), 1));
    int line_step = 40;
    int y_line_num = m_x_axis_right.x()/line_step;
    int x_line_num = -m_y_axis_top.y()/line_step;
    for(int i = 1;i < y_line_num;i++)
    {
        m_painter->drawLine(line_step*i,-320,line_step*i,0);
    }
    for(int i = 1;i < x_line_num;i++)
    {
        m_painter->drawLine(0,-line_step*i,400,-line_step*i);
    }

    // paint histogram
    m_painter->setPen(Qt::black);
    QVector<QString> labels;
    QVector<double> values(5);
    int x_scale = m_x_axis_right.x()/6;
    int Histopram_width = 40;
    labels <<"红\n烧\n牛\n肉"<<"合\n味\n道"<<"汤\n达\n人"<<"茶\nπ"<<"香\n飘\n飘";
    values[0]=25;
    values[1]=23;
    values[2]=12;
    values[3]=8;
    values[4]=20;
    for(int i=0;i<values.length();i++)
    {
        m_painter->drawText(QRect(x_scale*(i+1)-5,10,15,100),labels[i]);
        m_painter->drawText(x_scale*(i+1)-5,-values[i]*4-5,QString::number(values[i]));
    }
    for(int i=0;i<values.length();i++)
    {
        m_painter->setRenderHint(QPainter::Antialiasing, true);
        QLinearGradient linear(QPointF(x_scale*(i+1)-Histopram_width/2, -values[i]*4), QPointF(x_scale*(i+1)-Histopram_width/2+40, 0));
        linear.setColorAt(0, QColor(0,255,255));
        linear.setColorAt(1, QColor(30,144,255));
        linear.setSpread(QGradient::PadSpread);
        m_painter->setPen(QPen(QColor(0, 160, 230,50), 1));
        m_painter->setBrush(linear);
        m_painter->drawRect(x_scale*(i+1)-20,-values[i]*4,Histopram_width,values[i]*4);
    }


    m_painter->drawRect(380,-350,20,10);
    font.setPointSize(5);
    m_painter->setFont(font);
    m_painter->setPen(Qt::black);
    m_painter->drawText(QRect(410,-350,80,10),"购买热力");
    this->setPixmap(*m_pixmap);
}
