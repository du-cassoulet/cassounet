#pragma once

#include <iostream>
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
  TT_NEQUALS,
  TT_PLUS,
  TT_MINUS,
  TT_MUL,
  TT_DIV,
  TT_MOD,
  TT_LPAREN,
  TT_RPAREN,
  TT_NOT,
  TT_OR,
  TT_AND,
  TT_LT,
  TT_GT,
  TT_LTE,
  TT_GTE,
  TT_POW
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
  std::string to_string_type();
};