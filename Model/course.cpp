#include "course.h"
#include "user.h"
Course::Course(const string& t, const string& d): title(t), code(random_code()), description(d){
    //settare classroom dal file
}

const string& Course::getTitle() const{
    return title;
}

const string& Course::getCode() const{
    return code;
}

const string& Course::getDescription() const{
    return description;
}

const MyVector<Homework *> &Course::getHomeworks() const{
    return homew;
}

void Course::setTitle(const string& t){
    title=t;
}

void Course::setDescription(const string& d){
    description=d;
}

void Course::addHomework(Homework *h){
    homew.push_back(h);
}

void Course::removeHomework(Homework *h){
    MyVector<Homework*>::iterator it=homew.begin();
    bool temp=true;
    while(it!=homew.end() && temp){

        if((*it)->getTitle()==h->getTitle())
            temp = false;
          else
            ++it;
    }

    if(!temp)
        homew.erase(it);
}


void Course::setCode(){
    code=random_code();
}

const string Course::random_code(){
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



