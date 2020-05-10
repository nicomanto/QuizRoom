#include "homeworkform.h"

HomeworkForm::HomeworkForm(QWidget *parent): PrincipalForm(parent),homework_title(new QLabel("Titolo",this)),homework_instructions(new QLabel("Esegui questo quiz e bla bla blajcdsqijbucqbiocnoinqiconeonqeicnioqcnioqen webchbeqj e e e e e e e e e ee  e e e e e  e e e ec",this)),container_info_quiz(new QGroupBox(this)),layout_container_info_quiz(new QVBoxLayout(container_info_quiz)), score(nullptr),deadline(nullptr){
    main_layout=new QVBoxLayout(this);

    menubar=new QMenuBar(this);

    if(true){ //se è uno scorehomework;
        int my_score=10;
        int total_score=200;
        QString s(QString::number(my_score)+'/'+QString::number(total_score));
        score= new QLabel("Score: "+s,this);
    }

    if(true){ //se è un timehomework
        QString s("09/05/2020");
        deadline= new QLabel("Deadline: "+s,this);
    }


    quiz=new QPushButton("start quiz",this);

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



    if(true){ //controllare se l'utente può modificare l'homework
        QAction* modify_homework = new QAction("modifica",homework);
        homework->addAction(modify_homework);
    }

    if(true){ //controllare se l'utente può eliminare l'homework
        QAction* delete_homework = new QAction("elimina",homework);
        homework->addAction(delete_homework);
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

   main_layout->addWidget(homework_title);
   main_layout->addWidget(homework_instructions);


   layout_container_info_quiz->addWidget(score);
   layout_container_info_quiz->addWidget(deadline);
   layout_container_info_quiz->addWidget(quiz);

    main_layout->addWidget(container_info_quiz, Qt::AlignCenter);
}

void HomeworkForm::setStyle(){
    PrincipalForm::setStyle();

    homework_title->setAlignment(Qt::AlignCenter);
    homework_title->setTextInteractionFlags(Qt::TextSelectableByMouse);
    homework_title->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Fixed);
    homework_title->setWordWrap(true);

    homework_instructions->setAlignment(Qt::AlignCenter);
    homework_instructions->setTextInteractionFlags(Qt::TextSelectableByMouse);
    homework_instructions->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    homework_instructions->setWordWrap(true);
    homework_instructions->setStyleSheet("margin: 0 200 0 200;");


    menubar->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Fixed);

    //main_layout->setAlignment(Qt::AlignTop);

    score->setAlignment(Qt::AlignCenter);
    deadline->setAlignment(Qt::AlignCenter);

    quiz->setFixedSize(QSize(width()/2,height()/7));


    QFont font( "Arial", 18, QFont::Bold);
    homework_title->setFont(font);

    font=QFont( "Arial", 14);
    homework_instructions->setFont(font);

    font=QFont( "Arial", 12);
    score->setFont(font);

    font=QFont( "Arial", 12);
    deadline->setFont(font);

    layout_container_info_quiz->setAlignment(Qt::AlignCenter);
    container_info_quiz->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Fixed);


    QFile file(":/Resources/style_homework.css");
    file.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(file.readAll());

    setStyleSheet(styleSheet);


}


void HomeworkForm::addMenuButton(QPushButton *b){}
