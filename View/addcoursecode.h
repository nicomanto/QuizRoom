#ifndef ADDCOURSECODE_H
#define ADDCOURSECODE_H

#include <QLineEdit>
#include <QPushButton>
#include "baseform.h"
#include "errordialog.h"

class AddCourseCode : public BaseForm{
    Q_OBJECT

private:

    QLineEdit *code_form;

    QPushButton *confirm_button;

    /*QWidget* container_button; //container del button
    QBoxLayout* layout_button; //layout del container del button*/

    virtual void addForm();

    virtual void setStyle();

public:
    explicit AddCourseCode(QWidget *parent);
    ~AddCourseCode()= default;


signals:
    void addCourse(const QString&);
    //void toClose();

private slots:

    //slots per emettere il segnale addCourse;
    void send_code();

};

#endif // ADDCOURSECODE_H
