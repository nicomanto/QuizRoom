#ifndef MODIFYCOURSEFORM_H
#define MODIFYCOURSEFORM_H

#include <QLineEdit>
#include <QTextEdit>
#include <QPushButton>
#include <QGroupBox>
#include <QFile>

#include "baseform.h"


class ModifyCourseForm : public BaseForm{
    Q_OBJECT

private:
    QGroupBox* box_title;
    QGroupBox* box_description;

    QVBoxLayout* layout_box_title;
    QVBoxLayout* layout_box_description;

    QLineEdit *title_form;
    QTextEdit *description_form;

    QPushButton *confirm_button;

public:
    explicit ModifyCourseForm(QWidget *parent = nullptr);
    ~ModifyCourseForm()= default;

    virtual void addForm();

    virtual void setStyle();





signals:

public slots:

};

#endif // MODIFYCOURSEFORM_H
