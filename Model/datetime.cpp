#include "datetime.h"

DateTime::DateTime(): Time(), Date(){}

DateTime::DateTime(unsigned int d, unsigned int m, unsigned int y, unsigned int o, unsigned int mi): Time(o,mi), Date(d,m,y){}

DateTime::DateTime(const Date &d, const Time &t): Time(t), Date(d){}

std::string DateTime::ToString() const{
    return Date::ToString()+" "+Time::ToString();
}

bool DateTime::operator<(const DateTime &d) const{
    if(Date::operator>(d))
       return false;

    return Date::operator<(d) || (Date::operator==(d) && Time::operator<(d));


}

bool DateTime::operator>(const DateTime &d) const{
    return !(*this==d) && !(*this<d);
}

bool DateTime::operator==(const DateTime &d) const{
    return Date::operator==(d) && Time::operator==(d);
}

bool DateTime::operator!=(const DateTime &d) const{
    return !(*this==d);
}

DateTime DateTime::getCurrentDateTime(){
    return DateTime(Date::getCurrentDate(),Time::getCurrentTime());
}



std::ostream &operator<<(std::ostream &out, const DateTime& d){
    out<<d.ToString();
    return out;
}
