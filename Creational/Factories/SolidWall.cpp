#include "headers.h"
#include "SolidWall.h"

SolidWall::SolidWall(const Point2D start, const Point2D end, const int elevation,
                     const int height, const int width,
                     const Material material)
  : Wall{start, end, elevation, height},
    width{width}, material{material}
{
  if (elevation < 0 && material == Material::aerated_concrete)
    throw invalid_argument("elevation");

  if (width < 120 && material == Material::brick)
    throw invalid_argument("width");
}
