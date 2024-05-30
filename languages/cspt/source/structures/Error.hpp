#pragma once

#include <string>

#include "Position.hpp"

struct Error
{
  std::string error_name;
  std::string details;
  Position start;
  Position end;

  Error(std::string _error_name, std::string _details, Position _start, Position _end);

  std::string to_string();
};

struct IllegalCharError : public Error
{
  IllegalCharError(std::string _details, Position _start, Position _end);
  IllegalCharError(std::string _details, Position _pos);
};

struct SyntaxError : public Error
{
  SyntaxError(std::string _details, Position _start, Position _end);
  SyntaxError(std::string _details, Position _pos);
};

struct RTError : public Error
{
  RTError(std::string _details, Position _start, Position _end);
  RTError(std::string _details, Position _pos);
};