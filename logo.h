#ifndef LOGO_H
#define LOGO_H

#include <QWidget>

class Logo : public QWidget
{
    Q_OBJECT
public:
    Logo(QWidget* parent = nullptr);
protected:
    void paintEvent(QPaintEvent* event) override;

};

#endif // LOGO_H
