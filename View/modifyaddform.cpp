#include "modifyaddform.h"

ModifyAddForm::ModifyAddForm(const QString& title, const QString& description, QWidget *parent): BaseForm(parent),box_title(new QGroupBox("Titolo",this)),box_description(new QGroupBox("Descrizione",this)),layout_box_title(new QVBoxLayout(box_title)), layout_box_description(new QVBoxLayout(box_description)),
    title_form(new QLineEdit(title,box_title)), description_form(new QTextEdit(description,box_description)),confirm_button(new QPushButton("Conferma",this)),container_button(new QWidget(this)), layout_button(new QVBoxLayout(container_button)){

    main_layout=new QVBoxLayout(this);

    addForm();

    setStyle();

    setLayout(main_layout);

}




void ModifyAddForm::addForm(){

    main_layout->addWidget(box_title);
    main_layout->addWidget(box_description);

    layout_box_title->addWidget(title_form);
    layout_box_description->addWidget(description_form);

    layout_button->addWidget(confirm_button);
    main_layout->addWidget(container_button);

    connect(confirm_button,SIGNAL(clicked()),this,SLOT(send_information()));

}

void ModifyAddForm::setStyle(){
    BaseForm::setStyle();

    //larghezza del title_form fissa
    title_form->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Fixed);


    //imposto la scritto dei box al centro
    box_title->setAlignment(Qt::AlignCenter);
    box_description->setAlignment((Qt::AlignCenter));

    //setta la taglia della window
    setFixedSize(QSize(width_screen/2,height_screen/2));

    //imposta la dimensione fissa dalla window
    setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);

    //imposto l'altezza fissa del bottone
    confirm_button->setFixedHeight(height()/8);
    confirm_button->setFixedWidth(width()/4);
    confirm_button->setAutoDefault(false);
    layout_button->setAlignment(Qt::AlignRight);




    //imposto il foglio di stile
    QFile file(":/Resources/Style_sheet/style_modifyaddform.css");
    file.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(file.readAll());

    setStyleSheet(styleSheet);
}




//SLOTS

void ModifyAddForm::send_information(){
    try {
        emit addinformation(title_form->text(),description_form->toPlainText());
        parentWidget()->close();
    } catch(std::logic_error exc){
        //mostro l'errore all'utente
        ErrorMessage* error = new ErrorMessage(exc.what());


        error->show();
    }


}
