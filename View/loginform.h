#ifndef LOGIN_H
#define LOGIN_H

#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QFile>

#include "baseform.h"
#include "Control/controller.h"

class LoginForm : public BaseForm{
    Q_OBJECT

private:
    Controller& control;
    bool & relogin;

    QPushButton *login_button;
    QLineEdit *username_form;
    QLineEdit *password_form;
    QLabel* username;
    QLabel* password;

    virtual void addForm();

    virtual void setStyle();


public:
    explicit LoginForm(Controller& c,bool &r,QWidget *parent = nullptr);
    ~LoginForm()= default;


private slots:
    void to_principalform();
};

#endif // LOGIN_H
