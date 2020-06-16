#ifndef ADDHOMEWORKFORM_H
#define ADDHOMEWORKFORM_H

#include <QCheckBox>
#include <QIntValidator>
#include <QDateTimeEdit>
#include <QTimeZone>

#include "modifyaddform.h"

#include "Model/datetime.h"



class AddHomeworkForm : public ModifyAddForm{
    Q_OBJECT

private:

    QCheckBox* is_score;
    QCheckBox* is_time;

    QDateTimeEdit* deadline;  //dove scrivere la deadline

    QWidget* score_time_information;  //widget dell'informazioni sul tipo di compito(score/time)
    QGridLayout* layout_ST_infomation;  //layout del widget contenitore delle informazioni

    QPushButton* add_quiz;

    virtual void addForm();

    virtual void setStyle();

public:
    explicit AddHomeworkForm(const QString& title, const QString& description, QWidget *parent = nullptr);
    ~AddHomeworkForm()= default;



signals:
    //invia i dati del compito da salvare
    void addHomeworkinformation(const QString& ,const QString&, bool Time, bool Score, const DateTime&);

private slots:

    //emette il segnale per inviare i dati del compito
    void send_homework_information();


};

#endif // ADDHOMEWORKFORM_H
