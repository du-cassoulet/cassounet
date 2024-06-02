#pragma once

#include <vector>
#include <memory>

#include "Value.hpp"
#include "Null.hpp"
#include "String.hpp"
#include "BaseFunction.hpp"
#include "../RTResult.hpp"

struct BuiltInFunction : public virtual BaseFunction
{
private:
  RTResult log(Context* context);
  RTResult ask(Context* context);

public:
  BuiltInFunction(std::string _name, Position _start, Position _end, Context* _context);
  BuiltInFunction(std::string _name, Context* _context);

  RTResult execute(std::vector<std::shared_ptr<Value>> args) override;

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

  std::string to_string() override;
  BuiltInFunction copy();
};