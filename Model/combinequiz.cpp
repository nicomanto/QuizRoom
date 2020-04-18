#include "combinequiz.h"

CombineQuiz::CombineQuiz(const std::string &q, int p): Quiz(q,p){}

void CombineQuiz::addCorrectCombine(const std::string &a1, const std::string &a2){
    correct_combine[a1]=a2;
}

bool CombineQuiz::isCorrectCombine(const std::string &a1, const std::string &a2) const{
    return correct_combine.at(a1)==a2;
}



void CombineQuiz::addPoint(const std::string &a1, const std::string &a2){
    if (isCorrectCombine(a1,a2))
        setMyPoint();

}

void CombineQuiz::setMyPoint(){
    my_point+=point_correct_answer;
}

void CombineQuiz::setMalus(int m){
    malus+=total_point/m;
}

int CombineQuiz::CalcPointQuiz() const{
    return (my_point/total_point)*9+1-malus;
}

void CombineQuiz::setPointCAnswer(){
    point_correct_answer=total_point/correct_combine.size();
}

void CombineQuiz::showSolution() const{

}

CombineQuiz *CombineQuiz::clone() const{
    return new CombineQuiz(*this);
}
