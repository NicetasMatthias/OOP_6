#ifndef VIEW_H
#define VIEW_H

#include <graph.h>

#include <QWidget>
#include <QPainter>


namespace Ui {
class View;
}

class View : public QWidget
{
    Q_OBJECT

public:
    View(Graph*);
    ~View();
    void paint(Graph*);

protected:
    void paintEvent (QPaintEvent *event);

private:
    Ui::View *ui;
    Graph *g;
};

#endif // VIEW_H
