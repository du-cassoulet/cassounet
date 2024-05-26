#pragma once

#include <iostream>
#include "../Position.hpp"

struct Node
{
  Position start;
  Position end;

  std::string to_string();
};