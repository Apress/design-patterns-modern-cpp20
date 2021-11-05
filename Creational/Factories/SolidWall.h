#pragma once

#include <ostream>

#include "Wall.h"
#include "Material.h"

class SolidWall : public Wall
{
  int width;
  Material material;
public:
  SolidWall(const Point2D start, const Point2D end, const int elevation, 
    const int height, const int width, const Material material);

  friend std::ostream& operator<<(std::ostream& os, const SolidWall& obj)
  {
    return os
      << static_cast<const Wall&>(obj)
      << " width: " << obj.width
      << " material: " << obj.material;
  }

  static SolidWall create_main(Point2D start, Point2D end, int elevation, int height)
  {
    return SolidWall{start, end, elevation, height, 275, Material::aerated_concrete};
  }

  static std::unique_ptr<SolidWall> create_partition(Point2D start, Point2D end, int elevation, int height)
  {
    return make_unique<SolidWall>(start, end, elevation, height, 120, Material::brick);
  }
};
