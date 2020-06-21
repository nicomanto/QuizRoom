#include "errormessage.h"
#include <QFile>


ErrorMessage::ErrorMessage(const QString &m, QWidget *parent): QMessageBox(new QMessageBox(parent)){
    setWindowTitle("Attenzione");
    setText(m);
    setWindowIcon(QIcon(":/Resources/Images/error.png"));

    QFile file(":/Resources/Style_sheet/style_errormessage.css");
    file.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(file.readAll());

    setStyleSheet(styleSheet);

    //setta la paggina al centro dello schermo
    setGeometry(QStyle::alignedRect(Qt::LeftToRight,Qt::AlignCenter,size(),qApp->desktop()->availableGeometry()));
}
