#include "addclassicquizform.h"

AddClassicQuizForm::AddClassicQuizForm(Controller& c,Homework* h, int number_question, QWidget *parent): AddQuizForm(c,h,number_question, parent){

    main_layout=new QVBoxLayout(this);

    for(unsigned int i=0; i<4; ++i){
        check_answers.push_back(new QCheckBox(this));
        answers_form.push_back(new QLineEdit(this));
    }



    addForm();

    setStyle();

    setLayout(main_layout);

    connect(parentWidget(),SIGNAL(setInformation()),this,SLOT(setInformation()));

}

void AddClassicQuizForm::setInformation(){
    MyVector<std::string> answers;
    MyVector<std::string> correct_answers;

    for(unsigned int i=0;i<answers_form.size();i++){
        if(check_answers[i]->checkState()){
            correct_answers.push_back(answers_form[i]->text().toStdString());
        }

        answers.push_back(answers_form[i]->text().toStdString());
    }


        control.addClassicQuiz(this_homework,question_form->text().toStdString(),answers,correct_answers);


}


void AddClassicQuizForm::addForm(){

    main_layout->addWidget(box_question);
    main_layout->addWidget(box_answer);

     layout_box_question->addWidget(question_form);

    int j=0,k=0;
    for(unsigned int i=0; i<4;++i){

        if(i%2==0){
            j++;
            k=0;
        }

        QWidget* container_answer=new QWidget(this);
        QHBoxLayout* layout_container_answers=new QHBoxLayout(container_answer);
        layout_container_answers->addWidget(check_answers[i]);
        layout_container_answers->addWidget(answers_form[i]);

        layout_container_answers->setSpacing(5);
        container_answer->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);

        layout_box_answer->addWidget(container_answer,j,k);
        k++;
    }



}

void AddClassicQuizForm::setStyle(){
    AddQuizForm::setStyle();

    for(unsigned int i=0; i<4; ++i){
        answers_form[i]->setPlaceholderText("Pinna la risposta se è corretta");
        answers_form[i]->setMinimumWidth(width()/3);
    }
}


