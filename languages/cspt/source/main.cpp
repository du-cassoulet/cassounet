#include <iostream>
#include <string>
#include <fstream>
#include <memory>

#include "lib.hpp"
#include "structures/SymbolTable.hpp"
#include "structures/Lexer.hpp"
#include "structures/Parser.hpp"
#include "structures/Interpreter.hpp"
#include "structures/Position.hpp"
#include "structures/interpreter/BuiltInFunction.hpp"

#define FILE_NAME "<stdin>"
#define VERSION "1.0.0"

std::shared_ptr<Value> run_code(const std::string& code, SymbolTable* symbol_table, const std::string& filename = FILE_NAME)
{
  Lexer lexer = Lexer(code, filename);
  lexer.make_tokens();
  Parser parser = Parser(lexer.tokens);
  parser.parse();


  Interpreter interpreter = Interpreter(symbol_table);
  return interpreter.visit(parser.node).value;
}

std::string read_file(const std::string& filename)
{
  std::fstream my_file;
  std::string result;
	my_file.open(filename, std::ios::in);

	if (!my_file)
  {
		std::cout << "No such file";
	}
	else 
  {
		char ch;

		while (true)
    {
			my_file >> ch;
			if (my_file.eof())
				break;

			result += ch;
		}

	}

	my_file.close();

	return result;
}

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
    std::cout << "Version " << VERSION << std::endl;
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

    symbol_table.set("log", std::make_shared<BuiltInFunction>("log", Position(), Position(), &symbol_table));

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

      if (code.empty())
      {
        continue;
      }

      std::shared_ptr<Value> result = run_code(code, &symbol_table);
      std::cout << result->to_string() << std::endl;
      symbol_table.set("_", result);
    }
    
    return 0;
  }
  else
  {
    SymbolTable symbol_table = SymbolTable();
    std::string code = read_file(option);
    run_code(code, &symbol_table, option);
    return 0;
  }
}
