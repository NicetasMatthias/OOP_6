#include "interface.h"
#include "ui_interface.h"

Interface::Interface(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Interface)
{
    ui->setupUi(this);
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
                                 "",
                                 "*");
    ui->lineEdit_path->setText(tmp);
}
