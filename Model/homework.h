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
    Homework(string t, string i=string(),string a=string());

    string getTitle() const;
    string getInstructions() const;
    string getArguments() const;

    void setTitle(string t);
    void setInstructions(string i);
    void setArguments(string a);
};

#endif // HOMEWORK_H
