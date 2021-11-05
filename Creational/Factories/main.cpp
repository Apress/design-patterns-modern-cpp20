#include "headers.h"
#include "WallFactory.h"
#include "SolidWall.h"

int main(int argc, char* argv[])
{
  const auto main_wall = SolidWall::create_main({0,0}, {0,3000}, 2700, 3000);
  cout << main_wall << "\n";

  // this will fail
  const auto also_main_wall = WallFactory::create_main({0,0}, {10000,0}, -2000, 3000);
  if (!also_main_wall)
    cout << "Main wall not created\n";

  const auto partition = WallFactory::create_partition({2000,0}, {2000,4000}, 0, 2700);
  cout << *partition << "\n";

  const auto also_partition =
    WallFactory::create_wall(WallType::partition, {0,0}, {5000,0}, 0, 4200);
  if (also_partition)
    cout << *dynamic_pointer_cast<SolidWall>(also_partition) << "\n";

  // creation via nested factory
  auto basic = Wall::factory.create({0,0}, {5000,0}, 0, 3000);
  cout << *basic << "\n";

  // cannot create factory directly
  //Wall::BasicWallFactory factory{};
}