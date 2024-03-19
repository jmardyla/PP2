#include <functional>
#include <algorithm>
#include <string>
#include <cstring>
#include <stdexcept>
#include <utility> // std::exchange
#include "PtrCStringVector.h"
using namespace std;


PtrCStringVector::PtrCStringVector(): size_(0), capacity_(0), data_(nullptr)
{
    /// @todo zaimplementuj, szczegoly w pliku naglowkowym

}

PtrCStringVector::PtrCStringVector(const PtrCStringVector &srcPtrCStringVector): PtrCStringVector() {
    /// @todo zaimplementuj, szczegoly w pliku naglowkowym
    char **memoryForData = new char *[srcPtrCStringVector.capacity_];
    data_ = memoryForData;
    size_ = 0;
    capacity_ = srcPtrCStringVector.capacity_;
    for (int i = 0; i < srcPtrCStringVector.size_; i++) {
        char *textInNewVector = new char[strlen(srcPtrCStringVector[i]) + 1];
        std::strncpy(textInNewVector, srcPtrCStringVector[i], strlen(srcPtrCStringVector[i]) + 1);
        *(data_ + i) = textInNewVector;
        size_++;
    }
}

PtrCStringVector::~PtrCStringVector()
{
    /// @todo zaimplementuj, szczegoly w pliku naglowkowym
    this->free();

}

PtrCStringVector &PtrCStringVector::operator=(const PtrCStringVector &source)
{
    /// @todo zaimplementuj, szczegoly w pliku naglowkowym
    this->free();
    char **memoryForData = new char *[source.capacity_];
    data_ = memoryForData;
    size_ = 0;
    capacity_ = source.capacity_;
    for (int i = 0; i < source.size_; i++) {
        char *textInNewVector = new char[strlen(source[i]) + 1];
        std::strncpy(textInNewVector, source[i], strlen(source[i]) + 1);
        *(data_ + i) = textInNewVector;
        size_++;
    }
    return *this;
}

PtrCStringVector& PtrCStringVector::operator=(PtrCStringVector&& source)
{
    /// @todo zaimplementuj, szczegoly w pliku naglowkowym
    this->free();
    data_=source.data_;
    capacity_ = source.capacity_;
    size_=source.size_;
    source.size_=0;
    source.capacity_=0;
    source.data_ = nullptr;
    return *this;
}

void PtrCStringVector::push_back(const char *text2Add)
{
    /// @todo zaimplementuj, szczegoly w pliku naglowkowym
    if (capacity_==0) {
        char **memoryForData = new char *[5 * sizeof(char*)];
        data_ = memoryForData;
        capacity_ = 5 * sizeof(char*);
    }
    else if (capacity_/sizeof(char*)-size_<1) {
        char **memoryForData = new char *[2 * size_];
        std::memmove(memoryForData, data_, size_ * sizeof(char *));
        delete[] data_;
        data_ = memoryForData;
        capacity_ = 2 * size_ * sizeof(char*);
    }
    char* copiedText = new char[strlen(text2Add)+1];
    std::strncpy(copiedText, text2Add, strlen(text2Add)+1);
    *(data_+size_) = copiedText;
    size_++;
}

PtrCStringVector PtrCStringVector::operator+(const PtrCStringVector &anotherVector) const
{
    /// @todo zaimplementuj, szczegoly w pliku naglowkowym
    PtrCStringVector resultVector(*this);
    for(int i=0; i<anotherVector.size_; i++){
        resultVector.push_back(anotherVector[i]);
    }
    return resultVector;
}

char *PtrCStringVector::operator[](size_t index)
{
    /// @todo zaimplementuj, szczegoly w pliku naglowkowym
    if (index<size_) {
        return *(data_ + index);
    }
    throw std::out_of_range("index bigger than size_");
}
const char *PtrCStringVector::operator[](size_t index) const
{
    /// @todo zaimplementuj, szczegoly w pliku naglowkowym
    return const_cast<const char*>(*(data_+index));
}

PtrCStringVector PtrCStringVector::operator&(const PtrCStringVector &rhs) const
{
    /// @todo zaimplementuj, szczegoly w pliku naglowkowym
    PtrCStringVector resultVector;
    size_t minOfSizes = std::min(size_, rhs.size_);
    for(int i=0; i < minOfSizes; i++) {
        char* resultString = new char[strlen((*this)[i]) + strlen(rhs[i]) + 1];
        std::strcpy(resultString, (*this)[i]);
        std::strcat(resultString, rhs[i]);
        resultVector.push_back(resultString);
        delete[] resultString;
    }
    if (size_>rhs.size_) {
        for(size_t i=minOfSizes; i<size_; i++) {
            resultVector.push_back((*this)[i]);
        }
    }
    else if (size_<rhs.size_) {
        for(size_t i=minOfSizes; i<rhs.size_; i++) {
            resultVector.push_back(rhs[i]);
        }
    }
    return resultVector;
}

void PtrCStringVector::free()
{
    /// @todo sugeruje zaimplementowac, szczegoly w pliku naglowkowym
    for(int i=0; i<size_; i++) {
        delete[] (*this)[i];
    }
    delete[] data_;
    data_ = nullptr;
    size_=0;
    capacity_=0;

}

void PtrCStringVector::reserve(size_t new_capacity)
{
    /// @todo sugeruje zaimplementowac, szczegoly w pliku naglowkowym
}
