#include "homework.h"

Homework::Homework(){}

Homework::Homework(const string& t, const string& i): title(t), instructions(i){}

const string& Homework::getTitle() const{
    return title;
}

const std::string& Homework::getInstructions() const
{
    return instructions;
}

const MyVector<Quiz*>& Homework::getQuiz() const{
    return quiz;
}

void Homework::setTitle(const string& t){
    title=t;
}

void Homework::setInstructions(const string& i){
    instructions=i;
}


void Homework::clearQuiz(){
    quiz.clear();
}

void Homework::resetPointQuiz()
{
    for(unsigned int i=0; i<quiz.size();++i){
        quiz[i]->resetPoint();
    }
}

const std::string Homework::AllSolutionToString() const{

    int i=1;
    string temp="";
    for(MyVector<Quiz*>::const_iterator it=quiz.begin(); it!=quiz.end(); ++it){
        temp.append("\nQuiz ");
        temp.append(std::to_string(i)+":\n");
        temp.append((*it)->SolutionToString()+"\n");

        std::stringstream stream;
        stream << std::fixed << std::setprecision(2) << (*it)->getMyPoint();
        temp.append("Punti ottenuti: "+stream.str()+"\n");
        ++i;
    }

    return temp;
}


void Homework::addQuiz(Quiz* q){
    quiz.push_back(q);
}

void Homework::removeQuiz(Quiz *q){
    MyVector<Quiz*>::iterator it=quiz.begin();
    bool temp=true;
    while(it!=quiz.end() && temp){

        if((*it)->getQuestion()==q->getQuestion())
            temp = false;
          else
            ++it;
    }

    if(!temp)
        quiz.erase(it);


}




void Homework::showAllSolution() const{
    int i=1;
    for(MyVector<Quiz*>::const_iterator it=quiz.begin(); it!=quiz.end(); ++it){
        std::cout<<"Quiz "<<i<<std::endl;
        (*it)->showSolution();
        ++i;
    }
}

void Homework::showQuizSolution(const std::string &q) const{
    for(MyVector<Quiz*>::const_iterator it=quiz.begin(); it!=quiz.end(); ++it){
        if((*it)->getQuestion()==q)
            (*it)->showSolution();

    }
}

double Homework::QuizPoint(const std::string &q) const{
    for(MyVector<Quiz*>::const_iterator it=quiz.begin(); it!=quiz.end(); ++it){
        if((*it)->getQuestion()==q)
            return (*it)->CalcPointQuiz();

        }

    return 0;
}

double Homework::allPoint() const{
    double somma=0;

    for(MyVector<Quiz*>::const_iterator it=quiz.begin(); it!=quiz.end(); ++it){
        somma+=(*it)->CalcPointQuiz();
    }

    return somma;
}

double Homework::getTotalAllPoint() const
{
    double somma=0;

    for(MyVector<Quiz*>::const_iterator it=quiz.begin(); it!=quiz.end(); ++it){
        somma+=(*it)->getTotalPoint();
    }

    return somma;
}

bool Homework::isScoreHomework() const{
    return false;
}

bool Homework::isTimeHomework() const{
    return false;
}

bool Homework::haveResult() const{
    return false;
}

double Homework::getResult() const{
    return 0;
}

Homework *Homework::clone() const{
    return new Homework(*this);
}

Homework::~Homework(){}
