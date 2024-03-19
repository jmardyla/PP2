//
// Created by janek on 20.05.2023.
//
#include "object.h"
#include "iostream"
#ifndef ZAD8COMMANDSPARSER_DLASTUDENTOW_INTOBJECT_H
#define ZAD8COMMANDSPARSER_DLASTUDENTOW_INTOBJECT_H


class IntObject : public Object {
    int number_;

public:

    void print(std::ostream& os) const override {
        os << number_;
    }
    explicit IntObject(int number);
    ~IntObject() override = default;
    IntObject(const IntObject& that): number_(that.number_) {};

    bool operator==(const Object &obj) const override;
    int number() const {return number_;};

    Object* clone() const override
    {
        return new IntObject(*this);
    }
    std::string getType() override;

    void mul(int x) override {
        number_ *= x;
    }
};


#endif //ZAD8COMMANDSPARSER_DLASTUDENTOW_INTOBJECT_H
