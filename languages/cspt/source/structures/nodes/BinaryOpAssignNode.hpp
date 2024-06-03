#pragma once

#include <string>
#include <memory>

#include "../Token.hpp"
#include "Node.hpp"

struct BinaryOpAssignNode : public virtual Node
{
  Token op_tok;
  Token left;
  std::shared_ptr<Node> right;

  BinaryOpAssignNode(const Token& _left, const Token& _op_tok, std::shared_ptr<Node> _right);

  std::string to_string(int depth = 0) override;
};
