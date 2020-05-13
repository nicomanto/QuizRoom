#include "classicquizform.h"


ClassicQuizForm::ClassicQuizForm(QWidget *parent): QuizBaseForm(parent){
    main_layout= new QVBoxLayout(this);

    question=new QLabel("Che animale è il lupo?",this);
    container_answers= new QGroupBox(this);
    answers_layout= new QGridLayout(container_answers);

    answers.push_back(new QPushButton("risposta 1",this));
    answers.push_back(new QPushButton("risposta 2",this));
    answers.push_back(new QPushButton("risposta 3",this));
    answers.push_back(new QPushButton("risposta 4",this));


    addForm();

    setStyle();

    setLayout(main_layout);
}


void ClassicQuizForm::addForm(){
    main_layout->addWidget(question);


    //aggiunta delle possibili risposte
    int j=-1;
    for(unsigned int i=0; i<4;++i){
        if(i%2==0){
            j++;
            answers_layout->addWidget(answers[i],j,0,Qt::AlignCenter);
        }

        else
           answers_layout->addWidget(answers[i],j,1,Qt::AlignCenter);
    }


    main_layout->addWidget(container_answers);

}


void ClassicQuizForm::setStyle(){
    QuizBaseForm::setStyle();

    for(unsigned int i=0;i<4;++i){
        answers[i]->setCheckable(true);
    }
}



