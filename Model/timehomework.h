#ifndef TIMEHOMEWORK_H
#define TIMEHOMEWORK_H

#include "homework.h"
#include "datetime.h"
class TimeHomework : public Homework{
private:
    DateTime deadline;

    void setDeadline ();
public:
    TimeHomework();

    DateTime getDeadline() const;

};

#endif // TIMEHOMEWORK_H
