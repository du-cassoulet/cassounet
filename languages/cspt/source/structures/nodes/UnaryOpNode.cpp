#include "UnaryOpNode.hpp"

UnaryOpNode::UnaryOpNode(const Token& _op_tok, Node* _node)
: Node(_node->start, _op_tok.end), op_tok(_op_tok), node(_node) {}

std::string UnaryOpNode::to_string()
{
  return "UnaryOpNode(" + op_tok.to_string() + ", " + node->to_string() + ")";
}