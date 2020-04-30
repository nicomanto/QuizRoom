#include "course.h"
#include "user.h"
Course::Course(const string& t, const string& s, const string& d): title(t), code(random_code()), subject(s), description(d){
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

const MyVector<Homework *> &Course::getHomeworks() const{
    return homew;
}

const MyVector<User *> &Course::getClassroom() const{
    return classroom;
}

void Course::setTitle(const string& t){
    title=t;
}

void Course::setSubject(const string& s){
    subject=s;
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

void Course::addUser(User *h){
    classroom.push_back(h);
}

void Course::removeUser(User *h){
    MyVector<User*>::iterator it=classroom.begin();
    bool temp=true;
    while(it!=classroom.end() && temp){
        if((*(*it))==*h)
            temp = false;
          else
            ++it;
    }

    if(!temp)
        classroom.erase(it);
}

double Course::ShowAllHomeworkStatistics() const{
    //da implementare
    double statistics=0; //percentuale homework completati
    for(MyVector<Homework*>::const_iterator it = homew.begin(); it!=homew.end(); ++it)
        statistics+=(*it)->isDone();

    return statistics/homew.size()*100;
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



