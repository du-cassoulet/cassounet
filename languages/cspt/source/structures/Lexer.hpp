#pragma once 

#include <iostream>
#include <string>
#include <vector>
#include <memory>

#include "Position.hpp"
#include "Token.hpp"
#include "../constants/Keyword.hpp"
#include "Error.hpp"

struct Lexer
{
private:
  void make_identifier();
  void make_number();
  void make_string();
  void make_equals();
  void make_or();
  void make_and();
  void make_not();
  void make_lower_than();
  void make_greater_than();

public:
  std::string input;
  Position position;
  std::vector<Token> tokens = {};

  Lexer(std::string _input, std::string _filename);

  void advance();
  std::shared_ptr<IllegalCharError> make_tokens();
  void print_tokens();
};