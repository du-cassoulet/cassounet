#include "Token.hpp"

Token::Token(TokenType _type, std::string _value, Position _start, Position _end)
: type(_type), value(_value), start(_start), end(_end) {}

Token::Token(TokenType _type, Position _start, Position _end)
: type(_type), value(""), start(_start), end(_end) {}

Token::Token(TokenType _type, Position _pos)
: type(_type), value(""), start(_pos), end(_pos)
{
  Position _end = _pos.copy();
  _end.advance();
  end = _end;
}

std::string Token::to_string()
{
  std::string type_name = "";

  switch (type)
  {
    case TT_EOF:
      type_name = "EOF";
      break;

    case TT_IDENTIFIER:
      type_name = "IDENTIFIER";
      break;

    case TT_KEYWORD:
      type_name = "KEYWORD";
      break;

    case TT_NUMBER:
      type_name = "NUMBER";
      break;

    case TT_STRING:
      type_name = "STRING";
      break;

    case TT_ASSIGN:
      type_name = "ASSIGN";
      break;

    case TT_EQUALS:
      type_name = "EQUALS";
      break;

    case TT_PLUS:
      type_name = "PLUS";
      break;

    case TT_MINUS:
      type_name = "MINUS";
      break;

    case TT_MUL:
      type_name = "MUL";
      break;

    case TT_DIV:
      type_name = "DIV";
      break;

    case TT_LPAREN:
      type_name = "LPAREN";
      break;

    case TT_RPAREN:
      type_name = "RPAREN";
      break;
  }

  if (value == "")
  {
    return "Token(" + type_name + ", " + start.to_string() + " - " + end.to_string() + ")";
  }

  return "Token(" + type_name + ", " + value + ", " + start.to_string() + " - " + end.to_string() + ")";
}