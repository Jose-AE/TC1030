#include <iostream>
#include "Classes/user.h"

// pure virtual
class person {
  public:
   virtual int getNum() = 0;
};

class bob : public person {

   int getNum() override {}
};

class entity {
  public:
   virtual int getNum() {}
};

class enemy : public entity {
   int getNum() override {}
};

int main() {
   User user("JohnDoe", "pa$$w0rd");
   user.displayUserDetails();

   return 0;
}
