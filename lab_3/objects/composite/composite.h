#ifndef COMPOSITE_H
#define COMPOSITE_H

#include <object.h>

class Composite : public Object {
public:
    Composite() = default;
    explicit Composite(std::shared_ptr<Object>& component);
    explicit Composite(const std::vector<std::shared_ptr<Object>>& vector);

    size_t size() const;

    bool add(const std::shared_ptr<Object>& obj) override;
    bool remove(const Iterator& iterator) override;

    Iterator begin() override;
    Iterator end() override;

    bool is_visible() override;
    bool is_composite() const override;
    void transform(const Vertice& move, const Vertice& scale, const Vertice& rotate) override;
    void accept(std::shared_ptr<Visitor> visitor) override;

    Vertice get_center() const override;

private:
    std::vector<std::shared_ptr<Object>> _objects;
};

#endif // COMPOSITE_H
