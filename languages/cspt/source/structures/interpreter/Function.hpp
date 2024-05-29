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
  Function copy();
};