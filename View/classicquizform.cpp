#include "classicquizform.h"


ClassicQuizForm::ClassicQuizForm(Controller& c, ClassicQuiz* q, QWidget *parent): QuizBaseForm(c, QString::fromStdString(q->getQuestion()),parent), this_quiz(q){
    main_layout= new QVBoxLayout(this);

    container_answers= new QGroupBox(this);
    answers_layout= new QGridLayout(container_answers);



    randomize_answer();

    addForm();

    setStyle();

    setLayout(main_layout);

    //connect del parent (containerquizform) per quando clicca su termina e quindi si invieranno le risposte inserite
    connect(parentWidget(),SIGNAL(getAnswers()),this,SLOT(getAnswers()));
}

void ClassicQuizForm::getAnswers(){
    for(unsigned int i=0; i< answers.size();++i)
        if(answers[i]->isChecked())
            control.addPointClassicQuiz(this_quiz,answers[i]->text().toStdString());
}


void ClassicQuizForm::addForm(){
    main_layout->addWidget(question);


    //aggiunta delle possibili risposte
    int j=-1;

    for(unsigned int i=0; i<answers.size();++i){
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

    for(unsigned int i=0;i<answers.size();++i){
        answers[i]->setCheckable(true);
    }
}

void ClassicQuizForm::randomize_answer(){
    unsigned int count= control.getAnswersClassicQuizSize(this_quiz);
    srand(time(NULL));
    bool exist;
    MyVector<int>  already_included(1,-1);
    int number;

    while(count>0){


        do{
            exist=false;
            number=rand()%control.getAnswersClassicQuizSize(this_quiz);

            for(unsigned int i=0;i<already_included.size() && !exist;++i){
                if(number==already_included[i])
                    exist=true;
            }

        }while(exist);

        already_included.push_back(number);

        count--;
        answers.push_back(new QPushButton(QString::fromStdString(control.getAnsweratIndexClassicQuiz(this_quiz,number)),this));


    }
}



