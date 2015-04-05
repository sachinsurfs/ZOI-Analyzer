#include "guideline.h"
#include "newexp.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
   // QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),
    //                                                 "", tr("Files (*.*)"));
    NewExp *n=new NewExp(this);
    n->show();
    this->destroy();

    //QFile myFile(filename);
    //myFile.open(QIODevice::ReadOnly);
}

void MainWindow::on_pushButton_2_clicked()
{
    Guideline *g=new Guideline(this);
    g->show();
    this->destroy();
}
