#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include <QLineEdit>
#include <QPushButton>
#include <QApplication>
#include <QDesktopWidget>
#include <QVBoxLayout>
#include <QMenuBar>
#include <QFile>
#include <QStyle>
#include <QScreen>
#include <QLabel>


class LoginForm : public QWidget{
    Q_OBJECT

private:
    QVBoxLayout *main_layout;
    //QMenuBar* menubar;

    QPushButton *login_button;

    QLineEdit *username_form;
    QLineEdit *password_form;
    QLabel* username;
    QLabel* password;
public:
    explicit LoginForm(QWidget *parent = nullptr);
    ~LoginForm() = default;

    //void addMenu();

    void addForm();

    void setStyle();





signals:

public slots:
};

#endif // LOGIN_H
