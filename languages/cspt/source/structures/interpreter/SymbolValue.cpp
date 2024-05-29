#include "SymbolValue.hpp"

SymbolValue::SymbolValue(ValueType _type, Position _start, Position _end)
: Value(_type, _start, _end, true) {}

void SymbolValue::set_symbol_table(SymbolTable* _symbol_table) {
  symbol_table = _symbol_table;
}

SymbolTable* SymbolValue::get_symbol_table() {
  return symbol_table;
}