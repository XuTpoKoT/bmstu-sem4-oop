#ifndef OBJECT_H
#define OBJECT_H

#include <memory>
#include <vector>
#include <vertice.h>
#include <visitor.h>

class Object;

using Iterator = std::vector<std::shared_ptr<Object>>::iterator;

class Object {
public:
    Object() { _id = _next_id++; }
    virtual ~Object() = default;

    virtual bool add(const std::shared_ptr<Object>&) { return false; };
    virtual bool remove(const Iterator&) { return false; };

    virtual Iterator begin() { return Iterator(); };
    virtual Iterator end() { return Iterator(); };

    virtual bool is_visible() { return false; }
    virtual bool is_composite() const { return false; };

    virtual void accept(std::shared_ptr<Visitor> visitor) = 0;

    virtual Vertice get_center() const = 0;

    virtual void transform(const Vertice& move, const Vertice& scale, const Vertice& turn) = 0;

    virtual size_t get_id() { return _id; }

protected:
    size_t _id;
    inline static size_t _next_id;
};

class VisibleObject : public Object {
public:
    VisibleObject() = default;
    ~VisibleObject() override = default;

    bool is_visible() override { return true; }
};

class InvisibleObject : public Object {
public:
    InvisibleObject() = default;
    ~InvisibleObject() override = default;

    bool is_visible() override { return false; }
};

#endif // OBJECT_H
