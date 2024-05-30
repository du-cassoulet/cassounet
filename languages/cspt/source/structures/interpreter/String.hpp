#pragma once

#include <string>
#include <memory>

#include "./Value.hpp"
#include "../SymbolTable.hpp"

struct String : public virtual Value
{
  std::string value;

  String(std::string _value, Position _start, Position _end, SymbolTable* _symbol_table = nullptr);

  std::shared_ptr<Value> to_positive() override;
  std::shared_ptr<Value> to_negative() override;
  std::shared_ptr<Value> to_not() override;

  std::shared_ptr<Value> add(std::shared_ptr<Value> other) override;
  std::shared_ptr<Value> subtract(std::shared_ptr<Value> other) override;
  std::shared_ptr<Value> multiply(std::shared_ptr<Value> other) override;
  std::shared_ptr<Value> divide(std::shared_ptr<Value> other) override;
  std::shared_ptr<Value> modulo(std::shared_ptr<Value> other) override;
  std::shared_ptr<Value> power(std::shared_ptr<Value> other) override;
  std::shared_ptr<Value> equal(std::shared_ptr<Value> other) override;
  std::shared_ptr<Value> not_equal(std::shared_ptr<Value> other) override;
  std::shared_ptr<Value> greater_than(std::shared_ptr<Value> other) override;
  std::shared_ptr<Value> less_than(std::shared_ptr<Value> other) override;
  std::shared_ptr<Value> greater_than_or_equal(std::shared_ptr<Value> other) override;
  std::shared_ptr<Value> less_than_or_equal(std::shared_ptr<Value> other) override;
  std::shared_ptr<Value> and_op(std::shared_ptr<Value> other) override;
  std::shared_ptr<Value> or_op(std::shared_ptr<Value> other) override;

  std::string to_string() override;
};