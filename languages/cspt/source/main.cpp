#include <iostream>
#include <string>
#include "lib.hpp"
#include "./structures/SymbolTable.hpp"
#include "./structures/Lexer.hpp"
#include "./structures/Parser.hpp"
#include "./structures/Interpreter.hpp"

#define FILE_NAME "<stdin>"

int main(int argc, char *argv[])
{
  if (argc < 2)
  {
    std::cerr << "Usage: " << argv[0] << " <filename>" << std::endl;
    return 1;
  }

  std::string option = argv[1];

  if (option == "--version" || option == "-v")
  {
    std::cout << "Version 1.0.0" << std::endl;
    return 0;
  }
  else if (option == "--help" || option == "-h")
  {
    std::cout << "Usage: " << argv[0] << " <filename>" << std::endl;
    return 0;
  }
  else if (option == "repo")
  {
    std::cout << "Type 'exit' to exit the repo." << std::endl;

    SymbolTable symbol_table = SymbolTable();

    while (true)
    {
      std::string code;
      std::cout << ">>> ";

      getline(std::cin, code, '\n');

      if (code == "exit")
      {
        std::cout << "Exiting..." << std::endl;
        break;
      }

      Lexer lexer = Lexer(code, FILE_NAME);
      lexer.make_tokens();
      // lexer.print_tokens();

      Parser parser = Parser(lexer.tokens);
      parser.parse();
      // parser.print_node();

      Interpreter interpreter = Interpreter(&symbol_table);
      std::cout << interpreter.visit(parser.node)->to_string() << std::endl;
    }
    
    return 0;
  }
  else
  {
    std::cerr << "Usage: " << argv[0] << " <filename>" << std::endl;
    return 1;
  }
}
