#include "homeworkform.h"


HomeworkForm::HomeworkForm(const QString& title, QWidget *parent): PrincipalForm(parent){
    main_layout=new QVBoxLayout(this);
    scroll= new QScrollArea(this);
    menubar=new QMenuBar(this);

    course_title= new QLabel(title,this);

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
    QHBoxLayout* center = new QHBoxLayout(this);

    center->addWidget(course_title);


    scroll->setWidgetResizable(true);

    center->addWidget(scroll);
    QWidget * container = new QWidget(scroll);
    scroll->setWidget( container );

    QVBoxLayout* container_layout = new QVBoxLayout(container);
    container_layout->setAlignment(Qt::AlignCenter);

    for(unsigned int i=0; i <50; ++i){
        QString s= "Compito " + QString::number(i);
        homework.push_back(new QPushButton(s,this));
        container_layout->addWidget(homework[i]);
        addMenuButton(homework[i]);
    }


    main_layout->addLayout(center);
}

void HomeworkForm::setStyle(){
    BaseForm::setStyle();

    for(unsigned int i=0; i <50; ++i){
        homework[i]->setMinimumSize(width()/2,height()/5);
        homework[i]->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
        homework[i]->setMaximumSize(QSize(1000,600));
    }

    course_title->setAlignment(Qt::AlignCenter);
    scroll->setMaximumWidth(width()*2);
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

