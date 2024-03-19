#include <stdexcept> // std::out_of_range
#include <utility>   // std::exchange
#include <array>
#include <limits>
#include <algorithm>
#include <string>
#include <cstring>
#include "SortedUniqueVectoredList.h"
using namespace std;


/** class SortedUniqueVectoredList::Bucket
 * @param size ilosc elementow w kubelku, tworzac pusty ma byc 0
 * @param values elementy kubelka, jako tablica statyczna
 * @param BUCKET_SIZE ilosc elementow w statycznej tablicy
 * @param bucketCount_ ilosc kubelkow
 * @param next wskaznik na nastepny @ref Bucket, a jesli takiego nie ma na nullptr
 * @param previous wskaznik na poprzedni @ref Bucket, a jesli takiego nie ma na nullptr
 * @note jest to klasa zrobiona przy pomocy [idiomu PIMPL](https://en.cppreference.com/w/cpp/language/pimpl),
 *       ktory polega na tym, ze w klasie zewnetrznej jest jedynie deklaracja klasy wewnetrznej, ktora jest zaimplementowana w pliku zrodlowym **/
struct SortedUniqueVectoredList::Bucket
{
    constexpr static size_t BUCKET_SIZE = 10;

    std::array<std::string, BUCKET_SIZE> values;
    size_t size{};

    Bucket* next = nullptr;
    Bucket* previous = nullptr;

    Bucket(): size(0){};
    Bucket(const Bucket& bucket): size(bucket.size), values(bucket.values) {
    };
    ~Bucket() {
        size = 0;
    }
};

SortedUniqueVectoredList::SortedUniqueVectoredList():tail(nullptr), head(nullptr), size_(0), capacity_(0), bucketCount_(0) {};


SortedUniqueVectoredList::SortedUniqueVectoredList(const SortedUniqueVectoredList &source)
{
    /// @todo zaimplementuj, szczegoly w pliku naglowkowym
    copy(source);
}

SortedUniqueVectoredList::SortedUniqueVectoredList(SortedUniqueVectoredList &&another)
{
    /// @todo zaimplementuj, szczegoly w pliku naglowkowym
    this->move(std::move(another));
}

SortedUniqueVectoredList::~SortedUniqueVectoredList()
{
    /// @todo zaimplementuj, szczegoly w pliku naglowkowym
    free();
}

SortedUniqueVectoredList &SortedUniqueVectoredList::operator=(SortedUniqueVectoredList &&another)
{
    /// @todo zaimplementuj, szczegoly w pliku naglowkowym
    if (this != &another)
    {
        this->move(std::move(another));
    }
    return *this;
}

void SortedUniqueVectoredList::insert(const string &value)
{
    /// @todo zaimplementuj, szczegoly w pliku naglowkowym
    if (this->contains(value)) {
        return;
    }

    if (capacity_ - size_ == 0 && head != nullptr) {
        auto *newBucket = new Bucket();
        newBucket->next = nullptr;
        newBucket->previous = tail;
        tail->next = newBucket;
        tail = newBucket;
        capacity_ += Bucket::BUCKET_SIZE;
        bucketCount_++;
    } else if (capacity_ - size_ == 0) {
        auto *newBucket = new Bucket();
        newBucket->previous = nullptr;
        newBucket->next = nullptr;
        head = newBucket;
        tail = newBucket;
        capacity_ += Bucket::BUCKET_SIZE;
        bucketCount_++;
    }
    tail->values[tail->size++] = value;
    size_++;

    sort();

}

void SortedUniqueVectoredList::sort() {
//    for j in range(1, len(tab_to_sort)):
//      key = tab_to_sort[j]
//      i = j-1
//      while (i>-1 and tab_to_sort[i]>key):
//          tab_to_sort[i+1] = tab_to_sort[i]
//          i -= 1
//      tab_to_sort[i+1] = key

    for(int i=1, j; i<size_; i++) {
        auto key = (*this)[i];
        j = i-1;
        while (j>-1 && (*this)[j]>key) {
            (*this)[j+1] = ((*this)[j]);
            j--;
        }
        (*this)[j+1] = key;
    }

}

void SortedUniqueVectoredList::erase(const string &value)
{
    /// @todo zaimplementuj, szczegoly w pliku naglowkowym (opcjonalne zadanie)

}

SortedUniqueVectoredList::operator std::string() const
{
    /// @todo zaimplementuj, szczegoly w pliku naglowkowym
    string sum = "";
    for(size_t i=0; i<size_; i++) {
        sum += (*this)[i];
    }
    return sum;
}

void SortedUniqueVectoredList::allocate_new_bucket()
{
    /// @todo zaimplementuj, szczegoly w pliku naglowkowym

    capacity_ += Bucket::BUCKET_SIZE;
    bucketCount_++;
}

void SortedUniqueVectoredList::free()
{
    /// @todo zaimplementuj, szczegoly w pliku naglowkowym
    Bucket *temp;
    for(auto bucket=head; bucket!= nullptr;) {
        temp = bucket;
        bucket=bucket->next;
        delete temp;
    }
}

void SortedUniqueVectoredList::move(SortedUniqueVectoredList &&other)
{
    /// @todo zaimplementuj, szczegoly w pliku naglowkowym
    free();
    head = other.head;
    tail = other.tail;
    this->size_ = other.size_;
    this->capacity_ = other.capacity_;
    other.size_ = 0;
    other.capacity_ = 0;
    other.head = nullptr;
    other.tail = nullptr;
}

void SortedUniqueVectoredList::copy(const SortedUniqueVectoredList &other)
{
    /// @todo zaimplementuj, szczegoly w pliku naglowkowym
    auto x = head;
    for(auto bucket=other.head; bucket!=nullptr; bucket=bucket->next) {
        if (x != nullptr) {
            this->size_ -= x->size;
            std::copy(bucket->values.begin(), bucket->values.end(), x->values.begin());
            x = x->next;
            this->size_ += bucket->size;
        }
        else if (head!= nullptr) {
            auto* newBucket = new Bucket(*bucket);
            newBucket->next = nullptr;
            newBucket->previous = tail;
            tail->next = newBucket;
            tail = newBucket;
            capacity_ += Bucket::BUCKET_SIZE;
            bucketCount_++;
            x = nullptr;
            size_ += bucket->size;
        }
        else {
            auto* newBucket = new Bucket(*bucket);
            newBucket->next = nullptr;
            newBucket->previous = tail;
            head = newBucket;
            tail = newBucket;
            capacity_ += Bucket::BUCKET_SIZE;
            bucketCount_++;
            x = nullptr;
            size_ += bucket->size;

        }
    }
}

bool SortedUniqueVectoredList::contains(const string &value) const
{
    /// @todo zaimplementuj, szczegoly w pliku naglowkowym
    for(auto bucket=this->head; bucket!= nullptr; bucket=bucket->next) {
        for(const auto& str : bucket->values) {
            if (str==value) {
                return true;
            }
        }
    }
    return false;
}

SortedUniqueVectoredList SortedUniqueVectoredList::operator-(const SortedUniqueVectoredList &another) const
{
    SortedUniqueVectoredList ret;
    /// @todo zaimplementuj, szczegoly w pliku naglowkowym
    bool isRepeated = false;
    for(size_t i=0; i<size_; i++) {
        isRepeated = false;
        for(size_t j=0; j<another.size_; j++){
            if (another.contains((*this)[i])) {
                isRepeated = true;
            }
        }
        if (!isRepeated) ret.insert((*this)[i]);
    }
    return ret;
}

SortedUniqueVectoredList &SortedUniqueVectoredList::operator*=(const size_t howManyTimesMultiply)
{
    /// @todo zaimplementuj, szczegoly w pliku naglowkowym
    if (howManyTimesMultiply == 1) {
        return *this;
    }
    if (howManyTimesMultiply == 0) {
        for(size_t i=0; i<size_; i++) {
            (*this)[i] = "";
        }
    }
    else {
        for (size_t i = 0; i < size_; i++) {
            auto temp = (*this)[i];
            for (size_t j = 1; j < howManyTimesMultiply; j++) {
                (*this)[i] += temp;
            }
        }
    }
    return *this;
}

string &SortedUniqueVectoredList::operator[](size_t index)
{
    /// @todo zaimplementuj, szczegoly w pliku naglowkowym
    if (index>=size_) throw std::out_of_range("out of range with index " + to_string(index) + ", size_ is equal to " + to_string(size_));
    size_t bucketNumber = index/10;
    size_t indexInBucket = index%10;
    size_t bucketCounter{};
    auto bucket=this->head;
    for( ;bucketCounter<bucketNumber; bucket=bucket->next, bucketCounter++) {}
    return bucket->values.at(indexInBucket);


}

const string& SortedUniqueVectoredList::operator[](size_t index) const
{
    /// @todo zaimplementuj, szczegoly w pliku naglowkowym
    if (index>=size_) throw std::out_of_range("out of range");
    size_t bucketNumber = index/10;
    size_t indexInBucket = index%10;
    size_t bucketCounter{};
    auto bucket=this->head;
    for( ;bucketCounter<bucketNumber; bucket=bucket->next, bucketCounter++) {}
    return const_cast<const string&>(bucket->values.at(indexInBucket));
}

SortedUniqueVectoredList &SortedUniqueVectoredList::operator=(const SortedUniqueVectoredList &another)
{
    /// @todo zaimplementuj, szczegoly w pliku naglowkowym
    copy(another);
    return *this;
}
