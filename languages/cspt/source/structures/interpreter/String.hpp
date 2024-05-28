#pragma once

#include <string>
#include <memory>

#include "./Value.hpp"

struct String : public virtual Value
{
  std::string value;

  String(std::string _value);

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