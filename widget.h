#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QQuickWidget>

namespace Ui {
class widget;
}

class widget : public QWidget
{
    Q_OBJECT

public:
    explicit widget(QWidget *parent = nullptr);
    ~widget();

private:
    Ui::widget *ui;
//    QQuickWidget* m_quickWidget;
};

#endif // WIDGET_H
