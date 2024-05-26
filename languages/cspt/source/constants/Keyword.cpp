#include "Keyword.hpp"

Keyword::Keyword(KeywordType _name, std::string _value)
: name(_name), value(_value) {}

std::list<Keyword> Keyword::keywords = {
  Keyword(KeywordType::SET, "set"),
  Keyword(KeywordType::IF, "if"),
  Keyword(KeywordType::ELSE, "else"),
  Keyword(KeywordType::WHILE, "while"),
  Keyword(KeywordType::FOR, "for"),
};

Keyword Keyword::getKeyword(std::string value)
{
  for (Keyword keyword : keywords)
  {
    if (keyword.value == value)
    {
      return keyword;
    }
  }

  return Keyword(KeywordType::SET, "");
}

bool Keyword::isKeyword(std::string value)
{
  for (Keyword keyword : keywords)
  {
    if (keyword.value == value)
    {
      return true;
    }
  }

  return false;
}