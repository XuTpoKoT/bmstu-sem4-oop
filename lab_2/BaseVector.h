#ifndef BaseVector_h
#define BaseVector_h

#include <cstdlib>

class BaseVector {
public:
    virtual ~BaseVector() = 0;
    
    virtual bool isEmpty() const;
    virtual size_t getSize() const;
    
protected:
    size_t size;
};

#endif
