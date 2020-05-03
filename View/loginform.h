#ifndef LOGIN_H
#define LOGIN_H

#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include "formvirtual.h"


class LoginForm : public FormVirtual{
    Q_OBJECT

private:
    QPushButton *login_button;
    QLineEdit *username_form;
    QLineEdit *password_form;
    QLabel* username;
    QLabel* password;
public:
    explicit LoginForm(QWidget *parent = nullptr);
    ~LoginForm()= default;

    virtual void addMenu();

    virtual void addForm();

    virtual void setStyle();





signals:

public slots:
    void open(){
        show();
    }
};

#endif // LOGIN_H
