#include "addhomeworkform.h"

AddHomeworkForm::AddHomeworkForm(const QString& title, const QString& description, QWidget *parent): ModifyAddForm(title,description,parent), is_score(new QCheckBox("Compito con punteggio",this)),is_time(new QCheckBox("Compito con deadline",this))
  ,/*max_score(new QLineEdit(this))*/deadline(new QDateTimeEdit(QDate::currentDate().addDays(7),this)),score_time_information(new QWidget(this)), layout_ST_infomation(new QGridLayout(score_time_information)){

    delete confirm_button;
    confirm_button=new QPushButton("Conferma",this);
    addForm();

    setStyle();

    setLayout(main_layout);
}




void AddHomeworkForm::addForm(){

    main_layout->addWidget(box_title);
    main_layout->addWidget(box_description);

    layout_box_title->addWidget(title_form);
    layout_box_description->addWidget(description_form);

    layout_ST_infomation->addWidget(is_score,0,0,Qt::AlignCenter);
    layout_ST_infomation->addWidget(is_time,1,0,Qt::AlignCenter);
    layout_ST_infomation->addWidget(deadline,1,1,Qt::AlignCenter);



    layout_button->addWidget(confirm_button);

    connect(confirm_button,SIGNAL(clicked()),this,SLOT(send_homework_information()));

    main_layout->addWidget(score_time_information);

    main_layout->addWidget(container_button);

}

void AddHomeworkForm::setStyle(){
    ModifyAddForm::setStyle();

    deadline->setDisplayFormat("dd/MM/yyyy hh:mm");
    is_score->setFixedWidth(width()/3);
    is_time->setFixedWidth(width()/3);


    layout_button->setAlignment(Qt::AlignCenter);
    score_time_information->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    layout_ST_infomation->setAlignment(Qt::AlignCenter);

}




//SLOTS
void AddHomeworkForm::send_homework_information(){
    DateTime datetime(deadline->date().day(),deadline->date().month(), deadline->date().year(), deadline->time().hour(), deadline->time().minute());
    try{
            emit addHomeworkinformation(title_form->text(),description_form->toPlainText(),is_time->checkState(),is_score->checkState(),datetime);
            parentWidget()->close();
    } catch(std::logic_error exc){
            ErrorMessage* error = new ErrorMessage(exc.what());


            error->show();
    }

}
