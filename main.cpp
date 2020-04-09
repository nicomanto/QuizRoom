#include "Model/quizroom.h"
#include <iostream>
#include <QApplication>
#include <string.h> // per testare

#include "Model/myvector.h" //per testare

int main(int argc, char *argv[])
{

    MyVector<std::string> temp(5,"ciao");

    temp.pop_back();
    std::cout<<temp[4];
    std::cout<<"size:"<<temp.size()<<" "<<temp.capacity();

    MyVector<int> prova(10,10);
    int i=0;
    for(MyVector<int>::iterator r=prova.begin(); r != prova.end(); ++r, i++){
        *r=i;
    }
    MyVector<int>::iterator f=prova.begin(), t=prova.begin();

    f++;
    f++;
    f++;
    f++;
    t++;
    t++;
    t++;
    t++;
    t++;
    t++;

    std::cout<<*t<<*f<<std::endl;
    std::cout<<"ITERATOR before:"<<std::endl;
    for(MyVector<int>::iterator r=prova.begin(); r != prova.end(); ++r){
        std::cout<<*r<<" ";
    }

    std::cout<<"ITERATOR after"<<std::endl;
    //prova.erase(
    //prova.erase(prova.begin(),prova.end());
    prova.clear();
    for(MyVector<int>::iterator r=prova.begin(); r != prova.end(); ++r){
        std::cout<<*r<<" ";
    }



/*
    std::cout<<temp;
    temp.pop_back();
    std::cout<<temp.size()<<" "<<temp.capacity();

    temp.clear();

    temp.push_back("uno");
    temp.push_back("due");
    temp.push_back("tre");
    temp.push_back("quattro");
    std::cout<<std::endl<<f;
     std::cout<<temp.size()<<" "<<temp.capacity();



    MyVector<std::string>::iterator it=temp.begin();
    it++;
    std::cout<<"stampo temp before erase: "<<std::endl<<temp<<std::endl;

    MyVector<std::string>::const_iterator i(it); //MyVector<std::string>::iterator i(it);
     std::cout<<temp<<std::endl;
     std::cout<<"ITERATOR"<<std::endl;
    for(MyVector<std::string>::iterator r=temp.insert(it,"inserito"); r != temp.end(); ++r){
        std::cout<<*r<<" ";
    }
    std::cout<<temp<<std::endl;


*/






    /*QApplication a(argc, argv);
    QuizRoom w;
    w.show();
    return a.exec();*/
}
