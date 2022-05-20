#ifndef CONST_VECTOR_ITERATOR_H
#define CONST_VECTOR_ITERATOR_H

#include "BaseVectorIterator.h"

template <typename Type>
class Vector;

template <typename Type>
class ConstVectorIterator : public BaseVectorIterator {
public:
    explicit ConstVectorIterator(const Vector<Type>& v);
    ConstVectorIterator(const ConstVectorIterator& it) = default;

    virtual bool operator!=(ConstVectorIterator<Type> const& it) const;
    virtual bool operator==(ConstVectorIterator<Type> const& it) const;
    virtual bool operator<(ConstVectorIterator<Type> const& it) const;
    virtual bool operator<=(ConstVectorIterator<Type> const& it) const;
    virtual bool operator>(ConstVectorIterator<Type> const& it) const;
    virtual bool operator>=(ConstVectorIterator<Type> const& it) const;

    virtual ConstVectorIterator<Type> operator+(size_t index);
    virtual ConstVectorIterator<Type> operator+=(size_t index);
    virtual ConstVectorIterator<Type> operator++(int);
    virtual ConstVectorIterator<Type>& operator++();

    virtual ConstVectorIterator<Type> operator-(size_t index);
    virtual ConstVectorIterator<Type> operator-=(size_t index);
    virtual ConstVectorIterator<Type> operator--(int);
    virtual ConstVectorIterator<Type>& operator--();

    const Type& operator*() const;
    const Type* operator->() const;

    operator bool() const;

    ConstVectorIterator& operator=(const ConstVectorIterator& it);

private:
    void check_ptr() const;
    std::weak_ptr<Type[]> data;
};

template <typename Type>
ConstVectorIterator<Type>::ConstVectorIterator(const Vector<Type>& v)
{
    count = v.size;
    data = v.data;
    index = 0;
}

template <typename Type>
void ConstVectorIterator<Type>::check_ptr() const
{
    if (this->data.expired()) {
        auto timenow = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
        throw ReferenceVectorException(ctime(&timenow), __FILE__, typeid(ConstVectorIterator).name(), __FUNCTION__);
    }
}

template <typename Type>
bool ConstVectorIterator<Type>::operator!=(const ConstVectorIterator<Type>& it) const
{
    return this->index != it.index;
}

template <typename Type>
bool ConstVectorIterator<Type>::operator==(const ConstVectorIterator<Type>& it) const
{
    return this->index == it.index;
}

template <typename Type>
bool ConstVectorIterator<Type>::operator<(const ConstVectorIterator<Type>& it) const
{
    return this->index < it.index;
}

template <typename Type>
bool ConstVectorIterator<Type>::operator<=(const ConstVectorIterator<Type>& it) const
{
    return this->index <= it.index;
}

template <typename Type>
bool ConstVectorIterator<Type>::operator>(const ConstVectorIterator<Type>& it) const
{
    return this->index > it.index;
}

template <typename Type>
bool ConstVectorIterator<Type>::operator>=(const ConstVectorIterator<Type>& it) const
{
    return this->index >= it.index;
}

template <typename Type>
ConstVectorIterator<Type> ConstVectorIterator<Type>::operator+(size_t index)
{
    ConstVectorIterator it(*this);
    it += index;
    return it;
}

template <typename Type>
ConstVectorIterator<Type> ConstVectorIterator<Type>::operator+=(size_t index)
{
    this->index += index;
    return *this;
}

template <typename Type>
ConstVectorIterator<Type> ConstVectorIterator<Type>::operator++(int)
{
    ConstVectorIterator it(*this);
    ++(*this);
    return it;
}

template <typename Type>
ConstVectorIterator<Type>& ConstVectorIterator<Type>::operator++()
{
    index++;
    return *this;
}

template <typename Type>
ConstVectorIterator<Type> ConstVectorIterator<Type>::operator-(size_t index)
{
    ConstVectorIterator it = *this;
    it -= index;
    return it;
}

template <typename Type>
ConstVectorIterator<Type> ConstVectorIterator<Type>::operator-=(size_t index)
{
    if (this->index < index) {
        auto timenow = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
        throw IndexVectorException(ctime(&timenow), __FILE__, typeid(*this).name(), __FUNCTION__);
    }
    this->index -= index;
    return *this;
}

template <typename Type>
ConstVectorIterator<Type> ConstVectorIterator<Type>::operator--(int)
{
    ConstVectorIterator it(*this);
    --(*this);
    return it;
}

template <typename Type>
ConstVectorIterator<Type>& ConstVectorIterator<Type>::operator--()
{
    if (this->index == 0) {
        auto timenow = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
        throw IndexVectorException(ctime(&timenow), __FILE__, typeid(*this).name(), __FUNCTION__);
    }
    index--;
    return *this;
}

template <typename Type>
const Type& ConstVectorIterator<Type>::operator*() const
{
    this->check_ptr();
    this->check_index();
    std::shared_ptr<Type[]> d = this->data.lock();
    return d[this->index];
}

template <typename Type>
const Type* ConstVectorIterator<Type>::operator->() const
{
    this->check_ptr();
    this->check_index();
    std::shared_ptr<Type> d = this->data.lock();
    return &(d[this->index]);
}

template <typename Type>
ConstVectorIterator<Type>::operator bool() const
{
    return index < count && !data.expired();
}

template <typename Type>
ConstVectorIterator<Type>& ConstVectorIterator<Type>::operator=(const ConstVectorIterator& it)
{
    if (this != &it) {
        this->data = it.data;
        this->count = it.count;
        this->index = it.index;
    }
    return *this;
}

#endif
