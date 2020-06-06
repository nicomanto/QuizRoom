#include "homeworkform.h"

HomeworkForm::HomeworkForm(User* u,Controller& c,Homework* h,bool & r,QWidget *parent): PrincipalForm(u,c,r,parent),this_homework(h),homework_title(new QLabel(QString::fromStdString(control.getHomeworkTitle(this_homework)),this)),homework_instructions(new QLabel(QString::fromStdString(control.getHomeworkInstructions(this_homework)),this)),
    container_info_quiz(new QWidget(this)),layout_container_info_quiz(new QVBoxLayout(container_info_quiz)), score(nullptr),deadline(nullptr),start_quiz(new QPushButton("start quiz",this)),add_quiz(new QPushButton("aggiungi quiz",this)), container_button(new QWidget(this)), layout_button(new QHBoxLayout(container_button)){

    main_layout=new QVBoxLayout(this);

    menubar=new QMenuBar(this);



    if(control.isScoreHomework(this_homework)){ //se è uno scorehomework;

        ScoreHomework* t= dynamic_cast < ScoreHomework* > ( this_homework );
        //int my_score=0;
        //int total_score=200;
        QString s(QString::number(t->getTotalAllPoint()));
        score= new QLabel("Punteggio massimo: "+s,this);
    }

    if(control.isTimeHomework(this_homework)){ //se è un timehomework
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

    QAction* previous_page= new QAction(QIcon(":/Resources/Images/left_arrow.png"),"",menubar); //torno alla pagina precedente
    QAction* exit_login = new QAction("ritorna alla pagina di login",options);


    //controllo se posso modificare qualcosa dell'homework
    bool can_do_somethingH=false;

    if(control.UserCanEditHomework(user)){ //controllare se l'utente può modificare l'homework
        QAction* modify_homework = new QAction("modifica",homework);
        homework->addAction(modify_homework);

        //connect del bottone modifica
        connect(modify_homework,SIGNAL(triggered()),this,SLOT(to_homework_info()));
        can_do_somethingH=true;
    }

    if(control.UserCanDeleteHomework(user)){ //controllare se l'utente può eliminare l'homework
        QAction* delete_homework = new QAction("elimina",homework);
        homework->addAction(delete_homework);
        connect(delete_homework,SIGNAL(triggered()),this,SLOT(del_homework()));
        can_do_somethingH=true;
    }

    options->addAction(exit_login);

    menubar->addAction(previous_page);
    menubar->addMenu(options);

    if(can_do_somethingH)
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
   score->setVisible(false);
   deadline->setVisible(false);

   QSignalMapper* signalMapperQuiz = new QSignalMapper (this);

    if(control.isScoreHomework(this_homework)) { //controllo se è scorehomework
        layout_container_info_quiz->addWidget(score);
        score->setVisible(true);
    }

   if(control.isTimeHomework(this_homework)) { //controllo se è timehomework
        layout_container_info_quiz->addWidget(deadline);
        deadline->setVisible(true);
    }

   if(control.isTimeHomework(this_homework) || control.isScoreHomework(this_homework)) //controllo se è timehomework o scorehomework
       main_layout->addWidget(container_info_quiz, Qt::AlignCenter);


   layout_button->addWidget(start_quiz);
   layout_button->addWidget(add_quiz);

   main_layout->addWidget(container_button);

   connect(start_quiz,SIGNAL(clicked()),signalMapperQuiz,SLOT(map()));

   signalMapperQuiz->setMapping(start_quiz, 0);
   //mappatuara dei siggnali con l'indice dei quiz (in questo caso è solo uno)
   connect (signalMapperQuiz, SIGNAL(mapped(int)), this, SLOT(to_next_page(int)));


   connect(add_quiz,SIGNAL(clicked()),this,SLOT(to_addquiz()));


}

void HomeworkForm::setStyle(){
    PrincipalForm::setStyle();
    main_layout->setSpacing(0);


    //stile del titolo del compito
    homework_title->setAlignment(Qt::AlignCenter);
    homework_title->setTextInteractionFlags(Qt::TextSelectableByMouse);
    homework_title->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Fixed);
    homework_title->setWordWrap(true);
    homework_title->setObjectName("Title");


    //stile delle istruzioni del compito
    homework_instructions->setAlignment(Qt::AlignCenter);
    homework_instructions->setTextInteractionFlags(Qt::TextSelectableByMouse);
    homework_instructions->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    homework_instructions->setWordWrap(true);
    /*homework_instructions->setStyleSheet("margin: 0 200 0 200;");*/


    //stile menubar
    menubar->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Fixed);

    if(control.isScoreHomework(this_homework)) //controllo se è scorehomework
        score->setAlignment(Qt::AlignCenter);

    if(control.isTimeHomework(this_homework)) //controllo se è timehomework
        deadline->setAlignment(Qt::AlignCenter);


    //stile dei bottoni
    start_quiz->setFixedSize(QSize(width()/3,height()/7));
    add_quiz->setFixedSize(QSize(width()/3,height()/7));
    add_quiz->setVisible(false);

    if(control.haveEmptyQuiz(this_homework) && control.UserCanAddQuiz(user))//controllo se ha già un quiz o se ne è sprovvisto, in quel caso se ne può aggiungere uno
        add_quiz->setVisible(true);

    //aggiunta dei alcuni font
    QFont font( "Times new Roman", 18, QFont::Bold);
    homework_title->setFont(font);
    font=QFont( "Times new Roman", 14);
    homework_instructions->setFont(font);    

    if(control.isScoreHomework(this_homework)){ //controllo se è scorehomework
        font=QFont( "Times new Roman", 12);
        score->setFont(font);
    }
    if(control.isTimeHomework(this_homework)){ //controllo se è timehomework
        font=QFont( "Times new Roman", 12);
        deadline->setFont(font);
    }


    //stile dei container
    layout_container_info_quiz->setAlignment(Qt::AlignCenter);
    container_info_quiz->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Fixed);

    //aggiunta del foglio di stile
    QFile file(":/Resources/Style_sheet/style_homework.css");
    file.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(file.readAll());

    setStyleSheet(styleSheet);


}


HomeworkForm *HomeworkForm::clone() const{
    return new HomeworkForm(user,control,this_homework,relogin,parentWidget());
}





//SLOTS


void HomeworkForm::to_addquiz(){
    emit to_new_page(new ContainerAddQuizForm(user,control,this_homework,relogin,parentWidget()));

    //close();
}

void HomeworkForm::to_next_page(int index){
    emit to_new_page(new ContainerQuizForm(user,control,this_homework,relogin,parentWidget()));

    //close();
}



void HomeworkForm::to_homework_info(){
    to_addform(homework_title->text(),homework_instructions->text());
}


void HomeworkForm::del_homework(){
    control.deleteHomework(this_homework);

    emit to_update_previous_page();

    to_previous_page();

}



void HomeworkForm::confirm_addform(const QString& t, const QString& d){



   control.modifyHomework(this_homework,t.toStdString(),d.toStdString());

   emit to_update_previous_page();
   HomeworkForm* temp= new HomeworkForm(user,control,this_homework,relogin,parentWidget());
   emit to_new_page(temp);



   control.removeStackView();


   //close();
}

