#ifndef ADDINGFILES_H
#define ADDINGFILES_H

#include <QDialog>
#include <QFile>
#include <QString>
#include <QVector>

class File
{
private:
    QString filename;
    QString owner;
    QString size;
    QString last_modified;
    QString permissions;
public:
    File()
    {
        filename="";
        owner="";
        size="";
        last_modified="";
        permissions="";
    }
    File(QString filename, QString owner, QString size, QString last_modified, QString permissions)
    {
        this->filename=filename;
        this->owner=owner;
        this->size=size;
        this->last_modified=last_modified;
        this->permissions=permissions;
    }

    QString GetFilename () {return filename;}
    QString GetOwner () {return owner;}
    QString GetSize () {return size;}
    QString GetLast () {return last_modified;}
    QString GetPermission () {return permissions;}

    void SetPermission (QString permission) {permissions=permission;}
};


namespace Ui {
class AddingFiles;
}

class AddingFiles : public QDialog
{
    Q_OBJECT

public:
    explicit AddingFiles(QWidget *parent = nullptr, QVector<File> *files = {});
    ~AddingFiles();

private slots:
    void on_pushButton_clicked();

private:
    Ui::AddingFiles *ui;
    QVector<File> *f;
};

#endif // ADDINGFILES_H
