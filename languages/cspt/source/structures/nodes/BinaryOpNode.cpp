#include "BinaryOpNode.hpp"

BinaryOpNode::BinaryOpNode(OpType _op, Value _left, Value _right)
: op(_op), left(_left), right(_right) {}

std::string BinaryOpNode::to_string()
{
  std::string op_str;

  switch (op)
  {
    case ADD:
      op_str = "+";
      break;
    case SUB:
      op_str = "-";
      break;
    case MUL:
      op_str = "*";
      break;
    case DIV:
      op_str = "/";
      break;
  }

  return "BinaryOpNode(" + left.to_string() + " " + op_str + " " + right.to_string() + ")";
}