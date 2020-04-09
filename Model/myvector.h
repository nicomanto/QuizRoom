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
    friend class iterator;
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

    void push_back(const T& t) {insert(end(),t);}
    void pop_back(){
        //punt[my_size-1].~T(); my_size--;
        erase(--end());
    } //da fare try cacth undefined beaviour

    //assicura che il vettore può contenere almeno n elementi
    void reserve (unsigned int n);
    void resize(unsigned int n, const T& t=T());
    void clear() {erase(begin(),end());}


    T& operator[](unsigned int i) const {return punt[i];}

    MyVector& operator=(const MyVector& v);


    bool operator==(const MyVector& v) const;

    MyVector operator+(const MyVector& v) const;

    void append(const MyVector& v) {*this= *this + v;}

    class iterator{
        friend class MyVector<T>;
    private:
        T* i;
        unsigned int past_the_end;
        unsigned int sizeV;
        iterator(T* p, unsigned int temp = 0,unsigned int s=0) :i(p), past_the_end(temp), sizeV(s) {}
    public:
        iterator() : i(nullptr), past_the_end(0), sizeV(1) {}
        T& operator *() const {return *i;}
        T* operator->() const {return &(*i);}
        iterator& operator++();
        iterator operator++(int);
        iterator& operator--();
        iterator operator--(int);
        iterator& operator=(const iterator& j) {i=j.i, past_the_end=j.past_the_end; sizeV=j.sizeV; return *this;}
        bool operator ==(const iterator& j) const {return i==j.i; }
        bool operator !=(const iterator& j) const { return i != j.i;}

    };



    class const_iterator{
    private:
        T* i;
        unsigned int past_the_end;
        unsigned int sizeV;
        const_iterator(T* p, unsigned int temp = 0,unsigned int s=0) :i(p), past_the_end(temp), sizeV(s) {}
    public:
        const_iterator(): i(nullptr), past_the_end(0), sizeV(1) {}
        const_iterator(const iterator& j): i(j.i), past_the_end(j.past_the_end), sizeV(j.sizeV){} //conversione dall'iteratore normale
        const T& operator*() const {return *i;}
        const T* operator->() const {return &(*i);}
        const_iterator& operator++();
        const_iterator operator++(int);
        const_iterator& operator--();
        const_iterator operator--(int);
        const_iterator& operator=(const const_iterator& j) {i=j.i;past_the_end=j.past_the_end; sizeV=j.sizeV; return *this;}
        bool operator ==(const const_iterator& j) const {return i==j.i; }
        bool operator !=(const const_iterator& j) const { return i != j.i;}

    };

    iterator begin(){return iterator(punt,0,my_size);}
    iterator end(){
        if(punt==nullptr)
            return nullptr;
        return iterator((punt+my_size),my_size, my_size);
    }


    iterator erase(iterator it);
    iterator erase(iterator it1, iterator it2);
    iterator insert(iterator it, const T& t);
    void insert(iterator it1, unsigned int n, const T& t);
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
typename MyVector<T>::iterator& MyVector<T>::iterator::operator++() {
        if(i!=nullptr){
            if(past_the_end<sizeV){
                past_the_end++;
                i++;
            }
        }

        return *this;
}


template<class T>
typename MyVector<T>::iterator& MyVector<T>::iterator::operator--() {
        if(i!=nullptr){
            past_the_end--;
            i--;
        }

        return *this;
}

template<class T>
typename MyVector<T>::iterator MyVector<T>::iterator::operator--(int) {
        iterator temp=*this;

        --(*this);

        return temp;


}

template<class T>
typename MyVector<T>::iterator MyVector<T>::iterator::operator++(int) {
        iterator temp=*this;

        ++(*this);

        return temp;


}

template<class T>
typename MyVector<T>::const_iterator& MyVector<T>::const_iterator::operator++() {
        if(i!=nullptr){
            if(past_the_end<sizeV){
                past_the_end++;
                i++;
            }
        }

        return *this;
}


template<class T>
typename MyVector<T>::const_iterator& MyVector<T>::const_iterator::operator--() {
        if(i!=nullptr){
            past_the_end--;
            i--;
        }

        return *this;
}

template<class T>
typename MyVector<T>::const_iterator MyVector<T>::const_iterator::operator--(int) {
        const_iterator temp=*this;

        --(*this);

        return temp;
}

template<class T>
typename MyVector<T>::const_iterator MyVector<T>::const_iterator::operator++(int) {
        const_iterator temp=*this;

        ++(*this);

        return temp;
}


template<class T>
typename MyVector<T>::iterator MyVector<T>::erase(MyVector<T>::iterator it){ //da fare try cacth undefined beaviour
        iterator copy_iterator=it;
        iterator return_iterator=it;
        iterator e=end(); // shortens the vector by 1
        --e;

        while (it != e)
            *copy_iterator++ = *++it;

        resize(my_size-1);// destroy last element in vector
        return_iterator.sizeV=my_size;

        return return_iterator;

}
template<class T>
typename MyVector<T>::iterator MyVector<T>::erase(MyVector<T>::iterator it1, MyVector<T>::iterator it2){ //da fare try cacth undefined beaviour
        int lenght_remove=it2.past_the_end-it1.past_the_end;

        if(lenght_remove>=0){
            iterator copy_iterator=it1;

            while (it2 != end())
                *copy_iterator++ = *it2++;


            resize(my_size-(lenght_remove));
            return copy_iterator;
        }
        else{
            //eccezzione
            return end();
        }
}

template<class T>
typename MyVector<T>::iterator MyVector<T>::insert(MyVector<T>::iterator it, const T& t){  //da fare try cacth undefined beaviour
    resize(my_size+1);
    iterator copy_iterator=end();
    --copy_iterator;
    iterator return_iterator=copy_iterator;


    while (return_iterator.past_the_end != it.past_the_end)
        *copy_iterator--=*--return_iterator;

    *return_iterator=t;

    return return_iterator;
}

template<class T>
void MyVector<T>::insert(MyVector<T>::iterator it,unsigned int n, const T& t){ //da fare try cacth undefined beaviour
    resize(my_size+n);

    iterator temp=end();

    for(unsigned int i=it.past_the_end;i<it.sizeV;++i)
        *--temp=punt[i];



    while(temp.past_the_end != it.past_the_end)
        *--temp=t;
}

template<class T>
std::ostream& operator<<(std::ostream& os, const MyVector<T>& v) {
    for (unsigned int i = 0; i < v.my_size; ++i)
        os << v[i] << " ";


    return os;
}


#endif // MYVECTOR_H
