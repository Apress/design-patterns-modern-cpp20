#include <iostream>
#include <thread>
using namespace std;

class PerThreadSingleton
{
  PerThreadSingleton()
  {
    id = this_thread::get_id();
  }
public:
  thread::id id;
  static PerThreadSingleton& get()
  {
    thread_local PerThreadSingleton instance;
    return instance;
  }
};

int main()
{
  thread t1([]()
  {
    cout << "t1: " << PerThreadSingleton::get().id << "\n";
  });

  thread t2([]()
  {
    cout << "t2: " << PerThreadSingleton::get().id << "\n";
    cout << "t2 again: " << PerThreadSingleton::get().id << "\n";
  });

  t1.join();
  t2.join();

  return 0;
}