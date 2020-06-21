#ifndef DATETIME_H
#define DATETIME_H
#include "time.h"
#include "date.h"

class DateTime : public Time, public Date{
public:
    DateTime();
    DateTime(unsigned int d, unsigned int m, unsigned int y, unsigned int o, unsigned int mi=0);
    DateTime(const Date& d, const Time& t);

    std::string ToString() const;

    bool operator<(const DateTime& d) const;
    bool operator>(const DateTime& d) const;
    bool operator==(const DateTime& d) const;
    bool operator!=(const DateTime& d) const;

    static DateTime getCurrentDateTime();
};

std::ostream &operator<<(std::ostream &out, const DateTime& d);

#endif // DATETIME_H
