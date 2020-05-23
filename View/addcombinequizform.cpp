#include "addcombinequizform.h"

AddCombineQuizForm::AddCombineQuizForm(Controller& c,Homework* h, int number_question, QWidget *parent): AddQuizForm(c,h, number_question, parent){
    main_layout=new QVBoxLayout(this);

    for(unsigned int i=0; i<4; ++i){
        options_form.push_back(new QLineEdit(this));
        answers_form.push_back(new QLineEdit(this));
    }



    addForm();

    setStyle();

    setLayout(main_layout);

    connect(parentWidget(),SIGNAL(setInformation()),this,SLOT(setInformation()));
}

void AddCombineQuizForm::setInformation(){
    MyVector<std::string> elements;
    MyVector<std::string> answers;

    for(unsigned int i=0;i<options_form.size();i++){
        elements.push_back(options_form[i]->text().toStdString());
        answers.push_back(answers_form[i]->text().toStdString());
    }



    control.addCombineQuiz(this_homework,question_form->text().toStdString(),elements,answers);



    //emit send_information(question_form->text().toStdString(),elements,answers);

    /*try {
        emit send_information(question_form->text().toStdString(),elements,answers);
        //emit toClose();
    } catch(std::logic_error exc){
        ErrorDialog* error = new ErrorDialog(exc.what(),this);


        error->show();
    }*/
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
