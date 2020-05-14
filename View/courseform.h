#ifndef COURSEFORM_H
#define COURSEFORM_H
#include <QPushButton>
#include <QLabel>
#include <QFile>
#include <QScrollArea>
#include <QString>

#include "menubutton.h"
#include "Model/myvector.h"
#include "principalform.h"
#include "loginform.h"

class CourseForm : public PrincipalForm{
    Q_OBJECT
private:
    MyVector <QPushButton *> homework; //vettore dei pulsanti homework
    MyVector <QPushButton *> homework_menu;  //vettore dei pulsanti modifica homework

    QGroupBox* container_course; //contenitore delle informazioni del corso
    QGroupBox* container_center;  //contenitore degli elementi centrali della window (informazioni corso e i due vettori di bottoni)

    QVBoxLayout* info_course_layout;  // layout delle info del corso
    QHBoxLayout* center_layout;  //layout di container_center
    QGridLayout* scroll_layout;  //layout della scroll area

    QLabel* course_title;
    QLabel* course_description;
    QLabel* course_code;


    virtual void addMenu();

    virtual void addForm();

    virtual void setStyle();

    virtual void addMenuButton(QPushButton* b);
public:
    explicit CourseForm(const QString& title, QWidget *parent = nullptr);
    ~CourseForm()= default;




signals:

public slots:
};

#endif // COURSEFORM_H
