#include "homeworkform.h"


HomeworkForm::HomeworkForm(QWidget *parent): BaseForm(parent), scroll(new QScrollArea(this)){
    main_layout=new QVBoxLayout(this);
    menubar=new QMenuBar(this);

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
    QAction* add_homework = new QAction("crea compito",homework);

    options->addAction(exit_login);
    homework->addAction(add_homework);


    connect(exit_login,SIGNAL(triggered()),this,SLOT(close()));
    //connect(exit_login,SIGNAL(triggered()),new LoginForm,SLOT(open())); //tests

    menubar->addAction(course_page);
    menubar->addMenu(options);
    menubar->addMenu(homework);

    main_layout->addWidget(menubar);
}

void HomeworkForm::addForm(){
    QHBoxLayout* center = new QHBoxLayout(this);

    course_title= new QLabel("Titolo corso",this);
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
