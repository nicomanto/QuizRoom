#include "homeworkform.h"


HomeworkForm::HomeworkForm(const QString& title, QWidget *parent): PrincipalForm(parent){
    main_layout=new QVBoxLayout(this);
    scroll= new QScrollArea(this);
    menubar=new QMenuBar(this);

    center = new QHBoxLayout(this);

    course_title= new QLabel(title,this);
    course_description= new QLabel("Quiz del corso Letteratuta italiana 2018/2019",this);
    QString s("xvois8"); //codice;
    course_code=new QLabel("Codice corso: "+s,this);


    addMenu();
    addForm();
    setStyle();

    setLayout(main_layout);
}

void HomeworkForm::addMenu(){

    QMenu* options = new QMenu("Opzioni",menubar);
    QMenu*  homework= new QMenu("Compito",menubar);

    QAction* course_page= new QAction("<-",menubar);
    QAction* exit_login = new QAction("ritorna alla pagina di login",options);



    if(true){ //controllare se l'utente può aggiungere homework
        QAction* add_homework = new QAction("crea compito",homework);
        homework->addAction(add_homework);
    }

    options->addAction(exit_login);



    connect(exit_login,SIGNAL(triggered()),this,SLOT(close()));
    //connect(exit_login,SIGNAL(triggered()),new LoginForm,SLOT(open())); //tests

    menubar->addAction(course_page);
    menubar->addMenu(options);

    if(true)
        menubar->addMenu(homework);

    main_layout->addWidget(menubar);
}

void HomeworkForm::addForm(){

    QWidget* container= new QWidget(this);
    info_course=new QVBoxLayout(container);

    info_course->addWidget(course_title);
    info_course->addWidget(course_description);
    info_course->addWidget(course_code);

    container->setMaximumWidth(width());



    center->addWidget(container);

    container= new QWidget(this);
    container_grid=new QGridLayout(container);
    center->addWidget(scroll);

    scroll->setWidget( container );



    for(unsigned int i=0; i <50; ++i){
        QString s= "Compito " + QString::number(i);
        homework.push_back(new QPushButton(s,this));

        if(true) //controllo se posso modificare in qualche modo il compito
            homework_menu.push_back(new QPushButton(homework[i]));

        container_grid->addWidget(homework[i],i,0);

        if(true){ //controllo se posso modificare in qualche modo il compito
            addMenuButton(homework_menu[i]);
            container_grid->addWidget(homework_menu[i],i,1);
        }


    }


    main_layout->addLayout(center);
}

void HomeworkForm::setStyle(){
    BaseForm::setStyle();

    for(unsigned int i=0; i <50; ++i){
        homework[i]->setMinimumSize(width()/3,height()/5);
        homework[i]->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
        homework[i]->setMaximumSize(QSize(1000,600));

        if(true)//controllo se è creato
            homework_menu[i]->setFixedSize(22,height()/5);
    }

    course_title->setAlignment(Qt::AlignCenter);
    course_title->setTextInteractionFlags(Qt::TextSelectableByMouse);
    course_title->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Minimum);
    course_title->setWordWrap(true);

    course_description->setAlignment(Qt::AlignCenter);
    course_description->setTextInteractionFlags(Qt::TextSelectableByMouse);
    course_description->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);
    course_description->setWordWrap(true);

    course_code->setAlignment(Qt::AlignCenter);
    course_code->setTextInteractionFlags(Qt::TextSelectableByMouse);
    course_code->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    course_code->setWordWrap(true);


    info_course->setAlignment(Qt::AlignCenter);
    info_course->setSpacing(50);

    container_grid->setAlignment(Qt::AlignCenter);
    container_grid->setSpacing(0);

    QFont font( "Arial", 18, QFont::Bold);
    course_title->setFont(font);

    font=QFont( "Arial", 14);
    course_description->setFont(font);

    font=QFont( "Arial", 12);
    course_code->setFont(font);

    scroll->setMaximumWidth(width()*2);
    scroll->setWidgetResizable(true);

    menubar->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Fixed);

    QFile file(":/Resources/style_homework.css");
    file.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(file.readAll());

    setStyleSheet(styleSheet);
}


void HomeworkForm::addMenuButton(QPushButton *b){

    //devo crearlo solo se posso fare qualcosa, nel caso dello studente no
    MenuButton* button_options = new MenuButton(b,this);

    //controllare se l'utente può modificare un compito
    if(true){
        QAction* change = new QAction("Modifica",button_options);
        button_options->addAction(change);
    }

    //controllare se un utente può eliminare un compito
    if(true){
        QAction* del = new QAction("Elimina",button_options);
        button_options->addAction(del);
    }

    //true sse ho creato il button_options
    if(true)
        b->setMenu(button_options);

}





