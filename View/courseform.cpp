#include "courseform.h"

CourseForm::CourseForm(QWidget *parent) : BaseForm(parent),scroll(new QScrollArea(this)){

    main_layout=new QVBoxLayout(this);
    menubar=new QMenuBar(this);
    addMenu();
    addForm();

    setStyle();

    setLayout(main_layout);
}

void CourseForm::addMenu(){
    QMenu* options = new QMenu("Opzioni",menubar);
    QMenu*  course= new QMenu("Corso",menubar);

    QAction* exit_login = new QAction("ritorna alla pagina di login",options);
    QAction* add_course = new QAction("crea corso",course);
    QAction* subscribe_course = new QAction("iscriviti al corso",course);

    options->addAction(exit_login);
    course->addAction(add_course);
    course->addAction(subscribe_course);

    connect(exit_login,SIGNAL(triggered()),this,SLOT(close()));
    connect(exit_login,SIGNAL(triggered()),new LoginForm,SLOT(open())); //tests

    menubar->addMenu(options);
    menubar->addMenu(course);

    main_layout->addWidget(menubar);
}

void CourseForm::addForm(){
    //test inserimento push_button



    main_layout->addWidget(scroll);

    QWidget * container = new QWidget(scroll);
    scroll->setWidget( container );

    QVBoxLayout* container_layout = new QVBoxLayout(container);
    container_layout->setAlignment(Qt::AlignCenter);

    for(unsigned int i=0; i <50; ++i){
        QString s= "Corso " + QString::number(i);
        course.push_back(new QPushButton(s,this));
        container_layout->addWidget(course[i]);
    }

}

void CourseForm::setStyle(){
    BaseForm::setStyle();

    for(unsigned int i=0; i <50; ++i){
        course[i]->setMinimumSize(QSize(width()/2,height()/5));
        course[i]->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
        course[i]->setMaximumSize(QSize(1000,600));
    }

    scroll->setWidgetResizable(true);

    menubar->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Fixed);

    QFile file(":/Resources/style_course.css");
    file.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(file.readAll());

    setStyleSheet(styleSheet);
}
