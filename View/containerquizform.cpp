#include "containerquizform.h"

ContainerQuizForm::ContainerQuizForm(QWidget *parent): PrincipalForm(parent),scroll_layout(new QVBoxLayout(container_scroll)), end_quiz(new QPushButton("termina il quiz",this)){
    main_layout=new QVBoxLayout(this);
    menubar=new QMenuBar(this);
    scroll= new QScrollArea(this);

    addMenu();
    addForm();
    setStyle();

    setLayout(main_layout);
}

void ContainerQuizForm::addMenu(){

    QAction* previous_page = new QAction("<-",menubar); //ritorno alla pagina precedent

    menubar->addAction(previous_page);

    main_layout->addWidget(menubar);
}

void ContainerQuizForm::addForm(){

   main_layout->addWidget(scroll);

   scroll->setWidget( container_scroll );


   //aggiungo i quiz
    for(unsigned int i=0; i <10; ++i){

        quiz_box.push_back(new QGroupBox("Domanda "+QString::number(i+1),this));
        QVBoxLayout* temp= new QVBoxLayout(quiz_box[i]);

        if(i%2==0)
            quiz.push_back(new ClassicQuizForm(quiz_box[i]));
        else
            quiz.push_back(new CombineQuizForm(quiz_box[i]));

        temp->addWidget(quiz[i]);

        scroll_layout->addWidget(quiz_box[i]);

    }


    scroll_layout->addWidget(end_quiz,Qt::AlignCenter);

}

void ContainerQuizForm::setStyle(){
    PrincipalForm::setStyle();

    //stile della vista dei quiz
    for(unsigned int i=0; i <10; ++i){
       quiz_box[i]->setMinimumSize(QSize(width()/2,height()));
        quiz_box[i]->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
        quiz[i]->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    }


    scroll->setWidgetResizable(true);


    //stile menubar
    menubar->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Fixed);

    //stile layout scroll
    scroll_layout->setAlignment(Qt::AlignCenter);
    scroll_layout->setSpacing(10);

    //stile bottone end_quiz
    end_quiz->setFixedHeight(height()/5);



    //aggiunta foglio di stile
    QFile file(":/Resources/style_containerquiz.css");
    file.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(file.readAll());

    setStyleSheet(styleSheet);
}
