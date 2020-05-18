#ifndef LOGIN_H
#define LOGIN_H

#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QFile>
#include <QStyle>

#include <QGroupBox>

#include "baseform.h"
#include "Model/vectorusers.h"

class LoginForm : public BaseForm{
    Q_OBJECT

private:
    VectorUsers& Users;
    bool & relogin;

    QPushButton *login_button;
    QLineEdit *username_form;
    QLineEdit *password_form;
    QLabel* username;
    QLabel* password;

    virtual void addForm();

    virtual void setStyle();


public:
    explicit LoginForm(VectorUsers& u,bool &r,QWidget *parent = nullptr);
    ~LoginForm()= default;





signals:

private slots:
    void to_principalform();
};

#endif // LOGIN_H
