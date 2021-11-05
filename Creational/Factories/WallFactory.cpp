#include <iostream>
#include <vector>
#include <memory>
using namespace std;
#include "WallFactory.h"

std::vector<std::weak_ptr<Wall>> WallFactory::walls{};
