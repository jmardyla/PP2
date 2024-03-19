#pragma once

#include <iosfwd>
#include <string>


class Object
{
public:
//     TODO:
    virtual bool operator==(const Object& obj) const = 0;
    virtual void print(std::ostream&) const  = 0;
    virtual Object* clone() const = 0;
    virtual ~Object() = default;
    friend std::ostream& operator<<(std::ostream& os, const Object* object) {
        object->print(os);
        return os;
    }
    virtual std::string getType() = 0;
    virtual void mul(int x) = 0;
};
