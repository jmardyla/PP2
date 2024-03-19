#pragma once

#include <cinttypes>  // std::size_t
#include <memory>  // std::unique_ptr (dla chętnych)
#include <set>
#include "complexobject.h"
#include "intObject.h"
#include "stringObject.h"
#include "doubleObject.h"


//#define UNIMPLEMENTED_OBJECT_LIST_CONSTRUCTOR_SIZE_EMPTY_METHODS
//#define UNIMPLEMENTED_PUSH_FRONT
//#define UNIMPLEMENTED_POP_FRONT
//#define UNIMPLEMENTED_FRONT
//#define UNIMPLEMENTED_CLEAR
//#define UNIMPLEMENTED_REVERSE // rozmowa kwalifikacyjna
//#define UNIMPLEMENTED_ITERATOR_METHODS_AT_LEAST_EMPTY
//#define UNIMPLEMENTED_ITERATORS
//#define UNIMPLEMENTED_ERASE_AFTER
//#define UNIMPLEMENTED_ERASE


class Object;
enum class ObjectType {
    COMPLEX,
    INT,
    STRING,
    DOUBLE
};

class ObjectList
{
protected:
    struct Node;
    Node *head;
    size_t size_;



public:
    using value_type = Object;

    ObjectList();
    ObjectList(const ObjectList&);
    ObjectList(ObjectList&&);
    ~ObjectList();

    bool empty() const;
    size_t size() const;

    void clear();

    void reverse() noexcept;

    value_type& front();


    struct iterator {
    private:
        Node* m_ptr;
    public:
        explicit iterator(Node*);
        Object& operator*();
        Node* operator->() {return m_ptr;};
        iterator& operator++();
        const iterator operator++(int);

        bool operator==(const iterator &rhs) const;

        bool operator!=(const iterator &rhs) const;
    };
    iterator begin();
    iterator end();
    /**
     * @brief push_front
     * @param newObject
     * Wpierw sprawdzamy czy obiekt już jest w liście
     */
    void push_front(value_type* newObject);

    void pop_front();
    ObjectList& operator=(const ObjectList&);
    ObjectList& operator=(ObjectList&&);
    void erase_after(iterator position);

    /// tego std::forward_list nie ma
    void erase(iterator position);

    void mul(int x);
    std::string sum(std::string) noexcept(false);

    /// dla chętnych, tego testy nie sprawdzają:
    ObjectList reverse_copy() const;

    /// dla chętnych, tego testy nie sprawdzają:
    void sort() noexcept;

protected:
    // TODO:
};
