#pragma once

template <class T>
IteratorBase<T>::IteratorBase(T *pointer)
{
    this->pointer = pointer;
}

template <class T>
IteratorBase<T>::IteratorBase(const IteratorBase &other)
{
    this->pointer = other.pointer;
}

template <class T>
IteratorBase<T>::~IteratorBase()
{
    this->pointer = nullptr;
}

template <class T>
IteratorBase<T> &IteratorBase<T>::operator=(const IteratorBase &rhs)
{
    if (this != &rhs)
    {
        this->pointer = rhs.pointer;
    }

    return *this;
}

template <class T>
IteratorBase<T> &IteratorBase<T>::operator++()
{
    ++this->pointer;
    return *this;
}

template <class T>
IteratorBase<T> IteratorBase<T>::operator++(int)
{
    IteratorBase temp(*this);
    this->operator++();
    return temp;
}

template <class T>
IteratorBase<T> &IteratorBase<T>::operator--()
{
    --this->pointer;
    return *this;
}

template <class T>
IteratorBase<T> IteratorBase<T>::operator--(int)
{
    IteratorBase temp(*this);
    this->operator--();
    return temp;
}

template <class T>
ptrdiff_t IteratorBase<T>::operator-(const IteratorBase<T> &rhs)
{
    return this->pointer - rhs.pointer;
}

template <class T>
bool IteratorBase<T>::operator==(const IteratorBase &rhs)
{
    return this->pointer == rhs.pointer;
}

template <class T>
bool IteratorBase<T>::operator!=(const IteratorBase &rhs)
{
    return this->pointer != rhs.pointer;
}
