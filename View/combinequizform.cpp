#include "combinequizform.h"

CombineQuizForm::CombineQuizForm(CombineQuiz* q, QWidget *parent): QuizBaseForm(QString::fromStdString(q->getQuestion()), parent), this_quiz(q){
    main_layout= new QVBoxLayout(this);

    //question=new QLabel("Famiglia dell'animale?",this);
    container_answers= new QGroupBox(this);
    answers_layout= new QGridLayout(container_answers);

    answers.push_back(new QComboBox(this));
    answers.push_back(new QComboBox(this));
    answers.push_back(new QComboBox(this));
    answers.push_back(new QComboBox(this));

    /*elements.push_back(new QLabel("Cavallo",this));
    elements.push_back(new QLabel("Lucertola",this));
    elements.push_back(new QLabel("Delfino",this));
    elements.push_back(new QLabel("Pesce pagliaccio",this));*/

    randomize_answer();



    //std::cout<<this_quiz->getCorrectAnswer().at("lucertola")<<std::endl;






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

void CombineQuizForm::randomize_answer(){
    //inserisco le risposte nel combo_box
    bool temp;
    for(unsigned int i=0;i <answers.size(); ++i){

        for (std::map<std::string,std::string>::const_iterator it=this_quiz->getCorrectAnswer().begin(); it!=this_quiz->getCorrectAnswer().end(); ++it){
            temp=true;

            for(unsigned int j=0;j <answers[i]->count() && temp; ++j){
                if(QString::fromStdString(it->second)==answers[i]->itemText(j))
                    temp=false;

            }


            if(temp)
                answers[i]->addItem(QString::fromStdString(it->second));
        }
    }


    //randomizzo gli elementi da abbinare
    unsigned int count= this_quiz->getCorrectAnswer().size();
    srand(time(NULL));
    bool exist;

    MyVector<int>  already_included(1,-1);
    unsigned int number;

    MyVector<std::string> elem;

    for (std::map<std::string,std::string>::const_iterator it=this_quiz->getCorrectAnswer().begin(); it!=this_quiz->getCorrectAnswer().end(); ++it){
        elem.push_back(it->first);
    }


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

        elements.push_back(new QLabel(QString::fromStdString(elem[number]),this));
    }
}


