#include "addcombinequizform.h"

AddCombineQuizForm::AddCombineQuizForm(QWidget *parent): AddQuizForm(parent){
    main_layout=new QVBoxLayout(this);

    for(unsigned int i=0; i<4; ++i){
        options_form.push_back(new QLineEdit(this));
        answers_form.push_back(new QLineEdit(this));
    }



    addForm();

    setStyle();

    setLayout(main_layout);
}



void AddCombineQuizForm::addForm(){

    main_layout->addWidget(box_question);
    main_layout->addWidget(box_answer);

    layout_box_question->addWidget(question_form);


    for(unsigned int i=0; i<4;++i){
        layout_box_answer->addWidget(options_form[i],i,0);
        layout_box_answer->addWidget(answers_form[i],i,1);

    }



}

void AddCombineQuizForm::setStyle(){
    AddQuizForm::setStyle();

    for(unsigned int i=0; i<4; ++i){
        options_form[i]->setPlaceholderText("Opzione "+QString::number(i+1));
        answers_form[i]->setPlaceholderText("Riposta "+QString::number(i+1));

        options_form[i]->setMaximumWidth(width()/3);
        answers_form[i]->setMaximumWidth(width()/3);
    }
}
