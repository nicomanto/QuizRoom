#ifndef QUIZ_H
#define QUIZ_H
#include <string>
#include "myvector.h"
#include <map>

template<class T>
class Quiz{
private:
    std::string question;
    int point;
public:
    Quiz(const std::string& q,int p=0);

    std::string getQuestion() const;
    int getPoint() const;

    void setQuestion(const std::string& q);
    void setPoint(int p);

    virtual void showSolution() const=0;
    virtual void addAnswer(const T& a)=0;
    virtual void removeAnswer(const T& a)=0;

    virtual Quiz *clone() const=0;
    virtual ~Quiz();
};

template <class T>
Quiz<T>::Quiz(const std::string& q,int p): question(q), point(p){}


template <class T>
std::string  Quiz<T>::getQuestion() const{
    return question;
}

template <class T>
int Quiz<T>::getPoint() const{
    return point;
}

template <class T>
void Quiz<T>::setQuestion(const std::string& q){
    question=q;
}

template <class T>
void Quiz<T>::setPoint(int p){
    point=p;
}




#endif // QUIZ_H
