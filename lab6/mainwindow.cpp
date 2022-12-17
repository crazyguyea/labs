#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qmessagebox.h"

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


void MainWindow::on_pushButton_clicked()
{
    QMessageBox::critical(this, "Ошибка", "Здесь отображается ошибка");
}


void MainWindow::on_pushButton_2_clicked()
{
    QMessageBox::warning(this, "Опасность", "Здесь отображается опасность");
}


void MainWindow::on_pushButton_3_clicked()
{
    QMessageBox::information(this, "Информация", "Здесь отображается информация");
}

