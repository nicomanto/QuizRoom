#include "corso.h"

Corso::Corso(string t, string s, string d): title(t), code(random_code()), subject(s), description(d){
    //settare classroom dal file
}

string Corso::getTitle() const{
    return title;
}

string Corso::getCode() const
{
    return code;
}

string Corso::getSubject() const
{
    return subject;
}

string Corso::getDescription() const
{
    return description;
}

void Corso::setTitle(string t){
    title=t;
}

void Corso::setSubject(string s){
    subject=s;
}

void Corso::setDescription(string d){
    description=d;
}


void Corso::setCode(){
    code=random_code();
}

string Corso::random_code(){
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



