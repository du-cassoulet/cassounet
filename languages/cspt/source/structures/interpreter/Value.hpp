#pragma once

#include <iostream>
#include <string>
#include <memory>

struct Context;

#include "../Position.hpp"
#include "../Context.hpp"

enum class ValueType
{
  NUMBER,
  STRING,
  BOOLEAN,
  FUNCTION,
  BUILTIN_FUNCTION,
  LIST,
  NULL_VALUE
};

struct Value
{
  ValueType type;
  Position start;
  Position end;
  Context* context = nullptr;

  Value(ValueType _type, Position _start, Position _end);
  virtual ~Value() = default;

  void set_context(Context* _context);

  virtual bool is_true() = 0;

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

  virtual std::string to_string(int depth = 0) = 0;
};