#pragma once

#include <iostream>
#include <string>
#include <memory>

#include "../Position.hpp"

enum class ValueType
{
  NUMBER,
  STRING,
  BOOLEAN,
  FUNCTION,
  NULL_VALUE
};

struct Value
{
  ValueType type;
  bool symbol_valued;
  Position start;
  Position end;

  Value(ValueType _type, Position _start, Position _end, bool symbol_valued = false);
  virtual ~Value() = default;

  virtual std::shared_ptr<Value> to_positive() = 0;
  virtual std::shared_ptr<Value> to_negative() = 0;
  virtual std::shared_ptr<Value> to_not() = 0;

  virtual std::shared_ptr<Value> add(std::shared_ptr<Value> other) = 0;
  virtual std::shared_ptr<Value> subtract(std::shared_ptr<Value> other) = 0;
  virtual std::shared_ptr<Value> multiply(std::shared_ptr<Value> other) = 0;
  virtual std::shared_ptr<Value> divide(std::shared_ptr<Value> other) = 0;
  virtual std::shared_ptr<Value> modulo(std::shared_ptr<Value> other) = 0;
  virtual std::shared_ptr<Value> power(std::shared_ptr<Value> other) = 0;
  virtual std::shared_ptr<Value> equal(std::shared_ptr<Value> other) = 0;
  virtual std::shared_ptr<Value> not_equal(std::shared_ptr<Value> other) = 0;
  virtual std::shared_ptr<Value> greater_than(std::shared_ptr<Value> other) = 0;
  virtual std::shared_ptr<Value> less_than(std::shared_ptr<Value> other) = 0;
  virtual std::shared_ptr<Value> greater_than_or_equal(std::shared_ptr<Value> other) = 0;
  virtual std::shared_ptr<Value> less_than_or_equal(std::shared_ptr<Value> other) = 0;
  virtual std::shared_ptr<Value> and_op(std::shared_ptr<Value> other) = 0;
  virtual std::shared_ptr<Value> or_op(std::shared_ptr<Value> other) = 0;

  virtual std::string to_string() = 0;
};