#include <iostream>
#include "./structures/Lexer.cpp"

int main() {
  Lexer lexer = Lexer("set coucou\n= 0.87;");
  lexer.make_tokens();
  lexer.print_tokens();

  return 0;
}