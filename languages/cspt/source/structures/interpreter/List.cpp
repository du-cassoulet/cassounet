#include "List.hpp"

List::List(std::vector<std::shared_ptr<Value>> _values, Position _start, Position _end, SymbolTable* _symbol_table)
: Value(ValueType::LIST, _start, _end, _symbol_table), values(_values) {}

bool List::is_true() {
  return values.size() != 0;
}

std::shared_ptr<Value> List::to_positive() {
  throw std::runtime_error("Cannot convert a list to a number");
}

std::shared_ptr<Value> List::to_negative() {
  throw std::runtime_error("Cannot convert a list to a number");
}

std::shared_ptr<Value> List::to_not() {
  throw std::runtime_error("Cannot convert a list to a boolean");
}

std::shared_ptr<Value> List::add(std::shared_ptr<Value> other) {
  throw std::runtime_error("Cannot add a list");
}

std::shared_ptr<Value> List::subtract(std::shared_ptr<Value> other) {
  throw std::runtime_error("Cannot subtract a list");
}

std::shared_ptr<Value> List::multiply(std::shared_ptr<Value> other) {
  throw std::runtime_error("Cannot multiply a list");
}

std::shared_ptr<Value> List::divide(std::shared_ptr<Value> other) {
  throw std::runtime_error("Cannot divide a list");
}

std::shared_ptr<Value> List::modulo(std::shared_ptr<Value> other) {
  throw std::runtime_error("Cannot modulo a list");
}

std::shared_ptr<Value> List::power(std::shared_ptr<Value> other) {
  throw std::runtime_error("Cannot power a list");
}

std::shared_ptr<Value> List::equal(std::shared_ptr<Value> other) {
  throw std::runtime_error("Cannot compare a list");
}

std::shared_ptr<Value> List::not_equal(std::shared_ptr<Value> other) {
  throw std::runtime_error("Cannot compare a list");
}

std::shared_ptr<Value> List::greater_than(std::shared_ptr<Value> other) {
  throw std::runtime_error("Cannot compare a list");
}

std::shared_ptr<Value> List::less_than(std::shared_ptr<Value> other) {
  throw std::runtime_error("Cannot compare a list");
}

std::shared_ptr<Value> List::greater_than_or_equal(std::shared_ptr<Value> other) {
  throw std::runtime_error("Cannot compare a list");
}

std::shared_ptr<Value> List::less_than_or_equal(std::shared_ptr<Value> other) {
  throw std::runtime_error("Cannot compare a list");
}

std::shared_ptr<Value> List::and_op(std::shared_ptr<Value> other) {
  throw std::runtime_error("Cannot and a list");
}

std::shared_ptr<Value> List::or_op(std::shared_ptr<Value> other) {
  throw std::runtime_error("Cannot or a list");
}

std::string List::to_string()
{
  std::string res = "";
  res += "\033[0;30m[\033[0m\n";

  for (int i = 0; i < values.size(); i++)
  {
    res += std::string(2, ' ') + "\033[0;33m" + std::to_string(i) + "\033[0;30m:\033[0m " + values[i]->to_string() + "\033[0;30m,\033[0m\n";
  }

  res += "\033[0;30m]\033[0m";

  return res;
}