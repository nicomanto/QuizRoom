#include "addclassicquizform.h"

AddClassicQuizForm::AddClassicQuizForm(QWidget *parent): AddQuizForm(parent){

    main_layout=new QVBoxLayout(this);

    for(unsigned int i=0; i<4; ++i){
        check_answers.push_back(new QCheckBox(this));
        answers_form.push_back(new QLineEdit(this));
    }



    addForm();

    setStyle();

    setLayout(main_layout);

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

        layout_box_answer->addWidget(container_answer,j,k);
        k++;
    }



}

void AddClassicQuizForm::setStyle(){
    AddQuizForm::setStyle();

    for(unsigned int i=0; i<4; ++i){
        answers_form[i]->setPlaceholderText("Pinna la risposta se è corretta");
    }
}


