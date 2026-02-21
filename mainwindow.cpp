#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonCount_clicked()
{
    bool ok;
    int value = ui->lineEditCount->text().toInt(&ok);

    if (!ok)
        value = 0;

    value++;
    ui->lineEditCount->setText(QString::number(value));
}

void MainWindow::on_pushButtonReset_clicked()
{
    ui->lineEditCount->setText("0");
}

