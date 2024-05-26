#pragma once 

#include <string>

#include "./Value.hpp"

struct String : Value
{
  std::string value;

  String(std::string _value);

  std::string to_string();
};