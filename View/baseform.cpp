#include "baseform.h"

BaseForm::BaseForm(QWidget *parent) : QWidget(parent), main_layout(nullptr){

    QScreen *screen = QGuiApplication::primaryScreen();
    QRect  screenGeometry = screen->geometry();

    height_screen = screenGeometry.height();
    width_screen = screenGeometry.width();
}

BaseForm::~BaseForm(){}

void BaseForm::setStyle(){

    //titolo delle finestre
    setWindowTitle("QuizRoom");

    //stile layout principale
    main_layout->setAlignment(Qt::AlignCenter);

    //setta la paggina al centro dello schermo
    setGeometry(QStyle::alignedRect(Qt::LeftToRight,Qt::AlignCenter,size(),qApp->desktop()->availableGeometry()));

    //dimensione minima delle pagine
    setMinimumSize(QSize(width_screen/2,height_screen/4));

}
