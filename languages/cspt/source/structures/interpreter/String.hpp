#pragma once

#include <string>
#include <memory>

#include "Value.hpp"
#include "Boolean.hpp"
#include "../SymbolTable.hpp"
#include "../RTResult.hpp"

struct String : public virtual Value
{
  std::string value;

  String(std::string _value, Position _start, Position _end, Context* _context);

  bool is_true() override;

  RTResult to_positive() override;
  RTResult to_negative() override;
  RTResult to_not() override;

  RTResult add(std::shared_ptr<Value> other) override;
  RTResult subtract(std::shared_ptr<Value> other) override;
  RTResult multiply(std::shared_ptr<Value> other) override;
  RTResult divide(std::shared_ptr<Value> other) override;
  RTResult modulo(std::shared_ptr<Value> other) override;
  RTResult power(std::shared_ptr<Value> other) override;
  RTResult equal(std::shared_ptr<Value> other) override;
  RTResult not_equal(std::shared_ptr<Value> other) override;
  RTResult greater_than(std::shared_ptr<Value> other) override;
  RTResult less_than(std::shared_ptr<Value> other) override;
  RTResult greater_than_or_equal(std::shared_ptr<Value> other) override;
  RTResult less_than_or_equal(std::shared_ptr<Value> other) override;
  RTResult and_op(std::shared_ptr<Value> other) override;
  RTResult or_op(std::shared_ptr<Value> other) override;

  std::string to_string(int depth = 0) override;
};