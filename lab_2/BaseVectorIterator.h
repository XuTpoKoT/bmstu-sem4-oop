#ifndef BASE_VECTOR_ITERATOR_H
#define BASE_VECTOR_ITERATOR_H

#include <iostream>
#include <memory>
#include <cstdlib>

#include "VectorException.h"

class BaseVectorIterator {
public:
    virtual ~BaseVectorIterator() = 0;

protected:
    void check_index() const;
    size_t count;
    size_t index;
};

#endif // BASEVECTORITERATOR_H
