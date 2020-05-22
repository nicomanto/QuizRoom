#include "classicquizform.h"


ClassicQuizForm::ClassicQuizForm(ClassicQuiz* q, QWidget *parent): QuizBaseForm(QString::fromStdString(q->getQuestion()),parent), this_quiz(q){
    main_layout= new QVBoxLayout(this);

    //question=new QLabel("Che animale è il lupo?",this);
    container_answers= new QGroupBox(this);
    answers_layout= new QGridLayout(container_answers);



    randomize_answer();
    /*answers.push_back(new QPushButton(QString::fromStdString(this_quiz->getCorrectAnswer()[1]),this));
    answers.push_back(new QPushButton(QString::fromStdString(this_quiz->getCorrectAnswer()[2]),this));
    answers.push_back(new QPushButton(QString::fromStdString(this_quiz->getCorrectAnswer()[3]),this));*/


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

void ClassicQuizForm::randomize_answer(){
    unsigned int count= this_quiz->getCorrectAnswer().size();
    srand(time(NULL));
    bool exist;
    MyVector<int>  already_included(1,-1);
    int number;

    while(count>0){


        do{
            exist=false;
            number=rand()%this_quiz->getCorrectAnswer().size();

            for(unsigned int i=0;i<already_included.size() && !exist;++i){
                if(number==already_included[i])
                    exist=true;
            }

        }while(exist);

        already_included.push_back(number);

        count--;
        answers.push_back(new QPushButton(QString::fromStdString(this_quiz->getCorrectAnswer()[number]),this));
    }
}



