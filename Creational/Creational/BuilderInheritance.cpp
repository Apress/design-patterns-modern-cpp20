#include <string>
#include <iostream>
#include <functional>
using namespace std;

class PersonBuilder;

class Person
{
public:
  string name, position;
};

class PersonBuilder
{
protected:
  Person person;
public:
  [[nodiscard]] Person build() const {
    return person;
  }
};

//class PersonInfoBuilder : public PersonBuilder
//{
//public:
//  PersonInfoBuilder& called(const string& name)
//  {
//    person.name = name;
//    return *this;
//  }
//};
//
//class PersonJobBuilder : public PersonInfoBuilder
//{
//public:
//  PersonJobBuilder& works_as(const string& position)
//  {
//    person.position = position;
//    return *this;
//  }
//};

template<typename TSelf> class PersonInfoBuilder;

template <typename TSelf>
requires (is_base_of<TSelf, PersonInfoBuilder<TSelf>>)
class PersonInfoBuilder : PersonBuilder
{
  public TSelf& called(const string& name)
  {
    person.name = name;
    return static_cast<TSelf&>(*this);
  }
};

int main()
{
//  PersonJobBuilder pb;
//  auto person =
//    pb.called("Dmitri")
//      .works_as("Programmer") // will not compile
//      .build();
}