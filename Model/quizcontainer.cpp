#include "quizcontainer.h"

QuizContainer::QuizContainer(const std::string &t, const MyVector<Quiz*> &q, const std::string &d): title(t), description(d), quiz(q){}


std::string QuizContainer::getTitle() const{
    return title;
}


std::string QuizContainer::getDescription() const{
    return description;
}

void QuizContainer::setdTitle(const std::string &t){
    title=t;
}

void QuizContainer::setDescription(const std::string &d){
    description=d;
}


void QuizContainer::addQuiz(Quiz* q){
    quiz.push_back(q);
}
