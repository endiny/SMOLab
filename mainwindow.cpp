#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    completeWin = new CompleteWin();
    stepWin = new StepWin();
    connect(this, SIGNAL(stepByStep(Simulator*)), stepWin, SLOT(getSimulator(Simulator *)));
    connect(this, SIGNAL(fullTable(Simulator*)), completeWin, SLOT(getSimulator(Simulator *)));
    connect(stepWin, SIGNAL(fullTable(Simulator*)), completeWin, SLOT(getSimulator(Simulator*)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_completeBtn_clicked()
{
    initSimulator();
    emit fullTable(simulator);
}

Simulator *MainWindow::initSimulator()
{
    simulator = new Simulator(20000,
                              ui->sourceNumber->value(),
                              ui->serverNumber->value(),
                              ui->bufferSize->value(),
                              ui->sourceInt->value(),
                              ui->serverIntMin->value(),
                              ui->serverIntMax->value());
}

void MainWindow::on_startBtn_clicked()
{
    initSimulator();
    emit stepByStep(simulator);
}
