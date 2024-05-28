#include "Number.hpp"

Number::Number(double _value)
: value(_value) {}

std::string Number::to_string()
{
  return std::to_string(value);
}