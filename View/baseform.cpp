#include "baseform.h"

BaseForm::BaseForm(QWidget *parent) : QWidget(parent), main_layout(nullptr){

    QScreen *screen = QGuiApplication::primaryScreen();
    QRect  screenGeometry = screen->geometry();

    height_screen = screenGeometry.height();
    width_screen = screenGeometry.width();
}

BaseForm::~BaseForm(){}

void BaseForm::setStyle()
{
    setWindowTitle("ClassRoom");
    main_layout->setAlignment(Qt::AlignCenter);

    //setta la paggina al centro dello schermo
    setGeometry(QStyle::alignedRect(Qt::LeftToRight,Qt::AlignCenter,size(),qApp->desktop()->availableGeometry()));


    setMinimumSize(QSize(width_screen/3,height_screen/4));

}
