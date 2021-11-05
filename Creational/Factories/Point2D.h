#pragma once
#include <ostream>

class Point2D
{
public:
  int x, y;

  Point2D(const int x, const int y)
    : x{x},
      y{y}
  {
  }


  friend std::ostream& operator<<(std::ostream& os, const Point2D& obj)
  {
    return os
      << "(" << obj.x
      << "," << obj.y << ")";
  }
};
