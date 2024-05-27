#pragma once

#include <iostream>
#include <list>
#include <vector>
#include <memory>

#include "Token.hpp"
#include "nodes/Node.hpp"

struct Parser
{
public:
  Token current_token;
  std::list<Token> tokens;
  std::vector<std::shared_ptr<Node>> nodes = {};

  Parser(std::list<Token> _tokens);

  void parse();
  void print_nodes();
  void advance();
};