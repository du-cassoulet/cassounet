#include "NumberNode.hpp"

NumberNode::NumberNode(const Token& _value_tok)
: Node(_value_tok.start, _value_tok.end), value_tok(_value_tok) {}

std::string NumberNode::to_string()
{
  return "NumberNode(" + value_tok.to_string() + ")";
}