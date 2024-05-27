#include <iostream>
#include <string>
#include "lib.hpp"
#include "./structures/Lexer.hpp"
#include "./structures/Parser.hpp"

#define FILE_NAME "<stdin>"

int main()
{
  Lexer lexer = Lexer("1+1", FILE_NAME);
  lexer.make_tokens();
  lexer.print_tokens();

  // Parser parser = Parser(lexer.tokens);
  // parser.parse();
  // parser.print_nodes();

  return 0;
}
