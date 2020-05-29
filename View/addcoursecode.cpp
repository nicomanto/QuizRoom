#include "addcoursecode.h"

AddCourseCode::AddCourseCode(QWidget *parent): BaseForm(parent),code_form(new QLineEdit(this)),confirm_button(new QPushButton("Conferma",this)){
    main_layout= new QVBoxLayout(this);

    addForm();

    setStyle();

    setLayout(main_layout);
}




void AddCourseCode::addForm(){

    main_layout->addWidget(code_form);
    main_layout->addWidget(confirm_button);

    connect(confirm_button,SIGNAL(clicked()),this,SLOT(send_code()));
    connect(code_form,SIGNAL(returnPressed()),confirm_button,SIGNAL(clicked()));

}

void AddCourseCode::setStyle(){
    BaseForm::setStyle();


    code_form->setPlaceholderText("Inserisci il codice del corso");
    code_form->setMaxLength(7);
    //code_form->setAlignment(Qt::AlignCenter);


    //setta la taglia della window
    setFixedSize(QSize(width_screen/5,height_screen/5));
    //main_layout->SetFixedSize(QSize(width_screen/3,height_screen/3));

    //imposta la dimensione fissa dalla windowp
    setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);

    //imposto l'altezza fissa del bottone
    confirm_button->setFixedHeight(height()/4);
    code_form->setFixedHeight(height()/7);
    //confirm_button->setFixedWidth(width()/3);
    confirm_button->setAutoDefault(false);
    //layout_button->setAlignment(Qt::AlignRight);


}





//SLOTS
void AddCourseCode::send_code(){
    try {
        emit addCourse(code_form->text());
        parentWidget()->close();
    } catch(std::logic_error exc){
        ErrorMessage* error = new ErrorMessage(exc.what());


        error->show();
    }
}
