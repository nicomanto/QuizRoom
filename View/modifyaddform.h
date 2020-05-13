#ifndef MODIFYADDFORM_H
#define MODIFYADDFORM_H

#include <QLineEdit>
#include <QTextEdit>
#include <QPushButton>
#include <QGroupBox>
#include <QFile>

#include "baseform.h"


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
    QVBoxLayout* layout_button; //layout del container del button

public:
    explicit ModifyAddForm(QWidget *parent = nullptr);
    ~ModifyAddForm()= default;

    virtual void addForm();

    virtual void setStyle();

signals:

public slots:

};

#endif // MODIFYADDFORM_H
