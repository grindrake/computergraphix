#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    //QAction *saveAction;
public slots:
    //void fileDlg();
    void fileDlg2();
    void fileDlg3();

};

#endif // MAINWINDOW_H
