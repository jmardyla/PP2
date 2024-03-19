#include <iostream>
#include <fstream>
#include "objectlist.h"
#include "complexobject.h"
#include "intObject.h"
#include "stringObject.h"
#include "doubleObject.h"

/// @todo Uzupelnij swoje dane:
constexpr const char* const FIRSTNAME = "Jan";
constexpr const char* const SURNAME   = "Mardyla";
constexpr const char* const MAIL    = "mardyla@student.agh.edu.pl";
constexpr const char* const BOOK_ID = "417234";
constexpr const char* const TEACHER_MAIL = "bazior[at]agh.edu.pl"; // change if not correct

void validateStudentsInfo();


int main()
{
    validateStudentsInfo();
    ObjectList list;

//    std::fstream file;
//    file.open(R"(C:\Users\janek\CLionProjects\pp-2-lab8i9-uniqueobjectlist-inside-parser-1\zaj8i9UniqueObjectList_and_parser\systemTests\inputOutputData\getByIndexComplexObject.in.txt)");
//    if (file.is_open()) {
    std::string line;
    while (std::getline(std::cin, line)) {
        //std::cout << line << std::endl;
        std::string command =  line.substr(0, line.find(' '));
        if (command == "add") {
            std::string objectAndValue = line.substr(line.find(' ')+1);
            std::string object = objectAndValue.substr(0, objectAndValue.find(':'));
            std::string value = objectAndValue.substr(objectAndValue.find(':')+1);
            //std:: cout << command << ' ' << object << ' ' <<  value << std::endl;
            if (object == "ComplexObject") {
                list.push_front(new ComplexObject(value));
            }
            else if (object == "IntObject") {
                list.push_front(new IntObject(std::stoi(value)));
            }
            else if (object == "StringObject") {
                list.push_front(new StringObject(value));
            }
            else if (object == "DoubleObject") {
                list.push_front(new DoubleObject(std::stod(value)));
            }
        }
        else if (command == "get") {
            int index = std::stoi(line.substr(line.find(' ')+1));
            if (index==0) {
                std::cout << list.front().getType() + '(' << &(list.front()) << ')' << std::endl;
            }
        }
        else if (command == "mul") {
            int x = std::stoi(line.substr(line.find(' ')+1));
            list.mul(x);
        }
        else if (command == "sum") {
            try {
                std::string type = line.substr(line.find(' ') + 1);
                std::string sum = list.sum(type);
                std::cout << type + '(' << sum << ')' << std::endl;
            }
            catch (std::domain_error& e) {}
        }
        else {
            std::cerr << "invalid command" << std::endl;
        }
    }

        //file.close();
//    } else {
//        std::cout << "Failed to open the file." << std::endl;
//    }
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
