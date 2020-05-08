#include "courseform.h"

CourseForm::CourseForm(QWidget *parent) : PrincipalForm(parent){

    main_layout=new QVBoxLayout(this);
    menubar=new QMenuBar(this);
    scroll= new QScrollArea(this);

    addMenu();
    addForm();
    setStyle();

    setLayout(main_layout);
}

void CourseForm::addMenu(){
    QMenu* options = new QMenu("Opzioni",menubar);
    QMenu*  course= new QMenu("Corso",menubar);

    QAction* exit_login = new QAction("ritorna alla pagina di login",options);
    QAction* subscribe_course = new QAction("iscriviti al corso",course);



    if(true){ //controllare se l'utente può aggiungere corsi
        QAction* add_course = new QAction("crea corso",course);
        course->addAction(add_course);
    }

    course->addAction(subscribe_course);

    options->addAction(exit_login);

    connect(exit_login,SIGNAL(triggered()),this,SLOT(close()));
    connect(exit_login,SIGNAL(triggered()),new LoginForm,SLOT(open())); //tests

    menubar->addMenu(options);
    menubar->addMenu(course);

    main_layout->addWidget(menubar);
}

void CourseForm::addForm(){
    //test inserimento push_button

    main_layout->addWidget(scroll);

    QWidget * container = new QWidget(scroll);
    scroll->setWidget( container );

    container_grid = new QGridLayout(container);

    for(unsigned int i=0; i <50; ++i){
        QString s= "Corso " + QString::number(i);
        course.push_back(new QPushButton(s,this));

        if(true) //controllo se posso modificare in qualche modo il compito
            course_menu.push_back(new QPushButton(course[i]));

        container_grid->addWidget(course[i],i,0);

        if(true){ //controllo se posso modificare in qualche modo il compito
            addMenuButton(course_menu[i]);
            container_grid->addWidget(course_menu[i],i,1);
        }
    }

}

void CourseForm::setStyle(){
    BaseForm::setStyle();

    for(unsigned int i=0; i <50; ++i){
        course[i]->setMinimumSize(QSize(width()/2,height()/5));
        course[i]->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
        course[i]->setMaximumSize(QSize(1000,600));

        if(true)//controllo se è creato
            course_menu[i]->setFixedSize(22,height()/5);
    }

    scroll->setWidgetResizable(true);

    menubar->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Fixed);


    container_grid->setAlignment(Qt::AlignCenter);
    container_grid->setSpacing(0);

    QFile file(":/Resources/style_course.css");
    file.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(file.readAll());

    setStyleSheet(styleSheet);
}


void CourseForm::addMenuButton(QPushButton *b){
    MenuButton* button_options = new MenuButton(b,this);

    //controllare se l'utente può modificare un corso
    if(true){
        QAction* change = new QAction("Modifica",button_options);
        button_options->addAction(change);
    }

    //controllare se un utente può eliminare un corso
    if(true){
        QAction* del = new QAction("Elimina",button_options);
        button_options->addAction(del);
    }

    b->setMenu(button_options);

}
