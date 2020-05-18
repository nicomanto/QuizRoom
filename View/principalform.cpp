#include "principalform.h"

PrincipalForm::PrincipalForm(User* u,QWidget *parent): BaseForm(parent), menubar(nullptr), scroll(nullptr), container_scroll(new QGroupBox(scroll)),user(u){

}

PrincipalForm::~PrincipalForm(){}

void PrincipalForm::setStyle(){
    //BaseForm::setStyle();

    setMinimumSize(QSize(width()*10,height()*10));

}


//SLOTS
void PrincipalForm::to_login(){
    LoginForm* log= new LoginForm();

    log->show();

    parentWidget()->close();
}

void PrincipalForm::to_addform(){

    QDialog* dialog = new QDialog(this);
    QVBoxLayout* layout_dialog = new QVBoxLayout(dialog);


    layout_dialog->addWidget(new ModifyAddForm(dialog));

    layout_dialog->setSizeConstraint( QLayout::SetFixedSize );

    dialog->show();


}

