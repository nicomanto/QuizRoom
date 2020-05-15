#include "addquizform.h"

AddQuizForm::AddQuizForm(int number_question,QWidget *parent): BaseForm(parent),box_question(new QGroupBox("Domanda "+QString::number(number_question),this)),box_answer(new QGroupBox("Risposte",this)),layout_box_question(new QVBoxLayout(box_question)), layout_box_answer(new QGridLayout(box_answer)),
    question_form(new QLineEdit(box_question)){}

AddQuizForm::~AddQuizForm(){}

void AddQuizForm::setStyle(){
    BaseForm::setStyle();

    //larghezza della question_form fissa
    question_form->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Fixed);
    question_form->setMaximumWidth(width()/2);


    //centro la QLineDella domanda al centro
    layout_box_question->setAlignment(Qt::AlignCenter);


    //imposto la scritto dei box al centro ed espandibili
    box_question->setAlignment(Qt::AlignCenter);
    box_question->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    box_answer->setAlignment((Qt::AlignCenter));
    box_answer->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);


    //imposta la dimensione espandibile dalla window
    setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);


    //imposto il foglio di stile
    QFile file(":/Resources/style_addquizform.css");
    file.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(file.readAll());

    setStyleSheet(styleSheet);
}


