#pragma once

#include <string>
#include <memory>

#include "Node.hpp"

struct ReturnNode : public virtual Node
{
  std::shared_ptr<Node> node;

  ReturnNode(std::shared_ptr<Node> _node);

  std::string to_string(int depth = 0) override;
};