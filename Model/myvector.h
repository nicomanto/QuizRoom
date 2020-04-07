#ifndef MYVECTOR_H
#define MYVECTOR_H
#include<iostream>
using std::ostream;

template<class T>
class MyVector;

template<class T>
ostream& operator<< (ostream&, const MyVector<T>&);

template<class T>
class MyVector{
private:
    T* first;
    unsigned int my_size;
public:
    MyVector(unsigned int s=0, const T& t=T()) : first(s == 0 ? nullptr : new T[s]), my_size(s) {  //Converte da unsigned int ==> Vettore

        for (int i = 0; i < my_size; ++i) {

            first[i] = t;
        }
    }

    MyVector(const MyVector& v);
    ~MyVector(){};


    unsigned int size() const;
    unsigned int capacity() const;
    bool empty() const;
    T& front();
    T& back();
    void push_back(const T& t);
    void pop_back();
    void clear();

    T& operator[](unsigned int i) const;

    MyVector & operator=(const MyVector&);

    class iterator{
    private:
        typename T::iterator i;
    public:
        iterator(typename T::iterator it);
        T& operator *() const;
        T* operator->() const;
        iterator& operator++();
        iterator operator++(int);
        iterator& operator=(iterator& j);
        bool operator ==(iterator& j) const;
        bool operator !=(iterator& j) const;

    };

    class const_iterator{
    private:
        typename T::const_iterator i;
    public:
        const_iterator(typename T::const_iterator it);
        const_iterator(typename T::iterator it); //conversione
        const T& operator*() const;
        const T* operator->() const;
        const_iterator& operator++();
        const_iterator operator++(int);
        const_iterator& operator=(iterator& j);
        bool operator ==(iterator& j) const;
        bool operator !=(iterator& j) const;

    };

    iterator begin(){};
    iterator end();
};

#endif // MYVECTOR_H
