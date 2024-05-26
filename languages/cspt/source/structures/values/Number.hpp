#pragma once

#include "./Value.hpp"

struct Number : Value
{
  double value;

  Number(double _value);

  std::string to_string();
};