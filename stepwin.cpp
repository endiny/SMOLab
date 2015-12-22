#include "stepwin.h"
#include "ui_stepwin.h"

StepWin::StepWin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StepWin)
{
    ui->setupUi(this);
}

StepWin::~StepWin()
{
    delete ui;
}

void StepWin::getSimulator(Simulator *sim)
{
    simulator = sim;
    simulator->nextStep();
    updateView();
    this->show();
}

void StepWin::updateView()
{
    QStringListModel *sourceModel = Utils::getListModelFromStringVector(simulator->getSourses());
    QStringListModel *bufferModel = Utils::getListModelFromStringVector(simulator->getBuffer());
    QStringListModel *serverModel = Utils::getListModelFromStringVector(simulator->getServers());
    QStringListModel *denialModel = Utils::getListModelFromStringVector(simulator->getDenials());

    ui->sourceList->setModel(sourceModel);
    ui->bufferList->setModel(bufferModel);
    ui->serverList->setModel(serverModel);
    ui->denialList->setModel(denialModel);

}

void StepWin::on_nextBtn_clicked()
{
    simulator->nextStep();
    updateView();
}

void StepWin::on_finishBtn_clicked()
{
    emit fullTable(simulator);
    this->hide();
}
