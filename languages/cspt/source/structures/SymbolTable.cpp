#include "SymbolTable.hpp"

SymbolTable::SymbolTable(SymbolTable* _parent)
  : parent(_parent) {}

std::shared_ptr<Value> SymbolTable::get(const std::string& name)
{
  if (symbols.find(name) != symbols.end())
  {
    return std::make_shared<Value>(symbols[name]);
  }
  else if (parent != nullptr)
  {
    return parent->get(name);
  }

  return nullptr;
}

bool SymbolTable::has(const std::string& name)
{
  if (symbols.find(name) != symbols.end())
  {
    return true;
  }
  else if (parent != nullptr)
  {
    return parent->has(name);
  }

  return false;
}

void SymbolTable::set(const std::string& name, const Value& value)
{
  symbols[name] = value;
}

void SymbolTable::remove(const std::string& name)
{
  symbols.erase(name);
}