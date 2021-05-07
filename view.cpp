#include "view.h"
#include "ui_view.h"

View::View(Graph* p)
{
    g=p;
    ui->setupUi(this);
}

View::~View()
{
    delete ui;
}

void View::paint(Graph* p)
{
    g=p;
    repaint();
}

void View::paintEvent (QPaintEvent *event)
{

    qDebug() << "рисуем";
    Q_UNUSED(event);
    QPainter painter(this);
    QFont font;

    qreal cw = 0.5*rect().width();
    qreal ch = 0.5*rect().height();
    qreal cr = 0.7*(cw>ch?ch:cw);
    qreal cs = 1.5 * cr/g->get_m_size();
    qreal cf = 0.7 * cs;
    qreal a = 2.0*acos(-1.0)/g->get_m_size();
    QPointF *t = new QPointF[g->get_m_size()];

    painter.setPen(QPen(Qt::black));
    font.setPointSize(cf);
    painter.setFont(font);

    for (int i=0; i<g->get_m_size(); i++)
    {
        t[i] = QPointF(cw+cr*sin(i*a),ch-cr*cos(i*a));
        painter.drawEllipse(t[i],cs,cs);
        painter.drawText(t[i].rx()-cs/4-cs*((i>9?0.25:0)),t[i].ry()+cs/4,QString().setNum(i+1));
    }

    for (size_t i = 0; i < g->get_m_size(); i++)
        for (size_t j = 0; j < g->get_m_size(); j++)
        {
            if ((g->get_matrix()[i][j])&&(i!=j))
            {
                QLine tmp(t[i].rx(),t[i].ry(),t[j].rx(),t[j].ry());
                double dx=tmp.dx(), dy=tmp.dy(),tmpd,dyp,dxp;
                tmpd=cs/(sqrt(dx*dx+dy*dy));
                dx*=tmpd;
                dy*=tmpd;
                painter.drawLine(t[i]+QPointF(dx,dy),t[j]-QPointF(dx,dy));

                QPointF *arrow = new QPointF[3];

                if ((abs(dy)<1)||(abs(dx)<1))
                {
                    dyp=dx;
                    dxp=dy;
                }
                else
                {
                    dyp=dy;
                    dxp=-(dy*dyp)/dx;
                }

                tmpd=cs/(sqrt(dxp*dxp+dyp*dyp));
                dxp*=tmpd;
                dyp*=tmpd;

                arrow[0]=t[j]-QPointF(dx,dy);
                arrow[1]=t[j]-QPointF(dx,dy)-0.2*QPointF(dx,dy)+0.1*QPointF(dxp,dyp);
                arrow[2]=t[j]-QPointF(dx,dy)-0.2*QPointF(dx,dy)-0.1*QPointF(dxp,dyp);

                painter.setBrush(QBrush(Qt::black));

                painter.drawPolygon(arrow,3);

                painter.setBrush(QBrush(Qt::white));

                delete [] arrow;
            }
        }

    delete [] t;
}
