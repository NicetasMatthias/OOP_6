#include "interface.h"
#include "ui_interface.h"

Interface::Interface(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Interface)
{
    ui->setupUi(this);
    v=nullptr;
}

Interface::~Interface()
{
    delete ui;
}


void Interface::on_pushButton_file_clicked()
{
    QString tmp;
    tmp = QFileDialog::getOpenFileName(this,
                                 "Укажите файл с описание графа",
                                 "../OOP_6/data",
                                 "*");
    ui->lineEdit_path->setText(tmp);
}

void Interface::on_pushButton_view_clicked()
{
    int cntr = 0,size,err_c;
    QString tmp, fname = ui->lineEdit_path->text();
    QFile f(fname);
    if (!f.exists())
    {
        QMessageBox::warning(this,"Ошибка","Такого файла не существует");
        return;
    }
    if (!f.open(QIODevice::ReadOnly))
    {
        QMessageBox::warning(this,"Ошибка","Не удалось открыть файл для чтения");
        return;
    }
    //QTextStream in(&f);
    //if (in.atEnd())
    if (f.atEnd())
    {
        QMessageBox::warning(this,"Ошибка","Файл пустой");
        return;
    }
    //tmp = in.readLine();
    //qDebug() << "tmp считался: " << tmp;
    //size = tmp.toInt();
    tmp = f.readLine();
    qDebug() << "tmp считался: " << tmp;
    size = tmp.toInt();
    //in >> size;
    if (size<=0)
    {
        QMessageBox::warning(this,"Ошибка","В файле указаны некорректные данные");
        return;
    }
    g.create_m(size);
    qDebug() << "size считался: " << size;
    while(!f.atEnd())
    {
        qDebug() << "заход №" << cntr+1;
        err_c = g.add_m_line(f.readLine());
        switch (err_c)
        {
        case INVALID_NUM_OF_COLUMNS:
        case TOO_MANY_LINES:
        case INVALID_ARGS:
            qDebug() << "проход№" << cntr+1;
            QMessageBox::warning(this,"Ошибка","В файле указаны некорректные данные");
            return;
        case SUCCESS:
            break;
        default: break;
        }
        cntr++;
    }
    if (!g.is_ready())
    {
        qDebug() << "Матрица не готова после всех проходов (" << cntr << ")";
        QMessageBox::warning(this,"Ошибка","В файле указаны некорректные данные");
        return;
    }
    qDebug() << "Матрица нормально считалась";

    if (v==nullptr)
    {
        qDebug() << "пытаемся создать новое окно";
        v = new View(&g);
        qDebug() << "создали новое окно";
    }
    else
    {
        v->paint(&g);
    }
    if (!v->isVisible())
    {
        qDebug() << "пытаемся показать новое окно";
        v->show();
        qDebug() << "показываем новое окно";
    }


    /*

        if (v->isVisible())
        {
            qDebug() << "пытаемся закрыть старое окно";
            v->close();
            qDebug() << "закрыли старое окно";
        }
    qDebug() << "пытаемся создать новое окно";
    v = new View(&g);
    qDebug() << "пытаемся показать новое окно";
    v->show();
    qDebug() << "показали новое окно";
    */
}
