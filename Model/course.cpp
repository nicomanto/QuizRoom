#include "course.h"

Course::Course(string t, string s, string d): title(t), code(random_code()), subject(s), description(d){
    //settare classroom dal file
}

string Course::getTitle() const{
    return title;
}

string Course::getCode() const
{
    return code;
}

string Course::getSubject() const
{
    return subject;
}

string Course::getDescription() const
{
    return description;
}

void Course::setTitle(string t){
    title=t;
}

void Course::setSubject(string s){
    subject=s;
}

void Course::setDescription(string d){
    description=d;
}

int Course::ShowStatistics() const{
    //da implementare
}


void Course::setCode(){
    code=random_code();
}

string Course::random_code(){
    string temp;

    srand(time(NULL));

    for(int i=0; i<7;++i){
        if(rand()%2)
            temp+= std::to_string(rand()%10);
        else
            temp+= 'a' + rand()%26;
    }

    return temp;
}



