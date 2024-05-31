#include "Number.hpp"

Number::Number(double _value, Position _start, Position _end, SymbolTable* _symbol_table)
: Value(ValueType::NUMBER, _start, _end, _symbol_table), value(_value) {}

bool Number::is_true()
{
  return value != 0;
}

std::shared_ptr<Value> Number::to_positive()
{
  return std::make_shared<Number>(value, start, end);
}

std::shared_ptr<Value> Number::to_negative()
{
  return std::make_shared<Number>(-value, start, end);
}

std::shared_ptr<Value> Number::to_not()
{
  return std::make_shared<Boolean>(!value, start, end);
}

std::shared_ptr<Value> Number::add(std::shared_ptr<Value> other)
{
  Number number = dynamic_cast<Number&>(*other);
  return std::make_shared<Number>(value + number.value, start, end);
}

std::shared_ptr<Value> Number::subtract(std::shared_ptr<Value> other)
{
  Number number = dynamic_cast<Number&>(*other);
  return std::make_shared<Number>(value - number.value, start, end);
}

std::shared_ptr<Value> Number::multiply(std::shared_ptr<Value> other)
{
  Number number = dynamic_cast<Number&>(*other);
  return std::make_shared<Number>(value * number.value, start, end);
}

std::shared_ptr<Value> Number::divide(std::shared_ptr<Value> other)
{
  Number number = dynamic_cast<Number&>(*other);
  return std::make_shared<Number>(value / number.value, start, end);
}

std::shared_ptr<Value> Number::modulo(std::shared_ptr<Value> other)
{
  Number number = dynamic_cast<Number&>(*other);
  return std::make_shared<Number>(std::fmod(value, number.value), start, end);
}

std::shared_ptr<Value> Number::power(std::shared_ptr<Value> other)
{
  Number number = dynamic_cast<Number&>(*other);
  return std::make_shared<Number>(std::pow(value, number.value), start, end);
}

std::shared_ptr<Value> Number::equal(std::shared_ptr<Value> other)
{
  Number number = dynamic_cast<Number&>(*other);
  return std::make_shared<Boolean>(value == number.value, start, end);
}

std::shared_ptr<Value> Number::not_equal(std::shared_ptr<Value> other)
{
  Number number = dynamic_cast<Number&>(*other);
  return std::make_shared<Boolean>(value != number.value, start, end);
}

std::shared_ptr<Value> Number::greater_than(std::shared_ptr<Value> other)
{
  Number number = dynamic_cast<Number&>(*other);
  return std::make_shared<Boolean>(value > number.value, start, end);
}

std::shared_ptr<Value> Number::less_than(std::shared_ptr<Value> other)
{
  Number number = dynamic_cast<Number&>(*other);
  return std::make_shared<Boolean>(value < number.value, start, end);
}

std::shared_ptr<Value> Number::greater_than_or_equal(std::shared_ptr<Value> other)
{
  Number number = dynamic_cast<Number&>(*other);
  return std::make_shared<Boolean>(value >= number.value, start, end);
}

std::shared_ptr<Value> Number::less_than_or_equal(std::shared_ptr<Value> other)
{
  Number number = dynamic_cast<Number&>(*other);
  return std::make_shared<Boolean>(value <= number.value, start, end);
}

std::shared_ptr<Value> Number::and_op(std::shared_ptr<Value> other)
{
  throw std::runtime_error("Cannot perform and operation on number");
}

std::shared_ptr<Value> Number::or_op(std::shared_ptr<Value> other)
{
  throw std::runtime_error("Cannot perform or operation on number");
}

std::string Number::to_string()
{
  std::string str = "\033[0;33m" + std::to_string(value);
  str.erase(str.find_last_not_of('0') + 1, std::string::npos);
  str.erase(str.find_last_not_of('.') + 1, std::string::npos);
  return str + "\033[0m";
}