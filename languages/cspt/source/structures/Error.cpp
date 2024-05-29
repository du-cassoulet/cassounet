#include "Error.hpp"

Error::Error(std::string _error_name, std::string _details)
: error_name(_error_name), details(_details) {}

std::string Error::to_string()
{
  return error_name + ": " + details;
}