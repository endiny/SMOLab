#include "completewin.h"
#include "ui_completewin.h"

CompleteWin::CompleteWin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CompleteWin)
{
    ui->setupUi(this);
}

CompleteWin::~CompleteWin()
{
    delete ui;
}

void CompleteWin::getSimulator(Simulator *sim)
{
    simulator = sim;

    simulator->run();
    Statistic *statistic = simulator->getStatistic();

    vector<SourceRow*> sourceTableData = statistic->getSourceTable();
    QStandardItemModel* sourceTableModel = Utils::getSourceTableModel(sourceTableData);
    ui->sourceTable->setModel(sourceTableModel);
    ui->sourceTable->horizontalHeader()->setStretchLastSection(true);

    vector<ServerRow*> serverTableData = statistic->getServerTable();
    QStandardItemModel* serverTableModel = Utils::getServerTableModel(serverTableData);
    ui->serverTable->setModel(serverTableModel);
    ui->serverTable->horizontalHeader()->setStretchLastSection(true);

    this->show();
}
