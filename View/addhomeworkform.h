#ifndef ADDHOMEWORKFORM_H
#define ADDHOMEWORKFORM_H

#include <QCheckBox>
#include <QIntValidator>

#include "modifyaddform.h"


class AddHomeworkForm : public ModifyAddForm{
    Q_OBJECT

private:

    QCheckBox* is_score;
    QCheckBox* is_time;

    QLineEdit* max_score;  //dove scrivere il punteggio massimo
    QLineEdit* deadline;  //dove scrivere la deadline

    QWidget* score_time_information;  //widget dell'infomrazioni sul tipo di compito(score/time)
    QGridLayout* layout_ST_infomation;  //layout del widget contenitore delle informazioni

public:
    explicit AddHomeworkForm(QWidget *parent = nullptr);
    ~AddHomeworkForm()= default;

    virtual void addForm();

    virtual void setStyle();

signals:

public slots:

};

#endif // ADDHOMEWORKFORM_H