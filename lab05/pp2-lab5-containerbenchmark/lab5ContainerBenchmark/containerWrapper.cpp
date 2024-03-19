#include <iostream>
#include <algorithm> // std::sort, std::find, std::copy
#include <iterator> // std::distance, std::advance, std::back_inserter
#include <limits>   // std::numeric_limits<size_t>::max()
#include <numeric>  // std::accumulate()

using namespace std;

#include "containerWrapper.h"

#ifndef _MSC_FULL_VER // if not Visual Studio Compiler
    #warning "Klasa jest do zaimplementowania. Instrukcja w pliku naglowkowym"
#else
    #pragma message ("Klasa jest do zaimplementowania. Instrukcja w pliku naglowkowym")
#endif

IContainerWrapper::~IContainerWrapper() = default;

DequeWrapper::DequeWrapper(const value_type* array, std::size_t size): impl_(array, array+size) {}

void DequeWrapper::push_back(const value_type &element) {
    impl_.push_back(element);
}

void DequeWrapper::push_front(const value_type &element) {
    impl_.push_front(element);
}

void DequeWrapper::insert(const value_type &element, std::size_t pos) {
    impl_.insert(impl_.cbegin()+pos, element);
}

DequeWrapper::value_type &DequeWrapper::at(std::size_t pos) {
    return impl_.at(pos);
}

void DequeWrapper::sort() {
    std::sort(impl_.begin(), impl_.end());
}

void DequeWrapper::erase(std::size_t position) {
    impl_.erase(impl_.begin()+position);
}

DequeWrapper::value_type DequeWrapper::pop_back() {
    value_type lastElement = impl_.back();
    impl_.pop_back();
    return lastElement;
}

DequeWrapper::value_type DequeWrapper::pop_front() {
    value_type firstElement = impl_.front();
    impl_.pop_front();
    return firstElement;
}

std::size_t DequeWrapper::find(const value_type &key) const {
    auto it = std::find(impl_.begin(), impl_.end(), key);
    if (it != impl_.end()) return std::distance(impl_.begin(), it);
    return std::numeric_limits<size_t>::max();
}

DequeWrapper::value_type DequeWrapper::count() const {
    value_type sum = 0;
    for(value_type element : impl_) {
        sum += element;
    }
    return sum;
}