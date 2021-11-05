#pragma once

#include "pimpl.h"

class Foo
{
  class impl;
  pimpl<impl> impl;
public:
  void say_hello()
  {
    impl->say_hello();
  }
};
