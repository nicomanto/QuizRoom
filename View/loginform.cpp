#include "loginform.h"
LoginForm::LoginForm(QWidget *parent) : BaseForm(parent), login_button(new QPushButton("Login",this)),username_form(new QLineEdit(this)), password_form(new QLineEdit(this)),username(new QLabel("Username", this)),password(new QLabel("Password", this)){
    main_layout= new QVBoxLayout(this);

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

void LoginForm::addForm(){
    main_layout->addWidget(username);
    main_layout->addWidget(username_form);

    main_layout->addWidget(password);
    main_layout->addWidget(password_form);

    main_layout->addWidget(login_button);
}

void LoginForm::setStyle(){
    BaseForm::setStyle();


    username->setAlignment(Qt::AlignCenter);
    password->setAlignment(Qt::AlignCenter);

    setFixedSize(QSize(width_screen/2.5,height_screen/3));

    username_form->setFixedWidth(width()/2);
    password_form->setFixedWidth(width()/2);
    login_button->setFixedWidth(width()/2);
    login_button->setFixedHeight(height()/5);

    password_form->setEchoMode(QLineEdit::Password);

    setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);


    QFile file(":/Resources/style_login.css");
    file.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(file.readAll());

    setStyleSheet(styleSheet);

}
