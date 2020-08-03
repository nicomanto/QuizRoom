#ifndef VECTORUSERS_H
#define VECTORUSERS_H

#include <stdexcept>

#include "Model/student.h"
#include "Model/teacher.h"
#include "Model/myvector.h"
#include "Model/timescorehomework.h"
#include "Model/combinequiz.h"
#include "Model/classicquiz.h"


class PrincipalForm;

class Controller{
private:
    MyVector<User*> users;

    MyVector<PrincipalForm*> stack_page;

public:
    Controller();

    void addStackView(PrincipalForm* p); //aggiunge una pagina allo stack delle pagine visitate
    PrincipalForm* removeStackView(); //rimuove una pagina dallo stack delle pagine visitate
    void cleanStack();  //svuota tutto lo stack delle pagine

    PrincipalForm* getPreviousPage();  //ritorna l'ultima pagina dello stack delle pagine visitate


    User* getUser(const string& u, const string& p) const; //ritorna l'utente tramite username e password
    unsigned int getNumberUserCourse(User* u) const; //ritorna il numero di corsi di un utente

    //metodi che ritornano true sse u può fare queste determinate cose
    bool UserCanAddCourse(User* u) const;
    bool UserCanDeleteCourse(User* u) const;
    bool UserCanEditCourse(User* u) const;
    bool UserCanAddQuiz(User* u) const;
    bool UserCanAddHomework(User* u) const;
    bool UserCanDeleteHomework(User* u) const;
    bool UserCanEditHomework(User* u) const;

    void addCourseFromCode(User* s, const string& code);  //aggiunge un corso all'utente tramite il codice
    Course* getCourse(User* u,unsigned int i) const;  //ritorna il corso che si trova a posizione i nel vettore corsi dell'utente u
    unsigned int getNumberCourseHomework(Course* c) const;  //ritorna la size del vettore homework di un corso
    const string& getCourseTitle(Course* c) const;
    const string & getCourseDescription(Course* c) const;
    const string & getCourseCode(Course* c) const;
    void addCourse(User* s, const string& t, const string& d); //Aggiunge un nuovo corso all'utente s
    void modifyCourse(Course* c,const string& t,const string& d);  //modifica un corso c
    void deleteCourse(User* s, unsigned int i); //elimina un corso in posizioni i nel vettore corsi dell'utente s
    void deleteCourse(Course* c);  //elimina il corso c


    Homework* getHomework(Course* c, unsigned int i) const;  //ritorna l'homework in posizione i nel vettore homework di c
    void AddHomework(Course* c, const string& t, const string& d, bool time, bool score, const DateTime& deadline); //aggiunge un homework a c
    void modifyHomework(Homework* h,const string& t,const string& d); //modifica un homework
    void deleteHomework(Course* c, unsigned int i); //elimina l'homework in posizione i nel vettore homework di c
    void deleteHomework(Homework* h); //elimina l'homework h
    const string & getHomeworkTitle(Homework* h) const;
    const string & getHomeworkInstructions(Homework* h) const;
    bool isTimeHomework(Homework* h) const;
    bool isScoreHomework(Homework* h) const;
    bool haveEmptyQuiz(Homework* h) const;  //ritorna true sse h ha il vettore quiz vuota
    unsigned int getNumberHomeworkQuiz(Homework* h) const; //ritorna il numero di qui che ha h
    const string SolutionHomeworkToString(Homework* h) const;  //ritorna le soluzioni al compito h
    double getResultHomework(Homework* h) const; //ritorna il risultato del compito h
    void resetHomeworkQuizPoint(Homework* h);  //resetta il punteggio dei quiz dell'homework h
    bool HomeworkHaveResult(Homework* h) const; //controlla se h ha un risultato possibile
    void HomeworkClearQuiz(Homework* h); //svuota il vettore quiz dell'homework h


    //aggiunge un nuovo quiz a combinazione
    void addCombineQuiz(Homework* h, const string& question,const MyVector<std::string>& elements, const MyVector<std::string>& answers);
    //aggiunge un nuovo quiz classico
    void addClassicQuiz(Homework* h, const string& question,const MyVector<std::string>& answers, const MyVector<std::string>& correct_answers);


    Quiz* getQuiz(Homework* h, unsigned int i) const; //Ritorna il quiz all'indice i de vettore quiz del compito h
    const std::map<std::string,std::string>& getCorrectAnswersCombineQuiz(CombineQuiz* quiz) const;  //ritorna la mappa delle combinazioni corrette di quiz
    unsigned int getCorrectAnswersCombineQuizSize(CombineQuiz* quiz) const;  //ritorna il numero di combinazioni del quiz
    void addPointCombineQuiz(CombineQuiz* quiz, const string& option,const string& answer); //aggiunge i punti in base alla risposta passata (option <--> answer)

    const MyVector<std::string>& getAnswersClassicQuiz(ClassicQuiz* quiz) const; //ritorna tutte le risposte del quiz
    unsigned int getAnswersClassicQuizSize(ClassicQuiz* quiz) const; //ritorna il numero di risposte del quiz
    const string& getAnsweratIndexClassicQuiz(ClassicQuiz* quiz, unsigned int index) const;  //ritorna la risposta del vettore answers all'indice i
    void addPointClassicQuiz(ClassicQuiz* quiz, const string& answer); //aggiunge i punti al quiz in base a se la risposta (answer) è corretta

};

#endif // VECTORUSERS_H
