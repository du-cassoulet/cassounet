#pragma once

#include <string>
#include "../Position.hpp"

struct Node
{
  Position start;
  Position end;

  Node(const Position& _start, const Position& _end);
  
  virtual std::string to_string() = 0;
};