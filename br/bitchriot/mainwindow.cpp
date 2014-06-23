#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QTextStream>
#include <QFile>
#include <QString>
#include <QApplication>
#include <QWidget>
QString fileName;
QString str;
QByteArray test;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QObject::connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(fileDlg2()));
    QObject::connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(fileDlg3()));
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::fileDlg2()
{
    fileName = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                     "",
                                                     tr("Files (*.*)"));
    QFile file(fileName);
    file.open(QIODevice::WriteOnly);
    //if (!file.open(QIODevice::WriteOnly))
      // ui->textEdit->setText("omg");
    if (this->ui->radioButton->isChecked())
    {
        file.write("GOST sypher ", 12);
    }
    if (this->ui->radioButton_2->isChecked())
    {
        file.write("AES sypher ", 11);
    }
    if (this->ui->radioButton_3->isChecked())
    {
        file.write("ECB mode", 8);
    }
    if (this->ui->radioButton_4->isChecked())
    {
        file.write("CBC mode", 8);
    }
    if (this->ui->radioButton_5->isChecked())
    {
        file.write("CFB mode", 8);
    }
    if (this->ui->radioButton_6->isChecked())
    {
        file.write("OFB mode", 8);
    }
    file.close();
}

void MainWindow::fileDlg3()
{
    fileName = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                     "",
                                                     tr("Files (*.*)"));
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly))
        return;
    test = file.readAll();
    ui->textEdit->setText(test);
    file.close();
}
