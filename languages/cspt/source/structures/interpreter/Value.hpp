#pragma once

#include <iostream>
#include <string>

struct Value
{
  Value() {};

  virtual std::string to_string() = 0;
};