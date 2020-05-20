#ifndef COURSEFORM_H
#define COURSEFORM_H
#include <QPushButton>
#include <QLabel>
#include <QFile>
#include <QScrollArea>
#include <QString>

#include "menubutton.h"
#include "Model/myvector.h"
#include "mainform.h"
#include "homeworkform.h"
#include "addhomeworkform.h"

class CourseForm : public PrincipalForm{
    Q_OBJECT

private:

    Course* this_course;

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

    virtual bool addMenuButton(QPushButton* ,unsigned int i);
public:
    explicit CourseForm(User* u, Controller& c,Course* course,bool & r, QWidget *parent = nullptr);
    ~CourseForm()= default;




public slots:
    void to_addhomework();
    void to_course_info();
    void del_course();
    void del_homework(int);

    //void to_modifyform(Course* c,const QString& title="", const QString& description="");
    //void confirm_modifyform(Course* ,const QString&, const QString&);

    virtual void confirm_addform(const QString&, const QString&);
    void confirm_addhomework(const QString& ,const QString&, bool Time, bool Score, const DateTime&);

    virtual void to_next_page(int index);
    virtual void to_previous_page();

};

#endif // COURSEFORM_H
