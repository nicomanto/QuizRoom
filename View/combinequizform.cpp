#include "combinequizform.h"

CombineQuizForm::CombineQuizForm(QWidget *parent): QuizBaseForm(parent){
    main_layout= new QVBoxLayout(this);

    question=new QLabel("Famiglia dell'animale?",this);
    container_answers= new QGroupBox(this);
    answers_layout= new QGridLayout(container_answers);

    answers.push_back(new QComboBox(this));
    answers.push_back(new QComboBox(this));
    answers.push_back(new QComboBox(this));
    answers.push_back(new QComboBox(this));

    elements.push_back(new QLabel("Cavallo",this));
    elements.push_back(new QLabel("Lucertola",this));
    elements.push_back(new QLabel("Delfino",this));
    elements.push_back(new QLabel("Pesce pagliaccio",this));


    for(unsigned int i=0; i<4;++i){
        answers[i]->addItem("mammifero");
        answers[i]->addItem("rettile");
        answers[i]->addItem("presce");
    }



    addForm();

    setStyle();

    setLayout(main_layout);
}


void CombineQuizForm::addForm(){
    main_layout->addWidget(question);

    //aggiungo elementi da combinare e possibili risposte
    for(unsigned int i=0; i<4;++i){

            answers_layout->addWidget(elements[i],i,0,Qt::AlignCenter);


           answers_layout->addWidget(answers[i],i,1,Qt::AlignCenter);
    }


    answers_layout->setSpacing(20);
    main_layout->addWidget(container_answers);

}


