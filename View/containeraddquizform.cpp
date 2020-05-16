#include "containeraddquizform.h"

ContainerAddQuizForm::ContainerAddQuizForm(QWidget *parent): PrincipalForm(parent),container_quiz(new QWidget(this)), layout_container_quiz(new QVBoxLayout(container_quiz)), scroll_layout(new QVBoxLayout(container_scroll)),end(new QPushButton("termina",this)), add_combine(new QPushButton("Quiz a combinazione",this)),
    add_classic(new QPushButton("Quiz classico",this)),container_button(new QWidget(this)), layout_button(new QHBoxLayout(container_button)){

    main_layout=new QVBoxLayout(this);
    menubar=new QMenuBar(this);
    scroll= new QScrollArea(this);

    addMenu();
    addForm();
    setStyle();

    setLayout(main_layout);
}

void ContainerAddQuizForm::addMenu(){

    QAction* previous_page = new QAction("<-",menubar); //ritorno alla pagina precedent

    menubar->addAction(previous_page);

    main_layout->addWidget(menubar);

    //connect della previous_page
    connect(previous_page, SIGNAL(triggered()),this,SLOT(to_previous_page()));
}

void ContainerAddQuizForm::addForm(){

   main_layout->addWidget(scroll);

   scroll->setWidget( container_scroll );

   scroll_layout->addWidget(container_quiz);

   scroll_layout->addWidget(container_button);

   layout_button->addWidget(end);
   layout_button->addWidget(add_combine);
   layout_button->addWidget(add_classic);

   connect(add_classic,SIGNAL(clicked()),this,SLOT(addClassicWidget()));
   connect(add_combine,SIGNAL(clicked()),this,SLOT(addCombineWidget()));
   //connect(end,SIGNAL(clicked()),this,SLOT(close()));



}

void ContainerAddQuizForm::setStyle(){
    PrincipalForm::setStyle();




    scroll->setWidgetResizable(true);


    //stile menubar
    menubar->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Fixed);

    //stile layout scroll
    scroll_layout->setAlignment(Qt::AlignCenter);
    scroll_layout->setSpacing(10);

    //stile layout del button
    layout_button->setAlignment(Qt::AlignCenter);


    container_quiz->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);


    //setto la dimensione minima della finistra
    //setMinimumSize(QSize(width_screen/3,height_screen/3));

    //aggiunta foglio di stile
    QFile file(":/Resources/style_containerquiz.css");
    file.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(file.readAll());

    setStyleSheet(styleSheet);
}




//SLOTS
void ContainerAddQuizForm::addCombineWidget(){
    quiz.push_back(new AddCombineQuizForm(quiz.size()+1,container_quiz));
    layout_container_quiz->addWidget(quiz.back());
}

void ContainerAddQuizForm::addClassicWidget(){
    quiz.push_back(new AddClassicQuizForm(quiz.size()+1,container_quiz));
    layout_container_quiz->addWidget(quiz.back());
}

void ContainerAddQuizForm::to_next_page(){}

void ContainerAddQuizForm::to_previous_page(){
    emit to_new_page(new HomeworkForm(parentWidget()));

    close();
}

