#include "formvirtual.h"

FormVirtual::FormVirtual(QWidget *parent) : QWidget(parent), main_layout(nullptr), menubar(nullptr){}

FormVirtual::~FormVirtual(){}

void FormVirtual::setStyle()
{
    setWindowTitle("ClassRoom");
    main_layout->setAlignment(Qt::AlignCenter);

    //setta la paggina al centro dello schermo
    setGeometry(QStyle::alignedRect(Qt::LeftToRight,Qt::AlignCenter,size(),qApp->desktop()->availableGeometry()));

    QFile file(":/Resources/style.css");
    file.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(file.readAll());

    setStyleSheet(styleSheet);
}
