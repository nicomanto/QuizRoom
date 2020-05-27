#include "principalform.h"

PrincipalForm::PrincipalForm(User* u,Controller& c,bool & r,QWidget *parent): BaseForm(parent), user(u),control(c),relogin(r),menubar(nullptr), scroll(nullptr), container_scroll(new QGroupBox(scroll)){

}

PrincipalForm::~PrincipalForm(){}

void PrincipalForm::setStyle(){
    //BaseForm::setStyle();

    setMinimumSize(QSize(width()*10,height()*10));

}


//SLOTS
void PrincipalForm::to_login(){
    relogin=true;

    control.cleanStack();

    parentWidget()->close();
}

void PrincipalForm::to_addform(const QString& title, const QString& description){

    QDialog* dialog = new QDialog(this);
    QVBoxLayout* layout_dialog = new QVBoxLayout(dialog);

    ModifyAddForm* temp= new ModifyAddForm(title,description,dialog);
    layout_dialog->addWidget(temp);

    connect(temp,SIGNAL(addinformation(const QString&, const QString&)),this,SLOT(confirm_addform(const QString&, const QString&)));
    //connect(temp,SIGNAL(toClose()),dialog,SLOT(close()));

    layout_dialog->setSizeConstraint( QLayout::SetFixedSize );

    dialog->show();


}

//SLOTS
void PrincipalForm::to_previous_page(){
    emit previous_page();
}

void PrincipalForm::to_update_previous_page(){
    emit update_previous_page();
};






