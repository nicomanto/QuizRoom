#include "quizbaseform.h"


QuizBaseForm::QuizBaseForm(Controller& c,const QString& q ,QWidget *parent):BaseForm(parent), control(c), question(new QLabel(q,this)), container_answers(nullptr),answers_layout(nullptr){}

QuizBaseForm::~QuizBaseForm(){}

void QuizBaseForm::setStyle(){

    question->setAlignment(Qt::AlignCenter); //allineo question al centro della pagina
    question->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding); //setto question espandibile in base alla dimensione della pagina
    question->setMaximumHeight(height()*3);  //setto l'ampiezza massima di question
    question->setWordWrap(true);  //la scritta di question può andare a capo

    question->setStyleSheet("font-size: 18pt;"); //imposto il font diverso per question
    setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);  //window espandibile


    main_layout->setAlignment(Qt::AlignCenter);  //layout del quiz al centro
    container_answers->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding); //contenitore di domande espandibile

    answers_layout->setSpacing(20);

    QFile file(":/Resources/Style_sheet/style_quiz.css");
    file.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(file.readAll());

    setStyleSheet(styleSheet);
}
