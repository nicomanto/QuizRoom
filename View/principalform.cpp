#include "principalform.h"

PrincipalForm::PrincipalForm(QWidget *parent): BaseForm(parent), menubar(nullptr), scroll(nullptr), container_scroll(new QGroupBox(scroll)){

}

PrincipalForm::~PrincipalForm(){}




//SLOTS
void PrincipalForm::to_login(){
    LoginForm* log= new LoginForm();

    log->show();

    close();
}

void PrincipalForm::to_addform(){

    QDialog* dialog = new QDialog(this);
    QVBoxLayout* layout_dialog = new QVBoxLayout(dialog);


    layout_dialog->addWidget(new ModifyAddForm(dialog));

    layout_dialog->setSizeConstraint( QLayout::SetFixedSize );

    dialog->show();


}

