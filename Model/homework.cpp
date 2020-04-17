#include "homework.h"

Homework::Homework(const string& t,const string& i,const string& a): title(t), instructions(i), arguments(a){}

string Homework::getTitle() const{
    return title;
}

std::string Homework::getInstructions() const
{
    return instructions;
}

string Homework::getArguments() const{
    return arguments;
}

void Homework::setTitle(const string& t){
    title=t;
}

void Homework::setInstructions(const string& i){
    instructions=i;
}

void Homework::setArguments(const string& a){
    arguments=a;
}

Homework::~Homework(){}
