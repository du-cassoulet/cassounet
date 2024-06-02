#include "Boolean.hpp"

Boolean::Boolean(bool _value, Position _start, Position _end, Context* _context)
: Value(ValueType::BOOLEAN, _start, _end), value(_value)
{
  set_context(_context);
}

bool Boolean::is_true()
{
  return value;
}

std::shared_ptr<Value> Boolean::to_positive()
{
  throw std::runtime_error("Cannot convert boolean to positive");
}

std::shared_ptr<Value> Boolean::to_negative()
{
  throw std::runtime_error("Cannot convert boolean to negative");
}

std::shared_ptr<Value> Boolean::to_not()
{
  return std::make_shared<Boolean>(!value, start, end, context);
}

std::shared_ptr<Value> Boolean::add(std::shared_ptr<Value> other)
{
  throw std::runtime_error("Cannot add boolean");
}

std::shared_ptr<Value> Boolean::subtract(std::shared_ptr<Value> other)
{
  throw std::runtime_error("Cannot subtract boolean");
}

std::shared_ptr<Value> Boolean::multiply(std::shared_ptr<Value> other)
{
  throw std::runtime_error("Cannot multiply boolean");
}

std::shared_ptr<Value> Boolean::divide(std::shared_ptr<Value> other)
{
  throw std::runtime_error("Cannot divide boolean");
}

std::shared_ptr<Value> Boolean::modulo(std::shared_ptr<Value> other)
{
  throw std::runtime_error("Cannot modulo boolean");
}

std::shared_ptr<Value> Boolean::power(std::shared_ptr<Value> other)
{
  throw std::runtime_error("Cannot power boolean");
}

std::shared_ptr<Value> Boolean::equal(std::shared_ptr<Value> other)
{
  Boolean boolean = dynamic_cast<Boolean&>(*other);
  return std::make_shared<Boolean>(value == boolean.value, start, end, context);
}

std::shared_ptr<Value> Boolean::not_equal(std::shared_ptr<Value> other)
{
  Boolean boolean = dynamic_cast<Boolean&>(*other);
  return std::make_shared<Boolean>(value != boolean.value, start, end, context);
}

std::shared_ptr<Value> Boolean::greater_than(std::shared_ptr<Value> other)
{
  throw std::runtime_error("Cannot compare boolean");
}

std::shared_ptr<Value> Boolean::less_than(std::shared_ptr<Value> other)
{
  throw std::runtime_error("Cannot compare boolean");
}

std::shared_ptr<Value> Boolean::greater_than_or_equal(std::shared_ptr<Value> other)
{
  throw std::runtime_error("Cannot compare boolean");
}

std::shared_ptr<Value> Boolean::less_than_or_equal(std::shared_ptr<Value> other)
{
  throw std::runtime_error("Cannot compare boolean");
}

std::shared_ptr<Value> Boolean::and_op(std::shared_ptr<Value> other)
{
  Boolean boolean = dynamic_cast<Boolean&>(*other);
  return std::make_shared<Boolean>(value && boolean.value, start, end, context);
}

std::shared_ptr<Value> Boolean::or_op(std::shared_ptr<Value> other)
{
  Boolean boolean = dynamic_cast<Boolean&>(*other);
  return std::make_shared<Boolean>(value || boolean.value, start, end, context);
}

std::string Boolean::to_string()
{
  return value ? "\033[0;33mtrue\033[0m" : "\033[0;33mfalse\033[0m";
}