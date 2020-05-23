#ifndef COMBINEQUIZ_H
#define COMBINEQUIZ_H
#include "quiz.h"
#include <map>
class CombineQuiz : public Quiz{ //NO-Malus
private:
    std::map<std::string,std::string> correct_combine;

public:
    CombineQuiz();
    CombineQuiz(const std::string& q, double t=100);

    const std::map<std::string,std::string>& getCorrectAnswer() const;

    void addCorrectCombine(const std::string& a1,const std::string& a2);
    void removeCorrectCombine(const std::string& a1);
    bool isCorrectCombine(const std::string& a1, const std::string& a2) const;
    void addPoint(const std::string &a1, const std::string &a2);


    virtual bool HaveMalus() const;
    virtual double CalcPointQuiz()const;
    virtual void setPointCAnswer();

    virtual void showSolution() const;

    virtual void clear_all_answers();

    virtual CombineQuiz *clone() const;
};

#endif // COMBINEQUIZ_H
