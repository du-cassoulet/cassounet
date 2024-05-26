#include "./Position.hpp"

Position::Position(std::string _code, int _index, int _line, int _column, std::string _filename)
: code(_code), index(_index), line(_line), column(_column), filename(_filename) {}

Position::Position(std::string _code, std::string _filename)
: code(_code), index(0), line(0), column(0), filename(_filename) {}

void Position::advance()
{
  index++;
  column++;

  if (code[index] == '\n')
  {
    line++;
    column = 0;
  }
}

Position Position::copy()
{
  return Position(code, index, line, column, filename);
}

std::string Position::to_string()
{
  return filename + ":" + std::to_string(line + 1) + ":" + std::to_string(column + 1);
}