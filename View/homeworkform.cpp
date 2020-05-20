#include "homeworkform.h"

HomeworkForm::HomeworkForm(User* u,Controller& c,Homework* h,bool & r,QWidget *parent): PrincipalForm(u,c,r,parent),this_homework(h),homework_title(new QLabel(QString::fromStdString(this_homework->getTitle()),this)),homework_instructions(new QLabel(QString::fromStdString(this_homework->getInstructions()),this)),
    container_info_quiz(new QWidget(this)),layout_container_info_quiz(new QVBoxLayout(container_info_quiz)), score(nullptr),deadline(nullptr),start_quiz(new QPushButton("start quiz",this)),add_quiz(new QPushButton("aggiungi quiz",this)), container_button(new QWidget(this)), layout_button(new QHBoxLayout(container_button)){

    main_layout=new QVBoxLayout(this);

    menubar=new QMenuBar(this);

    if(this_homework->isScoreHomework()){ //se è uno scorehomework;

        ScoreHomework* t= dynamic_cast < ScoreHomework* > ( this_homework );
        int my_score=0;
        //int total_score=200;
        QString s(QString::number(my_score)+'/'+QString::number(t->getTotalScore()));
        score= new QLabel("Score: "+s,this);
    }

    if(this_homework->isTimeHomework()){ //se è un timehomework
        TimeHomework* t= dynamic_cast < TimeHomework* > ( this_homework );
        //QString s("09/05/2020");
        deadline= new QLabel("Deadline: "+QString::fromStdString(t->getDeadline().ToString()),this);
    }

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

        //connect del bottone modifica
        connect(modify_homework,SIGNAL(triggered()),this,SLOT(to_addform()));
    }

    if(true){ //controllare se l'utente può eliminare l'homework
        QAction* delete_homework = new QAction("elimina",homework);
        homework->addAction(delete_homework);
    }

    options->addAction(exit_login);

    menubar->addAction(previous_page);
    menubar->addMenu(options);

    if(true)
        menubar->addMenu(homework);

    main_layout->addWidget(menubar);


    //connect della previous_page
    connect(previous_page, SIGNAL(triggered()),this,SLOT(to_previous_page()));

    //connect della exit_to_login
    connect(exit_login,SIGNAL(triggered()),this,SLOT(to_login())); //tests
}

void HomeworkForm::addForm(){

   main_layout->addWidget(homework_title);
   main_layout->addWidget(homework_instructions);

    if(this_homework->isScoreHomework())//controllo se è scorehomework
        layout_container_info_quiz->addWidget(score);

   if(this_homework->isTimeHomework()) //controllo se è timehomework
        layout_container_info_quiz->addWidget(deadline);

   if(this_homework->isTimeHomework() || this_homework->isScoreHomework()) //controllo se è timehomework o scorehomework
       main_layout->addWidget(container_info_quiz, Qt::AlignCenter);



   layout_button->addWidget(start_quiz);
   layout_button->addWidget(add_quiz);

   main_layout->addWidget(container_button);

   //connect dei bottoni
   connect(start_quiz,SIGNAL(clicked()),this,SLOT(to_next_page())); //tests
   connect(add_quiz,SIGNAL(clicked()),this,SLOT(to_addquiz())); //tests


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

    if(this_homework->isScoreHomework()) //controllo se è scorehomework
        score->setAlignment(Qt::AlignCenter);

    if(this_homework->isTimeHomework()) //controllo se è timehomework
        deadline->setAlignment(Qt::AlignCenter);


    //stile dei bottoni
    start_quiz->setFixedSize(QSize(width()/3,height()/7));
    add_quiz->setFixedSize(QSize(width()/3,height()/7));
    add_quiz->setVisible(false);

    if(true)//controllo se ha già un quiz o se ne è sprovvisto, in quel caso se ne può aggiungere uno
        add_quiz->setVisible(true);

    //aggiunta dei alcuni font
    QFont font( "Arial", 18, QFont::Bold);
    homework_title->setFont(font);
    font=QFont( "Arial", 14);
    homework_instructions->setFont(font);    

    if(this_homework->isScoreHomework()){ //controllo se è scorehomework
        font=QFont( "Arial", 12);
        score->setFont(font);
    }
    if(this_homework->isTimeHomework()){ //controllo se è timehomework
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





//SLOTS


void HomeworkForm::to_addquiz(){
    emit to_new_page(new ContainerAddQuizForm(user,control,relogin,parentWidget()));

    close();
}

void HomeworkForm::to_next_page(int index){
    emit to_new_page(new ContainerQuizForm(user,control,relogin,parentWidget()));

    close();
}

void HomeworkForm::to_previous_page(){
    //emit to_new_page(new CourseForm(user,control,relogin,user->getCourse()[],parentWidget()));

    close();
}

