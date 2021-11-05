#pragma once

enum class Material
{
  brick,
  aerated_concrete,
  drywall
};

std::ostream& operator<<(std::ostream& os, Material material);