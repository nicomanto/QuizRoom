#include "addhomeworkform.h"

AddHomeworkForm::AddHomeworkForm(const QString& title, const QString& description, QWidget *parent): ModifyAddForm(title,description,parent), is_score(new QCheckBox("Compito con punteggio",this)),is_time(new QCheckBox("Compito con deadline",this))
  ,max_score(new QLineEdit(this)),deadline(new QLineEdit(this)),score_time_information(new QWidget(this)), layout_ST_infomation(new QGridLayout(score_time_information)){


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
    layout_ST_infomation->addWidget(max_score,0,1,Qt::AlignCenter);
    layout_ST_infomation->addWidget(is_time,1,0,Qt::AlignCenter);
    layout_ST_infomation->addWidget(deadline,1,1,Qt::AlignCenter);



    layout_button->addWidget(confirm_button);

    main_layout->addWidget(score_time_information);

    main_layout->addWidget(container_button);

}

void AddHomeworkForm::setStyle(){
    ModifyAddForm::setStyle();

    max_score->setMaximumWidth(width()/3);
    deadline->setMaximumWidth(width()/3);
    is_score->setFixedWidth(width()/3);
    is_time->setFixedWidth(width()/3);
    max_score->setValidator( new QIntValidator(0, 100, this) );


    layout_button->setAlignment(Qt::AlignCenter);
    score_time_information->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    layout_ST_infomation->setAlignment(Qt::AlignCenter);
}
