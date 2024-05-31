#pragma once

#include <iostream>
#include <list>
#include <vector>
#include <memory>
#include <optional>
#include <algorithm>

#include "Token.hpp"
#include "Error.hpp"
#include "ParseResult.hpp"
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
#include "nodes/ReturnNode.hpp"
#include "nodes/ListNode.hpp"
#include "nodes/IfNode.hpp"

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
  ParseResult atom();
  ParseResult call();
  ParseResult power();
  ParseResult factor();
  ParseResult term();
  ParseResult arith_expr();
  ParseResult comp_expr();
  ParseResult bin_op(FunctionType funca, std::list<TokenType> ops, FunctionType funcb);
  ParseResult if_expr();
  ParseResult expr();
  ParseResult statement();
  ParseResult statements();

public:
  static void print_node(ParseResult* result);

  std::vector<Token> tokens;
  std::shared_ptr<Node> node = nullptr;
  std::optional<Token> current_token = std::nullopt;
  int token_index = 0;

  Parser(std::vector<Token> _tokens);

  ParseResult parse();
  void advance();
  void reverse(int num = 1);
};