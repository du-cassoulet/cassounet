#pragma once

#include <string>
#include "Position.hpp"

enum TokenType
{
  TT_EOF,
  TT_IDENTIFIER,
  TT_KEYWORD,
  TT_NUMBER,
  TT_STRING,
  TT_ASSIGN,
  TT_EQUALS,
  TT_PLUS,
  TT_MINUS,
  TT_MUL,
  TT_DIV,
  TT_LPAREN,
  TT_RPAREN,
};

struct Token
{
  TokenType type;
  std::string value;
  Position start;
  Position end;

  Token(TokenType _type, std::string _value, Position _start, Position _end);
  Token(TokenType _type, Position _start, Position _end);
  Token(TokenType _type, Position _pos);

  std::string to_string();
};