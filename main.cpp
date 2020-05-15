#include "View/loginform.h"
#include "View/mainform.h"
#include "View/courseform.h"
#include "View/homeworkform.h"
#include "View/classicquizform.h"
#include "View/combinequizform.h"
#include "View/containerquizform.h"
#include "View/modifyaddform.h"
#include "View/addhomeworkform.h"
#include "View/addclassicquizform.h"
#include "View/addcombinequizform.h"
#include "View/containeraddquizform.h"

#include <iostream>
#include <QApplication>
#include "Model/myvector.h" //per testare
#include <iostream>
#include "Model/datetime.h"
#include "Model/course.h"

#include "Model/combinequiz.h"
#include "Model/classicquiz.h"
#include "Model/quizcontainer.h"
#include "Model/timescorehomework.h"

#include "Model/student.h"
#include "Model/teacher.h"


int main(int argc, char *argv[])
{

/*

    CombineQuiz a("ciao",10);
    ClassicQuiz c("classic",10,30);


    c.addCorrectAnswer("cavallo");
    c.addPoint("cavallo");
    a.addCorrectCombine("ciao","2");
    a.addCorrectCombine("ciao1","1");
    a.addCorrectCombine("ciao2","0");


    QuizContainer b("bello","descrizione");
    std::cout<<"Titolo container: "<<b.getTitle();
    b.addQuiz(&a);
    b.addQuiz(&c);
    //b.removeQuiz(&c);
    b.showQuizSolution("cavallo");
    std::cout<<"ris: "<<b.QuizPoint("ciao")<<std::endl;

    a.addPoint("ciao","2");
    a.addPoint("ciao1","1");
    a.addPoint("ciao2","2");
        std::cout<<a.CalcPointQuiz();

        std::cout<<"Title: "<<a.getQuestion();

    std::cout<<"ris: "<<b.allPoint()<<std::endl;


    DateTime data(25,03,2020,00);
    TimeScoreHomework sh(data, "Prova compito");

    std::cout<<"Total score before: "<<sh.getTotalScore()<<std::endl;

    sh.addQuizContainer(b);
    //if(sh.isTimeHomework() && sh.isScoreHomework())
        std::cout<<sh.getDeadline()<<std::endl;
        //sh.removeQuizContainer(b);
    //std::cout<<"Total score after: "<<sh.getTotalScore()<<std::endl;
    //std::cout<<"result: "<<sh.getResult()<<std::endl;

    std::cout<<"test blank"<<std::endl;


    //sh.addQuizContainer(b);
    //sh.removeQuizContainer(b);
    for(MyVector<QuizContainer>::iterator it=sh.getContainerQuiz().begin(); it!=sh.getContainerQuiz().end(); ++it){
        std::cout<<"1";
        std::cout<<it->getTitle()<<std::endl;

    }


    std::cout<<std::endl<<std::endl<<"Show al solution Quiz"<<std::endl;
    sh.getContainerQuiz()[0].showAllSolution();


    sh.getContainerQuiz()[0].setDone(true);
    if(sh.isDone())
        std::cout<<std::endl<<std::endl<<"isDone"<<std::endl;
    else
        std::cout<<std::endl<<std::endl<<"isNotDone"<<std::endl;






    Course y("Corso ciao");

    y.addHomework(&sh);

    Teacher mezzadrelli("Alessadro","Mezzadrelli","alemezza","pass","email");
    Student s1("Alessadro","Mezzadrelli","alemezza","pass","email");
    Student s2("Alessadro","Mezzadrelli","alemezza","pass","email");

    y.addUser(&mezzadrelli);
    y.addUser(&s1);
    y.addUser(&s2);
    mezzadrelli.addCourse(y);
    s1.addCourse(y);
    s2.addCourse(y);

    std::cout<<"statistics teacher: "<<mezzadrelli.ShowCourseStatistics(y)<<std::endl;
    std::cout<<"statistics student 1: "<<s1.ShowCourseStatistics(y)<<std::endl;
    std::cout<<"statistics student 2: "<<s2.ShowCourseStatistics(y)<<std::endl;
    */


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





    QApplication a(argc, argv);
    LoginForm w;
    w.show();
    return a.exec();


}
