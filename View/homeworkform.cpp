#include "homeworkform.h"

HomeworkForm::HomeworkForm(QWidget *parent): PrincipalForm(parent),homework_title(new QLabel("Titolo",this)),homework_instructions(new QLabel("Esegui questo quiz e bla bla blajcdsqijbucqbiocnoinqiconeonqeicnioqcnioqen webchbeqj e e e e e e e e e ee  e e e e e  e e e ec",this)),
    container_info_quiz(new QGroupBox(this)),layout_container_info_quiz(new QVBoxLayout(container_info_quiz)), score(nullptr),deadline(nullptr){

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


    start_quiz=new QPushButton("start quiz",this);

    addMenu();
    addForm();
    setStyle();

    setLayout(main_layout);
}


void HomeworkForm::addMenu(){

    QMenu* options = new QMenu("Opzioni",menubar);
    QMenu*  homework= new QMenu("Compito",menubar);

    QAction* previous_page= new QAction("<-",menubar);
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

    menubar->addAction(previous_page);
    menubar->addMenu(options);

    if(true)
        menubar->addMenu(homework);

    main_layout->addWidget(menubar);
}

void HomeworkForm::addForm(){

   main_layout->addWidget(homework_title);
   main_layout->addWidget(homework_instructions);

    if(true)//controllo se è scorehomework
        layout_container_info_quiz->addWidget(score);

   if(true) //controllo se è timehomework
        layout_container_info_quiz->addWidget(deadline);

   layout_container_info_quiz->addWidget(start_quiz);

    main_layout->addWidget(container_info_quiz, Qt::AlignCenter);
}

void HomeworkForm::setStyle(){
    PrincipalForm::setStyle();


    //stile del titolo del compito
    homework_title->setAlignment(Qt::AlignCenter);
    homework_title->setTextInteractionFlags(Qt::TextSelectableByMouse);
    homework_title->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Fixed);
    homework_title->setWordWrap(true);

    //stile delle istruzioni del compito
    homework_instructions->setAlignment(Qt::AlignCenter);
    homework_instructions->setTextInteractionFlags(Qt::TextSelectableByMouse);
    homework_instructions->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    homework_instructions->setWordWrap(true);
    homework_instructions->setStyleSheet("margin: 0 200 0 200;");


    //stile menubar
    menubar->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Fixed);


    if(true) //controllo se è scorehomework
        score->setAlignment(Qt::AlignCenter);

    if(true) //controllo se è timehomework
        deadline->setAlignment(Qt::AlignCenter);


    //stile del bottone start_quiz
    start_quiz->setFixedSize(QSize(width()/2,height()/7));

    //aggiunta dei alcuni font
    QFont font( "Arial", 18, QFont::Bold);
    homework_title->setFont(font);
    font=QFont( "Arial", 14);
    homework_instructions->setFont(font);    
    if(true){ //controllo se è scorehomework
        font=QFont( "Arial", 12);
        score->setFont(font);
    }
    if(true){ //controllo se è timehomework
        font=QFont( "Arial", 12);
        deadline->setFont(font);
    }


    //stile dei container
    layout_container_info_quiz->setAlignment(Qt::AlignCenter);
    container_info_quiz->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Fixed);

    //aggiunta del foglio di stile
    QFile file(":/Resources/style_homework.css");
    file.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(file.readAll());

    setStyleSheet(styleSheet);


}
