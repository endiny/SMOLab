#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Simulator/stdafx.h"
#include "completewin.h"
#include "stepwin.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
signals:
    void fullTable(Simulator *);
    void stepByStep(Simulator *);
private slots:
    void on_completeBtn_clicked();

    void on_startBtn_clicked();

private:
    Simulator* initSimulator();
    Ui::MainWindow *ui;
    StepWin *stepWin;
    CompleteWin *completeWin;
    Simulator *simulator;
};



#endif // MAINWINDOW_H
