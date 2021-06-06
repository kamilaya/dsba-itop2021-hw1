#ifndef DIALOGWINDOW_H
#define DIALOGWINDOW_H

#include "logo.h"

#include <QDialog>
#include <QPainter>


namespace Ui {
class DialogWindow;
}

class DialogWindow : public QDialog
{
    Q_OBJECT

public:
    explicit DialogWindow(QWidget *parent = nullptr);
    ~DialogWindow();


private:
    Ui::DialogWindow *ui;
    Logo* l;

};

#endif // DIALOGWINDOW_H
