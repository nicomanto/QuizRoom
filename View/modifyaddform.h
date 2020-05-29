#ifndef MODIFYADDFORM_H
#define MODIFYADDFORM_H

#include <QLineEdit>
#include <QTextEdit>
#include <QPushButton>
#include <QGroupBox>
#include <QFile>
#include <QLabel>

#include "baseform.h"
#include "errormessage.h"



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

    //invia le informazioni da aggiungere
    void addinformation(const QString& ,const QString&);

private slots:
    //slot per emettere addinformation() o per mostrare una finestra di errore
    void send_information();
};

#endif // MODIFYADDFORM_H
