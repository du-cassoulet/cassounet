#pragma once

#include <vector>
#include <memory>

#include "BaseFunction.hpp"
#include "Value.hpp"
#include "Null.hpp"
#include "../nodes/Node.hpp"
#include "../SymbolTable.hpp"
#include "../Position.hpp"
#include "../RTResult.hpp"
#include "../Interpreter.hpp"

struct Function : public virtual BaseFunction
{
  std::shared_ptr<Node> body_node;
  std::vector<std::string> arg_names;
  bool should_auto_return;

  Function(std::string _name, Position _start, Position _end, std::shared_ptr<Node> _body_node, std::vector<std::string> _arg_names, bool _should_auto_return = false, SymbolTable* _symbol_table = nullptr);

  RTResult execute(std::vector<std::shared_ptr<Value>> args) override;
  
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
  Function copy();
};