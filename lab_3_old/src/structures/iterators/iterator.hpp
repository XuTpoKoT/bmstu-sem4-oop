#pragma once

template <class T>
Iterator<T>::Iterator(T *pointer) : IteratorBase<T>(pointer)
{
}

template <class T>
Iterator<T>::Iterator(const Iterator &other) : IteratorBase<T>(other.pointer)
{
}

template <class T>
T &Iterator<T>::operator*()
{
    return *this->pointer;
}

template <class T>
T *Iterator<T>::operator->()
{
    return this->pointer;
}
