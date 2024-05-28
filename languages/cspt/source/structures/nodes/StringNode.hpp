#pragma once

#include <iostream>
#include <string>

#include "Node.hpp"
#include "../Token.hpp"

struct StringNode : public virtual Node
{
  NodeType type = NodeType::String;
  Token value_tok;

  StringNode(const Token& _value_tok);

  std::string to_string(int depth = 0) override;
};