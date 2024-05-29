#include "Null.hpp"

Null::Null(Position _start, Position _end, SymbolTable* _symbol_table)
: Value(ValueType::NULL_VALUE, _start, _end, false) {}

void Null::to_positive() {
  throw std::runtime_error("Cannot convert null to a number");
}

void Null::to_negative() {
  throw std::runtime_error("Cannot convert null to a number");
}

void Null::to_not() {
  throw std::runtime_error("Cannot convert null to a boolean");
}

void Null::add(std::shared_ptr<Value> other) {
  throw std::runtime_error("Cannot add null");
}

void Null::subtract(std::shared_ptr<Value> other) {
  throw std::runtime_error("Cannot subtract null");
}

void Null::multiply(std::shared_ptr<Value> other) {
  throw std::runtime_error("Cannot multiply null");
}

void Null::divide(std::shared_ptr<Value> other) {
  throw std::runtime_error("Cannot divide null");
}

void Null::modulo(std::shared_ptr<Value> other) {
  throw std::runtime_error("Cannot modulo null");
}

void Null::power(std::shared_ptr<Value> other) {
  throw std::runtime_error("Cannot power null");
}

void Null::equal(std::shared_ptr<Value> other) {
  throw std::runtime_error("Cannot compare null");
}

void Null::not_equal(std::shared_ptr<Value> other) {
  throw std::runtime_error("Cannot compare null");
}

void Null::greater_than(std::shared_ptr<Value> other) {
  throw std::runtime_error("Cannot compare null");
}

void Null::less_than(std::shared_ptr<Value> other) {
  throw std::runtime_error("Cannot compare null");
}

void Null::greater_than_or_equal(std::shared_ptr<Value> other) {
  throw std::runtime_error("Cannot compare null");
}

void Null::less_than_or_equal(std::shared_ptr<Value> other) {
  throw std::runtime_error("Cannot compare null");
}

void Null::and_op(std::shared_ptr<Value> other) {
  throw std::runtime_error("Cannot and null");
}

void Null::or_op(std::shared_ptr<Value> other) {
  throw std::runtime_error("Cannot or null");
}

std::string Null::to_string() {
  return "null";
}