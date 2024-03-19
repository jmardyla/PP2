#include <memory>
#include <stdexcept>
#include <utility>  // std::exchange()
#include "objectlist.h"
#include "object.h"
#include <complex>


struct ObjectList::Node
{
    // TODO
    value_type* value;
    Node* next;

    bool operator==(const Node &rhs) const {
        return *value == *rhs.value;
    }

    explicit Node(value_type* key): value(key), next(nullptr){};
    ~Node() = default;

};


ObjectList::ObjectList(): head(nullptr), size_(0) {
}

ObjectList::ObjectList(const ObjectList &other) {
    size_ = 0;
    if (other.head!= nullptr) {
        head = new Node(other.head->value);
        Node *newPtr = head;
        size_++;
        for (Node *ptr = other.head->next; ptr != nullptr; ptr = ptr->next) {
            Node *newNode = new Node(ptr->value);
            newPtr->next = newNode;
            newPtr = newNode;
            size_++;
        }
    }
    else {
        head = nullptr;
    }
}

ObjectList::ObjectList(ObjectList &&other) {
    size_ = 0;
    if (other.head!= nullptr) {
        head = new Node(other.head->value);
        Node *newPtr = head;
        size_++;
        Node *ptr = other.head->next;
        delete other.head;
        for (;ptr != nullptr;) {
            Node *newNode = new Node(ptr->value);
            newPtr->next = newNode;
            newPtr = newNode;
            size_++;
            Node* temp = ptr;
            ptr = ptr->next;
            delete temp;
        }
        other.head = nullptr;
        other.size_ = 0;
    }
    else {
        head = nullptr;
    }
//    head = other.head;
//    size_ = other.size_;
//    other.clear();
}

ObjectList::~ObjectList() {
    this->clear();
    delete head;
}

bool ObjectList::empty() const {
    if (size_>0) return false;
    return true;
}

size_t ObjectList::size() const {
    return size_;
}

void ObjectList::push_front(value_type *newObject) {
    for(Node* x = head; x!= nullptr; x=x->next) {
        if (*newObject == *x->value) {
            return;
        }
    }
    Node* newNode = new Node(newObject);
    newNode->next = head;
    head = newNode;
    size_++;
}

void ObjectList::pop_front() {
    Node* toDelete = head;
    head = head->next;
    delete toDelete;
    size_--;
}

ObjectList::value_type& ObjectList::front() {
    return *(head->value);
}

void ObjectList::clear() {
    for(Node* x = head, *y; x!= nullptr;) {
        y = x;
        x = x->next;
        delete y;
    }
    size_= 0;
    head = nullptr;
}

void ObjectList::reverse() noexcept {
    Node* oldHead = head;
    Node *curr = head, *prev= nullptr, *succ;
    while(curr != nullptr) {
        succ=curr->next;
        curr->next = prev;
        prev=curr;
        curr=succ;
    }
    oldHead->next = nullptr;
    head=prev;
}

ObjectList::iterator::iterator(Node* node): m_ptr(node) {
}

ObjectList::iterator ObjectList::begin() {
    return iterator(head);
}

ObjectList::iterator ObjectList::end() {
    return iterator(nullptr);
}

ObjectList::iterator& ObjectList::iterator::operator++() {
    m_ptr= m_ptr->next;
    return *this;
}

const ObjectList::iterator ObjectList::iterator::operator++(int) {
    auto tmp = this;
    m_ptr = m_ptr->next;
    return *tmp;
}

bool ObjectList::iterator::operator==(const ObjectList::iterator &rhs) const {
    return m_ptr == rhs.m_ptr;
}

bool ObjectList::iterator::operator!=(const ObjectList::iterator &rhs) const {
    return !(rhs == *this);
}

Object& ObjectList::iterator::operator*() {
    return *m_ptr->value;
}

ObjectList& ObjectList::operator=(const ObjectList &other) {
    if (this==&other) return *this;
    this->clear();
    size_ = 0;
    if (other.head!= nullptr) {
        head = new Node(other.head->value);
        Node *newPtr = head;
        size_++;
        for (Node *ptr = other.head->next; ptr != nullptr; ptr = ptr->next) {
            Node *newNode = new Node(ptr->value);
            newPtr->next = newNode;
            newPtr = newNode;
            size_++;
        }
    }
    else {
        head = nullptr;
    }
    return *this;
}

ObjectList& ObjectList::operator=(ObjectList &&other) {
    if (this==&other) return *this;
    this->clear();
    head = other.head;
    size_ = other.size_;
    other.head = nullptr;
    other.size_ = 0;
    return *this;
}

void ObjectList::erase_after(iterator position) {
    if (position->next == nullptr || position==this->end()) return;

    Node *temp = position->next;
    position.operator->()->next = position->next->next;
    delete temp;
    size_--;
}

void ObjectList::erase(iterator position) {
    if (position!=this->begin() && position!=this->end()) {
        auto it = this->begin();
        ++it;
        for (auto itPrevious = this->begin(); it != this->end(); ++it, ++itPrevious) {
            if (it==position) {
                erase_after(itPrevious);
                break;
            }
        }
    }
    else if (position==this->begin()) {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
}

void ObjectList::mul(int x) {
    for(auto & it : *this) {
        it.mul(x);
    }
}

std::string ObjectList::sum(std::string type) {
    ObjectType objectType;
    int counter = 0;
    std::complex<double> sumComplex(0, 0);
    std::string sumString = "";
    int sumInt = 0;
    double sumDouble = 0;
    if (type == "ComplexObject") {
        objectType = ObjectType::COMPLEX;
    } else if (type == "StringObject") {
        objectType = ObjectType::STRING;
    } else if (type == "IntObject") {
        objectType = ObjectType::INT;
    } else if (type == "DoubleObject") {
        objectType = ObjectType::DOUBLE;
    }
    for (auto it= this->begin(); it!=this->end(); ++it) {
        if (it->value->getType() != type) continue;
        counter++;
        switch (objectType) {
            case ObjectType::COMPLEX: {
                auto *object = dynamic_cast<ComplexObject *>(it->value);
                sumComplex += object->number();
                break;
            }
            case ObjectType::INT: {
                auto *object = dynamic_cast<IntObject *>(it->value);
                sumInt += object->number();
                break;
            }
            case ObjectType::STRING: {
                auto *object = dynamic_cast<StringObject *>(it->value);
                sumString += object->text();
                break;
            }
            case ObjectType::DOUBLE: {
                auto *object = dynamic_cast<DoubleObject *>(it->value);
                sumDouble += object->number();
                break;
            }
        }
    }
    if (counter==0) throw std::domain_error("No instances of this object in the list");
    switch (objectType) {
        case ObjectType::COMPLEX: {
            return ComplexObject(sumComplex).numberInString();
        }
        case ObjectType::INT: {
            return std::to_string(sumInt);
        }
        case ObjectType::STRING: {
            return '\"' + sumString + '\"';
        }
        case ObjectType::DOUBLE: {
            return std::to_string(sumDouble);
        }
    }
}