#ifndef ADDCOURSECODE_H
#define ADDCOURSECODE_H

#include <QLineEdit>
#include <QPushButton>
#include <QFile>
#include "baseform.h"
#include "errormessage.h"

class AddCourseCode : public BaseForm{
    Q_OBJECT

private:

    QLabel* code_label;

    QLineEdit *code_form;

    QPushButton *confirm_button;

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
