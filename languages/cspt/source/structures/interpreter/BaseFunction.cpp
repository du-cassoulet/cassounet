#include "BaseFunction.hpp"

BaseFunction::BaseFunction(ValueType _type, std::string _name, Position _start, Position _end, SymbolTable* _symbol_table)
: Value(_type, _start, _end), SymbolValue(_type, _start, _end), name(_name) {}

SymbolTable BaseFunction::generate_new_symbol_table()
{
  return SymbolTable(symbol_table);
}

void BaseFunction::populate_args(std::vector<std::string> arg_names, std::vector<std::shared_ptr<Value>> args, SymbolTable* new_symbol_table)
{
  for (int i = 0; i < arg_names.size(); i++)
  {
    new_symbol_table->set(arg_names[i], args[i]);
  }
}

void BaseFunction::check_arg_count(std::vector<std::string> arg_names, std::vector<std::shared_ptr<Value>> args)
{
  if (arg_names.size() != args.size())
  {
    throw std::runtime_error("Function '" + name + "' expected " + std::to_string(arg_names.size()) + " arguments, but got " + std::to_string(args.size()));
  }
}

void BaseFunction::check_args(std::vector<std::string> arg_names, std::vector<std::shared_ptr<Value>> args, SymbolTable* symbol_table)
{
  check_arg_count(arg_names, args);
  populate_args(arg_names, args, symbol_table);
}