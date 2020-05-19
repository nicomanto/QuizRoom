#include "courseform.h"


CourseForm::CourseForm(User* u,Controller& c,Course* course, bool & r,QWidget *parent): PrincipalForm(u,c,r,parent), container_course(new QGroupBox(this)),container_center(new QGroupBox(this)), info_course_layout(new QVBoxLayout(container_course)),
    center_layout(new QHBoxLayout(container_center)), scroll_layout(new QGridLayout(container_scroll)), course_title(new QLabel(QString::fromStdString(course->getTitle()),this)),
    course_description(new QLabel(QString::fromStdString(course->getDescription()),this)),course_code(new QLabel(QString::fromStdString(course->getCode()),this)),this_course(course){

    main_layout=new QVBoxLayout(this);
    scroll= new QScrollArea(this);
    menubar=new QMenuBar(this);


    addMenu();
    addForm();
    setStyle();

    setLayout(main_layout);
}

void CourseForm::addMenu(){

    QMenu* options = new QMenu("Opzioni",menubar);
    QMenu* course= new QMenu("Corso",menubar);
    QMenu*  homework= new QMenu("Compito",menubar);

    QAction* previous_page= new QAction("<-",menubar); //torno alla pagina precedente
    QAction* exit_login = new QAction("ritorna alla pagina di login",options);



    if(true){ //controllare se l'utente può aggiungere homework
        QAction* add_homework = new QAction("crea compito",homework);
        homework->addAction(add_homework);
        connect(add_homework,SIGNAL(triggered()),this,SLOT(to_addhomework()));
    }

    if(true){ //controllare se l'utente può modificare il corso
        QAction* modify_course = new QAction("modifica",homework);
        course->addAction(modify_course);
        connect(modify_course,SIGNAL(triggered()),this,SLOT(to_course_info()));
    }

    if(true){ //controllare se l'utente può eliminare il corso
        QAction* delete_course = new QAction("elimina",homework);
        course->addAction(delete_course);
        connect(delete_course,SIGNAL(triggered()),this,SLOT(to_delete_course()));
    }

    options->addAction(exit_login);


    menubar->addAction(previous_page);
    menubar->addMenu(options);

    if(true)
        menubar->addMenu(course);

    if(true)
        menubar->addMenu(homework);

    main_layout->addWidget(menubar);


    //connect della previous_page
    connect(previous_page, SIGNAL(triggered()),this,SLOT(to_previous_page()));

    //connect della exit_to_login
    connect(exit_login,SIGNAL(triggered()),this,SLOT(to_login())); //tests
}

void CourseForm::addForm(){


    info_course_layout->addWidget(course_title);
    info_course_layout->addWidget(course_description);
    info_course_layout->addWidget(course_code);

    container_course->setMaximumWidth(width());

    center_layout->addWidget(container_course);
    center_layout->addWidget(scroll);

    scroll->setWidget( container_scroll );


    //aggiungo i compiti del corso
    for(unsigned int i=0; i <50; ++i){
        QString s= "Compito " + QString::number(i);
        homework.push_back(new QPushButton(s,this));

        //connect del bottone compito
         connect(homework[i],SIGNAL(clicked()),this,SLOT(to_next_page()));

        if(true) //controllo se posso modificare in qualche modo il compito
            homework_menu.push_back(new QPushButton(homework[i]));

        scroll_layout->addWidget(homework[i],i,0);

        if(true){ //controllo se posso modificare in qualche modo il compito
            addMenuButton(homework_menu[i],i);
            scroll_layout->addWidget(homework_menu[i],i,1);
        }


    }


    main_layout->addWidget(container_center);
}

void CourseForm::setStyle(){
    PrincipalForm::setStyle();

    //stile dei bottoni homework e homework_menu
    for(unsigned int i=0; i <50; ++i){
        homework[i]->setMinimumSize(width()/3,height()/5);
        homework[i]->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
        homework[i]->setMaximumSize(QSize(1000,height()/5));

        if(true)//controllo se è creato
            homework_menu[i]->setFixedSize(22,height()/5);
    }


    //stile del course title
    course_title->setAlignment(Qt::AlignCenter);
    course_title->setTextInteractionFlags(Qt::TextSelectableByMouse);
    course_title->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Minimum);
    course_title->setWordWrap(true);

    //stile del course description
    course_description->setAlignment(Qt::AlignCenter);
    course_description->setTextInteractionFlags(Qt::TextSelectableByMouse);
    course_description->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);
    course_description->setWordWrap(true);

    //stile del coruse code
    course_code->setAlignment(Qt::AlignCenter);
    course_code->setTextInteractionFlags(Qt::TextSelectableByMouse);
    course_code->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    course_code->setWordWrap(true);


    //stile info corso
    info_course_layout->setAlignment(Qt::AlignCenter);
    container_course->setMaximumWidth(width()/2);
    info_course_layout->setSpacing(50);


    //stile scroll
    scroll_layout->setAlignment(Qt::AlignCenter);
    scroll->setMinimumWidth(width()/2);
    scroll_layout->setSpacing(0);


    //aggiunta dei font di alcuni elementi
    QFont font( "Arial", 18, QFont::Bold);
    course_title->setFont(font);

    font=QFont( "Arial", 14);
    course_description->setFont(font);

    font=QFont( "Arial", 12);
    course_code->setFont(font);


    //stile scroll area
    //scroll->setMaximumWidth(width()*2);
    scroll->setWidgetResizable(true);

    //stile menubar
    menubar->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Fixed);


    //aggiunta foglio di stile
    QFile file(":/Resources/style_course.css");
    file.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(file.readAll());

    setStyleSheet(styleSheet);
}


void CourseForm::addMenuButton(QPushButton *b,unsigned int i){

    //devo crearlo solo se posso fare qualcosa, nel caso dello studente no
    MenuButton* button_options = new MenuButton(i,b,this);

    //controllare se l'utente può modificare un compito
    if(true){
        QAction* change = new QAction("Modifica",button_options);
        button_options->addAction(change);

        //connect del bottone modifica
        connect(change,SIGNAL(triggered()),this,SLOT(course_info()));
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



//SLOTS
void CourseForm::to_previous_page(){
    emit to_new_page(new MainForm(user,control,relogin, parentWidget()));

    close();
}


void CourseForm::to_next_page(int index){
    emit to_new_page(new HomeworkForm(user,control,relogin,parentWidget()));

    close();
}



void CourseForm::to_addhomework(){
    QDialog* dialog = new QDialog(this);
    QVBoxLayout* layout_dialog = new QVBoxLayout(dialog);


    layout_dialog->addWidget(new AddHomeworkForm("","",dialog));

    layout_dialog->setSizeConstraint( QLayout::SetFixedSize );

    dialog->show();
}

void CourseForm::to_course_info(){
    to_addform(course_title->text(),course_description->text());
}

void CourseForm::to_delete_course(){
    control.deleteCourse(this_course);

    to_previous_page();
}


