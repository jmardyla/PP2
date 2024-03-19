#pragma once

#include <iosfwd>
#include <string>
#include "object.h"


class StringObject : public Object
{
    std::string text_;

public:    
//     TODO:

    explicit StringObject(std::string text);
    StringObject(const StringObject &objectToCopy);
    ~StringObject() override = default;
    bool operator==(const Object &obj) const override;

    std::string text();
    Object* clone() const override
    {
       return new StringObject(*this);
    }

    void print(std::ostream &os) const override {
        os << text_;
    }

    std::string getType() override {
        return "StringObject";
    }

    void mul(int x) override {
        std::string temp = text_;
        for (int i=1; i<x; i++) {
            text_ += temp;
        }
    }
};
