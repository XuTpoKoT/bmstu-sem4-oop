#ifndef VECTOR_H
#define VECTOR_H

#include <stdarg.h>
#include <cmath>
#include <iostream>
#include <initializer_list>
#include <memory>
#include <vector>
#include <stdexcept>

#include "BaseVector.h"
#include "ConstVectorIterator.h"
#include "RegularVectorIterator.h"

template<typename Type>
class Vector: public BaseVector
{
public:
    friend class ConstVectorIterator<Type>;
    friend class RegularVectorIterator<Type>;
    
    explicit Vector(size_t size);
    Vector(size_t size, const Type* vec);
    Vector(size_t size, Type val, ...);
    Vector(std::initializer_list<Type> args);
    explicit Vector(std::vector<Type> v);
    explicit Vector(const Vector<Type> &vec);
    Vector(Vector<Type>&& vec) noexcept;
    virtual ~Vector() {}

    Vector<Type>& operator=(const Vector<Type>& vector);
    Vector<Type>& operator=(Vector<Type>&& vector);
    Vector<Type>& operator=(std::initializer_list<Type> list);

    template <typename Type2>
    decltype(auto) operator+(const Vector<Type2>& v) const;
    Vector<Type>& operator+=(const Vector<Type>& v);
    template <typename Type2>
    decltype(auto) add(const Vector<Type2>& v) const;
    Vector<Type>& add_equal(const Vector<Type>& v) const;

    template <typename Type2>
    decltype(auto) operator+(const Type2& element) const noexcept;
    Vector<Type>& operator+=(const Type& element) noexcept;
    template <typename Type2>
    decltype(auto) add_element(const Type2& element) const noexcept;
    Vector<Type>& add_equal_element(const Type& element) const noexcept;

    template <typename Type2>
    decltype(auto) operator-(const Vector<Type2>& v) const;
    Vector<Type>& operator-=(const Vector<Type>& v);
    template <typename Type2>
    decltype(auto) sub(const Vector<Type2>& v) const;
    Vector<Type>& sub_equal(const Vector<Type>& v) const;

    template <typename Type2>
    decltype(auto) operator-(const Type2& element) const noexcept;
    Vector<Type>& operator-=(const Type& element) noexcept;
    template <typename Type2>
    decltype(auto) sub_element(const Type2& element) const noexcept;
    Vector<Type>& sub_equal_element(const Type& element) const noexcept;

    // скалярное умножение
    Type operator*(const Vector<Type>& v) const;
    Type dot_product(const Vector<Type>& v) const;

    // умножение вектора на число
    template <typename Type2>
    decltype(auto) operator^(const Type2& element) const noexcept;
    Vector<Type>& operator^=(const Type& element) noexcept;
    template <typename Type2>
    decltype(auto) mul_element(const Type2& element) const noexcept;
    Vector<Type>& mul_equal_element(const Type& element) const noexcept;

    // ^ - поэлементное
    template <typename Type2>
    decltype(auto) operator^(const Vector<Type2>& v) const;
    Vector<Type>& operator^=(const Vector<Type>& v);
    template <typename Type2>
    decltype(auto) mul(const Vector<Type2>& v) const;
    Vector<Type>& mul_equal(const Vector<Type>& v) const;

    // | - векторное
    template <typename Type2>
    decltype(auto) operator|(const Vector<Type2>& v) const;
    Vector<Type>& operator|=(const Vector<Type>& v);
    template <typename Type2>
    decltype(auto) cross_product(const Vector<Type2>& v) const;
    Vector<Type>& cross_product_equal(const Vector<Type>& v) const;

    template <typename Type2>
    decltype(auto) operator/(const Vector<Type2>& v) const;
    Vector<Type>& operator/=(const Vector<Type>& v);
    template <typename Type2>
    decltype(auto) div(const Vector<Type2>& v) const;
    Vector<Type>& div_equal(const Vector<Type>& v) const;

    template <typename Type2>
    decltype(auto) operator/(const Type2& element) const;
    Vector<Type>& operator/=(const Type& element);
    template <typename Type2>
    decltype(auto) div_element(const Type2& element) const;
    Vector<Type>& div_equal_element(const Type& element) const;

    bool operator==(const Vector<Type>& v) noexcept;
    bool operator!=(const Vector<Type>& v) noexcept;
    bool equals(const Vector<Type>& v) noexcept;

    Vector<Type> operator-() const noexcept;
    Vector<Type> negative() const noexcept;

    Type& operator[](size_t index);
    const Type& operator[](size_t index) const;
    const Type& get_element(size_t index) const;
    void set_element(size_t index, const Type& element);

    double lenght() const noexcept;
    bool is_unit() const noexcept;
    double angle(Vector<Type>& v) const;
    bool is_orthogonality(const Vector<Type>& v) const;
    bool is_collinearity(Vector<Type>& v) const;
    Vector<Type> get_single() const;

    RegularVectorIterator<Type> begin();
    RegularVectorIterator<Type> end();
    ConstVectorIterator<Type> begin() const;
    ConstVectorIterator<Type> end() const;
    ConstVectorIterator<Type> cbegin() const;
    ConstVectorIterator<Type> cend() const;

    template <typename Type2>
    friend std::ostream& operator<<(std::ostream& stream, const Vector<Type2>& v);
    template <typename Type2>
    friend std::istream& operator>>(std::istream& stream, Vector<Type2>& v);

private:
    std::shared_ptr<Type[]> data;
    std::shared_ptr<Type[]> allocate_memory(size_t count);
    void check_size(size_t count) const;
    void check_index(size_t index, size_t limit) const;
};

#endif 
