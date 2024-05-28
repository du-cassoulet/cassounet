#pragma once

#include <string>
#include <memory>

#include "Node.hpp"
#include "../Token.hpp"

struct UnaryOpNode : public virtual Node
{
  NodeType type = NodeType::UnaryOperation;
  Token op_tok;
  std::shared_ptr<Node> node;

  UnaryOpNode(const Token& _op_tok, std::shared_ptr<Node> _node);

  std::string to_string(int depth = 0) override;
};