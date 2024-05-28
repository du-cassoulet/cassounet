#include "Value.hpp"

Value::Value(ValueType _type, Position _start, Position _end, SymbolTable* _symbol_table)
: type(_type), start(_start), end(_end), symbol_table(_symbol_table) {}

void Value::set_symbol_table(SymbolTable* _symbol_table)
{
  symbol_table = _symbol_table;
}