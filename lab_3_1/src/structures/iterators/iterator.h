#pragma once

template <class T>
class VectorBase;
template <class T>
class MatrixBase;

#include "base_iterator.h"

template <class T>
class Iterator : public IteratorBase<T>
{
public:
    Iterator(const Iterator &);

    T &operator*();
    T *operator->();

    friend class VectorBase<T>;
    friend class MatrixBase<T>;

private:
    Iterator(T *);
};

#include "iterator.hpp"
