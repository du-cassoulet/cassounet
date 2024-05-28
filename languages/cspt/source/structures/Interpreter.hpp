#pragma once

#include <string>
#include <memory>

#include "./nodes/Node.hpp"
// #include "interpreter/Number.cpp"

struct Interpreter
{
private:
  std::string visit_number(std::shared_ptr<Node> node);

public:
  std::shared_ptr<Node> node;

  Interpreter(std::shared_ptr<Node> _node);

  std::string visit();
};