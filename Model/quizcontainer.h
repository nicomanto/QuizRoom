#ifndef QUIZCONTAINER_H
#define QUIZCONTAINER_H
#include <string>
#include "myvector.h"
#include "quiz.h"

class QuizContainer{
private:
  std::string  title;
  std::string description;
  bool done;
  MyVector<Quiz*> quiz;
public:
    QuizContainer();
    QuizContainer(const std::string& t, const std::string & d=std::string());

    std::string getTitle() const;
    std::string getDescription() const;
    bool isDone() const;
    const MyVector<Quiz*>& getQuiz() const; //ritorna il vettore ai quiz

    void setTitle(const std::string& t);
    void setDone(bool t);
    void setDescription(const std::string& d);

    void addQuiz(Quiz* q); //aggiunge un quiz
    void removeQuiz(Quiz* q); //rimuove un quiz

    void showAllSolution() const; //mostra tutte le soluzioni dei quiz
    void showQuizSolution(const std::string& q) const; //mostra le soluzioni specifiche di un quiz
    double QuizPoint(const std::string& q) const; //ritorna il punteggio di un singolo quiz
    double allPoint() const; //ritorna il punteggio di tutti i quiz
    double getTotalAllPoint() const; //ritorna la somma del punteggio massimo ottenibile

};



#endif // QUIZCONTAINER_H
