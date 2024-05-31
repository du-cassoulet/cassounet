#include <iostream>
#include <string>
#include <fstream>
#include <memory>
#include <filesystem>

#include "lib.hpp"
#include "structures/SymbolTable.hpp"
#include "structures/Lexer.hpp"
#include "structures/Parser.hpp"
#include "structures/Interpreter.hpp"
#include "structures/Position.hpp"
#include "structures/interpreter/BuiltInFunction.hpp"

#define FILE_NAME "<stdin>"
#define VERSION "1.0.0"

namespace fs = std::filesystem;

struct ReturnValue
{
  std::shared_ptr<Value> value;
  std::shared_ptr<Error> error;

  ReturnValue(std::shared_ptr<Value> _value, std::shared_ptr<Error> _error)
  : value(_value), error(_error) {}
};

std::string global_file_path(std::string filename)
{
  if (filename.rfind("./", 0) == 0)
  {
    filename = filename.substr(2);
  }

  std::string path = fs::current_path();
  path += "/" + filename;
  return path; 
}

ReturnValue run_code(const std::string& code, SymbolTable* symbol_table, const std::string& filename = FILE_NAME)
{
  Lexer lexer = Lexer(code, filename);
  std::shared_ptr<IllegalCharError> illegal_char_error = lexer.make_tokens();

  if (illegal_char_error != nullptr)
  {
    return ReturnValue(nullptr, illegal_char_error);
  }

  Parser parser = Parser(lexer.tokens);
  ParseResult result = parser.parse();

  if (result.error != nullptr)
  {
    return ReturnValue(nullptr, result.error);
  }

  Interpreter interpreter = Interpreter(symbol_table);
  RTResult return_value = interpreter.visit(result.node);
  return ReturnValue(return_value.value, return_value.error);
}

std::string read_file(const std::string& filename)
{
  std::ifstream file(filename);
  if (!file.is_open()) {
    std::cerr << "Could not open the file" << std::endl;
    exit(1);
  }
  
  std::string line;
  std::string result = "";
  while (std::getline(file, line)) {
    result += line + "\n";
  }
  
  file.close();

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
  else
  { 
    SymbolTable symbol_table = SymbolTable();
    symbol_table.set("log", std::make_shared<BuiltInFunction>("log", Position(), Position(), &symbol_table));

    if (option == "repo")
    {
      std::cout << "Type 'exit' to exit the repo." << std::endl;

      while (true)
      {
        std::string code;
        std::cout << "\033[0;30m>>>\033[0m ";

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

        ReturnValue result = run_code(code, &symbol_table);
        if (result.error != nullptr)
        {
          std::cerr << result.error->to_string() << std::endl;
          continue;
        }

        std::cout << result.value->to_string() << std::endl;
        symbol_table.set("_", result.value);
      }
      
      return 0;
    }
    else
    {
      std::string filename = global_file_path(option);
      std::string code = read_file(filename);

      if (code.empty())
      {
        return 0;
      }

      auto begin = std::chrono::high_resolution_clock::now();
      ReturnValue result = run_code(code, &symbol_table, filename);
      auto end = std::chrono::high_resolution_clock::now();

      if (result.error != nullptr)
      {
        std::cerr << result.error->to_string() << std::endl;
        return 1;
      }

      double delay = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count();
      double milliseconds = delay / 1000000;

      std::cout << "\033[0;30mExecuted in " << milliseconds << " ms\033[0m" << std::endl;

      return 0;
    }
  }
}
