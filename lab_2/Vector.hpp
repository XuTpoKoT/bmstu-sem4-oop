#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <stdlib.h>
#include <cstddef>

#include "Vector.h"
#include "VectorException.h"

#include <cmath>

#define EPS 1e-6

template <typename Type>
std::shared_ptr<Type[]> Vector<Type>::allocate_memory(size_t size)
{
    if (size == 0) {
        auto timenow = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
        throw SizeVectorException(ctime(&timenow), __FILE__, typeid(Vector).name(), __FUNCTION__);
    }

    try {
        return std::make_shared<Type[]>(size);
    } catch (std::bad_alloc& err) {
        auto timenow = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
        throw MemoryAllocationVectorException(ctime(&timenow), __FILE__, typeid(Vector).name(), __FUNCTION__);
    }
}

template <typename Type>
void Vector<Type>::check_size(size_t size) const
{
    if (this->size != size) {
        auto timenow = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
        throw SizeVectorException(ctime(&timenow), __FILE__, typeid(Vector).name(), __FUNCTION__);
    }
}

template <typename Type>
void Vector<Type>::check_index(size_t index, size_t limit) const
{
    if (index >= limit) {
        auto timenow = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
        throw IndexVectorException(ctime(&timenow), __FILE__, typeid(Vector).name(), __FUNCTION__);
    }
}

// Констукторы
template <typename Type>
Vector<Type>::Vector(size_t size)
{
    this->size = size;
    this->data = allocate_memory(size);
}

template <typename Type>
Vector<Type>::Vector(std::initializer_list<Type> list)
{
    this->size = list.size();
    this->data = allocate_memory(this->size);

    size_t i = 0;
    for (auto elem : list)
        this->data[i++] = elem;
}

template <typename Type>
Vector<Type>::Vector(size_t size, const Type* vector)
{
    this->size = size;
    this->data = allocate_memory(size);
    for (size_t i = 0; i < size; i++)
        this->data[i] = vector[i];
}

template<typename Type>
Vector<Type>::Vector(size_t size, Type val, ...)
{
    this->size = size;
    data = allocate_memory(size);

    va_list lst;
    va_start(lst, val);
    for (size_t i = 0; i < size; i++) {
        this->data[i] = val;
        val = va_arg(lst, Type);
    }
    va_end(lst);
}

template <typename Type>
Vector<Type>::Vector(std::vector<Type> v)
{
    this->count = v.size();
    this->data = allocate_memory(v.count);
    for (size_t i = 0; i < v.size(); i++)
        this->data[i] = v[i];
}

template <typename Type>
Vector<Type>::Vector(const Vector& vector)
{
    this->size = vector.size;
    this->data = allocate_memory(vector.size);
    for (size_t i = 0; i < vector.size; i++)
        this->data[i] = vector.data[i];
}

template <typename Type>
Vector<Type>::Vector(Vector&& vector) noexcept
{
    this->size = vector.size;
    this->data = vector.data;
}

// операторы присваивания
template <typename Type>
Vector<Type>& Vector<Type>::operator=(const Vector<Type>& vector)
{
    this->size = vector.size;
    this->data = allocate_memory(vector.size);
    for (size_t i = 0; i < this->size; i++)
        this->data[i] = vector.data[i];
    return *this;
}

template <typename Type>
Vector<Type>& Vector<Type>::operator=(Vector<Type>&& vector)
{
    this->size = vector.size;
    this->data = vector.data;
    return *this;
}

template <typename Type>
Vector<Type>& Vector<Type>::operator=(std::initializer_list<Type> list)
{
    this->size = list.size();
    this->data = allocate_memory(this->size);
    size_t i = 0;
    for (const auto& elem : list)
        this->data[i++] = elem;
    return *this;
}

// сложение вектора с вектором
template <typename Type>
template <typename Type2>
decltype(auto) Vector<Type>::operator+(const Vector<Type2>& v) const
{
    check_size(v.size);
    Vector<decltype(this->data[0] + v.data[0])> res(v.size);
    for (size_t i = 0; i < res.size; i++)
        res[i] = this->data[i] + v.data[i];
    return res;
}

template <typename Type>
Vector<Type>& Vector<Type>::operator+=(const Vector<Type>& v)
{
    check_size(v.size);
    for (size_t i = 0; i < v.size; i++)
        this->data[i] += v[i];
    return *this;
}

template <typename Type>
template <typename Type2>
decltype(auto) Vector<Type>::add(const Vector<Type2>& v) const
{
    return operator+(v);
}

template <typename Type>
Vector<Type>& Vector<Type>::add_equal(const Vector<Type>& v) const
{
    return operator+=(v);
}

// сложение вектора с числом
template <typename Type>
template <typename Type2>
decltype(auto) Vector<Type>::operator+(const Type2& element) const noexcept
{
    Vector<decltype(this->data[0] + element)> res(this->size);
    for (size_t i = 0; i < this->size; i++)
        res[i] = this->data[i] + element;
    return res;
}

template <typename Type>
Vector<Type>& Vector<Type>::operator+=(const Type& element) noexcept
{
    for (size_t i = 0; i < this->size; i++)
        this->data[i] += element;
    return *this;
}

template <typename Type>
template <typename Type2>
decltype(auto) Vector<Type>::add_element(const Type2& element) const noexcept
{
    return operator+(element);
}

template <typename Type>
Vector<Type>& Vector<Type>::add_equal_element(const Type& element) const noexcept
{
    return operator+=(element);
}

// вычитание вектора из вектора
template <typename Type>
template <typename Type2>
decltype(auto) Vector<Type>::operator-(const Vector<Type2>& v) const
{
    check_size(v.size);
    Vector<decltype(this->data[0] + v.data[0])> res(v.size);
    for (size_t i = 0; i < res.size; i++)
        res[i] = this->data[i] - v.data[i];
    return res;
}

template <typename Type>
Vector<Type>& Vector<Type>::operator-=(const Vector<Type>& v)
{
    check_size(v.size);
    for (size_t i = 0; i < v.size; i++)
        this->data[i] -= v[i];
    return *this;
}

template <typename Type>
template <typename Type2>
decltype(auto) Vector<Type>::sub(const Vector<Type2>& v) const
{
    return operator-(v);
}

template <typename Type>
Vector<Type>& Vector<Type>::sub_equal(const Vector<Type>& v) const
{
    return operator-=(v);
}

// вычитание числа из вектора
template <typename Type>
template <typename Type2>
decltype(auto) Vector<Type>::operator-(const Type2& element) const noexcept
{
    Vector<decltype(this->data[0] - element)> res(this->size);
    for (size_t i = 0; i < this->size; i++)
        res.data[i] = this->data[i] - element;
    return res;
}

template <typename Type>
Vector<Type>& Vector<Type>::operator-=(const Type& element) noexcept
{
    for (size_t i = 0; i < this->size; i++)
        this->data[i] -= element;
    return *this;
}

template <typename Type>
template <typename Type2>
decltype(auto) Vector<Type>::sub_element(const Type2& element) const noexcept
{
    return operator-(element);
}

template <typename Type>
Vector<Type>& Vector<Type>::sub_equal_element(const Type& element) const noexcept
{
    return operator-=(element);
}

// скалярное
template <typename Type>
Type Vector<Type>::operator*(const Vector<Type>& v) const
{
    check_size(v.size);
    Type res = 0;
    for (size_t i = 0; i < v.size; i++)
        res += this->data[i] * v.data[i];
    return res;
}

template <typename Type>
Type Vector<Type>::dot_product(const Vector<Type>& v) const
{
    return operator*(v);
}

// умножение вектора на число
template <typename Type>
template <typename Type2>
decltype(auto) Vector<Type>::operator^(const Type2& element) const noexcept
{
    Vector<decltype(this->data[0] * element)> res(this->size);
    for (size_t i = 0; i < res.size; i++)
        res.data[i] = this->data[i] * element;
    return res;
}

template <typename Type>
Vector<Type>& Vector<Type>::operator^=(const Type& element) noexcept
{
    for (size_t i = 0; i < this->size; i++)
        this->data[i] *= element;
    return *this;
}

template <typename Type>
template <typename Type2>
decltype(auto) Vector<Type>::mul_element(const Type2& element) const noexcept
{
    return operator*(element);
}

template <typename Type>
Vector<Type>& Vector<Type>::mul_equal_element(const Type& element) const noexcept
{
    return operator^=(element);
}

// поэлементное умножение
template <typename Type>
template <typename Type2>
decltype(auto) Vector<Type>::operator^(const Vector<Type2>& v) const
{
    check_size(v.size);
    Vector<decltype(this->data[0] * v.data[0])> res(v.size);
    for (size_t i = 0; i < v.size; i++)
        res.data[i] = this->data[i] * v.data[i];
    return res;
}

template <typename Type>
Vector<Type>& Vector<Type>::operator^=(const Vector<Type>& v)
{
    check_size(v.size);
    for (size_t i = 0; i < v.size; i++)
        this->data[i] *= v.data[i];
    return *this;
}

template <typename Type>
template <typename Type2>
decltype(auto) Vector<Type>::mul(const Vector<Type2>& v) const
{
    return operator^(v);
}

template <typename Type>
Vector<Type>& Vector<Type>::mul_equal(const Vector<Type>& v) const
{
    return operator^=(v);
}

// векторное произведение
template <typename Type>
template <typename Type2>
decltype(auto) Vector<Type>::operator|(const Vector<Type2>& v) const
{
    check_size(v.size);
    check_size(3);
    Vector<decltype(this->data[0] * v.data[0])> res(v.size);

    res[0] = this->data[1] * v.data[2] - this->data[2] * v.data[1];
    res[1] = this->data[2] * v.data[0] - this->data[0] * v.data[2];
    res[2] = this->data[0] * v.data[1] - this->data[1] * v.data[0];

    return res;
}

template <typename Type>
Vector<Type>& Vector<Type>::operator|=(const Vector<Type>& v)
{
    check_size(v.size);
    check_size(3);

    Type x = this->data[1] * v.data[2] - this->data[2] * v.data[1];
    Type y = this->data[2] * v.data[0] - this->data[0] * v.data[2];
    Type z = this->data[0] * v.data[1] - this->data[1] * v.data[0];

    this->data[0] = x;
    this->data[1] = y;
    this->data[2] = z;

    return *this;
}

template <typename Type>
template <typename Type2>
decltype(auto) Vector<Type>::cross_product(const Vector<Type2>& v) const
{
    return operator|(v);
}

template <typename Type>
Vector<Type>& Vector<Type>::cross_product_equal(const Vector<Type>& v) const
{
    return operator|=(v);
}

// деление вектора на вектор
template <typename Type>
template <typename Type2>
decltype(auto) Vector<Type>::operator/(const Vector<Type2>& v) const
{
    check_size(v.size);
    Vector<decltype(this->data[0] + v.data[0])> res(v.size);
    for (size_t i = 0; i < v.size; i++) {
        if (fabs(v.data[i]) < EPS) {
            auto timenow = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
            throw DivisionByZeroVectorException(ctime(&timenow), __FILE__, typeid(Vector).name(), __FUNCTION__);
        }
        res.data[i] = this->data[i] / v.data[i];
    }

    return res;
}

template <typename Type>
Vector<Type>& Vector<Type>::operator/=(const Vector<Type>& v)
{
    check_size(v.size);
    for (size_t i = 0; i < v.size; i++) {
        if (fabs(v.data[i]) < EPS) {
            auto timenow = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
            throw DivisionByZeroVectorException(ctime(&timenow), __FILE__, typeid(Vector).name(), __FUNCTION__);
        }
        this->data[i] /= v.data[i];
    }

    return *this;
}

template <typename Type>
template <typename Type2>
decltype(auto) Vector<Type>::div(const Vector<Type2>& v) const
{
    return operator/(v);
}

template <typename Type>
Vector<Type>& Vector<Type>::div_equal(const Vector<Type>& v) const
{
    return operator/=(v);
}

// деление вектора на число
template <typename Type>
template <typename Type2>
decltype(auto) Vector<Type>::operator/(const Type2& element) const
{
    if (fabs(element) < EPS) {
        auto timenow = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
        throw DivisionByZeroVectorException(ctime(&timenow), __FILE__, typeid(Vector).name(), __FUNCTION__);
    }
    Vector<decltype(this->data[0] + element)> res(this->size);
    for (size_t i = 0; i < this->size; i++)
        res.data[i] = this->data[i] / element;

    return res;
}

template <typename Type>
Vector<Type>& Vector<Type>::operator/=(const Type& element)
{
    if (fabs(element) < EPS) {
        auto timenow = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
        throw DivisionByZeroVectorException(ctime(&timenow), __FILE__, typeid(Vector).name(), __FUNCTION__);
    }
    for (size_t i = 0; i < this->size; i++)
        this->data[i] /= element;

    return *this;
}

template <typename Type>
template <typename Type2>
decltype(auto) Vector<Type>::div_element(const Type2& element) const
{
    return operator/(element);
}

template <typename Type>
Vector<Type>& Vector<Type>::div_equal_element(const Type& element) const
{
    return operator/=(element);
}

// равенство / неравенство
template <typename Type>
bool Vector<Type>::operator==(const Vector<Type>& v) noexcept
{
    if (this->size != v.size)
        return false;

    for (size_t i = 0; i < v.size; i++)
        if ((this->data[i] != v.data[i]))
            return false;
    return true;
}

template <typename Type>
bool Vector<Type>::operator!=(const Vector<Type>& v) noexcept
{
    return !operator==(v);
}

template <typename Type>
bool Vector<Type>::equals(const Vector<Type>& v) noexcept
{
    return operator==(v);
}

// отрицание
template <typename Type>
Vector<Type> Vector<Type>::operator-() const noexcept
{
    Vector<Type> res(this->size);
    for (size_t i = 0; i < this->size; i++)
        res[i] = -data[i];
    return res;
}

template <typename Type>
Vector<Type> Vector<Type>::negative() const noexcept
{
    return operator-();
}

// []
template <typename Type>
Type& Vector<Type>::operator[](size_t index)
{
    check_index(index, this->size);
    return this->data[index];
}

template <typename Type>
const Type& Vector<Type>::operator[](size_t index) const
{
    check_index(index, this->size);
    return this->data[index];
}

template <typename Type>
const Type& Vector<Type>::get_element(size_t index) const
{
    return operator[](index);
}

template <typename Type>
void Vector<Type>::set_element(size_t index, const Type& element)
{
    operator[](index) = element;
}

// математические методы
template <typename Type>
double Vector<Type>::lenght() const noexcept
{
    double len = 0;
    for (size_t i = 0; i < this->size; i++)
        len += this->data[i] * this->data[i];
    return std::sqrt(len);
}

template <typename Type>
bool Vector<Type>::is_unit() const noexcept
{
    return fabs(lenght() - 1) < EPS;
}

template <typename Type>
double Vector<Type>::angle(Vector<Type>& v) const
{
    return acos(dot_product(v) / lenght() / v.lenght()) * 180 / M_PI;
}

template <typename Type>
bool Vector<Type>::is_orthogonality(const Vector<Type>& v) const
{
    return dot_product(v) == 0;
}

template <typename Type>
bool Vector<Type>::is_collinearity(Vector<Type>& v) const
{
    return angle(v) < EPS;
}

template <typename Type>
Vector<Type> Vector<Type>::get_single() const
{
    Vector<Type> res(*this);
    return res / lenght();
}

// итераторы
template <typename Type>
RegularVectorIterator<Type> Vector<Type>::begin()
{
    RegularVectorIterator<Type> it(*this);
    return it + size;
}

template <typename Type>
RegularVectorIterator<Type> Vector<Type>::end()
{
    RegularVectorIterator<Type> it(*this);
    return it;
}

template <typename Type>
ConstVectorIterator<Type> Vector<Type>::begin() const
{
    ConstVectorIterator<Type> it(*this);
    return it;
}

template <typename Type>
ConstVectorIterator<Type> Vector<Type>::end() const
{
    ConstVectorIterator<Type> it(*this);
    return it + size;
}

template <typename Type>
ConstVectorIterator<Type> Vector<Type>::cbegin() const
{
    ConstVectorIterator<Type> it(*this);
    return it;
}

template <typename Type>
ConstVectorIterator<Type> Vector<Type>::cend() const
{
    ConstVectorIterator<Type> it(*this);
    return it + size;
}

// операторы работы с потоком
template <typename Type2>
std::ostream& operator<<(std::ostream& stream, const Vector<Type2>& v)
{
    for (auto it = v.cbegin(); it != v.cend(); ++it)
        stream << *it << " ";
    return stream;
}

template <typename Type2>
std::istream& operator>>(std::istream& stream, Vector<Type2>& v)
{
    for (auto it = v.begin(); it != v.end(); ++it)
        stream >> *it;
    return stream;
}

#endif

