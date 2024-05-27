#pragma once

#include <string>

#include "Node.hpp"
#include "../Token.hpp"

struct UnaryOpNode : public virtual Node
{
  Token op_tok;
  Node* node;

  UnaryOpNode(const Token& _op_tok, Node* _node);

  std::string to_string() override;
};