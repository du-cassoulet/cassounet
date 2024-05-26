#pragma once

#include <string>
#include <list>

enum class KeywordType
{
  SET,
  IF,
  ELSE,
  WHILE,
  FOR,
};

struct Keyword
{
  KeywordType name;
  std::string value;

  Keyword(KeywordType _name, std::string _value);

  static std::list<Keyword> keywords;
  static Keyword getKeyword(std::string value);
  static bool isKeyword(std::string value);
};