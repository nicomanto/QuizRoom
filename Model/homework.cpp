#include "homework.h"

Homework::Homework(string t, string i, string a): title(t), instructions(i), arguments(a){}

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

void Homework::setTitle(string t){
    title=t;
}

void Homework::setInstructions(string i){
    instructions=i;
}

void Homework::setArguments(string a){
    arguments=a;
}
