#include <iostream>
using namespace std;

#include "user.h"
#include "windows.h"

#ifndef _MSC_FULL_VER // if not Visual Studio Compiler
    #warning "Funkcje sa do zaimplementowania. Instrukcja w pliku naglowkowym"
#else
    #pragma message ("Funkcje sa do zaimplementowania. Instrukcja w pliku naglowkowym")
#endif

string Windows::version() {
    return this->version_;
}

size_t Windows::activated_systems() {
    return activated_systems_;
}

int Windows::add_user(const string& user_name, const string& password) {
    User new_windows_user;
    new_windows_user.password_ = password;
    new_windows_user.user_name_ = user_name;
    users_.push_back(new_windows_user);
    return users_.size()-1;
}

User Windows::user(int user_id) {
    return users_[user_id];
}

string Windows::user_home_directory(int user_id) {
    string user_path = "C:\\Users\\" + users_[user_id].user_name_;
    return user_path;
}