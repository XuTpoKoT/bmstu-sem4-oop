#ifndef REGULAR_VECTOR_ITERATOR_H
#define REGULAR_VECTOR_ITERATOR_H

#include "BaseVectorIterator.h"

template <typename Type>
class Vector;

template <typename Type>
class RegularVectorIterator : public BaseVectorIterator {
public:
    explicit RegularVectorIterator(const Vector<Type>& v);
    explicit RegularVectorIterator(const RegularVectorIterator& it) = default;

    virtual bool operator!=(RegularVectorIterator<Type> const& it) const;
    virtual bool operator==(RegularVectorIterator<Type> const& it) const;
    virtual bool operator<(RegularVectorIterator<Type> const& it) const;
    virtual bool operator<=(RegularVectorIterator<Type> const& it) const;
    virtual bool operator>(RegularVectorIterator<Type> const& it) const;
    virtual bool operator>=(RegularVectorIterator<Type> const& it) const;

    virtual RegularVectorIterator<Type> operator+(size_t index);
    virtual RegularVectorIterator<Type> operator+=(size_t index);
    virtual RegularVectorIterator<Type> operator++(int);
    virtual RegularVectorIterator<Type>& operator++();

    virtual RegularVectorIterator<Type> operator-(size_t index);
    virtual RegularVectorIterator<Type> operator-=(size_t index);
    virtual RegularVectorIterator<Type> operator--(int);
    virtual RegularVectorIterator<Type>& operator--();

    const Type& operator*() const;
    const Type* operator->() const;

    Type& operator*();
    Type* operator->();

    operator bool() const;

    RegularVectorIterator& operator=(const RegularVectorIterator& it);

private:
    void check_ptr();
    std::weak_ptr<Type[]> data;
};

template <typename Type>
RegularVectorIterator<Type>::RegularVectorIterator(const Vector<Type>& v)
{
    count = v.size;
    data = v.data;
    index = 0;
}

template <typename Type>
void RegularVectorIterator<Type>::check_ptr()
{
    if (this->data.expired()) {
        auto timenow = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
        throw ReferenceVectorException(ctime(&timenow), __FILE__, typeid(RegularVectorIterator).name(), __FUNCTION__);
    }
}

template <typename Type>
bool RegularVectorIterator<Type>::operator!=(const RegularVectorIterator<Type>& it) const
{
    return this->index != it.index;
}

template <typename Type>
bool RegularVectorIterator<Type>::operator==(const RegularVectorIterator<Type>& it) const
{
    return this->index == it.index;
}

template <typename Type>
bool RegularVectorIterator<Type>::operator<(const RegularVectorIterator<Type>& it) const
{
    return this->index < it.index;
}

template <typename Type>
bool RegularVectorIterator<Type>::operator<=(const RegularVectorIterator<Type>& it) const
{
    return this->index <= it.index;
}

template <typename Type>
bool RegularVectorIterator<Type>::operator>(const RegularVectorIterator<Type>& it) const
{
    return this->index > it.index;
}

template <typename Type>
bool RegularVectorIterator<Type>::operator>=(const RegularVectorIterator<Type>& it) const
{
    return this->index >= it.index;
}

template <typename Type>
RegularVectorIterator<Type> RegularVectorIterator<Type>::operator+(size_t index)
{
    RegularVectorIterator it(*this);
    it += index;
    return it;
}

template <typename Type>
RegularVectorIterator<Type> RegularVectorIterator<Type>::operator+=(size_t index)
{
    this->index += index;
    return *this;
}

template <typename Type>
RegularVectorIterator<Type> RegularVectorIterator<Type>::operator++(int)
{
    RegularVectorIterator it(*this);
    ++(*this);
    return it;
}

template <typename Type>
RegularVectorIterator<Type>& RegularVectorIterator<Type>::operator++()
{
    index++;
    return *this;
}

template <typename Type>
RegularVectorIterator<Type> RegularVectorIterator<Type>::operator-(size_t index)
{
    RegularVectorIterator it = *this;
    it -= index;
    return it;
}

template <typename Type>
RegularVectorIterator<Type> RegularVectorIterator<Type>::operator-=(size_t index)
{
    if (this->index < index) {
        auto timenow = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
        throw IndexVectorException(ctime(&timenow), __FILE__, typeid(*this).name(), __FUNCTION__);
    }
    this->index -= index;
    return *this;
}

template <typename Type>
RegularVectorIterator<Type> RegularVectorIterator<Type>::operator--(int)
{
    RegularVectorIterator it(*this);
    --(*this);
    return it;
}

template <typename Type>
RegularVectorIterator<Type>& RegularVectorIterator<Type>::operator--()
{
    if (this->index == 0) {
        auto timenow = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
        throw IndexVectorException(ctime(&timenow), __FILE__, typeid(*this).name(), __FUNCTION__);
    }
    index--;
    return *this;
}

template <typename Type>
const Type& RegularVectorIterator<Type>::operator*() const
{
    this->check_ptr();
    this->check_index();
    std::shared_ptr<Type[]> d = this->data.lock();
    return d[this->index];
}

template <typename Type>
const Type* RegularVectorIterator<Type>::operator->() const
{
    this->check_ptr();
    this->check_index();
    std::shared_ptr<Type[]> d = this->data.lock();
    return &(d[this->index]);
}

template <typename Type>
Type& RegularVectorIterator<Type>::operator*()
{
    this->check_ptr();
    this->check_index();
    std::shared_ptr<Type[]> d = this->data.lock();
    return d[this->index];
}

template <typename Type>
Type* RegularVectorIterator<Type>::operator->()
{
    this->check_ptr();
    this->check_index();
    std::shared_ptr<Type[]> d = this->data.lock();
    return &(d[this->index]);
}

template <typename Type>
RegularVectorIterator<Type>::operator bool() const
{
    return index < count && !data.expired();
}

template <typename Type>
RegularVectorIterator<Type>& RegularVectorIterator<Type>::operator=(const RegularVectorIterator& it)
{
    if (this != &it) {
        this->data = it.data;
        this->count = it.count;
        this->index = it.index;
    }
    return *this;
}

#endif // REGULARVECTORITERATOR_H
