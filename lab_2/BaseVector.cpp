#include <stdio.h>
#include "BaseVector.h"

BaseVector::~BaseVector() {
}

size_t BaseVector::getSize() const {
    return size;
}

bool BaseVector::isEmpty() const {
    return size == 0;
}
