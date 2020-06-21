#include "containerprincipalform.h"

ContainerPrincipalForm::ContainerPrincipalForm(User* u,Controller& c,bool &r,QWidget *parent) : BaseForm(parent),control(c),main_window(new MainForm(u,c,r,this)){
    main_layout= new QVBoxLayout(this);

    addForm();
    setStyle();

    setLayout(main_layout);


    //aggiungo la pagina allo stack delle pagine che ho visitato per fare rollback
    control.addStackView(main_window);


    //connect del conteniore delle pagine principali, nonchè della pagina che sta contenendo, cioè mainwindow
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

    //connect della nuova pagina che ho appena aggiunto
    connect(main_window,SIGNAL(to_new_page(PrincipalForm*)),this,SLOT(update_main_window(PrincipalForm*)));
    connect(main_window,SIGNAL(previous_page()),this,SLOT(previous_main_window()));
    connect(main_window,SIGNAL(update_previous_page()),this,SLOT(update_previous_main_window()));
}

void ContainerPrincipalForm::previous_main_window(){

    main_window->close();
    main_window=control.removeStackView();

    main_layout->addWidget(main_window);
    main_window->show();
}

void ContainerPrincipalForm::update_previous_main_window(){

    PrincipalForm* previous_page=control.removeStackView()->clone();

    control.addStackView(previous_page);

    //connect della pagina aggiornata precedentemente. Riaggiunte perchè viene creata una copia con i nuovi dati della pagina precedente
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


    //setColorBackground
    QPalette pal = palette();
    pal.setColor(QPalette::Background, QColor::fromRgb(51,51,51));
    setAutoFillBackground(true);
    setPalette(pal);


}

