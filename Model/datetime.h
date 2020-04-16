#ifndef DATETIME_H
#define DATETIME_H
#include "time.h"
#include "date.h"

class DateTime : public Time, public Date
{
public:
    DateTime();
};

#endif // DATETIME_H
