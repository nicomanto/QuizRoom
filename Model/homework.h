#ifndef HOMEWORK_H
#define HOMEWORK_H

#include <string>

using std::string;

class Homework{
private:
    string title;
    string instructions;
    string arguments;
    // MyVector <*QuizModule> module_q;       modulo per quiz (struttura del contenitore dei quiz)

public:
    Homework(const string& t, const string& i=string(),const string& a=string());

    string getTitle() const;
    string getInstructions() const;
    string getArguments() const;

    void setTitle(const string& t);
    void setInstructions(const string& i);
    void setArguments(const string& a);


    virtual int getResult() const=0;
    virtual Homework* clone() const=0;
    virtual ~Homework();
};

#endif // HOMEWORK_H
