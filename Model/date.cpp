#include "date.h"
Date::Date(unsigned int d, unsigned int m,unsigned int y){
    if(!isDate(d,m,y))
        throw::std::out_of_range (std::to_string(d)+"/"+std::to_string(m)+"/"+std::to_string(y)+" non rappresenta una data.");

    day=d;
    month=m;
    year=y;

}

Date::Date(): day(getCurrentDate().Day()), month(getCurrentDate().month), year(getCurrentDate().year){}

unsigned int Date::Day() const{
    return day;
}

unsigned int Date::Month() const{
    return month;
}

unsigned int Date::Year() const{
    return year;
}

bool Date::isBisestile(unsigned int y) const{
    return y%400==0 || (y%4==0 && !(y%100==0));
}

bool Date::operator<(const Date &t) const{
    if(year<t.year)
        return true;
    if(year==t.year && month<t.month)
        return true;
    if(year==t.year && month==t.month && day<t.day)
        return true;

    return false;
}

bool Date::operator>(const Date &t) const
{
    return !(*this<t) && !(*this==t);
}

bool Date::operator==(const Date &t) const
{
    return day==t.day && month==t.month && year==t.year;
}

bool Date::operator!=(const Date &t) const{
    return !(*this==t);
}

std::string Date::ToString() const{
    std::string temp,d,m,y;

    if(day<10)
        d+="0";
    if(month<10)
        m+="0";
    if(year<10)
        y+="0";

    temp+= d+std::to_string(day)+"/"+m+std::to_string(month)+"/"+y+std::to_string(year);

    return temp;
}


bool Date::isDate(unsigned d, unsigned m,unsigned int y)const {
    if(d<=0 || m<=0 || y<=0 || m>12 || d>31)
        return false;

    if((m==4 || m==6 || m==9 || m==11) && d==31)
        return false;

    if(isBisestile(y)){ // bisestile
        if(m==2 && d>29)
            return false;
    }
    else{
        if(m==2 && d>28)
            return false;
    }

    return true;
}

Date Date::getCurrentDate(){
    std::time_t current_time = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());

    const std::tm temp = *std::localtime( std::addressof(current_time) );


    return Date(temp.tm_mday,temp.tm_mon+1,temp.tm_year + 1900);
}


std::ostream& operator<<(std::ostream &out, const Date& d){
    out<<d.ToString();
    return out;
}
