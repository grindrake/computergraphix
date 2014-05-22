#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QString>
#include <QApplication>
QString fileName;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QObject::connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(fileDlg()));
    QObject::connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(fileDlg2()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::fileDlg()
{
    fileName = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                     "",
                                                     tr("Files (*.*)"));
    ui->label_2->setText(fileName);
}

void MainWindow::fileDlg2()
{
    fileName = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                     "",
                                                     tr("Files (*.*)"));
    ui->label_6->setText(fileName);
}
