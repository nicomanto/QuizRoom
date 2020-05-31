#include "errormessage.h"


ErrorMessage::ErrorMessage(const QString &m, QWidget *parent): QMessageBox(new QMessageBox(parent)){
    setWindowTitle("Attenzione");
    setText(m);
    setWindowIcon(QIcon(":/Resources/Images/error.png"));

    //setta la paggina al centro dello schermo
    setGeometry(QStyle::alignedRect(Qt::LeftToRight,Qt::AlignCenter,size(),qApp->desktop()->availableGeometry()));
}
