#include "classicquiz.h"

ClassicQuiz::ClassicQuiz(){}

ClassicQuiz::ClassicQuiz(const std::string& q,double mp, double tm): MalusQuiz(q,mp,tm){}

const MyVector<std::string> &ClassicQuiz::getCorrectAnswer() const{
    return correct_answer;
}

const MyVector<std::string> &ClassicQuiz::getAnswers() const{
    return answer;
}

void ClassicQuiz::addAnswer(const std::string& a){
    if(!isAnswer(a))
        answer.push_back(a);
}

void ClassicQuiz::addCorrectAnswer(const std::string& ca){
    if(!isCorrectAnswer(ca)){
        addAnswer(ca);  // nel caso non sia stata inserita come answer
        correct_answer.push_back(ca);

        setPointCAnswer();
    }


}

void ClassicQuiz::removeAnswer(const std::string& a){
    removeCorrectAnswer(a);

    MyVector<std::string>::iterator it=answer.begin();
    while(it!=answer.end() || *it==a){++it;}

    if(it!=answer.end())
        answer.erase(it);
}

void ClassicQuiz::removeCorrectAnswer(const std::string& ca){
    MyVector<std::string>::iterator it=correct_answer.begin();
    while(it!=correct_answer.end() || *it==ca){++it;}

    if(it!=correct_answer.end())
        correct_answer.erase(it);
}

bool ClassicQuiz::isAnswer(const std::string& a) const{
    for(MyVector<std::string>::const_iterator it=answer.begin(); it!=answer.end(); ++it)
        if(*it==a) return true;

    return false;
}

bool ClassicQuiz::isCorrectAnswer(const std::string& ca) const{
    for(MyVector<std::string>::const_iterator it=correct_answer.begin(); it!=correct_answer.end(); ++it)
        if(*it==ca)
            return true;

    return false;
}

void ClassicQuiz::addPoint(const std::string &ca){
    if (isCorrectAnswer(ca))
        addMyPoint(point_correct_answer);
    else
        addTotalMalus(CalcMalus());
}

double ClassicQuiz::CalcMalus() const {//percentuale sui punti della domanda
    return (point_correct_answer*malus_point)/100;
}

double ClassicQuiz::CalcPointQuiz(){  //ritorna il punteggio ottenuto
    double temp=(my_point/total_point)*9+1-total_malus;
    resetPoint();
    return temp;
}

void ClassicQuiz::setPointCAnswer(){  //setta il numero di punteggio ottenuto dalle domande
    //(il punteggio è uguali per tutti in base al numero di domande
    point_correct_answer=total_point/correct_answer.size();
}

void ClassicQuiz::showSolution() const{
    for(MyVector<std::string>::const_iterator it=correct_answer.begin(); it!=correct_answer.end(); ++it)
        std::cout<<*it<<std::endl;
}

const std::string ClassicQuiz::SolutionToString() const{
    std::string temp="";
    for(MyVector<std::string>::const_iterator it=correct_answer.begin(); it!=correct_answer.end(); ++it)
        temp.append(*it+"\n");

    return temp;

}

void ClassicQuiz::resetPoint(){
    my_point=0;
    total_malus=0;
}

void ClassicQuiz::clear_all_answers(){
    correct_answer.clear();
    answer.clear();
    resetPoint();
}

ClassicQuiz* ClassicQuiz::clone() const{
    return new ClassicQuiz(*this);
}
