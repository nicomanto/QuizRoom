#include "quizbaseform.h"


QuizBaseForm::QuizBaseForm(QWidget *parent):BaseForm(parent), question(nullptr), container_answers(nullptr),answers_layout(nullptr){}

QuizBaseForm::~QuizBaseForm(){}

void QuizBaseForm::setStyle(){
    BaseForm::setStyle();

    question->setAlignment(Qt::AlignCenter);
    question->setStyleSheet("font: 18pt Times New Roman;");
    setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);

    answers_layout->setSpacing(20);
    container_answers->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);



    QFile file(":/Resources/style_quiz.css");
    file.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(file.readAll());

    setStyleSheet(styleSheet);
}
