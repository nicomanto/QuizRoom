#include "formvirtual.h"

FormVirtual::FormVirtual(QWidget *parent) : QWidget(parent), main_layout(nullptr), menubar(nullptr){}

FormVirtual::~FormVirtual(){}

void FormVirtual::setStyle()
{
    setWindowTitle("ClassRoom");

    QFile file(":/Resources/style.css");
    file.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(file.readAll());

    setStyleSheet(styleSheet);
}
