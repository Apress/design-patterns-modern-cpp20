#include "pimpl.h"

template<typename T>
pimpl<T>::pimpl() : m{new T{}}
{
}

template<typename T>
template<typename... Args>
pimpl<T>::pimpl(Args &&... args)
  : m{ new T{std::forward<Args>(args)... }}
{
}

template<typename T>
pimpl<T>::~pimpl()
{
  // no need to delete here since
  // we are using a unique_ptr
}

template<typename T>
T *pimpl<T>::operator->()
{
  return m.get();
}

template<typename T>
T &pimpl<T>::operator*()
{
  return *m.get();
}