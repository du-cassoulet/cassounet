#pragma once

#include <iostream>
#include <list>
#include <vector>
#include <memory>
#include <optional>
#include <algorithm>

#include "Token.hpp"
#include "nodes/Node.hpp"

enum class Function
{
  ATOM,
  POWER,
  FACTOR,
  TERM,
  ARITH_EXPR,
  COMP_EXPR
};

struct Parser
{
private:
  std::shared_ptr<Node> atom();
  std::shared_ptr<Node> power();
  std::shared_ptr<Node> factor();
  std::shared_ptr<Node> term();
  std::shared_ptr<Node> arith_expr();
  std::shared_ptr<Node> comp_expr();
  std::shared_ptr<Node> bin_op(Function funca, std::list<TokenType> ops, Function funcb);

public:
  std::vector<Token> tokens;
  std::shared_ptr<Node> node = nullptr;
  std::optional<Token> current_token = std::nullopt;
  int token_index = 0;

  Parser(std::vector<Token> _tokens);

  void parse();
  void print_node();
  void advance();
};