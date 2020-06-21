#ifndef TIME_H
#define TIME_H
#include<iostream>
#include <chrono>
class Time{
private:
    unsigned int minutes;
public:
    Time();
    Time(unsigned int o, unsigned int m=0);

    unsigned int Hours() const;
    unsigned int Minutes() const;

    std::string ToString() const;

    bool operator<(const Time& t) const;
    bool operator>(const Time& t) const;
    bool operator==(const Time& t) const;
    bool operator!=(const Time& t) const;

    static Time getCurrentTime();
};


std::ostream& operator<<(std::ostream &out, const Time& d);

#endif // TIME_H
