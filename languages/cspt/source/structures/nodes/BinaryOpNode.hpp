#pragma once

#include <string>

#include "../values/Value.hpp"

enum OpType
{
  ADD,
  SUB,
  MUL,
  DIV,
};

struct BinaryOpNode
{
  OpType op;
  Value left;
  Value right;

  BinaryOpNode(OpType _op, Value _left, Value _right);
  std::string to_string();
};
