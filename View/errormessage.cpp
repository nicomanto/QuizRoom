#include "errormessage.h"


ErrorMessage::ErrorMessage(const QString &m, QWidget *parent): QMessageBox(new QMessageBox(parent)){
    setWindowTitle("Attenzione");
    setText(m);
    setWindowIcon(QIcon(":/Resources/Images/error.png"));
}
