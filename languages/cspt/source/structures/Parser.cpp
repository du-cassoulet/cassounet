#include "Parser.hpp"
#include "nodes/NumberNode.hpp"
#include "nodes/StringNode.hpp"
#include "nodes/BooleanNode.hpp"
#include "nodes/UnaryOpNode.hpp"
#include "nodes/BinaryOpNode.hpp"

Parser::Parser(std::vector<Token> _tokens)
: tokens(_tokens) {
  if (!tokens.empty())
  {
    current_token = tokens[token_index];
  }
  else
  {
    throw std::invalid_argument("No tokens");
  }
}

std::shared_ptr<Node> Parser::atom()
{
  if (current_token->match(TokenType::TT_NUMBER))
  {
    std::shared_ptr<Node> node = std::make_shared<NumberNode>(*current_token);
    advance();
    return node;
  } else if (current_token->match(TokenType::TT_STRING))
  {
    std::shared_ptr<Node> node = std::make_shared<StringNode>(*current_token);
    advance();
    return node;
  }
  else if (current_token->match(TokenType::TT_KEYWORD, {"true", "false"}))
  {
    std::shared_ptr<Node> node = std::make_shared<BooleanNode>(*current_token);
    advance();
    return node;
  }
  else
  {
    throw std::invalid_argument("Invalid token: '" + current_token->to_string_type() + "'");
  }
}

std::shared_ptr<Node> Parser::power()
{
  return bin_op(Function::ATOM, {TokenType::TT_POW}, Function::FACTOR);
}

std::shared_ptr<Node> Parser::factor()
{
  if (current_token->match(TokenType::TT_NOT))
  {
    Token op_tok = *current_token;
    advance();

    std::shared_ptr<Node> node = comp_expr();
    return std::make_shared<UnaryOpNode>(op_tok, node);
  }
  else if (current_token->match({TokenType::TT_PLUS, TokenType::TT_MINUS}))
  {
    Token op_tok = *current_token;
    advance();

    std::shared_ptr<Node> node = factor();
    return std::make_shared<UnaryOpNode>(op_tok, node);
  }
  else
  {
    return power();
  }
}

std::shared_ptr<Node> Parser::term()
{
  return bin_op(Function::FACTOR, {TokenType::TT_MUL, TokenType::TT_DIV, TokenType::TT_MOD}, Function::FACTOR);
}

std::shared_ptr<Node> Parser::arith_expr()
{
  return bin_op(Function::TERM, {TokenType::TT_PLUS, TokenType::TT_MINUS}, Function::TERM);
}

std::shared_ptr<Node> Parser::comp_expr()
{
  return bin_op(Function::ARITH_EXPR, {
    TokenType::TT_EQUALS,
    TokenType::TT_NEQUALS,
    TokenType::TT_LT,
    TokenType::TT_GT,
    TokenType::TT_LTE,
    TokenType::TT_GTE
  }, Function::ARITH_EXPR);
}

std::shared_ptr<Node> Parser::bin_op(Function funca, std::list<TokenType> ops, Function funcb)
{
  std::shared_ptr<Node> left;

  switch (funca)
  {
    case Function::ATOM:
      left = atom();
      break;

    case Function::FACTOR:
      left = factor();
      break;

    case Function::TERM:
      left = term();
      break;

    case Function::ARITH_EXPR:
      left = arith_expr();
      break;

    case Function::COMP_EXPR:
      left = comp_expr();
      break;

    default:
      throw std::invalid_argument("Invalid function");
  }

  while (std::find(ops.begin(), ops.end(), current_token->type) != ops.end())
  {
    Token op_tok = *current_token;
    advance();

    std::shared_ptr<Node> right;

    switch (funcb)
    {
      case Function::ATOM:
        right = atom();
        left = std::make_shared<BinaryOpNode>(left, op_tok, right);
        break;

      case Function::FACTOR:
        right = factor();
        left = std::make_shared<BinaryOpNode>(left, op_tok, right);
        break;

      case Function::TERM:
        right = term();
        left = std::make_shared<BinaryOpNode>(left, op_tok, right);
        break;

      case Function::ARITH_EXPR:
        right = arith_expr();
        left = std::make_shared<BinaryOpNode>(left, op_tok, right);
        break;

      case Function::COMP_EXPR:
        right = comp_expr();
        left = std::make_shared<BinaryOpNode>(left, op_tok, right);
        break;

      default:
        throw std::invalid_argument("Invalid function");
    }
  }

  return left;
}

void Parser::parse()
{
  this->node = bin_op(Function::COMP_EXPR, {TokenType::TT_OR, TokenType::TT_AND}, Function::COMP_EXPR);
}

void Parser::print_node()
{
  std::cout << node->to_string() << std::endl;
}

void Parser::advance()
{
  if (!current_token->match(TokenType::TT_EOF))
  {
    token_index++;

    if (token_index < tokens.size())
    {
      current_token = tokens[token_index];
    }
    else
    {
      current_token = std::nullopt;
    }
  }
  else
  {
    throw std::invalid_argument("No more tokens");
  }
}