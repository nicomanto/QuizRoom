﻿#include "courseform.h"


CourseForm::CourseForm(User* u,Controller& c,Course* course, bool & r,QWidget *parent): PrincipalForm(u,c,r,parent), this_course(course), container_course(new QGroupBox(this)),container_center(new QGroupBox(this)), info_course_layout(new QVBoxLayout(container_course)),
    center_layout(new QHBoxLayout(container_center)), scroll_layout(new QGridLayout(container_scroll)), course_title(new QLabel(QString::fromStdString(this_course->getTitle()),this)),
    course_description(new QLabel(QString::fromStdString(this_course->getDescription()),this)),course_code(new QLabel(QString::fromStdString("Codice: "+this_course->getCode()),this)){

    main_layout=new QVBoxLayout(this);
    scroll= new QScrollArea(this);
    menubar=new QMenuBar(this);


    addMenu();
    addForm();
    setStyle();

    setLayout(main_layout);
}

CourseForm *CourseForm::clone() const{
    return new CourseForm(user,control,this_course,relogin,parentWidget());
}

void CourseForm::addMenu(){

    QMenu* options = new QMenu("Opzioni",menubar);
    QMenu* course= new QMenu("Corso",menubar);
    QMenu*  homework= new QMenu("Compito",menubar);

    QAction* previous_page= new QAction("<-",menubar); //torno alla pagina precedente
    QAction* exit_login = new QAction("ritorna alla pagina di login",options);

    bool can_do_somethingC=false;
    bool can_do_somethingH=false;

    if(user->CanAddHomework()){ //controllare se l'utente può aggiungere homework
        QAction* add_homework = new QAction("crea compito",homework);
        homework->addAction(add_homework);
        connect(add_homework,SIGNAL(triggered()),this,SLOT(to_addhomework()));
        can_do_somethingH=true;
    }

    if(user->CanEditCourse()){ //controllare se l'utente può modificare il corso
        QAction* modify_course = new QAction("modifica",homework);
        course->addAction(modify_course);
        connect(modify_course,SIGNAL(triggered()),this,SLOT(to_course_info()));
        can_do_somethingC=true;
    }

    if(user->CanDeleteHomework()){ //controllare se l'utente può eliminare il corso
        QAction* delete_course = new QAction("elimina",homework);
        course->addAction(delete_course);
        connect(delete_course,SIGNAL(triggered()),this,SLOT(del_course()));
        can_do_somethingC=true;
    }

    options->addAction(exit_login);


    menubar->addAction(previous_page);
    menubar->addMenu(options);

    if(can_do_somethingC)
        menubar->addMenu(course);

    if(can_do_somethingH)
        menubar->addMenu(homework);

    main_layout->addWidget(menubar);


    //connect della previous_page
    connect(previous_page, SIGNAL(triggered()),this,SLOT(to_previous_page()));

    //connect della exit_to_login
    connect(exit_login,SIGNAL(triggered()),this,SLOT(to_login())); //tests
}

void CourseForm::addForm(){


    info_course_layout->addWidget(course_title);
    info_course_layout->addWidget(course_description);
    info_course_layout->addWidget(course_code);

    container_course->setMaximumWidth(width());

    center_layout->addWidget(container_course);
    center_layout->addWidget(scroll);

    scroll->setWidget( container_scroll );

    QSignalMapper* signalMapperHomework = new QSignalMapper (this);

    //aggiungo i compiti del corso
    for(unsigned int i=0; i <this_course->getHomeworks().size(); ++i){
        QString s= "Compito " + QString::number(i);
        homework.push_back(new QPushButton(QString::fromStdString(this_course->getHomeworks()[i]->getTitle()),this));

        //connect del bottone compito
        connect(homework[i],SIGNAL(clicked()),signalMapperHomework,SLOT(map()));
        signalMapperHomework->setMapping(homework[i], i);


        homework_menu.push_back(new QPushButton(homework[i]));
        homework_menu[i]->setVisible(false); //setto invisibile perchè non so se può modificarlo

        scroll_layout->addWidget(homework[i],i,0);




        if(addMenuButton(homework_menu[i],i))
            homework_menu[i]->setVisible(true);

        scroll_layout->addWidget(homework_menu[i],i,1);


    }

    connect (signalMapperHomework, SIGNAL(mapped(int)), this, SLOT(to_next_page(int)));

    main_layout->addWidget(container_center);
}

void CourseForm::setStyle(){
    PrincipalForm::setStyle();

    //stile dei bottoni homework e homework_menu
    for(unsigned int i=0; i <this_course->getHomeworks().size(); ++i){
        homework[i]->setMinimumSize(width()/3,height()/5);
        homework[i]->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
        homework[i]->setMaximumSize(QSize(1000,height()/5));

        //if(true)//controllo se è creato
            homework_menu[i]->setFixedSize(22,height()/5);
    }


    //stile del course title
    course_title->setAlignment(Qt::AlignCenter);
    course_title->setTextInteractionFlags(Qt::TextSelectableByMouse);
    course_title->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Minimum);
    course_title->setWordWrap(true);

    //stile del course description
    course_description->setAlignment(Qt::AlignCenter);
    course_description->setTextInteractionFlags(Qt::TextSelectableByMouse);
    course_description->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);
    course_description->setWordWrap(true);

    //stile del coruse code
    course_code->setAlignment(Qt::AlignCenter);
    course_code->setTextInteractionFlags(Qt::TextSelectableByMouse);
    course_code->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    course_code->setWordWrap(true);


    //stile info corso
    info_course_layout->setAlignment(Qt::AlignCenter);
    container_course->setMaximumWidth(width()/2);
    info_course_layout->setSpacing(50);


    //stile scroll
    scroll_layout->setAlignment(Qt::AlignCenter);
    scroll->setMinimumWidth(width()/2);
    scroll_layout->setSpacing(0);


    //aggiunta dei font di alcuni elementi
    QFont font( "Arial", 18, QFont::Bold);
    course_title->setFont(font);

    font=QFont( "Arial", 14);
    course_description->setFont(font);

    font=QFont( "Arial", 12);
    course_code->setFont(font);


    //stile scroll area
    //scroll->setMaximumWidth(width()*2);
    scroll->setWidgetResizable(true);

    //stile menubar
    menubar->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Fixed);


    //aggiunta foglio di stile
    QFile file(":/Resources/style_course.css");
    file.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(file.readAll());

    setStyleSheet(styleSheet);
}


bool CourseForm::addMenuButton(QPushButton *b,unsigned int i){
    MenuButton* button_options = new MenuButton(i,b,this);
    bool temp=false;

    QSignalMapper* signalMapperDelete = new QSignalMapper (this);


    //controllare se un utente può eliminare un corso
    if(user->CanDeleteHomework()){
        QAction* del = new QAction("Elimina",button_options);
        button_options->addAction(del);
        temp=true;

        connect(del,SIGNAL(triggered()),signalMapperDelete,SLOT(map()));
        signalMapperDelete -> setMapping (del, i) ;
    }

    connect (signalMapperDelete, SIGNAL(mapped(int)), this, SLOT(del_homework(int)));

    b->setMenu(button_options);

    return temp;

}



//SLOTS
/*void CourseForm::to_previous_page(){
    emit to_new_page(new MainForm(user,control,relogin, parentWidget()));

    close();
}*/


void CourseForm::to_next_page(int index){
    emit to_new_page(new HomeworkForm(user,control,this_course->getHomeworks()[index],relogin,parentWidget()));

    close();
}



void CourseForm::to_addhomework(){
    QDialog* dialog = new QDialog(this);
    QVBoxLayout* layout_dialog = new QVBoxLayout(dialog);

    AddHomeworkForm* temp= new AddHomeworkForm("","",dialog);
    layout_dialog->addWidget(temp);

    layout_dialog->setSizeConstraint( QLayout::SetFixedSize );

    connect(temp,SIGNAL(addHomeworkinformation(const QString& ,const QString&, bool, bool, const DateTime&)),this,SLOT(confirm_addhomework(const QString& ,const QString&, bool, bool, const DateTime&)));
    connect(temp,SIGNAL(toClose()),dialog,SLOT(close()));

    dialog->show();
}

void CourseForm::to_course_info(){
    to_addform(course_title->text(),course_description->text());
}

void CourseForm::del_course(){
    control.deleteCourse(this_course);
    //emit to_new_page(new CourseForm(user,control,this_course,relogin,parentWidget()));
    emit to_update_previous_page();

    to_previous_page();
}

void CourseForm::del_homework(int i){

    control.deleteHomework(this_course,i);

    emit to_new_page(new CourseForm(user,control,this_course,relogin,parentWidget()));
    control.removeStackView();

    close();
}


/*void CourseForm::to_modifyform(Course *c, const QString &title, const QString &description){
    QDialog* dialog = new QDialog(this);
    QVBoxLayout* layout_dialog = new QVBoxLayout(dialog);

    ModifyAddForm* temp= new ModifyAddForm(title,description,dialog);
    layout_dialog->addWidget(temp);

    connect(temp,SIGNAL(addinformationcourse(Course*, const QString&, const QString&)),this,SLOT(confirm_modifyform(Course* ,const QString&, const QString&)));
    connect(temp,SIGNAL(toClose()),dialog,SLOT(close()));

    layout_dialog->setSizeConstraint( QLayout::SetFixedSize );

    dialog->show();
}

void CourseForm::confirm_modifyform(Course * c, const QString &, const QString &){
    if(t=="")
         throw std::runtime_error("Titolo mancante");


    control.addCourse(user,t.toStdString(),d.toStdString());


    emit to_new_page(new MainForm(user,control,relogin,parentWidget()));

    close();
}*/


void CourseForm::confirm_addform(const QString& t, const QString& d){

   control.modifyCourse(this_course,t.toStdString(),d.toStdString());

   emit to_update_previous_page();
   CourseForm* temp= new CourseForm(user,control,this_course,relogin,parentWidget());
   emit to_new_page(temp);



   control.removeStackView();


   //close();
}


void CourseForm::confirm_addhomework(const QString& t,const QString& d, bool Time, bool Score, const DateTime& deadline){




    control.AddHomework(this_course,t.toStdString(),d.toStdString(),Time,Score,deadline);



    emit to_update_previous_page();
    CourseForm* temp= new CourseForm(user,control,this_course,relogin,parentWidget());
    emit to_new_page(temp);



    control.removeStackView();
}



