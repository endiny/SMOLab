#ifndef COMPLETEWIN_H
#define COMPLETEWIN_H

#include <QWidget>
#include "Simulator/stdafx.h"
#include "utils.h"
namespace Ui {
class CompleteWin;
}

class CompleteWin : public QWidget
{
    Q_OBJECT

public:
    explicit CompleteWin(QWidget *parent = 0);
    ~CompleteWin();
public slots:
    void getSimulator(Simulator * sim);
private:
    Ui::CompleteWin *ui;
    Simulator *simulator;
};

#endif // COMPLETEWIN_H
