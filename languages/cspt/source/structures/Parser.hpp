#pragma once

#include <iostream>
#include <list>
#include "Token.hpp"
#include "nodes/Node.hpp"

struct Parser
{
  std::list<Token> tokens;
  Token current_token;
  std::list<Node> nodes = {};

  Parser(std::list<Token> _tokens);

  void parse();
  void print_nodes();
  void advance();
};