#include "loginform.h"
#include "mainform.h"
LoginForm::LoginForm(QWidget *parent) : BaseForm(parent), login_button(new QPushButton("Login",this)),username_form(new QLineEdit(this)), password_form(new QLineEdit(this)),username(new QLabel("Username", this)),password(new QLabel("Password", this)){

    main_layout=new QVBoxLayout(this);

    addForm();

    setStyle();

    setLayout(main_layout);

}



void LoginForm::addForm(){
    main_layout->addWidget(username);
    main_layout->addWidget(username_form);

    main_layout->addWidget(password);
    main_layout->addWidget(password_form);

    main_layout->addWidget(login_button);

    //connect per il login
    connect(login_button, SIGNAL(clicked()),this,SLOT(to_main()));
}

void LoginForm::setStyle(){
    BaseForm::setStyle();


    username->setAlignment(Qt::AlignCenter);  //setta al centro la scritta 'username'
    password->setAlignment(Qt::AlignCenter); //setta al centro la scritta 'password'

    setFixedSize(QSize(width_screen/2.5,height_screen/3));  //setta la taglia della window


    //setto le dimensioni fisse dei vari form
    username_form->setFixedWidth(width()/2);
    password_form->setFixedWidth(width()/2);
    login_button->setFixedWidth(width()/2);
    login_button->setFixedHeight(height()/7);

    main_layout->setSpacing(30);

    //imposta la modalitò 'testo oscurato'
    password_form->setEchoMode(QLineEdit::Password);


    //imposta la dimensione fissa dalla window
    setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);



    //imposto il foglio di stile
    QFile file(":/Resources/style_login.css");
    file.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(file.readAll());

    setStyleSheet(styleSheet);

}



//SLOTS
void LoginForm::to_main(){
    MainForm* m= new MainForm();

    m->showMaximized();

    close();
}
