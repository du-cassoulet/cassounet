#include "Interpreter.hpp"

Interpreter::Interpreter(std::shared_ptr<Node> _node)
: node(_node) {}

std::string Interpreter::visit_number(std::shared_ptr<Node> node)
{
  // Number value = Number(std::stod(node->value_tok.value));
  // return value.to_string();

  return "Number";
}

std::string Interpreter::visit()
{
  // switch (node->type)
  // {
  //   case NodeType::Number:
  //   {
  //     return visit_number(std::make_shared<NumberNode>(node));
  //   }
  // }

  return "Invalid node type";
}