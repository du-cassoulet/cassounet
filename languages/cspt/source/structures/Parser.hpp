#pragma once

#include <iostream>
#include <list>
#include <vector>
#include <memory>
#include <optional>
#include <algorithm>

#include "Token.hpp"
#include "nodes/Node.hpp"
#include "nodes/NumberNode.hpp"
#include "nodes/StringNode.hpp"
#include "nodes/BooleanNode.hpp"
#include "nodes/NullNode.hpp"
#include "nodes/UnaryOpNode.hpp"
#include "nodes/BinaryOpNode.hpp"
#include "nodes/VarAssignNode.hpp"
#include "nodes/VarReAssignNode.hpp"
#include "nodes/VarAccessNode.hpp"
#include "nodes/CallNode.hpp"

enum class FunctionType
{
  ATOM,
  POWER,
  FACTOR,
  TERM,
  ARITH_EXPR,
  COMP_EXPR,
  CALL
};

struct Parser
{
private:
  std::shared_ptr<Node> atom();
  std::shared_ptr<Node> call();
  std::shared_ptr<Node> power();
  std::shared_ptr<Node> factor();
  std::shared_ptr<Node> term();
  std::shared_ptr<Node> arith_expr();
  std::shared_ptr<Node> comp_expr();
  std::shared_ptr<Node> bin_op(FunctionType funca, std::list<TokenType> ops, FunctionType funcb);
  std::shared_ptr<Node> expr();

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