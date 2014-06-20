#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QString>
#include <QApplication>
#include "bitch.h"
#include "CryptoPP\pwdbased.h"
//#include "blockspreading.h"
QString fileName;
QString str;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QObject::connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(fileDlg()));
    QObject::connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(fileDlg2()));
    QObject::connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(fileDlg3()));
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

void MainWindow::fileDlg3()
{
    //blockspreading();
    //ui->ed3->setText("asd");
    static int inlen;
    QByteArray *in, *out, *buf;
    //byte *in, *out, *buf;
    int blocksize = 16;
    //buf = new byte[blocksize-1];
    buf = new QByteArray[blocksize-1];
    int outlen;

    FILE* f;

    f = fopen ("../../tex.txt","r");

    if (f)
    {
    fseek (f, 0, SEEK_END);
    inlen = ftell (f);
    rewind (f);

    outlen  = inlen + (inlen+1)%16;
    //in = new byte[inlen];
    //out = new byte[outlen];
    in = new QByteArray[inlen];
    out = new QByteArray[outlen];

    fread (in, sizeof(char), 0, f);

    for (int i=0; i<inlen; i++)   // записываю текст в аут
    {
        fread(&(out[i]), sizeof(char), 1, f);
        //cout<<out[i];
        //for(int i=0; i<list.size(); ++i){
        //QString str(out[i].constData());
            // use your string as needed
       // }
        //ui->ed3->setText(QString("%1").arg(out[i]));
        ui->ed3->setText(out[i]);
    }

    memset (out+inlen, '/0', outlen-inlen); // зануление последних элементов

    //cout<<"\n"<<"\n";
    ui->ed3->setText("\n");

    fclose (f);
    }
    else
    {
        //cout<<"Empty stream"<<"\n";
        ui->ed3->setText("Empty stream");
    }

    for ( int k = 0; k<(outlen/blocksize); k++ )
    {
    memcpy(buf, out + k*blocksize, blocksize);


    for (int j = 0; j < blocksize; j++)
    {
        //cout<<buf[j];
        //ui->ed3->setText(QString("%1").arg(buf[j]));
        ui->ed3->setText(buf[j]);
    }
    //cout<<"\n";
    ui->ed3->setText("\n");
    }
}
