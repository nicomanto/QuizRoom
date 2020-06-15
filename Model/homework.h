#ifndef HOMEWORK_H
#define HOMEWORK_H
#include <iomanip>
#include <sstream>
#include <string>

#include "myvector.h"
#include "quiz.h"

using std::string;


class Homework{
protected:
    string title;
    string instructions;

    MyVector<Quiz*> quiz;
public:
    Homework();
    Homework(const string& t, const string& i=string());

    const string& getTitle() const;
    const string& getInstructions() const;
    const MyVector<Quiz*>& getQuiz() const; //ritorna il vettore che contiene i container dei quiz

    void setTitle(const string& t);
    void setInstructions(const string& i);

    void clearQuiz();

    void resetPointQuiz();

    const std::string AllSolutionToString() const;

    void showAllSolution() const; //mostra tutte le soluzioni dei quiz
    void showQuizSolution(const std::string& q) const; //mostra le soluzioni specifiche di un quiz
    double QuizPoint(const std::string& q) const; //ritorna il punteggio di un singolo quiz
    double allPoint() const; //ritorna il punteggio di tutti i quiz
    double getTotalAllPoint() const; //ritorna la somma del punteggio massimo ottenibile

    void addQuiz(Quiz* q); //aggiunge un quiz
    void removeQuiz(Quiz* q); //rimuove un quiz

    virtual bool isScoreHomework() const;
    virtual bool isTimeHomework() const;

    virtual bool haveResult() const;
    virtual double getResult() const; //ritorna il risultato del quiz

    virtual Homework *clone() const;
    virtual ~Homework();
};

#endif // HOMEWORK_H
