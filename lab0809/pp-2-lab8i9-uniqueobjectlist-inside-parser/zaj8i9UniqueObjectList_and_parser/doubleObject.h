//
// Created by janek on 20.05.2023.
//
#include "iostream"
#ifndef ZAD8COMMANDSPARSER_DLASTUDENTOW_DOUBLEOBJECT_H
#define ZAD8COMMANDSPARSER_DLASTUDENTOW_DOUBLEOBJECT_H

#include "object.h"
class DoubleObject : public Object {
    double number_;
public:
    explicit DoubleObject(double number): number_(number) {};
    ~DoubleObject() override = default;
    DoubleObject(const DoubleObject& that): number_(that.number_) {};
    bool operator==(const Object &obj) const override;

    double number() const {return number_;};
    Object* clone() const override
    {
        return new DoubleObject(*this);
    }

    void print(std::ostream &os) const override {
        os << number_;
    }

    std::string getType() override {
        return "DoubleObject";
    }

    void mul(int x) override {
        number_ *= x;
    }
};


#endif //ZAD8COMMANDSPARSER_DLASTUDENTOW_DOUBLEOBJECT_H
