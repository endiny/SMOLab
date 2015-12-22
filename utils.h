#ifndef UTILS_H
#define UTILS_H
#include <QStandardItem>
#include <QStringList>
#include <QStringListModel>
#include "Simulator/stdafx.h"

class Utils
{
public:
    Utils();
    static QStandardItemModel* getSourceTableModel(vector<SourceRow*> tableData)
    {
        int numRows = tableData.size();
        cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << numRows << endl << endl;
        int numColumns = 8;

        QStandardItemModel* model = new QStandardItemModel(0, 0);

        QStringList horizontalHeader;
        horizontalHeader.append("source No");
        horizontalHeader.append("Customer count");
        horizontalHeader.append("P denial");
        horizontalHeader.append("T system");
        horizontalHeader.append("T bufer");
        horizontalHeader.append("T service");
        horizontalHeader.append("DT bufer");
        horizontalHeader.append("DT service");

        model->setHorizontalHeaderLabels(horizontalHeader);


       for(int i=0; i<numRows; i++){
           model->appendRow(convertSourceRowToStandartItem(tableData.at(i)));
       }


        return model;
    }

    static QStandardItemModel* getServerTableModel(vector<ServerRow *> tableData){
        int numRows = tableData.size();
        int numColumns = 2;

        QStandardItemModel* model = new QStandardItemModel(0, 0);

        QStringList horizontalHeader;
        horizontalHeader.append("Server No");
        horizontalHeader.append("Utilization");

        model->setHorizontalHeaderLabels(horizontalHeader);

        for(int i=0; i<numRows; i++){
            model->appendRow(convertServerRowToStandartItem(tableData.at(i)));
        }

        return model;
    }

    static QList<QStandardItem*> convertServerRowToStandartItem(ServerRow* row){
        QList<QStandardItem*> a;

        a.append(new QStandardItem(QString::number(row->serverNo)));
        a.append(new QStandardItem(QString::number(row->utilization)));

        return a;
    }

    static QList<QStandardItem*> convertSourceRowToStandartItem(SourceRow* row){
        QList<QStandardItem*> a;
        //QStandardItem *a = new QStandardItem()
        a.append(new QStandardItem(QString::number(row->sourceNo)));
        a.append(new QStandardItem(QString::number(row->count)));
        a.append(new QStandardItem(QString::number(row->denialProbability)));
        a.append(new QStandardItem(QString::number(row->stayInSystemT)));
        a.append(new QStandardItem(QString::number(row->bufferT)));
        a.append(new QStandardItem(QString::number(row->serviceT)));
        a.append(new QStandardItem(QString::number(row->bufferTD)));
        a.append(new QStandardItem(QString::number(row->serverTD)));
        return a;
    }

    static QStringListModel* getListModelFromStringVector(vector<string> vec){

        QStringListModel *model = new QStringListModel();
        QStringList list;
        for(int i=0; i<vec.size(); i++){
            list << QString::fromUtf8(vec.at(i).c_str());
        }
        model->setStringList(list);
        return model;
    }


};

#endif // UTILS_H
