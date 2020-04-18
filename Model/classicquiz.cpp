#include "classicquiz.h"

ClassicQuiz::ClassicQuiz(const std::string &q, int p, int m): Quiz(q,p,m){}

void ClassicQuiz::addAnswer(const std::string &a){
    if(!isAnswer(a))
        answer.push_back(a);
}

void ClassicQuiz::addCorrectAnswer(const std::string &ca){
    if(!isCorrectAnswer(ca)){
        addAnswer(ca);  // nel caso non sia stata inserita come answer
        correct_answer.push_back(ca);

        setPointCAnswer();
    }


}

bool ClassicQuiz::isAnswer(const std::string &a) const{
    for(MyVector<std::string>::const_iterator it=answer.begin(); it!=answer.end(); ++it)
        if(*it==a) return true;

    return false;
}

bool ClassicQuiz::isCorrectAnswer(const std::string &ca){
    for(MyVector<std::string>::const_iterator it=correct_answer.begin(); it!=correct_answer.end(); ++it)
        if(*it==ca)

            return false;
}

void ClassicQuiz::addPoint(const std::string &ca){
    if (isCorrectAnswer(ca))
        setMyPoint();
    else
        setMalus(10);
}

void ClassicQuiz::setMyPoint(){
    my_point+=point_correct_answer;
}

void ClassicQuiz::setMalus(int m){
    malus+=total_point/m;
}

int ClassicQuiz::CalcPointQuiz() const{
    return (my_point/total_point)*9+1-malus;
}

void ClassicQuiz::setPointCAnswer(){
    point_correct_answer=total_point/correct_answer.size();
}

void ClassicQuiz::showSolution() const{

}

ClassicQuiz* ClassicQuiz::clone() const{
    return new ClassicQuiz(*this);
}
