#pragma once

#include <string>

#include "./Value.hpp"

struct Number : public virtual Value
{
  double value;

  Number(double _value);

  std::string to_string() override;
};