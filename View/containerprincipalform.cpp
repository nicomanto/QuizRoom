#include "containerprincipalform.h"

ContainerPrincipalForm::ContainerPrincipalForm(User* u,QWidget *parent) : BaseForm(parent),main_window(new MainForm(u,this)){

    main_layout= new QVBoxLayout(this);

    addForm();
    setStyle();

    setLayout(main_layout);

    connect(main_window,SIGNAL(to_new_page(PrincipalForm*)),this,SLOT(update_main_window(PrincipalForm*)));
}

void ContainerPrincipalForm::update_main_window(PrincipalForm* p){
    main_window=p;
    main_layout->addWidget(main_window);
    connect(main_window,SIGNAL(to_new_page(PrincipalForm*)),this,SLOT(update_main_window(PrincipalForm*)));
}

void ContainerPrincipalForm::addForm(){
    main_layout->addWidget(main_window);
}

void ContainerPrincipalForm::setStyle(){
    BaseForm::setStyle();

    //dimensione minima delle pagine
    setMinimumSize(QSize(width_screen/2+100,height_screen/3+50));

}
