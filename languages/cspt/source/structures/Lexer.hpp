#pragma once 

#include <iostream>
#include <string>
#include <list>
#include "Position.hpp"
#include "Token.hpp"

struct Lexer
{
private:
  void make_identifier();
  void make_number();
  void make_string();
  void make_equals();

public:
  std::string input;
  Position position;
  std::list<Token> tokens = {};

  Lexer(std::string _input, std::string _filename);

  void advance();
  void make_tokens();
  void print_tokens();
};