#include "combinequiz.h"

CombineQuiz::CombineQuiz(){}

CombineQuiz::CombineQuiz(const std::string &q): Quiz(q){}

const std::map<std::string,std::string>& CombineQuiz::getCorrectAnswer() const{
    return correct_combine;
}

void CombineQuiz::addCorrectCombine(const std::string& a1, const std::string& a2){
    correct_combine[a1]=a2;

    setPointCAnswer();
}

void CombineQuiz::removeCorrectCombine(const std::string& a1){
    correct_combine.erase(a1);
}

bool CombineQuiz::isCorrectCombine(const std::string &a1, const std::string &a2) const{
    return correct_combine.at(a1)==a2;
}



void CombineQuiz::addPoint(const std::string &a1, const std::string &a2){
    if (isCorrectCombine(a1,a2))
        addMyPoint(point_correct_answer);

}

bool CombineQuiz::HaveMalus() const{
    return false;
}

double CombineQuiz::CalcPointQuiz() const{ // calcolo risultato diverso
    return (my_point/total_point)*10;

}

void CombineQuiz::setPointCAnswer(){
    point_correct_answer=total_point/correct_combine.size();
}

void CombineQuiz::showSolution() const{
    for(std::map<std::string,std::string>::const_iterator it=correct_combine.begin(); it!=correct_combine.end(); ++it)
        std::cout<<it->first<<" "<<it->second<<std::endl;
}

void CombineQuiz::resetPoint(){
    my_point=0;
}

const std::string CombineQuiz::SolutionToString() const{
    std::string temp="";
    for(std::map<std::string,std::string>::const_iterator it=correct_combine.begin(); it!=correct_combine.end(); ++it)
        temp.append(it->first+" <-> "+it->second+"\n");

    return temp;
}

void CombineQuiz::clear_all_answers(){
    correct_combine.clear();
    resetPoint();
}

CombineQuiz *CombineQuiz::clone() const{
    return new CombineQuiz(*this);
}
