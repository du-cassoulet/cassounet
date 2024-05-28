#pragma once

#include <iostream>
#include <string>
#include <memory>

#include "../SymbolTable.hpp"
#include "../Position.hpp"

enum class ValueType
{
  NUMBER,
  STRING,
  BOOLEAN,
  FUNCTION
};

struct Value
{
  ValueType type;
  Position start;
  Position end;
  SymbolTable* symbol_table;

  Value(ValueType _type, Position _start, Position _end, SymbolTable* _symbol_table = nullptr);

  void set_symbol_table(SymbolTable* _symbol_table);

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