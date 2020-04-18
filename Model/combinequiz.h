#ifndef COMBINEQUIZ_H
#define COMBINEQUIZ_H
#include "quiz.h"
#include <map>
class CombineQuiz : public Quiz{
private:
    std::map<std::string,std::string> correct_combine;
public:
    CombineQuiz(const std::string& q, int p=0);

    void addCorrectCombine(const std::string& a1, const std::string& a2);
    bool isCorrectCombine(const std::string& a1, const std::string& a2) const;
    void addPoint(const std::string &a1, const std::string &a2);

    virtual void setMyPoint();
    virtual void setMalus(int m);
    virtual int CalcPointQuiz()const;
    virtual void setPointCAnswer();

    virtual void showSolution() const;

    virtual CombineQuiz *clone() const;
};

#endif // COMBINEQUIZ_H
