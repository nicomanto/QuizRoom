#include "loginform.h"
#include "containerprincipalform.h"

LoginForm::LoginForm(Controller& c,bool & r,QWidget *parent) : BaseForm(parent), control(c),relogin(r),container_informations(new QWidget(this)),layout_informations(new QVBoxLayout(container_informations)),login_button(new QPushButton("Login")),username_form(new QLineEdit(this)), password_form(new QLineEdit(this)),username(new QLabel("Username", this)),password(new QLabel("Password", this)){

    main_layout=new QHBoxLayout(this);

    addForm();

    setStyle();

    setLayout(main_layout);


}



void LoginForm::addForm(){
    QPixmap img;
    img.load(":/Resources/Images/login.png");

    QLabel* ImgLogin = new QLabel;

    ImgLogin->setPixmap(img.scaled(200,200));
    //ImgLogin->setFixedSize(QSize(200,200));
    main_layout->addWidget(ImgLogin);

    main_layout->addWidget(container_informations);

    layout_informations->addWidget(username);
    layout_informations->addWidget(username_form);


    layout_informations->addWidget(password);
    layout_informations->addWidget(password_form);

    layout_informations->addWidget(login_button);

    //connect per il login
    connect(login_button, SIGNAL(clicked()),this,SLOT(to_principalform()));
    connect(username_form,SIGNAL(returnPressed()),login_button,SIGNAL(clicked()));
    connect(password_form,SIGNAL(returnPressed()),login_button,SIGNAL(clicked()));
}

void LoginForm::setStyle(){
    BaseForm::setStyle();

    setWindowTitle("QuizRoom - Login");

    username->setAlignment(Qt::AlignCenter);  //setta al centro la scritta 'username'
    password->setAlignment(Qt::AlignCenter); //setta al centro la scritta 'password'

    setFixedSize(QSize(width_screen/3,height_screen/4));  //setta la taglia della window


    //setto le dimensioni fisse dei vari form
    /*username_form->setFixedWidth(width()/2);
    password_form->setFixedWidth(width()/2);
    login_button->setFixedWidth(width()/2);
    login_button->setFixedHeight(height()/7);*/

   // main_layout->setSpacing(30);

    //imposta la modalitò 'testo oscurato'
    password_form->setEchoMode(QLineEdit::Password);


    //imposta la dimensione fissa dalla window
    setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);



    //imposto il foglio di stile
    QFile file(":/Resources/Style_sheet/style_login.css");
    file.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(file.readAll());

    setStyleSheet(styleSheet);

}



//SLOTS
void LoginForm::to_principalform(){

    try{
        ContainerPrincipalForm* m= new ContainerPrincipalForm(control.getUser((username_form->text()).toStdString(),(password_form->text()).toStdString()),control,relogin);

        m->showMaximized();

        close();
    }
    catch(std::logic_error exc){
       ErrorMessage* error = new ErrorMessage(exc.what());


        error->show();
    }
}
