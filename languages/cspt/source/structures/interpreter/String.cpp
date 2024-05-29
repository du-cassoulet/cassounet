#include "String.hpp"

String::String(std::string _value, Position _start, Position _end, SymbolTable* _symbol_table)
: Value(ValueType::STRING, _start, end, _symbol_table), value(_value) {}

void String::to_positive()
{
  throw std::runtime_error("Cannot convert string to positive");
}

void String::to_negative()
{
  throw std::runtime_error("Cannot convert string to negative");
}

void String::to_not()
{
  throw std::runtime_error("Cannot convert string to not");
}

void String::add(std::shared_ptr<Value> other)
{
  if (other == nullptr)
  {
    throw std::runtime_error("Cannot add string to non-string");
  }

  String string = dynamic_cast<String&>(*other);
  
  value += string.value;
}

void String::subtract(std::shared_ptr<Value> other)
{
  throw std::runtime_error("Cannot subtract string");
}

void String::multiply(std::shared_ptr<Value> other)
{
  throw std::runtime_error("Cannot multiply string");
}

void String::divide(std::shared_ptr<Value> other)
{
  throw std::runtime_error("Cannot divide string");
}

void String::modulo(std::shared_ptr<Value> other)
{
  throw std::runtime_error("Cannot modulo string");
}

void String::power(std::shared_ptr<Value> other)
{
  throw std::runtime_error("Cannot power string");
}

void String::equal(std::shared_ptr<Value> other)
{
  throw std::runtime_error("Cannot compare string");
}

void String::not_equal(std::shared_ptr<Value> other)
{
  throw std::runtime_error("Cannot compare string");
}

void String::greater_than(std::shared_ptr<Value> other)
{
  throw std::runtime_error("Cannot compare string");
}

void String::less_than(std::shared_ptr<Value> other)
{
  throw std::runtime_error("Cannot compare string");
}

void String::greater_than_or_equal(std::shared_ptr<Value> other)
{
  throw std::runtime_error("Cannot compare string");
}

void String::less_than_or_equal(std::shared_ptr<Value> other)
{
  throw std::runtime_error("Cannot compare string");
}

void String::and_op(std::shared_ptr<Value> other)
{
  throw std::runtime_error("Cannot and string");
}

void String::or_op(std::shared_ptr<Value> other)
{
  throw std::runtime_error("Cannot or string");
}

std::string String::to_string()
{
  return value;
}