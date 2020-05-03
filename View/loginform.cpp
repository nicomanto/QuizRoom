#include "loginform.h"

LoginForm::LoginForm(QWidget *parent) : FormVirtual(parent){

    main_layout = new QVBoxLayout(this);

    addForm();

    setStyle();

    setLayout(main_layout);



}

void LoginForm::addMenu(){}
/*{
    menubar = new QMenuBar(this);
    QMenu* menu = new QMenu("Options",menubar);
    QAction* exit = new QAction("Exit to login",menu);

    menu->addAction(exit);

    connect(exit,SIGNAL(triggered()),this,SLOT(close()));


    menubar->addMenu(menu);

    main_layout->addWidget(menubar);
}*/

void LoginForm::addForm()
{
    login_button = new QPushButton("Login",this);
    username_form= new QLineEdit(this);
    password_form= new QLineEdit(this);
    username= new QLabel("Username", this);
    password= new QLabel("Password",this);

    main_layout->addWidget(username);
    main_layout->addWidget(username_form);

    main_layout->addWidget(password);
    main_layout->addWidget(password_form);

    main_layout->addWidget(login_button);
}

void LoginForm::setStyle(){
    FormVirtual::setStyle();


    username->setAlignment(Qt::AlignCenter);
    password->setAlignment(Qt::AlignCenter);


    username_form->setFixedWidth(300);
    password_form->setFixedWidth(300);
    login_button->setFixedWidth(300);
    login_button->setFixedHeight(50);

    password_form->setEchoMode(QLineEdit::Password);
    setFixedSize(QSize(600,200));
    setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);




}
