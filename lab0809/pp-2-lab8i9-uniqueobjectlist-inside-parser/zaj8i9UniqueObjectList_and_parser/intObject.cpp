//
// Created by janek on 20.05.2023.
//

#include "intObject.h"

IntObject::IntObject(int number): number_(number) {
}

bool IntObject::operator==(const Object &obj) const {
    try {
        IntObject that = dynamic_cast<const IntObject &>(obj);
        return this->number_ == that.number_;
    }
    catch (std::bad_cast& e) {
        return false;
    }
}

std::string IntObject::getType() {
    return "IntObject";
}