#include "addingfiles.h"
#include "ui_addingfiles.h"
#include <QString>
#include <QTextStream>

AddingFiles::AddingFiles(QWidget *parent, QVector<File> *files) :
    QDialog(parent),
    ui(new Ui::AddingFiles)
{
    ui->setupUi(this);
    f=files;
}

AddingFiles::~AddingFiles()
{
    delete ui;
}

void AddingFiles::on_pushButton_clicked()
{
    f->append(File(ui->lineEdit->text(), ui->lineEdit_2->text(), ui->lineEdit_3->text(),
                   ui->lineEdit_4->text(), ui->lineEdit_5->text()));
    close();
}

