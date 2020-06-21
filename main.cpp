#include <QApplication>
#include <iostream>

#include "Control/controller.h"
#include "View/loginform.h"

int main(int argc, char *argv[]){

    QApplication a(argc, argv);
    a.setWindowIcon(QIcon(":/Resources/Images/quiz_app_icon.png"));

    Controller user;
    bool relogin;
    do{
        relogin=false;
        LoginForm* form= new LoginForm(user,relogin);

        form->show();
        a.exec();
    }while(relogin);



    return 0;
}
