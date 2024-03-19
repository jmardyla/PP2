#include <iostream>
#include <array>
#include "containerWrapper.h"
using namespace std;

/**
  @mainpage Laboratorium 5

  Tresc zadan dla w pliku `README.md`

  Ponizszy plik jest do testow manualnych (jak ktos jeszcze nie jest obeznany z testami jednostkowymi)

  Tresc do implementacji - szukaj w plikach *.h
**/

/// @todo Uzupelnij swoje dane:
constexpr const char* const FIRSTNAME = "Jan";
constexpr const char* const SURNAME   = "Mardyla";
constexpr const char* const MAIL    = "mardyla@sdfa.sadf";
constexpr const char* const BOOK_ID = "25223";
constexpr const char* const TEACHER_MAIL = "bazior[at]agh.edu.pl"; // change if not correct

void validateStudentsInfo();

int main()
{
    std::array<int64_t, 10> tablica = {23, 43, 753, 123412, 1, 0, 98, 15, 60, 98213};
    ContainerWrapper kontener(tablica.begin() , 10);
    for(int i=0; i<10; i++){
        cout<< i << " " << kontener.at(i) << endl;
    }
}


constexpr inline size_t compileTimeStrlen(const char* text) noexcept
{
    return (*text ? 1+compileTimeStrlen(text+1) : 0);
}

constexpr inline size_t compileTimeCountFirstDigits(const char* text) noexcept
{
    return (*text && ('0'<=*text && *text<='9') ? 1+compileTimeCountFirstDigits(text+1) : 0);
}

constexpr inline bool compileTimeIsDigit(const char* text) noexcept
{
    return compileTimeStrlen(text) == compileTimeCountFirstDigits(text);
}

constexpr inline bool compileTimeContains(const char* text, char letter) noexcept
{
    if ('\n' == *text)
        return false;

    return *text == letter ? 1 : compileTimeContains(text+1, letter);
}

void validateStudentsInfo()
{
    static_assert(compileTimeStrlen(FIRSTNAME) > 2, "You must input your first name!");
    static_assert(compileTimeStrlen(SURNAME) > 2, "You must input your surname!");

    static_assert(compileTimeStrlen(BOOK_ID) > 1, "You must input your student book id!");
    static_assert(compileTimeIsDigit(BOOK_ID), "You student book id should consist only digits, shouldn't it?!");

    static_assert(compileTimeStrlen(MAIL) > 3, "You must input your mail (preferred AGH mail)!");
    static_assert(compileTimeContains(MAIL, '@'), "Invalid mail! It should contain '@'!");
    static_assert(compileTimeContains(MAIL, '.'), "Invalid mail! It should contain '.'!");
}
