#pragma once

#include <cstddef>

template <class T>
class IteratorBase
{
public:
    IteratorBase(const IteratorBase &);
    virtual ~IteratorBase();
    IteratorBase &operator=(const IteratorBase &);

    IteratorBase &operator++();
    IteratorBase operator++(int);
    IteratorBase &operator--();
    IteratorBase operator--(int);

    ptrdiff_t operator-(const IteratorBase &);

    bool operator==(const IteratorBase &);
    bool operator!=(const IteratorBase &);

protected:
    IteratorBase(T *);

    T *pointer;
};


#include "base_iterator.hpp"
