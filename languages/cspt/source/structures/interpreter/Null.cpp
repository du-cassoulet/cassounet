#include "Null.hpp"

Null::Null(Position _start, Position _end, SymbolTable* _symbol_table)
: Value(ValueType::NULL_VALUE, _start, _end, false) {}

Null::Null()
: Value(ValueType::NULL_VALUE, Position(), Position(), false) {}

bool Null::is_true() {
  return false;
}

std::shared_ptr<Value> Null::to_positive() {
  throw std::runtime_error("Cannot convert null to a number");
}

std::shared_ptr<Value> Null::to_negative() {
  throw std::runtime_error("Cannot convert null to a number");
}

std::shared_ptr<Value> Null::to_not() {
  throw std::runtime_error("Cannot convert null to a boolean");
}

std::shared_ptr<Value> Null::add(std::shared_ptr<Value> other) {
  throw std::runtime_error("Cannot add null");
}

std::shared_ptr<Value> Null::subtract(std::shared_ptr<Value> other) {
  throw std::runtime_error("Cannot subtract null");
}

std::shared_ptr<Value> Null::multiply(std::shared_ptr<Value> other) {
  throw std::runtime_error("Cannot multiply null");
}

std::shared_ptr<Value> Null::divide(std::shared_ptr<Value> other) {
  throw std::runtime_error("Cannot divide null");
}

std::shared_ptr<Value> Null::modulo(std::shared_ptr<Value> other) {
  throw std::runtime_error("Cannot modulo null");
}

std::shared_ptr<Value> Null::power(std::shared_ptr<Value> other) {
  throw std::runtime_error("Cannot power null");
}

std::shared_ptr<Value> Null::equal(std::shared_ptr<Value> other) {
  throw std::runtime_error("Cannot compare null");
}

std::shared_ptr<Value> Null::not_equal(std::shared_ptr<Value> other) {
  throw std::runtime_error("Cannot compare null");
}

std::shared_ptr<Value> Null::greater_than(std::shared_ptr<Value> other) {
  throw std::runtime_error("Cannot compare null");
}

std::shared_ptr<Value> Null::less_than(std::shared_ptr<Value> other) {
  throw std::runtime_error("Cannot compare null");
}

std::shared_ptr<Value> Null::greater_than_or_equal(std::shared_ptr<Value> other) {
  throw std::runtime_error("Cannot compare null");
}

std::shared_ptr<Value> Null::less_than_or_equal(std::shared_ptr<Value> other) {
  throw std::runtime_error("Cannot compare null");
}

std::shared_ptr<Value> Null::and_op(std::shared_ptr<Value> other) {
  throw std::runtime_error("Cannot and null");
}

std::shared_ptr<Value> Null::or_op(std::shared_ptr<Value> other) {
  throw std::runtime_error("Cannot or null");
}

std::string Null::to_string() {
  return "\033[0;30mnull\033[0m";
}