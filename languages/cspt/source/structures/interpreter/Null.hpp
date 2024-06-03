#pragma once

#include <string>
#include <memory>

#include "Value.hpp"
#include "../SymbolTable.hpp"

struct Null : public virtual Value
{
  Null(Position _start, Position _end, Context* _context);

  bool is_true() override;
  
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

  std::string to_string(int depth = 0) override;
};