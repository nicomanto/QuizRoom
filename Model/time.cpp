#include "time.h"

Time::Time(unsigned int h, unsigned int m){
    if(h>23 || m>59)
        throw::std::out_of_range (std::to_string(h)+":"+std::to_string(m)+" non rappresenta un orario.");

    else
        minutes= h*60 + m;

}

unsigned int Time::Hours() const{
    return minutes /60;
}

unsigned int Time::Minutes() const{
    return minutes % 60;
}


std::string Time::ToString() const{
    std::string temp,m,h;

    if(Hours()<10)
        h+="0";
    if(Minutes()<10)
        m+="0";

    temp+= h+std::to_string(Hours())+":"+m+std::to_string(Minutes());

    return temp;
}

bool Time::operator<(const Time &t) const{
    if(Hours()<t.Hours())
        return true;

    if(Hours()==t.Hours() && Minutes()<t.Minutes()){
        if(Minutes()>t.Minutes())
            return false;
        else if(Minutes()==t.Minutes())
            return false;
        else
            return true;
    }

    return true;
}

bool Time::operator>(const Time &t) const{
    return !(*this<t) && !(*this==t);
}

bool Time::operator==(const Time &t) const{
     return Hours()==t.Hours() && Minutes()==t.Minutes();
}

bool Time::operator!=(const Time &t) const{
   return !(*this==t);
}

Time Time::getCurrentTime(){

    std::time_t current_time = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());

    const std::tm temp = *std::localtime( std::addressof(current_time) );

    return Time(temp.tm_hour,temp.tm_min);


}


std::ostream& operator<<(std::ostream &out, const Time& t){
    out<<t.ToString();
    return out;
}
