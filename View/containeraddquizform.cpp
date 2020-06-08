#include "containeraddquizform.h"

ContainerAddQuizForm::ContainerAddQuizForm(User* u,Controller& c,Homework* h,bool & r,QWidget *parent): PrincipalForm(u,c,r,parent),this_homework(h),container_quiz(new QWidget(this)), layout_container_quiz(new QVBoxLayout(container_quiz)), scroll_layout(new QVBoxLayout(container_scroll)),end(new QPushButton("termina",this)), add_combine(new QPushButton("Quiz a combinazione",this)),
    add_classic(new QPushButton("Quiz classico",this)),container_button(new QWidget(this)), layout_button(new QHBoxLayout(container_button)){

    main_layout=new QVBoxLayout(this);
    menubar=new QMenuBar(this);
    scroll= new QScrollArea(this);

    addMenu();
    addForm();
    setStyle();

    setLayout(main_layout);
}


void ContainerAddQuizForm::addMenu(){

    QAction* previous_page= new QAction(QIcon(":/Resources/Images/left_arrow.png"),"",menubar); //torno alla pagina precedente

    menubar->addAction(previous_page);

    main_layout->addWidget(menubar);

    //connect della previous_page
    connect(previous_page, SIGNAL(triggered()),this,SLOT(to_previous_page()));
}

void ContainerAddQuizForm::addForm(){

   main_layout->addWidget(scroll);

   scroll->setWidget( container_scroll );

   scroll_layout->addWidget(container_quiz);

   scroll_layout->addWidget(container_button);

   layout_button->addWidget(end);
   layout_button->addWidget(add_combine);
   layout_button->addWidget(add_classic);

   connect(add_classic,SIGNAL(clicked()),this,SLOT(addClassicWidget()));
   connect(add_combine,SIGNAL(clicked()),this,SLOT(addCombineWidget()));
   connect(end,SIGNAL(clicked()),this,SLOT(to_add_quiz()));



}

void ContainerAddQuizForm::setStyle(){
    PrincipalForm::setStyle();
    main_layout->setSpacing(0);



    scroll->setWidgetResizable(true);


    //stile menubar
    menubar->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Fixed);

    //stile layout scroll
    scroll_layout->setAlignment(Qt::AlignCenter);
    scroll_layout->setSpacing(10);

    //stile layout del button
    layout_button->setAlignment(Qt::AlignCenter);


    container_quiz->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);


    //setto la dimensione minima della finistra
    //setMinimumSize(QSize(width_screen/3,height_screen/3));

    //aggiunta foglio di stile
    QFile file(":/Resources/Style_sheet/style_containeraddquiz.css");
    file.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(file.readAll());

    setStyleSheet(styleSheet);
}


ContainerAddQuizForm *ContainerAddQuizForm::clone() const{
    return new ContainerAddQuizForm(user,control,this_homework,relogin,parentWidget());
}




//SLOTS
void ContainerAddQuizForm::addCombineWidget(){
    AddCombineQuizForm* temp= new AddCombineQuizForm(control,this_homework,quiz.size()+1,this);
    quiz.push_back(temp);

    layout_container_quiz->addWidget(quiz.back());
}

void ContainerAddQuizForm::addClassicWidget(){
    quiz.push_back(new AddClassicQuizForm(control,this_homework,quiz.size()+1,this));
    layout_container_quiz->addWidget(quiz.back());
}

void ContainerAddQuizForm::to_next_page(int index){}


void ContainerAddQuizForm::to_add_quiz(){


    try{

        //controllare se il vettore contiene già dei quiz->significa che prima non si è riusciti ad inviare tutti i quiz per qualche eccezzione
        //evita che ci siano dei duplicati dei quiz
        if(!(control.haveEmptyQuiz(this_homework)))
            control.HomeworkClearQuiz(this_homework);

        emit setInformation();
        emit to_update_previous_page();
        to_previous_page();



        //control.removeStackView();

    }catch(std::logic_error exc){
        ErrorMessage* error = new ErrorMessage(exc.what());


        error->show();
    }


}

