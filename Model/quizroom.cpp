#include "../Header/quizroom.h"
#include "ui_quizroom.h"

QuizRoom::QuizRoom(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::QuizRoom)
{
    ui->setupUi(this);
}

QuizRoom::~QuizRoom()
{
    delete ui;
}

