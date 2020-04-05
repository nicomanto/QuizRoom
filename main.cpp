#include "quizroom.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QuizRoom w;
    w.show();
    return a.exec();
}
