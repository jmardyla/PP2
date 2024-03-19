//
// Created by janek on 20.05.2023.
//

#include "doubleObject.h"

bool DoubleObject::operator==(const Object &obj) const {
    try {
        DoubleObject that = dynamic_cast<const DoubleObject &>(obj);
        return this->number_ == that.number_;
    }
    catch (std::bad_cast& e) {
        return false;
    }
}
