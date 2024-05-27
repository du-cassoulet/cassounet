#include "Parser.hpp"
#include "nodes/NumberNode.hpp"

Parser::Parser(std::list<Token> _tokens)
: tokens(_tokens), current_token(tokens.front())
{
  tokens.pop_front();
}

void Parser::parse()
{
  nodes.push_back(std::make_shared<NumberNode>(current_token));
}

void Parser::print_nodes()
{
  for (auto& node : nodes) {
    std::cout << node->to_string() << std::endl;
  }
}

void Parser::advance()
{
  if (current_token.type != TokenType::TT_EOF && !tokens.empty())
  {
    current_token = tokens.front();
    tokens.pop_front();
  }
  else
  {
    throw std::invalid_argument("No more tokens");
  }
}