#pragma once

template <class T>
ConstIterator<T>::ConstIterator(T *pointer) : IteratorBase<T>(pointer)
{
}

template <class T>
ConstIterator<T>::ConstIterator(const ConstIterator &other) : IteratorBase<T>(other.pointer)
{
}

template <class T>
const T &ConstIterator<T>::operator*()
{
    return *this->pointer;
}

template <class T>
const T *ConstIterator<T>::operator->()
{
    return this->pointer;
}
