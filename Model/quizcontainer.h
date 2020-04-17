#ifndef QUIZCONTAINER_H
#define QUIZCONTAINER_H
#include <string>
#include "myvector.h"
#include "quiz.h"

template <class T>
class QuizContainer{
private:
  std::string  title;
  std::string description;
  MyVector<Quiz<T>*> quiz;
public:
    QuizContainer(const std::string& t, const MyVector<Quiz<T>*>& q, const std::string & d=std::string());

    std::string getTitle() const;
    std::string getDescription() const;

    void setdTitle(const std::string& t);
    void setDescription(const std::string& d);

    void addQuiz(const Quiz<T>& q);
};

template<class T>
QuizContainer<T>::QuizContainer(const std::string &t, const MyVector<Quiz<T> *> &q, const std::string &d): title(t), description(d), quiz(q){}

template<class T>
std::string QuizContainer<T>::getTitle() const{
    return title;
}

template<class T>
std::string QuizContainer<T>::getDescription() const{
    return description;
}

template<class T>
void QuizContainer<T>::setdTitle(const std::string &t){
    title=t;
}

template<class T>
void QuizContainer<T>::setDescription(const std::string &d){
    description=d;
}

template<class T>
void QuizContainer<T>::addQuiz(const Quiz<T> &q){
    quiz.pop_back(q);
}


#endif // QUIZCONTAINER_H
