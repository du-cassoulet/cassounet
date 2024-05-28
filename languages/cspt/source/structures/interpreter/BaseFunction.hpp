#pragma once

#include <vector>
#include <memory>

#include "Value.hpp"
#include "../SymbolTable.hpp"

struct BaseFunction : public virtual Value
{
  std::string name;

  BaseFunction(std::string _name = "anonymous", SymbolTable* _symbol_table = nullptr);

  SymbolTable generate_new_symbol_table();
  void populate_args(std::vector<std::string> arg_names, std::vector<std::shared_ptr<Value>> args, SymbolTable& new_symbol_table);
  void check_arg_count(std::vector<std::string> arg_names, std::vector<std::shared_ptr<Value>> args);
  void check_args(std::vector<std::string> arg_names, std::vector<std::shared_ptr<Value>> args, SymbolTable& symbol_table);
};