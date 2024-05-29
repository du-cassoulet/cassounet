#pragma once

#include <string>

struct Error
{
  std::string error_name;
  std::string details;

  Error(std::string _error_name, std::string _details);

  std::string to_string();
};