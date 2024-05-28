#pragma once

#include <map>
#include <string>
#include <optional>
#include <memory>

#include "Value.hpp"

struct SymbolTable
{
public:
  std::map<std::string, Value> symbols;
  SymbolTable* parent;

  SymbolTable(SymbolTable* _parent = nullptr);

  std::shared_ptr<Value> get(const std::string& name);
  bool has(const std::string& name);
  void set(const std::string& name, const Value& value);
  void remove(const std::string& name);
};