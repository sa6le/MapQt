#include "widget.h"
#include "ui_widget.h"


widget::widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::widget)
{
    ui->setupUi(this);
//    m_quickWidget = new QQuickWidget(this) ;
//    m_quickWidget->setSource(QUrl("qrc:/main.qml"));
//    m_quickWidget->setResizeMode(QQuickWidget::SizeRootObjectToView);
//    ui->gridLayout->addWidget(m_quickWidget, 1, 0);
}

widget::~widget()
{
    delete ui;
}
