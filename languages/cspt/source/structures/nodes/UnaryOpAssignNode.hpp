#pragma once

#include <string>
#include <memory>

#include "../Token.hpp"
#include "Node.hpp"

struct UnaryOpAssignNode : public virtual Node
{
  Token op_tok;
  Token var_name_tok;

  UnaryOpAssignNode(const Token& _op_tok, const Token& _var_name_tok);

  std::string to_string(int depth = 0) override;
};