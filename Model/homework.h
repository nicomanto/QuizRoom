#ifndef HOMEWORK_H
#define HOMEWORK_H

#include <string>

using std::string;
#include "quiz.h"

class Homework{
protected:
    string title;
    string instructions;

    bool done;
    MyVector<Quiz*> quiz;
public:
    Homework();
    Homework(const string& t, const string& i=string());

    string getTitle() const;
    string getInstructions() const;
    bool isDone() const;
    const MyVector<Quiz*>& getQuiz() const; //ritorna il vettore che contiene i container dei quiz

    void setTitle(const string& t);
    void setInstructions(const string& i);
    void setDone(bool t);

    void clearQuiz();

    std::string AllSolutionToString() const;

    void showAllSolution() const; //mostra tutte le soluzioni dei quiz
    void showQuizSolution(const std::string& q) const; //mostra le soluzioni specifiche di un quiz
    double QuizPoint(const std::string& q) const; //ritorna il punteggio di un singolo quiz
    double allPoint() const; //ritorna il punteggio di tutti i quiz
    double getTotalAllPoint() const; //ritorna la somma del punteggio massimo ottenibile

    virtual void addQuiz(Quiz* q); //aggiunge un quiz
    virtual void removeQuiz(Quiz* q); //rimuove un quiz

    virtual bool isScoreHomework() const;
    virtual bool isTimeHomework() const;
    virtual bool haveResult() const;
    virtual double getResult() const; //ritorna il risultato del quiz
    virtual Homework *clone() const;
    virtual ~Homework();
};

#endif // HOMEWORK_H
