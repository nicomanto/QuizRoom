#include "../Header/myvector.h"
template<class T>
MyVector<T>::MyVector(unsigned int s, const T &t)

template<class T>
MyVector<T>::MyVector(const MyVector<T> &v)
{

}

template<class T>
MyVector<T>::~MyVector()
{

}

template<class T>
unsigned int MyVector<T>::size() const
{

}

template<class T>
unsigned int MyVector<T>::capacity() const
{

}

template<class T>
bool MyVector<T>::empty() const
{

}

template<class T>
T& MyVector<T>::front()
{

}

template<class T>
T& MyVector<T>::back()
{

}

template<class T>
void MyVector<T>::push_back(const T &t)
{

}

template<class T>
void MyVector<T>::pop_back()
{

}

template<class T>
void MyVector<T>::clear()
{

}

template<class T>
T& MyVector<T>::operator[](unsigned int i) const
{

}

template<class T>
MyVector<T>& MyVector<T>::operator=(const MyVector<T> &)
{

}

template<class T>
MyVector<T>::iterator::iterator(typename T::iterator it) : i(it){

}

template<class T>
T& MyVector<T>::iterator::operator *() const
{

}

template<class T>
T* MyVector<T>::iterator::operator->() const
{

}

template<class T>
typename MyVector<T>::iterator& MyVector<T>::iterator::operator++()
{

}

template<class T>
typename MyVector<T>::iterator MyVector<T>::iterator::operator++(int)
{

}

template<class T>
typename MyVector<T>::iterator &MyVector<T>::iterator::operator=(MyVector<T>::iterator &j)
{

}

template<class T>
bool MyVector<T>::iterator::operator ==(MyVector<T>::iterator& j) const
{

}

template<class T>
bool MyVector<T>::iterator::operator !=(MyVector<T>::iterator &j) const
{

}

template<class T>
MyVector<T>::const_iterator::const_iterator(typename T::const_iterator it)
{

}

template<class T>
MyVector<T>::const_iterator::const_iterator(typename T::iterator it)
{

}

template<class T>
const T& MyVector<T>::const_iterator::operator*() const
{

}

template<class T>
const T *MyVector<T>::const_iterator::operator->() const
{

}

template<class T>
typename MyVector<T>::const_iterator& MyVector<T>::const_iterator::operator++()
{

}

template<class T>
typename MyVector<T>::const_iterator MyVector<T>::const_iterator::operator++(int)
{

}

template<class T>
typename MyVector<T>::const_iterator& MyVector<T>::const_iterator::operator=(MyVector<T>::iterator &j)
{

}

template<class T>
bool MyVector<T>::const_iterator::operator ==(MyVector<T>::iterator &j) const
{

}

template<class T>
bool MyVector<T>::const_iterator::operator !=(MyVector<T>::iterator &j) const
{

}
