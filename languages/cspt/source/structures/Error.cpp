#include "Error.hpp"

Error::Error(std::string _error_name, std::string _details, Position _start, Position _end)
: error_name(_error_name), details(_details), start(_start), end(_end) {}

IllegalCharError::IllegalCharError(std::string _details, Position _start, Position _end)
: Error("\033[0;31mIllegal Character Error\033[0;30m:\033[0m", _details, _start, _end) {}

IllegalCharError::IllegalCharError(std::string _details, Position _pos)
: Error("\033[0;31mIllegal Character Error\033[0;30m:\033[0m", _details, _pos, _pos) {
  Position _end = _pos.copy();
  _end.advance();
  end = _end;
}

SyntaxError::SyntaxError(std::string _details, Position _start, Position _end)
: Error("\033[0;31mSyntax Error\033[0;30m:\033[0m", _details, _start, _end) {}

SyntaxError::SyntaxError(std::string _details, Position _pos)
: Error("\033[0;31mSyntax Error\033[0;30m:\033[0m", _details, _pos, _pos) {
  Position _end = _pos.copy();
  _end.advance();
  end = _end;
}

RTError::RTError(std::string _details, Position _start, Position _end)
: Error("\033[0;31mRuntime Error\033[0;30m:\033[0m", _details, _start, _end) {}

RTError::RTError(std::string _details, Position _pos)
: Error("\033[0;31mRuntime Error\033[0;30m:\033[0m", _details, _pos, _pos) {
  Position _end = _pos.copy();
  _end.advance();
  end = _end;
}

std::string Error::to_string()
{
  return error_name + "\n" + details;
}