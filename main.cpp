#include "Model/quizroom.h"
#include <iostream>
#include <QApplication>
#include <string.h> // per testare

#include "Model/myvector.h" //per testare

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QuizRoom w;
    w.show();
    return a.exec();
}
