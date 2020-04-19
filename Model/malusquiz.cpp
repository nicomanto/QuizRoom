#include "malusquiz.h"

MalusQuiz::MalusQuiz(const std::string& q, double tp, double mp, double tm) : Quiz(q,tp), total_malus(tm), malus_point(mp){}

double MalusQuiz::getTotalMalus() const{
    return total_malus;
}

double MalusQuiz::getMalusPoint() const{
    return malus_point;
}

void MalusQuiz::setMalusPoint(double mp){
    malus_point=mp;
}

void MalusQuiz::setTotalMalus(double m){
    total_malus=m;
}

void MalusQuiz::addTotalMalus(double m){
    total_malus+=m;
}

bool MalusQuiz::HaveMalus() const{
    return true;
}
