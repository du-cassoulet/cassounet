#include <iostream>
#include <string>
#include "lib.hpp"
#include "./structures/Lexer.hpp"
#include "./structures/Parser.hpp"
// #include "./structures/Interpreter.hpp"

#define FILE_NAME "<stdin>"

int main()
{
  Lexer lexer = Lexer("3", FILE_NAME);
  lexer.make_tokens();
  lexer.print_tokens();

  Parser parser = Parser(lexer.tokens);
  parser.parse();
  parser.print_node();

  // Interpreter interpreter = Interpreter(parser.node);
  // std::cout << interpreter.visit() << std::endl;

  return 0;
}
