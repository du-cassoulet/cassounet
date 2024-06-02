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

bool Token::match(TokenType correct_type, std::list<std::string> values)
{
  if (type != correct_type)
  {
    return false;
  }

  if (values.size() == 0)
  {
    return true;
  }

  for (std::string correct_value : values)
  {
    if (value == correct_value)
    {
      return true;
    }
  }

  return false;
}

bool Token::match(std::list<TokenType> types)
{
  for (TokenType correct_type : types)
  {
    if (type == correct_type)
    {
      return true;
    }
  }

  return false;
}

Token Token::copy()
{
  return Token(type, value, start, end);
}

std::string Token::to_string_type()
{
  switch (type)
  {
    case TokenType::TT_EOF:
      return "EOF";

    case TokenType::TT_IDENTIFIER:
      return "IDENTIFIER";

    case TokenType::TT_KEYWORD:
      return "KEYWORD";

    case TokenType::TT_NUMBER:
      return "NUMBER";

    case TokenType::TT_STRING:
      return "STRING";

    case TokenType::TT_ASSIGN:
      return "ASSIGN";

    case TokenType::TT_EQUALS:
      return "EQUALS";

    case TokenType::TT_PLUS:
      return "PLUS";

    case TokenType::TT_MINUS:
      return "MINUS";

    case TokenType::TT_MUL:
      return "MUL";

    case TokenType::TT_DIV:
      return "DIV";

    case TokenType::TT_MOD:
      return "MOD";

    case TokenType::TT_POW:
      return "POW";

    case TokenType::TT_LPAREN:
      return "LPAREN";

    case TokenType::TT_RPAREN:
      return "RPAREN";

    case TokenType::TT_NOT:
      return "NOT";

    case TokenType::TT_OR:
      return "OR";

    case TokenType::TT_AND:
      return "AND";

    case TokenType::TT_LT:
      return "LT";

    case TokenType::TT_GT:
      return "GT";

    case TokenType::TT_LTE:
      return "LTE";

    case TokenType::TT_GTE:
      return "GTE";

    case TokenType::TT_COMMA:
      return "COMMA";

    case TokenType::TT_SEMICOLON:
      return "SEMICOLON";

    case TokenType::TT_LBRACKET:
      return "LBRACKET";

    case TokenType::TT_RBRACKET:
      return "RBRACKET";

    case TokenType::TT_ARROW:
      return "ARROW";

    default:
      throw std::invalid_argument("Invalid token type");
  }
}

std::string Token::to_string()
{
  std::string interval = "";

  if (value == "")
  {
    return "Token(" + to_string_type() + ", " + start.to_string() + ")";
  }

  return "Token(" + to_string_type() + ", " + value + ", " + start.to_string() + ")";
}