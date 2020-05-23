#include "containerprincipalform.h"

ContainerPrincipalForm::ContainerPrincipalForm(User* u,Controller& c,bool &r,QWidget *parent) : BaseForm(parent),user(u),relogin(r),control(c),main_window(new MainForm(u,c,r,this)){
    main_layout= new QVBoxLayout(this);

    addForm();
    setStyle();

    setLayout(main_layout);

    control.addStackView(main_window);

    connect(main_window,SIGNAL(to_new_page(PrincipalForm*)),this,SLOT(update_main_window(PrincipalForm*)));
    connect(main_window,SIGNAL(previous_page()),this,SLOT(previous_main_window()));
    connect(main_window,SIGNAL(update_previous_page()),this,SLOT(update_previous_main_window()));
}

void ContainerPrincipalForm::update_main_window(PrincipalForm* p){
    control.addStackView(main_window);

    main_window->close();
    main_window=p;
    main_layout->addWidget(main_window);
    main_window->show();
    connect(main_window,SIGNAL(to_new_page(PrincipalForm*)),this,SLOT(update_main_window(PrincipalForm*)));
    connect(main_window,SIGNAL(previous_page()),this,SLOT(previous_main_window()));
    connect(main_window,SIGNAL(update_previous_page()),this,SLOT(update_previous_main_window()));
}

void ContainerPrincipalForm::previous_main_window(){
    //std::cout<<main_window<<std::endl;
    main_window->close();
    main_window=control.removeStackView();
    //main_window->show();
    main_layout->addWidget(main_window);
    main_window->show();
    //connect(main_window,SIGNAL(to_new_page(PrincipalForm*)),this,SLOT(update_main_window(PrincipalForm*)));
    //connect(main_window,SIGNAL(previous_page()),this,SLOT(previous_main_window()));
}

void ContainerPrincipalForm::update_previous_main_window(){
    //main_window->close();

    //control.removeStackView();
    //main_window->close();

    PrincipalForm* previous_page=control.removeStackView()->clone();

    control.addStackView(previous_page);

    /*main_layout->addWidget(previous_page);

    std::cout<<"ciaoo"<<std::endl;

    previous_page->clone();

    control.addStackView(main_window);*/

    //main_window=previous_page;
    //main_layout->addWidget(previous_page);

    //previous_page->setLayout(main_layout);

    //main_window->show();


    connect(previous_page,SIGNAL(to_new_page(PrincipalForm*)),this,SLOT(update_main_window(PrincipalForm*)));
    connect(previous_page,SIGNAL(previous_page()),this,SLOT(previous_main_window()));
    connect(previous_page,SIGNAL(update_previous_page()),this,SLOT(update_previous_main_window()));
}

void ContainerPrincipalForm::addForm(){
    main_layout->addWidget(main_window);
}

void ContainerPrincipalForm::setStyle(){
    BaseForm::setStyle();

    //dimensione minima delle pagine
    setMinimumSize(QSize(width_screen/2+100,height_screen/3+50));

}
