#include "Foo.h"

#include <iostream>

class Foo::impl
{
public:
  void say_hello()
  {
    std::cout << "hello";
  }
};
