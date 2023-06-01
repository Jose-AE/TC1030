#ifndef USER_H
#define USER_H

#include <string>

class User {
  public:
   User(const std::string& username, const std::string& password);

   std::string getUsername() const;
   void setUsername(const std::string& username);

   std::string getPassword() const;
   void setPassword(const std::string& password);

   void displayUserDetails() const;

  private:
   std::string username;
   std::string password;
};

#endif  // USER_H
