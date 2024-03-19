#include <iostream>
#include <random>
#include <typeinfo>
#include <type_traits>
#include <cstring>
#include <cctype>
#include "stringObject.h"
using namespace std;

// TODO:
StringObject::StringObject(std::string text): text_(text) {
}

StringObject::StringObject(const StringObject &objectToCopy) {
    text_ = objectToCopy.text_;
}

bool StringObject::operator==(const Object &obj) const {
    try {
        StringObject that = dynamic_cast<const StringObject &>(obj);
        return this->text_ == that.text_;
    }
    catch (std::bad_cast& e) {
        return false;
    }
}

string StringObject::text() {
    return this->text_;
}

