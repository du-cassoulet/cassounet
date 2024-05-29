#pragma once

#include <string>
#include <memory>

#include "./Value.hpp"
#include "../SymbolTable.hpp"

struct Null : public virtual Value
{
  Null(Position _start, Position _end, SymbolTable* _symbol_table = nullptr);

  void to_positive() override;
  void to_negative() override;
  void to_not() override;

  void add(std::shared_ptr<Value> other) override;
  void subtract(std::shared_ptr<Value> other) override;
  void multiply(std::shared_ptr<Value> other) override;
  void divide(std::shared_ptr<Value> other) override;
  void modulo(std::shared_ptr<Value> other) override;
  void power(std::shared_ptr<Value> other) override;
  void equal(std::shared_ptr<Value> other) override;
  void not_equal(std::shared_ptr<Value> other) override;
  void greater_than(std::shared_ptr<Value> other) override;
  void less_than(std::shared_ptr<Value> other) override;
  void greater_than_or_equal(std::shared_ptr<Value> other) override;
  void less_than_or_equal(std::shared_ptr<Value> other) override;
  void and_op(std::shared_ptr<Value> other) override;
  void or_op(std::shared_ptr<Value> other) override;

  std::string to_string() override;
};