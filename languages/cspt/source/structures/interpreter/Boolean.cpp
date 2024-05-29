#include "Boolean.hpp"

Boolean::Boolean(bool _value, Position _start, Position _end, SymbolTable* _symbol_table)
: Value(ValueType::BOOLEAN, _start, _end, _symbol_table), value(_value) {}

void Boolean::to_positive()
{
  throw std::runtime_error("Cannot convert boolean to positive");
}

void Boolean::to_negative()
{
  throw std::runtime_error("Cannot convert boolean to negative");
}

void Boolean::to_not()
{
  value = !value;
}

void Boolean::add(std::shared_ptr<Value> other)
{
  throw std::runtime_error("Cannot add boolean");
}

void Boolean::subtract(std::shared_ptr<Value> other)
{
  throw std::runtime_error("Cannot subtract boolean");
}

void Boolean::multiply(std::shared_ptr<Value> other)
{
  throw std::runtime_error("Cannot multiply boolean");
}

void Boolean::divide(std::shared_ptr<Value> other)
{
  throw std::runtime_error("Cannot divide boolean");
}

void Boolean::modulo(std::shared_ptr<Value> other)
{
  throw std::runtime_error("Cannot modulo boolean");
}

void Boolean::power(std::shared_ptr<Value> other)
{
  throw std::runtime_error("Cannot power boolean");
}

void Boolean::equal(std::shared_ptr<Value> other)
{
  Boolean boolean = dynamic_cast<Boolean&>(*other);
  value = value == boolean.value;
}

void Boolean::not_equal(std::shared_ptr<Value> other)
{
  Boolean boolean = dynamic_cast<Boolean&>(*other);
  value = value != boolean.value;
}

void Boolean::greater_than(std::shared_ptr<Value> other)
{
  throw std::runtime_error("Cannot compare boolean");
}

void Boolean::less_than(std::shared_ptr<Value> other)
{
  throw std::runtime_error("Cannot compare boolean");
}

void Boolean::greater_than_or_equal(std::shared_ptr<Value> other)
{
  throw std::runtime_error("Cannot compare boolean");
}

void Boolean::less_than_or_equal(std::shared_ptr<Value> other)
{
  throw std::runtime_error("Cannot compare boolean");
}

void Boolean::and_op(std::shared_ptr<Value> other)
{
  Boolean boolean = dynamic_cast<Boolean&>(*other);
  value = value && boolean.value;
}

void Boolean::or_op(std::shared_ptr<Value> other)
{
  Boolean boolean = dynamic_cast<Boolean&>(*other);
  value = value || boolean.value;
}

std::string Boolean::to_string()
{
  return value ? "true" : "false";
}