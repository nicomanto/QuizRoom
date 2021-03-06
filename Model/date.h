#ifndef DATE_H
#define DATE_H
#include <iostream>
#include <chrono>
#include <string>

class Date{
private:
    unsigned int day;
    unsigned int month;
    unsigned int year;

    bool isBisestile(unsigned int y) const;

    //ritorna il numero di anni bisestili prima della data
    int numeroAnniBisestili() const;
    bool isDate(unsigned d, unsigned m,unsigned int y) const;
public:
    Date();
    Date(unsigned int d, unsigned int m, unsigned int y);

    unsigned int Day() const;
    unsigned int Month() const;
    unsigned int Year() const;


    bool operator<(const Date& t) const;
    bool operator>(const Date& t) const;
    bool operator==(const Date& t) const;
    bool operator!=(const Date& t) const;

    int daysFromNowToDate() const;

    std::string ToString() const;
    static Date getCurrentDate();
};


std::ostream& operator<<(std::ostream &out, const Date& d);

#endif // DATE_H
