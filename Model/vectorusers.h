#ifndef VECTORUSERS_H
#define VECTORUSERS_H

#include <stdexcept>

#include "teacher.h"
#include "student.h"
#include "myvector.h"

class VectorUsers{
private:
    MyVector<User*> users;
public:
    VectorUsers();
    ~VectorUsers()=default;

    User* getUser(const string& u, const string& p) const;
};

#endif // VECTORUSERS_H
