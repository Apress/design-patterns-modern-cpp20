#include <functional>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Person
{
public:
  string name;
  int age;
};

class PersonBuilder
{
public:
  vector<void(Person&)> actions;

  PersonBuilder& called(const string& name)
  {
    actions.push_back([=](Person& p)
    {
      p.name = name;
    });
  }
};