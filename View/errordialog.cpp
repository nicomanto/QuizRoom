#include "errordialog.h"


ErrorDialog::ErrorDialog(const QString &m, QWidget *parent): QDialog(new QDialog(parent)), layout_error(new QVBoxLayout(this)), msg(new QLabel(m,this)){
    layout_error->addWidget(msg);

    layout_error->setSizeConstraint( QLayout::SetFixedSize );

    setLayout(layout_error);
}
