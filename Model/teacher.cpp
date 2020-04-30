#include "teacher.h"
#include "student.h"
Teacher::Teacher(){}

Teacher::Teacher(const string& n,const string& s,const string& u,const string& p,const string& e,const string& m): User(n,s,u,p,e), subject(m){}

string Teacher::getSubject() const{
    return subject;
}

void Teacher::setSubject(const string& m){
    subject=m;
}

bool Teacher::CanAddHomework() const{
    return true;
}

bool Teacher::CanDeleteHomework() const{
    return true;
}

bool Teacher::CanEditHomework() const{
    return true;
}

bool Teacher::CanAddCourse() const{
    return true;
}

bool Teacher::CanDeleteCourse() const{
    return true;
}

bool Teacher::CanEditCourse() const{
    return true;
}

bool Teacher::CanAddQuiz() const{
    return true;
}

bool Teacher::CanDeleteQuiz() const{
    return true;
}

bool Teacher::CanEditQuiz() const{
    return true;
}

bool Teacher::CanDoQuiz() const{
    return false;
}

double Teacher::ShowCourseStatistics(const Course& c) const{
    //ritorna la statistica del corso per tutti gli studenti del corso
    const MyVector<User*> classroom=c.getClassroom();
    int num_student=0;
    double statistics=0;

    for(int i=0; i<classroom.size();++i){
        if(dynamic_cast<Student*>(classroom[i])){
            num_student++;
            for(int j=0;j<classroom[i]->getCourse().size();++j)
                if(classroom[i]->getCourse()[j].getTitle()==c.getTitle())
                    statistics+=classroom[i]->getCourse()[j].ShowAllHomeworkStatistics();
        }
    }

    return statistics/num_student; //niente *100 perchè è già una percentuale

}

Teacher* Teacher::clone() const{
    return new Teacher(*this);
}
