#include "Value.hpp"

Value::Value(ValueType _type, Position _start, Position _end, bool _symbol_valued)
: type(_type), start(_start), end(_end), symbol_valued(_symbol_valued) {}