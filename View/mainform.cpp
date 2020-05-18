#include "mainform.h"

MainForm::MainForm(User* u,bool &r,QWidget *parent) : PrincipalForm(u,r,parent), scroll_layout(new QGridLayout(container_scroll)){
    main_layout=new QVBoxLayout(this);
    menubar=new QMenuBar(this);
    scroll= new QScrollArea(this);

    addMenu();
    addForm();
    setStyle();

    setLayout(main_layout);
}


void MainForm::addMenu(){
    QMenu* options = new QMenu("Opzioni",menubar);
    QMenu*  course= new QMenu("Corso",menubar);


    QAction* exit_login = new QAction("ritorna alla pagina di login",options);
    QAction* subscribe_course = new QAction("iscriviti al corso",course);



    if(user->CanAddCourse()){
        QAction* add_course = new QAction("crea corso",course);
        course->addAction(add_course);
        //connect del bottone aggiungi
        connect(add_course,SIGNAL(triggered()),this,SLOT(to_addform()));
    }


    course->addAction(subscribe_course);

    options->addAction(exit_login);

    menubar->addMenu(options);
    menubar->addMenu(course);

    main_layout->addWidget(menubar);



    //connect della exit_to_login
    connect(exit_login,SIGNAL(triggered()),this,SLOT(to_login())); //tests
}

void MainForm::addForm(){
    //test inserimento push_button

    main_layout->addWidget(scroll);  //aggiungo la scroll area al layout principale

    scroll->setWidget( container_scroll );  //il contenitore degli elemnti all'interno della scroll area

    //for che aggiunge i bottoni
    for(unsigned int i=0; i <user->getCourse().size(); ++i){
        //QString s= "Corso " + QString::number(i);
        course.push_back(new QPushButton(QString::fromStdString((user->getCourse()[i].getTitle())),this));

        //connect del bottone corso
        connect(course[i],SIGNAL(clicked()),this,SLOT(to_next_page()));


        course_menu.push_back(new QPushButton(course[i]));
        course_menu[i]->setVisible(false); //setto invisibile perchè non so se può modificarlo

        scroll_layout->addWidget(course[i],i,0);




        if(addMenuButton(course_menu[i]))
            course_menu[i]->setVisible(true);

        scroll_layout->addWidget(course_menu[i],i,1);

    }

}

void MainForm::setStyle(){
    PrincipalForm::setStyle();




    //setto lo stile dei vari bottoni
    for(unsigned int i=0; i <user->getCourse().size(); ++i){
        course[i]->setMinimumSize(QSize(width()/2,height()/5));
        course[i]->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
        course[i]->setMaximumSize(QSize(1000,height()/5));

        if(true)//controllo se è creato
            course_menu[i]->setFixedSize(22,height()/5);
    }

    //area di scroll resizable
    scroll->setWidgetResizable(true);

    menubar->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Fixed);

    scroll_layout->setAlignment(Qt::AlignCenter);
    scroll_layout->setSpacing(0);  //setto lo spazio fra gli elementi di scroll a

    QFile file(":/Resources/style_main.css");
    file.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(file.readAll());

    setStyleSheet(styleSheet);
}


//aggiungo il menu a tendina al bottone
bool MainForm::addMenuButton(QPushButton *b){
    MenuButton* button_options = new MenuButton(b,this);
    bool temp=false;

    //controllare se l'utente può modificare un corso
    if(user->CanEditHomework()){
        QAction* change = new QAction("Modifica",button_options);
        button_options->addAction(change);

        //connect del bottone modifica
        connect(change,SIGNAL(triggered()),this,SLOT(to_addform()));
        temp=true;
    }

    //controllare se un utente può eliminare un corso
    if(user->CanDeleteHomework()){
        QAction* del = new QAction("Elimina",button_options);
        button_options->addAction(del);
        temp=true;
    }



    b->setMenu(button_options);

    return temp;

}



//SLOTS
void MainForm::to_next_page(){
    emit to_new_page(new CourseForm(user, relogin,"ciao",parentWidget()));

    close();
}

void MainForm::to_previous_page(){
    relogin=true;

    parentWidget()->close();
}

