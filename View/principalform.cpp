#include "principalform.h"

PrincipalForm::PrincipalForm(QWidget *parent): BaseForm(parent), menubar(nullptr), scroll(nullptr), container_scroll(new QGroupBox(scroll)){}

PrincipalForm::~PrincipalForm(){
}

