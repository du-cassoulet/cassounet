#pragma once

#include <iostream>
#include <string>
#include <memory>

enum class ValueType
{
  NUMBER,
  STRING,
  BOOLEAN
};

struct Value
{
  ValueType type;

  Value(ValueType _type);

  virtual void to_positive() = 0;
  virtual void to_negative() = 0;
  virtual void to_not() = 0;

  virtual void add(std::shared_ptr<Value> other) = 0;
  virtual void subtract(std::shared_ptr<Value> other) = 0;
  virtual void multiply(std::shared_ptr<Value> other) = 0;
  virtual void divide(std::shared_ptr<Value> other) = 0;
  virtual void modulo(std::shared_ptr<Value> other) = 0;
  virtual void power(std::shared_ptr<Value> other) = 0;
  virtual void equal(std::shared_ptr<Value> other) = 0;
  virtual void not_equal(std::shared_ptr<Value> other) = 0;
  virtual void greater_than(std::shared_ptr<Value> other) = 0;
  virtual void less_than(std::shared_ptr<Value> other) = 0;
  virtual void greater_than_or_equal(std::shared_ptr<Value> other) = 0;
  virtual void less_than_or_equal(std::shared_ptr<Value> other) = 0;
  virtual void and_op(std::shared_ptr<Value> other) = 0;
  virtual void or_op(std::shared_ptr<Value> other) = 0;

  virtual std::string to_string() = 0;
};