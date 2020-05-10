#include "courseform.h"


CourseForm::CourseForm(const QString& title, QWidget *parent): PrincipalForm(parent){

    main_layout=new QVBoxLayout(this);
    scroll= new QScrollArea(this);
    menubar=new QMenuBar(this);

    center_layout = new QHBoxLayout(this);

    container_course= new QGroupBox(this);
    container_homework= new QGroupBox(this);

    course_title= new QLabel(title,this);
    course_description= new QLabel("Quiz del corso Letteratuta italiana 2018/2019",this);
    QString s("xvois8"); //codice;
    course_code=new QLabel("Codice corso: "+s,this);


    addMenu();
    addForm();
    setStyle();

    setLayout(main_layout);
}

void CourseForm::addMenu(){

    QMenu* options = new QMenu("Opzioni",menubar);
    QMenu* course= new QMenu("Corso",menubar);
    QMenu*  homework= new QMenu("Compito",menubar);

    QAction* main_page= new QAction("<-",menubar);
    QAction* exit_login = new QAction("ritorna alla pagina di login",options);



    if(true){ //controllare se l'utente può aggiungere homework
        QAction* add_homework = new QAction("crea compito",homework);
        homework->addAction(add_homework);
    }

    if(true){ //controllare se l'utente può modificare il corso
        QAction* modify_course = new QAction("modifica",homework);
        course->addAction(modify_course);
    }

    if(true){ //controllare se l'utente può eliminare il corso
        QAction* delete_course = new QAction("elimina",homework);
        course->addAction(delete_course);
    }

    options->addAction(exit_login);



    connect(exit_login,SIGNAL(triggered()),this,SLOT(close()));
    //connect(exit_login,SIGNAL(triggered()),new LoginForm,SLOT(open())); //tests

    menubar->addAction(main_page);
    menubar->addMenu(options);

    if(true)
        menubar->addMenu(course);

    if(true)
        menubar->addMenu(homework);

    main_layout->addWidget(menubar);
}

void CourseForm::addForm(){

    info_course_layout=new QVBoxLayout(container_course);

    info_course_layout->addWidget(course_title);
    info_course_layout->addWidget(course_description);
    info_course_layout->addWidget(course_code);

    container_course->setMaximumWidth(width());



    center_layout->addWidget(container_course);

    scroll_layout=new QGridLayout(container_homework);
    center_layout->addWidget(scroll);

    scroll->setWidget( container_homework );



    for(unsigned int i=0; i <50; ++i){
        QString s= "Compito " + QString::number(i);
        homework.push_back(new QPushButton(s,this));

        if(true) //controllo se posso modificare in qualche modo il compito
            homework_menu.push_back(new QPushButton(homework[i]));

        scroll_layout->addWidget(homework[i],i,0);

        if(true){ //controllo se posso modificare in qualche modo il compito
            addMenuButton(homework_menu[i]);
            scroll_layout->addWidget(homework_menu[i],i,1);
        }


    }


    main_layout->addLayout(center_layout);
}

void CourseForm::setStyle(){
    PrincipalForm::setStyle();

    for(unsigned int i=0; i <50; ++i){
        homework[i]->setMinimumSize(width()/3,height()/5);
        homework[i]->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
        homework[i]->setMaximumSize(QSize(1000,height()/5));

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


    info_course_layout->setAlignment(Qt::AlignCenter);
    info_course_layout->setSpacing(50);

    scroll_layout->setAlignment(Qt::AlignCenter);
    scroll_layout->setSpacing(0);

    QFont font( "Arial", 18, QFont::Bold);
    course_title->setFont(font);

    font=QFont( "Arial", 14);
    course_description->setFont(font);

    font=QFont( "Arial", 12);
    course_code->setFont(font);

    scroll->setMaximumWidth(width()*2);
    scroll->setWidgetResizable(true);

    menubar->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Fixed);

    QFile file(":/Resources/style_course.css");
    file.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(file.readAll());

    setStyleSheet(styleSheet);
}


void CourseForm::addMenuButton(QPushButton *b){

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






