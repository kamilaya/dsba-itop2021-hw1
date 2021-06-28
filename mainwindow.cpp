#include "mainwindow.h"
#include "dialogwindow.h"
#include "./ui_mainwindow.h"
#include "addingfiles.h"

#include <iostream>
#include <QFile>
#include <QFileDialog>
#include <QWidget>
#include <QList>
#include <QStandardItemModel>
#include <QTextStream>
#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    model = new QStandardItemModel(0, 5, parent);


    model->setColumnCount(5);
    model->setHorizontalHeaderLabels(QStringList() << "Filename" << "Owner" << "Size" << "Last modified" << "Permissions");



    proxyModel = new QSortFilterProxyModel();
    proxyModel->setSourceModel(model);

    ui->tableView->setModel(proxyModel);
    ui->tableView->setSortingEnabled(true);
    ui->tableView->sortByColumn(4);
}



MainWindow::~MainWindow()
{
    delete ui;
    delete model;
}



void MainWindow::on_pushButton_clicked()
{
//     AFTER DISCUSSION
//     QString fileName = QFileDialog::getOpenFileName(this,"Open File","*.txt");
//     QFile file(fileName);
//     file.open(QIODevice::ReadOnly);

//     file.readLine();
    
    
    QFile file(":/new/prefix1/data (1).txt");
    file.open(QIODevice::ReadOnly);

    file.readLine();

    int row = 0;

    while(!file.atEnd())
    {
        QByteArray line = file.readLine();
        QList<QByteArray> lineAsVector = line.split('|');

        model->insertRows(row, 1);
        model->setData(model->index(row, 0), QString(lineAsVector.at(0)));
        model->setData(model->index(row, 1), QString(lineAsVector.at(1)));
        model->setData(model->index(row, 2), lineAsVector.at(2).toInt());
        model->setData(model->index(row, 3), lineAsVector.at(3).toDouble());
        model->setData(model->index(row, 4), QString(lineAsVector.at(4)));
        files.append(File(QString(lineAsVector.at(0)),QString(lineAsVector.at(1)),
                          QString(lineAsVector.at(2)),QString(lineAsVector.at(3)),
                          QString(lineAsVector.at(4))));
        row++;
    }
}




void MainWindow::on_actionAbout_triggered()
{
    DialogWindow secDialog;
    secDialog.setModal(true);
    secDialog.exec();
}





void MainWindow::on_pushButton_2_clicked()
{
    AddingFiles *a = new AddingFiles(this, &files);
    a->open();
}


void MainWindow::on_pushButton_3_clicked()
{
    if (files.length()>( ui->tableView->model()->rowCount()))
    {
        int i = 1;
//         AFTER DISCUSSION
//         QString fileName = QFileDialog::getOpenFileName(this,"*.txt");
        QString fileName = QFileDialog::getOpenFileName(this,":/new/prefix1/data (1).txt");
        while(files.length() > ui->tableView->model()->rowCount())
        {
            File x = files.at(files.length()-i);
            QFile arr(fileName);
            arr.open(QIODevice::ReadOnly);
            QByteArray a = arr.readAll();
            arr.close();
            a.append((x.GetFilename()+"|"+x.GetOwner()+"|"+x.GetSize()+"|"+x.GetLast()+
                      "|"+x.GetPermission()).toUtf8());
            
//             AFTER DISCUSSION
//             a.append("\n");

            if (arr.open(QIODevice::WriteOnly))
            {
                arr.write(a);
            }
            arr.close();
            model->insertRows(ui->tableView->model()->rowCount()-1, 1);
            model->setData(model->index(ui->tableView->model()->rowCount()-1, 0), x.GetFilename());
            arr.close();
            i++;
        }
    }
    
}

