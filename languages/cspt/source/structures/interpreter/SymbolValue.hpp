#pragma once

#include "Value.hpp"
#include "../SymbolTable.hpp"

class SymbolValue : public virtual Value {
protected:
  SymbolTable* symbol_table;

public:
  SymbolValue(ValueType _type, Position _start, Position _end);

  void set_symbol_table(SymbolTable* _symbol_table);
  SymbolTable* get_symbol_table();
};