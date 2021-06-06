#include "dialogwindow.h"
#include "ui_dialogwindow.h"

#include <QtWidgets>

DialogWindow::DialogWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogWindow)
{
    ui->setupUi(this);

    l = new Logo(ui->widget);

    QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(l->sizePolicy().hasHeightForWidth());
    l->setSizePolicy(sizePolicy);


     QHBoxLayout* horLayout = new QHBoxLayout(ui->widget);
     horLayout->addWidget(l);
}

DialogWindow::~DialogWindow()
{
    delete ui;
}


