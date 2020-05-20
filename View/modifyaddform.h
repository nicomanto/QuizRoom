#ifndef MODIFYADDFORM_H
#define MODIFYADDFORM_H

#include <QLineEdit>
#include <QTextEdit>
#include <QPushButton>
#include <QGroupBox>
#include <QFile>
#include <QDialog>
#include <QLabel>

#include "baseform.h"
#include "errordialog.h"

#include "Model/course.h"


class ModifyAddForm : public BaseForm{
    Q_OBJECT

protected:
    QGroupBox* box_title;
    QGroupBox* box_description;

    QVBoxLayout* layout_box_title;
    QVBoxLayout* layout_box_description;

    QLineEdit *title_form;
    QTextEdit *description_form;

    QPushButton *confirm_button;

    QWidget* container_button; //container del button
    QBoxLayout* layout_button; //layout del container del button

    virtual void addForm();

    virtual void setStyle();

public:
    explicit ModifyAddForm(const QString& title, const QString& description, QWidget *parent);
    ~ModifyAddForm()= default;


signals:
    void addinformation(const QString& ,const QString&);
    void addinformationcourse(Course* c,const QString& title="", const QString& description="");
    void toClose();

private slots:
    void send_information();
};

#endif // MODIFYADDFORM_H
