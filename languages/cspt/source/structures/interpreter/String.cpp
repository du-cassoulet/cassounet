#include "String.hpp"

String::String(std::string _value, Position _start, Position _end, SymbolTable* _symbol_table)
: Value(ValueType::STRING, _start, _end, _symbol_table), value(_value) {}

bool String::is_true()
{
  return value != "";
}

std::shared_ptr<Value> String::to_positive()
{
  throw std::runtime_error("Cannot convert string to positive");
}

std::shared_ptr<Value> String::to_negative()
{
  throw std::runtime_error("Cannot convert string to negative");
}

std::shared_ptr<Value> String::to_not()
{
  throw std::runtime_error("Cannot convert string to not");
}

std::shared_ptr<Value> String::add(std::shared_ptr<Value> other)
{
  if (other == nullptr)
  {
    throw std::runtime_error("Cannot add string to non-string");
  }

  String string = dynamic_cast<String&>(*other);
  
  return std::make_shared<String>(value + string.value, start, end);
}

std::shared_ptr<Value> String::subtract(std::shared_ptr<Value> other)
{
  throw std::runtime_error("Cannot subtract string");
}

std::shared_ptr<Value> String::multiply(std::shared_ptr<Value> other)
{
  throw std::runtime_error("Cannot multiply string");
}

std::shared_ptr<Value> String::divide(std::shared_ptr<Value> other)
{
  throw std::runtime_error("Cannot divide string");
}

std::shared_ptr<Value> String::modulo(std::shared_ptr<Value> other)
{
  throw std::runtime_error("Cannot modulo string");
}

std::shared_ptr<Value> String::power(std::shared_ptr<Value> other)
{
  throw std::runtime_error("Cannot power string");
}

std::shared_ptr<Value> String::equal(std::shared_ptr<Value> other)
{
  throw std::runtime_error("Cannot compare string");
}

std::shared_ptr<Value> String::not_equal(std::shared_ptr<Value> other)
{
  throw std::runtime_error("Cannot compare string");
}

std::shared_ptr<Value> String::greater_than(std::shared_ptr<Value> other)
{
  throw std::runtime_error("Cannot compare string");
}

std::shared_ptr<Value> String::less_than(std::shared_ptr<Value> other)
{
  throw std::runtime_error("Cannot compare string");
}

std::shared_ptr<Value> String::greater_than_or_equal(std::shared_ptr<Value> other)
{
  throw std::runtime_error("Cannot compare string");
}

std::shared_ptr<Value> String::less_than_or_equal(std::shared_ptr<Value> other)
{
  throw std::runtime_error("Cannot compare string");
}

std::shared_ptr<Value> String::and_op(std::shared_ptr<Value> other)
{
  throw std::runtime_error("Cannot and string");
}

std::shared_ptr<Value> String::or_op(std::shared_ptr<Value> other)
{
  throw std::runtime_error("Cannot or string");
}

std::string String::to_string()
{
  return "\033[0;92m\"" + value + "\"\033[0m";
}