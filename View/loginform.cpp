#include "loginform.h"

LoginForm::LoginForm(QWidget *parent) : QWidget(parent){

    main_layout = new QVBoxLayout(this);

    //addMenu();

    addForm();


    setStyle();

    setLayout(main_layout);



}

/*void LoginForm::addMenu()
{
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
    password_form->setEchoMode(QLineEdit::Password);
    //menubar->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Fixed);
    setFixedSize(QSize(600,200));
    setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);

    setWindowTitle("ClassRoom");


    setGeometry(QStyle::alignedRect(Qt::LeftToRight,Qt::AlignCenter,size(),qApp->desktop()->availableGeometry()));

    QFile file(":/Resources/style.css");
    file.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(file.readAll());

    setStyleSheet(styleSheet);

}
