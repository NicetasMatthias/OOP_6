#ifndef INTERFACE_H
#define INTERFACE_H

#include <QWidget>
#include <graph.h>
#include <QFile>
#include <QFileDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class Interface; }
QT_END_NAMESPACE

class Interface : public QWidget
{
    Q_OBJECT

public:
    Graph g;

    Interface(QWidget *parent = nullptr);
    ~Interface();

private slots:
    void on_pushButton_file_clicked();

private:
    Ui::Interface *ui;
};
#endif // INTERFACE_H
