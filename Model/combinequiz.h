#ifndef COMBINEQUIZ_H
#define COMBINEQUIZ_H
#include <map>
#include <iostream>
#include "quiz.h"

class CombineQuiz : public Quiz{ //NO-Malus
private:
    std::map<std::string,std::string> correct_combine;


    virtual void setPointCAnswer();

public:
    CombineQuiz();
    CombineQuiz(const std::string& q);

    const std::map<std::string,std::string>& getCorrectAnswer() const;

    void addCorrectCombine(const std::string& a1,const std::string& a2);
    void removeCorrectCombine(const std::string& a1);
    bool isCorrectCombine(const std::string& a1, const std::string& a2) const;


    virtual bool HaveMalus() const;
    virtual double CalcPointQuiz () const;

    void addPoint(const std::string &a1, const std::string &a2);
    virtual void showSolution() const;



    virtual const std::string SolutionToString()const;

    virtual void clear_all_answers();

    virtual void resetPoint();

    virtual CombineQuiz *clone() const;
};

#endif // COMBINEQUIZ_H
