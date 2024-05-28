#include "NumberNode.hpp"

NumberNode::NumberNode(const Token& _value_tok)
: Node(_value_tok.start, _value_tok.end), value_tok(_value_tok) {
  if (value_tok.type != TokenType::TT_NUMBER) {
    throw std::runtime_error("Invalid token type");
  }
}

std::string NumberNode::to_string(int depth)
{
  return "NumberNode(" + value_tok.to_string() + ")";
}