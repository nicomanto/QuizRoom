#ifndef QUIZCONTAINER_H
#define QUIZCONTAINER_H
#include <string>
#include "myvector.h"
#include "quiz.h"


class QuizContainer{
private:
  std::string  title;
  std::string description;
  MyVector<Quiz*> quiz;
public:
    QuizContainer(const std::string& t, const std::string & d=std::string());

    std::string getTitle() const;
    std::string getDescription() const;

    void setdTitle(const std::string& t);
    void setDescription(const std::string& d);

    void addQuiz(Quiz* q);

    void showAllSolution() const;
    void showQuizSolution(const std::string& q) const;
    double QuizPoint(const std::string& q) const;
    double allPoint() const;

};



#endif // QUIZCONTAINER_H
