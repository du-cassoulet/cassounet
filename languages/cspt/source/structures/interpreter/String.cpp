#include "String.hpp"

String::String(std::string _value)
: value(_value) {}

std::string String::to_string()
{
  return value;
}