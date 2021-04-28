#include "graph.h"
#include <QDebug>

Graph::Graph()
{
    m = nullptr;
    ready = false;
}

Graph::~Graph()
{
    if (m != nullptr) delete m;
}

bool Graph::is_ready()
{
    return ready;
}

void Graph::create_m(unsigned int s)
{
    m = new Matrix(s);
    curr_str = 0;
    ready = false;
}

void Graph::delete_m()
{
    if (m != nullptr) delete m;
    ready = false;
}

int Graph::add_m_line(QString inp)
{
    int tmp;
    if (ready)
    {
        qDebug() << "Ошибка: слишком много строк в файле";
        return TOO_MANY_LINES;
    }
    QStringList list = inp.split(" ");
    if (list.size()!=m->size)
    {
        qDebug() << "Ошибка: неверное количество чисел в строке: " << list.size();
        return INVALID_NUM_OF_COLUMNS;
    }
    for (size_t i = 0; i < list.size(); i++)
    {
        tmp=list[i].toInt();
        switch (tmp)
        {
        case 0:
            m->data[curr_str][i]=false;
            break;
        case 1:
            m->data[curr_str][i]=true;
            break;
        default:
            qDebug() << "Ошибка: неправильные числа в матрице";
            return INVALID_ARGS;
        }
    }
    curr_str++;
    qDebug() << "curr_str = " << curr_str << "\nsize = " << m->size;
    if (curr_str==m->size) ready = true;
    return SUCCESS;
}



int Graph::get_m_size()
{
    return m->size;
}
QVector < QVector<bool> > Graph::get_matrix()
{
    return m->data;
}
