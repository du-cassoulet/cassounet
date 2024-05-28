#pragma once 

#include <string>

#include "./Value.hpp"

struct String : public virtual Value
{
  std::string value;

  String(std::string _value);

  std::string to_string() override;
};