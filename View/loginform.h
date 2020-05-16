#ifndef LOGIN_H
#define LOGIN_H

#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QFile>
#include <QStyle>

#include <QGroupBox>

#include "baseform.h"

class LoginForm : public BaseForm{
    Q_OBJECT

private:
    QPushButton *login_button;
    QLineEdit *username_form;
    QLineEdit *password_form;
    QLabel* username;
    QLabel* password;

    virtual void addForm();

    virtual void setStyle();


public:
    explicit LoginForm(QWidget *parent = nullptr);
    ~LoginForm()= default;





signals:

private slots:
    void to_principalform();
};

#endif // LOGIN_H
