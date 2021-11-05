#pragma once

#include <memory>

template <typename T> class pimpl
{
  std::unique_ptr<T> impl;
public:
  pimpl();
  ~pimpl();

  T* operator->();
  T& operator*();

  // lets you pass init values to the impl
  template<typename ...Args> pimpl(Args&& ...args);
};

