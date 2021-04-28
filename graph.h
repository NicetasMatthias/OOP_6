#ifndef GRAPH_H
#define GRAPH_H

enum errors
{
    SUCCESS = 0,
    INVALID_NUM_OF_COLUMNS = 1,
    TOO_MANY_LINES,
    INVALID_ARGS,
};


#include <matrix.h>

class Graph
{
private:    
    Matrix *m;
    bool ready;
    unsigned int curr_str;


public:
    Graph();
    ~Graph();
    bool is_ready();
    void create_m(unsigned int);
    void delete_m();
    int add_m_line(QString);
    int get_m_size();
    QVector < QVector<bool> > get_matrix();
};

#endif // GRAPH_H
