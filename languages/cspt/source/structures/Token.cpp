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

std::string Token::to_string_type()
{
  switch (type)
  {
    case TT_EOF:
      return "EOF";

    case TT_IDENTIFIER:
      return "IDENTIFIER";

    case TT_KEYWORD:
      return "KEYWORD";

    case TT_NUMBER:
      return "NUMBER";

    case TT_STRING:
      return "STRING";

    case TT_ASSIGN:
      return "ASSIGN";

    case TT_EQUALS:
      return "EQUALS";

    case TT_PLUS:
      return "PLUS";

    case TT_MINUS:
      return "MINUS";

    case TT_MUL:
      return "MUL";

    case TT_DIV:
      return "DIV";

    case TT_MOD:
      return "MOD";

    case TT_POW:
      return "POW";

    case TT_LPAREN:
      return "LPAREN";

    case TT_RPAREN:
      return "RPAREN";

    case TT_NOT:
      return "NOT";

    case TT_OR:
      return "OR";

    case TT_AND:
      return "AND";

    case TT_LT:
      return "LT";

    case TT_GT:
      return "GT";

    case TT_LTE:
      return "LTE";

    case TT_GTE:
      return "GTE";

    default: 
      throw std::invalid_argument("Invalid token type");
  }
}

std::string Token::to_string()
{
  std::string interval = "";

  if (start == end)
  {
    interval = start.to_string();
  }
  else
  {
    interval = start.to_string() + " - " + end.to_string();
  }

  if (value == "")
  {
    return "Token(" + to_string_type() + ", " + interval + ")";
  }

  return "Token(" + to_string_type() + ", " + value + ", " + interval + ")";
}