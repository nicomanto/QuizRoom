#include "Model/quizroom.h"
#include <iostream>
#include <QApplication>
#include <string.h> // per testare

#include "Model/myvector.h" //per testare

int main(int argc, char *argv[])
{

    MyVector<std::string> temp(5,"ciao"),f;
    f.push_back("ciao");
    std::cout<<f<<std::endl;
    temp.append(f);
    std::cout<<temp;
    std::cout<<temp.size()<<" "<<temp.capacity();
    temp.push_back("z");

    std::cout<<temp;
    temp.pop_back();
    std::cout<<temp.size()<<" "<<temp.capacity();

    temp.clear();
    temp.push_back("ciao");
    std::cout<<temp;
     std::cout<<temp.size()<<" "<<temp.capacity();


    /*QApplication a(argc, argv);
    QuizRoom w;
    w.show();
    return a.exec();*/
}
