#include "Model/quizroom.h"
#include <iostream>
#include <QApplication>
#include "Model/myvector.h" //per testare


int main(int argc, char *argv[])
{
    /*int y=8;
    MyVector<int> temp(2,y), f(temp),z(5,7);


   z.front();


    temp.pop_back();
    temp.push_back(5);
    temp.push_back(5);
    std::cout<<"Front: "<<temp.front()<<std::endl;
    std::cout<<"BAck: "<<temp.back()<<std::endl;

    //temp=f;
    MyVector<int> te(temp);
    std::cout<<std::endl;
    std::cout<<"size:"<<te.size()<<" capacity:"<<te.capacity()<<std::endl;
    for(MyVector<int>::iterator r=z.begin(); r != z.end(); ++r){
        std::cout<<*r<<" ";
    }

    //z.append(temp);
    z.insert(z.begin(),9);
    MyVector<int>::iterator c= ++(++z.begin());
    MyVector<int>::iterator k= ++(++(++(++z.begin())));

    if(temp==te){

        std::cout<<"size:"<<temp.size()<<" capacity:"<<temp.capacity()<<std::endl;
        for(MyVector<int>::iterator r=temp.begin(); r != temp.end(); ++r){
            std::cout<<*r<<" ";
        }
        std::cout<<std::endl;
        std::cout<<"size:"<<temp.size()<<" capacity:"<<temp.capacity()<<std::endl;
        for(MyVector<int>::iterator r=z.begin(); r != z.end(); ++r){
            std::cout<<*r<<" ";
        }


    }*/


    /*MyVector<int> prova(10,10);
    int i=0;

    MyVector<int>::const_iterator r=prova.begin();
    r++;
    MyVector<int>::const_iterator k=prova.begin();
    //MyVector<int>::iterator y=k;
    MyVector<int>::const_iterator f=prova.begin(), t=prova.begin();

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
    }*/



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
