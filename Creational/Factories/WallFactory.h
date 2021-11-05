#pragma once
#include "Material.h"
#include "SolidWall.h"

enum class WallType
{
  basic,
  main,
  partition
};

class WallFactory
{
  static std::vector<std::weak_ptr<Wall>> walls;
public:
  static std::shared_ptr<SolidWall> create_main(Point2D start, Point2D end, int elevation, int height)
  {
    if (elevation < 0) return {};

    return make_shared<SolidWall>(start, end, elevation, height, 275, Material::aerated_concrete);
  }

  static std::shared_ptr<SolidWall> create_partition(Point2D start, Point2D end, int elevation, int height)
  {
    const auto this_wall = new SolidWall{start, end, elevation, height, 120, Material::brick};

    // ensure we don't intersect other walls
    for (const auto wall: walls)
    {
      if (auto p = wall.lock())
      {
        if (this_wall->intersects(*p))
        {
          delete this_wall;
          return {};
        }
      }
    }

    shared_ptr<SolidWall> ptr(this_wall);
    walls.push_back(ptr);
    return ptr;
  }

  static std::shared_ptr<Wall> create_wall(WallType type, Point2D start, 
    Point2D end, int elevation, int height)
  {
    switch (type)
    {
    case WallType::main:
      return make_shared<SolidWall>(start, end, elevation, height, 
        375, Material::aerated_concrete);
    case WallType::partition:
      return make_shared<SolidWall>(start, end, elevation, height, 
        120, Material::brick);
    case WallType::basic:
      //return make_shared<Wall>(start, end, elevation, height);
      return shared_ptr<Wall>{new Wall(start, end, elevation, height)};
    }
    return {};
  }
};
