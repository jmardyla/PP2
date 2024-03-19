#include <iostream>
#include <algorithm>
#include <cstring>
#include <utility> // std::exchange
using namespace std;

#include "simpleString.h"

#ifndef _MSC_FULL_VER // if not Visual Studio Compiler
    #warning "Klasa jest do zaimplementowania. Instrukcja w pliku naglowkowym"
#else
    #pragma message ("Klasa jest do zaimplementowania. Instrukcja w pliku naglowkowym")
#endif

SimpleString::SimpleString(): data_(new char[1]{}), size_(0), capacity_(0) {
    instances_++;
}

SimpleString::SimpleString(const char* text): size_(strlen(text)), capacity_(strlen(text)+1){
    data_ = new char[capacity_];
    std::strncpy(data_, text, capacity_);
    instances_++;
}

SimpleString::SimpleString(const SimpleString &text): size_(text.size_), capacity_(text.capacity_) {
    data_ = new char[capacity_];
    std::strncpy(data_, text.data_, size_+1);
    instances_++;
}

SimpleString::SimpleString(SimpleString &&simpleStringToBeMoved): data_(simpleStringToBeMoved.data_), size_(simpleStringToBeMoved.size_), capacity_(simpleStringToBeMoved.capacity_) {
    simpleStringToBeMoved.data_ = new char[1]();
    simpleStringToBeMoved.size_ = 0;
    simpleStringToBeMoved.capacity_ = 0;
}

SimpleString::~SimpleString() {
    delete[] data_;
    instances_--;
}

void SimpleString::assign(const char *new_text) {
    delete[] data_;
    this->size_ = ::strlen(new_text);
    this->capacity_ = this->size_+1;
    data_ = new char[capacity_];
    std::strncpy(data_, new_text, capacity_);
}

bool SimpleString::equal_to(const SimpleString &secondSimpleString, bool case_sensitive) const {
    int longerSize = max(strlen(this->data_), strlen(secondSimpleString.data_));
    int shorterSize = min(strlen(this->data_), strlen(secondSimpleString.data_));
    if (case_sensitive) {
        int result = strncmp(this->data_, secondSimpleString.data_, longerSize);
        if (result == 0) {
            return true;
        } else return false;
    }
    else {
        int i=0;
        while(tolower(*((this->data_)+i)) == tolower(*(secondSimpleString.data_+i)) && i<shorterSize) {
            i++;
        }
        if (i==this->size_ && this->size_==secondSimpleString.size_) {
            return true;
        }
        else return false;

    }
}

void SimpleString::append(const SimpleString &secondSimpleString) {
    this->capacity_ = this->size_ + secondSimpleString.size_ + 1;
    char* textsMerged = new char[this->capacity_];
    std::strncpy(textsMerged, this->data_, this->size_);
    std::strncpy(textsMerged+ this->size_, secondSimpleString.data_, secondSimpleString.size_+1);
    delete[] this->data_;
    textsMerged[this->capacity_-1] = 0;
    this->data_ = textsMerged;
    this->size_ = strlen(this->data_);

}

SimpleString SimpleString::substr(std::size_t pos, std::size_t count) const {
    char* substring;
    if (count <= (this->size_ - pos)) {
        substring = new char[count+1];
        std::strncpy(substring, this->data_ + pos, count);
        substring[count] = 0;
    } else {
        substring = new char[(this->size_ - pos)+1];
        std::strncpy(substring, this->data_ + pos, (this->size_ - pos));
        substring[(this->size_ - pos)] = 0;
    }
    SimpleString newSimpleString(substring);
    delete[] substring;
    return newSimpleString;
}

int SimpleString::compare(const SimpleString &secondSimpleString, bool case_sensitive) const {
    if (case_sensitive) {
        return std::strcmp(this->data_, secondSimpleString.data_);
    }
    else {
        int comparedValue;
        int shorterSize = min(this->size_, secondSimpleString.size_);
        for(int i=0; i<shorterSize; i++){
            comparedValue = std::tolower(*(this->data_+i)) - std::tolower(*(secondSimpleString.data_+i));
            if (comparedValue != 0) {
                if (comparedValue > 0) return 1;
                else return -1;
            }
        }
        if (secondSimpleString.size_ == this->size_) {
            return 0;
        }
        else if (this->size_ > secondSimpleString.size_) {
            return 1;
        }
        else return -1;
    }
}