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
    friend ostream& operator<< <T> (ostream&, const MyVector<T>&);
private:
    T* punt;
    unsigned int my_size;
    unsigned int my_capacity;
public:

    MyVector(unsigned int s=0, const T& t=T());
    MyVector(const MyVector& v);
    ~MyVector(){delete[] punt;}

    unsigned int size() const {return my_size;}
    unsigned int capacity() const {return my_capacity;}
    bool empty() const {return my_size==0;}
    T& front() const {return punt[0];} //ritorna il primo elemento
    T& back()const {return punt[my_size-1];} // ritorna l'ultimo elemento

    void push_back(const T& t);
    void pop_back(){punt[my_size-1].~T();--my_size;} //da fare try cacth undefined beaviour

    //assicura che il vettore può contenere almeno n elementi
    void reserve (unsigned int n);
    void resize(unsigned int n, const T& t=T());
    void clear();

    T& operator[](unsigned int i) const {return punt[i];}

    MyVector& operator=(const MyVector& v);


    bool operator==(const MyVector& v) const;

    MyVector operator+(const MyVector& v) const;

    void append(const MyVector& v) {*this= *this + v;}

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

    iterator begin(){}
    iterator end();
};

template <class T>
MyVector<T>::MyVector(unsigned int s, const T& t) : punt(s == 0 ? nullptr : new T[s]), my_size(s), my_capacity(s) {  //Converte da unsigned int ==> Vettore

    for (unsigned int i = 0; i < my_size; ++i) {

        punt[i] = t;
    }
}

template <class T>
MyVector<T>::MyVector(const MyVector& v): punt(v.my_size==0? nullptr : new T[v.my_size]), my_size(v.my_size), my_capacity(v.my_capacity){
    for (unsigned int i=0; i<my_size;++i){
        punt[i]=v[i];
    }
}

template <class T>
void MyVector<T>::push_back(const T& t){
    resize(my_size+1);

    punt[my_size-1]=t;
}


//assicura che il vettore può contenere almeno n elementi
template<class T>
void MyVector<T>::reserve (unsigned int n){
    if(my_capacity<n){
        T* temp= new T[2*n]; //aumento del doppio per sicurezza

        my_capacity=2*n;
        for(unsigned int i=0;i<my_size;++i)
            temp[i]=punt[i];

        delete[] punt;
        punt=temp;
    }

}

template<class T>
void MyVector<T>::resize(unsigned int n, const T& t){
    if(n<=my_size){
        for(unsigned int i=n;i<my_size;++i)
            punt[i].~T();
    }
    else{
        reserve(n);
        for(unsigned int i=my_size;i<n;++i)
            punt[i]=t;
    }


    my_size=n;
}

template<class T>
void MyVector<T>::clear(){
    delete [] punt;
    punt=nullptr;
    my_size=0;
    my_capacity=0;
}


template<class T>
MyVector<T>& MyVector<T>::operator=(const MyVector<T>& v) {
       if(this!=&v){
           delete [] punt;
           punt =(v.my_size==0? nullptr: new T[v.my_capacity]);
           my_size=v.my_size;
           my_capacity=v.my_capacity;

           for(unsigned int i=0;i<my_size;i++)
               punt[i]=v[i];
       }

       return *this;
}


template<class T>
bool MyVector<T>::operator==(const MyVector<T>& v) const {

        if (this == &v)
            return true;

        if (v.my_size != my_size)
            return false;

        if(my_capacity!=v.my_capacity)
            return false;

        for (unsigned int i = 0; i < my_size; i++) {
            if (punt[i] != v[i])
                return false;
        }

        return true;

}

template<class T>
MyVector<T> MyVector<T>::operator+(const MyVector<T>& v) const {
    MyVector temp(my_size + v.my_size);
    unsigned int i;

    for (i = 0; i < my_size; ++i) {
        temp.punt[i] = punt[i];
    }

    for (unsigned int j = i, k=0; k < v.my_size; ++j, ++k) {

        temp.punt[j] = v.punt[k];
    }

    return temp;
}



template<class T>
std::ostream& operator<<(std::ostream& os, const MyVector<T>& v) {
    for (unsigned int i = 0; i < v.my_size; ++i) {
        //std::cout << "indice: "<<i << std::endl;
        os << v[i] << " ";
    }

    return os;
}


#endif // MYVECTOR_H
