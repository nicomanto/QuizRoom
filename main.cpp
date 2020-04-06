#include "Model/Header/quizroom.h"
#include <iostream>
#include <QApplication>
#include <string.h>

#include "Model/Header/myvector.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QuizRoom w;
    w.show();
    return a.exec();
}
