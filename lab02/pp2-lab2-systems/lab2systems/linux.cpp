#include <iostream>
using namespace std;

#include "user.h"
#include "linux.h"

#ifndef _MSC_FULL_VER // if not Visual Studio Compiler
    #warning "Funkcje sa do zaimplementowania. Instrukcja w pliku naglowkowym"
#else
    #pragma message ("Funkcje sa do zaimplementowania. Instrukcja w pliku naglowkowym")
#endif



string Linux::distribution() {
    return distribution_;
}

size_t Linux::open_source_sympathizers() {
    return open_source_sympathizers_;
}

int Linux::add_user(const string& user_name, const string& password) {
    User new_linux_user;
    new_linux_user.password_ = password;
    new_linux_user.user_name_ = user_name;
    users_.push_back(new_linux_user);
    return users_.size()-1;
}

User Linux::user(int user_id) {
    return users_[user_id];
}

string Linux::user_home_directory(int user_id) {
    string user_path = "/home/" + users_[user_id].user_name_ + "/";
    return user_path;
}

optional<string> Linux::graphic_environment() const {
    return this->graphic_environment_;
}

void Linux::set_graphic_environment(optional<string> graph_env) {
    this->graphic_environment_ = graph_env;
}

