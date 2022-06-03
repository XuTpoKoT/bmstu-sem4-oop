#pragma once

template <class T>
class VectorBase;
template <class T>
class MatrixBase;

#include "base_iterator.h"

template <class T>
class ConstIterator : public IteratorBase<T>
{
public:
    ConstIterator(const ConstIterator &);

    const T &operator*();
    const T *operator->();

    friend class VectorBase<T>;
    friend class MatrixBase<T>;

private:
    ConstIterator(T *);
};


#include "const_iterator.hpp"
