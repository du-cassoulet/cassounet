#include "Parser.hpp"

Parser::Parser(std::list<Token> _tokens)
: tokens(_tokens), current_token(tokens.front()) {
  tokens.pop_front();
}

void Parser::parse()
{
  while (current_token.type != TokenType::TT_EOF)
  {
    advance();
  }
}

void Parser::print_nodes()
{
  for (Node node : nodes)
  {
    std::cout << node.to_string() << std::endl;
  }
}

void Parser::advance()
{
  if (tokens.size() > 0)
  {
    current_token = tokens.front();
    tokens.pop_front();
  }
  else
  {
    throw std::invalid_argument("No more tokens");
  }
}