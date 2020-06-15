#ifndef COURSEFORM_H
#define COURSEFORM_H

#include <QLabel>
#include <QString>

#include "menubutton.h"
#include "mainform.h"
#include "homeworkform.h"
#include "addhomeworkform.h"

#include "Model/myvector.h"

class CourseForm : public PrincipalForm{
    Q_OBJECT

private:

    Course* this_course;

    MyVector <QPushButton *> homework; //vettore dei pulsanti homework
    MyVector <QPushButton *> homework_menu;  //vettore dei pulsanti modifica homework

    QGroupBox* container_course; //contenitore delle informazioni del corso
    QWidget* container_center;  //contenitore degli elementi centrali della window (informazioni corso e i due vettori di bottoni)

    QVBoxLayout* info_course_layout;  // layout delle info del corso
    QHBoxLayout* center_layout;  //layout di container_center
    QGridLayout* scroll_layout;  //layout della scroll area

    QLabel* course_title;
    QLabel* course_description;
    QLabel* course_code;




    virtual void addMenu();

    virtual void addForm();

    virtual void setStyle();

    bool addMenuButton(QPushButton* ,unsigned int i);
public:
    explicit CourseForm(User* u, Controller& c,Course* course,bool & r, QWidget *parent = nullptr);
    ~CourseForm()= default;

    virtual CourseForm *clone() const;


private slots:
    //creazione form per la'ggiunta di un compito
    void to_addhomework();

    //invio dei dati del corso in cui mi trovo
    void to_course_info();

    //eliminazione del corso in cui mi trovo
    void del_course();

    //eliminazione del compito all'indice i del vettore
    void del_homework(int);

    virtual void confirm_addform(const QString&, const QString&);

    //aggiunta del nuovo compito appena creato
    void confirm_addhomework(const QString& ,const QString&, bool Time, bool Score, const DateTime&);

    virtual void to_next_page(int index);

};

#endif // COURSEFORM_H
