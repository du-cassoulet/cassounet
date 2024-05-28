#include "Number.hpp"

Number::Number(double _value)
: Value(ValueType::NUMBER), value(_value) {}

void Number::to_positive()
{
  value = +value;
}

void Number::to_negative()
{
  value = -value;
}

void Number::to_not()
{
  value = !value;
}

void Number::add(std::shared_ptr<Value> other)
{
  Number number = dynamic_cast<Number&>(*other);
  value += number.value;
}

void Number::subtract(std::shared_ptr<Value> other)
{
  Number number = dynamic_cast<Number&>(*other);
  value -= number.value;
}

void Number::multiply(std::shared_ptr<Value> other)
{
  Number number = dynamic_cast<Number&>(*other);
  value *= number.value;
}

void Number::divide(std::shared_ptr<Value> other)
{
  Number number = dynamic_cast<Number&>(*other);
  value /= number.value;
}

void Number::modulo(std::shared_ptr<Value> other)
{
  Number number = dynamic_cast<Number&>(*other);
  value = std::fmod(value, number.value);
}

void Number::power(std::shared_ptr<Value> other)
{
  Number number = dynamic_cast<Number&>(*other);
  value = std::pow(value, number.value);
}

void Number::equal(std::shared_ptr<Value> other)
{
  Number number = dynamic_cast<Number&>(*other);
  value = value == number.value;
}

void Number::not_equal(std::shared_ptr<Value> other)
{
  Number number = dynamic_cast<Number&>(*other);
  value = value != number.value;
}

void Number::greater_than(std::shared_ptr<Value> other)
{
  Number number = dynamic_cast<Number&>(*other);
  value = value > number.value;
}

void Number::less_than(std::shared_ptr<Value> other)
{
  Number number = dynamic_cast<Number&>(*other);
  value = value < number.value;
}

void Number::greater_than_or_equal(std::shared_ptr<Value> other)
{
  Number number = dynamic_cast<Number&>(*other);
  value = value >= number.value;
}

void Number::less_than_or_equal(std::shared_ptr<Value> other)
{
  Number number = dynamic_cast<Number&>(*other);
  value = value <= number.value;
}

void Number::and_op(std::shared_ptr<Value> other)
{
  throw std::runtime_error("Cannot perform and operation on number");
}

void Number::or_op(std::shared_ptr<Value> other)
{
  throw std::runtime_error("Cannot perform or operation on number");
}

std::string Number::to_string()
{
  std::string str = std::to_string(value);
  str.erase(str.find_last_not_of('0') + 1, std::string::npos);
  str.erase(str.find_last_not_of('.') + 1, std::string::npos);
  return str;
}