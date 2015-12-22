#ifndef STEPWIN_H
#define STEPWIN_H

#include <QWidget>
#include <QVector>
#include <QLabel>
#include <QString>
#include <QDebug>
#include <QStringList>
#include <QStringListModel>
#include "utils.h"
#include "Simulator/stdafx.h"

namespace Ui {
class StepWin;
}

class StepWin : public QWidget
{
    Q_OBJECT

public:
    explicit StepWin(QWidget *parent = 0);
    ~StepWin();
public slots:
    void getSimulator(Simulator *sim);
private slots:
    void on_nextBtn_clicked();
    void on_finishBtn_clicked();

signals:
    void fullTable(Simulator *);
private:
    void updateView();
    Ui::StepWin *ui;
    Simulator *simulator;
};

#endif // STEPWIN_H
