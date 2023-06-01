#include "user.h"
#include <iostream>

User::User(const std::string& username, const std::string& password)
    : username(username), password(password) {}

std::string User::getUsername() const { return username; }

void User::setUsername(const std::string& username) {
   this->username = username;
}

std::string User::getPassword() const { return password; }

void User::setPassword(const std::string& password) {
   this->password = password;
}

void User::displayUserDetails() const {
   std::cout << "Username: " << username << std::endl;
   std::cout << "Password: " << password << std::endl;
}
